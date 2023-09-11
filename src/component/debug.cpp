#include <stdinc.hpp>
#include "loader/component_loader.hpp"

#include "game/structs.hpp"
#include "game/game.hpp"

#include "debug.hpp"
#include "gsc.hpp"
#include "json.hpp"
#include "io.hpp"

#include "scheduler.hpp"
#include "scripting.hpp"
#include "command.hpp"

#include <utils/hook.hpp>
#include <utils/string.hpp>
#include <utils/compression.hpp>
#include <utils/io.hpp>

namespace debug
{
    namespace
    {
        const game::dvar_t* developer_script = nullptr;
        game::dvar_t* scr_max_loop_time = nullptr;

        // gsc-tool
        std::unordered_map<game::opcode, std::string> opcode_map
        {
            {game::opcode::OP_End, "END"},
            {game::opcode::OP_Return, "RETN"},
            {game::opcode::OP_GetUndefined, "GET_UNDEFINED"},
            {game::opcode::OP_GetZero, "GET_ZERO"},
            {game::opcode::OP_GetByte, "GET_BYTE"},
            {game::opcode::OP_GetNegByte, "GET_NBYTE"},
            {game::opcode::OP_GetUnsignedShort, "GET_USHORT"},
            {game::opcode::OP_GetNegUnsignedShort, "GET_NUSHORT"},
            {game::opcode::OP_GetInteger, "GET_INT"},
            {game::opcode::OP_GetFloat, "GET_FLOAT"},
            {game::opcode::OP_GetString, "GET_STRING"},
            {game::opcode::OP_GetIString, "GET_ISTRING"},
            {game::opcode::OP_GetVector, "GET_VECTOR"},
            {game::opcode::OP_GetLevelObject, "GET_LEVEL_OBJ"},
            {game::opcode::OP_GetAnimObject, "GET_ANIM_OBJ"},
            {game::opcode::OP_GetSelf, "GET_SELF"},
            {game::opcode::OP_GetLevel, "GET_LEVEL"},
            {game::opcode::OP_GetGame, "GET_GAME"},
            {game::opcode::OP_GetAnim, "GET_ANIM"},
            {game::opcode::OP_GetAnimation, "GET_ANIMATION"},
            {game::opcode::OP_GetGameRef, "GET_GAME_REF"},
            {game::opcode::OP_GetFunction, "GET_FUNCTION"},
            {game::opcode::OP_CreateLocalVariable, "CREATE_LOCAL_VARIABLE"},
            {game::opcode::OP_SafeCreateLocalVariables, "SAFE_CREATE_LOCAL_VARIABLES"},
            {game::opcode::OP_RemoveLocalVariables, "REMOVE_LOCAL_VARIABLES"},
            {game::opcode::OP_EvalLocalVariableCached, "EVAL_LOCAL_VARIABLE_CACHED"},
            {game::opcode::OP_EvalArray, "EVAL_ARRAY"},
            {game::opcode::OP_EvalLocalArrayRefCached, "EVAL_LOCAL_ARRAY_REF_CACHED"},
            {game::opcode::OP_EvalArrayRef, "EVAL_ARRAY_REF"},
            {game::opcode::OP_ClearArray, "CLEAR_ARRAY"},
            {game::opcode::OP_EmptyArray, "EMPTY_ARRAY"},
            {game::opcode::OP_GetSelfObject, "GET_SELF_OBJECT"},
            {game::opcode::OP_EvalFieldVariable, "EVAL_FIELD_VARIABLE"},
            {game::opcode::OP_EvalFieldVariableRef, "EVAL_FIELD_VARIABLE_REF"},
            {game::opcode::OP_ClearFieldVariable, "CLEAR_FIELD_VARIABLE"},
            {game::opcode::OP_SafeSetVariableFieldCached, "SAFE_SET_VARIABLE_FIELD_CACHED"},
            {game::opcode::OP_SafeSetWaittillVariableFieldCached, "SAFE_SET_WAITTILL_VARIABLE_FIELD_CACHED"},
            {game::opcode::OP_ClearParams, "CLEAR_PARAMS"},
            {game::opcode::OP_CheckClearParams, "CHECK_CLEAR_PARAMS"},
            {game::opcode::OP_EvalLocalVariableRefCached, "EVAL_LOCAL_VARIABLE_REF_CACHED"},
            {game::opcode::OP_SetVariableField, "SET_VARIABLE_FIELD"},
            {game::opcode::OP_CallBuiltin, "CALL_BUILTIN_FUNC"},
            {game::opcode::OP_CallBuiltinMethod, "CALL_BUILTIN_METHOD"},
            {game::opcode::OP_Wait, "WAIT"},
            {game::opcode::OP_WaitTillFrameEnd, "WAITTILLFRAMEEND"},
            {game::opcode::OP_PreScriptCall, "PRE_CALL"},
            {game::opcode::OP_ScriptFunctionCall, "SCRIPT_FUNC_CALL"},
            {game::opcode::OP_ScriptFunctionCallPointer, "SCRIPT_FUNC_CALL_POINTER"},
            {game::opcode::OP_ScriptMethodCall, "SCRIPT_METHOD_CALL"},
            {game::opcode::OP_ScriptMethodCallPointer, "SCRIPT_METHOD_CALL_POINTER"},
            {game::opcode::OP_ScriptThreadCall, "SCRIPT_THREAD_CALL"},
            {game::opcode::OP_ScriptThreadCallPointer, "SCRIPT_THREAD_CALL_POINTER"},
            {game::opcode::OP_ScriptMethodThreadCall, "SCRIPT_METHOD_THREAD_CALL"},
            {game::opcode::OP_ScriptMethodThreadCallPointer, "SCRIPT_METHOD_THREAD_CALL_POINTER"},
            {game::opcode::OP_DecTop, "DEC_TOP"},
            {game::opcode::OP_CastFieldObject, "CAST_FIELD_OBJECT"},
            {game::opcode::OP_CastBool, "CAST_BOOL"},
            {game::opcode::OP_BoolNot, "BOOL_NOT"},
            {game::opcode::OP_BoolComplement, "BOOL_COMPLEMENT"},
            {game::opcode::OP_JumpOnFalse, "JMP_FALSE"},
            {game::opcode::OP_JumpOnTrue, "JMP_TRUE"},
            {game::opcode::OP_JumpOnFalseExpr, "JMP_EXPR_FALSE"},
            {game::opcode::OP_JumpOnTrueExpr, "JMP_EXPR_TRUE"},
            {game::opcode::OP_Jump, "JMP"},
            {game::opcode::OP_JumpBack, "JMP_BACK"},
            {game::opcode::OP_Inc, "INC"},
            {game::opcode::OP_Dec, "DEC"},
            {game::opcode::OP_Bit_Or, "BIT_OR"},
            {game::opcode::OP_Bit_Xor, "BIT_XOR"},
            {game::opcode::OP_Bit_And, "BIT_AND"},
            {game::opcode::OP_Equal, "EQUAL"},
            {game::opcode::OP_NotEqual, "NOT_EQUAL"},
            {game::opcode::OP_LessThan, "LESS"},
            {game::opcode::OP_GreaterThan, "GREATER"},
            {game::opcode::OP_LessThanOrEqualTo, "LESS_EQUAL"},
            {game::opcode::OP_GreaterThanOrEqualTo, "GREATER_EQUAL"},
            {game::opcode::OP_ShiftLeft, "SHIFT_LEFT"},
            {game::opcode::OP_ShiftRight, "SHIFT_RIGHT"},
            {game::opcode::OP_Plus, "PLUS"},
            {game::opcode::OP_Minus, "MINUS"},
            {game::opcode::OP_Multiply, "MULT"},
            {game::opcode::OP_Divide, "DIV"},
            {game::opcode::OP_Modulus, "MOD"},
            {game::opcode::OP_SizeOf, "SIZE"},
            {game::opcode::OP_WaitTillMatch, "WAITTILLMATCH"},
            {game::opcode::OP_WaitTill, "WAITTILL"},
            {game::opcode::OP_Notify, "NOTIFY"},
            {game::opcode::OP_EndOn, "ENDON"},
            {game::opcode::OP_VoidCodePos, "VOIDCODEPOS"},
            {game::opcode::OP_Switch, "SWITCH"},
            {game::opcode::OP_EndSwitch, "ENDSWITCH"},
            {game::opcode::OP_Vector, "VECTOR"},
            {game::opcode::OP_GetHash, "GET_HASH"},
            {game::opcode::OP_RealWait, "REAL_WAIT"},
            {game::opcode::OP_VectorConstant, "VECTOR_CONSTANT"},
            {game::opcode::OP_IsDefined, "IS_DEFINED"},
            {game::opcode::OP_VectorScale, "VECTOR_SCALE"},
            {game::opcode::OP_AnglesToUp, "ANGLES_TO_UP"},
            {game::opcode::OP_AnglesToRight, "ANGLES_TO_RIGHT"},
            {game::opcode::OP_AnglesToForward, "ANGLES_TO_FORDWARD"},
            {game::opcode::OP_AngleClamp180, "ANGLE_CLAMP_180"},
            {game::opcode::OP_VectorToAngles, "VECTOR_TO_ANGLES"},
            {game::opcode::OP_Abs, "ABS"},
            {game::opcode::OP_GetTime, "GET_TIME"},
            {game::opcode::OP_GetDvar, "GET_DVAR"},
            {game::opcode::OP_GetDvarInt, "GET_DVAR_INT"},
            {game::opcode::OP_GetDvarFloat, "GET_DVAR_FLOAT"},
            {game::opcode::OP_GetDvarVector, "GET_DVAR_VECTOR"},
            {game::opcode::OP_GetDvarColorRed, "GET_DVAR_COLOR_RED"},
            {game::opcode::OP_GetDvarColorGreen, "GET_DVAR_COLOR_GREEN"},
            {game::opcode::OP_GetDvarColorBlue, "GET_DVAR_COLOR_BLUE"},
            {game::opcode::OP_GetDvarColorAlpha, "GET_DVAR_COLOR_ALPHA"},
            {game::opcode::OP_FirstArrayKey, "FIRST_ARRAY_KEY"},
            {game::opcode::OP_NextArrayKey, "NEXT_ARRAY_KEY"},
            {game::opcode::OP_ProfileStart, "PROFILE_START"},
            {game::opcode::OP_ProfileStop, "PROFILE_STOP"},
            {game::opcode::OP_SafeDecTop, "SAFE_DEC_TOP"},
            {game::opcode::OP_Nop, "NOP"},
            {game::opcode::OP_Abort, "ABORT"},
            {game::opcode::OP_Object, "OBJECT"},
            {game::opcode::OP_ThreadObject, "THREAD_OBJECT"},
            {game::opcode::OP_EvalLocalVariable, "EVAL_LOCAL_VARIABLE"},
            {game::opcode::OP_EvalLocalVariableRef, "EVAL_LOCAL_VARIABLE_REF"},
            {game::opcode::OP_DevblockBegin, "DEVBLOCK_BEGIN"},
            {game::opcode::OP_DevblockEnd, "DEVBLOCK_END"},
            {game::opcode::OP_Breakpoint, "BREAKPOINT"},
        };

