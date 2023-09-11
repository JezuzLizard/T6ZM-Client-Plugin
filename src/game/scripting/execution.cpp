#include <stdinc.hpp>
#include "execution.hpp"
#include "safe_execution.hpp"
#include "stack_isolation.hpp"

#include "component/scripting.hpp"

namespace scripting
{
	namespace
	{
		game::VariableValue* allocate_argument()
		{
			game::VariableValue* value_ptr = ++game::scr_VmPub->top;
			++game::scr_VmPub->inparamcount;
			return value_ptr;
		}

		script_value get_return_value()
		{
			if (game::scr_VmPub->inparamcount == 0)
			{
				return {};
			}

			game::Scr_ClearOutParams(game::SCRIPTINSTANCE_SERVER);
			game::scr_VmPub->outparamcount = game::scr_VmPub->inparamcount;
			game::scr_VmPub->inparamcount = 0;

			return script_value(game::scr_VmPub->top[1 - game::scr_VmPub->outparamcount]);
		}

		std::optional<int> get_field_id(const int classnum, const std::string& field)
		{
			const auto& table = scripting::fields_table[classnum];
			const auto lower = utils::string::to_lower(field);
			const auto iter = table.find(lower);
			if (iter != table.end())
			{
				return {iter->second};
			}

			return {};
		}
	}

	void push_value(const script_value& value)
	{
		auto* value_ptr = allocate_argument();
		*value_ptr = value.get_raw();

		game::AddRefToValue(game::SCRIPTINSTANCE_SERVER, value_ptr);
	}

	void notify(const entity& entity, const std::string& event, const std::vector<script_value>& arguments)
	{
		stack_isolation _;
		for (auto i = arguments.rbegin(); i != arguments.rend(); ++i)
		{
			push_value(*i);
		}

		const auto event_id = game::SL_GetString(event.data(), 0);
		game::Scr_NotifyId(game::SCRIPTINSTANCE_SERVER, 0, entity.get_entity_id(), event_id, game::scr_VmPub->inparamcount);
	}

	script_value call_function(const std::string& name, const entity& entity,
		const std::vector<script_value>& arguments)
	{
		const auto entref = entity.get_entity_reference();
		const auto function = find_function_ptr(name);
		if (!function)
		{
			throw std::runtime_error("Unknown function '" + name + "'");
		}

		stack_isolation _;

		for (auto i = arguments.rbegin(); i != arguments.rend(); ++i)
		{
			push_value(*i);
		}

		game::scr_VmPub->outparamcount = game::scr_VmPub->inparamcount;
		game::scr_VmPub->inparamcount = 0;

		if (!safe_execution::call(function, entref))
		{
			const auto error = reinterpret_cast<const char*>(SELECT(0x2E27C70, 0x2DF7F70));
			throw std::runtime_error(error);
		}

		return get_return_value();
	}

	script_value call_function(const std::string& name, const std::vector<script_value>& arguments)
	{
		return call_function(name, entity(), arguments);
	}

	template <>
	script_value call(const std::string& name, const std::vector<script_value>& arguments)
	{
		return call_function(name, arguments);
	}

	script_value exec_ent_thread(const entity& entity, const char* pos, const std::vector<script_value>& arguments)
	{
		const auto id = entity.get_entity_id();

		stack_isolation _;
		for (auto i = arguments.rbegin(); i != arguments.rend(); ++i)
		{
			push_value(*i);
		}

		game::VariableValue value{};
		value.type = game::SCRIPT_OBJECT;
		value.u.uintValue = id;
		game::AddRefToValue(game::SCRIPTINSTANCE_SERVER, &value);

		const auto local_id = game::AllocThread(game::SCRIPTINSTANCE_SERVER, id);
		const auto result = game::VM_Execute(game::SCRIPTINSTANCE_SERVER, local_id, pos, arguments.size());
		game::RemoveRefToObject(game::SCRIPTINSTANCE_SERVER, result);

		return get_return_value();
	}

	script_value get_custom_field(const entity& entity, const std::string& field)
	{
		const object object = entity.get_entity_id();
		return object.get(field);
	}

	void set_custom_field(const entity& entity, const std::string& field, const script_value& value)
	{
		const object object = entity.get_entity_id();
		object.set(field, value);
	}

	void set_entity_field(const entity& entity, const std::string& field, const script_value& value)
	{
		const auto entref = entity.get_entity_reference();
		const auto id = get_field_id(entref.classnum, field);

		if (id.has_value())
		{
			stack_isolation _;
			push_value(value);

			game::scr_VmPub->outparamcount = game::scr_VmPub->inparamcount;
			game::scr_VmPub->inparamcount = 0;

			if (!safe_execution::set_entity_field(entref, id.value()))
			{
				throw std::runtime_error("Failed to set value for field '" + field + "'");
			}
		}
		else
		{
			set_custom_field(entity, field, value);
		}
	}

	script_value get_entity_field(const entity& entity, const std::string& field)
	{
		const auto entref = entity.get_entity_reference();
		const auto id = get_field_id(entref.classnum, field);

		if (id.has_value())
		{
			stack_isolation _;

			game::VariableValue value{};
			if (!safe_execution::get_entity_field(entref, id.value(), &value))
			{
				throw std::runtime_error("Failed to get value for field '" + field + "'");
			}

			const auto __ = gsl::finally([&value]()
			{
				game::RemoveRefToValue(game::SCRIPTINSTANCE_SERVER, value.type, value.u);
			});

			return value;
		}
		else
		{
			return get_custom_field(entity, field);
		}
	}

	unsigned int make_array()
	{
		unsigned int index = 0;
		const auto variable = game::AllocVariable(game::SCRIPTINSTANCE_SERVER, &index);
		variable->w.type = game::SCRIPT_ARRAY;
		variable->u.f.prev = 0;
		variable->u.f.next = 0;

		return index;
	}

	unsigned int make_object()
	{
		unsigned int index = 0;
		const auto variable = game::AllocVariable(game::SCRIPTINSTANCE_SERVER, &index);
		variable->w.type = game::SCRIPT_STRUCT;
		variable->u.f.prev = 0;

		return index;
	}
}