#include <stdinc.hpp>
#include "loader/component_loader.hpp"

#include "game/game.hpp"

#include "io.hpp"
#include "gsc.hpp"
#include "scheduler.hpp"

#include "gsc.hpp"
#include "json.hpp"

#include <utils/hook.hpp>
#include <utils/http.hpp>
#include <utils/io.hpp>

namespace io
{
	namespace
	{
		void replace(std::string& str, const std::string& from, const std::string& to) 
		{
			const auto start_pos = str.find(from);

			if (start_pos == std::string::npos)
			{
				return;
			}

			str.replace(start_pos, from.length(), to);
		}

		scripting::script_value http_get(const gsc::function_args& args)
		{
			const auto url = args[0].as<std::string>();
			const scripting::object object{};
			const auto object_id = object.get_entity_id();

			scheduler::once([object_id, url]()
			{
				const auto result = utils::http::get_data(url.data());
				scheduler::once([object_id, result]()
				{
					const auto value = result.has_value()
						? result.value().substr(0, 0x5000)
						: "";
					scripting::notify(object_id, "done", {value});
				});
			}, scheduler::pipeline::async);

			return object;
		}
	}

	bool first_print = true;

	void print_to_log(std::string text)
	{
		const auto path = config::working_directory;
		if (first_print)
		{
			utils::io::write_file(utils::string::va("%s/T6ZM-Client-Plugin.log", path), text, false);
			first_print = false;
		}
		else
		{
			utils::io::write_file(utils::string::va("%s/T6ZM-Client-Plugin.log", path), text, true);
		}
	}

	const std::string get_scriptdata_folder()
	{
		const std::string scriptdata_folder = utils::string::va("%s/data/scriptdata/", (*game::fs_homepath)->current.string);
		if (!utils::io::directory_exists(scriptdata_folder))
		{
			utils::io::create_directory(scriptdata_folder);
		}
		return scriptdata_folder;
	}