        std::string get_opcode_name(const game::opcode opcode)
        {
            if (opcode_map.find(opcode) != opcode_map.end())
            {
                return opcode_map[opcode];
            }

            return "unknown";
        }

        void print_error(const char* msg, ...)
        {
            char buffer[2048];

            va_list ap;
            va_start(ap, msg);

            vsnprintf_s(buffer, sizeof(buffer), _TRUNCATE, msg, ap);

            va_end(ap);

            io::print_to_log("******* script runtime error *******\n");
            io::print_to_log(utils::string::va("%s\n", buffer));
            io::print_to_log(debug::get_call_stack().data());
            io::print_to_log("************************************\n");
        }

        void print_call_error(const game::opcode opcode)
        {
            const auto error = reinterpret_cast<const char*>(SELECT(0x2E27C70, 0x2DF7F70));
            const auto fs_pos = *reinterpret_cast<char**>(SELECT(0x2E23C08, 0x2DF3F08));

            if (opcode == game::opcode::OP_CallBuiltin || opcode == game::opcode::OP_CallBuiltinMethod)
            {
                std::string name{};
                for (auto i = 0; i < 4; i++)
                {
                    const auto ptr = *reinterpret_cast<void**>(fs_pos + i);
                    name = opcode == game::opcode::OP_CallBuiltinMethod
                        ? gsc::find_builtin_method_name(ptr) 
                        : gsc::find_builtin_name(ptr);

                    if (!name.empty())
                    {
                        break;
                    }
                }

                const auto type = opcode == game::opcode::OP_CallBuiltinMethod 
                    ? "method" 
                    : "function";

                print_error("in call to builtin %s \"%s\": %s", type, name.data(), error);
            }
            else
            {
                const auto opcode_name = get_opcode_name(opcode);

                print_error("while processing instruction %s: %s", opcode_name.data(), error);
            }
        }

