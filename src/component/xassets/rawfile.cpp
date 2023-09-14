#include "stdinc.hpp"

#include <game/structs.hpp>
#include <game/game.hpp>

#include <utils/io.hpp>
#include <utils/string.hpp>

#include <component/io.hpp>

#include "assetutil.hpp"

namespace Assets
{
	namespace RawFile
	{
		std::unordered_map<std::string, std::unique_ptr<std::string>> rawfile_buffers;

		void dump(game::RawFile* asset)
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
			io::print_to_log(std::format("Dumping rawfile asset {} from fastfile {}\n", asset->name, game::g_load->filename));
			std::string buffer{};
			if (asset->buffer)
			{
				buffer.assign(asset->buffer, asset->len);
			}

			utils::io::write_file(std::format("{}/{}/{}", Assets::Utils::get_dump_dir(), game::g_load->filename, asset->name), buffer);
		}

		void _override(game::RawFile* asset)
		{
			if (!asset || !asset->name || asset->name[0] == '\0')
			{
				return;
			}

			int inIWD;
			std::string buffer;
			std::string dir = Assets::Utils::get_read_dir(asset->name, game::ASSET_TYPE_RAWFILE, &inIWD);

			buffer = utils::io::read_file_using_search_paths(dir, asset->name, inIWD);
			if (buffer.empty())
			{
				return;
			}

			io::print_to_log(std::format("Overriding rawfile {}\n", asset->name));

			auto itr = rawfile_buffers.find(asset->name);
			if (itr != rawfile_buffers.end())
			{
				rawfile_buffers.erase(itr);
			}
			rawfile_buffers[asset->name] = std::make_unique<std::string>();
			itr = rawfile_buffers.find(asset->name);
			auto rawfile_buffer = itr->second.get();

			rawfile_buffer->assign(buffer, buffer.length());

			asset->len = buffer.length();
			asset->buffer = rawfile_buffer->data();
		}
	};
}