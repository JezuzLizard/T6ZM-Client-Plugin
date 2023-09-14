#include "stdinc.hpp"

#include <game/structs.hpp>
#include <game/game.hpp>

#include <utils/io.hpp>
#include <utils/string.hpp>

#include <component/io.hpp>
#include "assetutil.hpp"

namespace Assets
{
	namespace MapEnts
	{
		std::string mapents_buffer;

		void dump(game::MapEnts* asset)
		{
			if (!asset || !asset->name || asset->name[0] == '\0')
			{
				return;
			}

			// Don't attempt to dump referenced assets
			if (asset->name[0] == ',')
			{
				return;
			}

			io::print_to_log(std::format("Dumping mapents asset {} from fastfile {}\n", asset->name, game::g_load->filename));

			utils::io::write_file(std::format("{}/{}.d3dbsp.mapents.txt", Assets::Utils::get_dump_dir(), asset->name), asset->entityString);

			nlohmann::json mapTriggers;
		}

		void _override(game::MapEnts* asset)
		{
			int inIWD;
			std::string fullFileName = std::format("{}.d3dbsp.mapents.txt", asset->name);
			std::string dir = Assets::Utils::get_read_dir(fullFileName, game::ASSET_TYPE_MAP_ENTS, &inIWD);
			std::string buffer;

			buffer = utils::io::read_file_using_search_paths(dir, fullFileName, inIWD);

			if (buffer.empty())
			{
				return;
			}

			if (!mapents_buffer.empty())
			{
				mapents_buffer.clear();
			}

			mapents_buffer.assign(buffer, buffer.length());

			asset->entityString = mapents_buffer.data();
			asset->numEntityChars = mapents_buffer.length();
		}
	}
}