#include <stdinc.hpp>
#include "loader/component_loader.hpp"

#include <game/structs.hpp>
#include <game/game.hpp>

#include <utils/hook.hpp>

#include "xassets/rawfile.hpp"
#include "xassets/stringtable.hpp"
#include "xassets/mapents.hpp"

#include "io.hpp"

namespace Assets
{
	namespace
	{
		utils::hook::detour DB_LinkXAssetEntry_hook;

		void* DB_LinkXAssetEntry_original;

		game::XAssetEntry* DB_LinkXAssetEntry_call(game::XAssetEntry* newEntry, [[maybe_unused]]void* caller_addr, int allowOverride)
		{
			switch (newEntry->asset.type)
			{
			case game::ASSET_TYPE_MAP_ENTS:
				MapEnts::dump(newEntry->asset.header.mapEnts);
				MapEnts::_override(newEntry->asset.header.mapEnts);
				break;
			case game::ASSET_TYPE_RAWFILE:
				RawFile::dump(newEntry->asset.header.rawfile);
				RawFile::_override(newEntry->asset.header.rawfile);
				break;
			case game::ASSET_TYPE_STRINGTABLE:
				StringTable::dump(newEntry->asset.header.stringTable);
				StringTable::_override(newEntry->asset.header.stringTable);
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

REGISTER_COMPONENT(Assets::component)