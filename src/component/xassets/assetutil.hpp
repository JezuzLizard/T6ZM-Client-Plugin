#pragma once

namespace game
{
#define QUICK_TO_JSON_FIELD(j, v, membername) j[#membername] = v.membername

#define QUICK_TO_JSON_FIELD_SAFE_CSTR(j, v, membername) \
	if (v.membername) \
		j[#membername] = v.membername; \
	else \
		j[#membername] = "(NULL)"

#define QUICK_TO_JSON_FIELD_PTR_ADDR(j, v, membername) j[#membername] = reinterpret_cast<size_t>(&v.membername)

#define QUICK_TO_JSON_FIELD_DYNAMIC_ARRAY(j, v, membername, countname) \
	for (auto i = 0; i < v.countname; i++) \
	{ \
		j[#membername][i] = v.membername[i]; \
	}

#define QUICK_TO_JSON_FIELD_STATIC_ARRAY(j, v, membername) \
	for (auto i = 0; i < ARRAY_COUNT(v.membername); i++) \
	{ \
		j[#membername][i] = v.membername[i]; \
	}

#define QUICK_TO_JSON_FIELD_SL_STRING(j, v, membername) j[#membername "Str"] = SL_ConvertToStringSafe(v.membername, *gInst)
}

namespace Assets
{
	namespace Utils
	{
		const std::string get_dump_dir();
		const std::string get_read_dir(const std::string& filename, game::XAssetType type, int* inIWD);
	}
}