        void vm_execute_error_stub(utils::hook::assembler& a)
        {
            a.pushad();
            a.push(eax);
            a.call(print_call_error);
            a.pop(eax);
            a.popad();

            a.add(eax, 0xFFFFFFE5);
            a.mov(dword_ptr(ebp, 0x6C), esi);
            a.mov(dword_ptr(ebp, 0x44), edx);

            a.jmp(SELECT(0x8F8A60, 0x8F77C0));
        }

        utils::hook::detour scr_terminal_error_hook;
        void scr_terminal_error_stub(int inst, const char* error)
        {
            io::print_to_log("====================================================\n");
            io::print_to_log(utils::string::va("Scr_TerminalError: %s\n", error));
            io::print_to_log("====================================================\n");
            scr_terminal_error_hook.invoke<void>(inst, error);
        }

        utils::hook::detour alloc_child_variable_hook;
        const char* allocations[0x10000];

        int* alloc_child_variable_stub(int inst, unsigned int* index)
        {
            const auto result = alloc_child_variable_hook.invoke<int*>(inst, index);
            //io::print_to_log(utils::string::va("Allocating variable on %d\n", inst));
            if (inst == game::SCRIPTINSTANCE_SERVER && game::scr_VmPub[inst].function_count)
            {
                const auto pos = game::fs->pos;
                allocations[*index] = pos;
            }
            return result;
        }

