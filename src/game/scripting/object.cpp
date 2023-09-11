#include <stdinc.hpp>
#include "object.hpp"
#include "execution.hpp"

namespace scripting
{
	namespace
	{
		unsigned int get_canonical_string(const std::string& string, int is_static)
		{
			const auto lower = utils::string::to_lower(string);
			const auto id = game::SL_GetCanonicalString(lower.data(), is_static);
			return id;
		}
	}

	object_value::object_value(unsigned int parent_id, unsigned int id)
		: id_(id)
		, parent_id_(parent_id)
	{
		if (!this->id_)
		{
			return;
		}

		const auto value = game::scr_VarGlob->childVariableValue[this->id_];
		game::VariableValue variable;
		variable.u = value.u.u;
		variable.type = (game::scriptType_e)value.type;

		this->value_ = variable;
	}

	void object_value::operator=(const script_value& _value)
	{
		if (!this->id_)
		{
			return;
		}

		const auto value = _value.get_raw();

		const auto variable = &game::scr_VarGlob->childVariableValue[this->id_];
		game::VariableValue variable_{};
		variable_.type = variable->type;
		variable_.u = variable->u.u;

		game::AddRefToValue(game::SCRIPTINSTANCE_SERVER, &value);
		game::RemoveRefToValue(game::SCRIPTINSTANCE_SERVER, variable->type, variable->u.u);

		variable->type = gsl::narrow_cast<char>(value.type);
		variable->u.u = value.u;

		this->value_ = value;
	}

	object::object(const unsigned int id)
		: id_(id)
	{
		this->add();
	}

	object::object(const object& other)
	{
		this->operator=(other);
	}

	object::object(object&& other) noexcept
	{
		this->id_ = other.id_;
		other.id_ = 0;
	}

	object::object()
	{
		this->id_ = make_object();
	}

	object::object(std::unordered_map<std::string, script_value> values)
	{
		this->id_ = make_object();

		for (const auto& value : values)
		{
			this->set(value.first, value.second);
		}
	}

	object::~object()
	{
		this->release();
	}

	object& object::operator=(const object& other)
	{
		if (&other != this)
		{
			this->release();
			this->id_ = other.id_;
			this->add();
		}

		return *this;
	}

	object& object::operator=(object&& other) noexcept
	{
		if (&other != this)
		{
			this->release();
			this->id_ = other.id_;
			other.id_ = 0;
		}

		return *this;
	}

	void object::add() const
	{
		if (this->id_)
		{
			game::VariableValue value{};
			value.u.uintValue = this->id_;
			value.type = game::SCRIPT_OBJECT;

			game::AddRefToValue(game::SCRIPTINSTANCE_SERVER, &value);
		}
	}

	void object::release() const
	{
		if (this->id_)
		{
			game::VariableValue value{};
			value.u.uintValue = this->id_;
			value.type = game::SCRIPT_OBJECT;

			game::RemoveRefToValue(game::SCRIPTINSTANCE_SERVER, value.type, value.u);
		}
	}

	std::vector<std::string> object::get_keys() const
	{
		std::vector<std::string> result;

		auto current = game::scr_VarGlob->objectVariableChildren[this->id_].firstChild;

		while (current)
		{
			const auto var = game::scr_VarGlob->childVariableValue[current];
			const auto string_id = (unsigned __int8)var.name_lo + (var.k.keys.name_hi << 8);

			if (string_id < 0x34BC)
			{
				const auto string = reinterpret_cast<const char**>(SELECT(0x2DACC28, 0x2D7CF28))[string_id];
				result.push_back(string);
			}

			current = var.nextSibling;
		}

		return result;
	}

	unsigned int object::size() const
	{
		return game::Scr_GetSelf(game::SCRIPTINSTANCE_SERVER, this->id_);
	}

	void object::erase(const std::string& key) const
	{
		const auto string_value = get_canonical_string(key.data(), 0);
		const auto variable_id = game::FindVariable(game::SCRIPTINSTANCE_SERVER, this->id_, string_value);
		if (variable_id)
		{
			game::RemoveVariableValue(game::SCRIPTINSTANCE_SERVER, this->id_, variable_id);
		}
	}

	script_value object::get(const std::string& key) const
	{
		const auto string_value = get_canonical_string(key.data(), 0);
		const auto variable_id = game::FindVariable(game::SCRIPTINSTANCE_SERVER, this->id_, string_value);

		if (!variable_id)
		{
			return {};
		}

		const auto value = game::scr_VarGlob->childVariableValue[variable_id];
		game::VariableValue variable;
		variable.u = value.u.u;
		variable.type = (game::scriptType_e)value.type;

		return variable;
	}

	void object::set(const std::string& key, const script_value& value_) const
	{
		const auto value = value_.get_raw();
		const auto variable_id = this->get_value_id(key);

		if (!variable_id)
		{
			return;
		}

		const auto variable = &game::scr_VarGlob->childVariableValue[variable_id];
		game::VariableValue variable_{};
		variable_.type = variable->type;
		variable_.u = variable->u.u;

		game::AddRefToValue(game::SCRIPTINSTANCE_SERVER, &value);
		game::RemoveRefToValue(game::SCRIPTINSTANCE_SERVER, variable_.type, variable_.u);

		variable->type = gsl::narrow_cast<char>(value.type);
		variable->u.u = value.u;
	}

	unsigned int object::get_entity_id() const
	{
		return this->id_;
	}

	unsigned int object::get_value_id(const std::string& key) const
	{
		const auto string_value = get_canonical_string(key.data(), 0);
		const auto variable_id = game::FindVariable(game::SCRIPTINSTANCE_SERVER, this->id_, string_value);

		if (!variable_id)
		{
			return game::GetNewVariable(game::SCRIPTINSTANCE_SERVER, this->id_, string_value);
		}

		return variable_id;
	}

	entity object::get_raw() const
	{
		return entity(this->id_);
	}
}
