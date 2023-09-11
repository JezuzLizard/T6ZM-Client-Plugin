#include <stdinc.hpp>
#include "loader/component_loader.hpp"
#include "utils/hook.hpp"

//#include "csc.hpp"
#include "gsc.hpp"
//#include "test.hpp"
#include "scheduler.hpp"
//#include "script.hpp"

/*
#define MAX_CSC_HUDELEMS 2048
#define MAX_CSC_HUDELEM_FIELDS 51
#define MAX_CSC_ARCHIVED_HUDELEMS 64

namespace csc_hud
{
	struct hudelem_waypoint_data
	{
		int useWaypointData;
		float iconWidth;
		float iconHeight;
		float offscreenPointerDistance;
		float offscreenDistanceAlphaThreshold;
		float offscreenPointerWidth;
		float offscreenPointerHeight;
		float offscreenPadLeft;
		float offscreenPadRight;
		float offscreenPadTop;
		float offscreenPadBottom;
		float tweakY;
		float playerOffsetProne;
		float playerOffsetCrouch;
		float playerOffsetStand;
		float offscreenScaleLength;
		float offscreenScaleSmallest;
		float distScaleRangeMin;
		float distScaleRangeMax;
		float distScaleSmallest;
		int showOffscreenPointer;
		int showMaterialOffscreen;
		int showMaterial;
		int showLabelOffscreen;
	};

	struct csc_hudelem_s
	{
		game::hudelem_s elem;
		char nameId[16];
		int clientNum;
		int archived;
		char label[256];
		char text[256];
		char materialName[64];
		char offscreenPointerMaterialName[64];
		hudelem_waypoint_data waypointData;
	};

	struct __declspec(align(4)) csc_hudelem_field_t
	{
		const char* name;
		int ofs;
		game::fieldtype_t type;
		int mask;
		int shift;
		void(__cdecl* setter)(csc_hudelem_s*, int);
		void(__cdecl* getter)(csc_hudelem_s*, int);
	};

	enum csc_hudelem_netfield_e
	{
		CSC_HE_NETFIELD_TYPE_INT = 0x0,
		CSC_HE_NETFIELD_TYPE_FLOAT = 0x1,
		CSC_HE_NETFIELD_TYPE_STRING = 0x2,
		CSC_HE_NETFIELD_TYPE_COLOR = 0x3,
		CSC_HE_NETFIELD_TYPE_COUNT = 0x4,
	};

	union csc_hudelem_netfield_value
	{
		int intValue;
		const char* stringValue;
		float floatValue;
	};

	struct csc_hudelem_netfield_t
	{
		const char* name;
		const char* id;
		int ofs;
		csc_hudelem_netfield_e type;
	};

	struct csc_hudelem_netfield_data
	{
		const char* id;
		void* newValue;
	};

	namespace
	{
		utils::hook::detour CG_Draw2dHudElems_hook;

		utils::hook::detour P_DamageFeedback_hook;

		void* P_DamageFeedback_original;

		csc_hudelem_s csc_hudelems[MAX_CSC_HUDELEMS];

		csc_hudelem_s csc_hudelems_for_deltas[MAX_CSC_HUDELEMS];

		std::unordered_map<std::string, std::string> serverArchivedHudelemIds;

		std::unordered_map<std::string, csc_hudelem_s*> clientArchivedHudelems;

		int archivedHudelemClientCount = 0;

		int archivedHudelemServerCount = 0;

		int cscHudelemNetfieldId = 0;

		csc_hudelem_netfield_t cscHudelemNetfields[71] =
		{
			{"type", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, elem.type), CSC_HE_NETFIELD_TYPE_INT},
			{"x", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, elem.x), CSC_HE_NETFIELD_TYPE_FLOAT},
			{"y", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, elem.y), CSC_HE_NETFIELD_TYPE_FLOAT},
			{"z", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, elem.z), CSC_HE_NETFIELD_TYPE_FLOAT},
			{"targetEntNum", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, elem.targetEntNum), CSC_HE_NETFIELD_TYPE_INT},
			{"fontScale", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, elem.fontScale), CSC_HE_NETFIELD_TYPE_FLOAT},
			{"fromFontScale", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, elem.fromFontScale), CSC_HE_NETFIELD_TYPE_FLOAT},
			{"fontScaleStartTime", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, elem.fontScaleStartTime), CSC_HE_NETFIELD_TYPE_INT},
			{"fontScaleTime", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, elem.fontScaleTime), CSC_HE_NETFIELD_TYPE_INT},
			{"font", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, elem.font), CSC_HE_NETFIELD_TYPE_INT},
			{"alignOrg", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, elem.alignOrg), CSC_HE_NETFIELD_TYPE_INT},
			{"alignScreen", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, elem.alignScreen), CSC_HE_NETFIELD_TYPE_INT},
			{"color", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, elem.color), CSC_HE_NETFIELD_TYPE_COLOR},
			{"fromColor", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, elem.fromColor), CSC_HE_NETFIELD_TYPE_COLOR},
			{"fadeStartTime", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, elem.fadeStartTime), CSC_HE_NETFIELD_TYPE_INT},
			{"fadeTime", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, elem.fadeTime), CSC_HE_NETFIELD_TYPE_INT},
			//{"label", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, elem.label), CSC_HE_NETFIELD_TYPE_INT},
			{"width", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, elem.width), CSC_HE_NETFIELD_TYPE_INT},
			{"height", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, elem.height), CSC_HE_NETFIELD_TYPE_INT},
			{"materialIndex", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, elem.materialIndex), CSC_HE_NETFIELD_TYPE_INT},
			{"offscreenMaterialIdx", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, elem.offscreenMaterialIdx), CSC_HE_NETFIELD_TYPE_INT},
			{"fromWidth", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, elem.fromWidth), CSC_HE_NETFIELD_TYPE_INT},
			{"fromHeight", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, elem.fromHeight), CSC_HE_NETFIELD_TYPE_INT},
			{"scaleStartTime", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, elem.scaleStartTime), CSC_HE_NETFIELD_TYPE_INT},
			{"scaleTime", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, elem.scaleTime), CSC_HE_NETFIELD_TYPE_INT},
			{"fromX", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, elem.fromX), CSC_HE_NETFIELD_TYPE_FLOAT},
			{"fromY", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, elem.fromY), CSC_HE_NETFIELD_TYPE_FLOAT},
			{"fromAlignOrg", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, elem.fromAlignOrg), CSC_HE_NETFIELD_TYPE_INT},
			{"fromAlignScreen", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, elem.fromAlignScreen), CSC_HE_NETFIELD_TYPE_INT},
			{"moveStartTime", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, elem.moveStartTime), CSC_HE_NETFIELD_TYPE_INT},
			{"moveTime", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, elem.moveTime), CSC_HE_NETFIELD_TYPE_INT},
			{"time", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, elem.time), CSC_HE_NETFIELD_TYPE_INT},
			{"duration", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, elem.duration), CSC_HE_NETFIELD_TYPE_INT},
			{"value", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, elem.value), CSC_HE_NETFIELD_TYPE_FLOAT},
			//{"text", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, elem.text), CSC_HE_NETFIELD_TYPE_INT},
			{"sort", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, elem.sort), CSC_HE_NETFIELD_TYPE_FLOAT},
			{"fxBirthTime", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, elem.fxBirthTime), CSC_HE_NETFIELD_TYPE_INT},
			{"fxLetterTime", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, elem.fxLetterTime), CSC_HE_NETFIELD_TYPE_INT},
			{"fxDecayStartTime", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, elem.fxDecayStartTime), CSC_HE_NETFIELD_TYPE_INT},
			{"fxDecayDuration", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, elem.fxDecayDuration), CSC_HE_NETFIELD_TYPE_INT},
			{"soundID", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, elem.soundID), CSC_HE_NETFIELD_TYPE_INT},
			{"flags", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, elem.flags), CSC_HE_NETFIELD_TYPE_INT},
			{"nameId", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, nameId), CSC_HE_NETFIELD_TYPE_STRING},
			{"clientnum", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, clientNum), CSC_HE_NETFIELD_TYPE_INT},
			{"archived", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, archived), CSC_HE_NETFIELD_TYPE_INT},
			{"label", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, label), CSC_HE_NETFIELD_TYPE_STRING},
			{"text", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, text), CSC_HE_NETFIELD_TYPE_STRING},
			{"materialname", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, materialName), CSC_HE_NETFIELD_TYPE_STRING},
			{"offscreenPointerMaterialName", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, offscreenPointerMaterialName), CSC_HE_NETFIELD_TYPE_STRING},
			{"iconwidth", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, waypointData.iconWidth), CSC_HE_NETFIELD_TYPE_FLOAT},
			{"iconheight", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, waypointData.iconHeight), CSC_HE_NETFIELD_TYPE_FLOAT},
			{"offscreenPointerDistance", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, waypointData.offscreenPointerDistance), CSC_HE_NETFIELD_TYPE_FLOAT},
			{"offscreenDistanceAlphaThreshold", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, waypointData.offscreenDistanceAlphaThreshold), CSC_HE_NETFIELD_TYPE_FLOAT},
			{"offscreenPointerWidth", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, waypointData.offscreenPointerWidth), CSC_HE_NETFIELD_TYPE_FLOAT},
			{"offscreenPointerHeight", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, waypointData.offscreenPointerHeight), CSC_HE_NETFIELD_TYPE_FLOAT},
			{"offscreenPadLeft", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, waypointData.offscreenPadLeft), CSC_HE_NETFIELD_TYPE_FLOAT},
			{"offscreenPadRight", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, waypointData.offscreenPadRight), CSC_HE_NETFIELD_TYPE_FLOAT},
			{"offscreenPadTop", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, waypointData.offscreenPadTop), CSC_HE_NETFIELD_TYPE_FLOAT},
			{"offscreenPadBottom", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, waypointData.offscreenPadBottom), CSC_HE_NETFIELD_TYPE_FLOAT},
			{"tweakY", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, waypointData.tweakY), CSC_HE_NETFIELD_TYPE_FLOAT},
			{"playerOffsetProne", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, waypointData.playerOffsetProne), CSC_HE_NETFIELD_TYPE_FLOAT},
			{"playerOffsetCrouch", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, waypointData.playerOffsetCrouch), CSC_HE_NETFIELD_TYPE_FLOAT},
			{"playerOffsetStand", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, waypointData.playerOffsetStand), CSC_HE_NETFIELD_TYPE_FLOAT},
			{"offscreenScaleLength", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, waypointData.offscreenScaleLength), CSC_HE_NETFIELD_TYPE_FLOAT},
			{"offscreenScaleSmallest", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, waypointData.offscreenScaleSmallest), CSC_HE_NETFIELD_TYPE_FLOAT},
			{"distScaleRangeMin", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, waypointData.distScaleRangeMin), CSC_HE_NETFIELD_TYPE_FLOAT},
			{"distScaleRangeMax", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, waypointData.distScaleRangeMax), CSC_HE_NETFIELD_TYPE_FLOAT},
			{"distScaleSmallest", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, waypointData.distScaleSmallest), CSC_HE_NETFIELD_TYPE_FLOAT},
			{"showOffscreenPointer", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, waypointData.showOffscreenPointer), CSC_HE_NETFIELD_TYPE_INT},
			{"showMaterialOffscreen", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, waypointData.showMaterialOffscreen), CSC_HE_NETFIELD_TYPE_INT},
			{"showMaterial", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, waypointData.showMaterial), CSC_HE_NETFIELD_TYPE_INT},
			{"showLabelOffscreen", "f" + cscHudelemNetfieldId++, offsetof(csc_hudelem_s, waypointData.showLabelOffscreen), CSC_HE_NETFIELD_TYPE_INT},
			{0, 0, 0, CSC_HE_NETFIELD_TYPE_INT},
		};

		const char* g_he_font[6] =
		{
			"default",
			"bigfixed",
			"smallfixed",
			"objective",
			"big",
			"small"
		};

		const char* g_he_alignx[3] =
		{
			"left",
			"center",
			"right"
		};

		const char* g_he_aligny[3] =
		{
			"top",
			"middle",
			"bottom"
		};

		const char* g_he_textstyle[3] =
		{
			"normal",
			"shadowed",
			"shadowedmore"
		};

		const char* g_he_horzalign[8] =
		{
			"subleft",
			"left",
			"center",
			"right",
			"fullscreen",
			"noscale",
			"alignto640",
			"center_safearea"
		};

		const char* g_he_vertalign[8] =
		{
			"subtop",
			"top",
			"middle",
			"bottom",
			"fullscreen",
			"noscale",
			"alignto480",
			"center_safearea"
		};

		const char* he_flag_names[8] =
		{
			"NONE",
			"FOREGROUND",
			"HIDEWHENDEAD",
			"HIDEWHENINMENU",
			"SHADOWED",
			"SHADOWEDMORE",
			"3DFONTUSEGLOWCOLOR",
			"HIDEWHENINSCOPE",
		};

		int he_flag_values[8] =
		{
			0x0,
			0x1,
			0x2,
			0x4,
			0x8,
			0x10,
			0x20,
			0x40,
		};

		game::Material* Material_Register(const char* name)
		{
			game::Material* result;

			if ((*game::useFastFile)->current.enabled)
				result = game::Material_Register_FastFile(name).material;
			else
				result = game::Material_Register_LoadObj(name);
			return result;
		}

		game::Material* Material_RegisterHandle(const char* name)
		{
			if (!*name)
			{
				return game::rgp->defaultMaterial;
			}
			return Material_Register(name);
		}

		void HudElem_SetFontScale(csc_hudelem_s* elem, int offset);
		void HudElem_SetFont(csc_hudelem_s* elem, int offset);
		void HudElem_GetFont(csc_hudelem_s* elem, int offset);
		void HudElem_SetAlignX(csc_hudelem_s* elem, int offset);
		void HudElem_GetAlignX(csc_hudelem_s* elem, int offset);
		void HudElem_SetAlignY(csc_hudelem_s* elem, int offset);
		void HudElem_GetAlignY(csc_hudelem_s* elem, int offset);
		void HudElem_SetHorzAlign(csc_hudelem_s* elem, int offset);
		void HudElem_GetHorzAlign(csc_hudelem_s* elem, int offset);
		void HudElem_SetVertAlign(csc_hudelem_s* elem, int offset);
		void HudElem_GetVertAlign(csc_hudelem_s* elem, int offset);
		void HudElem_SetColor(csc_hudelem_s* elem, int offset);
		void HudElem_GetColor(csc_hudelem_s* elem, int offset);
		void HudElem_SetAlpha(csc_hudelem_s* elem, int offset);
		void HudElem_GetAlpha(csc_hudelem_s* elem, int offset);
		void HudElem_SetLocalizedString(csc_hudelem_s* elem, int offset);
		void HudElem_GetLocalizedString(csc_hudelem_s* hud, int offset);
		void HudElem_SetFlagForeground(csc_hudelem_s* elem, int offset);
		void HudElem_GetFlagForeground(csc_hudelem_s* elem, int offset);
		void HudElem_SetFlagHideWhenDead(csc_hudelem_s* elem, int offset);
		void HudElem_GetFlagHideWhenDead(csc_hudelem_s* elem, int offset);
		void HudElem_SetFlagHideWhenInMenu(csc_hudelem_s* elem, int offset);
		void HudElem_GetFlagHideWhenInMenu(csc_hudelem_s* elem, int offset);
		void HudElem_SetFlagHideWhenInScope(csc_hudelem_s* hud, int offset);
		void HudElem_GetFlagHideWhenInScope(csc_hudelem_s* hud, int offset);
		void HudElem_SetFontStyle3d(csc_hudelem_s* elem, int offset);
		void HudElem_GetFontStyle3d(csc_hudelem_s* elem, int offset);
		void HudElem_SetFont3dUseGlowColor(csc_hudelem_s* elem, int offset);
		void HudElem_GetFont3dUseGlowColor(csc_hudelem_s* elem, int offset);
		void HudElem_SetGlowColor(csc_hudelem_s* elem, int offset);
		void HudElem_GetGlowColor(csc_hudelem_s* elem, int offset);
		void HudElem_SetGlowAlpha(csc_hudelem_s* elem, int offset);
		void HudElem_GetGlowAlpha(csc_hudelem_s* elem, int offset);
		void HudElem_ReadOnlyField(csc_hudelem_s* hud, int offset);
		void HudElem_GetFlags(csc_hudelem_s* hud, int offset);
		void HudElem_SetArchived(csc_hudelem_s* hud, int offset);
		void HudElem_GetText(csc_hudelem_s* hud, int offset);
		void HudElem_GetMaterialName(csc_hudelem_s* hud, int offset);
		void HudElem_SetOffscreenPointerMaterialName(csc_hudelem_s* hud, int offset);
		void HudElem_GetOffscreenPointerMaterialName(csc_hudelem_s* hud, int offset);

		csc_hudelem_field_t cscHudelemFields[MAX_CSC_HUDELEM_FIELDS] =
		{
			{"x", offsetof(csc_hudelem_s, elem.x), F_FLOAT, 0, 0, 0, 0},
			{"y", offsetof(csc_hudelem_s, elem.y), F_FLOAT, 0, 0, 0, 0},
			{"z", offsetof(csc_hudelem_s, elem.z), F_FLOAT, 0, 0, 0, 0},
			{"targetentnum", offsetof(csc_hudelem_s, elem.targetEntNum), F_INT, 0, 0, HudElem_ReadOnlyField, 0},
			{"fontscale", offsetof(csc_hudelem_s, elem.fontScale), F_FLOAT, -1, 0, HudElem_SetFontScale, 0},
			{"font", offsetof(csc_hudelem_s, elem.font), F_INT, -1, 0, HudElem_SetFont, HudElem_GetFont},
			{"alignx", offsetof(csc_hudelem_s, elem.alignOrg), F_INT, 3, 2, HudElem_SetAlignX, HudElem_GetAlignX},
			{"aligny", offsetof(csc_hudelem_s, elem.alignOrg), F_INT, 3, 0, HudElem_SetAlignY, HudElem_GetAlignY},
			{"horzalign", offsetof(csc_hudelem_s, elem.alignScreen), F_INT, 7, 3, HudElem_SetHorzAlign, HudElem_GetHorzAlign},
			{"vertalign", offsetof(csc_hudelem_s, elem.alignScreen), F_INT, 7, 0, HudElem_SetVertAlign, HudElem_GetVertAlign},
			{"color", offsetof(csc_hudelem_s, elem.color), F_INT, -1, 0, HudElem_SetColor, HudElem_GetColor},
			{"alpha", offsetof(csc_hudelem_s, elem.color), F_INT, -1, 0, HudElem_SetAlpha, HudElem_GetAlpha},
			{"label", offsetof(csc_hudelem_s, label), F_STRING, -1, 0, HudElem_SetLocalizedString, HudElem_GetLocalizedString},
			{"sort", offsetof(csc_hudelem_s, elem.sort), F_FLOAT, 0, 0, 0, 0},
			{"foreground", offsetof(csc_hudelem_s, elem.flags), F_INT, -1, 0, HudElem_SetFlagForeground, HudElem_GetFlagForeground},
			{"hidewhendead", offsetof(csc_hudelem_s, elem.flags), F_INT, -1, 0, HudElem_SetFlagHideWhenDead, HudElem_GetFlagHideWhenDead},
			{"hidewheninmenu", offsetof(csc_hudelem_s, elem.flags), F_INT, -1, 0, HudElem_SetFlagHideWhenInMenu, HudElem_GetFlagHideWhenInMenu},
			{"hidewheninscope", offsetof(csc_hudelem_s, elem.flags), F_INT, -1, 0, HudElem_SetFlagHideWhenInScope, HudElem_GetFlagHideWhenInScope},
			{"fontstyle3d", offsetof(csc_hudelem_s, elem.flags), F_INT, -1, 0, HudElem_SetFontStyle3d, HudElem_GetFontStyle3d},
			{"font3duseglowcolor", offsetof(csc_hudelem_s, elem.flags), F_INT, -1, 0, HudElem_SetFont3dUseGlowColor, HudElem_GetFont3dUseGlowColor},
			{"glowcolor", offsetof(csc_hudelem_s, elem.glowColor), F_INT, -1, 0, HudElem_SetGlowColor, HudElem_GetGlowColor},
			{"glowalpha", offsetof(csc_hudelem_s, elem.glowColor), F_INT, -1, 0, HudElem_SetGlowAlpha, HudElem_GetGlowAlpha},
			{"flags", offsetof(csc_hudelem_s, elem.flags), F_INT, -1, 0, HudElem_ReadOnlyField, HudElem_GetFlags},
			{"text", offsetof(csc_hudelem_s, text), F_STRING, -1, 0, HudElem_ReadOnlyField, HudElem_GetText},
			{"material", offsetof(csc_hudelem_s, materialName), F_STRING, -1, 0, HudElem_ReadOnlyField, HudElem_GetMaterialName},
			{"offscreenpointermaterial", offsetof(csc_hudelem_s, offscreenPointerMaterialName), F_STRING, -1, 0, HudElem_SetOffscreenPointerMaterialName, HudElem_GetOffscreenPointerMaterialName},
			{"usewaypointdata", offsetof(csc_hudelem_s, waypointData.useWaypointData), F_INT, 0, 0, 0},
			{"waypointiconwidth", offsetof(csc_hudelem_s, waypointData.iconWidth), F_FLOAT, 0, 0, 0},
			{"waypointiconheight", offsetof(csc_hudelem_s, waypointData.iconHeight), F_FLOAT, 0, 0, 0},
			{"waypointoffscreenpointerdistance", offsetof(csc_hudelem_s, waypointData.offscreenPointerDistance), F_FLOAT, 0, 0, 0},
			{"waypointoffscreendistancealphathreshold", offsetof(csc_hudelem_s, waypointData.offscreenDistanceAlphaThreshold), F_FLOAT, 0, 0, 0},
			{"waypointoffscreenpointerwidth", offsetof(csc_hudelem_s, waypointData.offscreenPointerWidth), F_FLOAT, 0, 0, 0},
			{"waypointoffscreenpointerheight", offsetof(csc_hudelem_s, waypointData.offscreenPointerHeight), F_FLOAT, 0, 0, 0},
			{"waypointoffscreenpadleft", offsetof(csc_hudelem_s, waypointData.offscreenPadLeft), F_FLOAT, 0, 0, 0},
			{"waypointoffscreenpadright", offsetof(csc_hudelem_s, waypointData.offscreenPadRight), F_FLOAT, 0, 0, 0},
			{"waypointoffscreenpadtop", offsetof(csc_hudelem_s, waypointData.offscreenPadTop), F_FLOAT, 0, 0, 0},
			{"waypointoffscreenpadbottom", offsetof(csc_hudelem_s, waypointData.offscreenPadBottom), F_FLOAT, 0, 0, 0},
			{"waypointtweaky", offsetof(csc_hudelem_s, waypointData.tweakY), F_FLOAT, 0, 0, 0},
			{"waypointplayeroffsetprone", offsetof(csc_hudelem_s, waypointData.playerOffsetProne), F_FLOAT, 0, 0, 0},
			{"waypointplayeroffsetcrouch", offsetof(csc_hudelem_s, waypointData.playerOffsetCrouch), F_FLOAT, 0, 0, 0},
			{"waypointplayeroffsetstand", offsetof(csc_hudelem_s, waypointData.playerOffsetStand), F_FLOAT, 0, 0, 0},
			{"waypointoffscreenscalelength", offsetof(csc_hudelem_s, waypointData.offscreenScaleLength), F_FLOAT, 0, 0, 0},
			{"waypointoffscreenscalesmallest", offsetof(csc_hudelem_s, waypointData.offscreenScaleSmallest), F_FLOAT, 0, 0, 0},
			{"waypointdistscalerangemin", offsetof(csc_hudelem_s, waypointData.distScaleRangeMin), F_FLOAT, 0, 0, 0},
			{"waypointdistscalerangemax", offsetof(csc_hudelem_s, waypointData.distScaleRangeMax), F_FLOAT, 0, 0, 0},
			{"waypointdistscalesmallest", offsetof(csc_hudelem_s, waypointData.distScaleSmallest), F_FLOAT, 0, 0, 0},
			{"waypointshowoffscreenpointer", offsetof(csc_hudelem_s, waypointData.showOffscreenPointer), F_INT, 0, 0, 0},
			{"waypointshowmaterialoffscreen", offsetof(csc_hudelem_s, waypointData.showMaterialOffscreen), F_INT, 0, 0, 0},
			{"waypointshowmaterial", offsetof(csc_hudelem_s, waypointData.showMaterial), F_INT, 0, 0, 0},
			{"waypointshowlabeloffscreen", offsetof(csc_hudelem_s, waypointData.showLabelOffscreen), F_INT, 0, 0, 0},
			{0, 0, F_INT, 0, 0, 0, 0}
		};

		void HudElem_ReadOnlyField(csc_hudelem_s* hud, [[maybe_unused]]int offset)
		{
			game::Scr_Error("hudelem field is read only", game::SCRIPTINSTANCE_CLIENT, false);
		}

		void HudElem_GetFlags(csc_hudelem_s* hud, int offset)
		{
			char buffer[1024];
			game::hudelem_flags_t flags = hud->elem.flags;
			int i;

			for (i = 0; i < (sizeof(he_flag_values) / 4); i++)
			{
				if ((flags & he_flag_values[i]) != 0)
				{
					sprintf(buffer, "%s", he_flag_names[i]);
				}
			}
		
			game::Scr_AddString(game::SCRIPTINSTANCE_CLIENT, buffer);
		}

		void HudElem_SetFlagHideWhenInScope(csc_hudelem_s* hud, int offset)
		{
			int* flags;

			flags = (int*)((char*)hud + cscHudelemFields[offset].ofs);
			if (game::Scr_GetInt(game::SCRIPTINSTANCE_CLIENT, 0))
			{
				*flags |= game::HE_FLAG_HIDEWHENINSCOPE;
			}
			else
			{
				*flags &= ~game::HE_FLAG_HIDEWHENINSCOPE;
			}
		}

		void HudElem_GetFlagHideWhenInScope(csc_hudelem_s* hud, [[maybe_unused]] int offset)
		{
			game::Scr_AddInt(game::SCRIPTINSTANCE_CLIENT, ((hud->elem.flags & game::HE_FLAG_HIDEWHENINSCOPE) != 0));
		}

		void HudElem_SetEnumString(csc_hudelem_s* hud, csc_hudelem_field_t* f, const char** names, int nameCount)
		{
			int* value;
			const char* selectedName;
			int i;
			const char* errormsg;
			char Buffer[2048];
			int nameIndex;

			value = (int*)((char*)hud + f->ofs);
			selectedName = game::Scr_GetString(0, game::SCRIPTINSTANCE_CLIENT);
			for (nameIndex = 0; nameIndex < nameCount; ++nameIndex)
			{
				if (!strcmp(selectedName, names[nameIndex]))
				{
					*value &= ~(f->mask << f->shift);
					*value |= nameIndex << f->shift;
					return;
				}
			}
			sprintf(
				Buffer,
				"\"%s\" is not a valid value for hudelem field \"%s\"\nShould be one of:",
				selectedName,
				f->name);
			for (i = 0; i < nameCount; ++i)
			{
				errormsg = game::va(" %s", names[i]);
				strncat(Buffer, errormsg, 0x800u);
				Buffer[2047] = 0;
			}
			game::Scr_Error(errormsg, game::SCRIPTINSTANCE_CLIENT, false);
		}

		void HudElem_GetEnumString(csc_hudelem_s* hud, int offset, const char** names)
		{
			game::Scr_AddString(
				game::SCRIPTINSTANCE_CLIENT,
				names[cscHudelemFields[offset].mask & (*(int*)((char*)&hud->elem.type + cscHudelemFields[offset].ofs) >> cscHudelemFields[offset].shift)]);
		}

		void HudElem_SetFontScale(csc_hudelem_s* hud, [[maybe_unused]]int offset)
		{
			float fontScale;
			const char* msg;

			fontScale = game::Scr_GetFloat(game::SCRIPTINSTANCE_CLIENT, 0);
			if (fontScale <= 0.0)
			{
				msg = game::va("font scale was %g; should be > 0", fontScale);
				game::Scr_Error(msg, game::SCRIPTINSTANCE_CLIENT, false);
			}
			hud->elem.fontScale = fontScale;
		}

		void HudElem_SetFont(csc_hudelem_s* hud, int offset)
		{
			HudElem_SetEnumString(hud, &cscHudelemFields[offset], g_he_font, 6);
		}

		void HudElem_GetFont(csc_hudelem_s* hud, int offset)
		{
			HudElem_GetEnumString(hud, offset, g_he_font);
		}

		void HudElem_SetAlignX(csc_hudelem_s* hud, int offset)
		{
			HudElem_SetEnumString(hud, &cscHudelemFields[offset], g_he_alignx, 3);
		}

		void HudElem_GetAlignX(csc_hudelem_s* hud, int offset)
		{
			HudElem_GetEnumString(hud, offset, g_he_alignx);
		}

		void HudElem_SetAlignY(csc_hudelem_s* hud, int offset)
		{
			HudElem_SetEnumString(hud, &cscHudelemFields[offset], g_he_aligny, 3);
		}

		void HudElem_GetAlignY(csc_hudelem_s* hud, int offset)
		{
			HudElem_GetEnumString(hud, offset, g_he_aligny);
		}

		void HudElem_SetHorzAlign(csc_hudelem_s* hud, int offset)
		{
			HudElem_SetEnumString(hud, &cscHudelemFields[offset], g_he_horzalign, 8);
		}

		void HudElem_GetHorzAlign(csc_hudelem_s* hud, int offset)
		{
			HudElem_GetEnumString(hud, offset, g_he_horzalign);
		}

		void HudElem_SetVertAlign(csc_hudelem_s* hud, int offset)
		{
			HudElem_SetEnumString(hud, &cscHudelemFields[offset], g_he_vertalign, 8);
		}

		void HudElem_GetVertAlign(csc_hudelem_s* hud, int offset)
		{
			HudElem_GetEnumString(hud, offset, g_he_vertalign);
		}

		void HudElem_SetColor(csc_hudelem_s* hud, [[maybe_unused]] int offset)
		{
			float colorValue;
			float color[3];

			game::Scr_GetVector(game::SCRIPTINSTANCE_CLIENT, color, 0);
			colorValue = std::clamp(color[0], 0.0f, 1.0f);
			hud->elem.color.color.r = (int)((255.0f * colorValue) + 9.313225746154785e-10f);
			colorValue = std::clamp(color[1], 0.0f, 1.0f);
			hud->elem.color.color.g = (int)((255.0f * colorValue) + 9.313225746154785e-10f);
			colorValue = std::clamp(color[1], 0.0f, 1.0f);
			hud->elem.color.color.b = (int)((255.0f * colorValue) + 9.313225746154785e-10f);
		}

		void HudElem_GetColor(csc_hudelem_s* hud, [[maybe_unused]] int offset)
		{
			float color[3];

			color[0] = hud->elem.color.color.r * 0.0039215689f;
			color[1] = hud->elem.color.color.g * 0.0039215689f;
			color[2] = hud->elem.color.color.b * 0.0039215689f;
			game::Scr_AddVector(game::SCRIPTINSTANCE_CLIENT, color);
		}

		void HudElem_SetAlpha(csc_hudelem_s* hud, [[maybe_unused]] int offset)
		{
			float alpha;
			float alphaValue;

			alpha = game::Scr_GetFloat(game::SCRIPTINSTANCE_CLIENT, 0);
			alphaValue = std::clamp(alpha, 0.0f, 1.0f);
			hud->elem.color.color.a = (int)((alphaValue * 255.0f) + 9.313225746154785e-10f);
		}

		void HudElem_GetAlpha(csc_hudelem_s* hud, [[maybe_unused]] int offset)
		{
			game::Scr_AddFloat(game::SCRIPTINSTANCE_CLIENT, hud->elem.color.color.a * 0.0039215689f);
		}

		game::gentity_s* Scr_GetEntity(unsigned int index)
		{
			game::scr_entref_t entRef;

			entRef = *game::Scr_GetEntityRef(SCRIPTINSTANCE_SERVER, &entRef, index);
			if (entRef.classnum == game::CLASS_NUM_ENTITY)
			{
				return &game::g_entities[entRef.entnum];
			}
			game::gScrVarPub[SCRIPTINSTANCE_SERVER].error_index = index + 1;
			game::Scr_Error("not an entity", SCRIPTINSTANCE_SERVER, 0);
			return 0;
		}

		void Scr_ValidateLocalizedStringRef(int parmIndex, const char* token, int tokenLen)
		{
			int i;
			const char* errorMsg;

			if (tokenLen > 1)
			{
				for (i = 0; i < tokenLen; ++i)
				{
					if (!isalnum(token[i]) && token[i] != '_')
					{
						errorMsg = game::va("Illegal localized string reference: %s must contain only alpha-numeric characters and underscores", token);
						game::Scr_ParamError(parmIndex, game::SCRIPTINSTANCE_CLIENT, errorMsg);
					}
				}
			}
		}

		const char* Com_DisplayName(const char* name, const char* clanAbbrev, [[maybe_unused]] int type)
		{
			char buffer[32];

			if (!clanAbbrev)
			{
				game::I_strncpyz(buffer, name, 31u);
				buffer[31] = 0;
			}
			else
			{
				_snprintf(buffer, 0x20u, "[%s]%s", clanAbbrev, name);
			}
		}

		const char* CS_DisplayName(const game::clientState_s* cs, int type)
		{
			return Com_DisplayName(cs->name, cs->clanAbbrev, type);
		}

		void Scr_ConstructMessageString(int firstParmIndex, int lastParmIndex, const char* errorContext, char* string, unsigned int stringLimit)
		{
			const char* errorMsg;
			const char* clientName;
			unsigned int charIndex;
			unsigned int charIndexa;
			unsigned int tokenLen;
			int type;
			game::gentity_s* ent;
			const char* token;
			unsigned int stringLen;

			stringLen = 0;
			while (firstParmIndex <= lastParmIndex)
			{
				type = game::Scr_GetType(game::SCRIPTINSTANCE_CLIENT, firstParmIndex);
				if (type == game::VAR_ISTRING)
				{
					token = (char*)game::Scr_GetIString(game::SCRIPTINSTANCE_CLIENT, firstParmIndex);
					tokenLen = strlen(token);
					game::Scr_ValidateLocalizedStringRef(firstParmIndex, token, tokenLen);
					if (stringLen + tokenLen + 1 >= stringLimit)
					{
						errorMsg = game::va("%s is too long. Max length is %i\n", errorContext, stringLimit);
						game::Scr_ParamError(firstParmIndex, game::SCRIPTINSTANCE_CLIENT, errorMsg);
					}
					if (stringLen)
						string[stringLen++] = '\x14';
				}
				else
				{
					token = game::Scr_GetString(firstParmIndex, game::SCRIPTINSTANCE_CLIENT);
					tokenLen = strlen(token);
					for (charIndex = 0; charIndex < tokenLen; ++charIndex)
					{
						if (token[charIndex] == '\x14' || token[charIndex] == '\x15' || token[charIndex] == '\x16')
						{
							errorMsg = game::va("bad escape character (%i) present in string", token[charIndex]);
							game::Scr_ParamError(firstParmIndex, game::SCRIPTINSTANCE_CLIENT, errorMsg);
						}
					}
					if (stringLen + tokenLen + 1 >= stringLimit)
					{
						errorMsg = game::va("%s is too long. Max length is %i\n", errorContext, stringLimit);
						game::Scr_ParamError(firstParmIndex, game::SCRIPTINSTANCE_CLIENT, errorMsg);
					}
					if (tokenLen)
						string[stringLen++] = '\x15';
				}
				for (charIndexa = 0; charIndexa < tokenLen; ++charIndexa)
				{
					if (token[charIndexa] == '\x14' || token[charIndexa] == '\x15' || token[charIndexa] == '\x16')
						string[stringLen] = '.';
					else
						string[stringLen] = token[charIndexa];
					++stringLen;
				}
				++firstParmIndex;
			}
			string[stringLen] = 0;
		}

		void HudElem_SetLocalizedString(csc_hudelem_s* hud, [[maybe_unused]] int offset)
		{
			char buffer[256];

			Scr_ConstructMessageString(0, 0, "Hud Elem String", buffer, 0x100u);
			strncpy(hud->label, buffer, sizeof(hud->label));
			hud->label[sizeof(hud->label) - 1] = '\0';
		}

		void HudElem_GetLocalizedString(csc_hudelem_s* hud, [[maybe_unused]] int offset)
		{
			game::Scr_AddString(game::SCRIPTINSTANCE_CLIENT, hud->label);
		}

		void HudElem_GetText(csc_hudelem_s* hud, [[maybe_unused]] int offset)
		{
			game::Scr_AddString(game::SCRIPTINSTANCE_CLIENT, hud->text);
		}

		void HudElem_GetMaterialName(csc_hudelem_s* hud, [[maybe_unused]] int offset)
		{
			game::Scr_AddString(game::SCRIPTINSTANCE_CLIENT, hud->materialName);
		}

		void HudElem_SetOffscreenPointerMaterialName(csc_hudelem_s* hud, [[maybe_unused]] int offset)
		{
			const char* materialName = game::Scr_GetString(0, game::SCRIPTINSTANCE_CLIENT);

			strncpy(hud->offscreenPointerMaterialName, materialName, sizeof(hud->offscreenPointerMaterialName));
			hud->offscreenPointerMaterialName[sizeof(hud->offscreenPointerMaterialName) - 1] = '\0';
		}

		void HudElem_GetOffscreenPointerMaterialName(csc_hudelem_s* hud, [[maybe_unused]] int offset)
		{
			game::Scr_AddString(game::SCRIPTINSTANCE_CLIENT, hud->offscreenPointerMaterialName);
		}

		void HudElem_SetFlagForeground(csc_hudelem_s* hud, int offset)
		{
			int* flags;

			flags = (int*)((char*)hud + cscHudelemFields[offset].ofs);
			if (game::Scr_GetInt(game::SCRIPTINSTANCE_CLIENT, 0))
			{
				*flags |= game::HE_FLAG_FOREGROUND;
			}
			else
			{
				*flags &= ~game::HE_FLAG_FOREGROUND;
			}
		}

		void HudElem_GetFlagForeground(csc_hudelem_s* hud, [[maybe_unused]] int offset)
		{
			game::Scr_AddInt(game::SCRIPTINSTANCE_CLIENT, ((hud->elem.flags & game::HE_FLAG_FOREGROUND) != 0));
		}

		void HudElem_SetFlagHideWhenDead(csc_hudelem_s* hud, int offset)
		{
			int* flags;

			flags = (int*)((char*)hud + cscHudelemFields[offset].ofs);
			if (game::Scr_GetInt(game::SCRIPTINSTANCE_CLIENT, 0))
			{
				*flags |= game::HE_FLAG_HIDEWHENDEAD;
			}
			else
			{
				*flags &= ~game::HE_FLAG_HIDEWHENDEAD;
			}
		}

		void HudElem_GetFlagHideWhenDead(csc_hudelem_s* hud, [[maybe_unused]] int offset)
		{
			game::Scr_AddInt(game::SCRIPTINSTANCE_CLIENT, ((hud->elem.flags & game::HE_FLAG_HIDEWHENDEAD) != 0));
		}

		void HudElem_SetFlagHideWhenInMenu(csc_hudelem_s* hud, int offset)
		{
			int* flags;

			flags = (int*)((char*)hud + cscHudelemFields[offset].ofs);
			if (game::Scr_GetInt(game::SCRIPTINSTANCE_CLIENT, 0))
			{
				*flags |= game::HE_FLAG_HIDEWHENINMENU;
			}
			else
			{
				*flags &= ~game::HE_FLAG_HIDEWHENINMENU;
			}
		}

		void HudElem_GetFlagHideWhenInMenu(csc_hudelem_s* hud, [[maybe_unused]] int offset)
		{
			game::Scr_AddInt(game::SCRIPTINSTANCE_CLIENT, ((hud->elem.flags & HE_FLAG_HIDEWHENINMENU) != 0));
		}

		void HudElem_SetFontStyle3d(csc_hudelem_s* hud, int offset)
		{
			unsigned int* flags;
			const char* str;
			const char* errorMsg;

			flags = (unsigned int*)((char*)hud + cscHudelemFields[offset].ofs);
			str = game::Scr_GetString(0, game::SCRIPTINSTANCE_CLIENT);
			if (strcmp(str, "normal"))
			{
				if (strcmp(str, "shadowed"))
				{
					if (strcmp(str, "shadowedmore"))
					{
						errorMsg = game::va("unknown text style '%s', should be normal, shadowed, or shadowedmore", (const char*)str);
						game::Scr_ParamError(0, game::SCRIPTINSTANCE_CLIENT, errorMsg);
					}
					else
					{
						*flags = *flags & ~HE_FLAG_SHADOWED | HE_FLAG_SHADOWEDMORE;
					}
				}
				else
				{
					*flags = *flags & ~HE_FLAG_SHADOWEDMORE | HE_FLAG_SHADOWED;
				}
			}
			else
			{
				*flags &= ~HE_FLAG_SHADOWEDMORE | HE_FLAG_SHADOWED;
			}
		}

		void HudElem_GetFontStyle3d(csc_hudelem_s* hud, [[maybe_unused]] int offset)
		{
			int flags;

			flags = hud->elem.flags;
			if ((flags & HE_FLAG_SHADOWED) != 0)
			{
				game::Scr_AddString(game::SCRIPTINSTANCE_CLIENT, g_he_textstyle[1]);
			}
			else if ((flags & HE_FLAG_SHADOWEDMORE) != 0)
			{
				game::Scr_AddString(game::SCRIPTINSTANCE_CLIENT, g_he_textstyle[2]);
			}
			else
			{
				game::Scr_AddString(game::SCRIPTINSTANCE_CLIENT, g_he_textstyle[0]);
			}
		}

		void HudElem_SetFont3dUseGlowColor(csc_hudelem_s* hud, int offset)
		{
			int* flags;

			flags = (int*)((char*)hud + cscHudelemFields[offset].ofs);
			if (game::Scr_GetInt(game::SCRIPTINSTANCE_CLIENT, 0))
			{
				*flags |= HE_FLAG_SET3DFONTUSEGLOWCOLOR;
			}
			else
			{
				*flags &= ~HE_FLAG_SET3DFONTUSEGLOWCOLOR;
			}
		}

		void HudElem_GetFont3dUseGlowColor(csc_hudelem_s* hud, [[maybe_unused]] int offset)
		{
			game::Scr_AddInt(game::SCRIPTINSTANCE_CLIENT, ((hud->elem.flags & HE_FLAG_SET3DFONTUSEGLOWCOLOR) != 0));
		}

		void HudElem_SetGlowColor(csc_hudelem_s* hud, [[maybe_unused]] int offset)
		{
			float colorValue;
			float color[3];

			game::Scr_GetVector(game::SCRIPTINSTANCE_CLIENT, color, 0);
			colorValue = std::clamp(color[0], 0.0f, 1.0f);
			hud->elem.glowColor.color.r = (int)((255.0f * colorValue) + 9.313225746154785e-10f);
			colorValue = std::clamp(color[0], 0.0f, 1.0f);
			hud->elem.glowColor.color.g = (int)((255.0f * colorValue) + 9.313225746154785e-10f);
			colorValue = std::clamp(color[0], 0.0f, 1.0f);
			hud->elem.glowColor.color.b = (int)((255.0f * colorValue) + 9.313225746154785e-10f);
		}

		void HudElem_GetGlowColor(csc_hudelem_s* hud, [[maybe_unused]] int offset)
		{
			float color[3];

			color[0] = hud->elem.glowColor.color.r * 0.0039215689f;
			color[1] = hud->elem.glowColor.color.g * 0.0039215689f;
			color[2] = hud->elem.glowColor.color.b * 0.0039215689f;
			game::Scr_AddVector(game::SCRIPTINSTANCE_CLIENT, color);
		}

		void HudElem_SetGlowAlpha(csc_hudelem_s* hud, [[maybe_unused]] int offset)
		{
			float alpha;
			float alphaValue;

			alpha = game::Scr_GetFloat(game::SCRIPTINSTANCE_CLIENT, 0);
			alphaValue = std::clamp(alpha, 0.0f, 1.0f);
			hud->elem.glowColor.color.a = (int)((alphaValue * 255.0f) + 9.313225746154785e-10f);
		}

		void HudElem_GetGlowAlpha(csc_hudelem_s* hud, [[maybe_unused]] int offset)
		{
			game::Scr_AddFloat(game::SCRIPTINSTANCE_CLIENT, hud->elem.glowColor.color.a * 0.0039215689f);
		}

		csc_hudelem_s* HECmd_GetHudElem(scr_entref_t entref)
		{
			csc_hudelem_s* result;

			if (entref.classnum == CLASS_NUM_HUDELEM)
			{
				result = &csc_hudelems[entref.entnum];
			}
			else
			{
				game::Scr_ObjectError(game::SCRIPTINSTANCE_CLIENT, "not a hud element");
				result = 0;
			}
			return result;
		}

		void HudElem_ClearTypeSettings(csc_hudelem_s* hud, bool clearLabel)
		{
			hudelem_s* elem = &hud->elem;

			elem->width = 0;
			elem->height = 0;
			elem->materialIndex = 0;
			elem->fromX = 0.0f;
			elem->fromY = 0.0f;
			elem->fromAlignOrg = 0;
			elem->fromAlignScreen = 0;
			elem->fromWidth = 0;
			elem->fromHeight = 0;
			elem->scaleStartTime = 0;
			elem->scaleTime = 0;
			elem->time = 0;
			elem->duration = 0;
			elem->value = 0.0f;
			elem->text = 0;
			if (clearLabel)
			{
				memset(hud->label, 0, sizeof(hud->label));
			}
			memset(hud->text, 0, sizeof(hud->text));
			memset(hud->materialName, 0, sizeof(hud->materialName));
			memset(hud->offscreenPointerMaterialName, 0, sizeof(hud->offscreenPointerMaterialName));
		}

		void HECmd_SetText(scr_entref_t entref)
		{
			char string[256];
			csc_hudelem_s* hud;

			hud = HECmd_GetHudElem(entref);
			HudElem_ClearTypeSettings(hud, false);
			Scr_ConstructMessageString(0, game::Scr_GetNumParam(game::SCRIPTINSTANCE_CLIENT) - 1, "Hud Elem String", string, 0x100u);
			hud->elem.type = HE_TYPE_TEXT;
			strncpy(hud->text, string, sizeof(hud->text));
			hud->text[sizeof(hud->text) - 1] = '\0';
		}

		void __cdecl HECmd_SetTargetEnt(scr_entref_t entref)
		{
			csc_hudelem_s* hud = HECmd_GetHudElem(entref);
			if (entref.classnum == CLASS_NUM_HUDELEM)
			{
				hud->elem.targetEntNum = game::CScr_GetEntity(0)->nextState.number;
			}
			else
			{
				game::Scr_ParamError(-1, game::SCRIPTINSTANCE_CLIENT, "not a hud element");
			}
		}

		void HECmd_ClearTargetEnt(scr_entref_t entref)
		{
			HECmd_GetHudElem(entref)->elem.targetEntNum = 1023;
		}

		void Scr_FreeHudElemConstStrings(csc_hudelem_s* hud)
		{
			const csc_hudelem_field_t* f;

			for (f = cscHudelemFields; f->name; ++f)
			{
				if (f->type == F_STRING)
					game::Scr_SetString(game::SCRIPTINSTANCE_CLIENT, 0, (unsigned short*)((char*)hud + f->ofs));
			}
		}

		void Scr_FreeHudElem(csc_hudelem_s* hud)
		{
			game::Scr_NotifyNum_Internal(game::SCRIPTINSTANCE_CLIENT, hud - csc_hudelems, CLASS_NUM_HUDELEM, game::scr_const->death, 0);
			Scr_FreeHudElemConstStrings(hud);
			game::Scr_FreeEntityNum(game::SCRIPTINSTANCE_CLIENT, CLASS_NUM_HUDELEM, hud - csc_hudelems);
		}

		void HudElem_Free(csc_hudelem_s* hud)
		{
			Scr_FreeHudElem(hud);
			hud->elem.type = HE_TYPE_FREE;
		}

		void HECmd_Destroy(scr_entref_t entref)
		{
			csc_hudelem_s* hud;

			hud = HECmd_GetHudElem(entref);
			HudElem_Free(hud);
		}

		void BG_LerpHudColors(hudelem_s* elem, int time, hudelem_color_t* toColor)
		{
			float lerp;
			int timeSinceFadeStarted;

			timeSinceFadeStarted = time - elem->fadeStartTime;
			if (elem->fadeTime <= 0 || timeSinceFadeStarted >= elem->fadeTime)
			{
				*toColor = elem->color;
			}
			else
			{
				if (timeSinceFadeStarted < 0)
					timeSinceFadeStarted = 0;
				lerp = (float)timeSinceFadeStarted / elem->fadeTime;
				toColor->color.r = elem->fromColor.color.r + (elem->color.color.r - (unsigned char)(elem->fromColor.color.r * lerp));
				toColor->color.g = elem->fromColor.color.g + (elem->color.color.g - (unsigned char)(elem->fromColor.color.g * lerp));
				toColor->color.b = elem->fromColor.color.b + (elem->color.color.b - (unsigned char)(elem->fromColor.color.b * lerp));
				toColor->color.a = elem->fromColor.color.a + (elem->color.color.a - (unsigned char)(elem->fromColor.color.a * lerp));
			}
		}

		void HECmd_FadeOverTime(scr_entref_t entref)
		{
			const char* v1;
			const char* v2;
			float fadeTime;
			csc_hudelem_s* hud;

			hud = HECmd_GetHudElem(entref);
			fadeTime = game::Scr_GetFloat(game::SCRIPTINSTANCE_CLIENT, 0);
			if (fadeTime > 0.0)
			{
				if (fadeTime > 60.0)
				{
					v2 = game::va("fade time %g > 60", fadeTime);
					game::Scr_ParamError(0, game::SCRIPTINSTANCE_CLIENT, v2);
				}
			}
			else
			{
				v1 = game::va("fade time %g <= 0", fadeTime);
				game::Scr_ParamError(0, game::SCRIPTINSTANCE_CLIENT, v1);
			}
			BG_LerpHudColors(&hud->elem, game::cgArray->time, &hud->elem.fromColor);
			hud->elem.fadeStartTime = game::cgArray->time;
			hud->elem.fadeTime = (int)((float)(1000.0 * fadeTime) + 9.313225746154785e-10);
		}

		void HECmd_MoveOverTime(scr_entref_t entref)
		{
			const char* v1;
			const char* v2;
			csc_hudelem_s* hud;
			float moveTime;

			hud = HECmd_GetHudElem(entref);
			moveTime = game::Scr_GetFloat(game::SCRIPTINSTANCE_CLIENT, 0);
			if (moveTime > 0.0)
			{
				if (moveTime > 60.0)
				{
					v2 = game::va("move time %g > 60", moveTime);
					game::Scr_ParamError(0, game::SCRIPTINSTANCE_CLIENT, v2);
				}
			}
			else
			{
				v1 = game::va("move time %g <= 0", moveTime);
				game::Scr_ParamError(0, game::SCRIPTINSTANCE_CLIENT, v1);
			}
			hud->elem.moveStartTime = game::cgArray->time;
			hud->elem.moveTime = (int)((float)(1000.0 * moveTime) + 9.313225746154785e-10);
			hud->elem.fromX = hud->elem.x;
			hud->elem.fromY = hud->elem.y;
			hud->elem.fromAlignOrg = hud->elem.alignOrg;
			hud->elem.fromAlignScreen = hud->elem.alignScreen;
		}

		void HECmd_GetTextWidth(scr_entref_t entref)
		{
			char* translation;
			Font_s* font;
			int width;
			csc_hudelem_s* hud;
			char text[128];

			hud = HECmd_GetHudElem(entref);
			if (hud->elem.type != HE_TYPE_TEXT)
				game::Scr_Error("GetTextWidth called on a non text type hud elem", game::SCRIPTINSTANCE_CLIENT, false);
			translation = game::SEH_LocalizeTextMessage(text, text, LOCMSG_SAFE);
			if (!translation)
				translation = text;
			font = game::UI_GetFontHandleDefault(hud->elem.fontScale);
			width = game::UI_TextWidth(translation, 0, font, 1.0);
			game::Scr_AddInt(game::SCRIPTINSTANCE_CLIENT, width / 2);
		}

		csc_hudelem_s* HudElem_SetDefaults(csc_hudelem_s* hud)
		{
			hudelem_s* elem = &hud->elem;
			hudelem_waypoint_data* waypointData = &hud->waypointData;

			hud->archived = 0;
			memset(hud->nameId, 0, sizeof(hud->nameId));

			elem->type = HE_TYPE_TEXT;
			elem->x = 0.0;
			elem->y = 0.0;
			elem->z = 0.0;
			elem->targetEntNum = 1023;
			elem->font = 0;
			elem->alignOrg = 0;
			elem->alignScreen = 0;
			elem->color.rgba = -1;
			elem->glowColor.rgba = 0;
			elem->fromColor.rgba = 0;
			elem->fadeStartTime = 0;
			elem->fadeTime = 0;
			elem->label = 0;
			elem->sort = 0.0;
			elem->flags = HE_FLAG_NONE;
			elem->fxBirthTime = 0;
			elem->fxLetterTime = 0;
			elem->fxDecayStartTime = 0;
			elem->fxDecayDuration = 0;
			elem->soundID = 0;
			elem->moveStartTime = 0;
			elem->moveTime = 0;
			elem->fromFontScale = 0.0;
			elem->fontScaleStartTime = 0;
			elem->fontScaleTime = 0;
			elem->fontScale = 1.0;
			waypointData->useWaypointData = false;
			waypointData->iconWidth = 36.0f;
			waypointData->iconHeight = 36.0f;
			waypointData->offscreenPointerDistance = 30.0f;
			waypointData->offscreenDistanceAlphaThreshold = 30.0f;
			waypointData->offscreenPointerWidth = 25.0f;
			waypointData->offscreenPointerHeight = 12.0f;
			waypointData->offscreenPadLeft = 40.0f;
			waypointData->offscreenPadRight = 0.0f;
			waypointData->offscreenPadTop = 0.0f;
			waypointData->offscreenPadBottom = 30.0f;
			waypointData->tweakY = -17.0f;
			waypointData->playerOffsetProne = 30.0f;
			waypointData->playerOffsetCrouch = 56.0f;
			waypointData->playerOffsetStand = 74.0f;
			waypointData->offscreenScaleLength = 500.0f;
			waypointData->offscreenScaleSmallest = 1.0f;
			waypointData->distScaleRangeMin = 0.0f;
			waypointData->distScaleRangeMax = 3000.0f;
			waypointData->distScaleSmallest = 0.8f;
			waypointData->showOffscreenPointer = true;
			waypointData->showMaterialOffscreen = true;
			waypointData->showMaterial = true;
			HudElem_ClearTypeSettings(hud, true);
			return hud;
		}

		void HECmd_Reset(scr_entref_t entref)
		{
			csc_hudelem_s* hud;

			hud = HECmd_GetHudElem(entref);
			HudElem_SetDefaults(hud);
		}

		void HECmd_ScaleOverTime(scr_entref_t entref)
		{
			const char* errorMsg;
			int width;
			int height;
			csc_hudelem_s* hud;
			float scaleTime;

			hud = HECmd_GetHudElem(entref);
			if (game::Scr_GetNumParam(game::SCRIPTINSTANCE_CLIENT) != 3)
			{
				game::Scr_Error("hudelem scaleOverTime(time_in_seconds, new_width, new_height)", game::SCRIPTINSTANCE_CLIENT, false);
			}
			scaleTime = game::Scr_GetFloat(game::SCRIPTINSTANCE_CLIENT, 0);
			if (scaleTime > 0.0)
			{
				if (scaleTime > 60.0)
				{
					errorMsg = game::va("scale time %g > 60", scaleTime);
					game::Scr_ParamError(0, game::SCRIPTINSTANCE_CLIENT, errorMsg);
				}
			}
			else
			{
				errorMsg = game::va("scale time %g <= 0", scaleTime);
				game::Scr_ParamError(0, game::SCRIPTINSTANCE_CLIENT, errorMsg);
			}
			width = game::Scr_GetInt(game::SCRIPTINSTANCE_CLIENT, 1u);
			height = game::Scr_GetInt(game::SCRIPTINSTANCE_CLIENT, 2u);
			hud->elem.scaleStartTime = game::cgArray->time;
			hud->elem.scaleTime = (int)((float)(1000.0 * scaleTime) + 9.313225746154785e-10);
			hud->elem.fromWidth = hud->elem.width;
			hud->elem.fromHeight = hud->elem.height;
			hud->elem.width = width;
			hud->elem.height = height;
		}

		void HECmd_SetClock_Internal(scr_entref_t entref, he_type_t type, const char* cmdName)
		{
			const char* errorMsg;
			const char* shaderName;
			float totalClockTimeInSeconds;
			float timeInSeconds;
			int duration;
			int materialIndex;
			int width;
			int height;
			int numParam;
			csc_hudelem_s* hud;
			int time;

			hud = HECmd_GetHudElem(entref);
			numParam = game::Scr_GetNumParam(game::SCRIPTINSTANCE_CLIENT);
			if (numParam != 3 && numParam != 5)
			{
				errorMsg = game::va(
					"USAGE: <hudelem> %s(time_in_seconds, total_clock_time_in_seconds, shadername[, width, height]);\n",
					cmdName);
				game::Scr_Error(errorMsg, game::SCRIPTINSTANCE_CLIENT, false);
			}
			timeInSeconds = game::Scr_GetFloat(game::SCRIPTINSTANCE_CLIENT, 0) * 1000.0;
			time = (int)(timeInSeconds + 0.4999999990686774);
			if (time <= 0 && type != HE_TYPE_CLOCK_UP)
			{
				errorMsg = game::va("time %g should be > 0", (float)((float)time * 0.001));
				game::Scr_ParamError(0, game::SCRIPTINSTANCE_CLIENT, errorMsg);
			}
			totalClockTimeInSeconds = game::Scr_GetFloat(game::SCRIPTINSTANCE_CLIENT, 1u) * 1000.0;
			duration = (int)(totalClockTimeInSeconds + 0.4999999990686774);
			if (duration <= 0)
			{
				errorMsg = game::va("duration %g should be > 0", (float)((float)duration * 0.001));
				game::Scr_ParamError(1u, game::SCRIPTINSTANCE_CLIENT, errorMsg);
			}
			shaderName = game::Scr_GetString(2u, game::SCRIPTINSTANCE_CLIENT);
			if (numParam == 3)
			{
				width = 0;
				height = 0;
			}
			else
			{
				width = game::Scr_GetInt(game::SCRIPTINSTANCE_CLIENT, 3u);
				if (width < 0)
				{
					errorMsg = game::va("width %i < 0", width);
					game::Scr_ParamError(3u, game::SCRIPTINSTANCE_CLIENT, errorMsg);
				}
				height = game::Scr_GetInt(game::SCRIPTINSTANCE_CLIENT, 4u);
				if (height < 0)
				{
					errorMsg = game::va("height %i < 0", height);
					game::Scr_ParamError(4u, game::SCRIPTINSTANCE_CLIENT, errorMsg);
				}
			}
			HudElem_ClearTypeSettings(hud, true);
			hud->elem.type = type;
			hud->elem.time = time + game::cgArray->time;
			hud->elem.duration = duration;
			strncpy(hud->materialName, shaderName, sizeof(hud->materialName));
			hud->materialName[sizeof(hud->materialName) - 1] = '\0';
			hud->elem.width = width;
			hud->elem.height = height;
		}

		void HECmd_SetClock(scr_entref_t entref)
		{
			HECmd_SetClock_Internal(entref, HE_TYPE_CLOCK_DOWN, "setClock");
		}

		void HECmd_SetClockUp(scr_entref_t entref)
		{
			HECmd_SetClock_Internal(entref, HE_TYPE_CLOCK_UP, "setClockUp");
		}

		void HECmd_SetShader(scr_entref_t entref)
		{
			const char* shaderName;
			const char* errorMsg;
			int width;
			int height;
			int materialIndex;
			int numParam;
			csc_hudelem_s* hud;

			hud = HECmd_GetHudElem(entref);
			numParam = game::Scr_GetNumParam(game::SCRIPTINSTANCE_CLIENT);
			if (numParam != 1 && numParam != 3)
			{
				game::Scr_Error("USAGE: <hudelem> setShader(\"materialname\"[, optional_width, optional_height]);", game::SCRIPTINSTANCE_CLIENT, false);
			}
			shaderName = game::Scr_GetString(0, game::SCRIPTINSTANCE_CLIENT);
			if (numParam == 1)
			{
				width = 0;
				height = 0;
			}
			else
			{
				width = game::Scr_GetInt(game::SCRIPTINSTANCE_CLIENT, 1u);
				if (width < 0)
				{
					errorMsg = game::va("width %i < 0", width);
					game::Scr_ParamError(1u, game::SCRIPTINSTANCE_CLIENT, errorMsg);
				}
				height = game::Scr_GetInt(game::SCRIPTINSTANCE_CLIENT, 2u);
				if (height < 0)
				{
					errorMsg = game::va("height %i < 0", height);
					game::Scr_ParamError(2u, game::SCRIPTINSTANCE_CLIENT, errorMsg);
				}
			}
			HudElem_ClearTypeSettings(hud, true);
			hud->elem.type = HE_TYPE_MATERIAL;
			strncpy(hud->materialName, shaderName, sizeof(hud->materialName));
			hud->materialName[sizeof(hud->materialName) - 1] = '\0';
			hud->elem.width = width;
			hud->elem.height = height;
		}

		int GetIntGTZero(unsigned int index)
		{
			const char* v1;
			int number;

			number = game::Scr_GetInt(game::SCRIPTINSTANCE_CLIENT, index);
			if (number >= 0)
			{
				return number;
			}
			v1 = game::va("Time (%i) must be greater than zero.", number);
			game::Scr_ParamError(index, game::SCRIPTINSTANCE_CLIENT, v1);
			return number;
		}

		void HECmd_SetPulseFX(scr_entref_t entref)
		{
			int v1;
			int v2;
			int v3;
			csc_hudelem_s* hud;
			playerState_s* ps;

			if (game::Scr_GetNumParam(game::SCRIPTINSTANCE_CLIENT) != 3)
			{
				game::Scr_Error("USAGE: <hudelem> SetPulseFX( <speed>, <decayStart>, <decayDuration> );\n", game::SCRIPTINSTANCE_CLIENT, false);
			}
			hud = HECmd_GetHudElem(entref);
			hud->elem.fxBirthTime = game::cgArray->time;
			hud->elem.fxLetterTime = GetIntGTZero(0);
			hud->elem.fxDecayStartTime = GetIntGTZero(1u);
			hud->elem.fxDecayDuration = GetIntGTZero(2u);
			if (hud->clientNum == 1023)
			{
				game::Scr_Error("SetPulseFX called on a non-client entity hud element\n", game::SCRIPTINSTANCE_CLIENT, false);
			}
			else
			{
				ps = &game::cgArray->nextSnap->ps;
				++ps->hudElemLastAssignedSoundID;
				ps->hudElemLastAssignedSoundID %= 32;
				if (!ps->hudElemLastAssignedSoundID)
					++ps->hudElemLastAssignedSoundID;
				hud->elem.soundID = ps->hudElemLastAssignedSoundID;
			}
		}

		void HECmd_SetTimer_Internal(scr_entref_t entref, he_type_t type, const char* cmdName)
		{
			const char* errorMsg;
			float timeSeconds;
			csc_hudelem_s* hud;
			int timeMilliseconds;

			hud = HECmd_GetHudElem(entref);
			if (game::Scr_GetNumParam(game::SCRIPTINSTANCE_CLIENT) != 1)
			{
				errorMsg = game::va("USAGE: <hudelem> %s(time_in_seconds);\n", cmdName);
				game::Scr_Error(errorMsg, game::SCRIPTINSTANCE_CLIENT, false);
			}
			timeSeconds = game::Scr_GetFloat(game::SCRIPTINSTANCE_CLIENT, 0) * 1000.0;
			timeMilliseconds = (int)(timeSeconds + 0.4999999990686774);
			if (timeMilliseconds <= 0 && type != HE_TYPE_TIMER_UP)
			{
				errorMsg = game::va("time %g should be > 0", (float)timeMilliseconds * 0.001);
				game::Scr_ParamError(0, game::SCRIPTINSTANCE_CLIENT, errorMsg);
			}
			HudElem_ClearTypeSettings(hud, false);
			hud->elem.type = type;
			hud->elem.time = timeMilliseconds + game::cgArray->time;
		}

		void HECmd_SetTenthsTimer(scr_entref_t entref)
		{
			HECmd_SetTimer_Internal(entref, HE_TYPE_TENTHS_TIMER_DOWN, "setTenthsTimer");
		}

		void HECmd_SetTenthsTimerUp(scr_entref_t entref)
		{
			HECmd_SetTimer_Internal(entref, HE_TYPE_TENTHS_TIMER_UP, "setTenthsTimerUp");
		}

		void HECmd_SetTimer(scr_entref_t entref)
		{
			HECmd_SetTimer_Internal(entref, HE_TYPE_TIMER_DOWN, "setTimer");
		}

		void HECmd_SetTimerUp(scr_entref_t entref)
		{
			HECmd_SetTimer_Internal(entref, HE_TYPE_TIMER_UP, "setTimerUp");
		}

		void HECmd_SetValue(scr_entref_t entref)
		{
			csc_hudelem_s* hud;
			float value;
			char label[256];

			hud = HECmd_GetHudElem(entref);
			value = game::Scr_GetFloat(game::SCRIPTINSTANCE_CLIENT, 0);
			HudElem_ClearTypeSettings(hud, false);
			if (hud->elem.type != HE_TYPE_SCORE)
			{
				hud->elem.type = HE_TYPE_VALUE;
			}
			hud->elem.value = value;
		}

		void HECmd_SetWaypoint(scr_entref_t entref)
		{
			int constantSize;
			int numParam;
			csc_hudelem_s* hud;
			const char* materialName;

			hud = HECmd_GetHudElem(entref);
			numParam = game::Scr_GetNumParam(game::SCRIPTINSTANCE_CLIENT);
			constantSize = game::Scr_GetInt(game::SCRIPTINSTANCE_CLIENT, 0);
			hud->elem.type = HE_TYPE_WAYPOINT;
			hud->elem.value = (float)constantSize;
			materialName = game::Scr_GetString(1u, game::SCRIPTINSTANCE_CLIENT);
			if (materialName && *materialName)
			{
				strncpy(hud->materialName, materialName, sizeof(hud->materialName));
				hud->materialName[sizeof(hud->materialName) - 1] = '\0';
			}
			if (numParam == 3)
			{
				hud->elem.time = game::Scr_GetInt(game::SCRIPTINSTANCE_CLIENT, 2u);
			}
		}

		csc_hudelem_s* HudElem_Alloc(int clientNum)
		{
			unsigned int i;

			for (i = 0; i < MAX_CSC_HUDELEMS; ++i)
			{
				if (!csc_hudelems[i].elem.type)
				{
					HudElem_SetDefaults(&csc_hudelems[i]);
					csc_hudelems[i].clientNum = clientNum;
					return &csc_hudelems[i];
				}
			}
			return 0;
		}

		void Scr_AddEntityNum(int entnum, classNum_e classnum, scriptInstance_t inst, int clientNum)
		{
			unsigned int entId;

			entId = game::Scr_GetEntityId(entnum, inst, classnum, clientNum);
			game::Scr_AddObject(inst, entId);
		}

		void Scr_AddHudElem(csc_hudelem_s* hud)
		{
			Scr_AddEntityNum(hud - csc_hudelems, CLASS_NUM_HUDELEM, game::SCRIPTINSTANCE_CLIENT, 0);
		}

		void CScr_NewClientHudElem(scr_entref_t entref)
		{
			csc_hudelem_s* hud;
			if (entref.classnum != CLASS_NUM_ENTITY)
			{
				game::Scr_Error("not an entity", game::SCRIPTINSTANCE_CLIENT, false);
			}
			hud = HudElem_Alloc(entref.client);
			if (!hud)
			{
				game::Scr_Error("out of hudelems", game::SCRIPTINSTANCE_CLIENT, false);
			}
			Scr_AddHudElem(hud);
		}

		void CScr_NewHudElem()
		{
			csc_hudelem_s* hud;

			hud = HudElem_Alloc(1023);
			if (!hud)
			{
				game::Scr_Error("out of hudelems", game::SCRIPTINSTANCE_CLIENT, false);
			}
			Scr_AddHudElem(hud);
		}

		int compare_hudelems(const csc_hudelem_s** val1, const csc_hudelem_s** val2)
		{
			float compareVal;
			int result;

			compareVal = (*val1)->elem.sort - (*val2)->elem.sort;
			if (compareVal >= 0.0)
			{
				result = compareVal > 0.0;
			}
			else
			{
				result = -1;
			}
			return result;
		}

		size_t GetSortedCSCHudElems(csc_hudelem_s** huds)
		{
			size_t activeElemIndex;
			csc_hudelem_s* activeHuds;
			int i;

			activeElemIndex = 0;
			activeHuds = csc_hudelems;
			for (i = 0; i < MAX_CSC_HUDELEMS; ++i)                    // CopyInUseHudElems
			{
				if (activeHuds[i].elem.type != HE_TYPE_FREE)
				{
					huds[activeElemIndex++] = &activeHuds[i];
				}
			}
			qsort(huds, activeElemIndex, sizeof(csc_hudelem_s*), (_CoreCrtNonSecureSearchSortCompareFunction)compare_hudelems);
			return activeElemIndex;
		}

		// Decomp Status: Untested
		// void __usercall HudElemColorToVec4(float *color@<eax>, hudelem_color_t *hudElemColor@<ecx>)
		void HudElemColorToVec4(float* color, hudelem_color_t* hudElemColor)
		{
			float brightnessScale;

			color[0] = (float)(unsigned __int8)hudElemColor->color.r * 0.0039215689;
			color[1] = (float)(unsigned __int8)hudElemColor->color.g * 0.0039215689;
			color[2] = (float)(unsigned __int8)hudElemColor->color.b * 0.0039215689;
			color[3] = (float)(unsigned __int8)hudElemColor->color.a * 0.0039215689;
			if ((*game::cl_paused)->current.integer)
			{
				brightnessScale = (*game::hudElemPausedBrightness)->current.value;
				color[0] = color[0] * brightnessScale;
				color[1] = color[1] * brightnessScale;
				color[2] = color[2] * brightnessScale;
			}
		}

		float R_NormalizedTextScale(Font_s* font, float scale)
		{
			return scale * 48.0 / (double)font->pixelHeight;
		}

		int R_TextHeight(Font_s* font)
		{
			return font->pixelHeight;
		}

		int UI_TextHeight(Font_s* font, float scale)
		{
			float result;
			float actualScale;

			actualScale = R_NormalizedTextScale(font, scale);
			result = (float)((float)R_TextHeight(font) * actualScale) + 0.5;
			return (int)floor(result);
		}

		// Decomp Status: Untested
		// void __usercall DrawHudElemClock(cg_hudelem_t *cghe@<eax>, int localClientNum@<ecx>, hudelem_s *elem)
		void DrawCSCHudElemClock(cg_hudelem_t* cghe, int localClientNum, csc_hudelem_s* hud)
		{
			Material* needleMaterial; // eax
			int duration;
			Material* clockMaterial;
			float height;
			float width;
			float y;
			char materialName[64];
			int clockTime;
			float angle;
			hudelem_s* elem;

			elem = &hud->elem;
			strncpy(materialName, hud->materialName, 64);
			clockMaterial = Material_RegisterHandle(materialName);
			game::I_strncat(64, materialName, "needle");
			needleMaterial = Material_RegisterHandle(materialName);
			clockTime = game::GetHudElemTime(elem, cghe->timeNow);
			duration = elem->duration;
			if (elem->duration)
				angle = game::AngleNormalize360((float)((float)clockTime * 360.0) / (float)elem->duration);
			else
				angle = game::AngleNormalize360((float)clockTime * 0.0060000001);
			width = game::HudElemMaterialWidth(elem, cghe, &game::scrPlaceFull[localClientNum]);
			height = game::HudElemMaterialHeight(elem, cghe, &game::scrPlaceFull[localClientNum]);
			y = game::OffsetHudElemY(elem, cghe, -0.0 - (float)(cghe->height - height));
			game::CL_DrawStretchPicPhysical(cghe->x, y, width, height, 0.0, 0.0, 1.0, 1.0, cghe->color, clockMaterial);
			game::CG_DrawRotatedPicPhysicalW(                 // CG_DrawRotatedPicPhysical
				&game::scrPlaceFull[localClientNum],
				angle,
				cghe->x,
				y,
				width,
				height,
				cghe->color,
				needleMaterial);
		}

		// Decomp Status: Untested
		// void GetHudElemInfo(int localClientNum, hudelem_s *elem, cg_hudelem_t *cghe, char *hudElemString)
		void GetCSCHudElemInfo(int localClientNum, csc_hudelem_s* hud, cg_hudelem_t* cghe, char* hudElemString)
		{
			float baseFontScale;
			int fontEnum;
			int fontScaleTime;
			int timeDiff;
			float elemFontScale;
			Font_s* font;
			char* label;
			char* hudElemText;
			char* text;
			const char* string;
			const char* string_1;
			ScreenPlacement* scrPlace;
			float fontScale;
			hudelem_s* elem;

			elem = &hud->elem;
			scrPlace = &game::scrPlaceFull[localClientNum];
			baseFontScale = 0.25;
			switch (elem->font)
			{
			case HE_FONT_BIGFIXED:
				baseFontScale = 0.5;
				fontEnum = 4;
				break;
			case HE_FONT_SMALLFIXED:
				baseFontScale = 0.33333334;
				fontEnum = 5;
				break;
			case HE_FONT_OBJECTIVE:
				fontEnum = 6;
				break;
			case HE_FONT_BIG:
				fontEnum = 2;
				break;
			case HE_FONT_SMALL:
				fontEnum = 3;
				break;
			default:
				fontEnum = 0;
				break;
			}
			fontScaleTime = elem->fontScaleTime;
			timeDiff = cghe->timeNow - elem->fontScaleStartTime;
			if (fontScaleTime <= 0 || timeDiff >= fontScaleTime)
			{
				elemFontScale = elem->fontScale;
			}
			else
			{
				if (timeDiff < 0)
				{
					timeDiff = 0;
				}
				elemFontScale = (float)((float)((float)timeDiff / (float)fontScaleTime) * (float)(elem->fontScale - elem->fromFontScale))
					+ elem->fromFontScale;
			}
			fontScale = (float)(scrPlace->scaleVirtualToReal[1] * elemFontScale) * baseFontScale;
			cghe->fontScale = fontScale;
			if (fontEnum == 2)
			{
				font = game::assets->bigFont;
			}
			else
			{
				font = game::UI_GetFontHandle(fontEnum, scrPlace, fontScale);
			}
			cghe->font = font;
			cghe->fontHeight = UI_TextHeight(font, cghe->fontScale);
			cghe->hudElemLabel[0] = 0;
			label = hud->label;
			if (label[0])
			{
				game::CG_TranslateHudElemMessage(
					label,
					"hudelem string",
					cghe->hudElemLabel,
					localClientNum);
			}
			hudElemText = cghe->hudElemText;
			cghe->hudElemText[0] = 0;
			switch (elem->type)
			{
			case HE_TYPE_TEXT:
				text = hud->text;
				if (text)
				{
					game::CG_TranslateHudElemMessage(
						text,
						"hudelem string",
						cghe->hudElemText,
						localClientNum);
				}
				break;
			case HE_TYPE_VALUE:
				sprintf(hudElemText, "%g", elem->value);
				break;
			case HE_TYPE_SCORE:
				if ((*game::language)->current.integer == 2)
				{
					sprintf(hudElemText, "%g", 0.0f);
				}
				else
				{
					sprintf(hudElemText, "%g", elem->value);
				}
				break;
			case HE_TYPE_TIMER_DOWN:
			case HE_TYPE_TIMER_UP:
				string = game::HudElemTimerString(elem, cghe->timeNow);
				game::CopyStringToHudElemString(hudElemText, string);
				break;
			case HE_TYPE_TENTHS_TIMER_DOWN:
			case HE_TYPE_TENTHS_TIMER_UP:
				string_1 = game::HudElemTenthsTimerString(elem, cghe->timeNow);
				game::CopyStringToHudElemString(hudElemText, string_1);
				break;
			default:
				break;
			}
			if (cghe->hudElemLabel[0] && *hudElemText)
			{
				game::ConsolidateHudElemText(hudElemString, elem, cghe);
			}
			if (cghe->hudElemLabel[0])
			{
				elem = elem;
				cghe->labelWidth = game::HudElemStringWidth(elem, cghe, cghe->hudElemLabel);
			}
			else
			{
				cghe->labelWidth = 0.0;
			}
			if (*hudElemText)
			{
				elem = elem;
				cghe->textWidth = game::HudElemStringWidth(elem, cghe, cghe->hudElemText);
			}
			else
			{
				cghe->textWidth = 0.0;
			}
			cghe->width = game::HudElemWidth(elem, cghe, scrPlace);
			cghe->height = game::HudElemHeight(elem, cghe, scrPlace);
			game::SetHudElemPos(cghe, elem, scrPlace);
			return;
		}

		float GetWaypointDataFloat(csc_hudelem_s* hud, float dvarValue, float hudValue)
		{
			if (hud->waypointData.useWaypointData)
			{
				return hudValue;
			}
			else
			{
				return dvarValue;
			}
		}

		void WaypointGetWorldPos(int localClientNum, csc_hudelem_s* hud, float* worldPos)
		{
			hudelem_s* elem = &hud->elem;
			int targetEntNum = elem->targetEntNum;
			centity_s* targetEnt;
			entityType_t eType;
			float stanceZOffset;
			float targetEntZPos;
			int eFlags;

			if (targetEntNum == 1023)
			{
				worldPos[0] = elem->x;
				worldPos[1] = elem->y;
				worldPos[2] = elem->z;
			}
			else
			{
				if (targetEntNum == game::cgArray->predictedPlayerEntity.nextState.number)
				{
					return;
				}
				targetEnt = game::CG_GetEntity(localClientNum, targetEntNum);
				eType = targetEnt->nextState.eType;
				worldPos[0] = targetEnt->pose.origin[0];
				worldPos[1] = targetEnt->pose.origin[1];
				targetEntZPos = targetEnt->pose.origin[2];
				worldPos[2] = targetEntZPos;
				if (eType == ET_PLAYER || eType == ET_ACTOR)
				{
					eFlags = targetEnt->currentState.eFlags;
					if ((eFlags & 8) != 0)
					{
						stanceZOffset = GetWaypointDataFloat(hud, (*game::waypointPlayerOffsetProne)->current.value, hud->waypointData.playerOffsetProne);
					}
					else if ((eFlags & 4) != 0)
					{
						stanceZOffset = GetWaypointDataFloat(hud, (*game::waypointPlayerOffsetCrouch)->current.value, hud->waypointData.playerOffsetCrouch);
					}
					else
					{
						stanceZOffset = GetWaypointDataFloat(hud, (*game::waypointPlayerOffsetStand)->current.value, hud->waypointData.playerOffsetStand);
					}
					worldPos[2] = stanceZOffset + targetEntZPos;
				}
			}
		}

		float GetScaleForDistance(csc_hudelem_s* hud, float* worldPos)
		{
			float rangeMin;
			float rangeMax;
			float range;
			float dist3D;
			float distSmallest;

			dist3D = sqrtf(
				(*worldPos - game::cgArray->refdef.vieworg[0])
					* (*worldPos - game::cgArray->refdef.vieworg[0]))
					+ (worldPos[1] - game::cgArray->refdef.vieworg[1])
						* (worldPos[1] - game::cgArray->refdef.vieworg[1])
				+ (worldPos[2] - game::cgArray->refdef.vieworg[2]) * (worldPos[2] - game::cgArray->refdef.vieworg[2]);
			rangeMin = GetWaypointDataFloat(hud, (*game::waypointDistScaleRangeMin)->current.value, hud->waypointData.distScaleRangeMin);
			if (rangeMin >= dist3D)
			{
				return 1.0f;
			}
			rangeMax = GetWaypointDataFloat(hud, (*game::waypointDistScaleRangeMax)->current.value, hud->waypointData.distScaleRangeMax);
			distSmallest = GetWaypointDataFloat(hud, (*game::waypointDistScaleSmallest)->current.value, hud->waypointData.distScaleSmallest);
			if (dist3D >= rangeMax)
			{
				return distSmallest;
			}
			range = rangeMax - rangeMin;
			if ((rangeMax - rangeMin) <= 0.0f)
			{
				range = 1.0f;
			}
			return (distSmallest * (dist3D - rangeMin) / range)
				+ (1.0f - (dist3D - rangeMin) / range);
		}

		// Decomp Status: Untested
		// void __usercall DrawOffscreenViewableWaypoint(int localClientNum, hudelem_s *elem)
		void DrawCSCOffscreenViewableWaypoint(int localClientNum, csc_hudelem_s* hud)
		{
			float scaleVirtualToRealX;
			float scaleVirtualToRealY;
			float offscreenPointerDistance;
			float scaleVirtualToRealAvg;
			float offscreenDistanceThresholdAlpha;
			float offscreenPointerHeight;
			float scaledOffscreenPointerDistance;
			float scaledOffscreenPointerHeight;
			float scaledOffscreenPointerHalfHeight;
			float padLeft;
			float v14;
			float padRight;
			float padBottom;
			float tweakY;
			float offscreenScale;
			float offscreenScaleSmallest;
			float arcTanAngle;
			float distScale;
			hudelem_flags_t flags;
			int labelStyle;
			float s1;
			float pointerIconWidth;
			float screenPos[2];
			float pointerIconHeight;
			float scale;
			float worldPos[3];
			float scaledOffscreenPointerDistance_1;
			float v42;
			float offscreenPointerWidth;
			float resultNormal[2];
			float color[4];
			float finalHeight;
			float padTop;
			bool hasMaterial;
			bool hasOffscreenMaterial;
			float color_1[4];
			cg_hudelem_t cghe;
			char hudElemLabel[256];
			hudelem_s* elem;
			hudelem_color_t toColor;
			Material* material;
			Material* offscreenMaterialPointer;
			float offscreenScaleSmallestDvarValue;
			bool isVisibleOnScreen = true;

			elem = &hud->elem;
			hasMaterial = hud->materialName[0] != '\0';
			hasOffscreenMaterial = hud->offscreenPointerMaterialName[0] != '\0';
			if ((game::cgArray->shellshock.duration + (game::cgArray->shellshock.startTime - game::cgArray->time)) > 0)
			{
				return;
			}
			BG_LerpHudColors(elem, game::cgArray->time, &toColor);
			if (!toColor.color.a)
			{
				return;
			}
			if (hasMaterial)
			{
				material = Material_RegisterHandle(hud->materialName);
			}
			else
			{
				material = 0;
			}
			HudElemColorToVec4(color, &toColor);
			scaleVirtualToRealX = game::scrPlaceFull[localClientNum].scaleVirtualToReal[0];
			scaleVirtualToRealY = game::scrPlaceFull[localClientNum].scaleVirtualToReal[1];
			pointerIconWidth = GetWaypointDataFloat(hud, (*game::waypointIconWidth)->current.value, hud->waypointData.iconWidth)* scaleVirtualToRealX;
			offscreenPointerDistance = GetWaypointDataFloat(hud, (*game::waypointOffscreenPointerDistance)->current.value, hud->waypointData.offscreenPointerDistance);
			pointerIconHeight = GetWaypointDataFloat(hud, (*game::waypointIconHeight)->current.value, hud->waypointData.iconHeight) * scaleVirtualToRealY;
			scaleVirtualToRealAvg = (scaleVirtualToRealX + scaleVirtualToRealY) * 0.5f;
			offscreenDistanceThresholdAlpha = GetWaypointDataFloat(hud, (*game::waypointOffscreenDistanceThresholdAlpha)->current.value, hud->waypointData.offscreenDistanceAlphaThreshold) * scaleVirtualToRealAvg;
			offscreenPointerWidth = GetWaypointDataFloat(hud, (*game::waypointOffscreenPointerWidth)->current.value, hud->waypointData.offscreenPointerWidth) * scaleVirtualToRealX;
			offscreenPointerHeight = GetWaypointDataFloat(hud, (*game::waypointOffscreenPointerHeight)->current.value, hud->waypointData.offscreenPointerHeight);
			scaledOffscreenPointerDistance = offscreenPointerDistance * scaleVirtualToRealAvg;
			scaledOffscreenPointerHeight = offscreenPointerHeight * scaleVirtualToRealY;
			finalHeight = scaledOffscreenPointerHeight;
			if (offscreenDistanceThresholdAlpha < 0.1f)
			{
				offscreenDistanceThresholdAlpha = 0.1f;
			}
			scaledOffscreenPointerHalfHeight = scaledOffscreenPointerHeight * 0.5f;
			padLeft = GetWaypointDataFloat(hud, (*game::waypointOffscreenPadLeft)->current.value, hud->waypointData.offscreenPadLeft) * scaleVirtualToRealX;
			v14 = scaledOffscreenPointerHalfHeight + scaledOffscreenPointerDistance;
			scale = padLeft + v14;
			padRight = GetWaypointDataFloat(hud, (*game::waypointOffscreenPadRight)->current.value, hud->waypointData.offscreenPadRight) * scaleVirtualToRealX;
			padTop = (GetWaypointDataFloat(hud, (*game::waypointOffscreenPadTop)->current.value, hud->waypointData.offscreenPadTop) * scaleVirtualToRealY) + v14;
			padBottom = (GetWaypointDataFloat(hud, (*game::waypointOffscreenPadBottom)->current.value, hud->waypointData.offscreenPadBottom) * scaleVirtualToRealY) + v14;
			tweakY = GetWaypointDataFloat(hud, (*game::waypointTweakY)->current.value, hud->waypointData.tweakY) * scaleVirtualToRealY;
			WaypointGetWorldPos(localClientNum, hud, worldPos);
			game::WorldPosToScreenPos(worldPos, localClientNum, screenPos);
			screenPos[1] = screenPos[1] + tweakY;
			if (game::ClampScreenPosToEdges(
				localClientNum,
				screenPos,
				scale,
				padRight + v14,
				padTop,
				padBottom,
				resultNormal,
				&scale) && (scale > 0.0f))
			{
				isVisibleOnScreen = false;
				if (hud->waypointData.showOffscreenPointer)
				{
					color_1[0] = color[0];
					color_1[1] = color[1];
					color_1[2] = color[2];
					color_1[3] = color[3];
					if (offscreenDistanceThresholdAlpha > scale)
					{
						color_1[3] = (color[3] / offscreenDistanceThresholdAlpha) * scale;
					}
					offscreenScale = GetWaypointDataFloat(hud, (*game::waypointOffscreenScaleLength)->current.value, hud->waypointData.offscreenScaleLength) * scaleVirtualToRealAvg;
					offscreenScaleSmallestDvarValue = (*game::waypointOffscreenScaleSmallest)->current.value;
					if (offscreenScale <= scale)
					{
						offscreenScaleSmallest = GetWaypointDataFloat(hud, offscreenScaleSmallestDvarValue, hud->waypointData.offscreenScaleSmallest);
					}
					else
					{
						offscreenScaleSmallest = (offscreenScaleSmallestDvarValue
							* (scale / offscreenScale))
							+ (1.0f - (scale / offscreenScale));
					}
					scaledOffscreenPointerDistance_1 = scaledOffscreenPointerDistance;
					pointerIconHeight = offscreenScaleSmallest * pointerIconHeight;
					pointerIconWidth = offscreenScaleSmallest * pointerIconWidth;
					scaledOffscreenPointerDistance = (resultNormal[0] * scaledOffscreenPointerDistance) + screenPos[0];
					v42 = (resultNormal[1] * scaledOffscreenPointerDistance_1) + screenPos[1];
					arcTanAngle = atan2(resultNormal[0], (-0.0f - resultNormal[1]));
					if (hasOffscreenMaterial)
					{
						offscreenMaterialPointer = Material_RegisterHandle(hud->offscreenPointerMaterialName);
					}
					else
					{
						offscreenMaterialPointer = game::cgMedia->offscreenObjectivePointer;
					}
					game::CL_DrawStretchPicPhysicalRotateXY(
						color_1,
						offscreenMaterialPointer,
						scaledOffscreenPointerDistance - (offscreenPointerWidth * 0.5f),
						v42 - scaledOffscreenPointerHalfHeight,
						offscreenPointerWidth,
						finalHeight,
						arcTanAngle * 57.295776);
				}
			}
			distScale = GetScaleForDistance(hud, worldPos);
			if (hasMaterial && hud->waypointData.showMaterial && (isVisibleOnScreen || hud->waypointData.showMaterialOffscreen))
			{
				pointerIconHeight = distScale * pointerIconHeight;
				pointerIconWidth = distScale * pointerIconWidth;
				game::CL_DrawStretchPic(
					material,
					color,
					screenPos[0] - (pointerIconWidth * 0.5f),
					screenPos[1] - (pointerIconHeight * 0.5f),
					pointerIconWidth,
					pointerIconHeight,
					0.0f,
					0.0f,
					1.0f,
					1.0f);
			}
			GetCSCHudElemInfo(localClientNum, hud, &cghe, hudElemLabel);
			if (cghe.hudElemLabel[0] == '\0' || (!isVisibleOnScreen && !hud->waypointData.showLabelOffscreen))
			{
				return;
			}
			if (hasMaterial)
			{
				screenPos[1] = screenPos[1] - 15.0f; //TODO make this adjustable
			}
			flags = elem->flags;
			labelStyle = 0;
			if ((flags & HE_FLAG_SHADOWED) != 0)
			{
				labelStyle = 3;
			}
			else if ((flags & HE_FLAG_SHADOWEDMORE) != 0)
			{
				labelStyle = 6;
			}
			if ((flags & HE_FLAG_SET3DFONTUSEGLOWCOLOR) != 0)
			{
				game::HudElemColorToVec4(color, &elem->glowColor);
			}
			s1 = cghe.fontScale * distScale;
			game::CL_DrawTextPhysical(
				cghe.font,
				labelStyle,
				cghe.hudElemLabel,
				32,
				screenPos[0] - (cghe.labelWidth * 0.5f),
				screenPos[1],
				s1,
				s1,
				color);
		}

		// Decomp Status: Untested
		// void __usercall DrawHudElemString(cg_hudelem_t *cghe@<eax>, ScreenPlacement *scrPlace@<ecx>, int localClientNum, char *text, hudelem_s *elem)
		void DrawCSCHudElemString(cg_hudelem_t* cghe, ScreenPlacement* scrPlace, int localClientNum, char* text, csc_hudelem_s* hud)
		{
			float v8;
			int fxBirthTime;
			float glowColorR;
			float glowColorG;
			float glowColorB;
			float brightness;
			char* v14;
			float textScale;
			float scaleX;
			float y;
			hudelem_s* elem;

			elem = &hud->elem;
			y = game::OffsetHudElemY(elem, cghe, -0.0 - (float)(cghe->height - cghe->fontHeight));
			fxBirthTime = elem->fxBirthTime;
			textScale = (float)(cghe->fontScale * 48.0) / (float)cghe->font->pixelHeight;// R_NormalizedTextScale ScrPlace_HiResGetScale
			scaleX = (scrPlace->scaleRealToVirtual[1] * scrPlace->scaleVirtualToReal[0]) * textScale;
			if (fxBirthTime && fxBirthTime > cghe->timeNow)
			{
				fxBirthTime = cghe->timeNow;
			}
			glowColorR = (float)(unsigned __int8)elem->glowColor.color.r * 0.0039215689;
			game::glowColor[0] = glowColorR;
			glowColorG = (float)(unsigned __int8)elem->glowColor.color.g * 0.0039215689;
			game::glowColor[1] = glowColorG;
			glowColorB = (float)(unsigned __int8)elem->glowColor.color.b * 0.0039215689;
			game::glowColor[2] = glowColorB;
			game::glowColor[3] = (float)(unsigned __int8)elem->glowColor.color.a * 0.0039215689;
			if ((*game::cl_paused)->current.integer)
			{
				brightness = (*game::hudElemPausedBrightness)->current.value;
				game::glowColor[0] = glowColorR * brightness;
				game::glowColor[1] = glowColorG * brightness;
				game::glowColor[2] = glowColorB * brightness;
			}
			if (fxBirthTime)
			{
				v14 = game::SEH_PrintStrlen(text);
				game::CL_PlayTextFXPulseSounds(
					elem->fxDecayStartTime,
					v14,
					fxBirthTime,
					localClientNum,
					cghe->timeNow,
					elem->fxLetterTime,
					&game::cgArray->hudElemSound[elem->soundID].lastPlayedTime);
			}
			game::R_AddCmdDrawTextWithEffects(
				text,
				0x7FFFFFFF,
				cghe->font,
				cghe->x,
				cghe->fontHeight + y,
				scaleX,
				textScale,
				cghe->color,
				3,
				game::cgMedia->textDecodeCharacters,
				game::cgMedia->textDecodeCharactersGlow,
				fxBirthTime,
				elem->fxLetterTime,
				elem->fxDecayStartTime,
				elem->fxDecayDuration);
		}

		void DrawCSCHudElemMaterial(cg_hudelem_t* cghe, int localClientNum, csc_hudelem_s* hud)
		{
			Material* material;
			float y;
			float width;
			float height;
			hudelem_s* elem;

			elem = &hud->elem;
			material = Material_RegisterHandle(hud->materialName);
			height = game::HudElemMaterialHeight(elem, cghe, &game::scrPlaceFull[localClientNum]);
			width = game::HudElemMaterialWidth(elem, cghe, &game::scrPlaceFull[localClientNum]);
			y = game::OffsetHudElemY(elem, cghe, 0.0f - (cghe->height - height));
			game::CL_DrawStretchPicPhysical(
				cghe->x,
				y,
				width,
				height,
				0.0,
				0.0,
				1.0,
				1.0,
				cghe->color,
				material);
		}

		void DrawSingleCSCHudElem2d(int localClientNum, csc_hudelem_s* hud)
		{
			hudelem_color_t v2;
			hudelem_color_t toColor;
			cg_hudelem_t cghe;
			char hudElemString[256];
			hudelem_s* elem;

			elem = &hud->elem;
			if (elem->type)
			{
				if (elem->type == HE_TYPE_WAYPOINT)
				{
					DrawCSCOffscreenViewableWaypoint(localClientNum, hud);
				}
				else
				{
					cghe.timeNow = game::cgArray->time;
					BG_LerpHudColors(elem, game::cgArray->time, &toColor);
					if (toColor.color.a)
					{
						HudElemColorToVec4(cghe.color, &toColor);
						GetCSCHudElemInfo(localClientNum, hud, &cghe, hudElemString);
						if (cghe.hudElemLabel[0])
						{
							DrawCSCHudElemString(&cghe, &game::scrPlaceFull[localClientNum], localClientNum, cghe.hudElemLabel, hud);
							cghe.x = cghe.x + cghe.labelWidth;
						}
						switch (elem->type)
						{
						case HE_TYPE_TEXT:
						case HE_TYPE_VALUE:
						case HE_TYPE_TIMER_DOWN:
						case HE_TYPE_TIMER_UP:
						case HE_TYPE_TENTHS_TIMER_DOWN:
						case HE_TYPE_TENTHS_TIMER_UP:
							if (cghe.hudElemText[0])
							{
								DrawCSCHudElemString(&cghe, &game::scrPlaceFull[localClientNum], localClientNum, cghe.hudElemText, hud);
							}
							break;
						case HE_TYPE_SCORE:
							if ((*game::language)->current.integer != 2 && cghe.hudElemText[0])
							{
								DrawCSCHudElemString(&cghe, &game::scrPlaceFull[localClientNum], localClientNum, cghe.hudElemText, hud);
							}
							break;
						case HE_TYPE_MATERIAL:
							DrawCSCHudElemMaterial(&cghe, localClientNum, hud);
							break;
						case HE_TYPE_CLOCK_DOWN:
						case HE_TYPE_CLOCK_UP:
							DrawCSCHudElemClock(&cghe, localClientNum, hud);
							break;
						default:
							return;
						}
					}
				}
			}
		}

		BOOL BG_UsingSniperScope(playerState_s* ps)
		{
			WeaponDef* weapon = game::bg_weaponDefs[ps->weapon];
			weapOverlayReticle_t overlayReticleType = weapon->overlayReticle;
			float weaponPosFrac = ps->fWeaponPosFrac;
			bool hasScopeOverlayMaterial = weapon->overlayMaterial;
		
			if (hasScopeOverlayMaterial)
			{
				const char* ree = "ree";
			}
			return hasScopeOverlayMaterial && weaponPosFrac > 0.9;
		}

		void CG_Draw2dCSCHudElemList(int localClientNum, csc_hudelem_s** huds, int count, int foreground, bool playerAlive)
		{
			int i;
			csc_hudelem_s* elem;
			hudelem_flags_t flags;
			playerState_s* ps = &game::cgArray->predictedPlayerState;
			//playerState_s* ps = &game::cgArray->nextSnap->ps;

			for (i = 0; i < count; ++i)
			{
				elem = huds[i];
				flags = elem->elem.flags;
				if (elem->archived)
				{

				}
				if (playerAlive || (flags & HE_FLAG_HIDEWHENDEAD) == 0)
				{
					if (((flags & HE_FLAG_HIDEWHENINMENU) != 0) && game::uiInfoArray->openMenuCount)
					{
						continue;
					}
					if ((flags & HE_FLAG_HIDEWHENINSCOPE) != 0 && BG_UsingSniperScope(ps))
					{
						continue;
					}
					if (foreground)
					{
						if ((flags & HE_FLAG_FOREGROUND) != 0)
						{
							DrawSingleCSCHudElem2d(localClientNum, elem);
						}
					}
					else if ((flags & HE_FLAG_FOREGROUND) == 0)
					{
						DrawSingleCSCHudElem2d(localClientNum, elem);
					}
				}
			}
		}

		void CG_Draw2dCSCHudElems(int localClientNum, int foreground)
		{
			int count;
			csc_hudelem_s* activeHuds[MAX_CSC_HUDELEMS];

			count = GetSortedCSCHudElems(activeHuds);
			if (count)
			{
				CG_Draw2dCSCHudElemList(localClientNum, activeHuds, count, foreground, game::cgArray->nextSnap->ps.pm_type < PM_LASTSTAND_TRANSITION);
			}
		}

		bool processingCSCHudelems = false;

		void CG_Draw2dHudElems_stub(int localClientNum, int foreground)
		{
			processingCSCHudelems = false;
			CG_Draw2dHudElems_hook.invoke<void>(localClientNum, foreground);
			processingCSCHudelems = true;
			memcpy(csc_hudelems_for_deltas, csc_hudelems, sizeof(csc_hudelems_for_deltas));
			CG_Draw2dCSCHudElems(localClientNum, foreground);
		}

		void HECmd_GetHudElemArray()
		{
			int i;
			int paramCount;

			game::Scr_MakeArray(game::SCRIPTINSTANCE_CLIENT);
			for (i = 0; i < MAX_CSC_HUDELEMS; ++i)
			{
				if (csc_hudelems[i].elem.type)
				{
					Scr_AddHudElem(&csc_hudelems[i]);
					game::Scr_AddArray(game::SCRIPTINSTANCE_CLIENT);
				}
			}
		}

		void P_DamageFeedback_call(gentity_s* ent, [[maybe_unused]] void* call_addr)
		{
			game::P_DamageFeedback(ent, P_DamageFeedback_original);
			ent->client->ps.stats[2] = ent->maxhealth;
		}

		NAKED void P_DamageFeedback_stub()
		{
			__asm
			{
				push eax;
				call P_DamageFeedback_call;
				add esp, 0x4;
				ret;
			}
		}

		void CScr_GetLocalActorHealth(scr_entref_t entref)
		{
			int actorHealth;

			if (entref.classnum != CLASS_NUM_ENTITY)
			{
				game::Scr_Error("not an entity", game::SCRIPTINSTANCE_CLIENT, false);
			}
			centity_s* ent = game::CG_GetEntity(entref.client, entref.entnum);

			if (ent->nextState.eType != ET_ACTOR)
			{
				game::Scr_Error("not an actor", game::SCRIPTINSTANCE_CLIENT, false);
			}

			actorHealth = ent->nextState.lerp.u.anonymous.data[3];
			game::Scr_AddInt(game::SCRIPTINSTANCE_CLIENT, actorHealth);
		}

		void CScr_GetLocalActorMaxHealth(scr_entref_t entref)
		{
			int actorHealth;

			if (entref.classnum != CLASS_NUM_ENTITY)
			{
				game::Scr_Error("not an entity", game::SCRIPTINSTANCE_CLIENT, false);
			}
			centity_s* ent = game::CG_GetEntity(entref.client, entref.entnum);

			if (ent->nextState.eType != ET_ACTOR)
			{
				game::Scr_Error("not an actor", game::SCRIPTINSTANCE_CLIENT, false);
			}

			actorHealth = ent->nextState.lerp.u.anonymous.data[4];
			game::Scr_AddInt(game::SCRIPTINSTANCE_CLIENT, actorHealth);
		}

		void SHECmd_RegisterArchivedHudelem()
		{
			std::string nameId = game::Scr_GetString(0, SCRIPTINSTANCE_SERVER);

			if (serverArchivedHudelemIds.contains(nameId))
			{
				game::Scr_Error(game::va("%s is already registered as an archived csc hudelem", nameId), SCRIPTINSTANCE_SERVER, false);
			}

			serverArchivedHudelemIds.insert_or_assign(nameId, nameId);
		}

		void SHECmd_UnregisterArchivedHudelem()
		{
			std::string nameId = game::Scr_GetString(0, SCRIPTINSTANCE_SERVER);

			if (!serverArchivedHudelemIds.contains(nameId))
			{
				game::Scr_Error(game::va("%s is not registered as an archived csc hudelem", nameId), SCRIPTINSTANCE_SERVER, false);
			}

			serverArchivedHudelemIds.erase(nameId);
		}

		void HECmd_SetArchived(scr_entref_t entref)
		{
			csc_hudelem_s* hud = HECmd_GetHudElem(entref);
			const char* nameId = game::Scr_GetString(0, game::SCRIPTINSTANCE_CLIENT);
			if (!hud->archived)
			{
				if ((archivedHudelemClientCount + 1) >= MAX_CSC_ARCHIVED_HUDELEMS)
				{
					game::Scr_Error(game::va("hit limit of csc archived hudelems max is %s", MAX_CSC_ARCHIVED_HUDELEMS), game::SCRIPTINSTANCE_CLIENT, false);
				}
				archivedHudelemClientCount++;
				hud->archived = 1;
				strncpy(hud->nameId, nameId, sizeof(hud->nameId));
				clientArchivedHudelems.insert_or_assign(nameId, hud);
			}
		}

		void HECmd_UnsetArchived(scr_entref_t entref)
		{
			csc_hudelem_s* hud = HECmd_GetHudElem(entref);
			const char* nameId = hud->nameId;
			if (hud->archived)
			{
				archivedHudelemClientCount--;
				hud->archived = 0;
				memset(hud->nameId, 0, sizeof(hud->nameId));
				if (clientArchivedHudelems.contains(nameId))
				{
					clientArchivedHudelems.erase(nameId);
				}
			}
		}

		std::string HudElem_GetDeltasServerMessage(csc_hudelem_s* newHud, csc_hudelem_s* oldHud)
		{
			std::string buffer;
			void* ofs1;
			void* ofs2;
			csc_hudelem_netfield_value value1;
			csc_hudelem_netfield_value value2;
			csc_hudelem_netfield_t* field;

			for (field = cscHudelemNetfields; field; field++)
			{
				ofs1 = (reinterpret_cast<char*>(newHud) + field->ofs);
				ofs2 = (reinterpret_cast<char*>(oldHud) + field->ofs);
				switch (field->type)
				{
				case CSC_HE_NETFIELD_TYPE_INT:
					value1.intValue = *reinterpret_cast<int*>(ofs1);
					value2.intValue = *reinterpret_cast<int*>(ofs2);
					if (value1.intValue != value2.intValue)
					{
						buffer += "|["s + field->id + ","s + std::to_string(value1.intValue) + "]"s;
					}
					break;
				case CSC_HE_NETFIELD_TYPE_FLOAT:
					value1.floatValue = *reinterpret_cast<float*>(ofs1);
					value2.floatValue = *reinterpret_cast<float*>(ofs2);
					if (value1.intValue != value2.intValue)
					{
						buffer += "|["s + field->id + ","s + std::to_string(value1.floatValue) + "]"s;
					}
					break;
				case CSC_HE_NETFIELD_TYPE_STRING:
					value1.stringValue = reinterpret_cast<const char*>(ofs1);
					value2.stringValue = reinterpret_cast<const char*>(ofs2);
					if (game::I_stricmp(0x7FFFFFFF, value1.stringValue, value2.stringValue))
					{
						buffer += "|["s + field->id + ","s + std::string(value1.stringValue) + "]"s;
					}
					break;
				case CSC_HE_NETFIELD_TYPE_COLOR:
					value1.intValue = *reinterpret_cast<int*>(ofs1);
					value2.intValue = *reinterpret_cast<int*>(ofs2);
					if (value1.intValue != value2.intValue)
					{
						buffer += "|["s + field->id + ","s + std::to_string(value1.intValue) + "]"s;
					}
					break;
				default:
					continue;
				}

			}
		}

		std::string HudElem_ConstructServerMessage()
		{
			std::string buffer;
			std::string lastGoodBuffer;
			csc_hudelem_s* newHud;
			csc_hudelem_s* oldHud;
			int i;

			for (i = 0; i < MAX_CSC_HUDELEMS; ++i)
			{
				newHud = &csc_hudelems[i];
				oldHud = &csc_hudelems_for_deltas[i];

				if (!oldHud->archived)
				{
					continue;
				}
				if (game::I_stricmp(0x7FFFFFFF, newHud->nameId, oldHud->nameId))
				{
					continue;
				}
				buffer += "hcsc ["s + newHud->nameId + "]"s;

				if (newHud->elem.type == HE_TYPE_FREE)
				{
					buffer += "|[f0,0]"s;
					continue;
				}

				buffer += HudElem_GetDeltasServerMessage(newHud, oldHud);
				if (buffer.length() >= SCRIPT_NETWORK_NOTIFY_MAX_LEN) //Drop excess hud updates for now
				{
					buffer = lastGoodBuffer;
					break;
				}
				lastGoodBuffer = buffer;
			}

			return buffer;
		}

		void HudElem_SendHudelemDeltasMessageToServer()
		{
			std::string msg = HudElem_ConstructServerMessage();

			if (msg.empty())
			{
				return;
			}

			if (msg.length() >= SCRIPT_NETWORK_NOTIFY_MAX_LEN)
			{
				return;
			}

			game::CL_AddReliableCommand(msg.c_str());
		}

		void HudElem_ReceivehudelemDeltasMessageFromServer()
		{

		}

		void HudElem_SendHudelemDeltasMessageToClient()
		{

		}
	}

	class component final : public component_interface
	{
	public:
		void post_unpack() override
		{
		#if CSC_HUD_PATCHES
			CG_Draw2dHudElems_hook.create(0x44DD50, CG_Draw2dHudElems_stub);

			P_DamageFeedback_hook.create(0x4E7000, P_DamageFeedback_stub);

			P_DamageFeedback_original = P_DamageFeedback_hook.get_original();

			//Always call entityspawned callback for actors in CSC
			utils::hook::nop(0x42AF9E, 6);
			//utils::hook::nop(0x42AFAC, 2);

			csc::method::add("settext", HECmd_SetText);
			csc::method::add("settargetent", HECmd_SetTargetEnt);
			csc::method::add("cleartargetent", HECmd_ClearTargetEnt);
			csc::method::add("destroy", HECmd_Destroy);
			csc::method::add("fadeovertime", HECmd_FadeOverTime);
			csc::method::add("moveovertime", HECmd_MoveOverTime);
			csc::method::add("reset", HECmd_Reset);
			csc::method::add("scaleovertime", HECmd_ScaleOverTime);
			csc::method::add("setclock", HECmd_SetClock);
			csc::method::add("setclockup", HECmd_SetClockUp);
			csc::method::add("setshader", HECmd_SetShader);
			//method::add("setpulsefx", HECmd_SetPulseFX);
			csc::method::add("settenthstimer", HECmd_SetTenthsTimer);
			csc::method::add("settenthstimerup", HECmd_SetTenthsTimerUp);
			csc::method::add("settimer", HECmd_SetTimer);
			csc::method::add("settimerup", HECmd_SetTimerUp);
			csc::method::add("setvalue", HECmd_SetValue);
			csc::method::add("setwaypoint", HECmd_SetWaypoint);
			csc::method::add("newclienthudelem", CScr_NewClientHudElem);
			csc::method::add("setarchived", HECmd_SetArchived);
			csc::method::add("unsetarchived", HECmd_UnsetArchived);
			csc::function::add("newhudelem", CScr_NewHudElem);
			csc::function::add("gethudelems", HECmd_GetHudElemArray);

			gsc::function::add("registerarchivedhudelem", SHECmd_RegisterArchivedHudelem);
			gsc::function::add("unregisterarchivedhudelem", SHECmd_UnregisterArchivedHudelem);

			script::AddClassmapGetterFunc(game::SCRIPTINSTANCE_CLIENT, CLASS_NUM_HUDELEM, 0,
				[](scriptInstance_t inst, int offset_, int entnum, int clientnum)
				{
					void(__cdecl * getter)(csc_hudelem_s*, int);
					csc_hudelem_s* hud;
					csc_hudelem_field_t* field;

					hud = &csc_hudelems[entnum];
					field = &cscHudelemFields[offset_];
					getter = cscHudelemFields[offset_].getter;

					if (getter)
					{
						getter(hud, offset_);
					}
					else
					{
						game::GScr_GetGenericField(field->ofs, field->type, hud, inst, 0);
					}
				});
			script::AddClassmapSetterFunc(game::SCRIPTINSTANCE_CLIENT, CLASS_NUM_HUDELEM, 0,
				[](scriptInstance_t inst, int offset_, int entnum, int clientnum)
				{
					void(__cdecl * setter)(csc_hudelem_s*, int);
					csc_hudelem_s* hud;
					csc_hudelem_field_t* field;

					hud = &csc_hudelems[entnum];
					field = &cscHudelemFields[offset_];
					setter = cscHudelemFields[offset_].setter;

					if (setter)
					{
						setter(hud, offset_);
					}
					else
					{
						game::Scr_SetGenericField(field->type, 0, field->ofs, hud, inst);
					}
					return 1;
				});

			csc::method::add("getlocalactorhealth", CScr_GetLocalActorHealth);
			csc::method::add("getlocalactormaxhealth", CScr_GetLocalActorMaxHealth);

			test::CG_AddSaveLoadCallback(
				[](MemoryFile* saveFile)
				{
					int i;

					for (i = 0; i < MAX_CSC_HUDELEMS; i++)
					{
						if (csc_hudelems[i].elem.type == HE_TYPE_FREE)
						{
							continue;
						}
						game::MemFile_WriteData(saveFile, 2, &i);
						game::MemFile_WriteData(saveFile, sizeof(csc_hudelem_s), &csc_hudelems[i]);
					}
					i = -1;
					game::MemFile_WriteData(saveFile, 2, &i);
				},
				[](MemoryFile* saveFile)
					{
						int i;
						unsigned short entnum;

						memset(csc_hudelems, 0, sizeof(csc_hudelems));
						game::MemFile_ReadData(&entnum, 2u, saveFile);

						for (i = entnum; entnum != 0xFFFF; i = entnum)
						{
							game::MemFile_ReadData(&csc_hudelems[i], sizeof(csc_hudelem_s), saveFile);
							game::MemFile_ReadData(&entnum, 2u, saveFile);
						}
					});

			scheduler::on_postloadscripts(game::SCRIPTINSTANCE_CLIENT, []()
				{
					csc_hudelem_field_t* f;

					for (f = cscHudelemFields; f->name; ++f)
					{
						game::Scr_AddClassField(game::SCRIPTINSTANCE_CLIENT, CLASS_NUM_HUDELEM, f->name, (f - cscHudelemFields));
					}
				});

			scheduler::on_cg_pre_shutdown(
				[](int localClientNum)
				{
					int i;

					for (i = 0; i < MAX_CSC_HUDELEMS; ++i)
					{
						if (csc_hudelems[i].elem.type)
						{
							HudElem_Free(&csc_hudelems[i]);
						}
					}
					memset(csc_hudelems, 0, sizeof(csc_hudelems));
				});

			test::Cmd_AddCustomClientCmdHandler(DEPLOYABLE_CMD_HUDELEM_ARCHIVE, []()
				{
					int argCount = game::Cmd_Argc();
					int i;

					return true;
				});

			test::Cmd_AddCustomServerCmdHandler("hcsc", [](client_s* client)
				{
					int argCount = game::SV_Cmd_Argc();
					int i;

					gclient_s* gClient = client->gentity->client;

					if ((gClient->ps.otherFlags & POF_ISSPECTATING) != 0 && gClient->spectatorClient)
					{

					}

					return true;
				});
		#endif		
		}

	private:
	};
}
REGISTER_COMPONENT(csc_hud::component)
*/