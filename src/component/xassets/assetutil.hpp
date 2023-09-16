#pragma once

namespace Assets
{
	namespace Utils
	{
		const std::string get_dump_dir();
		const std::string get_read_dir(const std::string& filename, game::XAssetType type, int* inIWD);
	}
}