#include "stdinc.hpp"

#include <game/structs.hpp>
#include <game/game.hpp>

#include <utils/io.hpp>
#include <utils/string.hpp>

#include <component/io.hpp>

#include "assetutil.hpp"

namespace Assets
{
	namespace StringTable
	{
		void dump(game::StringTable* asset)
		{
			std::string buffer;

			for (int row = 0; row < asset->rowCount; row++)
			{
				for (int column = 0; column < asset->columnCount; column++)
				{
					buffer += std::format("{}{}",
						(asset->values[(row * asset->columnCount) + column].string)
						? asset->values[(row * asset->columnCount) + column].string
						: "",
						(column == asset->columnCount - 1) ? "\n" : ",");
				}
			}

			io::print_to_log(std::format("Dumping stringtable asset {} from fastfile {}\n", asset->name, game::g_load->filename));

			utils::io::write_file(std::format("dump/{}/{}", game::g_load->filename, asset->name), buffer);
		}

		void _override(game::StringTable* asset)
		{
			if (!asset || !asset->name || asset->name[0] == '\0')
			{
				return;
			}

			int inIWD;
			std::string dir = Assets::Utils::get_read_dir(asset->name, game::ASSET_TYPE_RAWFILE, &inIWD);

			std::string fullpath = std::format("{}/{}", dir, asset->name);

			// TODO: Handle stringtables in IWDs
			if (!utils::io::file_exists(fullpath) || inIWD)
			{
				return;
			}

			std::ifstream f(fullpath);
			try
			{
				io::print_to_log(std::format("Overriding stringtable {}\n", asset->name));
				aria::csv::CsvParser parser(f);
				for (int rowIndex = 0; auto & row : parser)
				{
					for (int columnIndex = 0; auto & field : row)
					{
						asset->values[(rowIndex * asset->columnCount) + columnIndex].string = field.c_str();
						columnIndex++;
					}
					rowIndex++;
				}
			}
			catch (std::exception& e)
			{
				io::print_to_log(std::format("Error while attempting to parse csv {} {}", asset->name, e.what()));
			}
		}
	}
}