        void remove_variable_allocation(unsigned int index, int inst)
        {
            io::print_to_log(utils::string::va("Removing variable on %d at index %d\n", inst, index));
            if (inst == game::SCRIPTINSTANCE_SERVER)
            {
                allocations[index] = nullptr;
            }
        }

        void remove_variable_allocation2(int inst, unsigned int index/*esi*/, int parentValue/*eax*/, int value/*edi*/)
        {
            io::print_to_log(utils::string::va("remove_variable_allocation2 args: %d, %d, %d, %d\n", inst, index, parentValue, value));
            if (inst == game::SCRIPTINSTANCE_SERVER)
            {
                allocations[index] = nullptr;
            }
        }

        void free_child_variable_stub(utils::hook::assembler& a)
        {
            a.pushad();
            a.mov(ebx, ptr(esp, 8));
            a.push(ebx);
            a.push(edi);
            a.call(remove_variable_allocation);
            a.pop(edi);
            a.pop(ebx);
            a.popad();

            a.mov(ecx, dword_ptr(eax, 0x4));
            a.and_(ecx, 0x7F);
            a.push(ebx);

            a.jmp(0x8F1C97);
        }

        void free_child_variable_stub3(int inst, int parentValue/*eax*/, int value/*edi*/, int index/*esi*/)
        {
            static const auto call_func = remove_variable_allocation2;

            static const auto retn_addr = SELECT(0x0, 0x8F1C97);

            __asm
            {
                //pushad;
                push parentValue;
                push value;
                push index;
                push inst;
                call call_func;
                add esp, 0x10;
                //popad;

                mov ecx, dword ptr[eax + 0x4];
                and ecx, 0x7F;
                push ebx;

                jmp retn_addr;
            }
        }

