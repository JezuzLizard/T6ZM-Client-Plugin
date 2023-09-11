#include <stdinc.hpp>
#include "loader/component_loader.hpp"

#include "game/game.hpp"
#include "game/scripting/safe_execution.hpp"
#include "component/gsc.hpp"

#include "utils/io.hpp"

#include "io.hpp"

#include <utils/hook.hpp>
#include <utils/string.hpp>

#ifndef NO_COMP_LUI
namespace lui
{
	namespace
	{
		utils::hook::detour LUI_CoD_GetRawFile_hook;

		std::unordered_map<std::string, std::unique_ptr<std::string>> rawfile_buffers;

		void override_rawfile(game::RawFile* rawfile)
		{
			if (!rawfile || !rawfile->name || rawfile->name[0] == '\0')
			{
				return;
			}

			if (rawfile->name[0] == ',')
			{
				return;
			}

			std::string buffer{};

			std::string full_path = utils::string::va("%s/data/%s", (*game::fs_homepath)->current.string, utils::string::to_lower(rawfile->name).data());

			auto num_bytes = utils::io::file_size(full_path);

			if (num_bytes <= 0)
			{
				return;
			}

			buffer = utils::io::read_file(full_path);

			io::print_to_log(utils::string::va("Overriding luafile %s\n", rawfile->name));

			auto itr = rawfile_buffers.find(rawfile->name);
			if (itr != rawfile_buffers.end())
			{
				rawfile_buffers.erase(itr);
			}
			rawfile_buffers[rawfile->name] = std::make_unique<std::string>();
			itr = rawfile_buffers.find(rawfile->name);
			auto rawfile_buffer = itr->second.get();

			rawfile_buffer->assign(buffer, num_bytes);

			rawfile->len = num_bytes;
			rawfile->buffer = rawfile_buffer->data();
		}

		game::RawFile* LUI_CoD_GetRawFile_stub(const char* name)
		{
			auto lua_file = LUI_CoD_GetRawFile_hook.invoke<game::RawFile*>(name);

			override_rawfile(lua_file);

			return lua_file;
		}
	}

	class component final : public component_interface
	{
	public:
		void post_unpack() override
		{
			//LUI_CoD_GetRawFile_hook.create(0x4A7550, LUI_CoD_GetRawFile_stub);
		}
	};
}

REGISTER_COMPONENT(lui::component)
#endif