#include <stdinc.hpp>
#include "loader/component_loader.hpp"

#include <game/structs.hpp>
#include "game/game.hpp"
#include "game/scripting/safe_execution.hpp"
#include "component/gsc.hpp"

#include "utils/io.hpp"

#include "io.hpp"

#include <utils/hook.hpp>
#include <utils/string.hpp>

namespace assets
{
	namespace
	{
		utils::hook::detour DB_LinkXAssetEntry_hook;

		void* DB_LinkXAssetEntry_original;

		std::unordered_map<std::string, std::unique_ptr<std::string>> rawfile_buffers;

		void dump_rawfile(game::RawFile* rawfile)
		{
			if (!rawfile || !rawfile->name || rawfile->name[0] == '\0')
			{
				return;
			}

			// Don't attempt to dump referenced assets
			if (rawfile->name[0] == ',')
			{
				return;
			}
			io::print_to_log(std::format("Dumping rawfile asset {} from fastfile {}\n", rawfile->name, game::g_load->filename));
			std::string buffer{};
			if (rawfile->buffer)
			{
				buffer.assign(rawfile->buffer, rawfile->len);
			}

			utils::io::write_file(utils::string::va("data/dump/%s/%s", game::g_load->filename, rawfile->name), buffer);
		}

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

			std::string fullpath = std::format("data/asset_overrides/{}", rawfile->name);

			if (!utils::io::file_exists(fullpath))
			{
				return;
			}

			std::string buffer;
			buffer = utils::io::read_file(fullpath);

			if (buffer.empty())
			{
				return;
			}
			io::print_to_log(std::format("Overriding rawfile {}\n", rawfile->name));

			auto itr = rawfile_buffers.find(rawfile->name);
			if (itr != rawfile_buffers.end())
			{
				rawfile_buffers.erase(itr);
			}
			rawfile_buffers[rawfile->name] = std::make_unique<std::string>();
			itr = rawfile_buffers.find(rawfile->name);
			auto rawfile_buffer = itr->second.get();

			rawfile_buffer->assign(buffer, buffer.length());

			rawfile->len = buffer.length();
			rawfile->buffer = rawfile_buffer->data();
			io::print_to_log(std::format("Bytes read {}\n", buffer.length()));
		}

		game::XAssetEntry* DB_LinkXAssetEntry_call(game::XAssetEntry* newEntry, [[maybe_unused]]void* caller_addr, int allowOverride)
		{
			switch (newEntry->asset.type)
			{
			case game::ASSET_TYPE_RAWFILE:
				dump_rawfile(newEntry->asset.header.rawfile);
				override_rawfile(newEntry->asset.header.rawfile);
				break;
			}

			return game::DB_LinkXAssetEntry(newEntry, allowOverride, DB_LinkXAssetEntry_original);
		}
	}

	NAKED void DB_LinkXAssetEntry_stub()
	{
		__asm
		{
			push eax;
			call DB_LinkXAssetEntry_call;
			add esp, 0x4;
			ret;
		}
	}

	class component final : public component_interface
	{
	public:
		void post_unpack() override
		{
			DB_LinkXAssetEntry_hook.create(game::DB_LinkXAssetEntry_ADDR(), DB_LinkXAssetEntry_stub);

			DB_LinkXAssetEntry_original = DB_LinkXAssetEntry_hook.get_original();
		}
	};
}

REGISTER_COMPONENT(assets::component)