	class component final : public component_interface
	{
	public:
		void post_unpack() override
		{
			gsc::function::add("isalphanumeric", [](const gsc::function_args& args)->scripting::script_value
			{
				auto string = args[0].as<std::string>();
				for (char c : string) {
					if (!isalnum(c)) {
						return false;
					}
				}
				return true;
			});

			gsc::function::add("isstringint", [](const gsc::function_args& args)->scripting::script_value
			{
				auto string = args[0].as<std::string>();
				if (string.empty() || ((!isdigit(string[0])) && (string[0] != '-') && (string[0] != '+'))) {
					return false;
				}

				char* p;
				auto number = strtol(string.c_str(), &p, 10);

				return (*p == 0);
			});

			gsc::function::add("isstringfloat", [](const gsc::function_args& args)->scripting::script_value
			{
				auto string = args[0].as<std::string>();
				if (string.empty() || ((!isdigit(string[0])) && (string[0] != '-') && (string[0] != '+') && (string[0] != '.'))) {
					return false;
				}

				char* p;
				auto number = strtof(string.c_str(), &p);

				return (*p == 0);
			});

			gsc::function::add("va", [](const gsc::function_args& args)
			{
				auto fmt = args[0].as<std::string>();

				for (auto i = 1u; i < args.size(); i++)
				{
					const auto arg = args[i].to_string();
					replace(fmt, "%s", arg);
				}

				return fmt;
			});

			gsc::function::add("jsonprint", [](const gsc::function_args& args) -> scripting::script_value
			{
				std::string buffer;

				for (const auto arg : args.get_raw())
				{
					buffer.append(json::gsc_to_string(arg));
					buffer.append("\t");
				}

				io::print_to_log(utils::string::va("%s\n", buffer.data()));
				return {};
			});

			gsc::function::add("fremove", [](const gsc::function_args& args)
			{
				const auto scriptdata_folder = get_scriptdata_folder();
				const auto path = args[0].as<std::string>();
				if (!utils::io::is_file_path_valid(scriptdata_folder, path))
				{
					throw std::runtime_error("Directory provided is invalid");
				}
				std::string full_path(scriptdata_folder + "/"s + path);
				return std::remove(full_path.c_str());
			});

			gsc::function::add("fopen", [](const gsc::function_args& args)
			{
				const auto scriptdata_folder = get_scriptdata_folder();

				const auto path = args[0].as<std::string>();
				if (!utils::io::is_file_path_valid(scriptdata_folder, path))
				{
					throw std::runtime_error("Directory provided is invalid");
				}
				std::string full_path(scriptdata_folder + "/"s + path);

				const auto* mode = args[1].as<const char*>();

				FILE* handle = nullptr;
				if (fopen_s(&handle, full_path.c_str(), mode) != 0)
				{
					throw std::runtime_error("Invalid handle");
				}

				if (!handle)
				{
					io::print_to_log("fopen: Invalid path\n");
				}

				return handle;
			});

			gsc::function::add("fclose", [](const gsc::function_args& args)
			{
				const auto handle = args[0].as_ptr<FILE>();
				return fclose(handle);
			});

			gsc::function::add("fwrite", [](const gsc::function_args& args)
			{
				const auto handle = args[0].as_ptr<FILE>();
				const auto text = args[1].as<std::string>();

				return fprintf(handle, text.c_str());
			});

			gsc::function::add("fread", [](const gsc::function_args& args)
			{
				const auto handle = args[0].as_ptr<FILE>();

				fseek(handle, 0, SEEK_END);
				const auto length = ftell(handle);

				fseek(handle, 0, SEEK_SET);
				char* buffer = (char*)calloc(length, sizeof(char));

				fread(buffer, sizeof(char), length, handle);

				const std::string result = buffer;

				free(buffer);

				return result;
			});

			gsc::function::add("fileexists", [](const gsc::function_args& args)
			{
				const auto scriptdata_folder = get_scriptdata_folder();
				const auto path = args[0].as<std::string>();
				
				if (!utils::io::is_file_path_valid(scriptdata_folder, path))
				{
					throw std::runtime_error("Directory provided is invalid");
				}
				const std::string full_path(scriptdata_folder + "/"s + path);
				return utils::io::file_exists(full_path);
			});

			gsc::function::add("writefile", [](const gsc::function_args& args)
			{
				const auto scriptdata_folder = get_scriptdata_folder();
				const auto path = args[0].as<std::string>();

				if (!utils::io::is_file_path_valid(scriptdata_folder, path))
				{
					throw std::runtime_error("Directory provided is invalid");
				}
				const std::string full_path(scriptdata_folder + "/"s + path);
				const auto data = args[1].as<std::string>();

				auto append = false;
				if (args.size() > 2)
				{
					append = args[2].as<bool>();
				}

				return utils::io::write_file(full_path, data, append);
			});

			gsc::function::add("readfile", [](const gsc::function_args& args)
			{
				const auto scriptdata_folder = get_scriptdata_folder();
				const auto path = args[0].as<std::string>();

				if (!utils::io::is_file_path_valid(scriptdata_folder, path))
				{
					throw std::runtime_error("Directory provided is invalid");
				}
				const std::string full_path(scriptdata_folder + "/"s + path);
				return utils::io::read_file(full_path);
			});

			gsc::function::add("filesize", [](const gsc::function_args& args)
			{
				const auto scriptdata_folder = get_scriptdata_folder();
				const auto path = args[0].as<std::string>();

				if (!utils::io::is_file_path_valid(scriptdata_folder, path))
				{
					throw std::runtime_error("Directory provided is invalid");
				}
				const std::string full_path(scriptdata_folder + "/"s + path);
				return utils::io::file_size(full_path);
			});

			gsc::function::add("createdirectory", [](const gsc::function_args& args)
			{
				const auto scriptdata_folder = get_scriptdata_folder();
				const auto path = args[0].as<std::string>();

				if (!utils::io::is_file_path_valid(scriptdata_folder, path))
				{
					throw std::runtime_error("Directory provided is invalid");
				}
				const std::string full_path(scriptdata_folder + "/"s + path);
				return utils::io::create_directory(full_path);
			});

			gsc::function::add("directoryexists", [](const gsc::function_args& args)
			{
				const auto scriptdata_folder = get_scriptdata_folder();
				const auto path = args[0].as<std::string>();

				if (!utils::io::is_file_path_valid(scriptdata_folder, path))
				{
					throw std::runtime_error("Directory provided is invalid");
				}
				const std::string full_path(scriptdata_folder + "/"s + path);
				return utils::io::directory_exists(full_path);
			});

			gsc::function::add("directoryisempty", [](const gsc::function_args& args)
			{
				const auto scriptdata_folder = get_scriptdata_folder();
				const auto path = args[0].as<std::string>();

				if (!utils::io::is_file_path_valid(scriptdata_folder, path))
				{
					throw std::runtime_error("Directory provided is invalid");
				}
				const std::string full_path(scriptdata_folder + "/"s + path);
				return utils::io::directory_is_empty(full_path);
			});

			gsc::function::add("listfiles", [](const gsc::function_args& args)
			{
				const auto scriptdata_folder = get_scriptdata_folder();
				const auto path = args[0].as<std::string>();

				if (!utils::io::is_file_path_valid(scriptdata_folder, path))
				{
					throw std::runtime_error("Directory provided is invalid");
				}
				const std::string full_path(scriptdata_folder + "/"s + path);
				const auto files = utils::io::list_files(full_path);

				scripting::array array{};
				for (const auto& file : files)
				{
					array.push(file);
				}

				return array;
			});

			gsc::function::add("copyfolder", [](const gsc::function_args& args)
			{
				const auto scriptdata_folder = get_scriptdata_folder();
				const auto source = args[0].as<std::string>();
				const auto target = args[1].as<std::string>();
				
				if (!utils::io::is_file_path_valid(scriptdata_folder, source) || !utils::io::is_file_path_valid(scriptdata_folder, target))
				{
					throw std::runtime_error("Directory provided is invalid");
				}
				const std::string full_path_source(scriptdata_folder + "/"s + source);
				const std::string full_path_target(scriptdata_folder + "/"s + target);
				utils::io::copy_folder(full_path_source, full_path_target);

				return scripting::script_value{};
			});

			gsc::function::add("removefile", [](const gsc::function_args& args)
			{
				const auto scriptdata_folder = get_scriptdata_folder();
				const auto path = args[0].as<std::string>();

				if (!utils::io::is_file_path_valid(scriptdata_folder, path))
				{
					throw std::runtime_error("Directory provided is invalid");
				}
				const std::string full_path(scriptdata_folder + "/"s + path);
				return utils::io::remove_file(full_path);
			});

			gsc::function::add("hashstring", [](const gsc::function_args& args)
			{
				const auto str = args[0].as<std::string>();
				return game::BG_StringHashValue(str.data());
			});

			gsc::function::add("httpget", http_get);
			gsc::function::add("curl", http_get);
		}
	};
}

REGISTER_COMPONENT(io::component)
