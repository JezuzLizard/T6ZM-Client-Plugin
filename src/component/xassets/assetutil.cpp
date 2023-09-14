#include "stdinc.hpp"

#include <game/structs.hpp>

#include "assetutil.hpp"

namespace Assets
{
	namespace Utils
	{
		const std::string dump_dir = "dump";
		const std::string default_read_dir = "raw";

		const std::string get_dump_dir()
		{
			return dump_dir;
		}

		const std::string get_read_dir(const std::string& filename, game::XAssetType type, int* inIWD)
		{
			// TODO: Handle IWDs and maps
			*inIWD = false;
			return default_read_dir;
		}
	}
}