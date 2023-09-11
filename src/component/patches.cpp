#include <stdinc.hpp>
#include "loader/component_loader.hpp"

#include "game/game.hpp"
#include "game/scripting/safe_execution.hpp"
#include "component/gsc.hpp"
#include "scheduler.hpp";

#include <utils/hook.hpp>
#include <utils/string.hpp>

#ifndef NO_COMP_PATCHES
namespace patches
{
	namespace
	{
		void* bg_get_client_field_stub(int a1, const char* a2)
		{
			const auto result = utils::hook::invoke<void*>(0x5B4220, a1, a2);
			if (!result)
			{
				const auto err = utils::string::va("No client field named %s found", a2);
				game::Scr_Error(game::SCRIPTINSTANCE_SERVER, err, 0);
			}

			return result;
		}

		void execute_with_seh_wrap(const scripting::safe_execution::script_function function, 
			const game::scr_entref_t entref, int is_method)
		{
			if (is_method)
			{
				if (gsc::call_method(reinterpret_cast<unsigned int>(function), entref))
				{
					return;
				}
			}
			else
			{
				if (gsc::call_function(reinterpret_cast<unsigned int>(function)))
				{
					return;
				}
			}

			if (!scripting::safe_execution::execute_with_seh(function, entref))
			{
				game::Scr_Error(game::SCRIPTINSTANCE_SERVER, "exception handled", 0);
			}
		}

		void call_builtin_stub(utils::hook::assembler& a)
		{
			a.mov(dword_ptr(SELECT(0x2E1A5E0, 0x2DEA8E0), eax), esi);

			a.pushad();
			a.push(0);
			a.push(0);
			a.push(0);
			a.push(ecx);
			a.call(execute_with_seh_wrap);
			a.add(esp, 0x10);
			a.popad();

			a.jmp(SELECT(0x8F6401, 0x8F5161));
		}

		void call_builtin_method_stub(utils::hook::assembler& a)
		{
			a.mov(dword_ptr(edx), ebx);

			a.pushad();
			a.push(1);
			a.push(eax);
			a.push(esi);
			a.push(dword_ptr(ebp, 0x2C));
			a.call(execute_with_seh_wrap);
			a.add(esp, 0x10);
			a.popad();

			a.add(esp, 0x18);

			a.jmp(SELECT(0x8F6498, 0x8F51F8));
		}
	}

	class component final : public component_interface
	{
	public:
		void post_unpack() override
		{
			patch();
		}

		void patch()
		{
			utils::hook::jump(SELECT(0x8F63F9, 0x8F5159), utils::hook::assemble(call_builtin_stub));
			utils::hook::jump(SELECT(0x8F6490, 0x8F51F0), utils::hook::assemble(call_builtin_method_stub));

			scheduler::once([]()
			{
				game::Dvar_RegisterInt("t6zm_client_plugin_loaded", 1, 0, 1, 0, "");
			}, scheduler::pipeline::frame, std::chrono::milliseconds(50));
		}
	};
}

REGISTER_COMPONENT(patches::component)
#endif