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

namespace config
{
	namespace components
	{
		__declspec(selectany) bool chat;
		__declspec(selectany) bool command;
		__declspec(selectany) bool debug;
		__declspec(selectany) bool exception;
		__declspec(selectany) bool gsc;
		__declspec(selectany) bool io;
		__declspec(selectany) bool json;
		__declspec(selectany) bool lui;
		__declspec(selectany) bool patches;
		__declspec(selectany) bool scheduler;
		__declspec(selectany) bool scripting;
	}

	namespace features
	{

	}
}