        std::vector<scripting::thread> get_all_threads()
        {
            std::vector<scripting::thread> threads;

            for (auto i = 1; i < 0x8000; i++)
            {
                const auto type = game::scr_VarGlob->objectVariableValue[i].w.type & 0x7F;
                if (type == game::SCRIPT_THREAD || type == game::SCRIPT_TIME_THREAD || type == game::SCRIPT_NOTIFY_THREAD)
                {
                    threads.push_back(i);
                }
            }

            return threads;
        }

        unsigned int get_var_count()
        {
            auto count = 0;

            for (auto i = 0; i < 0x8000; i++)
            {
                const auto type = game::scr_VarGlob->objectVariableValue[i].w.type & 0x7F;
                count += type != game::SCRIPT_FREE;
            }

            return count;
        }

        unsigned int get_child_var_count()
        {
            auto count = 0;

            for (auto i = 0; i < 0x10000; i++)
            {
                const auto type = game::scr_VarGlob->childVariableValue[i].type & 0x7F;
                count += type != game::SCRIPT_FREE;
            }

            return count;
        }

        void kill_current_thread()
        {
            for (auto frame = game::scr_VmPub->function_frame; frame != game::scr_VmPub->function_frame_start; --frame)
            {
                game::Scr_TerminateRunningThread(game::SCRIPTINSTANCE_SERVER, frame->fs.localId);
            }
        }

        void exceeded_max_child_vars_error_stub(int inst, const char* err)
        {
            const std::string name = utils::string::va("minidumps/child-var-allocations-%s.zip", 
                utils::string::get_timestamp().data());

            utils::compression::zip::archive zip_file{};
            zip_file.add("allocations.txt", debug::get_child_var_allocations(1));
            zip_file.write(name, "Redacted T6ZM child variable allocations");

            scr_terminal_error_stub(inst, 
                utils::string::va("%s\na child variable dump has been written at %s", err, name.data()));
        }

        bool check_infinite_loop()
        {
            const auto diff = game::Sys_Milliseconds() - *game::scr_starttime;
            if (scr_max_loop_time && scr_max_loop_time->current.integer && diff > scr_max_loop_time->current.integer)
            {
                game::scr_VmPub->function_frame->fs.pos = game::fs->pos;
                print_error("potential infinite loop in script - %ims elapsed. Killing thread.", diff);
                //kill_current_thread();
                return true;
            }

            return false;
        }

        void vm_execute_jmp_stub(utils::hook::assembler& a)
        {
            const auto kill = a.newLabel();

            a.pushad();
            a.call(check_infinite_loop);
            a.cmp(al, 0);
            a.jne(kill);

            a.popad();
            a.inc(ebx);
            a.and_(ebx, 0xFFFFFFFE);
            a.movzx(eax, word_ptr(ebx));
            a.jmp(SELECT(0x8F891F, 0x8F767F));

            a.bind(kill);
            a.popad();
            a.jmp(SELECT(0x8F7709, 0x8F6469));
        }
    }

    std::string get_call_stack(bool print_local_vars)
    {
        std::string info{};
        const auto line = [&info](const std::string& text)
        {
            info.append(text);
            info.append("\r\n");
        };

        for (auto frame = game::scr_VmPub->function_frame; frame != game::scr_VmPub->function_frame_start; --frame)
        {
            const auto function = scripting::find_function_pair(frame->fs.pos);

            if (function.has_value())
            {
                const auto value = function.value();
                line(utils::string::va("\tat function \"%s\" in file \"%s.gsc\"", value.second.data(), value.first.data()));
            }
            else
            {
                line(utils::string::va("\tat unknown location (%p)", frame->fs.pos));
            }

            const scripting::object local_vars{frame->fs.localId};
            if (local_vars.get_keys().size() && print_local_vars)
            {
                line(utils::string::va("\t\tlocal vars: %s", json::gsc_to_string(local_vars).data()));
            }
        }

        return info;
    }

