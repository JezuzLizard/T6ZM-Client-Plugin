#include "stdinc.hpp"

#include <game/structs.hpp>
#include <game/game.hpp>

#include <utils/io.hpp>
#include <utils/string.hpp>

#include <component/io.hpp>
#include "assetutil.hpp"

namespace game
{
	void to_json(nlohmann::json& j, const TriggerModel& v)
	{
		QUICK_TO_JSON_FIELD(j, v, contents);
		QUICK_TO_JSON_FIELD(j, v, hullCount);
		QUICK_TO_JSON_FIELD(j, v, firstHull);
	}

	void to_json(nlohmann::json& j, const TriggerHull& v)
	{
		QUICK_TO_JSON_FIELD(j, v, bounds);
		QUICK_TO_JSON_FIELD(j, v, contents);
		QUICK_TO_JSON_FIELD(j, v, slabCount);
		QUICK_TO_JSON_FIELD(j, v, firstSlab);
	}

	void to_json(nlohmann::json& j, const TriggerSlab& v)
	{
		QUICK_TO_JSON_FIELD(j, v, dir);
		QUICK_TO_JSON_FIELD(j, v, midPoint);
		QUICK_TO_JSON_FIELD(j, v, halfSize);
	}

	void to_json(nlohmann::json& j, const MapTriggers& v)
	{
		QUICK_TO_JSON_FIELD_DYNAMIC_ARRAY(j, v, models, count);
		QUICK_TO_JSON_FIELD_DYNAMIC_ARRAY(j, v, hulls, hullCount);
		QUICK_TO_JSON_FIELD_DYNAMIC_ARRAY(j, v, slabs, slabCount);
	}
}

namespace Assets
{
	namespace MapEnts
	{
		std::string mapents_buffer;

		void dump(game::MapEnts* asset)
		{
			std::string buffer;

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

			nlohmann::json j;

			j["mapTriggers"] = asset->trigger;

			buffer = j.dump(4);

			utils::io::write_file(std::format("{}/{}.d3dbsp.mapents.triggers.json", Assets::Utils::get_dump_dir(), asset->name), buffer);
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