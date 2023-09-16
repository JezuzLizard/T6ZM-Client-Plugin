#include <stdinc.hpp>
#include "game.hpp"

#include <utils/hook.hpp>

namespace game
{
	gamemode current = reinterpret_cast<const char*>(0xC2F028) == "multiplayer"s
		? gamemode::multiplayer
		: gamemode::zombies;

	namespace environment
	{
		bool t6mp()
		{
			return current == gamemode::multiplayer;
		}

		bool t6zm()
		{
			return current == gamemode::zombies;
		}
	}

	void add(int value)
	{
		game::Scr_AddInt(SCRIPTINSTANCE_SERVER, value);
	}

	void add(float value)
	{
		game::Scr_AddFloat(SCRIPTINSTANCE_SERVER, value);
	}

	void add(float* value)
	{
		game::Scr_AddVector(SCRIPTINSTANCE_SERVER, value);
	}

	void add(const char* value)
	{
		game::Scr_AddString(SCRIPTINSTANCE_SERVER, value);
	}

	void add(gentity_s* value)
	{
		game::Scr_AddEntity(SCRIPTINSTANCE_SERVER, value);
	}

	void add(void* value)
	{
		game::Scr_AddInt(SCRIPTINSTANCE_SERVER, reinterpret_cast<uintptr_t>(value));
	}

	template <>
	int get(int index)
	{
		return game::Scr_GetInt(SCRIPTINSTANCE_SERVER, index);
	}

	template <>
	float get(int index)
	{
		return game::Scr_GetFloat(SCRIPTINSTANCE_SERVER, index);
	}

	template <>
	const char* get(int index)
	{
		return game::Scr_GetString(SCRIPTINSTANCE_SERVER, index);
	}

	template <>
	std::string get(int index)
	{
		return game::Scr_GetString(SCRIPTINSTANCE_SERVER, index);
	}

	gentity_s* GetEntity(scr_entref_t entref)
	{
		if (entref.classnum != 0)
		{
			game::Scr_ObjectError(SCRIPTINSTANCE_SERVER, "Not an entity");
			return nullptr;
		}

		assert(entref.entnum < (1 << 10));

		return &game::g_entities[entref.entnum];
	}

	scr_entref_t Scr_GetEntityIdRef(unsigned int entId)
	{
		scr_entref_t entref{};

		const auto v2 = &game::scr_VarGlob->objectVariableValue[entId];

		entref.entnum = v2->u.f.next;
		entref.classnum = gsl::narrow_cast<unsigned short>(v2->w.classnum >> 8);

		return entref;
	}

	unsigned int SL_GetHashCode(const char* str, unsigned int len)
	{
		unsigned int i;

		if (len >= 256)
			return (len >> 2) % 0xBFFF + 1;
		for (i = 0; len; --len)
			i = 31 * i + *str++;
		return i % 0xBFFF + 1;
	}

	void Scr_TerminateWaitThread(scriptInstance_t inst, unsigned int localId, unsigned int startLocalId)
	{
		static const auto func = utils::hook::assemble([](utils::hook::assembler& a)
		{
			a.pushad();
			a.mov(esi, dword_ptr(esp, 0x24));
			a.push(dword_ptr(esp, 0x28));
			a.push(dword_ptr(esp, 0x2C));
			a.call(SELECT(0x8F4620, 0x8F3380));
			a.add(esp, 0x8);
			a.popad();

			a.ret();
		});

		utils::hook::invoke<void>(func, inst, localId, startLocalId);
	}

	void Scr_TerminateWaittillThread(scriptInstance_t inst, unsigned int localId, unsigned int startLocalId)
	{
		static const auto func = utils::hook::assemble([](utils::hook::assembler& a)
		{
			a.pushad();
			a.mov(esi, dword_ptr(esp, 0x24));
			a.mov(edi, dword_ptr(esp, 0x28));
			a.push(dword_ptr(esp, 0x2C));
			a.call(SELECT(0x8F4750, 0x8F34B0));
			a.add(esp, 0x4);
			a.popad();

			a.ret();
		});

		utils::hook::invoke<void>(func, inst, localId, startLocalId);
	}

	namespace plutonium
	{
		bool is_up_to_date()
		{
			return true;
		}
	}

	void to_json(nlohmann::json& j, const Bounds& v)
	{
		QUICK_TO_JSON_FIELD(j, v, midPoint);
		QUICK_TO_JSON_FIELD(j, v, halfSize);
	}

	// XAssetEntry* __usercall DB_LinkXAssetEntry@<eax>(XAssetEntry* newEntry@<eax>, int allowOverride)
	XAssetEntry* DB_LinkXAssetEntry(XAssetEntry* newEntry, int allowOverride, void* call_addr)
	{
		XAssetEntry* answer;

		__asm
		{
			push allowOverride;
			mov eax, newEntry;
			call call_addr;
			add esp, 0x4;
			mov answer, eax;
		}

		return answer;
	}
}