    std::string get_child_var_allocations(int limit)
    {
        std::string info{};
        const auto line = [&info](const std::string& text)
        {
            info.append(text);
            info.append("\r\n");
        };

        line(utils::string::va("child var allocations where count > %i\n", limit));
        std::unordered_map<std::string, int> allocations_map;

        auto total = 0;
        for (auto i = 0; i < 0x10000; i++)
        {
            const auto pos = allocations[i];
            if (pos == nullptr)
            {
                continue;
            }

            total++;
            const auto pair_value = scripting::find_function_pair(pos);

            if (!pair_value.has_value())
            {
                continue;
            }

            const auto pair = pair_value.value();
            const auto function = utils::string::va("%s::%s", pair.first.data(), pair.second.data());

            allocations_map[function]++;
        }

        std::vector<std::pair<std::string, int>> sorted_allocations(
            allocations_map.begin(), allocations_map.end());
        std::sort(sorted_allocations.begin(), sorted_allocations.end(),
            [](std::pair<std::string, int> a, std::pair<std::string, int> b)
            {
                return a.second > b.second;
            }
        );

        for (const auto& allocation : sorted_allocations)
        {
            if (allocation.second < limit)
            {
                continue;
            }

            line(utils::string::va("%s: %i", allocation.first.data(), allocation.second));
        }

        line(utils::string::va("\ntotal: %i, total calculated: %i", total, get_child_var_count()));

        return info;
    }

    unsigned int get_current_client_count()
    {
        unsigned int max_clients = game::Dvar_FindVar("com_maxclients")->current.integer;
        unsigned int count = 0;
        for (auto i = 0; i < max_clients; i++)
        {
            if (game::g_entities[i].number)
            {
                ++count;
            }
        } 
        return count;
    }

