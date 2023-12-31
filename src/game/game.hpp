#pragma once

#include "structs.hpp"

#define SELECT(mp, zm) (game::environment::t6mp() ? mp : zm)
#define ASSIGN(type, mp, sp) reinterpret_cast<type>(SELECT(mp, sp))
#define CALL_ADDR(mp, sp) ASSIGN(void*, mp, sp)

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

namespace game
{
	enum gamemode
	{
		none,
		multiplayer,
		zombies
	};

	extern gamemode current;

	namespace environment
	{
		bool t6mp();
		bool t6zm();
	}

	template <typename T>
	class symbol
	{
	public:
		symbol(const size_t t6mp, const size_t t6zm)
			: t6mp_(reinterpret_cast<T*>(t6mp))
			, t6zm_(reinterpret_cast<T*>(t6zm))
		{
		}

		T* get() const
		{
			if (environment::t6mp())
			{
				return t6mp_;
			}

			return t6zm_;
		}

		void set(const size_t ptr)
		{
			this->t6mp_ = reinterpret_cast<T*>(ptr);
			this->t6zm_ = reinterpret_cast<T*>(ptr);
		}

		operator T* () const
		{
			return this->get();
		}

		T* operator->() const
		{
			return this->get();
		}

	private:
		T* t6mp_;
		T* t6zm_;
	};

	void add(int);
	void add(float);
	void add(const char*);
	void add(gentity_s*);
	void add(void*);

	template <typename T>
	T get(int index);

	template <typename T>
	T get_ptr(int index)
	{
		const auto value = reinterpret_cast<int (*)(unsigned int, unsigned int)>(SELECT(0x45D840, 
			0x49A060))(0, index);

		return reinterpret_cast<T>(value);
	}

	gentity_s* GetEntity(scr_entref_t entref);
	scr_entref_t Scr_GetEntityIdRef(unsigned int entId);
	void Scr_TerminateWaitThread(scriptInstance_t inst, unsigned int localId, unsigned int startLocalId);
	void Scr_TerminateWaittillThread(scriptInstance_t inst, unsigned int localId, unsigned int startLocalId);

	void to_json(nlohmann::json& j, const Bounds& v);

	inline void* DB_LinkXAssetEntry_ADDR() { return CALL_ADDR(0x0, 0x7FCCC0); }
	XAssetEntry* DB_LinkXAssetEntry(XAssetEntry* newEntry, int allowOverride, void* call_addr = DB_LinkXAssetEntry_ADDR());
}

#include "symbols.hpp"