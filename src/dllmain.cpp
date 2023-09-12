#include <stdinc.hpp>
#include "loader/component_loader.hpp"

#include "game/game.hpp"

#include "utils/io.hpp"
#include "utils/string.hpp"

#include <utils/hook.hpp>

#define EXTERN extern "C"
#define DLLEXPORT __declspec(dllexport)
#define EXPORT EXTERN DLLEXPORT

namespace config
{
	char working_directory[1024];
}

EXPORT uint64_t __cdecl PreInit()
{
	const char* path;
	path = _getcwd(config::working_directory, sizeof(config::working_directory));
	if (path == NULL)
	{
		MessageBoxA(NULL,
			"Invalid game directory",
			"ERROR", MB_ICONERROR);
		exit(-1);
	}
	component_loader::post_unpack();
	return 1ull;
}

EXPORT uint64_t __cdecl PostInit()
{
	component_loader::post_load();
	return 1ull;
}

EXPORT uint64_t __cdecl AuthorInfo()
{
	return (uint64_t)"JezuzLizard";
}

EXPORT uint64_t __cdecl ExtendedInfo()
{
	return (uint64_t)("T6ZM-Client-Plugin\n");
}

EXPORT uint64_t __cdecl OfficialMod()
{
	return TRUE;
}

EXPORT uint64_t __cdecl DependencyCount()
{
	return 0;
}

EXPORT uint64_t __cdecl GetDependency(uint32_t Index)
{
	return (uint64_t)nullptr;
}

EXPORT uint64_t __cdecl SendMessageB(const char* Message, void* Callback)
{
	return 1;
}

BOOL APIENTRY DllMain(HMODULE /*module_*/, DWORD ul_reason_for_call, LPVOID /*reserved_*/)
{
	//TODO: get name of parent process to determine whether we use redacted loading vs Plutonium loading
	if (ul_reason_for_call == DLL_PROCESS_ATTACH)
	{
        /*
        if (!signatures::process())
        {
            MessageBoxA(NULL,
                "This version of t6-gsc-utils is outdated.\n" \
                "Download the latest dll from here: https://github.com/fedddddd/t6-gsc-utils/releases",
                "ERROR", MB_ICONERROR);

            return FALSE;
        }
        if (game::plutonium::printf.get() != nullptr)
        {
            utils::hook::jump(reinterpret_cast<uintptr_t>(&printf), game::plutonium::printf);
            component_loader::post_unpack();
        }
        */
	}

	return TRUE;
}