    class component final : public component_interface
    {
    public:
        void post_unpack() override
        {
            //developer_script = game::Dvar_FindVar("developer_script");
            /*
            scr_max_loop_time = game::Dvar_RegisterInt("scr_maxLoopTime", 2500, 0, 
                100000, 0, "Maximum loop time before a thread gets killed, 0: don't kill infinite loops");
            */
            developer_script = 0;
            scr_max_loop_time = 0;

            if (!config::components::debug)
            {
                return;
            }

            utils::hook::jump(SELECT(0x8F8A57, 0x8F77B7), utils::hook::assemble(vm_execute_error_stub));
            //utils::hook::jump(SELECT(0x8F8918, 0x8F7678), utils::hook::assemble(vm_execute_jmp_stub));

            scr_terminal_error_hook.create(SELECT(0x698C50, 0x410440), scr_terminal_error_stub);

            gsc::function::add("getvarusage", [](const gsc::function_args&) -> scripting::script_value
            {
                return get_var_count();
            });

            gsc::function::add("getchildvarusage", [](const gsc::function_args&) -> scripting::script_value
            {
                return get_child_var_count();
            });

            gsc::function::add("getusagestats", [](const gsc::function_args&) -> scripting::script_value
            {
                scripting::object stats{};

                stats["maxvars"] = 0x8000;
                stats["maxchildvars"] = 0x10000;
                stats["childvars"] = get_child_var_count();
                stats["vars"] = get_var_count();

                return stats;
            });

            gsc::function::add("clearlocalizedconfigstring", [](const gsc::function_args& args)
            {
                const auto target = args[0].as<std::string>();

                for (auto i = 489; i < 1000; i++)
                {
                    const auto string_value = game::sv_configstrings[i];
                    std::string string(game::SL_ConvertToString(string_value));

                    //io::print_to_log(utils::string::va("%d Checking string %s against %s first character is %d\n", i, string.data(), target.data(), static_cast<int>(string.front())));

                    if (string != ""s && (string.size() > 0) && string.compare(target) == 0)
                    {
                        //io::print_to_log(utils::string::va("Clearing string %s\n", string.data()));
                        game::SV_SetConfigstring(i, 0);
                        return true;
                    }
                }

                return false;
            });

            gsc::function::add("replacelocalizedconfigstring", [](const gsc::function_args& args)
            {
                const auto target = args[0].as<std::string>();
                const auto new_string = args[1].as<std::string>();

                for (auto i = 489; i < 1000; i++)
                {
                    const auto string_value = game::sv_configstrings[i];
                    std::string string(game::SL_ConvertToString(string_value));

                    if (string != ""s && (string.size() > 0) && string.compare(target) == 0)
                    {
                        game::SV_SetConfigstring(i, new_string.c_str());
                        return true;
                    }
                }

                return false;
            });

            gsc::function::add("dumpconfigstrings", [](const gsc::function_args& args) -> scripting::script_value
            {
                const auto configstrings_file_path = io::get_scriptdata_folder() + "/configstrings.txt"s;

                FILE* handle = nullptr;
                if (fopen_s(&handle, configstrings_file_path.c_str(), "w") != 0)
                {
                    throw std::runtime_error("Failed to open configstrings.txt");
                }

                if (!handle)
                {
                    throw std::runtime_error("Failed to create handle for configstrings.txt");
                }

                for (auto i = 0; i < 2806; i++)
                {
                    fprintf(handle, utils::string::va("%d | %s\n", i, game::SL_ConvertToString(game::sv_configstrings[i]), true));
                }

                fclose(handle);

                return {};
            });

            gsc::function::add("getconfigstringcountfortype", [](const gsc::function_args& args) -> scripting::script_value
            {
                auto type = args[0].as<std::string>();

                auto min_range = 0u;

                auto max_range = 2806u;

                if (type == "localize"s)
                {
                    min_range = 489;
                    max_range = 1000;
                }

                auto count = 0u;
                for (auto i = min_range; i < max_range; i++)
                {
                    const auto string_value = game::sv_configstrings[i];
                    std::string string(game::SL_ConvertToString(string_value));

                    if (string != ""s && string.size() > 0)
                    {
                        count++;
                    }
                }

                return count;
            });

            if (game::environment::t6zm())
            {
                alloc_child_variable_hook.create(0x8F19A0, alloc_child_variable_stub);
                utils::hook::jump(0x8F1C90, utils::hook::assemble(free_child_variable_stub));
                //utils::hook::jump(0x8F1C90, free_child_variable_stub3);
                utils::hook::call(0x8F1A3F, exceeded_max_child_vars_error_stub);

                command::add("printallocations", [](command::params& params)
                {
                    auto limit = 1;
                    if (params.size() > 1)
                    {
                        limit = atoi(params.get(1));
                    }

                    io::print_to_log(get_child_var_allocations(limit).data());
                });

                gsc::function::add("dumpallocations", [](const gsc::function_args& args) -> scripting::script_value
                {
                    const auto scriptdata_folder = io::get_scriptdata_folder();
                    const auto path = args[0].as<std::string>();

                    if (!utils::io::is_file_path_valid(scriptdata_folder, path))
                    {
                        throw std::runtime_error("Directory provided is invalid");
                    }
                    const std::string full_path(scriptdata_folder + "/"s + path);

                    auto limit = 1;
                    if (args.size() >= 2)
                    {
                        limit = args[1].as<int>();
                    }

                    const std::string header = utils::string::va("map: %s,gametype: %s,location: %s,time: %d,clientcount: %d\n", game::Dvar_FindVar("mapname")->current.string,
                                                                                         game::Dvar_FindVar("g_gametype")->current.string,
                                                                                         game::Dvar_FindVar("ui_zm_mapstartlocation")->current.string,
                                                                                         *reinterpret_cast<unsigned int*>(0x2338F18),
                                                                                         get_current_client_count());
                    utils::io::write_file(full_path, header, false);
                    utils::io::write_file(full_path, get_child_var_allocations(limit).data(), true);
                    return {};
                });
            }

            gsc::function::add("printcallstack", [](const gsc::function_args&) -> scripting::script_value
            {
                io::print_to_log(debug::get_call_stack().data());
                return {};
            });

            gsc::function::add("getcallstack", [](const gsc::function_args&) -> scripting::script_value
            {
                return debug::get_call_stack();
            });
        }
    };
}

REGISTER_COMPONENT(debug::component)
