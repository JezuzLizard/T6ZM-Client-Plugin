#include <stdinc.hpp>
#include <fstream>
#include "io.hpp"

namespace utils::io
{
	bool remove_file(const std::string& file)
	{
		return DeleteFileA(file.data()) == TRUE;
	}

	bool file_exists_in_iwd(const std::string& file)
	{
		// TODO
		return false;
	}

	bool file_exists(const std::string& file)
	{
		return std::ifstream(file).good();
	}

	bool write_file(const std::string& file, const std::string& data, const bool append)
	{
		const auto pos = file.find_last_of("/\\");
		if (pos != std::string::npos)
		{
			create_directory(file.substr(0, pos));
		}

		std::ofstream stream(
			file, std::ios::binary | std::ofstream::out | (append ? std::ofstream::app : 0));

		if (stream.is_open())
		{
			stream.write(data.data(), data.size());
			stream.close();
			return true;
		}

		return false;
	}

	std::string read_file_using_search_paths(const std::string& dir, const std::string& file, const int inIWD)
	{
		std::string buffer;
		std::string fullpath;
		if (inIWD)
		{
			// TODO: Check IWDs next
			return "";
		}
		else
		{
			fullpath += dir + "/" + file;
			if (!utils::io::file_exists(fullpath))
			{
				return "";
			}
		}

		return read_file(fullpath);
	}

	std::string read_file(const std::string& file)
	{
		std::string data;
		read_file(file, &data);
		return data;
	}

	bool read_file(const std::string& file, std::string* data)
	{
		if (!data) return false;
		data->clear();

		if (file_exists(file))
		{
			std::ifstream stream(file, std::ios::binary);
			if (!stream.is_open()) return false;

			stream.seekg(0, std::ios::end);
			const std::streamsize size = stream.tellg();
			stream.seekg(0, std::ios::beg);

			if (size > -1)
			{
				data->resize(static_cast<uint32_t>(size));
				stream.read(const_cast<char*>(data->data()), size);
				stream.close();
				return true;
			}
		}

		return false;
	}

	size_t file_size(const std::string& file)
	{
		if (file_exists(file))
		{
			std::ifstream stream(file, std::ios::binary);

			if (stream.good())
			{
				stream.seekg(0, std::ios::end);
				return static_cast<size_t>(stream.tellg());
			}
		}

		return 0;
	}

	bool create_directory(const std::string& directory)
	{
		return std::filesystem::create_directories(directory);
	}

	bool directory_exists(const std::string& directory)
	{
		return std::filesystem::is_directory(directory);
	}

	bool directory_is_empty(const std::string& directory)
	{
		return std::filesystem::is_empty(directory);
	}

	std::vector<std::string> list_files(const std::string& directory)
	{
		std::vector<std::string> files;

		for (auto& file : std::filesystem::directory_iterator(directory))
		{
			files.push_back(file.path().generic_string());
		}

		return files;
	}

	void copy_folder(const std::filesystem::path& src, const std::filesystem::path& target)
	{
		std::filesystem::copy(src, target, std::filesystem::copy_options::overwrite_existing | std::filesystem::copy_options::recursive);
	}

	//EBIC chatGPT code
	bool is_file_path_valid(const std::string& root, const std::string& path)
	{
		std::vector<std::string> components;
		size_t start = 0, end = 0;
		while ((end = path.find('/', start)) != std::string::npos)
		{
			std::string component = path.substr(start, end - start);
			components.push_back(component);
			start = end + 1;
		}
		components.push_back(path.substr(start));

		// Check each component for directory traversal
		for (const std::string& component : components)
		{
			if (component == "..") {
				// Parent directory reference detected
				return false;
			}
		}

		// The file path is valid
		return true;
	}

	/*
	void parse_ini_file(const std::string& filePath, std::map<std::string,std::map<std::string,std::string>>& config_file) 
	{
		std::ifstream file(filePath);
		if (!file.is_open()) 
		{
			throw std::runtime_error("Failed to open file");
		}

		std::string line;
		std::string currentSection;
		while (std::getline(file, line)) 
		{
			if (line.empty() || line[0] == '#') 
			{
				continue; // Ignore empty lines and comments
			}
			if (line[0] == '[') {
				// This line contains a new section
				currentSection = line.substr(1, line.find(']') - 1);
				continue;
			}
			auto delimiterPos = line.find('=');
			auto key = line.substr(0, delimiterPos);
			auto value = line.substr(delimiterPos + 1);
			key.erase(std::remove_if(key.begin(), key.end(), ::isspace), key.end());
			value.erase(std::remove_if(value.begin(), value.end(), ::isspace), value.end());
			config_file[currentSection][key] = value;
		}
	}
	*/
}