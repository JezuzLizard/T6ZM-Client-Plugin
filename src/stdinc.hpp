#pragma once

#pragma warning(disable: 6011)
#pragma warning(disable: 6054)
#pragma warning(disable: 6387)
#pragma warning(disable: 26451)
#pragma warning(disable: 26812)
#pragma warning(disable: 28182)

#define DLL_EXPORT extern "C" __declspec(dllexport)
#define WIN32_LEAN_AND_MEAN
#define REDACTED_STEAM_API_BASE_ADDRESS 0x6A6C0000

#include <windows.h>

#include <vector>
#include <cassert>
#include <mutex>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <regex>
#include <queue>
#include <unordered_set>
#include <filesystem>
#include <map>
#include <csetjmp>
#include <atlcomcli.h>
#include <variant>
#include <optional>
#include <Psapi.h>
#include <stdint.h>
#include <codecvt>
#include <direct.h>

#ifdef max
#undef max
#endif

#ifdef min
#undef min
#endif

#include <MinHook.h>
#include <gsl/gsl>

#include <json.hpp>

#include <asmjit/core/jitruntime.h>
#include <asmjit/x86/x86assembler.h>

#pragma comment(lib, "ntdll.lib")
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "urlmon.lib" )
#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "Crypt32.lib")

using namespace std::literals;

//#define NO_COMP_CHAT
//#define NO_COMP_EXCEPTION
//#define NO_COMP_LUI
//#define NO_COMP_PATCHES

namespace config
{
	extern char working_directory[1024];
}