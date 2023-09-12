#pragma once

#include <d3d11.h>

namespace game
{
	struct Material;
	struct FxEffectDef;
	struct XModel;
	struct GfxLightDef;
	struct pathnode_t;
	struct pathnode_tree_t;
	struct GfxPortal;
	struct GfxCell;
	struct menuDef_t;

	enum XAssetType
	{
		ASSET_TYPE_XMODELPIECES = 0x0,
		ASSET_TYPE_PHYSPRESET = 0x1,
		ASSET_TYPE_PHYSCONSTRAINTS = 0x2,
		ASSET_TYPE_DESTRUCTIBLEDEF = 0x3,
		ASSET_TYPE_XANIMPARTS = 0x4,
		ASSET_TYPE_XMODEL = 0x5,
		ASSET_TYPE_MATERIAL = 0x6,
		ASSET_TYPE_TECHNIQUE_SET = 0x7,
		ASSET_TYPE_IMAGE = 0x8,
		ASSET_TYPE_SOUND = 0x9,
		ASSET_TYPE_SOUND_PATCH = 0xA,
		ASSET_TYPE_CLIPMAP = 0xB,
		ASSET_TYPE_CLIPMAP_PVS = 0xC,
		ASSET_TYPE_COMWORLD = 0xD,
		ASSET_TYPE_GAMEWORLD_SP = 0xE,
		ASSET_TYPE_GAMEWORLD_MP = 0xF,
		ASSET_TYPE_MAP_ENTS = 0x10,
		ASSET_TYPE_GFXWORLD = 0x11,
		ASSET_TYPE_LIGHT_DEF = 0x12,
		ASSET_TYPE_UI_MAP = 0x13,
		ASSET_TYPE_FONT = 0x14,
		ASSET_TYPE_FONTICON = 0x15,
		ASSET_TYPE_MENULIST = 0x16,
		ASSET_TYPE_MENU = 0x17,
		ASSET_TYPE_LOCALIZE_ENTRY = 0x18,
		ASSET_TYPE_WEAPON = 0x19,
		ASSET_TYPE_WEAPONDEF = 0x1A,
		ASSET_TYPE_WEAPON_VARIANT = 0x1B,
		ASSET_TYPE_WEAPON_FULL = 0x1C,
		ASSET_TYPE_ATTACHMENT = 0x1D,
		ASSET_TYPE_ATTACHMENT_UNIQUE = 0x1E,
		ASSET_TYPE_WEAPON_CAMO = 0x1F,
		ASSET_TYPE_SNDDRIVER_GLOBALS = 0x20,
		ASSET_TYPE_FX = 0x21,
		ASSET_TYPE_IMPACT_FX = 0x22,
		ASSET_TYPE_AITYPE = 0x23,
		ASSET_TYPE_MPTYPE = 0x24,
		ASSET_TYPE_MPBODY = 0x25,
		ASSET_TYPE_MPHEAD = 0x26,
		ASSET_TYPE_CHARACTER = 0x27,
		ASSET_TYPE_XMODELALIAS = 0x28,
		ASSET_TYPE_RAWFILE = 0x29,
		ASSET_TYPE_STRINGTABLE = 0x2A,
		ASSET_TYPE_LEADERBOARD = 0x2B,
		ASSET_TYPE_XGLOBALS = 0x2C,
		ASSET_TYPE_DDL = 0x2D,
		ASSET_TYPE_GLASSES = 0x2E,
		ASSET_TYPE_EMBLEMSET = 0x2F,
		ASSET_TYPE_SCRIPTPARSETREE = 0x30,
		ASSET_TYPE_KEYVALUEPAIRS = 0x31,
		ASSET_TYPE_VEHICLEDEF = 0x32,
		ASSET_TYPE_MEMORYBLOCK = 0x33,
		ASSET_TYPE_ADDON_MAP_ENTS = 0x34,
		ASSET_TYPE_TRACER = 0x35,
		ASSET_TYPE_SKINNEDVERTS = 0x36,
		ASSET_TYPE_QDB = 0x37,
		ASSET_TYPE_SLUG = 0x38,
		ASSET_TYPE_FOOTSTEP_TABLE = 0x39,
		ASSET_TYPE_FOOTSTEPFX_TABLE = 0x3A,
		ASSET_TYPE_ZBARRIER = 0x3B,
		ASSET_TYPE_COUNT = 0x3C,
		ASSET_TYPE_STRING = 0x3C,
		ASSET_TYPE_ASSETLIST = 0x3D,
		ASSET_TYPE_REPORT = 0x3E,
		ASSET_TYPE_DEPEND = 0x3F,
		ASSET_TYPE_FULL_COUNT = 0x40,
	};

	enum ConstraintType
	{
		CONSTRAINT_NONE = 0x0,
		CONSTRAINT_POINT = 0x1,
		CONSTRAINT_DISTANCE = 0x2,
		CONSTRAINT_HINGE = 0x3,
		CONSTRAINT_JOINT = 0x4,
		CONSTRAINT_ACTUATOR = 0x5,
		CONSTRAINT_FAKE_SHAKE = 0x6,
		CONSTRAINT_LAUNCH = 0x7,
		CONSTRAINT_ROPE = 0x8,
		CONSTRAINT_LIGHT = 0x9,
		NUM_CONSTRAINT_TYPES = 0xA,
	};

	enum AttachPointType
	{
		ATTACH_POINT_WORLD = 0x0,
		ATTACH_POINT_DYNENT = 0x1,
		ATTACH_POINT_ENT = 0x2,
		ATTACH_POINT_BONE = 0x3,
	};

	enum SndBankState
	{
		SND_BANK_STATE_NEW = 0x0,
		SND_BANK_STATE_STREAM_HEADER = 0x1,
		SND_BANK_STATE_STREAM_TOC = 0x2,
		SND_BANK_STATE_LOADED_HEADER = 0x3,
		SND_BANK_STATE_LOADED_TOC = 0x4,
		SND_BANK_STATE_LOADED_ASSET_WAIT = 0x5,
		SND_BANK_STATE_LOADED_ASSETS = 0x6,
		SND_BANK_STATE_READY_TO_USE = 0x7,
		SND_BANK_STATE_ERROR = 0x8,
	};

	enum DynEntityType
	{
		DYNENT_TYPE_INVALID = 0x0,
		DYNENT_TYPE_CLUTTER = 0x1,
		DYNENT_TYPE_DESTRUCT = 0x2,
		DYNENT_TYPE_COUNT = 0x3,
	};

	enum rope_constraint_e
	{
		ROPE_PAIR_CONSTRAINT = 0x0,
		ROPE_WORLD_CONSTRAINT = 0x1,
		ROPE_DENTITY_CONSTRAINT = 0x2,
		ROPE_CENTITY_CONSTRAINT = 0x3,
	};

	enum nodeType
	{
		NODE_BADNODE = 0x0,
		NODE_PATHNODE = 0x1,
		NODE_COVER_STAND = 0x2,
		NODE_COVER_CROUCH = 0x3,
		NODE_COVER_CROUCH_WINDOW = 0x4,
		NODE_COVER_PRONE = 0x5,
		NODE_COVER_RIGHT = 0x6,
		NODE_COVER_LEFT = 0x7,
		NODE_COVER_PILLAR = 0x8,
		NODE_AMBUSH = 0x9,
		NODE_EXPOSED = 0xA,
		NODE_CONCEALMENT_STAND = 0xB,
		NODE_CONCEALMENT_CROUCH = 0xC,
		NODE_CONCEALMENT_PRONE = 0xD,
		NODE_REACQUIRE = 0xE,
		NODE_BALCONY = 0xF,
		NODE_SCRIPTED = 0x10,
		NODE_NEGOTIATION_BEGIN = 0x11,
		NODE_NEGOTIATION_END = 0x12,
		NODE_TURRET = 0x13,
		NODE_GUARD = 0x14,
		NODE_NUMTYPES = 0x15,
		NODE_DONTLINK = 0x15,
	};

	enum AddressingMode
	{
		AM_INVALID = 0x0,
		AM_IMPLICIT = 0x1,
		AM_ACCUMULATOR = 0x2,
		AM_IMMEDIATE = 0x3,
		AM_RELATIVE = 0x4,
		AM_ZEROPAGE = 0x5,
		AM_ZEROPAGE_X = 0x6,
		AM_ZEROPAGE_Y = 0x7,
		AM_ABSOLUTE = 0x8,
		AM_ABSOLUTE_X = 0x9,
		AM_ABSOLUTE_Y = 0xA,
		AM_INDEXED_INDIRECT = 0xB,
		AM_INDIRECT_INDEXED = 0xC,
	};

	enum weapType_t
	{
		WEAPTYPE_BULLET = 0x0,
		WEAPTYPE_GRENADE = 0x1,
		WEAPTYPE_PROJECTILE = 0x2,
		WEAPTYPE_BINOCULARS = 0x3,
		WEAPTYPE_GAS = 0x4,
		WEAPTYPE_BOMB = 0x5,
		WEAPTYPE_MINE = 0x6,
		WEAPTYPE_MELEE = 0x7,
		WEAPTYPE_RIOTSHIELD = 0x8,
		WEAPTYPE_NUM = 0x9,
	};

	enum weapClass_t
	{
		WEAPCLASS_RIFLE = 0x0,
		WEAPCLASS_MG = 0x1,
		WEAPCLASS_SMG = 0x2,
		WEAPCLASS_SPREAD = 0x3,
		WEAPCLASS_PISTOL = 0x4,
		WEAPCLASS_GRENADE = 0x5,
		WEAPCLASS_ROCKETLAUNCHER = 0x6,
		WEAPCLASS_TURRET = 0x7,
		WEAPCLASS_NON_PLAYER = 0x8,
		WEAPCLASS_GAS = 0x9,
		WEAPCLASS_ITEM = 0xA,
		WEAPCLASS_MELEE = 0xB,
		WEAPCLASS_KILLSTREAK_ALT_STORED_WEAPON = 0xC,
		WEAPCLASS_PISTOL_SPREAD = 0xD,
		WEAPCLASS_NUM = 0xE,
	};

	enum PenetrateType
	{
		PENETRATE_TYPE_NONE = 0x0,
		PENETRATE_TYPE_SMALL = 0x1,
		PENETRATE_TYPE_MEDIUM = 0x2,
		PENETRATE_TYPE_LARGE = 0x3,
		PENETRATE_TYPE_COUNT = 0x4,
	};

	enum ImpactType
	{
		IMPACT_TYPE_NONE = 0x0,
		IMPACT_TYPE_BULLET_SMALL = 0x1,
		IMPACT_TYPE_BULLET_LARGE = 0x2,
		IMPACT_TYPE_BULLET_AP = 0x3,
		IMPACT_TYPE_BULLET_XTREME = 0x4,
		IMPACT_TYPE_SHOTGUN = 0x5,
		IMPACT_TYPE_GRENADE_BOUNCE = 0x6,
		IMPACT_TYPE_GRENADE_EXPLODE = 0x7,
		IMPACT_TYPE_RIFLE_GRENADE = 0x8,
		IMPACT_TYPE_ROCKET_EXPLODE = 0x9,
		IMPACT_TYPE_ROCKET_EXPLODE_XTREME = 0xA,
		IMPACT_TYPE_PROJECTILE_DUD = 0xB,
		IMPACT_TYPE_MORTAR_SHELL = 0xC,
		IMPACT_TYPE_TANK_SHELL = 0xD,
		IMPACT_TYPE_BOLT = 0xE,
		IMPACT_TYPE_BLADE = 0xF,
		IMPACT_TYPE_COUNT = 0x10,
	};

	enum weapInventoryType_t
	{
		WEAPINVENTORY_PRIMARY = 0x0,
		WEAPINVENTORY_OFFHAND = 0x1,
		WEAPINVENTORY_ITEM = 0x2,
		WEAPINVENTORY_ALTMODE = 0x3,
		WEAPINVENTORY_MELEE = 0x4,
		WEAPINVENTORY_DWLEFTHAND = 0x5,
		WEAPINVENTORYCOUNT = 0x6,
	};

	enum weapFireType_t
	{
		WEAPON_FIRETYPE_FULLAUTO = 0x0,
		WEAPON_FIRETYPE_SINGLESHOT = 0x1,
		WEAPON_FIRETYPE_BURSTFIRE2 = 0x2,
		WEAPON_FIRETYPE_BURSTFIRE3 = 0x3,
		WEAPON_FIRETYPE_BURSTFIRE4 = 0x4,
		WEAPON_FIRETYPE_BURSTFIRE5 = 0x5,
		WEAPON_FIRETYPE_STACKED = 0x6,
		WEAPON_FIRETYPE_MINIGUN = 0x7,
		WEAPON_FIRETYPE_CHARGESHOT = 0x8,
		WEAPON_FIRETYPE_JETGUN = 0x9,
		WEAPON_FIRETYPECOUNT = 0xA,
	};

	enum weapClipType_t
	{
		WEAPON_CLIPTYPE_BOTTOM = 0x0,
		WEAPON_CLIPTYPE_TOP = 0x1,
		WEAPON_CLIPTYPE_LEFT = 0x2,
		WEAPON_CLIPTYPE_DP28 = 0x3,
		WEAPON_CLIPTYPE_PTRS = 0x4,
		WEAPON_CLIPTYPE_LMG = 0x5,
		WEAPON_CLIPTYPECOUNT = 0x6,
	};

	enum barrelType_t
	{
		BARREL_TYPE_SINGLE = 0x0,
		BARREL_TYPE_DUAL = 0x1,
		BARREL_TYPE_DUAL_ALTERNATE = 0x2,
		BARREL_TYPE_QUAD = 0x3,
		BARREL_TYPE_QUAD_ALTERNATE = 0x4,
		BARREL_TYPE_QUAD_DOUBLE_ALTERNATE = 0x5,
		BARREL_TYPE_COUNT = 0x6,
	};

	enum OffhandClass
	{
		OFFHAND_CLASS_NONE = 0x0,
		OFFHAND_CLASS_FRAG_GRENADE = 0x1,
		OFFHAND_CLASS_SMOKE_GRENADE = 0x2,
		OFFHAND_CLASS_FLASH_GRENADE = 0x3,
		OFFHAND_CLASS_GEAR = 0x4,
		OFFHAND_CLASS_SUPPLYDROP_MARKER = 0x5,
		OFFHAND_CLASS_COUNT = 0x6,
	};

	enum OffhandSlot
	{
		OFFHAND_SLOT_NONE = 0x0,
		OFFHAND_SLOT_LETHAL_GRENADE = 0x1,
		OFFHAND_SLOT_TACTICAL_GRENADE = 0x2,
		OFFHAND_SLOT_EQUIPMENT = 0x3,
		OFFHAND_SLOT_SPECIFIC_USE = 0x4,
		OFFHAND_SLOT_COUNT = 0x5,
	};

	enum weapStance_t
	{
		WEAPSTANCE_STAND = 0x0,
		WEAPSTANCE_DUCK = 0x1,
		WEAPSTANCE_PRONE = 0x2,
		WEAPSTANCE_NUM = 0x3,
	};

	enum activeReticleType_t
	{
		VEH_ACTIVE_RETICLE_NONE = 0x0,
		VEH_ACTIVE_RETICLE_PIP_ON_A_STICK = 0x1,
		VEH_ACTIVE_RETICLE_BOUNCING_DIAMOND = 0x2,
		VEH_ACTIVE_RETICLE_MISSILE_LOCK = 0x3,
		VEH_ACTIVE_RETICLE_COUNT = 0x4,
	};

	enum weaponIconRatioType_t
	{
		WEAPON_ICON_RATIO_1TO1 = 0x0,
		WEAPON_ICON_RATIO_2TO1 = 0x1,
		WEAPON_ICON_RATIO_4TO1 = 0x2,
		WEAPON_ICON_RATIO_COUNT = 0x3,
	};

	enum ammoCounterClipType_t
	{
		AMMO_COUNTER_CLIP_NONE = 0x0,
		AMMO_COUNTER_CLIP_MAGAZINE = 0x1,
		AMMO_COUNTER_CLIP_SHORTMAGAZINE = 0x2,
		AMMO_COUNTER_CLIP_SHOTGUN = 0x3,
		AMMO_COUNTER_CLIP_ROCKET = 0x4,
		AMMO_COUNTER_CLIP_BELTFED = 0x5,
		AMMO_COUNTER_CLIP_ALTWEAPON = 0x6,
		AMMO_COUNTER_CLIP_COUNT = 0x7,
	};

	enum weapOverlayReticle_t
	{
		WEAPOVERLAYRETICLE_NONE = 0x0,
		WEAPOVERLAYRETICLE_CROSSHAIR = 0x1,
		WEAPOVERLAYRETICLE_NUM = 0x2,
	};

	enum WeapOverlayInteface_t
	{
		WEAPOVERLAYINTERFACE_NONE = 0x0,
		WEAPOVERLAYINTERFACE_JAVELIN = 0x1,
		WEAPOVERLAYINTERFACE_TURRETSCOPE = 0x2,
		WEAPOVERLAYINTERFACECOUNT = 0x3,
	};

	enum weapProjExposion_t
	{
		WEAPPROJEXP_GRENADE = 0x0,
		WEAPPROJEXP_ROCKET = 0x1,
		WEAPPROJEXP_FLASHBANG = 0x2,
		WEAPPROJEXP_NONE = 0x3,
		WEAPPROJEXP_DUD = 0x4,
		WEAPPROJEXP_SMOKE = 0x5,
		WEAPPROJEXP_HEAVY = 0x6,
		WEAPPROJEXP_FIRE = 0x7,
		WEAPPROJEXP_NAPALMBLOB = 0x8,
		WEAPPROJEXP_BOLT = 0x9,
		WEAPPROJEXP_SHRAPNELSPAN = 0xA,
		WEAPPROJEXP_NUM = 0xB,
	};

	enum WeapStickinessType
	{
		WEAPSTICKINESS_NONE = 0x0,
		WEAPSTICKINESS_ALL = 0x1,
		WEAPSTICKINESS_ALL_NO_SENTIENTS = 0x2,
		WEAPSTICKINESS_GROUND = 0x3,
		WEAPSTICKINESS_GROUND_WITH_YAW = 0x4,
		WEAPSTICKINESS_FLESH = 0x5,
		WEAPSTICKINESS_COUNT = 0x6,
	};

	enum WeapRotateType
	{
		WEAPROTATE_GRENADE_ROTATE = 0x0,
		WEAPROTATE_BLADE_ROTATE = 0x1,
		WEAPROTATE_CYLINDER_ROTATE = 0x2,
		WEAPROTATE_COUNT = 0x3,
	};

	enum guidedMissileType_t
	{
		MISSILE_GUIDANCE_NONE = 0x0,
		MISSILE_GUIDANCE_SIDEWINDER = 0x1,
		MISSILE_GUIDANCE_HELLFIRE = 0x2,
		MISSILE_GUIDANCE_JAVELIN = 0x3,
		MISSILE_GUIDANCE_BALLISTIC = 0x4,
		MISSILE_GUIDANCE_WIREGUIDED = 0x5,
		MISSILE_GUIDANCE_TVGUIDED = 0x6,
		MISSILE_GUIDANCE_DRONE = 0x7,
		MISSILE_GUIDANCE_HEATSEEKING = 0x8,
		MISSILE_GUIDANCE_COUNT = 0x9,
	};

	enum tracerType_t
	{
		TRACERTYPE_LASER = 0x0,
		TRACERTYPE_SMOKE = 0x1,
		TRACERTYPE_NUM = 0x2,
	};

	enum eAttachment
	{
		ATTACHMENT_NONE = 0x0,
		ATTACHMENT_ACOG = 0x1,
		ATTACHMENT_DUALCLIP = 0x2,
		ATTACHMENT_DUALOPTIC = 0x3,
		ATTACHMENT_DW = 0x4,
		ATTACHMENT_EXTBARREL = 0x5,
		ATTACHMENT_EXTCLIP = 0x6,
		ATTACHMENT_EXTRAMAGS = 0x7,
		ATTACHMENT_FASTADS = 0x8,
		ATTACHMENT_FASTRELOAD = 0x9,
		ATTACHMENT_FMJ = 0xA,
		ATTACHMENT_GL = 0xB,
		ATTACHMENT_GRIP = 0xC,
		ATTACHMENT_HOLO = 0xD,
		ATTACHMENT_IR = 0xE,
		ATTACHMENT_IRONSIGHTS = 0xF,
		ATTACHMENT_LONGBREATH = 0x10,
		ATTACHMENT_MK = 0x11,
		ATTACHMENT_MMS = 0x12,
		ATTACHMENT_RANGEFINDER = 0x13,
		ATTACHMENT_REFLEX = 0x14,
		ATTACHMENT_RF = 0x15,
		ATTACHMENT_SELECTFIRE = 0x16,
		ATTACHMENT_SILENCER = 0x17,
		ATTACHMENT_STACKFIRE = 0x18,
		ATTACHMENT_STALKER = 0x19,
		ATTACHMENT_STEADYAIM = 0x1A,
		ATTACHMENT_SWAYREDUC = 0x1B,
		ATTACHMENT_TACKNIFE = 0x1C,
		ATTACHMENT_VZOOM = 0x1D,
		ATTACHMENT_TYPE_COUNT = 0x1E,
		ATTACHMENT_INVALID = 0x1E,
	};

	enum eAttachmentPoint
	{
		ATTACHMENT_POINT_NONE = 0x0,
		ATTACHMENT_POINT_TOP = 0x1,
		ATTACHMENT_POINT_FIRST = 0x1,
		ATTACHMENT_POINT_BOTTOM = 0x2,
		ATTACHMENT_POINT_TRIGGER = 0x3,
		ATTACHMENT_POINT_MUZZLE = 0x4,
		ATTACHMENT_POINT_GUNPERK = 0x5,
		ATTACHMENT_POINT_COUNT = 0x6,
		ATTACHMENT_POINT_INVALID = 0x6,
	};

	enum SndMenuCategory
	{
		SND_CATEGORY_SFX = 0x0,
		SND_CATEGORY_MUSIC = 0x1,
		SND_CATEGORY_VOICE = 0x2,
		SND_CATEGORY_UI = 0x3,
		SND_CATEGORY_CINEMATIC = 0x4,
		SND_CATEGORY_COUNT = 0x5,
	};

	enum LbColType
	{
		LBCOL_TYPE_NUMBER = 0x0,
		LBCOL_TYPE_TIME = 0x1,
		LBCOL_TYPE_LEVELXP = 0x2,
		LBCOL_TYPE_PRESTIGE = 0x3,
		LBCOL_TYPE_BIGNUMBER = 0x4,
		LBCOL_TYPE_PERCENT = 0x5,
		LBCOL_TYPE_TIME_FULL = 0x6,
		LBCOL_TYPE_COUNT = 0x7,
	};

	enum LbAggType
	{
		LBAGG_TYPE_MIN = 0x0,
		LBAGG_TYPE_MAX = 0x1,
		LBAGG_TYPE_ADD = 0x2,
		LBAGG_TYPE_REPLACE = 0x3,
		LBAGG_TYPE_COUNT = 0x4,
	};

	enum LbUpdateType
	{
		LBUPDATE_TYPE_NORMAL = 0x0,
		LBUPDATE_TYPE_RANK = 0x1,
		LBUPDATE_TYPE_COMBINE = 0x2,
		LBUPDATE_TYPE_COUNT = 0x3,
	};

	enum TractionType
	{
		TRACTION_TYPE_FRONT = 0x0,
		TRACTION_TYPE_BACK = 0x1,
		TRACTION_TYPE_ALL_WD = 0x2,
		NUM_TRACTION_TYPES = 0x3,
	};

	union $C8C573B57ACA1D7542AD56C4163862EC
	{
		unsigned __int16* localBoneNames; //OFS: 0x0 SIZE: 0x4
		unsigned __int16* boneNames; //OFS: 0x1 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE($C8C573B57ACA1D7542AD56C4163862EC, 0x4);

	union $37E13A30061EC97EDA76440B3BA5E97A
	{
		unsigned __int8* localParentList; //OFS: 0x0 SIZE: 0x4
		unsigned __int8* parentList; //OFS: 0x1 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE($37E13A30061EC97EDA76440B3BA5E97A, 0x4);

	union $BF9640C0B3AB5E078C286DD9616EC22F
	{
		__int16* localQuats; //OFS: 0x0 SIZE: 0x4
		__int16* quats; //OFS: 0x1 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE($BF9640C0B3AB5E078C286DD9616EC22F, 0x4);

	union $E1CD6A013C1D28F2956F4983A8D1052C
	{
		float* localTrans; //OFS: 0x0 SIZE: 0x4
		float* trans; //OFS: 0x1 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE($E1CD6A013C1D28F2956F4983A8D1052C, 0x4);

	struct FxFloatRange
	{
		float base;
		float amplitude;
	};

	struct FxSpawnDefLooping
	{
		int intervalMsec;
		int count;
	};

	struct FxIntRange
	{
		int base;
		int amplitude;
	};

	struct FxSpawnDefOneShot
	{
		FxIntRange count;
	};

	union FxSpawnDef
	{
		FxSpawnDefLooping looping;
		FxSpawnDefOneShot oneShot;
	};

	struct FxElemAtlas
	{
		unsigned __int8 behavior;
		unsigned __int8 index;
		unsigned __int8 fps;
		unsigned __int8 loopCount;
		unsigned __int8 colIndexBits;
		unsigned __int8 rowIndexBits;
		unsigned __int16 entryCountAndIndexRange;
	};

	struct FxElemVec3Range
	{
		vec3_t base;
		vec3_t amplitude;
	};

	struct FxElemVelStateInFrame
	{
		FxElemVec3Range velocity;
		FxElemVec3Range totalDelta;
	};

	struct FxElemVelStateSample
	{
		FxElemVelStateInFrame local;
		FxElemVelStateInFrame world;
	};

	struct FxElemVisualState
	{
		unsigned __int8 color[4];
		float rotationDelta;
		float rotationTotal;
		float size[2];
		float scale;
	};

	struct FxElemVisStateSample
	{
		FxElemVisualState base;
		FxElemVisualState amplitude;
	};

	struct FxElemMarkVisuals
	{
		Material* materials[2];
	};

	union FxEffectDefRef
	{
		const FxEffectDef* handle;
		const char* name;
	};

	union FxElemVisuals
	{
		const void* anonymous;
		Material* material;
		XModel* model;
		FxEffectDefRef effectDef;
		const char* soundName;
		GfxLightDef* lightDef;
	};

	union FxElemDefVisuals
	{
		FxElemMarkVisuals* markArray;
		FxElemVisuals* array;
		FxElemVisuals instance;
	};

	struct FxTrailVertex
	{
		vec2_t pos;
		vec2_t normal;
		float texCoord;
	};

	union $9AE4384B2E191C29A56F9E26BDA4EEE5
	{
		FxTrailVertex* vertsEA;
		FxTrailVertex* verts;
	};

	union $D31B43AE1E46D24CA4A859818848B5E1
	{
		unsigned __int16* indsEA;
		unsigned __int16* inds;
	};

	struct FxTrailDef
	{
		int scrollTimeMsec;
		int repeatDist;
		int splitDist;
		int vertCount;
		$9AE4384B2E191C29A56F9E26BDA4EEE5 ___u4;
		int indCount;
		$D31B43AE1E46D24CA4A859818848B5E1 ___u6;
	};

	struct FxSpotLightDef
	{
		float fovInnerFraction;
		float startRadius;
		float endRadius;
	};

	union FxElemExtendedDefPtr
	{
		FxTrailDef* localTrailDef;
		FxTrailDef* trailDef;
		FxSpotLightDef* localSpotLightDef;
		FxSpotLightDef* spotLightDef;
		void* unknownDef;
	};

	struct FxBillboardTrim
	{
		float topWidth;
		float bottomWidth;
	};

	union FxElemDefUnion
	{
		FxBillboardTrim billboard;
		FxIntRange cloudDensityRange;
	};

	struct FxElemSpawnSound
	{
		const char* spawnSound;
	};

	struct FxElemDef
	{
		int flags;
		FxSpawnDef spawn;
		FxFloatRange spawnRange;
		FxFloatRange fadeInRange;
		FxFloatRange fadeOutRange;
		float spawnFrustumCullRadius;
		FxIntRange spawnDelayMsec;
		FxIntRange lifeSpanMsec;
		FxFloatRange spawnOrigin[3];
		FxFloatRange spawnOffsetRadius;
		FxFloatRange spawnOffsetHeight;
		FxFloatRange spawnAngles[3];
		FxFloatRange angularVelocity[3];
		FxFloatRange initialRotation;
		unsigned int rotationAxis;
		FxFloatRange gravity;
		FxFloatRange reflectionFactor;
		FxElemAtlas atlas;
		float windInfluence;
		unsigned __int8 elemType;
		unsigned __int8 visualCount;
		unsigned __int8 velIntervalCount;
		unsigned __int8 visStateIntervalCount;
		const FxElemVelStateSample* velSamples;
		const FxElemVisStateSample* visSamples;
		FxElemDefVisuals visuals;
		vec3_t collMins;
		vec3_t collMaxs;
		FxEffectDefRef effectOnImpact;
		FxEffectDefRef effectOnDeath;
		FxEffectDefRef effectEmitted;
		FxFloatRange emitDist;
		FxFloatRange emitDistVariance;
		FxEffectDefRef effectAttached;
		FxElemExtendedDefPtr extended;
		unsigned __int8 sortOrder;
		unsigned __int8 lightingFrac;
		unsigned __int8 unused[2];
		unsigned __int16 alphaFadeTimeMsec;
		unsigned __int16 maxWindStrength;
		unsigned __int16 spawnIntervalAtMaxWind;
		unsigned __int16 lifespanAtMaxWind;
		FxElemDefUnion u;
		FxElemSpawnSound spawnSound;
		vec2_t billboardPivot;
	};

	union $61F5C926DE458DD50372790800CB2CE8
	{
		const FxElemDef* elemDefs;
		const FxElemDef* localElemDefs;
	};

	struct FxEffectDef
	{
		const char* name;
		unsigned __int16 flags;
		unsigned __int8 efPriority;
		__int16 elemDefCountLooping;
		__int16 elemDefCountOneShot;
		__int16 elemDefCountEmission;
		int totalSize;
		int msecLoopingLife;
		int msecNonLoopingLife;
		$61F5C926DE458DD50372790800CB2CE8 ___u9;
		vec3_t boundingBoxDim;
		vec3_t boundingBoxCentre;
		float occlusionQueryDepthBias;
		int occlusionQueryFadeIn;
		int occlusionQueryFadeOut;
		FxFloatRange occlusionQueryScaleRange;
	};

	struct DObjAnimMat
	{
		vec4_t quat; //OFS: 0x0 SIZE: 0x10
		vec3_t trans; //OFS: 0x10 SIZE: 0xC
		float transWeight; //OFS: 0x1C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(DObjAnimMat, 0x20);
	ASSERT_STRUCT_OFFSET(DObjAnimMat, quat, 0x0);
	ASSERT_STRUCT_OFFSET(DObjAnimMat, trans, 0x10);
	ASSERT_STRUCT_OFFSET(DObjAnimMat, transWeight, 0x1C);

	struct XSurfaceVertexInfo
	{
		__int16 vertCount[4]; //OFS: 0x0 SIZE: 0x8
		unsigned __int16* vertsBlend; //OFS: 0x8 SIZE: 0x4
		float* tensionData; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(XSurfaceVertexInfo, 0x10);
	ASSERT_STRUCT_OFFSET(XSurfaceVertexInfo, vertCount, 0x0);
	ASSERT_STRUCT_OFFSET(XSurfaceVertexInfo, vertsBlend, 0x8);
	ASSERT_STRUCT_OFFSET(XSurfaceVertexInfo, tensionData, 0xC);

	union GfxColor
	{
		unsigned int packed; //OFS: 0x0 SIZE: 0x4
		unsigned __int8 array[4]; //OFS: 0x1 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxColor, 0x4);

	union PackedTexCoords
	{
		unsigned int packed; //OFS: 0x0 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(PackedTexCoords, 0x4);

	union PackedUnitVec
	{
		unsigned int packed; //OFS: 0x0 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(PackedUnitVec, 0x4);

	struct GfxPackedVertex
	{
		vec3_t xyz; //OFS: 0x0 SIZE: 0xC
		float binormalSign; //OFS: 0xC SIZE: 0x4
		GfxColor color; //OFS: 0x10 SIZE: 0x4
		PackedTexCoords texCoord; //OFS: 0x14 SIZE: 0x4
		PackedUnitVec normal; //OFS: 0x18 SIZE: 0x4
		PackedUnitVec tangent; //OFS: 0x1C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxPackedVertex, 0x20);
	ASSERT_STRUCT_OFFSET(GfxPackedVertex, xyz, 0x0);
	ASSERT_STRUCT_OFFSET(GfxPackedVertex, binormalSign, 0xC);
	ASSERT_STRUCT_OFFSET(GfxPackedVertex, color, 0x10);
	ASSERT_STRUCT_OFFSET(GfxPackedVertex, texCoord, 0x14);
	ASSERT_STRUCT_OFFSET(GfxPackedVertex, normal, 0x18);
	ASSERT_STRUCT_OFFSET(GfxPackedVertex, tangent, 0x1C);

	struct __declspec(align(2)) XSurfaceCollisionAabb
	{
		unsigned __int16 mins[3]; //OFS: 0x0 SIZE: 0x6
		unsigned __int16 maxs[3]; //OFS: 0x6 SIZE: 0x6
	};
	ASSERT_STRUCT_SIZE(XSurfaceCollisionAabb, 0xC);
	ASSERT_STRUCT_OFFSET(XSurfaceCollisionAabb, mins, 0x0);
	ASSERT_STRUCT_OFFSET(XSurfaceCollisionAabb, maxs, 0x6);

	struct __declspec(align(2)) XSurfaceCollisionNode
	{
		XSurfaceCollisionAabb aabb; //OFS: 0x0 SIZE: 0xC
		unsigned __int16 childBeginIndex; //OFS: 0xC SIZE: 0x2
		unsigned __int16 childCount; //OFS: 0xE SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(XSurfaceCollisionNode, 0x10);
	ASSERT_STRUCT_OFFSET(XSurfaceCollisionNode, aabb, 0x0);
	ASSERT_STRUCT_OFFSET(XSurfaceCollisionNode, childBeginIndex, 0xC);
	ASSERT_STRUCT_OFFSET(XSurfaceCollisionNode, childCount, 0xE);

	struct __declspec(align(2)) XSurfaceCollisionLeaf
	{
		unsigned __int16 triangleBeginIndex; //OFS: 0x0 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(XSurfaceCollisionLeaf, 0x2);
	ASSERT_STRUCT_OFFSET(XSurfaceCollisionLeaf, triangleBeginIndex, 0x0);

	struct XSurfaceCollisionTree
	{
		vec3_t trans; //OFS: 0x0 SIZE: 0xC
		vec3_t scale; //OFS: 0xC SIZE: 0xC
		unsigned int nodeCount; //OFS: 0x18 SIZE: 0x4
		XSurfaceCollisionNode* nodes; //OFS: 0x1C SIZE: 0x4
		unsigned int leafCount; //OFS: 0x20 SIZE: 0x4
		XSurfaceCollisionLeaf* leafs; //OFS: 0x24 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(XSurfaceCollisionTree, 0x28);
	ASSERT_STRUCT_OFFSET(XSurfaceCollisionTree, trans, 0x0);
	ASSERT_STRUCT_OFFSET(XSurfaceCollisionTree, scale, 0xC);
	ASSERT_STRUCT_OFFSET(XSurfaceCollisionTree, nodeCount, 0x18);
	ASSERT_STRUCT_OFFSET(XSurfaceCollisionTree, nodes, 0x1C);
	ASSERT_STRUCT_OFFSET(XSurfaceCollisionTree, leafCount, 0x20);
	ASSERT_STRUCT_OFFSET(XSurfaceCollisionTree, leafs, 0x24);

	struct XRigidVertList
	{
		unsigned __int16 boneOffset; //OFS: 0x0 SIZE: 0x2
		unsigned __int16 vertCount; //OFS: 0x2 SIZE: 0x2
		unsigned __int16 triOffset; //OFS: 0x4 SIZE: 0x2
		unsigned __int16 triCount; //OFS: 0x6 SIZE: 0x2
		XSurfaceCollisionTree* collisionTree; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(XRigidVertList, 0xC);
	ASSERT_STRUCT_OFFSET(XRigidVertList, boneOffset, 0x0);
	ASSERT_STRUCT_OFFSET(XRigidVertList, vertCount, 0x2);
	ASSERT_STRUCT_OFFSET(XRigidVertList, triOffset, 0x4);
	ASSERT_STRUCT_OFFSET(XRigidVertList, triCount, 0x6);
	ASSERT_STRUCT_OFFSET(XRigidVertList, collisionTree, 0x8);

	union $B77F0BA221CCC9E303D1734EFF8202BB
	{
		XRigidVertList* vertList; //OFS: 0x0 SIZE: 0x4
		XRigidVertList* vertListEA; //OFS: 0x1 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE($B77F0BA221CCC9E303D1734EFF8202BB, 0x4);

	struct __declspec(align(16)) XSurface
	{
		unsigned __int8 tileMode; //OFS: 0x0 SIZE: 0x1
		unsigned __int8 vertListCount; //OFS: 0x1 SIZE: 0x1
		unsigned __int16 flags; //OFS: 0x2 SIZE: 0x2
		unsigned __int16 vertCount; //OFS: 0x4 SIZE: 0x2
		unsigned __int16 triCount; //OFS: 0x6 SIZE: 0x2
		unsigned __int16 baseVertIndex; //OFS: 0x8 SIZE: 0x2
		unsigned __int16* triIndices; //OFS: 0xC SIZE: 0x4
		XSurfaceVertexInfo vertInfo; //OFS: 0x10 SIZE: 0x10
		GfxPackedVertex* verts0; //OFS: 0x20 SIZE: 0x4
		ID3D11Buffer* vb0; //OFS: 0x24 SIZE: 0x4
		$B77F0BA221CCC9E303D1734EFF8202BB ___u10; //OFS: 0x28 SIZE: 0x4
		ID3D11Buffer* indexBuffer; //OFS: 0x2C SIZE: 0x4
		int partBits[5]; //OFS: 0x30 SIZE: 0x14
	};
	ASSERT_STRUCT_SIZE(XSurface, 0x50);
	ASSERT_STRUCT_OFFSET(XSurface, tileMode, 0x0);
	ASSERT_STRUCT_OFFSET(XSurface, vertListCount, 0x1);
	ASSERT_STRUCT_OFFSET(XSurface, flags, 0x2);
	ASSERT_STRUCT_OFFSET(XSurface, vertCount, 0x4);
	ASSERT_STRUCT_OFFSET(XSurface, triCount, 0x6);
	ASSERT_STRUCT_OFFSET(XSurface, baseVertIndex, 0x8);
	ASSERT_STRUCT_OFFSET(XSurface, triIndices, 0xC);
	ASSERT_STRUCT_OFFSET(XSurface, vertInfo, 0x10);
	ASSERT_STRUCT_OFFSET(XSurface, verts0, 0x20);
	ASSERT_STRUCT_OFFSET(XSurface, vb0, 0x24);
	ASSERT_STRUCT_OFFSET(XSurface, ___u10, 0x28);
	ASSERT_STRUCT_OFFSET(XSurface, indexBuffer, 0x2C);
	ASSERT_STRUCT_OFFSET(XSurface, partBits, 0x30);

	struct __declspec(align(8)) GfxDrawSurfFields
	{
		__int64 _bf_0; //OFS: 0x0 SIZE: 0x8
	};
	ASSERT_STRUCT_SIZE(GfxDrawSurfFields, 0x8);
	ASSERT_STRUCT_OFFSET(GfxDrawSurfFields, _bf_0, 0x0);

	union GfxDrawSurf
	{
		GfxDrawSurfFields fields; //OFS: 0x0 SIZE: 0x8
		unsigned __int64 packed; //OFS: 0x1 SIZE: 0x8
	};
	ASSERT_STRUCT_SIZE(GfxDrawSurf, 0x8);

	struct __declspec(align(8)) MaterialInfo
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		unsigned int gameFlags; //OFS: 0x4 SIZE: 0x4
		unsigned __int8 pad; //OFS: 0x8 SIZE: 0x1
		unsigned __int8 sortKey; //OFS: 0x9 SIZE: 0x1
		unsigned __int8 textureAtlasRowCount; //OFS: 0xA SIZE: 0x1
		unsigned __int8 textureAtlasColumnCount; //OFS: 0xB SIZE: 0x1
		GfxDrawSurf drawSurf; //OFS: 0x10 SIZE: 0x8
		unsigned int surfaceTypeBits; //OFS: 0x18 SIZE: 0x4
		unsigned int layeredSurfaceTypes; //OFS: 0x1C SIZE: 0x4
		unsigned __int16 hashIndex; //OFS: 0x20 SIZE: 0x2
		int surfaceFlags; //OFS: 0x24 SIZE: 0x4
		int contents; //OFS: 0x28 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(MaterialInfo, 0x30);
	ASSERT_STRUCT_OFFSET(MaterialInfo, name, 0x0);
	ASSERT_STRUCT_OFFSET(MaterialInfo, gameFlags, 0x4);
	ASSERT_STRUCT_OFFSET(MaterialInfo, pad, 0x8);
	ASSERT_STRUCT_OFFSET(MaterialInfo, sortKey, 0x9);
	ASSERT_STRUCT_OFFSET(MaterialInfo, textureAtlasRowCount, 0xA);
	ASSERT_STRUCT_OFFSET(MaterialInfo, textureAtlasColumnCount, 0xB);
	ASSERT_STRUCT_OFFSET(MaterialInfo, drawSurf, 0x10);
	ASSERT_STRUCT_OFFSET(MaterialInfo, surfaceTypeBits, 0x18);
	ASSERT_STRUCT_OFFSET(MaterialInfo, layeredSurfaceTypes, 0x1C);
	ASSERT_STRUCT_OFFSET(MaterialInfo, hashIndex, 0x20);
	ASSERT_STRUCT_OFFSET(MaterialInfo, surfaceFlags, 0x24);
	ASSERT_STRUCT_OFFSET(MaterialInfo, contents, 0x28);

	struct __declspec(align(1)) MaterialStreamRouting
	{
		unsigned __int8 source; //OFS: 0x0 SIZE: 0x1
		unsigned __int8 dest; //OFS: 0x1 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(MaterialStreamRouting, 0x2);
	ASSERT_STRUCT_OFFSET(MaterialStreamRouting, source, 0x0);
	ASSERT_STRUCT_OFFSET(MaterialStreamRouting, dest, 0x1);

	struct MaterialVertexStreamRouting
	{
		MaterialStreamRouting data[16]; //OFS: 0x0 SIZE: 0x20
		ID3D11InputLayout* decl[20]; //OFS: 0x20 SIZE: 0x50
	};
	ASSERT_STRUCT_SIZE(MaterialVertexStreamRouting, 0x70);
	ASSERT_STRUCT_OFFSET(MaterialVertexStreamRouting, data, 0x0);
	ASSERT_STRUCT_OFFSET(MaterialVertexStreamRouting, decl, 0x20);

	struct MaterialVertexDeclaration
	{
		unsigned __int8 streamCount; //OFS: 0x0 SIZE: 0x1
		bool hasOptionalSource; //OFS: 0x1 SIZE: 0x1
		bool isLoaded; //OFS: 0x2 SIZE: 0x1
		MaterialVertexStreamRouting routing; //OFS: 0x4 SIZE: 0x70
	};
	ASSERT_STRUCT_SIZE(MaterialVertexDeclaration, 0x74);
	ASSERT_STRUCT_OFFSET(MaterialVertexDeclaration, streamCount, 0x0);
	ASSERT_STRUCT_OFFSET(MaterialVertexDeclaration, hasOptionalSource, 0x1);
	ASSERT_STRUCT_OFFSET(MaterialVertexDeclaration, isLoaded, 0x2);
	ASSERT_STRUCT_OFFSET(MaterialVertexDeclaration, routing, 0x4);

	struct GfxVertexShaderLoadDef
	{
		unsigned __int8* program; //OFS: 0x0 SIZE: 0x4
		unsigned int programSize; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxVertexShaderLoadDef, 0x8);
	ASSERT_STRUCT_OFFSET(GfxVertexShaderLoadDef, program, 0x0);
	ASSERT_STRUCT_OFFSET(GfxVertexShaderLoadDef, programSize, 0x4);

	struct MaterialVertexShaderProgram
	{
		ID3D11VertexShader* vs; //OFS: 0x0 SIZE: 0x4
		GfxVertexShaderLoadDef loadDef; //OFS: 0x4 SIZE: 0x8
	};
	ASSERT_STRUCT_SIZE(MaterialVertexShaderProgram, 0xC);
	ASSERT_STRUCT_OFFSET(MaterialVertexShaderProgram, vs, 0x0);
	ASSERT_STRUCT_OFFSET(MaterialVertexShaderProgram, loadDef, 0x4);

	struct MaterialVertexShader
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		MaterialVertexShaderProgram prog; //OFS: 0x4 SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(MaterialVertexShader, 0x10);
	ASSERT_STRUCT_OFFSET(MaterialVertexShader, name, 0x0);
	ASSERT_STRUCT_OFFSET(MaterialVertexShader, prog, 0x4);

	struct GfxPixelShaderLoadDef
	{
		unsigned __int8* program; //OFS: 0x0 SIZE: 0x4
		unsigned int programSize; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxPixelShaderLoadDef, 0x8);
	ASSERT_STRUCT_OFFSET(GfxPixelShaderLoadDef, program, 0x0);
	ASSERT_STRUCT_OFFSET(GfxPixelShaderLoadDef, programSize, 0x4);

	struct MaterialPixelShaderProgram
	{
		ID3D11PixelShader* ps; //OFS: 0x0 SIZE: 0x4
		GfxPixelShaderLoadDef loadDef; //OFS: 0x4 SIZE: 0x8
	};
	ASSERT_STRUCT_SIZE(MaterialPixelShaderProgram, 0xC);
	ASSERT_STRUCT_OFFSET(MaterialPixelShaderProgram, ps, 0x0);
	ASSERT_STRUCT_OFFSET(MaterialPixelShaderProgram, loadDef, 0x4);

	struct MaterialPixelShader
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		MaterialPixelShaderProgram prog; //OFS: 0x4 SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(MaterialPixelShader, 0x10);
	ASSERT_STRUCT_OFFSET(MaterialPixelShader, name, 0x0);
	ASSERT_STRUCT_OFFSET(MaterialPixelShader, prog, 0x4);

	union $24E88C37EAA6E3E4A54A0CEC840448B6
	{
		MaterialPixelShader* pixelShader; //OFS: 0x0 SIZE: 0x4
		MaterialPixelShader* localPixelShader; //OFS: 0x1 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE($24E88C37EAA6E3E4A54A0CEC840448B6, 0x4);

	struct __declspec(align(1)) $8514BDC4D443D0EE4E7523DDD937FABD
	{
		unsigned __int8 textureIndex; //OFS: 0x0 SIZE: 0x1
		unsigned __int8 samplerIndex; //OFS: 0x1 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE($8514BDC4D443D0EE4E7523DDD937FABD, 0x2);
	ASSERT_STRUCT_OFFSET($8514BDC4D443D0EE4E7523DDD937FABD, textureIndex, 0x0);
	ASSERT_STRUCT_OFFSET($8514BDC4D443D0EE4E7523DDD937FABD, samplerIndex, 0x1);

	union MaterialArgumentLocation
	{
		unsigned __int16 offset; //OFS: 0x0 SIZE: 0x2
		$8514BDC4D443D0EE4E7523DDD937FABD __s1; //OFS: 0x1 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(MaterialArgumentLocation, 0x2);

	struct __declspec(align(2)) MaterialArgumentCodeConst
	{
		unsigned __int16 index; //OFS: 0x0 SIZE: 0x2
		unsigned __int8 firstRow; //OFS: 0x2 SIZE: 0x1
		unsigned __int8 rowCount; //OFS: 0x3 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(MaterialArgumentCodeConst, 0x4);
	ASSERT_STRUCT_OFFSET(MaterialArgumentCodeConst, index, 0x0);
	ASSERT_STRUCT_OFFSET(MaterialArgumentCodeConst, firstRow, 0x2);
	ASSERT_STRUCT_OFFSET(MaterialArgumentCodeConst, rowCount, 0x3);

	union MaterialArgumentDef
	{
		const float* literalConst; //OFS: 0x0 SIZE: 0x4
		MaterialArgumentCodeConst codeConst; //OFS: 0x1 SIZE: 0x4
		unsigned int codeSampler; //OFS: 0x2 SIZE: 0x4
		unsigned int nameHash; //OFS: 0x3 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(MaterialArgumentDef, 0x4);

	struct MaterialShaderArgument
	{
		unsigned __int16 type; //OFS: 0x0 SIZE: 0x2
		MaterialArgumentLocation location; //OFS: 0x2 SIZE: 0x2
		unsigned __int16 size; //OFS: 0x4 SIZE: 0x2
		unsigned __int16 buffer; //OFS: 0x6 SIZE: 0x2
		MaterialArgumentDef u; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(MaterialShaderArgument, 0xC);
	ASSERT_STRUCT_OFFSET(MaterialShaderArgument, type, 0x0);
	ASSERT_STRUCT_OFFSET(MaterialShaderArgument, location, 0x2);
	ASSERT_STRUCT_OFFSET(MaterialShaderArgument, size, 0x4);
	ASSERT_STRUCT_OFFSET(MaterialShaderArgument, buffer, 0x6);
	ASSERT_STRUCT_OFFSET(MaterialShaderArgument, u, 0x8);

	union $162ABAC4BFB8E6856684E7007F87BFF1
	{
		MaterialShaderArgument* localArgs; //OFS: 0x0 SIZE: 0x4
		MaterialShaderArgument* args; //OFS: 0x1 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE($162ABAC4BFB8E6856684E7007F87BFF1, 0x4);

	struct MaterialPass
	{
		MaterialVertexDeclaration* vertexDecl; //OFS: 0x0 SIZE: 0x4
		MaterialVertexShader* vertexShader; //OFS: 0x4 SIZE: 0x4
		$24E88C37EAA6E3E4A54A0CEC840448B6 ___u2; //OFS: 0x8 SIZE: 0x4
		unsigned __int8 perPrimArgCount; //OFS: 0xC SIZE: 0x1
		unsigned __int8 perObjArgCount; //OFS: 0xD SIZE: 0x1
		unsigned __int8 stableArgCount; //OFS: 0xE SIZE: 0x1
		unsigned __int8 customSamplerFlags; //OFS: 0xF SIZE: 0x1
		unsigned __int8 precompiledIndex; //OFS: 0x10 SIZE: 0x1
		unsigned __int8 materialType; //OFS: 0x11 SIZE: 0x1
		$162ABAC4BFB8E6856684E7007F87BFF1 ___u9; //OFS: 0x14 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(MaterialPass, 0x18);
	ASSERT_STRUCT_OFFSET(MaterialPass, vertexDecl, 0x0);
	ASSERT_STRUCT_OFFSET(MaterialPass, vertexShader, 0x4);
	ASSERT_STRUCT_OFFSET(MaterialPass, ___u2, 0x8);
	ASSERT_STRUCT_OFFSET(MaterialPass, perPrimArgCount, 0xC);
	ASSERT_STRUCT_OFFSET(MaterialPass, perObjArgCount, 0xD);
	ASSERT_STRUCT_OFFSET(MaterialPass, stableArgCount, 0xE);
	ASSERT_STRUCT_OFFSET(MaterialPass, customSamplerFlags, 0xF);
	ASSERT_STRUCT_OFFSET(MaterialPass, precompiledIndex, 0x10);
	ASSERT_STRUCT_OFFSET(MaterialPass, materialType, 0x11);
	ASSERT_STRUCT_OFFSET(MaterialPass, ___u9, 0x14);

	struct MaterialTechnique
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		unsigned __int16 flags; //OFS: 0x4 SIZE: 0x2
		unsigned __int16 passCount; //OFS: 0x6 SIZE: 0x2
		MaterialPass passArray[1]; //OFS: 0x8 SIZE: 0x18
	};
	ASSERT_STRUCT_SIZE(MaterialTechnique, 0x20);
	ASSERT_STRUCT_OFFSET(MaterialTechnique, name, 0x0);
	ASSERT_STRUCT_OFFSET(MaterialTechnique, flags, 0x4);
	ASSERT_STRUCT_OFFSET(MaterialTechnique, passCount, 0x6);
	ASSERT_STRUCT_OFFSET(MaterialTechnique, passArray, 0x8);

	struct MaterialTechniqueSet
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		unsigned __int8 worldVertFormat; //OFS: 0x4 SIZE: 0x1
		MaterialTechnique* techniques[36]; //OFS: 0x8 SIZE: 0x90
	};
	ASSERT_STRUCT_SIZE(MaterialTechniqueSet, 0x98);
	ASSERT_STRUCT_OFFSET(MaterialTechniqueSet, name, 0x0);
	ASSERT_STRUCT_OFFSET(MaterialTechniqueSet, worldVertFormat, 0x4);
	ASSERT_STRUCT_OFFSET(MaterialTechniqueSet, techniques, 0x8);

	union $48B4D848C9C3366C43B07DBED1A0E547
	{
		MaterialTechniqueSet* localTechniqueSet; //OFS: 0x0 SIZE: 0x4
		MaterialTechniqueSet* techniqueSet; //OFS: 0x1 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE($48B4D848C9C3366C43B07DBED1A0E547, 0x4);

	struct GfxImageLoadDef
	{
		unsigned __int8 levelCount; //OFS: 0x0 SIZE: 0x1
		unsigned __int8 flags; //OFS: 0x1 SIZE: 0x1
		int format; //OFS: 0x4 SIZE: 0x4
		int resourceSize; //OFS: 0x8 SIZE: 0x4
		unsigned __int8 data[1]; //OFS: 0xC SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(GfxImageLoadDef, 0x10);
	ASSERT_STRUCT_OFFSET(GfxImageLoadDef, levelCount, 0x0);
	ASSERT_STRUCT_OFFSET(GfxImageLoadDef, flags, 0x1);
	ASSERT_STRUCT_OFFSET(GfxImageLoadDef, format, 0x4);
	ASSERT_STRUCT_OFFSET(GfxImageLoadDef, resourceSize, 0x8);
	ASSERT_STRUCT_OFFSET(GfxImageLoadDef, data, 0xC);

	union GfxTexture
	{
		ID3D11ShaderResourceView* basemap; //OFS: 0x0 SIZE: 0x4
		GfxImageLoadDef* loadDef; //OFS: 0x1 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxTexture, 0x4);

	struct __declspec(align(1)) Picmip
	{
		unsigned __int8 platform[2]; //OFS: 0x0 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(Picmip, 0x2);
	ASSERT_STRUCT_OFFSET(Picmip, platform, 0x0);

	struct CardMemory
	{
		int platform[2]; //OFS: 0x0 SIZE: 0x8
	};
	ASSERT_STRUCT_SIZE(CardMemory, 0x8);
	ASSERT_STRUCT_OFFSET(CardMemory, platform, 0x0);

	struct GfxStreamedPartInfo
	{
		unsigned int levelCountAndSize; //OFS: 0x0 SIZE: 0x4
		unsigned int hash; //OFS: 0x4 SIZE: 0x4
		unsigned __int16 width; //OFS: 0x8 SIZE: 0x2
		unsigned __int16 height; //OFS: 0xA SIZE: 0x2
		unsigned __int32 offset; //OFS: 0xC SIZE: 0x4
		__int32 _bf_10; //OFS: 0x10 SIZE: 0x4
		__int32 _bf_14; //OFS: 0x14 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxStreamedPartInfo, 0x18);
	ASSERT_STRUCT_OFFSET(GfxStreamedPartInfo, levelCountAndSize, 0x0);
	ASSERT_STRUCT_OFFSET(GfxStreamedPartInfo, hash, 0x4);
	ASSERT_STRUCT_OFFSET(GfxStreamedPartInfo, width, 0x8);
	ASSERT_STRUCT_OFFSET(GfxStreamedPartInfo, height, 0xA);
	ASSERT_STRUCT_OFFSET(GfxStreamedPartInfo, offset, 0xC);
	ASSERT_STRUCT_OFFSET(GfxStreamedPartInfo, _bf_10, 0x10);
	ASSERT_STRUCT_OFFSET(GfxStreamedPartInfo, _bf_14, 0x14);

	struct GfxImage
	{
		GfxTexture texture; //OFS: 0x0 SIZE: 0x4
		unsigned __int8 mapType; //OFS: 0x4 SIZE: 0x1
		unsigned __int8 semantic; //OFS: 0x5 SIZE: 0x1
		unsigned __int8 category; //OFS: 0x6 SIZE: 0x1
		bool delayLoadPixels; //OFS: 0x7 SIZE: 0x1
		Picmip picmip; //OFS: 0x8 SIZE: 0x2
		bool noPicmip; //OFS: 0xA SIZE: 0x1
		unsigned __int8 track; //OFS: 0xB SIZE: 0x1
		CardMemory cardMemory; //OFS: 0xC SIZE: 0x8
		unsigned __int16 width; //OFS: 0x14 SIZE: 0x2
		unsigned __int16 height; //OFS: 0x16 SIZE: 0x2
		unsigned __int16 depth; //OFS: 0x18 SIZE: 0x2
		unsigned __int8 levelCount; //OFS: 0x1A SIZE: 0x1
		unsigned __int8 streaming; //OFS: 0x1B SIZE: 0x1
		unsigned int baseSize; //OFS: 0x1C SIZE: 0x4
		unsigned __int8* pixels; //OFS: 0x20 SIZE: 0x4
		GfxStreamedPartInfo streamedParts[1]; //OFS: 0x24 SIZE: 0x18
		unsigned __int8 streamedPartCount; //OFS: 0x3C SIZE: 0x1
		unsigned int loadedSize; //OFS: 0x40 SIZE: 0x4
		unsigned __int8 skippedMipLevels; //OFS: 0x44 SIZE: 0x1
		const char* name; //OFS: 0x48 SIZE: 0x4
		unsigned int hash; //OFS: 0x4C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxImage, 0x50);
	ASSERT_STRUCT_OFFSET(GfxImage, texture, 0x0);
	ASSERT_STRUCT_OFFSET(GfxImage, mapType, 0x4);
	ASSERT_STRUCT_OFFSET(GfxImage, semantic, 0x5);
	ASSERT_STRUCT_OFFSET(GfxImage, category, 0x6);
	ASSERT_STRUCT_OFFSET(GfxImage, delayLoadPixels, 0x7);
	ASSERT_STRUCT_OFFSET(GfxImage, picmip, 0x8);
	ASSERT_STRUCT_OFFSET(GfxImage, noPicmip, 0xA);
	ASSERT_STRUCT_OFFSET(GfxImage, track, 0xB);
	ASSERT_STRUCT_OFFSET(GfxImage, cardMemory, 0xC);
	ASSERT_STRUCT_OFFSET(GfxImage, width, 0x14);
	ASSERT_STRUCT_OFFSET(GfxImage, height, 0x16);
	ASSERT_STRUCT_OFFSET(GfxImage, depth, 0x18);
	ASSERT_STRUCT_OFFSET(GfxImage, levelCount, 0x1A);
	ASSERT_STRUCT_OFFSET(GfxImage, streaming, 0x1B);
	ASSERT_STRUCT_OFFSET(GfxImage, baseSize, 0x1C);
	ASSERT_STRUCT_OFFSET(GfxImage, pixels, 0x20);
	ASSERT_STRUCT_OFFSET(GfxImage, streamedParts, 0x24);
	ASSERT_STRUCT_OFFSET(GfxImage, streamedPartCount, 0x3C);
	ASSERT_STRUCT_OFFSET(GfxImage, loadedSize, 0x40);
	ASSERT_STRUCT_OFFSET(GfxImage, skippedMipLevels, 0x44);
	ASSERT_STRUCT_OFFSET(GfxImage, name, 0x48);
	ASSERT_STRUCT_OFFSET(GfxImage, hash, 0x4C);

	struct MaterialTextureDef
	{
		unsigned int nameHash; //OFS: 0x0 SIZE: 0x4
		char nameStart; //OFS: 0x4 SIZE: 0x1
		char nameEnd; //OFS: 0x5 SIZE: 0x1
		unsigned __int8 samplerState; //OFS: 0x6 SIZE: 0x1
		unsigned __int8 semantic; //OFS: 0x7 SIZE: 0x1
		unsigned __int8 isMatureContent; //OFS: 0x8 SIZE: 0x1
		unsigned __int8 pad[3]; //OFS: 0x9 SIZE: 0x3
		GfxImage* image; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(MaterialTextureDef, 0x10);
	ASSERT_STRUCT_OFFSET(MaterialTextureDef, nameHash, 0x0);
	ASSERT_STRUCT_OFFSET(MaterialTextureDef, nameStart, 0x4);
	ASSERT_STRUCT_OFFSET(MaterialTextureDef, nameEnd, 0x5);
	ASSERT_STRUCT_OFFSET(MaterialTextureDef, samplerState, 0x6);
	ASSERT_STRUCT_OFFSET(MaterialTextureDef, semantic, 0x7);
	ASSERT_STRUCT_OFFSET(MaterialTextureDef, isMatureContent, 0x8);
	ASSERT_STRUCT_OFFSET(MaterialTextureDef, pad, 0x9);
	ASSERT_STRUCT_OFFSET(MaterialTextureDef, image, 0xC);

	struct MaterialConstantDef
	{
		unsigned int nameHash; //OFS: 0x0 SIZE: 0x4
		char name[12]; //OFS: 0x4 SIZE: 0xC
		vec4_t literal; //OFS: 0x10 SIZE: 0x10
	};
	ASSERT_STRUCT_SIZE(MaterialConstantDef, 0x20);
	ASSERT_STRUCT_OFFSET(MaterialConstantDef, nameHash, 0x0);
	ASSERT_STRUCT_OFFSET(MaterialConstantDef, name, 0x4);
	ASSERT_STRUCT_OFFSET(MaterialConstantDef, literal, 0x10);

	union $382B425B74EB87266E778AD0F8D67068
	{
		MaterialConstantDef* localConstantTable; //OFS: 0x0 SIZE: 0x4
		MaterialConstantDef* constantTable; //OFS: 0x1 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE($382B425B74EB87266E778AD0F8D67068, 0x4);

	struct GfxStateBits
	{
		unsigned int loadBits[2]; //OFS: 0x0 SIZE: 0x8
		ID3D11BlendState* blendState; //OFS: 0x8 SIZE: 0x4
		ID3D11DepthStencilState* depthStencilState; //OFS: 0xC SIZE: 0x4
		ID3D11RasterizerState* rasterizerState; //OFS: 0x10 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxStateBits, 0x14);
	ASSERT_STRUCT_OFFSET(GfxStateBits, loadBits, 0x0);
	ASSERT_STRUCT_OFFSET(GfxStateBits, blendState, 0x8);
	ASSERT_STRUCT_OFFSET(GfxStateBits, depthStencilState, 0xC);
	ASSERT_STRUCT_OFFSET(GfxStateBits, rasterizerState, 0x10);

	struct __declspec(align(8)) Material
	{
		MaterialInfo info; //OFS: 0x0 SIZE: 0x30
		unsigned __int8 stateBitsEntry[36]; //OFS: 0x30 SIZE: 0x24
		unsigned __int8 textureCount; //OFS: 0x54 SIZE: 0x1
		unsigned __int8 constantCount; //OFS: 0x55 SIZE: 0x1
		unsigned __int8 stateBitsCount; //OFS: 0x56 SIZE: 0x1
		unsigned __int8 stateFlags; //OFS: 0x57 SIZE: 0x1
		unsigned __int8 cameraRegion; //OFS: 0x58 SIZE: 0x1
		unsigned __int8 probeMipBits; //OFS: 0x59 SIZE: 0x1
		$48B4D848C9C3366C43B07DBED1A0E547 ___u8; //OFS: 0x5C SIZE: 0x4
		MaterialTextureDef* textureTable; //OFS: 0x60 SIZE: 0x4
		$382B425B74EB87266E778AD0F8D67068 ___u10; //OFS: 0x64 SIZE: 0x4
		GfxStateBits* stateBitsTable; //OFS: 0x68 SIZE: 0x4
		Material* thermalMaterial; //OFS: 0x6C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(Material, 0x70);
	ASSERT_STRUCT_OFFSET(Material, info, 0x0);
	ASSERT_STRUCT_OFFSET(Material, stateBitsEntry, 0x30);
	ASSERT_STRUCT_OFFSET(Material, textureCount, 0x54);
	ASSERT_STRUCT_OFFSET(Material, constantCount, 0x55);
	ASSERT_STRUCT_OFFSET(Material, stateBitsCount, 0x56);
	ASSERT_STRUCT_OFFSET(Material, stateFlags, 0x57);
	ASSERT_STRUCT_OFFSET(Material, cameraRegion, 0x58);
	ASSERT_STRUCT_OFFSET(Material, probeMipBits, 0x59);
	ASSERT_STRUCT_OFFSET(Material, ___u8, 0x5C);
	ASSERT_STRUCT_OFFSET(Material, textureTable, 0x60);
	ASSERT_STRUCT_OFFSET(Material, ___u10, 0x64);
	ASSERT_STRUCT_OFFSET(Material, stateBitsTable, 0x68);
	ASSERT_STRUCT_OFFSET(Material, thermalMaterial, 0x6C);

	struct XModelLodInfo
	{
		float dist; //OFS: 0x0 SIZE: 0x4
		unsigned __int16 numsurfs; //OFS: 0x4 SIZE: 0x2
		unsigned __int16 surfIndex; //OFS: 0x6 SIZE: 0x2
		int partBits[5]; //OFS: 0x8 SIZE: 0x14
	};
	ASSERT_STRUCT_SIZE(XModelLodInfo, 0x1C);
	ASSERT_STRUCT_OFFSET(XModelLodInfo, dist, 0x0);
	ASSERT_STRUCT_OFFSET(XModelLodInfo, numsurfs, 0x4);
	ASSERT_STRUCT_OFFSET(XModelLodInfo, surfIndex, 0x6);
	ASSERT_STRUCT_OFFSET(XModelLodInfo, partBits, 0x8);

	struct XModelCollTri_s
	{
		vec4_t plane; //OFS: 0x0 SIZE: 0x10
		vec4_t svec; //OFS: 0x10 SIZE: 0x10
		vec4_t tvec; //OFS: 0x20 SIZE: 0x10
	};
	ASSERT_STRUCT_SIZE(XModelCollTri_s, 0x30);
	ASSERT_STRUCT_OFFSET(XModelCollTri_s, plane, 0x0);
	ASSERT_STRUCT_OFFSET(XModelCollTri_s, svec, 0x10);
	ASSERT_STRUCT_OFFSET(XModelCollTri_s, tvec, 0x20);

	struct XModelCollSurf_s
	{
		XModelCollTri_s* collTris; //OFS: 0x0 SIZE: 0x4
		int numCollTris; //OFS: 0x4 SIZE: 0x4
		vec3_t mins; //OFS: 0x8 SIZE: 0xC
		vec3_t maxs; //OFS: 0x14 SIZE: 0xC
		int boneIdx; //OFS: 0x20 SIZE: 0x4
		int contents; //OFS: 0x24 SIZE: 0x4
		int surfFlags; //OFS: 0x28 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(XModelCollSurf_s, 0x2C);
	ASSERT_STRUCT_OFFSET(XModelCollSurf_s, collTris, 0x0);
	ASSERT_STRUCT_OFFSET(XModelCollSurf_s, numCollTris, 0x4);
	ASSERT_STRUCT_OFFSET(XModelCollSurf_s, mins, 0x8);
	ASSERT_STRUCT_OFFSET(XModelCollSurf_s, maxs, 0x14);
	ASSERT_STRUCT_OFFSET(XModelCollSurf_s, boneIdx, 0x20);
	ASSERT_STRUCT_OFFSET(XModelCollSurf_s, contents, 0x24);
	ASSERT_STRUCT_OFFSET(XModelCollSurf_s, surfFlags, 0x28);

	struct XBoneInfo
	{
		vec3_t bounds[2]; //OFS: 0x0 SIZE: 0x18
		vec3_t offset; //OFS: 0x18 SIZE: 0xC
		float radiusSquared; //OFS: 0x24 SIZE: 0x4
		unsigned __int8 collmap; //OFS: 0x28 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(XBoneInfo, 0x2C);
	ASSERT_STRUCT_OFFSET(XBoneInfo, bounds, 0x0);
	ASSERT_STRUCT_OFFSET(XBoneInfo, offset, 0x18);
	ASSERT_STRUCT_OFFSET(XBoneInfo, radiusSquared, 0x24);
	ASSERT_STRUCT_OFFSET(XBoneInfo, collmap, 0x28);

	union $5450EEDCAAAB8839AFD82F44179F8B0A
	{
		XBoneInfo* localBoneInfo; //OFS: 0x0 SIZE: 0x4
		XBoneInfo* boneInfo; //OFS: 0x1 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE($5450EEDCAAAB8839AFD82F44179F8B0A, 0x4);

	struct PhysPreset
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		int flags; //OFS: 0x4 SIZE: 0x4
		float mass; //OFS: 0x8 SIZE: 0x4
		float bounce; //OFS: 0xC SIZE: 0x4
		float friction; //OFS: 0x10 SIZE: 0x4
		float bulletForceScale; //OFS: 0x14 SIZE: 0x4
		float explosiveForceScale; //OFS: 0x18 SIZE: 0x4
		const char* sndAliasPrefix; //OFS: 0x1C SIZE: 0x4
		float piecesSpreadFraction; //OFS: 0x20 SIZE: 0x4
		float piecesUpwardVelocity; //OFS: 0x24 SIZE: 0x4
		int canFloat; //OFS: 0x28 SIZE: 0x4
		float gravityScale; //OFS: 0x2C SIZE: 0x4
		vec3_t centerOfMassOffset; //OFS: 0x30 SIZE: 0xC
		vec3_t buoyancyBoxMin; //OFS: 0x3C SIZE: 0xC
		vec3_t buoyancyBoxMax; //OFS: 0x48 SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(PhysPreset, 0x54);
	ASSERT_STRUCT_OFFSET(PhysPreset, name, 0x0);
	ASSERT_STRUCT_OFFSET(PhysPreset, flags, 0x4);
	ASSERT_STRUCT_OFFSET(PhysPreset, mass, 0x8);
	ASSERT_STRUCT_OFFSET(PhysPreset, bounce, 0xC);
	ASSERT_STRUCT_OFFSET(PhysPreset, friction, 0x10);
	ASSERT_STRUCT_OFFSET(PhysPreset, bulletForceScale, 0x14);
	ASSERT_STRUCT_OFFSET(PhysPreset, explosiveForceScale, 0x18);
	ASSERT_STRUCT_OFFSET(PhysPreset, sndAliasPrefix, 0x1C);
	ASSERT_STRUCT_OFFSET(PhysPreset, piecesSpreadFraction, 0x20);
	ASSERT_STRUCT_OFFSET(PhysPreset, piecesUpwardVelocity, 0x24);
	ASSERT_STRUCT_OFFSET(PhysPreset, canFloat, 0x28);
	ASSERT_STRUCT_OFFSET(PhysPreset, gravityScale, 0x2C);
	ASSERT_STRUCT_OFFSET(PhysPreset, centerOfMassOffset, 0x30);
	ASSERT_STRUCT_OFFSET(PhysPreset, buoyancyBoxMin, 0x3C);
	ASSERT_STRUCT_OFFSET(PhysPreset, buoyancyBoxMax, 0x48);

	struct cplane_s
	{
		vec3_t normal; //OFS: 0x0 SIZE: 0xC
		float dist; //OFS: 0xC SIZE: 0x4
		unsigned __int8 type; //OFS: 0x10 SIZE: 0x1
		unsigned __int8 signbits; //OFS: 0x11 SIZE: 0x1
		unsigned __int8 pad[2]; //OFS: 0x12 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(cplane_s, 0x14);
	ASSERT_STRUCT_OFFSET(cplane_s, normal, 0x0);
	ASSERT_STRUCT_OFFSET(cplane_s, dist, 0xC);
	ASSERT_STRUCT_OFFSET(cplane_s, type, 0x10);
	ASSERT_STRUCT_OFFSET(cplane_s, signbits, 0x11);
	ASSERT_STRUCT_OFFSET(cplane_s, pad, 0x12);

	struct cbrushside_t
	{
		cplane_s* plane; //OFS: 0x0 SIZE: 0x4
		int cflags; //OFS: 0x4 SIZE: 0x4
		int sflags; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(cbrushside_t, 0xC);
	ASSERT_STRUCT_OFFSET(cbrushside_t, plane, 0x0);
	ASSERT_STRUCT_OFFSET(cbrushside_t, cflags, 0x4);
	ASSERT_STRUCT_OFFSET(cbrushside_t, sflags, 0x8);

	struct BrushWrapper
	{
		vec3_t mins; //OFS: 0x0 SIZE: 0xC
		int contents; //OFS: 0xC SIZE: 0x4
		vec3_t maxs; //OFS: 0x10 SIZE: 0xC
		unsigned int numsides; //OFS: 0x1C SIZE: 0x4
		cbrushside_t* sides; //OFS: 0x20 SIZE: 0x4
		int axial_cflags[2][3]; //OFS: 0x24 SIZE: 0x18
		int axial_sflags[2][3]; //OFS: 0x3C SIZE: 0x18
		unsigned int numverts; //OFS: 0x54 SIZE: 0x4
		vec3_t* verts; //OFS: 0x58 SIZE: 0x4
		cplane_s* planes; //OFS: 0x5C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(BrushWrapper, 0x60);
	ASSERT_STRUCT_OFFSET(BrushWrapper, mins, 0x0);
	ASSERT_STRUCT_OFFSET(BrushWrapper, contents, 0xC);
	ASSERT_STRUCT_OFFSET(BrushWrapper, maxs, 0x10);
	ASSERT_STRUCT_OFFSET(BrushWrapper, numsides, 0x1C);
	ASSERT_STRUCT_OFFSET(BrushWrapper, sides, 0x20);
	ASSERT_STRUCT_OFFSET(BrushWrapper, axial_cflags, 0x24);
	ASSERT_STRUCT_OFFSET(BrushWrapper, axial_sflags, 0x3C);
	ASSERT_STRUCT_OFFSET(BrushWrapper, numverts, 0x54);
	ASSERT_STRUCT_OFFSET(BrushWrapper, verts, 0x58);
	ASSERT_STRUCT_OFFSET(BrushWrapper, planes, 0x5C);

	struct PhysGeomInfo
	{
		BrushWrapper* brush; //OFS: 0x0 SIZE: 0x4
		int type; //OFS: 0x4 SIZE: 0x4
		vec3_t orientation[3]; //OFS: 0x8 SIZE: 0x24
		vec3_t offset; //OFS: 0x2C SIZE: 0xC
		vec3_t halfLengths; //OFS: 0x38 SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(PhysGeomInfo, 0x44);
	ASSERT_STRUCT_OFFSET(PhysGeomInfo, brush, 0x0);
	ASSERT_STRUCT_OFFSET(PhysGeomInfo, type, 0x4);
	ASSERT_STRUCT_OFFSET(PhysGeomInfo, orientation, 0x8);
	ASSERT_STRUCT_OFFSET(PhysGeomInfo, offset, 0x2C);
	ASSERT_STRUCT_OFFSET(PhysGeomInfo, halfLengths, 0x38);

	struct PhysGeomList
	{
		unsigned int count; //OFS: 0x0 SIZE: 0x4
		PhysGeomInfo* geoms; //OFS: 0x4 SIZE: 0x4
		int contents; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(PhysGeomList, 0xC);
	ASSERT_STRUCT_OFFSET(PhysGeomList, count, 0x0);
	ASSERT_STRUCT_OFFSET(PhysGeomList, geoms, 0x4);
	ASSERT_STRUCT_OFFSET(PhysGeomList, contents, 0x8);

	struct Collmap
	{
		PhysGeomList* geomList; //OFS: 0x0 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(Collmap, 0x4);
	ASSERT_STRUCT_OFFSET(Collmap, geomList, 0x0);

	struct PhysConstraint
	{
		unsigned __int16 targetname; //OFS: 0x0 SIZE: 0x2
		ConstraintType type; //OFS: 0x4 SIZE: 0x4
		AttachPointType attach_point_type1; //OFS: 0x8 SIZE: 0x4
		int target_index1; //OFS: 0xC SIZE: 0x4
		unsigned __int16 target_ent1; //OFS: 0x10 SIZE: 0x2
		const char* target_bone1; //OFS: 0x14 SIZE: 0x4
		AttachPointType attach_point_type2; //OFS: 0x18 SIZE: 0x4
		int target_index2; //OFS: 0x1C SIZE: 0x4
		unsigned __int16 target_ent2; //OFS: 0x20 SIZE: 0x2
		const char* target_bone2; //OFS: 0x24 SIZE: 0x4
		vec3_t offset; //OFS: 0x28 SIZE: 0xC
		vec3_t pos; //OFS: 0x34 SIZE: 0xC
		vec3_t pos2; //OFS: 0x40 SIZE: 0xC
		vec3_t dir; //OFS: 0x4C SIZE: 0xC
		int flags; //OFS: 0x58 SIZE: 0x4
		int timeout; //OFS: 0x5C SIZE: 0x4
		int min_health; //OFS: 0x60 SIZE: 0x4
		int max_health; //OFS: 0x64 SIZE: 0x4
		float distance; //OFS: 0x68 SIZE: 0x4
		float damp; //OFS: 0x6C SIZE: 0x4
		float power; //OFS: 0x70 SIZE: 0x4
		vec3_t scale; //OFS: 0x74 SIZE: 0xC
		float spin_scale; //OFS: 0x80 SIZE: 0x4
		float minAngle; //OFS: 0x84 SIZE: 0x4
		float maxAngle; //OFS: 0x88 SIZE: 0x4
		Material* material; //OFS: 0x8C SIZE: 0x4
		int constraintHandle; //OFS: 0x90 SIZE: 0x4
		int rope_index; //OFS: 0x94 SIZE: 0x4
		int centity_num[4]; //OFS: 0x98 SIZE: 0x10
	};
	ASSERT_STRUCT_SIZE(PhysConstraint, 0xA8);
	ASSERT_STRUCT_OFFSET(PhysConstraint, targetname, 0x0);
	ASSERT_STRUCT_OFFSET(PhysConstraint, type, 0x4);
	ASSERT_STRUCT_OFFSET(PhysConstraint, attach_point_type1, 0x8);
	ASSERT_STRUCT_OFFSET(PhysConstraint, target_index1, 0xC);
	ASSERT_STRUCT_OFFSET(PhysConstraint, target_ent1, 0x10);
	ASSERT_STRUCT_OFFSET(PhysConstraint, target_bone1, 0x14);
	ASSERT_STRUCT_OFFSET(PhysConstraint, attach_point_type2, 0x18);
	ASSERT_STRUCT_OFFSET(PhysConstraint, target_index2, 0x1C);
	ASSERT_STRUCT_OFFSET(PhysConstraint, target_ent2, 0x20);
	ASSERT_STRUCT_OFFSET(PhysConstraint, target_bone2, 0x24);
	ASSERT_STRUCT_OFFSET(PhysConstraint, offset, 0x28);
	ASSERT_STRUCT_OFFSET(PhysConstraint, pos, 0x34);
	ASSERT_STRUCT_OFFSET(PhysConstraint, pos2, 0x40);
	ASSERT_STRUCT_OFFSET(PhysConstraint, dir, 0x4C);
	ASSERT_STRUCT_OFFSET(PhysConstraint, flags, 0x58);
	ASSERT_STRUCT_OFFSET(PhysConstraint, timeout, 0x5C);
	ASSERT_STRUCT_OFFSET(PhysConstraint, min_health, 0x60);
	ASSERT_STRUCT_OFFSET(PhysConstraint, max_health, 0x64);
	ASSERT_STRUCT_OFFSET(PhysConstraint, distance, 0x68);
	ASSERT_STRUCT_OFFSET(PhysConstraint, damp, 0x6C);
	ASSERT_STRUCT_OFFSET(PhysConstraint, power, 0x70);
	ASSERT_STRUCT_OFFSET(PhysConstraint, scale, 0x74);
	ASSERT_STRUCT_OFFSET(PhysConstraint, spin_scale, 0x80);
	ASSERT_STRUCT_OFFSET(PhysConstraint, minAngle, 0x84);
	ASSERT_STRUCT_OFFSET(PhysConstraint, maxAngle, 0x88);
	ASSERT_STRUCT_OFFSET(PhysConstraint, material, 0x8C);
	ASSERT_STRUCT_OFFSET(PhysConstraint, constraintHandle, 0x90);
	ASSERT_STRUCT_OFFSET(PhysConstraint, rope_index, 0x94);
	ASSERT_STRUCT_OFFSET(PhysConstraint, centity_num, 0x98);

	struct PhysConstraints
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		unsigned int count; //OFS: 0x4 SIZE: 0x4
		PhysConstraint data[16]; //OFS: 0x8 SIZE: 0xA80
	};
	ASSERT_STRUCT_SIZE(PhysConstraints, 0xA88);
	ASSERT_STRUCT_OFFSET(PhysConstraints, name, 0x0);
	ASSERT_STRUCT_OFFSET(PhysConstraints, count, 0x4);
	ASSERT_STRUCT_OFFSET(PhysConstraints, data, 0x8);

	struct XModel
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		unsigned __int8 numBones; //OFS: 0x4 SIZE: 0x1
		unsigned __int8 numRootBones; //OFS: 0x5 SIZE: 0x1
		unsigned __int8 numsurfs; //OFS: 0x6 SIZE: 0x1
		unsigned __int8 lodRampType; //OFS: 0x7 SIZE: 0x1
		$C8C573B57ACA1D7542AD56C4163862EC ___u5; //OFS: 0x8 SIZE: 0x4
		$37E13A30061EC97EDA76440B3BA5E97A ___u6; //OFS: 0xC SIZE: 0x4
		$BF9640C0B3AB5E078C286DD9616EC22F ___u7; //OFS: 0x10 SIZE: 0x4
		$E1CD6A013C1D28F2956F4983A8D1052C ___u8; //OFS: 0x14 SIZE: 0x4
		unsigned __int8* partClassification; //OFS: 0x18 SIZE: 0x4
		DObjAnimMat* baseMat; //OFS: 0x1C SIZE: 0x4
		XSurface* surfs; //OFS: 0x20 SIZE: 0x4
		Material** materialHandles; //OFS: 0x24 SIZE: 0x4
		XModelLodInfo lodInfo[4]; //OFS: 0x28 SIZE: 0x70
		XModelCollSurf_s* collSurfs; //OFS: 0x98 SIZE: 0x4
		int numCollSurfs; //OFS: 0x9C SIZE: 0x4
		int contents; //OFS: 0xA0 SIZE: 0x4
		$5450EEDCAAAB8839AFD82F44179F8B0A ___u17; //OFS: 0xA4 SIZE: 0x4
		float radius; //OFS: 0xA8 SIZE: 0x4
		vec3_t mins; //OFS: 0xAC SIZE: 0xC
		vec3_t maxs; //OFS: 0xB8 SIZE: 0xC
		__int16 numLods; //OFS: 0xC4 SIZE: 0x2
		__int16 collLod; //OFS: 0xC6 SIZE: 0x2
		float* himipInvSqRadii; //OFS: 0xC8 SIZE: 0x4
		int memUsage; //OFS: 0xCC SIZE: 0x4
		int flags; //OFS: 0xD0 SIZE: 0x4
		bool bad; //OFS: 0xD4 SIZE: 0x1
		PhysPreset* physPreset; //OFS: 0xD8 SIZE: 0x4
		unsigned __int8 numCollmaps; //OFS: 0xDC SIZE: 0x1
		Collmap* collmaps; //OFS: 0xE0 SIZE: 0x4
		PhysConstraints* physConstraints; //OFS: 0xE4 SIZE: 0x4
		vec3_t lightingOriginOffset; //OFS: 0xE8 SIZE: 0xC
		float lightingOriginRange; //OFS: 0xF4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(XModel, 0xF8);
	ASSERT_STRUCT_OFFSET(XModel, name, 0x0);
	ASSERT_STRUCT_OFFSET(XModel, numBones, 0x4);
	ASSERT_STRUCT_OFFSET(XModel, numRootBones, 0x5);
	ASSERT_STRUCT_OFFSET(XModel, numsurfs, 0x6);
	ASSERT_STRUCT_OFFSET(XModel, lodRampType, 0x7);
	ASSERT_STRUCT_OFFSET(XModel, ___u5, 0x8);
	ASSERT_STRUCT_OFFSET(XModel, ___u6, 0xC);
	ASSERT_STRUCT_OFFSET(XModel, ___u7, 0x10);
	ASSERT_STRUCT_OFFSET(XModel, ___u8, 0x14);
	ASSERT_STRUCT_OFFSET(XModel, partClassification, 0x18);
	ASSERT_STRUCT_OFFSET(XModel, baseMat, 0x1C);
	ASSERT_STRUCT_OFFSET(XModel, surfs, 0x20);
	ASSERT_STRUCT_OFFSET(XModel, materialHandles, 0x24);
	ASSERT_STRUCT_OFFSET(XModel, lodInfo, 0x28);
	ASSERT_STRUCT_OFFSET(XModel, collSurfs, 0x98);
	ASSERT_STRUCT_OFFSET(XModel, numCollSurfs, 0x9C);
	ASSERT_STRUCT_OFFSET(XModel, contents, 0xA0);
	ASSERT_STRUCT_OFFSET(XModel, ___u17, 0xA4);
	ASSERT_STRUCT_OFFSET(XModel, radius, 0xA8);
	ASSERT_STRUCT_OFFSET(XModel, mins, 0xAC);
	ASSERT_STRUCT_OFFSET(XModel, maxs, 0xB8);
	ASSERT_STRUCT_OFFSET(XModel, numLods, 0xC4);
	ASSERT_STRUCT_OFFSET(XModel, collLod, 0xC6);
	ASSERT_STRUCT_OFFSET(XModel, himipInvSqRadii, 0xC8);
	ASSERT_STRUCT_OFFSET(XModel, memUsage, 0xCC);
	ASSERT_STRUCT_OFFSET(XModel, flags, 0xD0);
	ASSERT_STRUCT_OFFSET(XModel, bad, 0xD4);
	ASSERT_STRUCT_OFFSET(XModel, physPreset, 0xD8);
	ASSERT_STRUCT_OFFSET(XModel, numCollmaps, 0xDC);
	ASSERT_STRUCT_OFFSET(XModel, collmaps, 0xE0);
	ASSERT_STRUCT_OFFSET(XModel, physConstraints, 0xE4);
	ASSERT_STRUCT_OFFSET(XModel, lightingOriginOffset, 0xE8);
	ASSERT_STRUCT_OFFSET(XModel, lightingOriginRange, 0xF4);

	struct XModelPiece
	{
		XModel* model; //OFS: 0x0 SIZE: 0x4
		vec3_t offset; //OFS: 0x4 SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(XModelPiece, 0x10);
	ASSERT_STRUCT_OFFSET(XModelPiece, model, 0x0);
	ASSERT_STRUCT_OFFSET(XModelPiece, offset, 0x4);

	struct XModelPieces
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		int numpieces; //OFS: 0x4 SIZE: 0x4
		XModelPiece* pieces; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(XModelPieces, 0xC);
	ASSERT_STRUCT_OFFSET(XModelPieces, name, 0x0);
	ASSERT_STRUCT_OFFSET(XModelPieces, numpieces, 0x4);
	ASSERT_STRUCT_OFFSET(XModelPieces, pieces, 0x8);

	struct DestructibleStage
	{
		unsigned __int16 showBone; //OFS: 0x0 SIZE: 0x2
		float breakHealth; //OFS: 0x4 SIZE: 0x4
		float maxTime; //OFS: 0x8 SIZE: 0x4
		unsigned int flags; //OFS: 0xC SIZE: 0x4
		const FxEffectDef* breakEffect; //OFS: 0x10 SIZE: 0x4
		const char* breakSound; //OFS: 0x14 SIZE: 0x4
		const char* breakNotify; //OFS: 0x18 SIZE: 0x4
		const char* loopSound; //OFS: 0x1C SIZE: 0x4
		XModel* spawnModel[3]; //OFS: 0x20 SIZE: 0xC
		PhysPreset* physPreset; //OFS: 0x2C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(DestructibleStage, 0x30);
	ASSERT_STRUCT_OFFSET(DestructibleStage, showBone, 0x0);
	ASSERT_STRUCT_OFFSET(DestructibleStage, breakHealth, 0x4);
	ASSERT_STRUCT_OFFSET(DestructibleStage, maxTime, 0x8);
	ASSERT_STRUCT_OFFSET(DestructibleStage, flags, 0xC);
	ASSERT_STRUCT_OFFSET(DestructibleStage, breakEffect, 0x10);
	ASSERT_STRUCT_OFFSET(DestructibleStage, breakSound, 0x14);
	ASSERT_STRUCT_OFFSET(DestructibleStage, breakNotify, 0x18);
	ASSERT_STRUCT_OFFSET(DestructibleStage, loopSound, 0x1C);
	ASSERT_STRUCT_OFFSET(DestructibleStage, spawnModel, 0x20);
	ASSERT_STRUCT_OFFSET(DestructibleStage, physPreset, 0x2C);

	struct DestructiblePiece
	{
		DestructibleStage stages[5]; //OFS: 0x0 SIZE: 0xF0
		unsigned __int8 parentPiece; //OFS: 0xF0 SIZE: 0x1
		float parentDamagePercent; //OFS: 0xF4 SIZE: 0x4
		float bulletDamageScale; //OFS: 0xF8 SIZE: 0x4
		float explosiveDamageScale; //OFS: 0xFC SIZE: 0x4
		float meleeDamageScale; //OFS: 0x100 SIZE: 0x4
		float impactDamageScale; //OFS: 0x104 SIZE: 0x4
		float entityDamageTransfer; //OFS: 0x108 SIZE: 0x4
		PhysConstraints* physConstraints; //OFS: 0x10C SIZE: 0x4
		int health; //OFS: 0x110 SIZE: 0x4
		const char* damageSound; //OFS: 0x114 SIZE: 0x4
		const FxEffectDef* burnEffect; //OFS: 0x118 SIZE: 0x4
		const char* burnSound; //OFS: 0x11C SIZE: 0x4
		unsigned __int16 enableLabel; //OFS: 0x120 SIZE: 0x2
		int hideBones[5]; //OFS: 0x124 SIZE: 0x14
	};
	ASSERT_STRUCT_SIZE(DestructiblePiece, 0x138);
	ASSERT_STRUCT_OFFSET(DestructiblePiece, stages, 0x0);
	ASSERT_STRUCT_OFFSET(DestructiblePiece, parentPiece, 0xF0);
	ASSERT_STRUCT_OFFSET(DestructiblePiece, parentDamagePercent, 0xF4);
	ASSERT_STRUCT_OFFSET(DestructiblePiece, bulletDamageScale, 0xF8);
	ASSERT_STRUCT_OFFSET(DestructiblePiece, explosiveDamageScale, 0xFC);
	ASSERT_STRUCT_OFFSET(DestructiblePiece, meleeDamageScale, 0x100);
	ASSERT_STRUCT_OFFSET(DestructiblePiece, impactDamageScale, 0x104);
	ASSERT_STRUCT_OFFSET(DestructiblePiece, entityDamageTransfer, 0x108);
	ASSERT_STRUCT_OFFSET(DestructiblePiece, physConstraints, 0x10C);
	ASSERT_STRUCT_OFFSET(DestructiblePiece, health, 0x110);
	ASSERT_STRUCT_OFFSET(DestructiblePiece, damageSound, 0x114);
	ASSERT_STRUCT_OFFSET(DestructiblePiece, burnEffect, 0x118);
	ASSERT_STRUCT_OFFSET(DestructiblePiece, burnSound, 0x11C);
	ASSERT_STRUCT_OFFSET(DestructiblePiece, enableLabel, 0x120);
	ASSERT_STRUCT_OFFSET(DestructiblePiece, hideBones, 0x124);

	struct DestructibleDef
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		XModel* model; //OFS: 0x4 SIZE: 0x4
		XModel* pristineModel; //OFS: 0x8 SIZE: 0x4
		int numPieces; //OFS: 0xC SIZE: 0x4
		DestructiblePiece* pieces; //OFS: 0x10 SIZE: 0x4
		int clientOnly; //OFS: 0x14 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(DestructibleDef, 0x18);
	ASSERT_STRUCT_OFFSET(DestructibleDef, name, 0x0);
	ASSERT_STRUCT_OFFSET(DestructibleDef, model, 0x4);
	ASSERT_STRUCT_OFFSET(DestructibleDef, pristineModel, 0x8);
	ASSERT_STRUCT_OFFSET(DestructibleDef, numPieces, 0xC);
	ASSERT_STRUCT_OFFSET(DestructibleDef, pieces, 0x10);
	ASSERT_STRUCT_OFFSET(DestructibleDef, clientOnly, 0x14);

	union XAnimIndices
	{
		unsigned __int8* _1; //OFS: 0x0 SIZE: 0x4
		unsigned __int16* _2; //OFS: 0x1 SIZE: 0x4
		void* data; //OFS: 0x2 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(XAnimIndices, 0x4);

	struct XAnimNotifyInfo
	{
		unsigned __int16 name; //OFS: 0x0 SIZE: 0x2
		float time; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(XAnimNotifyInfo, 0x8);
	ASSERT_STRUCT_OFFSET(XAnimNotifyInfo, name, 0x0);
	ASSERT_STRUCT_OFFSET(XAnimNotifyInfo, time, 0x4);

	union XAnimDynamicFrames
	{
		unsigned __int8(*_1) [3]; //OFS: 0x0 SIZE: 0x4
		unsigned __int16(*_2) [3]; //OFS: 0x1 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(XAnimDynamicFrames, 0x4);

	union XAnimDynamicIndices
	{
		unsigned __int8 _1[1]; //OFS: 0x0 SIZE: 0x1
		unsigned __int16 _2[1]; //OFS: 0x1 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(XAnimDynamicIndices, 0x2);

	struct XAnimPartTransFrames
	{
		vec3_t mins; //OFS: 0x0 SIZE: 0xC
		vec3_t size; //OFS: 0xC SIZE: 0xC
		XAnimDynamicFrames frames; //OFS: 0x18 SIZE: 0x4
		XAnimDynamicIndices indices; //OFS: 0x1C SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(XAnimPartTransFrames, 0x20);
	ASSERT_STRUCT_OFFSET(XAnimPartTransFrames, mins, 0x0);
	ASSERT_STRUCT_OFFSET(XAnimPartTransFrames, size, 0xC);
	ASSERT_STRUCT_OFFSET(XAnimPartTransFrames, frames, 0x18);
	ASSERT_STRUCT_OFFSET(XAnimPartTransFrames, indices, 0x1C);

	union XAnimPartTransData
	{
		XAnimPartTransFrames frames; //OFS: 0x0 SIZE: 0x20
		vec3_t frame0; //OFS: 0x1 SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(XAnimPartTransData, 0x20);

	struct XAnimPartTrans
	{
		unsigned __int16 size; //OFS: 0x0 SIZE: 0x2
		unsigned __int8 smallTrans; //OFS: 0x2 SIZE: 0x1
		XAnimPartTransData u; //OFS: 0x4 SIZE: 0x20
	};
	ASSERT_STRUCT_SIZE(XAnimPartTrans, 0x24);
	ASSERT_STRUCT_OFFSET(XAnimPartTrans, size, 0x0);
	ASSERT_STRUCT_OFFSET(XAnimPartTrans, smallTrans, 0x2);
	ASSERT_STRUCT_OFFSET(XAnimPartTrans, u, 0x4);

	struct XAnimDeltaPartQuatDataFrames2
	{
		__int16(*frames) [2]; //OFS: 0x0 SIZE: 0x4
		XAnimDynamicIndices indices; //OFS: 0x4 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(XAnimDeltaPartQuatDataFrames2, 0x8);
	ASSERT_STRUCT_OFFSET(XAnimDeltaPartQuatDataFrames2, frames, 0x0);
	ASSERT_STRUCT_OFFSET(XAnimDeltaPartQuatDataFrames2, indices, 0x4);

	union XAnimDeltaPartQuatData2
	{
		XAnimDeltaPartQuatDataFrames2 frames; //OFS: 0x0 SIZE: 0x8
		__int16 frame0[2]; //OFS: 0x1 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(XAnimDeltaPartQuatData2, 0x8);

	struct XAnimDeltaPartQuat2
	{
		unsigned __int16 size; //OFS: 0x0 SIZE: 0x2
		XAnimDeltaPartQuatData2 u; //OFS: 0x4 SIZE: 0x8
	};
	ASSERT_STRUCT_SIZE(XAnimDeltaPartQuat2, 0xC);
	ASSERT_STRUCT_OFFSET(XAnimDeltaPartQuat2, size, 0x0);
	ASSERT_STRUCT_OFFSET(XAnimDeltaPartQuat2, u, 0x4);

	struct XAnimDeltaPartQuatDataFrames
	{
		__int16(*frames)[4]; //OFS: 0x0 SIZE: 0x4
		XAnimDynamicIndices indices; //OFS: 0x4 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(XAnimDeltaPartQuatDataFrames, 0x8);
	ASSERT_STRUCT_OFFSET(XAnimDeltaPartQuatDataFrames, frames, 0x0);
	ASSERT_STRUCT_OFFSET(XAnimDeltaPartQuatDataFrames, indices, 0x4);

	union XAnimDeltaPartQuatData
	{
		XAnimDeltaPartQuatDataFrames frames; //OFS: 0x0 SIZE: 0x8
		__int16 frame0[4]; //OFS: 0x1 SIZE: 0x8
	};
	ASSERT_STRUCT_SIZE(XAnimDeltaPartQuatData, 0x8);

	struct XAnimDeltaPartQuat
	{
		unsigned __int16 size; //OFS: 0x0 SIZE: 0x2
		XAnimDeltaPartQuatData u; //OFS: 0x4 SIZE: 0x8
	};
	ASSERT_STRUCT_SIZE(XAnimDeltaPartQuat, 0xC);
	ASSERT_STRUCT_OFFSET(XAnimDeltaPartQuat, size, 0x0);
	ASSERT_STRUCT_OFFSET(XAnimDeltaPartQuat, u, 0x4);

	struct XAnimDeltaPart
	{
		XAnimPartTrans* trans; //OFS: 0x0 SIZE: 0x4
		XAnimDeltaPartQuat2* quat2; //OFS: 0x4 SIZE: 0x4
		XAnimDeltaPartQuat* quat; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(XAnimDeltaPart, 0xC);
	ASSERT_STRUCT_OFFSET(XAnimDeltaPart, trans, 0x0);
	ASSERT_STRUCT_OFFSET(XAnimDeltaPart, quat2, 0x4);
	ASSERT_STRUCT_OFFSET(XAnimDeltaPart, quat, 0x8);

	struct XAnimParts
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		unsigned __int16 dataByteCount; //OFS: 0x4 SIZE: 0x2
		unsigned __int16 dataShortCount; //OFS: 0x6 SIZE: 0x2
		unsigned __int16 dataIntCount; //OFS: 0x8 SIZE: 0x2
		unsigned __int16 randomDataByteCount; //OFS: 0xA SIZE: 0x2
		unsigned __int16 randomDataIntCount; //OFS: 0xC SIZE: 0x2
		unsigned __int16 numframes; //OFS: 0xE SIZE: 0x2
		bool bLoop; //OFS: 0x10 SIZE: 0x1
		bool bDelta; //OFS: 0x11 SIZE: 0x1
		bool bDelta3D; //OFS: 0x12 SIZE: 0x1
		bool bLeftHandGripIK; //OFS: 0x13 SIZE: 0x1
		unsigned int streamedFileSize; //OFS: 0x14 SIZE: 0x4
		unsigned __int8 boneCount[10]; //OFS: 0x18 SIZE: 0xA
		unsigned __int8 notifyCount; //OFS: 0x22 SIZE: 0x1
		unsigned __int8 assetType; //OFS: 0x23 SIZE: 0x1
		bool isDefault; //OFS: 0x24 SIZE: 0x1
		unsigned int randomDataShortCount; //OFS: 0x28 SIZE: 0x4
		unsigned int indexCount; //OFS: 0x2C SIZE: 0x4
		float framerate; //OFS: 0x30 SIZE: 0x4
		float frequency; //OFS: 0x34 SIZE: 0x4
		float primedLength; //OFS: 0x38 SIZE: 0x4
		float loopEntryTime; //OFS: 0x3C SIZE: 0x4
		unsigned __int16* names; //OFS: 0x40 SIZE: 0x4
		unsigned __int8* dataByte; //OFS: 0x44 SIZE: 0x4
		__int16* dataShort; //OFS: 0x48 SIZE: 0x4
		int* dataInt; //OFS: 0x4C SIZE: 0x4
		__int16* randomDataShort; //OFS: 0x50 SIZE: 0x4
		unsigned __int8* randomDataByte; //OFS: 0x54 SIZE: 0x4
		int* randomDataInt; //OFS: 0x58 SIZE: 0x4
		XAnimIndices indices; //OFS: 0x5C SIZE: 0x4
		XAnimNotifyInfo* notify; //OFS: 0x60 SIZE: 0x4
		XAnimDeltaPart* deltaPart; //OFS: 0x64 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(XAnimParts, 0x68);
	ASSERT_STRUCT_OFFSET(XAnimParts, name, 0x0);
	ASSERT_STRUCT_OFFSET(XAnimParts, dataByteCount, 0x4);
	ASSERT_STRUCT_OFFSET(XAnimParts, dataShortCount, 0x6);
	ASSERT_STRUCT_OFFSET(XAnimParts, dataIntCount, 0x8);
	ASSERT_STRUCT_OFFSET(XAnimParts, randomDataByteCount, 0xA);
	ASSERT_STRUCT_OFFSET(XAnimParts, randomDataIntCount, 0xC);
	ASSERT_STRUCT_OFFSET(XAnimParts, numframes, 0xE);
	ASSERT_STRUCT_OFFSET(XAnimParts, bLoop, 0x10);
	ASSERT_STRUCT_OFFSET(XAnimParts, bDelta, 0x11);
	ASSERT_STRUCT_OFFSET(XAnimParts, bDelta3D, 0x12);
	ASSERT_STRUCT_OFFSET(XAnimParts, bLeftHandGripIK, 0x13);
	ASSERT_STRUCT_OFFSET(XAnimParts, streamedFileSize, 0x14);
	ASSERT_STRUCT_OFFSET(XAnimParts, boneCount, 0x18);
	ASSERT_STRUCT_OFFSET(XAnimParts, notifyCount, 0x22);
	ASSERT_STRUCT_OFFSET(XAnimParts, assetType, 0x23);
	ASSERT_STRUCT_OFFSET(XAnimParts, isDefault, 0x24);
	ASSERT_STRUCT_OFFSET(XAnimParts, randomDataShortCount, 0x28);
	ASSERT_STRUCT_OFFSET(XAnimParts, indexCount, 0x2C);
	ASSERT_STRUCT_OFFSET(XAnimParts, framerate, 0x30);
	ASSERT_STRUCT_OFFSET(XAnimParts, frequency, 0x34);
	ASSERT_STRUCT_OFFSET(XAnimParts, primedLength, 0x38);
	ASSERT_STRUCT_OFFSET(XAnimParts, loopEntryTime, 0x3C);
	ASSERT_STRUCT_OFFSET(XAnimParts, names, 0x40);
	ASSERT_STRUCT_OFFSET(XAnimParts, dataByte, 0x44);
	ASSERT_STRUCT_OFFSET(XAnimParts, dataShort, 0x48);
	ASSERT_STRUCT_OFFSET(XAnimParts, dataInt, 0x4C);
	ASSERT_STRUCT_OFFSET(XAnimParts, randomDataShort, 0x50);
	ASSERT_STRUCT_OFFSET(XAnimParts, randomDataByte, 0x54);
	ASSERT_STRUCT_OFFSET(XAnimParts, randomDataInt, 0x58);
	ASSERT_STRUCT_OFFSET(XAnimParts, indices, 0x5C);
	ASSERT_STRUCT_OFFSET(XAnimParts, notify, 0x60);
	ASSERT_STRUCT_OFFSET(XAnimParts, deltaPart, 0x64);

	struct SndAlias
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		unsigned int id; //OFS: 0x4 SIZE: 0x4
		const char* subtitle; //OFS: 0x8 SIZE: 0x4
		const char* secondaryname; //OFS: 0xC SIZE: 0x4
		unsigned int assetId; //OFS: 0x10 SIZE: 0x4
		const char* assetFileName; //OFS: 0x14 SIZE: 0x4
		unsigned int flags0; //OFS: 0x18 SIZE: 0x4
		unsigned int flags1; //OFS: 0x1C SIZE: 0x4
		unsigned int duck; //OFS: 0x20 SIZE: 0x4
		unsigned int contextType; //OFS: 0x24 SIZE: 0x4
		unsigned int contextValue; //OFS: 0x28 SIZE: 0x4
		unsigned int stopOnPlay; //OFS: 0x2C SIZE: 0x4
		unsigned int futzPatch; //OFS: 0x30 SIZE: 0x4
		unsigned __int16 fluxTime; //OFS: 0x34 SIZE: 0x2
		unsigned __int16 startDelay; //OFS: 0x36 SIZE: 0x2
		unsigned __int16 reverbSend; //OFS: 0x38 SIZE: 0x2
		unsigned __int16 centerSend; //OFS: 0x3A SIZE: 0x2
		unsigned __int16 volMin; //OFS: 0x3C SIZE: 0x2
		unsigned __int16 volMax; //OFS: 0x3E SIZE: 0x2
		unsigned __int16 pitchMin; //OFS: 0x40 SIZE: 0x2
		unsigned __int16 pitchMax; //OFS: 0x42 SIZE: 0x2
		unsigned __int16 distMin; //OFS: 0x44 SIZE: 0x2
		unsigned __int16 distMax; //OFS: 0x46 SIZE: 0x2
		unsigned __int16 distReverbMax; //OFS: 0x48 SIZE: 0x2
		unsigned __int16 envelopMin; //OFS: 0x4A SIZE: 0x2
		unsigned __int16 envelopMax; //OFS: 0x4C SIZE: 0x2
		unsigned __int16 envelopPercentage; //OFS: 0x4E SIZE: 0x2
		__int16 fadeIn; //OFS: 0x50 SIZE: 0x2
		__int16 fadeOut; //OFS: 0x52 SIZE: 0x2
		__int16 dopplerScale; //OFS: 0x54 SIZE: 0x2
		unsigned __int8 minPriorityThreshold; //OFS: 0x56 SIZE: 0x1
		unsigned __int8 maxPriorityThreshold; //OFS: 0x57 SIZE: 0x1
		unsigned __int8 probability; //OFS: 0x58 SIZE: 0x1
		unsigned __int8 occlusionLevel; //OFS: 0x59 SIZE: 0x1
		unsigned __int8 minPriority; //OFS: 0x5A SIZE: 0x1
		unsigned __int8 maxPriority; //OFS: 0x5B SIZE: 0x1
		unsigned __int8 pan; //OFS: 0x5C SIZE: 0x1
		unsigned __int8 limitCount; //OFS: 0x5D SIZE: 0x1
		unsigned __int8 entityLimitCount; //OFS: 0x5E SIZE: 0x1
		unsigned __int8 duckGroup; //OFS: 0x5F SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(SndAlias, 0x60);
	ASSERT_STRUCT_OFFSET(SndAlias, name, 0x0);
	ASSERT_STRUCT_OFFSET(SndAlias, id, 0x4);
	ASSERT_STRUCT_OFFSET(SndAlias, subtitle, 0x8);
	ASSERT_STRUCT_OFFSET(SndAlias, secondaryname, 0xC);
	ASSERT_STRUCT_OFFSET(SndAlias, assetId, 0x10);
	ASSERT_STRUCT_OFFSET(SndAlias, assetFileName, 0x14);
	ASSERT_STRUCT_OFFSET(SndAlias, flags0, 0x18);
	ASSERT_STRUCT_OFFSET(SndAlias, flags1, 0x1C);
	ASSERT_STRUCT_OFFSET(SndAlias, duck, 0x20);
	ASSERT_STRUCT_OFFSET(SndAlias, contextType, 0x24);
	ASSERT_STRUCT_OFFSET(SndAlias, contextValue, 0x28);
	ASSERT_STRUCT_OFFSET(SndAlias, stopOnPlay, 0x2C);
	ASSERT_STRUCT_OFFSET(SndAlias, futzPatch, 0x30);
	ASSERT_STRUCT_OFFSET(SndAlias, fluxTime, 0x34);
	ASSERT_STRUCT_OFFSET(SndAlias, startDelay, 0x36);
	ASSERT_STRUCT_OFFSET(SndAlias, reverbSend, 0x38);
	ASSERT_STRUCT_OFFSET(SndAlias, centerSend, 0x3A);
	ASSERT_STRUCT_OFFSET(SndAlias, volMin, 0x3C);
	ASSERT_STRUCT_OFFSET(SndAlias, volMax, 0x3E);
	ASSERT_STRUCT_OFFSET(SndAlias, pitchMin, 0x40);
	ASSERT_STRUCT_OFFSET(SndAlias, pitchMax, 0x42);
	ASSERT_STRUCT_OFFSET(SndAlias, distMin, 0x44);
	ASSERT_STRUCT_OFFSET(SndAlias, distMax, 0x46);
	ASSERT_STRUCT_OFFSET(SndAlias, distReverbMax, 0x48);
	ASSERT_STRUCT_OFFSET(SndAlias, envelopMin, 0x4A);
	ASSERT_STRUCT_OFFSET(SndAlias, envelopMax, 0x4C);
	ASSERT_STRUCT_OFFSET(SndAlias, envelopPercentage, 0x4E);
	ASSERT_STRUCT_OFFSET(SndAlias, fadeIn, 0x50);
	ASSERT_STRUCT_OFFSET(SndAlias, fadeOut, 0x52);
	ASSERT_STRUCT_OFFSET(SndAlias, dopplerScale, 0x54);
	ASSERT_STRUCT_OFFSET(SndAlias, minPriorityThreshold, 0x56);
	ASSERT_STRUCT_OFFSET(SndAlias, maxPriorityThreshold, 0x57);
	ASSERT_STRUCT_OFFSET(SndAlias, probability, 0x58);
	ASSERT_STRUCT_OFFSET(SndAlias, occlusionLevel, 0x59);
	ASSERT_STRUCT_OFFSET(SndAlias, minPriority, 0x5A);
	ASSERT_STRUCT_OFFSET(SndAlias, maxPriority, 0x5B);
	ASSERT_STRUCT_OFFSET(SndAlias, pan, 0x5C);
	ASSERT_STRUCT_OFFSET(SndAlias, limitCount, 0x5D);
	ASSERT_STRUCT_OFFSET(SndAlias, entityLimitCount, 0x5E);
	ASSERT_STRUCT_OFFSET(SndAlias, duckGroup, 0x5F);

	struct SndAliasList
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		unsigned int id; //OFS: 0x4 SIZE: 0x4
		SndAlias* head; //OFS: 0x8 SIZE: 0x4
		int count; //OFS: 0xC SIZE: 0x4
		int sequence; //OFS: 0x10 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(SndAliasList, 0x14);
	ASSERT_STRUCT_OFFSET(SndAliasList, name, 0x0);
	ASSERT_STRUCT_OFFSET(SndAliasList, id, 0x4);
	ASSERT_STRUCT_OFFSET(SndAliasList, head, 0x8);
	ASSERT_STRUCT_OFFSET(SndAliasList, count, 0xC);
	ASSERT_STRUCT_OFFSET(SndAliasList, sequence, 0x10);

	struct __declspec(align(2)) SndIndexEntry
	{
		unsigned __int16 value; //OFS: 0x0 SIZE: 0x2
		unsigned __int16 next; //OFS: 0x2 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(SndIndexEntry, 0x4);
	ASSERT_STRUCT_OFFSET(SndIndexEntry, value, 0x0);
	ASSERT_STRUCT_OFFSET(SndIndexEntry, next, 0x2);

	struct SndRadverb
	{
		char name[32]; //OFS: 0x0 SIZE: 0x20
		unsigned int id; //OFS: 0x20 SIZE: 0x4
		float smoothing; //OFS: 0x24 SIZE: 0x4
		float earlyTime; //OFS: 0x28 SIZE: 0x4
		float lateTime; //OFS: 0x2C SIZE: 0x4
		float earlyGain; //OFS: 0x30 SIZE: 0x4
		float lateGain; //OFS: 0x34 SIZE: 0x4
		float returnGain; //OFS: 0x38 SIZE: 0x4
		float earlyLpf; //OFS: 0x3C SIZE: 0x4
		float lateLpf; //OFS: 0x40 SIZE: 0x4
		float inputLpf; //OFS: 0x44 SIZE: 0x4
		float dampLpf; //OFS: 0x48 SIZE: 0x4
		float wallReflect; //OFS: 0x4C SIZE: 0x4
		float dryGain; //OFS: 0x50 SIZE: 0x4
		float earlySize; //OFS: 0x54 SIZE: 0x4
		float lateSize; //OFS: 0x58 SIZE: 0x4
		float diffusion; //OFS: 0x5C SIZE: 0x4
		float returnHighpass; //OFS: 0x60 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(SndRadverb, 0x64);
	ASSERT_STRUCT_OFFSET(SndRadverb, name, 0x0);
	ASSERT_STRUCT_OFFSET(SndRadverb, id, 0x20);
	ASSERT_STRUCT_OFFSET(SndRadverb, smoothing, 0x24);
	ASSERT_STRUCT_OFFSET(SndRadverb, earlyTime, 0x28);
	ASSERT_STRUCT_OFFSET(SndRadverb, lateTime, 0x2C);
	ASSERT_STRUCT_OFFSET(SndRadverb, earlyGain, 0x30);
	ASSERT_STRUCT_OFFSET(SndRadverb, lateGain, 0x34);
	ASSERT_STRUCT_OFFSET(SndRadverb, returnGain, 0x38);
	ASSERT_STRUCT_OFFSET(SndRadverb, earlyLpf, 0x3C);
	ASSERT_STRUCT_OFFSET(SndRadverb, lateLpf, 0x40);
	ASSERT_STRUCT_OFFSET(SndRadverb, inputLpf, 0x44);
	ASSERT_STRUCT_OFFSET(SndRadverb, dampLpf, 0x48);
	ASSERT_STRUCT_OFFSET(SndRadverb, wallReflect, 0x4C);
	ASSERT_STRUCT_OFFSET(SndRadverb, dryGain, 0x50);
	ASSERT_STRUCT_OFFSET(SndRadverb, earlySize, 0x54);
	ASSERT_STRUCT_OFFSET(SndRadverb, lateSize, 0x58);
	ASSERT_STRUCT_OFFSET(SndRadverb, diffusion, 0x5C);
	ASSERT_STRUCT_OFFSET(SndRadverb, returnHighpass, 0x60);

	struct SndDuck
	{
		char name[32]; //OFS: 0x0 SIZE: 0x20
		unsigned int id; //OFS: 0x20 SIZE: 0x4
		float fadeIn; //OFS: 0x24 SIZE: 0x4
		float fadeOut; //OFS: 0x28 SIZE: 0x4
		float startDelay; //OFS: 0x2C SIZE: 0x4
		float distance; //OFS: 0x30 SIZE: 0x4
		float length; //OFS: 0x34 SIZE: 0x4
		unsigned int fadeInCurve; //OFS: 0x38 SIZE: 0x4
		unsigned int fadeOutCurve; //OFS: 0x3C SIZE: 0x4
		float* attenuation; //OFS: 0x40 SIZE: 0x4
		float* filter; //OFS: 0x44 SIZE: 0x4
		int updateWhilePaused; //OFS: 0x48 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(SndDuck, 0x4C);
	ASSERT_STRUCT_OFFSET(SndDuck, name, 0x0);
	ASSERT_STRUCT_OFFSET(SndDuck, id, 0x20);
	ASSERT_STRUCT_OFFSET(SndDuck, fadeIn, 0x24);
	ASSERT_STRUCT_OFFSET(SndDuck, fadeOut, 0x28);
	ASSERT_STRUCT_OFFSET(SndDuck, startDelay, 0x2C);
	ASSERT_STRUCT_OFFSET(SndDuck, distance, 0x30);
	ASSERT_STRUCT_OFFSET(SndDuck, length, 0x34);
	ASSERT_STRUCT_OFFSET(SndDuck, fadeInCurve, 0x38);
	ASSERT_STRUCT_OFFSET(SndDuck, fadeOutCurve, 0x3C);
	ASSERT_STRUCT_OFFSET(SndDuck, attenuation, 0x40);
	ASSERT_STRUCT_OFFSET(SndDuck, filter, 0x44);
	ASSERT_STRUCT_OFFSET(SndDuck, updateWhilePaused, 0x48);

	struct SndAssetBankHeader
	{
		unsigned int magic; //OFS: 0x0 SIZE: 0x4
		unsigned int version; //OFS: 0x4 SIZE: 0x4
		unsigned int entrySize; //OFS: 0x8 SIZE: 0x4
		unsigned int checksumSize; //OFS: 0xC SIZE: 0x4
		unsigned int dependencySize; //OFS: 0x10 SIZE: 0x4
		unsigned int entryCount; //OFS: 0x14 SIZE: 0x4
		unsigned int dependencyCount; //OFS: 0x18 SIZE: 0x4
		unsigned int pad32; //OFS: 0x1C SIZE: 0x4
		__int64 fileSize; //OFS: 0x20 SIZE: 0x8
		__int64 entryOffset; //OFS: 0x28 SIZE: 0x8
		__int64 checksumOffset; //OFS: 0x30 SIZE: 0x8
		unsigned __int8 checksumChecksum[16]; //OFS: 0x38 SIZE: 0x10
		char dependencies[512]; //OFS: 0x48 SIZE: 0x200
		char padding[1464]; //OFS: 0x248 SIZE: 0x5B8
	};
	ASSERT_STRUCT_SIZE(SndAssetBankHeader, 0x800);
	ASSERT_STRUCT_OFFSET(SndAssetBankHeader, magic, 0x0);
	ASSERT_STRUCT_OFFSET(SndAssetBankHeader, version, 0x4);
	ASSERT_STRUCT_OFFSET(SndAssetBankHeader, entrySize, 0x8);
	ASSERT_STRUCT_OFFSET(SndAssetBankHeader, checksumSize, 0xC);
	ASSERT_STRUCT_OFFSET(SndAssetBankHeader, dependencySize, 0x10);
	ASSERT_STRUCT_OFFSET(SndAssetBankHeader, entryCount, 0x14);
	ASSERT_STRUCT_OFFSET(SndAssetBankHeader, dependencyCount, 0x18);
	ASSERT_STRUCT_OFFSET(SndAssetBankHeader, pad32, 0x1C);
	ASSERT_STRUCT_OFFSET(SndAssetBankHeader, fileSize, 0x20);
	ASSERT_STRUCT_OFFSET(SndAssetBankHeader, entryOffset, 0x28);
	ASSERT_STRUCT_OFFSET(SndAssetBankHeader, checksumOffset, 0x30);
	ASSERT_STRUCT_OFFSET(SndAssetBankHeader, checksumChecksum, 0x38);
	ASSERT_STRUCT_OFFSET(SndAssetBankHeader, dependencies, 0x48);
	ASSERT_STRUCT_OFFSET(SndAssetBankHeader, padding, 0x248);

	/*
	struct __declspec(align(2)) SndRuntimeAssetBank
	{
		const char* zone; //OFS: 0x0 SIZE: 0x4
		const char* language; //OFS: 0x4 SIZE: 0x4
		int fileHandle; //OFS: 0x8 SIZE: 0x4
		SndAssetBankHeader header; //OFS: 0xC SIZE: 0x800
		unsigned int entryOffset; //OFS: 0x80C SIZE: 0x4
		unsigned __int8 linkTimeChecksum[16]; //OFS: 0x810 SIZE: 0x10
		char filename[256]; //OFS: 0x820 SIZE: 0x100
		bool indicesLoaded; //OFS: 0x920 SIZE: 0x1
		bool indicesAllocated; //OFS: 0x921 SIZE: 0x1
	};
	int i = sizeof(SndAssetBankHeader);
	ASSERT_STRUCT_SIZE(SndRuntimeAssetBank, 0x922);
	ASSERT_STRUCT_OFFSET(SndRuntimeAssetBank, zone, 0x0);
	ASSERT_STRUCT_OFFSET(SndRuntimeAssetBank, language, 0x4);
	ASSERT_STRUCT_OFFSET(SndRuntimeAssetBank, fileHandle, 0x8);
	ASSERT_STRUCT_OFFSET(SndRuntimeAssetBank, header, 0xC);
	ASSERT_STRUCT_OFFSET(SndRuntimeAssetBank, entryOffset, 0x80C);
	ASSERT_STRUCT_OFFSET(SndRuntimeAssetBank, linkTimeChecksum, 0x810);
	ASSERT_STRUCT_OFFSET(SndRuntimeAssetBank, filename, 0x820);
	ASSERT_STRUCT_OFFSET(SndRuntimeAssetBank, indicesLoaded, 0x920);
	ASSERT_STRUCT_OFFSET(SndRuntimeAssetBank, indicesAllocated, 0x921);
	*/

	struct SndAssetBankEntry
	{
		unsigned int id; //OFS: 0x0 SIZE: 0x4
		unsigned int size; //OFS: 0x4 SIZE: 0x4
		unsigned int offset; //OFS: 0x8 SIZE: 0x4
		unsigned int frameCount; //OFS: 0xC SIZE: 0x4
		unsigned __int8 frameRateIndex; //OFS: 0x10 SIZE: 0x1
		unsigned __int8 channelCount; //OFS: 0x11 SIZE: 0x1
		unsigned __int8 looping; //OFS: 0x12 SIZE: 0x1
		unsigned __int8 format; //OFS: 0x13 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(SndAssetBankEntry, 0x14);
	ASSERT_STRUCT_OFFSET(SndAssetBankEntry, id, 0x0);
	ASSERT_STRUCT_OFFSET(SndAssetBankEntry, size, 0x4);
	ASSERT_STRUCT_OFFSET(SndAssetBankEntry, offset, 0x8);
	ASSERT_STRUCT_OFFSET(SndAssetBankEntry, frameCount, 0xC);
	ASSERT_STRUCT_OFFSET(SndAssetBankEntry, frameRateIndex, 0x10);
	ASSERT_STRUCT_OFFSET(SndAssetBankEntry, channelCount, 0x11);
	ASSERT_STRUCT_OFFSET(SndAssetBankEntry, looping, 0x12);
	ASSERT_STRUCT_OFFSET(SndAssetBankEntry, format, 0x13);

	struct SndLoadedAssets
	{
		const char* zone; //OFS: 0x0 SIZE: 0x4
		const char* language; //OFS: 0x4 SIZE: 0x4
		unsigned int loadedCount; //OFS: 0x8 SIZE: 0x4
		unsigned int entryCount; //OFS: 0xC SIZE: 0x4
		SndAssetBankEntry* entries; //OFS: 0x10 SIZE: 0x4
		unsigned int dataSize; //OFS: 0x14 SIZE: 0x4
		char* data; //OFS: 0x18 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(SndLoadedAssets, 0x1C);
	ASSERT_STRUCT_OFFSET(SndLoadedAssets, zone, 0x0);
	ASSERT_STRUCT_OFFSET(SndLoadedAssets, language, 0x4);
	ASSERT_STRUCT_OFFSET(SndLoadedAssets, loadedCount, 0x8);
	ASSERT_STRUCT_OFFSET(SndLoadedAssets, entryCount, 0xC);
	ASSERT_STRUCT_OFFSET(SndLoadedAssets, entries, 0x10);
	ASSERT_STRUCT_OFFSET(SndLoadedAssets, dataSize, 0x14);
	ASSERT_STRUCT_OFFSET(SndLoadedAssets, data, 0x18);

	struct SndDialogScriptIdLookup
	{
		unsigned int scriptId; //OFS: 0x0 SIZE: 0x4
		unsigned int aliasId; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(SndDialogScriptIdLookup, 0x8);
	ASSERT_STRUCT_OFFSET(SndDialogScriptIdLookup, scriptId, 0x0);
	ASSERT_STRUCT_OFFSET(SndDialogScriptIdLookup, aliasId, 0x4);

	/*
	struct SndBank
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		unsigned int aliasCount; //OFS: 0x4 SIZE: 0x4
		SndAliasList* alias; //OFS: 0x8 SIZE: 0x4
		SndIndexEntry* aliasIndex; //OFS: 0xC SIZE: 0x4
		unsigned int radverbCount; //OFS: 0x10 SIZE: 0x4
		SndRadverb* radverbs; //OFS: 0x14 SIZE: 0x4
		unsigned int duckCount; //OFS: 0x18 SIZE: 0x4
		SndDuck* ducks; //OFS: 0x1C SIZE: 0x4
		SndRuntimeAssetBank streamAssetBank; //OFS: 0x20 SIZE: 0x922
		SndRuntimeAssetBank loadAssetBank; //OFS: 0x942 SIZE: 0x922
		SndLoadedAssets loadedAssets; //OFS: 0x1264 SIZE: 0x1C
		unsigned int scriptIdLookupCount; //OFS: 0x1280 SIZE: 0x4
		SndDialogScriptIdLookup* scriptIdLookups; //OFS: 0x1284 SIZE: 0x4
		SndBankState state; //OFS: 0x1288 SIZE: 0x4
		int streamRequestId; //OFS: 0x128C SIZE: 0x4
		bool pendingIo; //OFS: 0x1290 SIZE: 0x1
		bool ioError; //OFS: 0x1291 SIZE: 0x1
		bool runtimeAssetLoad; //OFS: 0x1292 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(SndBank, 0x1294);
	ASSERT_STRUCT_OFFSET(SndBank, name, 0x0);
	ASSERT_STRUCT_OFFSET(SndBank, aliasCount, 0x4);
	ASSERT_STRUCT_OFFSET(SndBank, alias, 0x8);
	ASSERT_STRUCT_OFFSET(SndBank, aliasIndex, 0xC);
	ASSERT_STRUCT_OFFSET(SndBank, radverbCount, 0x10);
	ASSERT_STRUCT_OFFSET(SndBank, radverbs, 0x14);
	ASSERT_STRUCT_OFFSET(SndBank, duckCount, 0x18);
	ASSERT_STRUCT_OFFSET(SndBank, ducks, 0x1C);
	ASSERT_STRUCT_OFFSET(SndBank, streamAssetBank, 0x20);
	ASSERT_STRUCT_OFFSET(SndBank, loadAssetBank, 0x942);
	ASSERT_STRUCT_OFFSET(SndBank, loadedAssets, 0x1264);
	ASSERT_STRUCT_OFFSET(SndBank, scriptIdLookupCount, 0x1280);
	ASSERT_STRUCT_OFFSET(SndBank, scriptIdLookups, 0x1284);
	ASSERT_STRUCT_OFFSET(SndBank, state, 0x1288);
	ASSERT_STRUCT_OFFSET(SndBank, streamRequestId, 0x128C);
	ASSERT_STRUCT_OFFSET(SndBank, pendingIo, 0x1290);
	ASSERT_STRUCT_OFFSET(SndBank, ioError, 0x1291);
	ASSERT_STRUCT_OFFSET(SndBank, runtimeAssetLoad, 0x1292);
	*/

	struct SndPatch
	{
		char* name; //OFS: 0x0 SIZE: 0x4
		unsigned int elementCount; //OFS: 0x4 SIZE: 0x4
		unsigned int* elements; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(SndPatch, 0xC);
	ASSERT_STRUCT_OFFSET(SndPatch, name, 0x0);
	ASSERT_STRUCT_OFFSET(SndPatch, elementCount, 0x4);
	ASSERT_STRUCT_OFFSET(SndPatch, elements, 0x8);

	struct ClipMaterial
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		int surfaceFlags; //OFS: 0x4 SIZE: 0x4
		int contentFlags; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(ClipMaterial, 0xC);
	ASSERT_STRUCT_OFFSET(ClipMaterial, name, 0x0);
	ASSERT_STRUCT_OFFSET(ClipMaterial, surfaceFlags, 0x4);
	ASSERT_STRUCT_OFFSET(ClipMaterial, contentFlags, 0x8);

	struct cLeafBrushNodeLeaf_t
	{
		unsigned __int16* brushes; //OFS: 0x0 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(cLeafBrushNodeLeaf_t, 0x4);
	ASSERT_STRUCT_OFFSET(cLeafBrushNodeLeaf_t, brushes, 0x0);

	struct cLeafBrushNodeChildren_t
	{
		float dist; //OFS: 0x0 SIZE: 0x4
		float range; //OFS: 0x4 SIZE: 0x4
		unsigned __int16 childOffset[2]; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(cLeafBrushNodeChildren_t, 0xC);
	ASSERT_STRUCT_OFFSET(cLeafBrushNodeChildren_t, dist, 0x0);
	ASSERT_STRUCT_OFFSET(cLeafBrushNodeChildren_t, range, 0x4);
	ASSERT_STRUCT_OFFSET(cLeafBrushNodeChildren_t, childOffset, 0x8);

	union cLeafBrushNodeData_t
	{
		cLeafBrushNodeLeaf_t leaf; //OFS: 0x0 SIZE: 0x4
		cLeafBrushNodeChildren_t children; //OFS: 0x1 SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(cLeafBrushNodeData_t, 0xC);

	struct cLeafBrushNode_s
	{
		unsigned __int8 axis; //OFS: 0x0 SIZE: 0x1
		__int16 leafBrushCount; //OFS: 0x2 SIZE: 0x2
		int contents; //OFS: 0x4 SIZE: 0x4
		cLeafBrushNodeData_t data; //OFS: 0x8 SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(cLeafBrushNode_s, 0x14);
	ASSERT_STRUCT_OFFSET(cLeafBrushNode_s, axis, 0x0);
	ASSERT_STRUCT_OFFSET(cLeafBrushNode_s, leafBrushCount, 0x2);
	ASSERT_STRUCT_OFFSET(cLeafBrushNode_s, contents, 0x4);
	ASSERT_STRUCT_OFFSET(cLeafBrushNode_s, data, 0x8);

	struct __declspec(align(8)) cbrush_t
	{
		vec3_t mins; //OFS: 0x0 SIZE: 0xC
		int contents; //OFS: 0xC SIZE: 0x4
		vec3_t maxs; //OFS: 0x10 SIZE: 0xC
		unsigned int numsides; //OFS: 0x1C SIZE: 0x4
		cbrushside_t* sides; //OFS: 0x20 SIZE: 0x4
		int axial_cflags[2][3]; //OFS: 0x24 SIZE: 0x18
		int axial_sflags[2][3]; //OFS: 0x3C SIZE: 0x18
		unsigned int numverts; //OFS: 0x54 SIZE: 0x4
		vec3_t* verts; //OFS: 0x58 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(cbrush_t, 0x60);
	ASSERT_STRUCT_OFFSET(cbrush_t, mins, 0x0);
	ASSERT_STRUCT_OFFSET(cbrush_t, contents, 0xC);
	ASSERT_STRUCT_OFFSET(cbrush_t, maxs, 0x10);
	ASSERT_STRUCT_OFFSET(cbrush_t, numsides, 0x1C);
	ASSERT_STRUCT_OFFSET(cbrush_t, sides, 0x20);
	ASSERT_STRUCT_OFFSET(cbrush_t, axial_cflags, 0x24);
	ASSERT_STRUCT_OFFSET(cbrush_t, axial_sflags, 0x3C);
	ASSERT_STRUCT_OFFSET(cbrush_t, numverts, 0x54);
	ASSERT_STRUCT_OFFSET(cbrush_t, verts, 0x58);

	struct Bounds
	{
		vec3_t midPoint; //OFS: 0x0 SIZE: 0xC
		vec3_t halfSize; //OFS: 0xC SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(Bounds, 0x18);
	ASSERT_STRUCT_OFFSET(Bounds, midPoint, 0x0);
	ASSERT_STRUCT_OFFSET(Bounds, halfSize, 0xC);

	struct ClipInfo
	{
		int planeCount; //OFS: 0x0 SIZE: 0x4
		cplane_s* planes; //OFS: 0x4 SIZE: 0x4
		unsigned int numMaterials; //OFS: 0x8 SIZE: 0x4
		ClipMaterial* materials; //OFS: 0xC SIZE: 0x4
		unsigned int numBrushSides; //OFS: 0x10 SIZE: 0x4
		cbrushside_t* brushsides; //OFS: 0x14 SIZE: 0x4
		unsigned int leafbrushNodesCount; //OFS: 0x18 SIZE: 0x4
		cLeafBrushNode_s* leafbrushNodes; //OFS: 0x1C SIZE: 0x4
		unsigned int numLeafBrushes; //OFS: 0x20 SIZE: 0x4
		unsigned __int16* leafbrushes; //OFS: 0x24 SIZE: 0x4
		unsigned int numBrushVerts; //OFS: 0x28 SIZE: 0x4
		vec3_t* brushVerts; //OFS: 0x2C SIZE: 0x4
		unsigned int nuinds; //OFS: 0x30 SIZE: 0x4
		unsigned __int16* uinds; //OFS: 0x34 SIZE: 0x4
		unsigned __int16 numBrushes; //OFS: 0x38 SIZE: 0x2
		cbrush_t* brushes; //OFS: 0x3C SIZE: 0x4
		Bounds* brushBounds; //OFS: 0x40 SIZE: 0x4
		int* brushContents; //OFS: 0x44 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(ClipInfo, 0x48);
	ASSERT_STRUCT_OFFSET(ClipInfo, planeCount, 0x0);
	ASSERT_STRUCT_OFFSET(ClipInfo, planes, 0x4);
	ASSERT_STRUCT_OFFSET(ClipInfo, numMaterials, 0x8);
	ASSERT_STRUCT_OFFSET(ClipInfo, materials, 0xC);
	ASSERT_STRUCT_OFFSET(ClipInfo, numBrushSides, 0x10);
	ASSERT_STRUCT_OFFSET(ClipInfo, brushsides, 0x14);
	ASSERT_STRUCT_OFFSET(ClipInfo, leafbrushNodesCount, 0x18);
	ASSERT_STRUCT_OFFSET(ClipInfo, leafbrushNodes, 0x1C);
	ASSERT_STRUCT_OFFSET(ClipInfo, numLeafBrushes, 0x20);
	ASSERT_STRUCT_OFFSET(ClipInfo, leafbrushes, 0x24);
	ASSERT_STRUCT_OFFSET(ClipInfo, numBrushVerts, 0x28);
	ASSERT_STRUCT_OFFSET(ClipInfo, brushVerts, 0x2C);
	ASSERT_STRUCT_OFFSET(ClipInfo, nuinds, 0x30);
	ASSERT_STRUCT_OFFSET(ClipInfo, uinds, 0x34);
	ASSERT_STRUCT_OFFSET(ClipInfo, numBrushes, 0x38);
	ASSERT_STRUCT_OFFSET(ClipInfo, brushes, 0x3C);
	ASSERT_STRUCT_OFFSET(ClipInfo, brushBounds, 0x40);
	ASSERT_STRUCT_OFFSET(ClipInfo, brushContents, 0x44);

	struct __declspec(align(2)) cStaticModelWritable
	{
		unsigned __int16 nextModelInWorldSector; //OFS: 0x0 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(cStaticModelWritable, 0x2);
	ASSERT_STRUCT_OFFSET(cStaticModelWritable, nextModelInWorldSector, 0x0);

	struct cStaticModel_s
	{
		cStaticModelWritable writable; //OFS: 0x0 SIZE: 0x2
		XModel* xmodel; //OFS: 0x4 SIZE: 0x4
		int contents; //OFS: 0x8 SIZE: 0x4
		vec3_t origin; //OFS: 0xC SIZE: 0xC
		vec3_t invScaledAxis[3]; //OFS: 0x18 SIZE: 0x24
		vec3_t absmin; //OFS: 0x3C SIZE: 0xC
		vec3_t absmax; //OFS: 0x48 SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(cStaticModel_s, 0x54);
	ASSERT_STRUCT_OFFSET(cStaticModel_s, writable, 0x0);
	ASSERT_STRUCT_OFFSET(cStaticModel_s, xmodel, 0x4);
	ASSERT_STRUCT_OFFSET(cStaticModel_s, contents, 0x8);
	ASSERT_STRUCT_OFFSET(cStaticModel_s, origin, 0xC);
	ASSERT_STRUCT_OFFSET(cStaticModel_s, invScaledAxis, 0x18);
	ASSERT_STRUCT_OFFSET(cStaticModel_s, absmin, 0x3C);
	ASSERT_STRUCT_OFFSET(cStaticModel_s, absmax, 0x48);

	struct cNode_t
	{
		cplane_s* plane; //OFS: 0x0 SIZE: 0x4
		__int16 children[2]; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(cNode_t, 0x8);
	ASSERT_STRUCT_OFFSET(cNode_t, plane, 0x0);
	ASSERT_STRUCT_OFFSET(cNode_t, children, 0x4);

	struct cLeaf_s
	{
		unsigned __int16 firstCollAabbIndex; //OFS: 0x0 SIZE: 0x2
		unsigned __int16 collAabbCount; //OFS: 0x2 SIZE: 0x2
		int brushContents; //OFS: 0x4 SIZE: 0x4
		int terrainContents; //OFS: 0x8 SIZE: 0x4
		vec3_t mins; //OFS: 0xC SIZE: 0xC
		vec3_t maxs; //OFS: 0x18 SIZE: 0xC
		int leafBrushNode; //OFS: 0x24 SIZE: 0x4
		__int16 cluster; //OFS: 0x28 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(cLeaf_s, 0x2C);
	ASSERT_STRUCT_OFFSET(cLeaf_s, firstCollAabbIndex, 0x0);
	ASSERT_STRUCT_OFFSET(cLeaf_s, collAabbCount, 0x2);
	ASSERT_STRUCT_OFFSET(cLeaf_s, brushContents, 0x4);
	ASSERT_STRUCT_OFFSET(cLeaf_s, terrainContents, 0x8);
	ASSERT_STRUCT_OFFSET(cLeaf_s, mins, 0xC);
	ASSERT_STRUCT_OFFSET(cLeaf_s, maxs, 0x18);
	ASSERT_STRUCT_OFFSET(cLeaf_s, leafBrushNode, 0x24);
	ASSERT_STRUCT_OFFSET(cLeaf_s, cluster, 0x28);

	struct CollisionPartition
	{
		unsigned __int8 triCount; //OFS: 0x0 SIZE: 0x1
		int firstTri; //OFS: 0x4 SIZE: 0x4
		int nuinds; //OFS: 0x8 SIZE: 0x4
		int fuind; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(CollisionPartition, 0x10);
	ASSERT_STRUCT_OFFSET(CollisionPartition, triCount, 0x0);
	ASSERT_STRUCT_OFFSET(CollisionPartition, firstTri, 0x4);
	ASSERT_STRUCT_OFFSET(CollisionPartition, nuinds, 0x8);
	ASSERT_STRUCT_OFFSET(CollisionPartition, fuind, 0xC);

	union CollisionAabbTreeIndex
	{
		int firstChildIndex; //OFS: 0x0 SIZE: 0x4
		int partitionIndex; //OFS: 0x1 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(CollisionAabbTreeIndex, 0x4);

	struct CollisionAabbTree
	{
		vec3_t origin; //OFS: 0x0 SIZE: 0xC
		unsigned __int16 materialIndex; //OFS: 0xC SIZE: 0x2
		unsigned __int16 childCount; //OFS: 0xE SIZE: 0x2
		vec3_t halfSize; //OFS: 0x10 SIZE: 0xC
		CollisionAabbTreeIndex u; //OFS: 0x1C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(CollisionAabbTree, 0x20);
	ASSERT_STRUCT_OFFSET(CollisionAabbTree, origin, 0x0);
	ASSERT_STRUCT_OFFSET(CollisionAabbTree, materialIndex, 0xC);
	ASSERT_STRUCT_OFFSET(CollisionAabbTree, childCount, 0xE);
	ASSERT_STRUCT_OFFSET(CollisionAabbTree, halfSize, 0x10);
	ASSERT_STRUCT_OFFSET(CollisionAabbTree, u, 0x1C);

	struct cmodel_t
	{
		vec3_t mins; //OFS: 0x0 SIZE: 0xC
		vec3_t maxs; //OFS: 0xC SIZE: 0xC
		float radius; //OFS: 0x18 SIZE: 0x4
		ClipInfo* info; //OFS: 0x1C SIZE: 0x4
		cLeaf_s leaf; //OFS: 0x20 SIZE: 0x2C
	};
	ASSERT_STRUCT_SIZE(cmodel_t, 0x4C);
	ASSERT_STRUCT_OFFSET(cmodel_t, mins, 0x0);
	ASSERT_STRUCT_OFFSET(cmodel_t, maxs, 0xC);
	ASSERT_STRUCT_OFFSET(cmodel_t, radius, 0x18);
	ASSERT_STRUCT_OFFSET(cmodel_t, info, 0x1C);
	ASSERT_STRUCT_OFFSET(cmodel_t, leaf, 0x20);

	struct TriggerModel
	{
		int contents; //OFS: 0x0 SIZE: 0x4
		unsigned __int16 hullCount; //OFS: 0x4 SIZE: 0x2
		unsigned __int16 firstHull; //OFS: 0x6 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(TriggerModel, 0x8);
	ASSERT_STRUCT_OFFSET(TriggerModel, contents, 0x0);
	ASSERT_STRUCT_OFFSET(TriggerModel, hullCount, 0x4);
	ASSERT_STRUCT_OFFSET(TriggerModel, firstHull, 0x6);

	struct TriggerHull
	{
		Bounds bounds; //OFS: 0x0 SIZE: 0x18
		int contents; //OFS: 0x18 SIZE: 0x4
		unsigned __int16 slabCount; //OFS: 0x1C SIZE: 0x2
		unsigned __int16 firstSlab; //OFS: 0x1E SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(TriggerHull, 0x20);
	ASSERT_STRUCT_OFFSET(TriggerHull, bounds, 0x0);
	ASSERT_STRUCT_OFFSET(TriggerHull, contents, 0x18);
	ASSERT_STRUCT_OFFSET(TriggerHull, slabCount, 0x1C);
	ASSERT_STRUCT_OFFSET(TriggerHull, firstSlab, 0x1E);

	struct TriggerSlab
	{
		vec3_t dir; //OFS: 0x0 SIZE: 0xC
		float midPoint; //OFS: 0xC SIZE: 0x4
		float halfSize; //OFS: 0x10 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(TriggerSlab, 0x14);
	ASSERT_STRUCT_OFFSET(TriggerSlab, dir, 0x0);
	ASSERT_STRUCT_OFFSET(TriggerSlab, midPoint, 0xC);
	ASSERT_STRUCT_OFFSET(TriggerSlab, halfSize, 0x10);

	struct MapTriggers
	{
		unsigned int count; //OFS: 0x0 SIZE: 0x4
		TriggerModel* models; //OFS: 0x4 SIZE: 0x4
		unsigned int hullCount; //OFS: 0x8 SIZE: 0x4
		TriggerHull* hulls; //OFS: 0xC SIZE: 0x4
		unsigned int slabCount; //OFS: 0x10 SIZE: 0x4
		TriggerSlab* slabs; //OFS: 0x14 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(MapTriggers, 0x18);
	ASSERT_STRUCT_OFFSET(MapTriggers, count, 0x0);
	ASSERT_STRUCT_OFFSET(MapTriggers, models, 0x4);
	ASSERT_STRUCT_OFFSET(MapTriggers, hullCount, 0x8);
	ASSERT_STRUCT_OFFSET(MapTriggers, hulls, 0xC);
	ASSERT_STRUCT_OFFSET(MapTriggers, slabCount, 0x10);
	ASSERT_STRUCT_OFFSET(MapTriggers, slabs, 0x14);

	struct MapEnts
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		char* entityString; //OFS: 0x4 SIZE: 0x4
		int numEntityChars; //OFS: 0x8 SIZE: 0x4
		MapTriggers trigger; //OFS: 0xC SIZE: 0x18
	};
	ASSERT_STRUCT_SIZE(MapEnts, 0x24);
	ASSERT_STRUCT_OFFSET(MapEnts, name, 0x0);
	ASSERT_STRUCT_OFFSET(MapEnts, entityString, 0x4);
	ASSERT_STRUCT_OFFSET(MapEnts, numEntityChars, 0x8);
	ASSERT_STRUCT_OFFSET(MapEnts, trigger, 0xC);

	struct GfxPlacement
	{
		vec4_t quat; //OFS: 0x0 SIZE: 0x10
		vec3_t origin; //OFS: 0x10 SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(GfxPlacement, 0x1C);
	ASSERT_STRUCT_OFFSET(GfxPlacement, quat, 0x0);
	ASSERT_STRUCT_OFFSET(GfxPlacement, origin, 0x10);

	struct DynEntityDef
	{
		DynEntityType type; //OFS: 0x0 SIZE: 0x4
		GfxPlacement pose; //OFS: 0x4 SIZE: 0x1C
		XModel* xModel; //OFS: 0x20 SIZE: 0x4
		XModel* destroyedxModel; //OFS: 0x24 SIZE: 0x4
		unsigned __int16 brushModel; //OFS: 0x28 SIZE: 0x2
		unsigned __int16 physicsBrushModel; //OFS: 0x2A SIZE: 0x2
		const FxEffectDef* destroyFx; //OFS: 0x2C SIZE: 0x4
		unsigned int destroySound; //OFS: 0x30 SIZE: 0x4
		XModelPieces* destroyPieces; //OFS: 0x34 SIZE: 0x4
		PhysPreset* physPreset; //OFS: 0x38 SIZE: 0x4
		__int16 physConstraints[4]; //OFS: 0x3C SIZE: 0x8
		int health; //OFS: 0x44 SIZE: 0x4
		int flags; //OFS: 0x48 SIZE: 0x4
		int contents; //OFS: 0x4C SIZE: 0x4
		unsigned __int16 targetname; //OFS: 0x50 SIZE: 0x2
		unsigned __int16 target; //OFS: 0x52 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(DynEntityDef, 0x54);
	ASSERT_STRUCT_OFFSET(DynEntityDef, type, 0x0);
	ASSERT_STRUCT_OFFSET(DynEntityDef, pose, 0x4);
	ASSERT_STRUCT_OFFSET(DynEntityDef, xModel, 0x20);
	ASSERT_STRUCT_OFFSET(DynEntityDef, destroyedxModel, 0x24);
	ASSERT_STRUCT_OFFSET(DynEntityDef, brushModel, 0x28);
	ASSERT_STRUCT_OFFSET(DynEntityDef, physicsBrushModel, 0x2A);
	ASSERT_STRUCT_OFFSET(DynEntityDef, destroyFx, 0x2C);
	ASSERT_STRUCT_OFFSET(DynEntityDef, destroySound, 0x30);
	ASSERT_STRUCT_OFFSET(DynEntityDef, destroyPieces, 0x34);
	ASSERT_STRUCT_OFFSET(DynEntityDef, physPreset, 0x38);
	ASSERT_STRUCT_OFFSET(DynEntityDef, physConstraints, 0x3C);
	ASSERT_STRUCT_OFFSET(DynEntityDef, health, 0x44);
	ASSERT_STRUCT_OFFSET(DynEntityDef, flags, 0x48);
	ASSERT_STRUCT_OFFSET(DynEntityDef, contents, 0x4C);
	ASSERT_STRUCT_OFFSET(DynEntityDef, targetname, 0x50);
	ASSERT_STRUCT_OFFSET(DynEntityDef, target, 0x52);

	struct DynEntityPose
	{
		GfxPlacement pose; //OFS: 0x0 SIZE: 0x1C
		float radius; //OFS: 0x1C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(DynEntityPose, 0x20);
	ASSERT_STRUCT_OFFSET(DynEntityPose, pose, 0x0);
	ASSERT_STRUCT_OFFSET(DynEntityPose, radius, 0x1C);

	struct DynEntityClient
	{
		int physObjId; //OFS: 0x0 SIZE: 0x4
		unsigned __int16 flags; //OFS: 0x4 SIZE: 0x2
		unsigned __int16 lightingHandle; //OFS: 0x6 SIZE: 0x2
		int health; //OFS: 0x8 SIZE: 0x4
		unsigned __int16 burnTime; //OFS: 0xC SIZE: 0x2
		unsigned __int16 fadeTime; //OFS: 0xE SIZE: 0x2
		int physicsStartTime; //OFS: 0x10 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(DynEntityClient, 0x14);
	ASSERT_STRUCT_OFFSET(DynEntityClient, physObjId, 0x0);
	ASSERT_STRUCT_OFFSET(DynEntityClient, flags, 0x4);
	ASSERT_STRUCT_OFFSET(DynEntityClient, lightingHandle, 0x6);
	ASSERT_STRUCT_OFFSET(DynEntityClient, health, 0x8);
	ASSERT_STRUCT_OFFSET(DynEntityClient, burnTime, 0xC);
	ASSERT_STRUCT_OFFSET(DynEntityClient, fadeTime, 0xE);
	ASSERT_STRUCT_OFFSET(DynEntityClient, physicsStartTime, 0x10);

	struct DynEntityServer
	{
		unsigned __int16 flags; //OFS: 0x0 SIZE: 0x2
		int health; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(DynEntityServer, 0x8);
	ASSERT_STRUCT_OFFSET(DynEntityServer, flags, 0x0);
	ASSERT_STRUCT_OFFSET(DynEntityServer, health, 0x4);

	struct DynEntityColl
	{
		unsigned __int16 sector; //OFS: 0x0 SIZE: 0x2
		unsigned __int16 nextEntInSector; //OFS: 0x2 SIZE: 0x2
		vec3_t linkMins; //OFS: 0x4 SIZE: 0xC
		vec3_t linkMaxs; //OFS: 0x10 SIZE: 0xC
		int contents; //OFS: 0x1C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(DynEntityColl, 0x20);
	ASSERT_STRUCT_OFFSET(DynEntityColl, sector, 0x0);
	ASSERT_STRUCT_OFFSET(DynEntityColl, nextEntInSector, 0x2);
	ASSERT_STRUCT_OFFSET(DynEntityColl, linkMins, 0x4);
	ASSERT_STRUCT_OFFSET(DynEntityColl, linkMaxs, 0x10);
	ASSERT_STRUCT_OFFSET(DynEntityColl, contents, 0x1C);

	struct par_t
	{
		vec3_t p; //OFS: 0x0 SIZE: 0xC
		vec3_t p0; //OFS: 0xC SIZE: 0xC
		vec3_t p_prev; //OFS: 0x18 SIZE: 0xC
		int flags; //OFS: 0x24 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(par_t, 0x28);
	ASSERT_STRUCT_OFFSET(par_t, p, 0x0);
	ASSERT_STRUCT_OFFSET(par_t, p0, 0xC);
	ASSERT_STRUCT_OFFSET(par_t, p_prev, 0x18);
	ASSERT_STRUCT_OFFSET(par_t, flags, 0x24);

	struct constraint_t
	{
		vec3_t p; //OFS: 0x0 SIZE: 0xC
		rope_constraint_e type; //OFS: 0xC SIZE: 0x4
		int entity_index; //OFS: 0x10 SIZE: 0x4
		int bone_name_hash; //OFS: 0x14 SIZE: 0x4
		unsigned __int8 pi1; //OFS: 0x18 SIZE: 0x1
		unsigned __int8 pi2; //OFS: 0x19 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(constraint_t, 0x1C);
	ASSERT_STRUCT_OFFSET(constraint_t, p, 0x0);
	ASSERT_STRUCT_OFFSET(constraint_t, type, 0xC);
	ASSERT_STRUCT_OFFSET(constraint_t, entity_index, 0x10);
	ASSERT_STRUCT_OFFSET(constraint_t, bone_name_hash, 0x14);
	ASSERT_STRUCT_OFFSET(constraint_t, pi1, 0x18);
	ASSERT_STRUCT_OFFSET(constraint_t, pi2, 0x19);

	struct rope_frame_verts_t
	{
		int num_verts; //OFS: 0x0 SIZE: 0x4
		vec3_t v[50]; //OFS: 0x4 SIZE: 0x258
	};
	ASSERT_STRUCT_SIZE(rope_frame_verts_t, 0x25C);
	ASSERT_STRUCT_OFFSET(rope_frame_verts_t, num_verts, 0x0);
	ASSERT_STRUCT_OFFSET(rope_frame_verts_t, v, 0x4);

	struct rope_client_verts_t
	{
		rope_frame_verts_t frame_verts[2]; //OFS: 0x0 SIZE: 0x4B8
		unsigned int frame_index; //OFS: 0x4B8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(rope_client_verts_t, 0x4BC);
	ASSERT_STRUCT_OFFSET(rope_client_verts_t, frame_verts, 0x0);
	ASSERT_STRUCT_OFFSET(rope_client_verts_t, frame_index, 0x4B8);

	struct rope_t
	{
		par_t m_particles[25]; //OFS: 0x0 SIZE: 0x3E8
		constraint_t m_constraints[30]; //OFS: 0x3E8 SIZE: 0x348
		int m_entity_anchors[3]; //OFS: 0x730 SIZE: 0xC
		int m_num_particles; //OFS: 0x73C SIZE: 0x4
		int m_num_constraints; //OFS: 0x740 SIZE: 0x4
		int m_num_entity_anchors; //OFS: 0x744 SIZE: 0x4
		int m_num_draw_verts; //OFS: 0x748 SIZE: 0x4
		rope_client_verts_t m_client_verts; //OFS: 0x74C SIZE: 0x4BC
		vec3_t m_min; //OFS: 0xC08 SIZE: 0xC
		vec3_t m_max; //OFS: 0xC14 SIZE: 0xC
		vec3_t m_start; //OFS: 0xC20 SIZE: 0xC
		vec3_t m_end; //OFS: 0xC2C SIZE: 0xC
		int m_in_use; //OFS: 0xC38 SIZE: 0x4
		int m_visible; //OFS: 0xC3C SIZE: 0x4
		int m_dist_constraint; //OFS: 0xC40 SIZE: 0x4
		int m_flags; //OFS: 0xC44 SIZE: 0x4
		const Material* m_material; //OFS: 0xC48 SIZE: 0x4
		float m_seglen; //OFS: 0xC4C SIZE: 0x4
		float m_length; //OFS: 0xC50 SIZE: 0x4
		float m_width; //OFS: 0xC54 SIZE: 0x4
		float m_scale; //OFS: 0xC58 SIZE: 0x4
		float m_force_scale; //OFS: 0xC5C SIZE: 0x4
		int m_health; //OFS: 0xC60 SIZE: 0x4
		int m_frame; //OFS: 0xC64 SIZE: 0x4
		int m_stable_count; //OFS: 0xC68 SIZE: 0x4
		int m_static_rope; //OFS: 0xC6C SIZE: 0x4
		unsigned __int16 m_lightingHandle; //OFS: 0xC70 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(rope_t, 0xC74);
	ASSERT_STRUCT_OFFSET(rope_t, m_particles, 0x0);
	ASSERT_STRUCT_OFFSET(rope_t, m_constraints, 0x3E8);
	ASSERT_STRUCT_OFFSET(rope_t, m_entity_anchors, 0x730);
	ASSERT_STRUCT_OFFSET(rope_t, m_num_particles, 0x73C);
	ASSERT_STRUCT_OFFSET(rope_t, m_num_constraints, 0x740);
	ASSERT_STRUCT_OFFSET(rope_t, m_num_entity_anchors, 0x744);
	ASSERT_STRUCT_OFFSET(rope_t, m_num_draw_verts, 0x748);
	ASSERT_STRUCT_OFFSET(rope_t, m_client_verts, 0x74C);
	ASSERT_STRUCT_OFFSET(rope_t, m_min, 0xC08);
	ASSERT_STRUCT_OFFSET(rope_t, m_max, 0xC14);
	ASSERT_STRUCT_OFFSET(rope_t, m_start, 0xC20);
	ASSERT_STRUCT_OFFSET(rope_t, m_end, 0xC2C);
	ASSERT_STRUCT_OFFSET(rope_t, m_in_use, 0xC38);
	ASSERT_STRUCT_OFFSET(rope_t, m_visible, 0xC3C);
	ASSERT_STRUCT_OFFSET(rope_t, m_dist_constraint, 0xC40);
	ASSERT_STRUCT_OFFSET(rope_t, m_flags, 0xC44);
	ASSERT_STRUCT_OFFSET(rope_t, m_material, 0xC48);
	ASSERT_STRUCT_OFFSET(rope_t, m_seglen, 0xC4C);
	ASSERT_STRUCT_OFFSET(rope_t, m_length, 0xC50);
	ASSERT_STRUCT_OFFSET(rope_t, m_width, 0xC54);
	ASSERT_STRUCT_OFFSET(rope_t, m_scale, 0xC58);
	ASSERT_STRUCT_OFFSET(rope_t, m_force_scale, 0xC5C);
	ASSERT_STRUCT_OFFSET(rope_t, m_health, 0xC60);
	ASSERT_STRUCT_OFFSET(rope_t, m_frame, 0xC64);
	ASSERT_STRUCT_OFFSET(rope_t, m_stable_count, 0xC68);
	ASSERT_STRUCT_OFFSET(rope_t, m_static_rope, 0xC6C);
	ASSERT_STRUCT_OFFSET(rope_t, m_lightingHandle, 0xC70);

	struct clipMap_t
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		int isInUse; //OFS: 0x4 SIZE: 0x4
		ClipInfo info; //OFS: 0x8 SIZE: 0x48
		ClipInfo* pInfo; //OFS: 0x50 SIZE: 0x4
		unsigned int numStaticModels; //OFS: 0x54 SIZE: 0x4
		cStaticModel_s* staticModelList; //OFS: 0x58 SIZE: 0x4
		unsigned int numNodes; //OFS: 0x5C SIZE: 0x4
		cNode_t* nodes; //OFS: 0x60 SIZE: 0x4
		unsigned int numLeafs; //OFS: 0x64 SIZE: 0x4
		cLeaf_s* leafs; //OFS: 0x68 SIZE: 0x4
		unsigned int vertCount; //OFS: 0x6C SIZE: 0x4
		vec3_t* verts; //OFS: 0x70 SIZE: 0x4
		int triCount; //OFS: 0x74 SIZE: 0x4
		unsigned __int16* triIndices; //OFS: 0x78 SIZE: 0x4
		unsigned __int8* triEdgeIsWalkable; //OFS: 0x7C SIZE: 0x4
		int partitionCount; //OFS: 0x80 SIZE: 0x4
		CollisionPartition* partitions; //OFS: 0x84 SIZE: 0x4
		int aabbTreeCount; //OFS: 0x88 SIZE: 0x4
		CollisionAabbTree* aabbTrees; //OFS: 0x8C SIZE: 0x4
		unsigned int numSubModels; //OFS: 0x90 SIZE: 0x4
		cmodel_t* cmodels; //OFS: 0x94 SIZE: 0x4
		int numClusters; //OFS: 0x98 SIZE: 0x4
		int clusterBytes; //OFS: 0x9C SIZE: 0x4
		unsigned __int8* visibility; //OFS: 0xA0 SIZE: 0x4
		int vised; //OFS: 0xA4 SIZE: 0x4
		MapEnts* mapEnts; //OFS: 0xA8 SIZE: 0x4
		cbrush_t* box_brush; //OFS: 0xAC SIZE: 0x4
		cmodel_t box_model; //OFS: 0xB0 SIZE: 0x4C
		unsigned __int16 originalDynEntCount; //OFS: 0xFC SIZE: 0x2
		unsigned __int16 dynEntCount[4]; //OFS: 0xFE SIZE: 0x8
		DynEntityDef* dynEntDefList[2]; //OFS: 0x108 SIZE: 0x8
		DynEntityPose* dynEntPoseList[2]; //OFS: 0x110 SIZE: 0x8
		DynEntityClient* dynEntClientList[2]; //OFS: 0x118 SIZE: 0x8
		DynEntityServer* dynEntServerList[2]; //OFS: 0x120 SIZE: 0x8
		DynEntityColl* dynEntCollList[4]; //OFS: 0x128 SIZE: 0x10
		int num_constraints; //OFS: 0x138 SIZE: 0x4
		PhysConstraint* constraints; //OFS: 0x13C SIZE: 0x4
		int max_ropes; //OFS: 0x140 SIZE: 0x4
		rope_t* ropes; //OFS: 0x144 SIZE: 0x4
		unsigned int checksum; //OFS: 0x148 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(clipMap_t, 0x14C);
	ASSERT_STRUCT_OFFSET(clipMap_t, name, 0x0);
	ASSERT_STRUCT_OFFSET(clipMap_t, isInUse, 0x4);
	ASSERT_STRUCT_OFFSET(clipMap_t, info, 0x8);
	ASSERT_STRUCT_OFFSET(clipMap_t, pInfo, 0x50);
	ASSERT_STRUCT_OFFSET(clipMap_t, numStaticModels, 0x54);
	ASSERT_STRUCT_OFFSET(clipMap_t, staticModelList, 0x58);
	ASSERT_STRUCT_OFFSET(clipMap_t, numNodes, 0x5C);
	ASSERT_STRUCT_OFFSET(clipMap_t, nodes, 0x60);
	ASSERT_STRUCT_OFFSET(clipMap_t, numLeafs, 0x64);
	ASSERT_STRUCT_OFFSET(clipMap_t, leafs, 0x68);
	ASSERT_STRUCT_OFFSET(clipMap_t, vertCount, 0x6C);
	ASSERT_STRUCT_OFFSET(clipMap_t, verts, 0x70);
	ASSERT_STRUCT_OFFSET(clipMap_t, triCount, 0x74);
	ASSERT_STRUCT_OFFSET(clipMap_t, triIndices, 0x78);
	ASSERT_STRUCT_OFFSET(clipMap_t, triEdgeIsWalkable, 0x7C);
	ASSERT_STRUCT_OFFSET(clipMap_t, partitionCount, 0x80);
	ASSERT_STRUCT_OFFSET(clipMap_t, partitions, 0x84);
	ASSERT_STRUCT_OFFSET(clipMap_t, aabbTreeCount, 0x88);
	ASSERT_STRUCT_OFFSET(clipMap_t, aabbTrees, 0x8C);
	ASSERT_STRUCT_OFFSET(clipMap_t, numSubModels, 0x90);
	ASSERT_STRUCT_OFFSET(clipMap_t, cmodels, 0x94);
	ASSERT_STRUCT_OFFSET(clipMap_t, numClusters, 0x98);
	ASSERT_STRUCT_OFFSET(clipMap_t, clusterBytes, 0x9C);
	ASSERT_STRUCT_OFFSET(clipMap_t, visibility, 0xA0);
	ASSERT_STRUCT_OFFSET(clipMap_t, vised, 0xA4);
	ASSERT_STRUCT_OFFSET(clipMap_t, mapEnts, 0xA8);
	ASSERT_STRUCT_OFFSET(clipMap_t, box_brush, 0xAC);
	ASSERT_STRUCT_OFFSET(clipMap_t, box_model, 0xB0);
	ASSERT_STRUCT_OFFSET(clipMap_t, originalDynEntCount, 0xFC);
	ASSERT_STRUCT_OFFSET(clipMap_t, dynEntCount, 0xFE);
	ASSERT_STRUCT_OFFSET(clipMap_t, dynEntDefList, 0x108);
	ASSERT_STRUCT_OFFSET(clipMap_t, dynEntPoseList, 0x110);
	ASSERT_STRUCT_OFFSET(clipMap_t, dynEntClientList, 0x118);
	ASSERT_STRUCT_OFFSET(clipMap_t, dynEntServerList, 0x120);
	ASSERT_STRUCT_OFFSET(clipMap_t, dynEntCollList, 0x128);
	ASSERT_STRUCT_OFFSET(clipMap_t, num_constraints, 0x138);
	ASSERT_STRUCT_OFFSET(clipMap_t, constraints, 0x13C);
	ASSERT_STRUCT_OFFSET(clipMap_t, max_ropes, 0x140);
	ASSERT_STRUCT_OFFSET(clipMap_t, ropes, 0x144);
	ASSERT_STRUCT_OFFSET(clipMap_t, checksum, 0x148);

	struct ComPrimaryLight
	{
		unsigned __int8 type; //OFS: 0x0 SIZE: 0x1
		unsigned __int8 canUseShadowMap; //OFS: 0x1 SIZE: 0x1
		unsigned __int8 exponent; //OFS: 0x2 SIZE: 0x1
		char priority; //OFS: 0x3 SIZE: 0x1
		__int16 cullDist; //OFS: 0x4 SIZE: 0x2
		unsigned __int8 useCookie; //OFS: 0x6 SIZE: 0x1
		unsigned __int8 shadowmapVolume; //OFS: 0x7 SIZE: 0x1
		vec3_t color; //OFS: 0x8 SIZE: 0xC
		vec3_t dir; //OFS: 0x14 SIZE: 0xC
		vec3_t origin; //OFS: 0x20 SIZE: 0xC
		float radius; //OFS: 0x2C SIZE: 0x4
		float cosHalfFovOuter; //OFS: 0x30 SIZE: 0x4
		float cosHalfFovInner; //OFS: 0x34 SIZE: 0x4
		float cosHalfFovExpanded; //OFS: 0x38 SIZE: 0x4
		float rotationLimit; //OFS: 0x3C SIZE: 0x4
		float translationLimit; //OFS: 0x40 SIZE: 0x4
		float mipDistance; //OFS: 0x44 SIZE: 0x4
		float dAttenuation; //OFS: 0x48 SIZE: 0x4
		float roundness; //OFS: 0x4C SIZE: 0x4
		vec4_t diffuseColor; //OFS: 0x50 SIZE: 0x10
		vec4_t falloff; //OFS: 0x60 SIZE: 0x10
		vec4_t angle; //OFS: 0x70 SIZE: 0x10
		vec4_t aAbB; //OFS: 0x80 SIZE: 0x10
		vec4_t cookieControl0; //OFS: 0x90 SIZE: 0x10
		vec4_t cookieControl1; //OFS: 0xA0 SIZE: 0x10
		vec4_t cookieControl2; //OFS: 0xB0 SIZE: 0x10
		const char* defName; //OFS: 0xC0 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(ComPrimaryLight, 0xC4);
	ASSERT_STRUCT_OFFSET(ComPrimaryLight, type, 0x0);
	ASSERT_STRUCT_OFFSET(ComPrimaryLight, canUseShadowMap, 0x1);
	ASSERT_STRUCT_OFFSET(ComPrimaryLight, exponent, 0x2);
	ASSERT_STRUCT_OFFSET(ComPrimaryLight, priority, 0x3);
	ASSERT_STRUCT_OFFSET(ComPrimaryLight, cullDist, 0x4);
	ASSERT_STRUCT_OFFSET(ComPrimaryLight, useCookie, 0x6);
	ASSERT_STRUCT_OFFSET(ComPrimaryLight, shadowmapVolume, 0x7);
	ASSERT_STRUCT_OFFSET(ComPrimaryLight, color, 0x8);
	ASSERT_STRUCT_OFFSET(ComPrimaryLight, dir, 0x14);
	ASSERT_STRUCT_OFFSET(ComPrimaryLight, origin, 0x20);
	ASSERT_STRUCT_OFFSET(ComPrimaryLight, radius, 0x2C);
	ASSERT_STRUCT_OFFSET(ComPrimaryLight, cosHalfFovOuter, 0x30);
	ASSERT_STRUCT_OFFSET(ComPrimaryLight, cosHalfFovInner, 0x34);
	ASSERT_STRUCT_OFFSET(ComPrimaryLight, cosHalfFovExpanded, 0x38);
	ASSERT_STRUCT_OFFSET(ComPrimaryLight, rotationLimit, 0x3C);
	ASSERT_STRUCT_OFFSET(ComPrimaryLight, translationLimit, 0x40);
	ASSERT_STRUCT_OFFSET(ComPrimaryLight, mipDistance, 0x44);
	ASSERT_STRUCT_OFFSET(ComPrimaryLight, dAttenuation, 0x48);
	ASSERT_STRUCT_OFFSET(ComPrimaryLight, roundness, 0x4C);
	ASSERT_STRUCT_OFFSET(ComPrimaryLight, diffuseColor, 0x50);
	ASSERT_STRUCT_OFFSET(ComPrimaryLight, falloff, 0x60);
	ASSERT_STRUCT_OFFSET(ComPrimaryLight, angle, 0x70);
	ASSERT_STRUCT_OFFSET(ComPrimaryLight, aAbB, 0x80);
	ASSERT_STRUCT_OFFSET(ComPrimaryLight, cookieControl0, 0x90);
	ASSERT_STRUCT_OFFSET(ComPrimaryLight, cookieControl1, 0xA0);
	ASSERT_STRUCT_OFFSET(ComPrimaryLight, cookieControl2, 0xB0);
	ASSERT_STRUCT_OFFSET(ComPrimaryLight, defName, 0xC0);

	struct ComWorld
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		int isInUse; //OFS: 0x4 SIZE: 0x4
		unsigned int primaryLightCount; //OFS: 0x8 SIZE: 0x4
		ComPrimaryLight* primaryLights; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(ComWorld, 0x10);
	ASSERT_STRUCT_OFFSET(ComWorld, name, 0x0);
	ASSERT_STRUCT_OFFSET(ComWorld, isInUse, 0x4);
	ASSERT_STRUCT_OFFSET(ComWorld, primaryLightCount, 0x8);
	ASSERT_STRUCT_OFFSET(ComWorld, primaryLights, 0xC);

	struct pathlink_s
	{
		float fDist; //OFS: 0x0 SIZE: 0x4
		unsigned __int16 nodeNum; //OFS: 0x4 SIZE: 0x2
		unsigned __int8 disconnectCount; //OFS: 0x6 SIZE: 0x1
		unsigned __int8 negotiationLink; //OFS: 0x7 SIZE: 0x1
		unsigned __int8 flags; //OFS: 0x8 SIZE: 0x1
		unsigned __int8 ubBadPlaceCount[5]; //OFS: 0x9 SIZE: 0x5
	};
	ASSERT_STRUCT_SIZE(pathlink_s, 0x10);
	ASSERT_STRUCT_OFFSET(pathlink_s, fDist, 0x0);
	ASSERT_STRUCT_OFFSET(pathlink_s, nodeNum, 0x4);
	ASSERT_STRUCT_OFFSET(pathlink_s, disconnectCount, 0x6);
	ASSERT_STRUCT_OFFSET(pathlink_s, negotiationLink, 0x7);
	ASSERT_STRUCT_OFFSET(pathlink_s, flags, 0x8);
	ASSERT_STRUCT_OFFSET(pathlink_s, ubBadPlaceCount, 0x9);

	struct pathnode_constant_t
	{
		nodeType type; //OFS: 0x0 SIZE: 0x4
		int spawnflags; //OFS: 0x4 SIZE: 0x4
		unsigned __int16 targetname; //OFS: 0x8 SIZE: 0x2
		unsigned __int16 script_linkName; //OFS: 0xA SIZE: 0x2
		unsigned __int16 script_noteworthy; //OFS: 0xC SIZE: 0x2
		unsigned __int16 target; //OFS: 0xE SIZE: 0x2
		unsigned __int16 animscript; //OFS: 0x10 SIZE: 0x2
		int animscriptfunc; //OFS: 0x14 SIZE: 0x4
		vec3_t vOrigin; //OFS: 0x18 SIZE: 0xC
		float fAngle; //OFS: 0x24 SIZE: 0x4
		vec2_t forward; //OFS: 0x28 SIZE: 0x8
		float fRadius; //OFS: 0x30 SIZE: 0x4
		float minUseDistSq; //OFS: 0x34 SIZE: 0x4
		__int16 wOverlapNode[2]; //OFS: 0x38 SIZE: 0x4
		unsigned __int16 totalLinkCount; //OFS: 0x3C SIZE: 0x2
		pathlink_s* Links; //OFS: 0x40 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(pathnode_constant_t, 0x44);
	ASSERT_STRUCT_OFFSET(pathnode_constant_t, type, 0x0);
	ASSERT_STRUCT_OFFSET(pathnode_constant_t, spawnflags, 0x4);
	ASSERT_STRUCT_OFFSET(pathnode_constant_t, targetname, 0x8);
	ASSERT_STRUCT_OFFSET(pathnode_constant_t, script_linkName, 0xA);
	ASSERT_STRUCT_OFFSET(pathnode_constant_t, script_noteworthy, 0xC);
	ASSERT_STRUCT_OFFSET(pathnode_constant_t, target, 0xE);
	ASSERT_STRUCT_OFFSET(pathnode_constant_t, animscript, 0x10);
	ASSERT_STRUCT_OFFSET(pathnode_constant_t, animscriptfunc, 0x14);
	ASSERT_STRUCT_OFFSET(pathnode_constant_t, vOrigin, 0x18);
	ASSERT_STRUCT_OFFSET(pathnode_constant_t, fAngle, 0x24);
	ASSERT_STRUCT_OFFSET(pathnode_constant_t, forward, 0x28);
	ASSERT_STRUCT_OFFSET(pathnode_constant_t, fRadius, 0x30);
	ASSERT_STRUCT_OFFSET(pathnode_constant_t, minUseDistSq, 0x34);
	ASSERT_STRUCT_OFFSET(pathnode_constant_t, wOverlapNode, 0x38);
	ASSERT_STRUCT_OFFSET(pathnode_constant_t, totalLinkCount, 0x3C);
	ASSERT_STRUCT_OFFSET(pathnode_constant_t, Links, 0x40);

	struct __declspec(align(2)) SentientHandle
	{
		unsigned __int16 number; //OFS: 0x0 SIZE: 0x2
		unsigned __int16 infoIndex; //OFS: 0x2 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(SentientHandle, 0x4);
	ASSERT_STRUCT_OFFSET(SentientHandle, number, 0x0);
	ASSERT_STRUCT_OFFSET(SentientHandle, infoIndex, 0x2);

	struct pathnode_dynamic_t
	{
		SentientHandle pOwner; //OFS: 0x0 SIZE: 0x4
		int iFreeTime; //OFS: 0x4 SIZE: 0x4
		int iValidTime[3]; //OFS: 0x8 SIZE: 0xC
		int dangerousNodeTime[3]; //OFS: 0x14 SIZE: 0xC
		int inPlayerLOSTime; //OFS: 0x20 SIZE: 0x4
		__int16 wLinkCount; //OFS: 0x24 SIZE: 0x2
		__int16 wOverlapCount; //OFS: 0x26 SIZE: 0x2
		__int16 turretEntNumber; //OFS: 0x28 SIZE: 0x2
		__int16 userCount; //OFS: 0x2A SIZE: 0x2
		bool hasBadPlaceLink; //OFS: 0x2C SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(pathnode_dynamic_t, 0x30);
	ASSERT_STRUCT_OFFSET(pathnode_dynamic_t, pOwner, 0x0);
	ASSERT_STRUCT_OFFSET(pathnode_dynamic_t, iFreeTime, 0x4);
	ASSERT_STRUCT_OFFSET(pathnode_dynamic_t, iValidTime, 0x8);
	ASSERT_STRUCT_OFFSET(pathnode_dynamic_t, dangerousNodeTime, 0x14);
	ASSERT_STRUCT_OFFSET(pathnode_dynamic_t, inPlayerLOSTime, 0x20);
	ASSERT_STRUCT_OFFSET(pathnode_dynamic_t, wLinkCount, 0x24);
	ASSERT_STRUCT_OFFSET(pathnode_dynamic_t, wOverlapCount, 0x26);
	ASSERT_STRUCT_OFFSET(pathnode_dynamic_t, turretEntNumber, 0x28);
	ASSERT_STRUCT_OFFSET(pathnode_dynamic_t, userCount, 0x2A);
	ASSERT_STRUCT_OFFSET(pathnode_dynamic_t, hasBadPlaceLink, 0x2C);

	union $73F238679C0419BE2C31C6559E8604FC
	{
		float nodeCost; //OFS: 0x0 SIZE: 0x4
		int linkIndex; //OFS: 0x1 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE($73F238679C0419BE2C31C6559E8604FC, 0x4);

	struct pathnode_transient_t
	{
		int iSearchFrame; //OFS: 0x0 SIZE: 0x4
		pathnode_t* pNextOpen; //OFS: 0x4 SIZE: 0x4
		pathnode_t* pPrevOpen; //OFS: 0x8 SIZE: 0x4
		pathnode_t* pParent; //OFS: 0xC SIZE: 0x4
		float fCost; //OFS: 0x10 SIZE: 0x4
		float fHeuristic; //OFS: 0x14 SIZE: 0x4
		$73F238679C0419BE2C31C6559E8604FC ___u6; //OFS: 0x18 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(pathnode_transient_t, 0x1C);
	ASSERT_STRUCT_OFFSET(pathnode_transient_t, iSearchFrame, 0x0);
	ASSERT_STRUCT_OFFSET(pathnode_transient_t, pNextOpen, 0x4);
	ASSERT_STRUCT_OFFSET(pathnode_transient_t, pPrevOpen, 0x8);
	ASSERT_STRUCT_OFFSET(pathnode_transient_t, pParent, 0xC);
	ASSERT_STRUCT_OFFSET(pathnode_transient_t, fCost, 0x10);
	ASSERT_STRUCT_OFFSET(pathnode_transient_t, fHeuristic, 0x14);
	ASSERT_STRUCT_OFFSET(pathnode_transient_t, ___u6, 0x18);

	struct pathnode_t
	{
		pathnode_constant_t constant; //OFS: 0x0 SIZE: 0x44
		pathnode_dynamic_t dynamic; //OFS: 0x44 SIZE: 0x30
		pathnode_transient_t transient; //OFS: 0x74 SIZE: 0x1C
	};
	ASSERT_STRUCT_SIZE(pathnode_t, 0x90);
	ASSERT_STRUCT_OFFSET(pathnode_t, constant, 0x0);
	ASSERT_STRUCT_OFFSET(pathnode_t, dynamic, 0x44);
	ASSERT_STRUCT_OFFSET(pathnode_t, transient, 0x74);

	struct pathbasenode_t
	{
		vec3_t vOrigin; //OFS: 0x0 SIZE: 0xC
		unsigned int type; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(pathbasenode_t, 0x10);
	ASSERT_STRUCT_OFFSET(pathbasenode_t, vOrigin, 0x0);
	ASSERT_STRUCT_OFFSET(pathbasenode_t, type, 0xC);

	struct pathnode_tree_nodes_t
	{
		int nodeCount; //OFS: 0x0 SIZE: 0x4
		unsigned __int16* nodes; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(pathnode_tree_nodes_t, 0x8);
	ASSERT_STRUCT_OFFSET(pathnode_tree_nodes_t, nodeCount, 0x0);
	ASSERT_STRUCT_OFFSET(pathnode_tree_nodes_t, nodes, 0x4);

	union pathnode_tree_info_t
	{
		pathnode_tree_t* child[2]; //OFS: 0x0 SIZE: 0x8
		pathnode_tree_nodes_t s; //OFS: 0x1 SIZE: 0x8
	};
	ASSERT_STRUCT_SIZE(pathnode_tree_info_t, 0x8);

	struct pathnode_tree_t
	{
		int axis; //OFS: 0x0 SIZE: 0x4
		float dist; //OFS: 0x4 SIZE: 0x4
		pathnode_tree_info_t u; //OFS: 0x8 SIZE: 0x8
	};
	ASSERT_STRUCT_SIZE(pathnode_tree_t, 0x10);
	ASSERT_STRUCT_OFFSET(pathnode_tree_t, axis, 0x0);
	ASSERT_STRUCT_OFFSET(pathnode_tree_t, dist, 0x4);
	ASSERT_STRUCT_OFFSET(pathnode_tree_t, u, 0x8);

	struct PathData
	{
		unsigned int nodeCount; //OFS: 0x0 SIZE: 0x4
		unsigned int originalNodeCount; //OFS: 0x4 SIZE: 0x4
		pathnode_t* nodes; //OFS: 0x8 SIZE: 0x4
		pathbasenode_t* basenodes; //OFS: 0xC SIZE: 0x4
		int visBytes; //OFS: 0x10 SIZE: 0x4
		unsigned __int8* pathVis; //OFS: 0x14 SIZE: 0x4
		int smoothBytes; //OFS: 0x18 SIZE: 0x4
		unsigned __int8* smoothCache; //OFS: 0x1C SIZE: 0x4
		int nodeTreeCount; //OFS: 0x20 SIZE: 0x4
		pathnode_tree_t* nodeTree; //OFS: 0x24 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(PathData, 0x28);
	ASSERT_STRUCT_OFFSET(PathData, nodeCount, 0x0);
	ASSERT_STRUCT_OFFSET(PathData, originalNodeCount, 0x4);
	ASSERT_STRUCT_OFFSET(PathData, nodes, 0x8);
	ASSERT_STRUCT_OFFSET(PathData, basenodes, 0xC);
	ASSERT_STRUCT_OFFSET(PathData, visBytes, 0x10);
	ASSERT_STRUCT_OFFSET(PathData, pathVis, 0x14);
	ASSERT_STRUCT_OFFSET(PathData, smoothBytes, 0x18);
	ASSERT_STRUCT_OFFSET(PathData, smoothCache, 0x1C);
	ASSERT_STRUCT_OFFSET(PathData, nodeTreeCount, 0x20);
	ASSERT_STRUCT_OFFSET(PathData, nodeTree, 0x24);

	struct GameWorldSp
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		PathData path; //OFS: 0x4 SIZE: 0x28
	};
	ASSERT_STRUCT_SIZE(GameWorldSp, 0x2C);
	ASSERT_STRUCT_OFFSET(GameWorldSp, name, 0x0);
	ASSERT_STRUCT_OFFSET(GameWorldSp, path, 0x4);

	struct GameWorldMp
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		PathData path; //OFS: 0x4 SIZE: 0x28
	};
	ASSERT_STRUCT_SIZE(GameWorldMp, 0x2C);
	ASSERT_STRUCT_OFFSET(GameWorldMp, name, 0x0);
	ASSERT_STRUCT_OFFSET(GameWorldMp, path, 0x4);

	struct GfxStreamingAabbTree
	{
		vec4_t mins; //OFS: 0x0 SIZE: 0x10
		vec4_t maxs; //OFS: 0x10 SIZE: 0x10
		float maxStreamingDistance; //OFS: 0x20 SIZE: 0x4
		unsigned __int16 firstItem; //OFS: 0x24 SIZE: 0x2
		unsigned __int16 itemCount; //OFS: 0x26 SIZE: 0x2
		unsigned __int16 firstChild; //OFS: 0x28 SIZE: 0x2
		unsigned __int16 childCount; //OFS: 0x2A SIZE: 0x2
		unsigned __int16 smodelCount; //OFS: 0x2C SIZE: 0x2
		unsigned __int16 surfaceCount; //OFS: 0x2E SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(GfxStreamingAabbTree, 0x30);
	ASSERT_STRUCT_OFFSET(GfxStreamingAabbTree, mins, 0x0);
	ASSERT_STRUCT_OFFSET(GfxStreamingAabbTree, maxs, 0x10);
	ASSERT_STRUCT_OFFSET(GfxStreamingAabbTree, maxStreamingDistance, 0x20);
	ASSERT_STRUCT_OFFSET(GfxStreamingAabbTree, firstItem, 0x24);
	ASSERT_STRUCT_OFFSET(GfxStreamingAabbTree, itemCount, 0x26);
	ASSERT_STRUCT_OFFSET(GfxStreamingAabbTree, firstChild, 0x28);
	ASSERT_STRUCT_OFFSET(GfxStreamingAabbTree, childCount, 0x2A);
	ASSERT_STRUCT_OFFSET(GfxStreamingAabbTree, smodelCount, 0x2C);
	ASSERT_STRUCT_OFFSET(GfxStreamingAabbTree, surfaceCount, 0x2E);

	struct GfxWorldStreamInfo
	{
		int aabbTreeCount; //OFS: 0x0 SIZE: 0x4
		GfxStreamingAabbTree* aabbTrees; //OFS: 0x4 SIZE: 0x4
		int leafRefCount; //OFS: 0x8 SIZE: 0x4
		int* leafRefs; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxWorldStreamInfo, 0x10);
	ASSERT_STRUCT_OFFSET(GfxWorldStreamInfo, aabbTreeCount, 0x0);
	ASSERT_STRUCT_OFFSET(GfxWorldStreamInfo, aabbTrees, 0x4);
	ASSERT_STRUCT_OFFSET(GfxWorldStreamInfo, leafRefCount, 0x8);
	ASSERT_STRUCT_OFFSET(GfxWorldStreamInfo, leafRefs, 0xC);

	struct GfxWorldSun
	{
		unsigned int control; //OFS: 0x0 SIZE: 0x4
		vec3_t angles; //OFS: 0x4 SIZE: 0xC
		vec4_t ambientColor; //OFS: 0x10 SIZE: 0x10
		vec4_t sunCd; //OFS: 0x20 SIZE: 0x10
		vec4_t sunCs; //OFS: 0x30 SIZE: 0x10
		vec4_t skyColor; //OFS: 0x40 SIZE: 0x10
		float exposure; //OFS: 0x50 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxWorldSun, 0x54);
	ASSERT_STRUCT_OFFSET(GfxWorldSun, control, 0x0);
	ASSERT_STRUCT_OFFSET(GfxWorldSun, angles, 0x4);
	ASSERT_STRUCT_OFFSET(GfxWorldSun, ambientColor, 0x10);
	ASSERT_STRUCT_OFFSET(GfxWorldSun, sunCd, 0x20);
	ASSERT_STRUCT_OFFSET(GfxWorldSun, sunCs, 0x30);
	ASSERT_STRUCT_OFFSET(GfxWorldSun, skyColor, 0x40);
	ASSERT_STRUCT_OFFSET(GfxWorldSun, exposure, 0x50);

	struct GfxWorldFog
	{
		float baseDist; //OFS: 0x0 SIZE: 0x4
		float halfDist; //OFS: 0x4 SIZE: 0x4
		float baseHeight; //OFS: 0x8 SIZE: 0x4
		float halfHeight; //OFS: 0xC SIZE: 0x4
		float sunFogPitch; //OFS: 0x10 SIZE: 0x4
		float sunFogYaw; //OFS: 0x14 SIZE: 0x4
		float sunFogInner; //OFS: 0x18 SIZE: 0x4
		float sunFogOuter; //OFS: 0x1C SIZE: 0x4
		vec3_t fogColor; //OFS: 0x20 SIZE: 0xC
		float fogOpacity; //OFS: 0x2C SIZE: 0x4
		vec3_t sunFogColor; //OFS: 0x30 SIZE: 0xC
		float sunFogOpacity; //OFS: 0x3C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxWorldFog, 0x40);
	ASSERT_STRUCT_OFFSET(GfxWorldFog, baseDist, 0x0);
	ASSERT_STRUCT_OFFSET(GfxWorldFog, halfDist, 0x4);
	ASSERT_STRUCT_OFFSET(GfxWorldFog, baseHeight, 0x8);
	ASSERT_STRUCT_OFFSET(GfxWorldFog, halfHeight, 0xC);
	ASSERT_STRUCT_OFFSET(GfxWorldFog, sunFogPitch, 0x10);
	ASSERT_STRUCT_OFFSET(GfxWorldFog, sunFogYaw, 0x14);
	ASSERT_STRUCT_OFFSET(GfxWorldFog, sunFogInner, 0x18);
	ASSERT_STRUCT_OFFSET(GfxWorldFog, sunFogOuter, 0x1C);
	ASSERT_STRUCT_OFFSET(GfxWorldFog, fogColor, 0x20);
	ASSERT_STRUCT_OFFSET(GfxWorldFog, fogOpacity, 0x2C);
	ASSERT_STRUCT_OFFSET(GfxWorldFog, sunFogColor, 0x30);
	ASSERT_STRUCT_OFFSET(GfxWorldFog, sunFogOpacity, 0x3C);

	struct SunLightParseParams
	{
		char name[64]; //OFS: 0x0 SIZE: 0x40
		GfxWorldSun initWorldSun[1]; //OFS: 0x40 SIZE: 0x54
		float fogTransitionTime; //OFS: 0x94 SIZE: 0x4
		GfxWorldFog initWorldFog[1]; //OFS: 0x98 SIZE: 0x40
	};
	ASSERT_STRUCT_SIZE(SunLightParseParams, 0xD8);
	ASSERT_STRUCT_OFFSET(SunLightParseParams, name, 0x0);
	ASSERT_STRUCT_OFFSET(SunLightParseParams, initWorldSun, 0x40);
	ASSERT_STRUCT_OFFSET(SunLightParseParams, fogTransitionTime, 0x94);
	ASSERT_STRUCT_OFFSET(SunLightParseParams, initWorldFog, 0x98);

	union $9AACA8D77F0583C0373C04B0A9342BB6
	{
		vec4_t m[4]; //OFS: 0x0 SIZE: 0x40
		float member[16]; //OFS: 0x1 SIZE: 0x40
	};
	ASSERT_STRUCT_SIZE($9AACA8D77F0583C0373C04B0A9342BB6, 0x40);

	struct float44
	{
		$9AACA8D77F0583C0373C04B0A9342BB6 ___u0; //OFS: 0x0 SIZE: 0x40
	};
	ASSERT_STRUCT_SIZE(float44, 0x40);
	ASSERT_STRUCT_OFFSET(float44, ___u0, 0x0);

	struct GfxLightImage
	{
		GfxImage* image; //OFS: 0x0 SIZE: 0x4
		unsigned __int8 samplerState; //OFS: 0x4 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(GfxLightImage, 0x8);
	ASSERT_STRUCT_OFFSET(GfxLightImage, image, 0x0);
	ASSERT_STRUCT_OFFSET(GfxLightImage, samplerState, 0x4);

	struct GfxLightDef
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		GfxLightImage attenuation; //OFS: 0x4 SIZE: 0x8
		int lmapLookupStart; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxLightDef, 0x10);
	ASSERT_STRUCT_OFFSET(GfxLightDef, name, 0x0);
	ASSERT_STRUCT_OFFSET(GfxLightDef, attenuation, 0x4);
	ASSERT_STRUCT_OFFSET(GfxLightDef, lmapLookupStart, 0xC);

	struct GfxLight
	{
		unsigned __int8 type; //OFS: 0x0 SIZE: 0x1
		unsigned __int8 canUseShadowMap; //OFS: 0x1 SIZE: 0x1
		unsigned __int8 shadowmapVolume; //OFS: 0x2 SIZE: 0x1
		__int16 cullDist; //OFS: 0x4 SIZE: 0x2
		vec3_t color; //OFS: 0x8 SIZE: 0xC
		vec3_t dir; //OFS: 0x14 SIZE: 0xC
		vec3_t origin; //OFS: 0x20 SIZE: 0xC
		float radius; //OFS: 0x2C SIZE: 0x4
		float cosHalfFovOuter; //OFS: 0x30 SIZE: 0x4
		float cosHalfFovInner; //OFS: 0x34 SIZE: 0x4
		int exponent; //OFS: 0x38 SIZE: 0x4
		unsigned int spotShadowIndex; //OFS: 0x3C SIZE: 0x4
		float dAttenuation; //OFS: 0x40 SIZE: 0x4
		float roundness; //OFS: 0x44 SIZE: 0x4
		vec3_t angles; //OFS: 0x48 SIZE: 0xC
		float spotShadowHiDistance; //OFS: 0x54 SIZE: 0x4
		vec4_t diffuseColor; //OFS: 0x58 SIZE: 0x10
		vec4_t shadowColor; //OFS: 0x68 SIZE: 0x10
		vec4_t falloff; //OFS: 0x78 SIZE: 0x10
		vec4_t aAbB; //OFS: 0x88 SIZE: 0x10
		vec4_t cookieControl0; //OFS: 0x98 SIZE: 0x10
		vec4_t cookieControl1; //OFS: 0xA8 SIZE: 0x10
		vec4_t cookieControl2; //OFS: 0xB8 SIZE: 0x10
		char pad[8];
		float44 viewMatrix;
		float44 projMatrix;
		GfxLightDef* def;
		char pad2[10];
	};
	ASSERT_STRUCT_SIZE(GfxLight, 0x160);
	ASSERT_STRUCT_OFFSET(GfxLight, type, 0x0);
	ASSERT_STRUCT_OFFSET(GfxLight, canUseShadowMap, 0x1);
	ASSERT_STRUCT_OFFSET(GfxLight, shadowmapVolume, 0x2);
	ASSERT_STRUCT_OFFSET(GfxLight, cullDist, 0x4);
	ASSERT_STRUCT_OFFSET(GfxLight, color, 0x8);
	ASSERT_STRUCT_OFFSET(GfxLight, dir, 0x14);
	ASSERT_STRUCT_OFFSET(GfxLight, origin, 0x20);
	ASSERT_STRUCT_OFFSET(GfxLight, radius, 0x2C);
	ASSERT_STRUCT_OFFSET(GfxLight, cosHalfFovOuter, 0x30);
	ASSERT_STRUCT_OFFSET(GfxLight, cosHalfFovInner, 0x34);
	ASSERT_STRUCT_OFFSET(GfxLight, exponent, 0x38);
	ASSERT_STRUCT_OFFSET(GfxLight, spotShadowIndex, 0x3C);
	ASSERT_STRUCT_OFFSET(GfxLight, dAttenuation, 0x40);
	ASSERT_STRUCT_OFFSET(GfxLight, roundness, 0x44);
	ASSERT_STRUCT_OFFSET(GfxLight, angles, 0x48);
	ASSERT_STRUCT_OFFSET(GfxLight, spotShadowHiDistance, 0x54);
	ASSERT_STRUCT_OFFSET(GfxLight, diffuseColor, 0x58);
	ASSERT_STRUCT_OFFSET(GfxLight, shadowColor, 0x68);
	ASSERT_STRUCT_OFFSET(GfxLight, falloff, 0x78);
	ASSERT_STRUCT_OFFSET(GfxLight, aAbB, 0x88);
	ASSERT_STRUCT_OFFSET(GfxLight, cookieControl0, 0x98);
	ASSERT_STRUCT_OFFSET(GfxLight, cookieControl1, 0xA8);
	ASSERT_STRUCT_OFFSET(GfxLight, cookieControl2, 0xB8);
	ASSERT_STRUCT_OFFSET(GfxLight, viewMatrix, 0xD0);
	ASSERT_STRUCT_OFFSET(GfxLight, projMatrix, 0x110);
	ASSERT_STRUCT_OFFSET(GfxLight, def, 0x150);

	struct GfxLightCorona
	{
		vec3_t origin; //OFS: 0x0 SIZE: 0xC
		float radius; //OFS: 0xC SIZE: 0x4
		vec3_t color; //OFS: 0x10 SIZE: 0xC
		float intensity; //OFS: 0x1C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxLightCorona, 0x20);
	ASSERT_STRUCT_OFFSET(GfxLightCorona, origin, 0x0);
	ASSERT_STRUCT_OFFSET(GfxLightCorona, radius, 0xC);
	ASSERT_STRUCT_OFFSET(GfxLightCorona, color, 0x10);
	ASSERT_STRUCT_OFFSET(GfxLightCorona, intensity, 0x1C);

	struct GfxShadowMapVolume
	{
		unsigned int control; //OFS: 0x0 SIZE: 0x4
		unsigned int padding1; //OFS: 0x4 SIZE: 0x4
		unsigned int padding2; //OFS: 0x8 SIZE: 0x4
		unsigned int padding3; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxShadowMapVolume, 0x10);
	ASSERT_STRUCT_OFFSET(GfxShadowMapVolume, control, 0x0);
	ASSERT_STRUCT_OFFSET(GfxShadowMapVolume, padding1, 0x4);
	ASSERT_STRUCT_OFFSET(GfxShadowMapVolume, padding2, 0x8);
	ASSERT_STRUCT_OFFSET(GfxShadowMapVolume, padding3, 0xC);

	struct GfxVolumePlane
	{
		vec4_t plane; //OFS: 0x0 SIZE: 0x10
	};
	ASSERT_STRUCT_SIZE(GfxVolumePlane, 0x10);
	ASSERT_STRUCT_OFFSET(GfxVolumePlane, plane, 0x0);

	struct GfxExposureVolume
	{
		unsigned int control; //OFS: 0x0 SIZE: 0x4
		float exposure; //OFS: 0x4 SIZE: 0x4
		float luminanceIncreaseScale; //OFS: 0x8 SIZE: 0x4
		float luminanceDecreaseScale; //OFS: 0xC SIZE: 0x4
		float featherRange; //OFS: 0x10 SIZE: 0x4
		float featherAdjust; //OFS: 0x14 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxExposureVolume, 0x18);
	ASSERT_STRUCT_OFFSET(GfxExposureVolume, control, 0x0);
	ASSERT_STRUCT_OFFSET(GfxExposureVolume, exposure, 0x4);
	ASSERT_STRUCT_OFFSET(GfxExposureVolume, luminanceIncreaseScale, 0x8);
	ASSERT_STRUCT_OFFSET(GfxExposureVolume, luminanceDecreaseScale, 0xC);
	ASSERT_STRUCT_OFFSET(GfxExposureVolume, featherRange, 0x10);
	ASSERT_STRUCT_OFFSET(GfxExposureVolume, featherAdjust, 0x14);

	struct GfxWorldFogVolume
	{
		vec3_t mins; //OFS: 0x0 SIZE: 0xC
		unsigned int control; //OFS: 0xC SIZE: 0x4
		vec3_t maxs; //OFS: 0x10 SIZE: 0xC
		float fogTransitionTime; //OFS: 0x1C SIZE: 0x4
		unsigned int controlEx; //OFS: 0x20 SIZE: 0x4
		GfxWorldFog volumeWorldFog[1]; //OFS: 0x24 SIZE: 0x40
	};
	ASSERT_STRUCT_SIZE(GfxWorldFogVolume, 0x64);
	ASSERT_STRUCT_OFFSET(GfxWorldFogVolume, mins, 0x0);
	ASSERT_STRUCT_OFFSET(GfxWorldFogVolume, control, 0xC);
	ASSERT_STRUCT_OFFSET(GfxWorldFogVolume, maxs, 0x10);
	ASSERT_STRUCT_OFFSET(GfxWorldFogVolume, fogTransitionTime, 0x1C);
	ASSERT_STRUCT_OFFSET(GfxWorldFogVolume, controlEx, 0x20);
	ASSERT_STRUCT_OFFSET(GfxWorldFogVolume, volumeWorldFog, 0x24);

	struct GfxWorldFogModifierVolume
	{
		unsigned int control; //OFS: 0x0 SIZE: 0x4
		unsigned __int16 minX; //OFS: 0x4 SIZE: 0x2
		unsigned __int16 minY; //OFS: 0x6 SIZE: 0x2
		unsigned __int16 minZ; //OFS: 0x8 SIZE: 0x2
		unsigned __int16 maxX; //OFS: 0xA SIZE: 0x2
		unsigned __int16 maxY; //OFS: 0xC SIZE: 0x2
		unsigned __int16 maxZ; //OFS: 0xE SIZE: 0x2
		unsigned int controlEx; //OFS: 0x10 SIZE: 0x4
		float transitionTime; //OFS: 0x14 SIZE: 0x4
		float depthScale; //OFS: 0x18 SIZE: 0x4
		float heightScale; //OFS: 0x1C SIZE: 0x4
		vec4_t colorAdjust; //OFS: 0x20 SIZE: 0x10
	};
	ASSERT_STRUCT_SIZE(GfxWorldFogModifierVolume, 0x30);
	ASSERT_STRUCT_OFFSET(GfxWorldFogModifierVolume, control, 0x0);
	ASSERT_STRUCT_OFFSET(GfxWorldFogModifierVolume, minX, 0x4);
	ASSERT_STRUCT_OFFSET(GfxWorldFogModifierVolume, minY, 0x6);
	ASSERT_STRUCT_OFFSET(GfxWorldFogModifierVolume, minZ, 0x8);
	ASSERT_STRUCT_OFFSET(GfxWorldFogModifierVolume, maxX, 0xA);
	ASSERT_STRUCT_OFFSET(GfxWorldFogModifierVolume, maxY, 0xC);
	ASSERT_STRUCT_OFFSET(GfxWorldFogModifierVolume, maxZ, 0xE);
	ASSERT_STRUCT_OFFSET(GfxWorldFogModifierVolume, controlEx, 0x10);
	ASSERT_STRUCT_OFFSET(GfxWorldFogModifierVolume, transitionTime, 0x14);
	ASSERT_STRUCT_OFFSET(GfxWorldFogModifierVolume, depthScale, 0x18);
	ASSERT_STRUCT_OFFSET(GfxWorldFogModifierVolume, heightScale, 0x1C);
	ASSERT_STRUCT_OFFSET(GfxWorldFogModifierVolume, colorAdjust, 0x20);

	struct GfxLutVolume
	{
		vec3_t mins; //OFS: 0x0 SIZE: 0xC
		unsigned int control; //OFS: 0xC SIZE: 0x4
		vec3_t maxs; //OFS: 0x10 SIZE: 0xC
		float lutTransitionTime; //OFS: 0x1C SIZE: 0x4
		unsigned int lutIndex; //OFS: 0x20 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxLutVolume, 0x24);
	ASSERT_STRUCT_OFFSET(GfxLutVolume, mins, 0x0);
	ASSERT_STRUCT_OFFSET(GfxLutVolume, control, 0xC);
	ASSERT_STRUCT_OFFSET(GfxLutVolume, maxs, 0x10);
	ASSERT_STRUCT_OFFSET(GfxLutVolume, lutTransitionTime, 0x1C);
	ASSERT_STRUCT_OFFSET(GfxLutVolume, lutIndex, 0x20);

	struct GfxSkyDynamicIntensity
	{
		float angle0; //OFS: 0x0 SIZE: 0x4
		float angle1; //OFS: 0x4 SIZE: 0x4
		float factor0; //OFS: 0x8 SIZE: 0x4
		float factor1; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxSkyDynamicIntensity, 0x10);
	ASSERT_STRUCT_OFFSET(GfxSkyDynamicIntensity, angle0, 0x0);
	ASSERT_STRUCT_OFFSET(GfxSkyDynamicIntensity, angle1, 0x4);
	ASSERT_STRUCT_OFFSET(GfxSkyDynamicIntensity, factor0, 0x8);
	ASSERT_STRUCT_OFFSET(GfxSkyDynamicIntensity, factor1, 0xC);

	struct GfxWorldDpvsPlanes
	{
		int cellCount; //OFS: 0x0 SIZE: 0x4
		cplane_s* planes; //OFS: 0x4 SIZE: 0x4
		unsigned __int16* nodes; //OFS: 0x8 SIZE: 0x4
		unsigned int* sceneEntCellBits; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxWorldDpvsPlanes, 0x10);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsPlanes, cellCount, 0x0);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsPlanes, planes, 0x4);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsPlanes, nodes, 0x8);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsPlanes, sceneEntCellBits, 0xC);

	struct GfxAabbTree
	{
		vec3_t mins; //OFS: 0x0 SIZE: 0xC
		vec3_t maxs; //OFS: 0xC SIZE: 0xC
		unsigned __int16 childCount; //OFS: 0x18 SIZE: 0x2
		unsigned __int16 surfaceCount; //OFS: 0x1A SIZE: 0x2
		unsigned __int16 startSurfIndex; //OFS: 0x1C SIZE: 0x2
		unsigned __int16 smodelIndexCount; //OFS: 0x1E SIZE: 0x2
		unsigned __int16* smodelIndexes; //OFS: 0x20 SIZE: 0x4
		int childrenOffset; //OFS: 0x24 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxAabbTree, 0x28);
	ASSERT_STRUCT_OFFSET(GfxAabbTree, mins, 0x0);
	ASSERT_STRUCT_OFFSET(GfxAabbTree, maxs, 0xC);
	ASSERT_STRUCT_OFFSET(GfxAabbTree, childCount, 0x18);
	ASSERT_STRUCT_OFFSET(GfxAabbTree, surfaceCount, 0x1A);
	ASSERT_STRUCT_OFFSET(GfxAabbTree, startSurfIndex, 0x1C);
	ASSERT_STRUCT_OFFSET(GfxAabbTree, smodelIndexCount, 0x1E);
	ASSERT_STRUCT_OFFSET(GfxAabbTree, smodelIndexes, 0x20);
	ASSERT_STRUCT_OFFSET(GfxAabbTree, childrenOffset, 0x24);

	struct GfxPortalWritable
	{
		bool isQueued; //OFS: 0x0 SIZE: 0x1
		bool isAncestor; //OFS: 0x1 SIZE: 0x1
		unsigned __int8 recursionDepth; //OFS: 0x2 SIZE: 0x1
		unsigned __int8 hullPointCount; //OFS: 0x3 SIZE: 0x1
		vec2_t* hullPoints; //OFS: 0x4 SIZE: 0x4
		GfxPortal* queuedParent; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxPortalWritable, 0xC);
	ASSERT_STRUCT_OFFSET(GfxPortalWritable, isQueued, 0x0);
	ASSERT_STRUCT_OFFSET(GfxPortalWritable, isAncestor, 0x1);
	ASSERT_STRUCT_OFFSET(GfxPortalWritable, recursionDepth, 0x2);
	ASSERT_STRUCT_OFFSET(GfxPortalWritable, hullPointCount, 0x3);
	ASSERT_STRUCT_OFFSET(GfxPortalWritable, hullPoints, 0x4);
	ASSERT_STRUCT_OFFSET(GfxPortalWritable, queuedParent, 0x8);

	struct DpvsPlane
	{
		vec4_t coeffs; //OFS: 0x0 SIZE: 0x10
		unsigned __int8 side[3]; //OFS: 0x10 SIZE: 0x3
		unsigned __int8 pad; //OFS: 0x13 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(DpvsPlane, 0x14);
	ASSERT_STRUCT_OFFSET(DpvsPlane, coeffs, 0x0);
	ASSERT_STRUCT_OFFSET(DpvsPlane, side, 0x10);
	ASSERT_STRUCT_OFFSET(DpvsPlane, pad, 0x13);

	struct GfxPortal
	{
		GfxPortalWritable writable; //OFS: 0x0 SIZE: 0xC
		DpvsPlane plane; //OFS: 0xC SIZE: 0x14
		GfxCell* cell; //OFS: 0x20 SIZE: 0x4
		vec3_t* vertices; //OFS: 0x24 SIZE: 0x4
		unsigned __int8 vertexCount; //OFS: 0x28 SIZE: 0x1
		vec3_t hullAxis[2]; //OFS: 0x2C SIZE: 0x18
		vec3_t bounds[2]; //OFS: 0x44 SIZE: 0x18
	};
	ASSERT_STRUCT_SIZE(GfxPortal, 0x5C);
	ASSERT_STRUCT_OFFSET(GfxPortal, writable, 0x0);
	ASSERT_STRUCT_OFFSET(GfxPortal, plane, 0xC);
	ASSERT_STRUCT_OFFSET(GfxPortal, cell, 0x20);
	ASSERT_STRUCT_OFFSET(GfxPortal, vertices, 0x24);
	ASSERT_STRUCT_OFFSET(GfxPortal, vertexCount, 0x28);
	ASSERT_STRUCT_OFFSET(GfxPortal, hullAxis, 0x2C);
	ASSERT_STRUCT_OFFSET(GfxPortal, bounds, 0x44);

	struct GfxCell
	{
		vec3_t mins; //OFS: 0x0 SIZE: 0xC
		vec3_t maxs; //OFS: 0xC SIZE: 0xC
		int aabbTreeCount; //OFS: 0x18 SIZE: 0x4
		GfxAabbTree* aabbTree; //OFS: 0x1C SIZE: 0x4
		int portalCount; //OFS: 0x20 SIZE: 0x4
		GfxPortal* portals; //OFS: 0x24 SIZE: 0x4
		unsigned __int8 reflectionProbeCount; //OFS: 0x28 SIZE: 0x1
		unsigned __int8* reflectionProbes; //OFS: 0x2C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxCell, 0x30);
	ASSERT_STRUCT_OFFSET(GfxCell, mins, 0x0);
	ASSERT_STRUCT_OFFSET(GfxCell, maxs, 0xC);
	ASSERT_STRUCT_OFFSET(GfxCell, aabbTreeCount, 0x18);
	ASSERT_STRUCT_OFFSET(GfxCell, aabbTree, 0x1C);
	ASSERT_STRUCT_OFFSET(GfxCell, portalCount, 0x20);
	ASSERT_STRUCT_OFFSET(GfxCell, portals, 0x24);
	ASSERT_STRUCT_OFFSET(GfxCell, reflectionProbeCount, 0x28);
	ASSERT_STRUCT_OFFSET(GfxCell, reflectionProbes, 0x2C);

	struct GfxLightingSH
	{
		vec4_t V0; //OFS: 0x0 SIZE: 0x10
		vec4_t V1; //OFS: 0x10 SIZE: 0x10
		vec4_t V2; //OFS: 0x20 SIZE: 0x10
	};
	ASSERT_STRUCT_SIZE(GfxLightingSH, 0x30);
	ASSERT_STRUCT_OFFSET(GfxLightingSH, V0, 0x0);
	ASSERT_STRUCT_OFFSET(GfxLightingSH, V1, 0x10);
	ASSERT_STRUCT_OFFSET(GfxLightingSH, V2, 0x20);

	struct GfxReflectionProbeVolumeData
	{
		vec4_t volumePlanes[6]; //OFS: 0x0 SIZE: 0x60
	};
	ASSERT_STRUCT_SIZE(GfxReflectionProbeVolumeData, 0x60);
	ASSERT_STRUCT_OFFSET(GfxReflectionProbeVolumeData, volumePlanes, 0x0);

	struct GfxReflectionProbe
	{
		vec3_t origin; //OFS: 0x0 SIZE: 0xC
		GfxLightingSH lightingSH; //OFS: 0xC SIZE: 0x30
		GfxImage* reflectionImage; //OFS: 0x3C SIZE: 0x4
		GfxReflectionProbeVolumeData* probeVolumes; //OFS: 0x40 SIZE: 0x4
		unsigned int probeVolumeCount; //OFS: 0x44 SIZE: 0x4
		float mipLodBias; //OFS: 0x48 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxReflectionProbe, 0x4C);
	ASSERT_STRUCT_OFFSET(GfxReflectionProbe, origin, 0x0);
	ASSERT_STRUCT_OFFSET(GfxReflectionProbe, lightingSH, 0xC);
	ASSERT_STRUCT_OFFSET(GfxReflectionProbe, reflectionImage, 0x3C);
	ASSERT_STRUCT_OFFSET(GfxReflectionProbe, probeVolumes, 0x40);
	ASSERT_STRUCT_OFFSET(GfxReflectionProbe, probeVolumeCount, 0x44);
	ASSERT_STRUCT_OFFSET(GfxReflectionProbe, mipLodBias, 0x48);

	union $E9CAF76207D4E18BFAEAB74F9A0388A5
	{
		GfxReflectionProbe* localReflectionProbes; //OFS: 0x0 SIZE: 0x4
		GfxReflectionProbe* reflectionProbes; //OFS: 0x1 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE($E9CAF76207D4E18BFAEAB74F9A0388A5, 0x4);

	union $0C154162D624C03998BF2D76D7C461A7
	{
		GfxTexture* localReflectionProbeTextures; //OFS: 0x0 SIZE: 0x4
		GfxTexture* reflectionProbeTextures; //OFS: 0x1 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE($0C154162D624C03998BF2D76D7C461A7, 0x4);

	struct GfxLightmapArray
	{
		GfxImage* primary; //OFS: 0x0 SIZE: 0x4
		GfxImage* secondary; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxLightmapArray, 0x8);
	ASSERT_STRUCT_OFFSET(GfxLightmapArray, primary, 0x0);
	ASSERT_STRUCT_OFFSET(GfxLightmapArray, secondary, 0x4);

	union $1BF0B2674E235DA68BB7ED1EFC3D429C
	{
		GfxLightmapArray* localLightmaps; //OFS: 0x0 SIZE: 0x4
		GfxLightmapArray* lightmaps; //OFS: 0x1 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE($1BF0B2674E235DA68BB7ED1EFC3D429C, 0x4);

	union $2C36C8709DD5BDA147136C7746F79D97
	{
		GfxTexture* localLightmapPrimaryTextures; //OFS: 0x0 SIZE: 0x4
		GfxTexture* lightmapPrimaryTextures; //OFS: 0x1 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE($2C36C8709DD5BDA147136C7746F79D97, 0x4);

	union $901B6FEAA0E8DA4DCF2242949681F3F9
	{
		GfxTexture* localLightmapSecondaryTextures; //OFS: 0x0 SIZE: 0x4
		GfxTexture* lightmapSecondaryTextures; //OFS: 0x1 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE($901B6FEAA0E8DA4DCF2242949681F3F9, 0x4);

	struct GfxWorldVertexData0
	{
		unsigned __int8* data; //OFS: 0x0 SIZE: 0x4
		ID3D11Buffer* vb; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxWorldVertexData0, 0x8);
	ASSERT_STRUCT_OFFSET(GfxWorldVertexData0, data, 0x0);
	ASSERT_STRUCT_OFFSET(GfxWorldVertexData0, vb, 0x4);

	struct GfxWorldVertexData1
	{
		unsigned __int8* data; //OFS: 0x0 SIZE: 0x4
		ID3D11Buffer* vb; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxWorldVertexData1, 0x8);
	ASSERT_STRUCT_OFFSET(GfxWorldVertexData1, data, 0x0);
	ASSERT_STRUCT_OFFSET(GfxWorldVertexData1, vb, 0x4);

	struct GfxWorldDraw
	{
		unsigned int reflectionProbeCount; //OFS: 0x0 SIZE: 0x4
		$E9CAF76207D4E18BFAEAB74F9A0388A5 ___u1; //OFS: 0x4 SIZE: 0x4
		$0C154162D624C03998BF2D76D7C461A7 ___u2; //OFS: 0x8 SIZE: 0x4
		int lightmapCount; //OFS: 0xC SIZE: 0x4
		$1BF0B2674E235DA68BB7ED1EFC3D429C ___u4; //OFS: 0x10 SIZE: 0x4
		$2C36C8709DD5BDA147136C7746F79D97 ___u5; //OFS: 0x14 SIZE: 0x4
		$901B6FEAA0E8DA4DCF2242949681F3F9 ___u6; //OFS: 0x18 SIZE: 0x4
		unsigned int vertexCount; //OFS: 0x1C SIZE: 0x4
		unsigned int vertexDataSize0; //OFS: 0x20 SIZE: 0x4
		GfxWorldVertexData0 vd0; //OFS: 0x24 SIZE: 0x8
		unsigned int vertexDataSize1; //OFS: 0x2C SIZE: 0x4
		GfxWorldVertexData1 vd1; //OFS: 0x30 SIZE: 0x8
		int indexCount; //OFS: 0x38 SIZE: 0x4
		unsigned __int16* indices; //OFS: 0x3C SIZE: 0x4
		ID3D11Buffer* indexBuffer; //OFS: 0x40 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxWorldDraw, 0x44);
	ASSERT_STRUCT_OFFSET(GfxWorldDraw, reflectionProbeCount, 0x0);
	ASSERT_STRUCT_OFFSET(GfxWorldDraw, ___u1, 0x4);
	ASSERT_STRUCT_OFFSET(GfxWorldDraw, ___u2, 0x8);
	ASSERT_STRUCT_OFFSET(GfxWorldDraw, lightmapCount, 0xC);
	ASSERT_STRUCT_OFFSET(GfxWorldDraw, ___u4, 0x10);
	ASSERT_STRUCT_OFFSET(GfxWorldDraw, ___u5, 0x14);
	ASSERT_STRUCT_OFFSET(GfxWorldDraw, ___u6, 0x18);
	ASSERT_STRUCT_OFFSET(GfxWorldDraw, vertexCount, 0x1C);
	ASSERT_STRUCT_OFFSET(GfxWorldDraw, vertexDataSize0, 0x20);
	ASSERT_STRUCT_OFFSET(GfxWorldDraw, vd0, 0x24);
	ASSERT_STRUCT_OFFSET(GfxWorldDraw, vertexDataSize1, 0x2C);
	ASSERT_STRUCT_OFFSET(GfxWorldDraw, vd1, 0x30);
	ASSERT_STRUCT_OFFSET(GfxWorldDraw, indexCount, 0x38);
	ASSERT_STRUCT_OFFSET(GfxWorldDraw, indices, 0x3C);
	ASSERT_STRUCT_OFFSET(GfxWorldDraw, indexBuffer, 0x40);

	struct __declspec(align(2)) GfxLightGridEntry
	{
		unsigned __int16 colorsIndex; //OFS: 0x0 SIZE: 0x2
		unsigned __int8 primaryLightIndex; //OFS: 0x2 SIZE: 0x1
		unsigned __int8 visibility; //OFS: 0x3 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(GfxLightGridEntry, 0x4);
	ASSERT_STRUCT_OFFSET(GfxLightGridEntry, colorsIndex, 0x0);
	ASSERT_STRUCT_OFFSET(GfxLightGridEntry, primaryLightIndex, 0x2);
	ASSERT_STRUCT_OFFSET(GfxLightGridEntry, visibility, 0x3);

	struct __declspec(align(1)) GfxCompressedLightGridColors
	{
		unsigned __int8 rgb[56][3]; //OFS: 0x0 SIZE: 0xA8
	};
	ASSERT_STRUCT_SIZE(GfxCompressedLightGridColors, 0xA8);
	ASSERT_STRUCT_OFFSET(GfxCompressedLightGridColors, rgb, 0x0);

	struct __declspec(align(2)) GfxCompressedLightGridCoeffs
	{
		unsigned __int16 coeffs[9][3]; //OFS: 0x0 SIZE: 0x36
	};
	ASSERT_STRUCT_SIZE(GfxCompressedLightGridCoeffs, 0x36);
	ASSERT_STRUCT_OFFSET(GfxCompressedLightGridCoeffs, coeffs, 0x0);

	struct GfxSkyGridVolume
	{
		vec3_t mins; //OFS: 0x0 SIZE: 0xC
		vec3_t maxs; //OFS: 0xC SIZE: 0xC
		vec3_t lightingOrigin; //OFS: 0x18 SIZE: 0xC
		unsigned __int16 colorsIndex; //OFS: 0x24 SIZE: 0x2
		unsigned __int8 primaryLightIndex; //OFS: 0x26 SIZE: 0x1
		unsigned __int8 visibility; //OFS: 0x27 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(GfxSkyGridVolume, 0x28);
	ASSERT_STRUCT_OFFSET(GfxSkyGridVolume, mins, 0x0);
	ASSERT_STRUCT_OFFSET(GfxSkyGridVolume, maxs, 0xC);
	ASSERT_STRUCT_OFFSET(GfxSkyGridVolume, lightingOrigin, 0x18);
	ASSERT_STRUCT_OFFSET(GfxSkyGridVolume, colorsIndex, 0x24);
	ASSERT_STRUCT_OFFSET(GfxSkyGridVolume, primaryLightIndex, 0x26);
	ASSERT_STRUCT_OFFSET(GfxSkyGridVolume, visibility, 0x27);

	struct GfxLightGrid
	{
		unsigned int sunPrimaryLightIndex; //OFS: 0x0 SIZE: 0x4
		unsigned __int16 mins[3]; //OFS: 0x4 SIZE: 0x6
		unsigned __int16 maxs[3]; //OFS: 0xA SIZE: 0x6
		float offset; //OFS: 0x10 SIZE: 0x4
		unsigned int rowAxis; //OFS: 0x14 SIZE: 0x4
		unsigned int colAxis; //OFS: 0x18 SIZE: 0x4
		unsigned __int16* rowDataStart; //OFS: 0x1C SIZE: 0x4
		unsigned int rawRowDataSize; //OFS: 0x20 SIZE: 0x4
		unsigned __int8* rawRowData; //OFS: 0x24 SIZE: 0x4
		unsigned int entryCount; //OFS: 0x28 SIZE: 0x4
		GfxLightGridEntry* entries; //OFS: 0x2C SIZE: 0x4
		unsigned int colorCount; //OFS: 0x30 SIZE: 0x4
		GfxCompressedLightGridColors* colors; //OFS: 0x34 SIZE: 0x4
		unsigned int coeffCount; //OFS: 0x38 SIZE: 0x4
		GfxCompressedLightGridCoeffs* coeffs; //OFS: 0x3C SIZE: 0x4
		unsigned int skyGridVolumeCount; //OFS: 0x40 SIZE: 0x4
		GfxSkyGridVolume* skyGridVolumes; //OFS: 0x44 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxLightGrid, 0x48);
	ASSERT_STRUCT_OFFSET(GfxLightGrid, sunPrimaryLightIndex, 0x0);
	ASSERT_STRUCT_OFFSET(GfxLightGrid, mins, 0x4);
	ASSERT_STRUCT_OFFSET(GfxLightGrid, maxs, 0xA);
	ASSERT_STRUCT_OFFSET(GfxLightGrid, offset, 0x10);
	ASSERT_STRUCT_OFFSET(GfxLightGrid, rowAxis, 0x14);
	ASSERT_STRUCT_OFFSET(GfxLightGrid, colAxis, 0x18);
	ASSERT_STRUCT_OFFSET(GfxLightGrid, rowDataStart, 0x1C);
	ASSERT_STRUCT_OFFSET(GfxLightGrid, rawRowDataSize, 0x20);
	ASSERT_STRUCT_OFFSET(GfxLightGrid, rawRowData, 0x24);
	ASSERT_STRUCT_OFFSET(GfxLightGrid, entryCount, 0x28);
	ASSERT_STRUCT_OFFSET(GfxLightGrid, entries, 0x2C);
	ASSERT_STRUCT_OFFSET(GfxLightGrid, colorCount, 0x30);
	ASSERT_STRUCT_OFFSET(GfxLightGrid, colors, 0x34);
	ASSERT_STRUCT_OFFSET(GfxLightGrid, coeffCount, 0x38);
	ASSERT_STRUCT_OFFSET(GfxLightGrid, coeffs, 0x3C);
	ASSERT_STRUCT_OFFSET(GfxLightGrid, skyGridVolumeCount, 0x40);
	ASSERT_STRUCT_OFFSET(GfxLightGrid, skyGridVolumes, 0x44);

	struct GfxBrushModelWritable
	{
		vec3_t mins; //OFS: 0x0 SIZE: 0xC
		float padding1; //OFS: 0xC SIZE: 0x4
		vec3_t maxs; //OFS: 0x10 SIZE: 0xC
		float padding2; //OFS: 0x1C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxBrushModelWritable, 0x20);
	ASSERT_STRUCT_OFFSET(GfxBrushModelWritable, mins, 0x0);
	ASSERT_STRUCT_OFFSET(GfxBrushModelWritable, padding1, 0xC);
	ASSERT_STRUCT_OFFSET(GfxBrushModelWritable, maxs, 0x10);
	ASSERT_STRUCT_OFFSET(GfxBrushModelWritable, padding2, 0x1C);

	struct GfxBrushModel
	{
		GfxBrushModelWritable writable; //OFS: 0x0 SIZE: 0x20
		vec3_t bounds[2]; //OFS: 0x20 SIZE: 0x18
		unsigned int surfaceCount; //OFS: 0x38 SIZE: 0x4
		unsigned int startSurfIndex; //OFS: 0x3C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxBrushModel, 0x40);
	ASSERT_STRUCT_OFFSET(GfxBrushModel, writable, 0x0);
	ASSERT_STRUCT_OFFSET(GfxBrushModel, bounds, 0x20);
	ASSERT_STRUCT_OFFSET(GfxBrushModel, surfaceCount, 0x38);
	ASSERT_STRUCT_OFFSET(GfxBrushModel, startSurfIndex, 0x3C);

	struct MaterialMemory
	{
		Material* material; //OFS: 0x0 SIZE: 0x4
		int memory; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(MaterialMemory, 0x8);
	ASSERT_STRUCT_OFFSET(MaterialMemory, material, 0x0);
	ASSERT_STRUCT_OFFSET(MaterialMemory, memory, 0x4);

	struct sunflare_t
	{
		bool hasValidData; //OFS: 0x0 SIZE: 0x1
		Material* spriteMaterial; //OFS: 0x4 SIZE: 0x4
		Material* flareMaterial; //OFS: 0x8 SIZE: 0x4
		float spriteSize; //OFS: 0xC SIZE: 0x4
		float flareMinSize; //OFS: 0x10 SIZE: 0x4
		float flareMinDot; //OFS: 0x14 SIZE: 0x4
		float flareMaxSize; //OFS: 0x18 SIZE: 0x4
		float flareMaxDot; //OFS: 0x1C SIZE: 0x4
		float flareMaxAlpha; //OFS: 0x20 SIZE: 0x4
		int flareFadeInTime; //OFS: 0x24 SIZE: 0x4
		int flareFadeOutTime; //OFS: 0x28 SIZE: 0x4
		float blindMinDot; //OFS: 0x2C SIZE: 0x4
		float blindMaxDot; //OFS: 0x30 SIZE: 0x4
		float blindMaxDarken; //OFS: 0x34 SIZE: 0x4
		int blindFadeInTime; //OFS: 0x38 SIZE: 0x4
		int blindFadeOutTime; //OFS: 0x3C SIZE: 0x4
		float glareMinDot; //OFS: 0x40 SIZE: 0x4
		float glareMaxDot; //OFS: 0x44 SIZE: 0x4
		float glareMaxLighten; //OFS: 0x48 SIZE: 0x4
		int glareFadeInTime; //OFS: 0x4C SIZE: 0x4
		int glareFadeOutTime; //OFS: 0x50 SIZE: 0x4
		vec3_t sunFxPosition; //OFS: 0x54 SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(sunflare_t, 0x60);
	ASSERT_STRUCT_OFFSET(sunflare_t, hasValidData, 0x0);
	ASSERT_STRUCT_OFFSET(sunflare_t, spriteMaterial, 0x4);
	ASSERT_STRUCT_OFFSET(sunflare_t, flareMaterial, 0x8);
	ASSERT_STRUCT_OFFSET(sunflare_t, spriteSize, 0xC);
	ASSERT_STRUCT_OFFSET(sunflare_t, flareMinSize, 0x10);
	ASSERT_STRUCT_OFFSET(sunflare_t, flareMinDot, 0x14);
	ASSERT_STRUCT_OFFSET(sunflare_t, flareMaxSize, 0x18);
	ASSERT_STRUCT_OFFSET(sunflare_t, flareMaxDot, 0x1C);
	ASSERT_STRUCT_OFFSET(sunflare_t, flareMaxAlpha, 0x20);
	ASSERT_STRUCT_OFFSET(sunflare_t, flareFadeInTime, 0x24);
	ASSERT_STRUCT_OFFSET(sunflare_t, flareFadeOutTime, 0x28);
	ASSERT_STRUCT_OFFSET(sunflare_t, blindMinDot, 0x2C);
	ASSERT_STRUCT_OFFSET(sunflare_t, blindMaxDot, 0x30);
	ASSERT_STRUCT_OFFSET(sunflare_t, blindMaxDarken, 0x34);
	ASSERT_STRUCT_OFFSET(sunflare_t, blindFadeInTime, 0x38);
	ASSERT_STRUCT_OFFSET(sunflare_t, blindFadeOutTime, 0x3C);
	ASSERT_STRUCT_OFFSET(sunflare_t, glareMinDot, 0x40);
	ASSERT_STRUCT_OFFSET(sunflare_t, glareMaxDot, 0x44);
	ASSERT_STRUCT_OFFSET(sunflare_t, glareMaxLighten, 0x48);
	ASSERT_STRUCT_OFFSET(sunflare_t, glareFadeInTime, 0x4C);
	ASSERT_STRUCT_OFFSET(sunflare_t, glareFadeOutTime, 0x50);
	ASSERT_STRUCT_OFFSET(sunflare_t, sunFxPosition, 0x54);

	struct __declspec(align(2)) $35B54DACFB25E6634BE25ECADBFCE1AF
	{
		unsigned __int8 state; //OFS: 0x0 SIZE: 0x1
		char lod; //OFS: 0x1 SIZE: 0x1
		unsigned __int16 surfId; //OFS: 0x2 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE($35B54DACFB25E6634BE25ECADBFCE1AF, 0x4);
	ASSERT_STRUCT_OFFSET($35B54DACFB25E6634BE25ECADBFCE1AF, state, 0x0);
	ASSERT_STRUCT_OFFSET($35B54DACFB25E6634BE25ECADBFCE1AF, lod, 0x1);
	ASSERT_STRUCT_OFFSET($35B54DACFB25E6634BE25ECADBFCE1AF, surfId, 0x2);

	union XModelDrawInfo
	{
		$35B54DACFB25E6634BE25ECADBFCE1AF __s0; //OFS: 0x0 SIZE: 0x4
		unsigned int packed; //OFS: 0x1 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(XModelDrawInfo, 0x4);

	struct GfxSceneDynModel
	{
		XModelDrawInfo info; //OFS: 0x0 SIZE: 0x4
		unsigned __int16 dynEntId; //OFS: 0x4 SIZE: 0x2
		unsigned __int8 primaryLightIndex; //OFS: 0x6 SIZE: 0x1
		unsigned __int8 reflectionProbeIndex; //OFS: 0x7 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(GfxSceneDynModel, 0x8);
	ASSERT_STRUCT_OFFSET(GfxSceneDynModel, info, 0x0);
	ASSERT_STRUCT_OFFSET(GfxSceneDynModel, dynEntId, 0x4);
	ASSERT_STRUCT_OFFSET(GfxSceneDynModel, primaryLightIndex, 0x6);
	ASSERT_STRUCT_OFFSET(GfxSceneDynModel, reflectionProbeIndex, 0x7);

	struct __declspec(align(2)) BModelDrawInfo
	{
		unsigned __int16 surfId; //OFS: 0x0 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(BModelDrawInfo, 0x2);
	ASSERT_STRUCT_OFFSET(BModelDrawInfo, surfId, 0x0);

	struct __declspec(align(2)) GfxSceneDynBrush
	{
		BModelDrawInfo info; //OFS: 0x0 SIZE: 0x2
		unsigned __int16 dynEntId; //OFS: 0x2 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(GfxSceneDynBrush, 0x4);
	ASSERT_STRUCT_OFFSET(GfxSceneDynBrush, info, 0x0);
	ASSERT_STRUCT_OFFSET(GfxSceneDynBrush, dynEntId, 0x2);

	union __m128
	{
		float m128_f32[4]; //OFS: 0x0 SIZE: 0x10
		unsigned __int64 m128_u64[2]; //OFS: 0x1 SIZE: 0x10
		char m128_i8[16]; //OFS: 0x2 SIZE: 0x10
		__int16 m128_i16[8]; //OFS: 0x3 SIZE: 0x10
		int m128_i32[4]; //OFS: 0x4 SIZE: 0x10
		__int64 m128_i64[2]; //OFS: 0x5 SIZE: 0x10
		unsigned __int8 m128_u8[16]; //OFS: 0x6 SIZE: 0x10
		unsigned __int16 m128_u16[8]; //OFS: 0x7 SIZE: 0x10
		unsigned int m128_u32[4]; //OFS: 0x8 SIZE: 0x10
	};
	ASSERT_STRUCT_SIZE(__m128, 0x10);

	struct __declspec(align(16)) vector3
	{
		__m128 x; //OFS: 0x0 SIZE: 0x10
		__m128 y; //OFS: 0x10 SIZE: 0x10
		__m128 z; //OFS: 0x20 SIZE: 0x10
	};
	ASSERT_STRUCT_SIZE(vector3, 0x30);
	ASSERT_STRUCT_OFFSET(vector3, x, 0x0);
	ASSERT_STRUCT_OFFSET(vector3, y, 0x10);
	ASSERT_STRUCT_OFFSET(vector3, z, 0x20);

	struct __declspec(align(16)) vector4
	{
		vector3 baseclass_0; //OFS: 0x0 SIZE: 0x30
		__m128 w; //OFS: 0x30 SIZE: 0x10
	};
	ASSERT_STRUCT_SIZE(vector4, 0x40);
	ASSERT_STRUCT_OFFSET(vector4, baseclass_0, 0x0);
	ASSERT_STRUCT_OFFSET(vector4, w, 0x30);

	union $C40D9503F948761F4E9C66F9D1E59BF2
	{
		vector4 mat; //OFS: 0x0 SIZE: 0x40
		float disk_mat[16]; //OFS: 0x1 SIZE: 0x40
	};
	ASSERT_STRUCT_SIZE($C40D9503F948761F4E9C66F9D1E59BF2, 0x40);

	struct SSkinShaders
	{
		char* pixelShaderAlign; //OFS: 0x0 SIZE: 0x4
		char* pixelShader; //OFS: 0x4 SIZE: 0x4
		char* vertexShader; //OFS: 0x8 SIZE: 0x4
		int pixelShaderSize; //OFS: 0xC SIZE: 0x4
		int vertexShaderSize; //OFS: 0x10 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(SSkinShaders, 0x14);
	ASSERT_STRUCT_OFFSET(SSkinShaders, pixelShaderAlign, 0x0);
	ASSERT_STRUCT_OFFSET(SSkinShaders, pixelShader, 0x4);
	ASSERT_STRUCT_OFFSET(SSkinShaders, vertexShader, 0x8);
	ASSERT_STRUCT_OFFSET(SSkinShaders, pixelShaderSize, 0xC);
	ASSERT_STRUCT_OFFSET(SSkinShaders, vertexShaderSize, 0x10);

	struct __declspec(align(2)) half
	{
		unsigned __int16 v; //OFS: 0x0 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(half, 0x2);
	ASSERT_STRUCT_OFFSET(half, v, 0x0);

	struct __declspec(align(2)) $749465FE09F6B5AA86CFA3B719B18C52
	{
		half x; //OFS: 0x0 SIZE: 0x2
		half y; //OFS: 0x2 SIZE: 0x2
		half z; //OFS: 0x4 SIZE: 0x2
		half w; //OFS: 0x6 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE($749465FE09F6B5AA86CFA3B719B18C52, 0x8);
	ASSERT_STRUCT_OFFSET($749465FE09F6B5AA86CFA3B719B18C52, x, 0x0);
	ASSERT_STRUCT_OFFSET($749465FE09F6B5AA86CFA3B719B18C52, y, 0x2);
	ASSERT_STRUCT_OFFSET($749465FE09F6B5AA86CFA3B719B18C52, z, 0x4);
	ASSERT_STRUCT_OFFSET($749465FE09F6B5AA86CFA3B719B18C52, w, 0x6);

	union $E98D1066E6B5821BBA41C34B8DE3FBCC
	{
		$749465FE09F6B5AA86CFA3B719B18C52 __s0; //OFS: 0x0 SIZE: 0x8
		unsigned __int64 v; //OFS: 0x1 SIZE: 0x8
	};
	ASSERT_STRUCT_SIZE($E98D1066E6B5821BBA41C34B8DE3FBCC, 0x8);

	struct __declspec(align(8)) half4
	{
		$E98D1066E6B5821BBA41C34B8DE3FBCC ___u0; //OFS: 0x0 SIZE: 0x8
	};
	ASSERT_STRUCT_SIZE(half4, 0x8);
	ASSERT_STRUCT_OFFSET(half4, ___u0, 0x0);

	struct __declspec(align(2)) $0A448BE62E917ADBBD6F3F24D03B59C8
	{
		half x; //OFS: 0x0 SIZE: 0x2
		half y; //OFS: 0x2 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE($0A448BE62E917ADBBD6F3F24D03B59C8, 0x4);
	ASSERT_STRUCT_OFFSET($0A448BE62E917ADBBD6F3F24D03B59C8, x, 0x0);
	ASSERT_STRUCT_OFFSET($0A448BE62E917ADBBD6F3F24D03B59C8, y, 0x2);

	union $5AF4F59236CB1F68FB73292C18415124
	{
		$0A448BE62E917ADBBD6F3F24D03B59C8 __s0; //OFS: 0x0 SIZE: 0x4
		unsigned int v; //OFS: 0x1 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE($5AF4F59236CB1F68FB73292C18415124, 0x4);

	struct half2
	{
		$5AF4F59236CB1F68FB73292C18415124 ___u0; //OFS: 0x0 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(half2, 0x4);
	ASSERT_STRUCT_OFFSET(half2, ___u0, 0x0);

	struct __declspec(align(8)) SSkinVert
	{
		half4 pos_bone; //OFS: 0x0 SIZE: 0x8
		PackedUnitVec normal; //OFS: 0x8 SIZE: 0x4
		half2 uv; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(SSkinVert, 0x10);
	ASSERT_STRUCT_OFFSET(SSkinVert, pos_bone, 0x0);
	ASSERT_STRUCT_OFFSET(SSkinVert, normal, 0x8);
	ASSERT_STRUCT_OFFSET(SSkinVert, uv, 0xC);

	struct SSkinModel
	{
		int numVerts; //OFS: 0x0 SIZE: 0x4
		int numTris; //OFS: 0x4 SIZE: 0x4
		SSkinVert* verts; //OFS: 0x8 SIZE: 0x4
		unsigned __int16* tris; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(SSkinModel, 0x10);
	ASSERT_STRUCT_OFFSET(SSkinModel, numVerts, 0x0);
	ASSERT_STRUCT_OFFSET(SSkinModel, numTris, 0x4);
	ASSERT_STRUCT_OFFSET(SSkinModel, verts, 0x8);
	ASSERT_STRUCT_OFFSET(SSkinModel, tris, 0xC);

	struct SSkinAnim
	{
		int bones; //OFS: 0x0 SIZE: 0x4
		int width; //OFS: 0x4 SIZE: 0x4
		int frames; //OFS: 0x8 SIZE: 0x4
		float* data; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(SSkinAnim, 0x10);
	ASSERT_STRUCT_OFFSET(SSkinAnim, bones, 0x0);
	ASSERT_STRUCT_OFFSET(SSkinAnim, width, 0x4);
	ASSERT_STRUCT_OFFSET(SSkinAnim, frames, 0x8);
	ASSERT_STRUCT_OFFSET(SSkinAnim, data, 0xC);

	struct __declspec(align(16)) SSkinInstance
	{
		$C40D9503F948761F4E9C66F9D1E59BF2 ___u0; //OFS: 0x0 SIZE: 0x40
		SSkinShaders* shaders; //OFS: 0x40 SIZE: 0x4
		SSkinModel* model; //OFS: 0x44 SIZE: 0x4
		SSkinAnim* anim; //OFS: 0x48 SIZE: 0x4
		SSkinVert* instVerts; //OFS: 0x4C SIZE: 0x4
		float frame; //OFS: 0x50 SIZE: 0x4
		int pad1; //OFS: 0x54 SIZE: 0x4
		int pad2; //OFS: 0x58 SIZE: 0x4
		int pad3; //OFS: 0x5C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(SSkinInstance, 0x60);
	ASSERT_STRUCT_OFFSET(SSkinInstance, ___u0, 0x0);
	ASSERT_STRUCT_OFFSET(SSkinInstance, shaders, 0x40);
	ASSERT_STRUCT_OFFSET(SSkinInstance, model, 0x44);
	ASSERT_STRUCT_OFFSET(SSkinInstance, anim, 0x48);
	ASSERT_STRUCT_OFFSET(SSkinInstance, instVerts, 0x4C);
	ASSERT_STRUCT_OFFSET(SSkinInstance, frame, 0x50);
	ASSERT_STRUCT_OFFSET(SSkinInstance, pad1, 0x54);
	ASSERT_STRUCT_OFFSET(SSkinInstance, pad2, 0x58);
	ASSERT_STRUCT_OFFSET(SSkinInstance, pad3, 0x5C);

	struct GfxShadowGeometry
	{
		unsigned __int16 surfaceCount; //OFS: 0x0 SIZE: 0x2
		unsigned __int16 smodelCount; //OFS: 0x2 SIZE: 0x2
		unsigned __int16* sortedSurfIndex; //OFS: 0x4 SIZE: 0x4
		unsigned __int16* smodelIndex; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxShadowGeometry, 0xC);
	ASSERT_STRUCT_OFFSET(GfxShadowGeometry, surfaceCount, 0x0);
	ASSERT_STRUCT_OFFSET(GfxShadowGeometry, smodelCount, 0x2);
	ASSERT_STRUCT_OFFSET(GfxShadowGeometry, sortedSurfIndex, 0x4);
	ASSERT_STRUCT_OFFSET(GfxShadowGeometry, smodelIndex, 0x8);

	struct GfxLightRegionAxis
	{
		vec3_t dir; //OFS: 0x0 SIZE: 0xC
		float midPoint; //OFS: 0xC SIZE: 0x4
		float halfSize; //OFS: 0x10 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxLightRegionAxis, 0x14);
	ASSERT_STRUCT_OFFSET(GfxLightRegionAxis, dir, 0x0);
	ASSERT_STRUCT_OFFSET(GfxLightRegionAxis, midPoint, 0xC);
	ASSERT_STRUCT_OFFSET(GfxLightRegionAxis, halfSize, 0x10);

	struct GfxLightRegionHull
	{
		float kdopMidPoint[9]; //OFS: 0x0 SIZE: 0x24
		float kdopHalfSize[9]; //OFS: 0x24 SIZE: 0x24
		unsigned int axisCount; //OFS: 0x48 SIZE: 0x4
		GfxLightRegionAxis* axis; //OFS: 0x4C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxLightRegionHull, 0x50);
	ASSERT_STRUCT_OFFSET(GfxLightRegionHull, kdopMidPoint, 0x0);
	ASSERT_STRUCT_OFFSET(GfxLightRegionHull, kdopHalfSize, 0x24);
	ASSERT_STRUCT_OFFSET(GfxLightRegionHull, axisCount, 0x48);
	ASSERT_STRUCT_OFFSET(GfxLightRegionHull, axis, 0x4C);

	struct GfxLightRegion
	{
		unsigned int hullCount; //OFS: 0x0 SIZE: 0x4
		GfxLightRegionHull* hulls; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxLightRegion, 0x8);
	ASSERT_STRUCT_OFFSET(GfxLightRegion, hullCount, 0x0);
	ASSERT_STRUCT_OFFSET(GfxLightRegion, hulls, 0x4);

	struct GfxStaticModelInst
	{
		vec3_t mins; //OFS: 0x0 SIZE: 0xC
		vec3_t maxs; //OFS: 0xC SIZE: 0xC
		vec3_t lightingOrigin; //OFS: 0x18 SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(GfxStaticModelInst, 0x24);
	ASSERT_STRUCT_OFFSET(GfxStaticModelInst, mins, 0x0);
	ASSERT_STRUCT_OFFSET(GfxStaticModelInst, maxs, 0xC);
	ASSERT_STRUCT_OFFSET(GfxStaticModelInst, lightingOrigin, 0x18);

	struct srfTriangles_t
	{
		vec3_t mins; //OFS: 0x0 SIZE: 0xC
		int vertexDataOffset0; //OFS: 0xC SIZE: 0x4
		vec3_t maxs; //OFS: 0x10 SIZE: 0xC
		int vertexDataOffset1; //OFS: 0x1C SIZE: 0x4
		int firstVertex; //OFS: 0x20 SIZE: 0x4
		float himipRadiusInvSq; //OFS: 0x24 SIZE: 0x4
		unsigned __int16 vertexCount; //OFS: 0x28 SIZE: 0x2
		unsigned __int16 triCount; //OFS: 0x2A SIZE: 0x2
		int baseIndex; //OFS: 0x2C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(srfTriangles_t, 0x30);
	ASSERT_STRUCT_OFFSET(srfTriangles_t, mins, 0x0);
	ASSERT_STRUCT_OFFSET(srfTriangles_t, vertexDataOffset0, 0xC);
	ASSERT_STRUCT_OFFSET(srfTriangles_t, maxs, 0x10);
	ASSERT_STRUCT_OFFSET(srfTriangles_t, vertexDataOffset1, 0x1C);
	ASSERT_STRUCT_OFFSET(srfTriangles_t, firstVertex, 0x20);
	ASSERT_STRUCT_OFFSET(srfTriangles_t, himipRadiusInvSq, 0x24);
	ASSERT_STRUCT_OFFSET(srfTriangles_t, vertexCount, 0x28);
	ASSERT_STRUCT_OFFSET(srfTriangles_t, triCount, 0x2A);
	ASSERT_STRUCT_OFFSET(srfTriangles_t, baseIndex, 0x2C);

	struct GfxSurface
	{
		srfTriangles_t tris; //OFS: 0x0 SIZE: 0x30
		Material* material; //OFS: 0x30 SIZE: 0x4
		unsigned __int8 lightmapIndex; //OFS: 0x34 SIZE: 0x1
		unsigned __int8 reflectionProbeIndex; //OFS: 0x35 SIZE: 0x1
		unsigned __int8 primaryLightIndex; //OFS: 0x36 SIZE: 0x1
		unsigned __int8 flags; //OFS: 0x37 SIZE: 0x1
		vec3_t bounds[2]; //OFS: 0x38 SIZE: 0x18
	};
	ASSERT_STRUCT_SIZE(GfxSurface, 0x50);
	ASSERT_STRUCT_OFFSET(GfxSurface, tris, 0x0);
	ASSERT_STRUCT_OFFSET(GfxSurface, material, 0x30);
	ASSERT_STRUCT_OFFSET(GfxSurface, lightmapIndex, 0x34);
	ASSERT_STRUCT_OFFSET(GfxSurface, reflectionProbeIndex, 0x35);
	ASSERT_STRUCT_OFFSET(GfxSurface, primaryLightIndex, 0x36);
	ASSERT_STRUCT_OFFSET(GfxSurface, flags, 0x37);
	ASSERT_STRUCT_OFFSET(GfxSurface, bounds, 0x38);

	struct GfxPackedPlacement
	{
		vec3_t origin; //OFS: 0x0 SIZE: 0xC
		vec3_t axis[3]; //OFS: 0xC SIZE: 0x24
		float scale; //OFS: 0x30 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxPackedPlacement, 0x34);
	ASSERT_STRUCT_OFFSET(GfxPackedPlacement, origin, 0x0);
	ASSERT_STRUCT_OFFSET(GfxPackedPlacement, axis, 0xC);
	ASSERT_STRUCT_OFFSET(GfxPackedPlacement, scale, 0x30);

	struct __declspec(align(2)) GfxLightingSHQuantized
	{
		unsigned __int16 V0[4]; //OFS: 0x0 SIZE: 0x8
		unsigned __int16 V1[4]; //OFS: 0x8 SIZE: 0x8
		unsigned __int16 V2[4]; //OFS: 0x10 SIZE: 0x8
	};
	ASSERT_STRUCT_SIZE(GfxLightingSHQuantized, 0x18);
	ASSERT_STRUCT_OFFSET(GfxLightingSHQuantized, V0, 0x0);
	ASSERT_STRUCT_OFFSET(GfxLightingSHQuantized, V1, 0x8);
	ASSERT_STRUCT_OFFSET(GfxLightingSHQuantized, V2, 0x10);

	struct GfxStaticModelLmapVertexInfo
	{
		unsigned int* lmapVertexColors; //OFS: 0x0 SIZE: 0x4
		ID3D11Buffer* lmapVertexColorsVB; //OFS: 0x4 SIZE: 0x4
		unsigned __int16 numLmapVertexColors; //OFS: 0x8 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(GfxStaticModelLmapVertexInfo, 0xC);
	ASSERT_STRUCT_OFFSET(GfxStaticModelLmapVertexInfo, lmapVertexColors, 0x0);
	ASSERT_STRUCT_OFFSET(GfxStaticModelLmapVertexInfo, lmapVertexColorsVB, 0x4);
	ASSERT_STRUCT_OFFSET(GfxStaticModelLmapVertexInfo, numLmapVertexColors, 0x8);

	struct GfxStaticModelDrawInst
	{
		float cullDist; //OFS: 0x0 SIZE: 0x4
		GfxPackedPlacement placement; //OFS: 0x4 SIZE: 0x34
		XModel* model; //OFS: 0x38 SIZE: 0x4
		int flags; //OFS: 0x3C SIZE: 0x4
		float invScaleSq; //OFS: 0x40 SIZE: 0x4
		unsigned __int16 lightingHandle; //OFS: 0x44 SIZE: 0x2
		unsigned __int16 colorsIndex; //OFS: 0x46 SIZE: 0x2
		GfxLightingSHQuantized lightingSH; //OFS: 0x48 SIZE: 0x18
		unsigned __int8 primaryLightIndex; //OFS: 0x60 SIZE: 0x1
		unsigned __int8 visibility; //OFS: 0x61 SIZE: 0x1
		unsigned __int8 reflectionProbeIndex; //OFS: 0x62 SIZE: 0x1
		unsigned int smid; //OFS: 0x64 SIZE: 0x4
		GfxStaticModelLmapVertexInfo lmapVertexInfo[4]; //OFS: 0x68 SIZE: 0x30
	};
	ASSERT_STRUCT_SIZE(GfxStaticModelDrawInst, 0x98);
	ASSERT_STRUCT_OFFSET(GfxStaticModelDrawInst, cullDist, 0x0);
	ASSERT_STRUCT_OFFSET(GfxStaticModelDrawInst, placement, 0x4);
	ASSERT_STRUCT_OFFSET(GfxStaticModelDrawInst, model, 0x38);
	ASSERT_STRUCT_OFFSET(GfxStaticModelDrawInst, flags, 0x3C);
	ASSERT_STRUCT_OFFSET(GfxStaticModelDrawInst, invScaleSq, 0x40);
	ASSERT_STRUCT_OFFSET(GfxStaticModelDrawInst, lightingHandle, 0x44);
	ASSERT_STRUCT_OFFSET(GfxStaticModelDrawInst, colorsIndex, 0x46);
	ASSERT_STRUCT_OFFSET(GfxStaticModelDrawInst, lightingSH, 0x48);
	ASSERT_STRUCT_OFFSET(GfxStaticModelDrawInst, primaryLightIndex, 0x60);
	ASSERT_STRUCT_OFFSET(GfxStaticModelDrawInst, visibility, 0x61);
	ASSERT_STRUCT_OFFSET(GfxStaticModelDrawInst, reflectionProbeIndex, 0x62);
	ASSERT_STRUCT_OFFSET(GfxStaticModelDrawInst, smid, 0x64);
	ASSERT_STRUCT_OFFSET(GfxStaticModelDrawInst, lmapVertexInfo, 0x68);

	struct GfxWorldDpvsStatic
	{
		unsigned int smodelCount; //OFS: 0x0 SIZE: 0x4
		unsigned int staticSurfaceCount; //OFS: 0x4 SIZE: 0x4
		unsigned int litSurfsBegin; //OFS: 0x8 SIZE: 0x4
		unsigned int litSurfsEnd; //OFS: 0xC SIZE: 0x4
		unsigned int litTransSurfsBegin; //OFS: 0x10 SIZE: 0x4
		unsigned int litTransSurfsEnd; //OFS: 0x14 SIZE: 0x4
		unsigned int emissiveOpaqueSurfsBegin; //OFS: 0x18 SIZE: 0x4
		unsigned int emissiveOpaqueSurfsEnd; //OFS: 0x1C SIZE: 0x4
		unsigned int emissiveTransSurfsBegin; //OFS: 0x20 SIZE: 0x4
		unsigned int emissiveTransSurfsEnd; //OFS: 0x24 SIZE: 0x4
		unsigned int smodelVisDataCount; //OFS: 0x28 SIZE: 0x4
		unsigned int surfaceVisDataCount; //OFS: 0x2C SIZE: 0x4
		unsigned __int8* smodelVisData[3]; //OFS: 0x30 SIZE: 0xC
		unsigned __int8* surfaceVisData[3]; //OFS: 0x3C SIZE: 0xC
		unsigned __int8* smodelVisDataCameraSaved; //OFS: 0x48 SIZE: 0x4
		unsigned __int8* surfaceVisDataCameraSaved; //OFS: 0x4C SIZE: 0x4
		unsigned __int16* sortedSurfIndex; //OFS: 0x50 SIZE: 0x4
		GfxStaticModelInst* smodelInsts; //OFS: 0x54 SIZE: 0x4
		GfxSurface* surfaces; //OFS: 0x58 SIZE: 0x4
		GfxStaticModelDrawInst* smodelDrawInsts; //OFS: 0x5C SIZE: 0x4
		GfxDrawSurf* surfaceMaterials; //OFS: 0x60 SIZE: 0x4
		unsigned __int8* surfaceCastsSunShadow; //OFS: 0x64 SIZE: 0x4
		unsigned __int8* surfaceCastsShadow; //OFS: 0x68 SIZE: 0x4
		unsigned __int8* smodelCastsShadow; //OFS: 0x6C SIZE: 0x4
		volatile int usageCount; //OFS: 0x70 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxWorldDpvsStatic, 0x74);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsStatic, smodelCount, 0x0);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsStatic, staticSurfaceCount, 0x4);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsStatic, litSurfsBegin, 0x8);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsStatic, litSurfsEnd, 0xC);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsStatic, litTransSurfsBegin, 0x10);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsStatic, litTransSurfsEnd, 0x14);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsStatic, emissiveOpaqueSurfsBegin, 0x18);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsStatic, emissiveOpaqueSurfsEnd, 0x1C);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsStatic, emissiveTransSurfsBegin, 0x20);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsStatic, emissiveTransSurfsEnd, 0x24);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsStatic, smodelVisDataCount, 0x28);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsStatic, surfaceVisDataCount, 0x2C);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsStatic, smodelVisData, 0x30);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsStatic, surfaceVisData, 0x3C);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsStatic, smodelVisDataCameraSaved, 0x48);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsStatic, surfaceVisDataCameraSaved, 0x4C);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsStatic, sortedSurfIndex, 0x50);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsStatic, smodelInsts, 0x54);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsStatic, surfaces, 0x58);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsStatic, smodelDrawInsts, 0x5C);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsStatic, surfaceMaterials, 0x60);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsStatic, surfaceCastsSunShadow, 0x64);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsStatic, surfaceCastsShadow, 0x68);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsStatic, smodelCastsShadow, 0x6C);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsStatic, usageCount, 0x70);

	struct GfxWorldDpvsDynamic
	{
		unsigned int dynEntClientWordCount[2]; //OFS: 0x0 SIZE: 0x8
		unsigned int dynEntClientCount[2]; //OFS: 0x8 SIZE: 0x8
		unsigned int* dynEntCellBits[2]; //OFS: 0x10 SIZE: 0x8
		unsigned __int8* dynEntVisData[2][3]; //OFS: 0x18 SIZE: 0x18
		volatile int usageCount; //OFS: 0x30 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxWorldDpvsDynamic, 0x34);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsDynamic, dynEntClientWordCount, 0x0);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsDynamic, dynEntClientCount, 0x8);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsDynamic, dynEntCellBits, 0x10);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsDynamic, dynEntVisData, 0x18);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsDynamic, usageCount, 0x30);

	struct GfxWaterBuffer
	{
		unsigned int bufferSize; //OFS: 0x0 SIZE: 0x4
		vec4_t* buffer; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxWaterBuffer, 0x8);
	ASSERT_STRUCT_OFFSET(GfxWaterBuffer, bufferSize, 0x0);
	ASSERT_STRUCT_OFFSET(GfxWaterBuffer, buffer, 0x4);

	struct Occluder
	{
		unsigned int flags; //OFS: 0x0 SIZE: 0x4
		char name[16]; //OFS: 0x4 SIZE: 0x10
		vec3_t points[4]; //OFS: 0x14 SIZE: 0x30
	};
	ASSERT_STRUCT_SIZE(Occluder, 0x44);
	ASSERT_STRUCT_OFFSET(Occluder, flags, 0x0);
	ASSERT_STRUCT_OFFSET(Occluder, name, 0x4);
	ASSERT_STRUCT_OFFSET(Occluder, points, 0x14);

	struct GfxOutdoorBounds
	{
		vec3_t bounds[2]; //OFS: 0x0 SIZE: 0x18
	};
	ASSERT_STRUCT_SIZE(GfxOutdoorBounds, 0x18);
	ASSERT_STRUCT_OFFSET(GfxOutdoorBounds, bounds, 0x0);

	struct GfxHeroLight
	{
		unsigned __int8 type; //OFS: 0x0 SIZE: 0x1
		unsigned __int8 unused[3]; //OFS: 0x1 SIZE: 0x3
		vec3_t color; //OFS: 0x4 SIZE: 0xC
		vec3_t dir; //OFS: 0x10 SIZE: 0xC
		vec3_t origin; //OFS: 0x1C SIZE: 0xC
		float radius; //OFS: 0x28 SIZE: 0x4
		float cosHalfFovOuter; //OFS: 0x2C SIZE: 0x4
		float cosHalfFovInner; //OFS: 0x30 SIZE: 0x4
		int exponent; //OFS: 0x34 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxHeroLight, 0x38);
	ASSERT_STRUCT_OFFSET(GfxHeroLight, type, 0x0);
	ASSERT_STRUCT_OFFSET(GfxHeroLight, unused, 0x1);
	ASSERT_STRUCT_OFFSET(GfxHeroLight, color, 0x4);
	ASSERT_STRUCT_OFFSET(GfxHeroLight, dir, 0x10);
	ASSERT_STRUCT_OFFSET(GfxHeroLight, origin, 0x1C);
	ASSERT_STRUCT_OFFSET(GfxHeroLight, radius, 0x28);
	ASSERT_STRUCT_OFFSET(GfxHeroLight, cosHalfFovOuter, 0x2C);
	ASSERT_STRUCT_OFFSET(GfxHeroLight, cosHalfFovInner, 0x30);
	ASSERT_STRUCT_OFFSET(GfxHeroLight, exponent, 0x34);

	struct GfxHeroLightTree
	{
		vec3_t mins; //OFS: 0x0 SIZE: 0xC
		vec3_t maxs; //OFS: 0xC SIZE: 0xC
		int leftNode; //OFS: 0x18 SIZE: 0x4
		int rightNode; //OFS: 0x1C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxHeroLightTree, 0x20);
	ASSERT_STRUCT_OFFSET(GfxHeroLightTree, mins, 0x0);
	ASSERT_STRUCT_OFFSET(GfxHeroLightTree, maxs, 0xC);
	ASSERT_STRUCT_OFFSET(GfxHeroLightTree, leftNode, 0x18);
	ASSERT_STRUCT_OFFSET(GfxHeroLightTree, rightNode, 0x1C);

	struct GfxWorld
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		const char* baseName; //OFS: 0x4 SIZE: 0x4
		int planeCount; //OFS: 0x8 SIZE: 0x4
		int nodeCount; //OFS: 0xC SIZE: 0x4
		int surfaceCount; //OFS: 0x10 SIZE: 0x4
		GfxWorldStreamInfo streamInfo; //OFS: 0x14 SIZE: 0x10
		const char* skyBoxModel; //OFS: 0x24 SIZE: 0x4
		SunLightParseParams sunParse; //OFS: 0x28 SIZE: 0xD8
		GfxLight* sunLight; //OFS: 0x100 SIZE: 0x4
		unsigned int sunPrimaryLightIndex; //OFS: 0x104 SIZE: 0x4
		unsigned int primaryLightCount; //OFS: 0x108 SIZE: 0x4
		unsigned int coronaCount; //OFS: 0x10C SIZE: 0x4
		GfxLightCorona* coronas; //OFS: 0x110 SIZE: 0x4
		unsigned int shadowMapVolumeCount; //OFS: 0x114 SIZE: 0x4
		GfxShadowMapVolume* shadowMapVolumes; //OFS: 0x118 SIZE: 0x4
		unsigned int shadowMapVolumePlaneCount; //OFS: 0x11C SIZE: 0x4
		GfxVolumePlane* shadowMapVolumePlanes; //OFS: 0x120 SIZE: 0x4
		unsigned int exposureVolumeCount; //OFS: 0x124 SIZE: 0x4
		GfxExposureVolume* exposureVolumes; //OFS: 0x128 SIZE: 0x4
		unsigned int exposureVolumePlaneCount; //OFS: 0x12C SIZE: 0x4
		GfxVolumePlane* exposureVolumePlanes; //OFS: 0x130 SIZE: 0x4
		unsigned int worldFogVolumeCount; //OFS: 0x134 SIZE: 0x4
		GfxWorldFogVolume* worldFogVolumes; //OFS: 0x138 SIZE: 0x4
		unsigned int worldFogVolumePlaneCount; //OFS: 0x13C SIZE: 0x4
		GfxVolumePlane* worldFogVolumePlanes; //OFS: 0x140 SIZE: 0x4
		unsigned int worldFogModifierVolumeCount; //OFS: 0x144 SIZE: 0x4
		GfxWorldFogModifierVolume* worldFogModifierVolumes; //OFS: 0x148 SIZE: 0x4
		unsigned int worldFogModifierVolumePlaneCount; //OFS: 0x14C SIZE: 0x4
		GfxVolumePlane* worldFogModifierVolumePlanes; //OFS: 0x150 SIZE: 0x4
		unsigned int lutVolumeCount; //OFS: 0x154 SIZE: 0x4
		GfxLutVolume* lutVolumes; //OFS: 0x158 SIZE: 0x4
		unsigned int lutVolumePlaneCount; //OFS: 0x15C SIZE: 0x4
		GfxVolumePlane* lutVolumePlanes; //OFS: 0x160 SIZE: 0x4
		GfxSkyDynamicIntensity skyDynIntensity; //OFS: 0x164 SIZE: 0x10
		GfxWorldDpvsPlanes dpvsPlanes; //OFS: 0x174 SIZE: 0x10
		int cellBitsCount; //OFS: 0x184 SIZE: 0x4
		GfxCell* cells; //OFS: 0x188 SIZE: 0x4
		GfxWorldDraw draw; //OFS: 0x18C SIZE: 0x44
		GfxLightGrid lightGrid; //OFS: 0x1D0 SIZE: 0x48
		int modelCount; //OFS: 0x218 SIZE: 0x4
		GfxBrushModel* models; //OFS: 0x21C SIZE: 0x4
		vec3_t mins; //OFS: 0x220 SIZE: 0xC
		vec3_t maxs; //OFS: 0x22C SIZE: 0xC
		unsigned int checksum; //OFS: 0x238 SIZE: 0x4
		int materialMemoryCount; //OFS: 0x23C SIZE: 0x4
		MaterialMemory* materialMemory; //OFS: 0x240 SIZE: 0x4
		sunflare_t sun; //OFS: 0x244 SIZE: 0x60
		vec4_t outdoorLookupMatrix[4]; //OFS: 0x2A4 SIZE: 0x40
		GfxImage* outdoorImage; //OFS: 0x2E4 SIZE: 0x4
		unsigned int* cellCasterBits; //OFS: 0x2E8 SIZE: 0x4
		GfxSceneDynModel* sceneDynModel; //OFS: 0x2EC SIZE: 0x4
		GfxSceneDynBrush* sceneDynBrush; //OFS: 0x2F0 SIZE: 0x4
		unsigned int* primaryLightEntityShadowVis; //OFS: 0x2F4 SIZE: 0x4
		unsigned int* primaryLightDynEntShadowVis[2]; //OFS: 0x2F8 SIZE: 0x8
		unsigned int numSiegeSkinInsts; //OFS: 0x300 SIZE: 0x4
		SSkinInstance* siegeSkinInsts; //OFS: 0x304 SIZE: 0x4
		GfxShadowGeometry* shadowGeom; //OFS: 0x308 SIZE: 0x4
		GfxLightRegion* lightRegion; //OFS: 0x30C SIZE: 0x4
		GfxWorldDpvsStatic dpvs; //OFS: 0x310 SIZE: 0x74
		GfxWorldDpvsDynamic dpvsDyn; //OFS: 0x384 SIZE: 0x34
		float waterDirection; //OFS: 0x3B8 SIZE: 0x4
		GfxWaterBuffer waterBuffers[2]; //OFS: 0x3BC SIZE: 0x10
		const Material* waterMaterial; //OFS: 0x3CC SIZE: 0x4
		const Material* coronaMaterial; //OFS: 0x3D0 SIZE: 0x4
		const Material* ropeMaterial; //OFS: 0x3D4 SIZE: 0x4
		const Material* lutMaterial; //OFS: 0x3D8 SIZE: 0x4
		unsigned int numOccluders; //OFS: 0x3DC SIZE: 0x4
		Occluder* occluders; //OFS: 0x3E0 SIZE: 0x4
		unsigned int numOutdoorBounds; //OFS: 0x3E4 SIZE: 0x4
		GfxOutdoorBounds* outdoorBounds; //OFS: 0x3E8 SIZE: 0x4
		unsigned int heroLightCount; //OFS: 0x3EC SIZE: 0x4
		unsigned int heroLightTreeCount; //OFS: 0x3F0 SIZE: 0x4
		GfxHeroLight* heroLights; //OFS: 0x3F4 SIZE: 0x4
		GfxHeroLightTree* heroLightTree; //OFS: 0x3F8 SIZE: 0x4
		unsigned int lightingFlags; //OFS: 0x3FC SIZE: 0x4
		int lightingQuality; //OFS: 0x400 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxWorld, 0x404);
	ASSERT_STRUCT_OFFSET(GfxWorld, name, 0x0);
	ASSERT_STRUCT_OFFSET(GfxWorld, baseName, 0x4);
	ASSERT_STRUCT_OFFSET(GfxWorld, planeCount, 0x8);
	ASSERT_STRUCT_OFFSET(GfxWorld, nodeCount, 0xC);
	ASSERT_STRUCT_OFFSET(GfxWorld, surfaceCount, 0x10);
	ASSERT_STRUCT_OFFSET(GfxWorld, streamInfo, 0x14);
	ASSERT_STRUCT_OFFSET(GfxWorld, skyBoxModel, 0x24);
	ASSERT_STRUCT_OFFSET(GfxWorld, sunParse, 0x28);
	ASSERT_STRUCT_OFFSET(GfxWorld, sunLight, 0x100);
	ASSERT_STRUCT_OFFSET(GfxWorld, sunPrimaryLightIndex, 0x104);
	ASSERT_STRUCT_OFFSET(GfxWorld, primaryLightCount, 0x108);
	ASSERT_STRUCT_OFFSET(GfxWorld, coronaCount, 0x10C);
	ASSERT_STRUCT_OFFSET(GfxWorld, coronas, 0x110);
	ASSERT_STRUCT_OFFSET(GfxWorld, shadowMapVolumeCount, 0x114);
	ASSERT_STRUCT_OFFSET(GfxWorld, shadowMapVolumes, 0x118);
	ASSERT_STRUCT_OFFSET(GfxWorld, shadowMapVolumePlaneCount, 0x11C);
	ASSERT_STRUCT_OFFSET(GfxWorld, shadowMapVolumePlanes, 0x120);
	ASSERT_STRUCT_OFFSET(GfxWorld, exposureVolumeCount, 0x124);
	ASSERT_STRUCT_OFFSET(GfxWorld, exposureVolumes, 0x128);
	ASSERT_STRUCT_OFFSET(GfxWorld, exposureVolumePlaneCount, 0x12C);
	ASSERT_STRUCT_OFFSET(GfxWorld, exposureVolumePlanes, 0x130);
	ASSERT_STRUCT_OFFSET(GfxWorld, worldFogVolumeCount, 0x134);
	ASSERT_STRUCT_OFFSET(GfxWorld, worldFogVolumes, 0x138);
	ASSERT_STRUCT_OFFSET(GfxWorld, worldFogVolumePlaneCount, 0x13C);
	ASSERT_STRUCT_OFFSET(GfxWorld, worldFogVolumePlanes, 0x140);
	ASSERT_STRUCT_OFFSET(GfxWorld, worldFogModifierVolumeCount, 0x144);
	ASSERT_STRUCT_OFFSET(GfxWorld, worldFogModifierVolumes, 0x148);
	ASSERT_STRUCT_OFFSET(GfxWorld, worldFogModifierVolumePlaneCount, 0x14C);
	ASSERT_STRUCT_OFFSET(GfxWorld, worldFogModifierVolumePlanes, 0x150);
	ASSERT_STRUCT_OFFSET(GfxWorld, lutVolumeCount, 0x154);
	ASSERT_STRUCT_OFFSET(GfxWorld, lutVolumes, 0x158);
	ASSERT_STRUCT_OFFSET(GfxWorld, lutVolumePlaneCount, 0x15C);
	ASSERT_STRUCT_OFFSET(GfxWorld, lutVolumePlanes, 0x160);
	ASSERT_STRUCT_OFFSET(GfxWorld, skyDynIntensity, 0x164);
	ASSERT_STRUCT_OFFSET(GfxWorld, dpvsPlanes, 0x174);
	ASSERT_STRUCT_OFFSET(GfxWorld, cellBitsCount, 0x184);
	ASSERT_STRUCT_OFFSET(GfxWorld, cells, 0x188);
	ASSERT_STRUCT_OFFSET(GfxWorld, draw, 0x18C);
	ASSERT_STRUCT_OFFSET(GfxWorld, lightGrid, 0x1D0);
	ASSERT_STRUCT_OFFSET(GfxWorld, modelCount, 0x218);
	ASSERT_STRUCT_OFFSET(GfxWorld, models, 0x21C);
	ASSERT_STRUCT_OFFSET(GfxWorld, mins, 0x220);
	ASSERT_STRUCT_OFFSET(GfxWorld, maxs, 0x22C);
	ASSERT_STRUCT_OFFSET(GfxWorld, checksum, 0x238);
	ASSERT_STRUCT_OFFSET(GfxWorld, materialMemoryCount, 0x23C);
	ASSERT_STRUCT_OFFSET(GfxWorld, materialMemory, 0x240);
	ASSERT_STRUCT_OFFSET(GfxWorld, sun, 0x244);
	ASSERT_STRUCT_OFFSET(GfxWorld, outdoorLookupMatrix, 0x2A4);
	ASSERT_STRUCT_OFFSET(GfxWorld, outdoorImage, 0x2E4);
	ASSERT_STRUCT_OFFSET(GfxWorld, cellCasterBits, 0x2E8);
	ASSERT_STRUCT_OFFSET(GfxWorld, sceneDynModel, 0x2EC);
	ASSERT_STRUCT_OFFSET(GfxWorld, sceneDynBrush, 0x2F0);
	ASSERT_STRUCT_OFFSET(GfxWorld, primaryLightEntityShadowVis, 0x2F4);
	ASSERT_STRUCT_OFFSET(GfxWorld, primaryLightDynEntShadowVis, 0x2F8);
	ASSERT_STRUCT_OFFSET(GfxWorld, numSiegeSkinInsts, 0x300);
	ASSERT_STRUCT_OFFSET(GfxWorld, siegeSkinInsts, 0x304);
	ASSERT_STRUCT_OFFSET(GfxWorld, shadowGeom, 0x308);
	ASSERT_STRUCT_OFFSET(GfxWorld, lightRegion, 0x30C);
	ASSERT_STRUCT_OFFSET(GfxWorld, dpvs, 0x310);
	ASSERT_STRUCT_OFFSET(GfxWorld, dpvsDyn, 0x384);
	ASSERT_STRUCT_OFFSET(GfxWorld, waterDirection, 0x3B8);
	ASSERT_STRUCT_OFFSET(GfxWorld, waterBuffers, 0x3BC);
	ASSERT_STRUCT_OFFSET(GfxWorld, waterMaterial, 0x3CC);
	ASSERT_STRUCT_OFFSET(GfxWorld, coronaMaterial, 0x3D0);
	ASSERT_STRUCT_OFFSET(GfxWorld, ropeMaterial, 0x3D4);
	ASSERT_STRUCT_OFFSET(GfxWorld, lutMaterial, 0x3D8);
	ASSERT_STRUCT_OFFSET(GfxWorld, numOccluders, 0x3DC);
	ASSERT_STRUCT_OFFSET(GfxWorld, occluders, 0x3E0);
	ASSERT_STRUCT_OFFSET(GfxWorld, numOutdoorBounds, 0x3E4);
	ASSERT_STRUCT_OFFSET(GfxWorld, outdoorBounds, 0x3E8);
	ASSERT_STRUCT_OFFSET(GfxWorld, heroLightCount, 0x3EC);
	ASSERT_STRUCT_OFFSET(GfxWorld, heroLightTreeCount, 0x3F0);
	ASSERT_STRUCT_OFFSET(GfxWorld, heroLights, 0x3F4);
	ASSERT_STRUCT_OFFSET(GfxWorld, heroLightTree, 0x3F8);
	ASSERT_STRUCT_OFFSET(GfxWorld, lightingFlags, 0x3FC);
	ASSERT_STRUCT_OFFSET(GfxWorld, lightingQuality, 0x400);

	struct Glyph
	{
		unsigned __int16 letter; //OFS: 0x0 SIZE: 0x2
		char x0; //OFS: 0x2 SIZE: 0x1
		char y0; //OFS: 0x3 SIZE: 0x1
		unsigned __int8 _dx; //OFS: 0x4 SIZE: 0x1
		unsigned __int8 pixelWidth; //OFS: 0x5 SIZE: 0x1
		unsigned __int8 pixelHeight; //OFS: 0x6 SIZE: 0x1
		float s0; //OFS: 0x8 SIZE: 0x4
		float t0; //OFS: 0xC SIZE: 0x4
		float s1; //OFS: 0x10 SIZE: 0x4
		float t1; //OFS: 0x14 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(Glyph, 0x18);
	ASSERT_STRUCT_OFFSET(Glyph, letter, 0x0);
	ASSERT_STRUCT_OFFSET(Glyph, x0, 0x2);
	ASSERT_STRUCT_OFFSET(Glyph, y0, 0x3);
	ASSERT_STRUCT_OFFSET(Glyph, _dx, 0x4);
	ASSERT_STRUCT_OFFSET(Glyph, pixelWidth, 0x5);
	ASSERT_STRUCT_OFFSET(Glyph, pixelHeight, 0x6);
	ASSERT_STRUCT_OFFSET(Glyph, s0, 0x8);
	ASSERT_STRUCT_OFFSET(Glyph, t0, 0xC);
	ASSERT_STRUCT_OFFSET(Glyph, s1, 0x10);
	ASSERT_STRUCT_OFFSET(Glyph, t1, 0x14);

	struct KerningPairs
	{
		unsigned __int16 wFirst; //OFS: 0x0 SIZE: 0x2
		unsigned __int16 wSecond; //OFS: 0x2 SIZE: 0x2
		int iKernAmount; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(KerningPairs, 0x8);
	ASSERT_STRUCT_OFFSET(KerningPairs, wFirst, 0x0);
	ASSERT_STRUCT_OFFSET(KerningPairs, wSecond, 0x2);
	ASSERT_STRUCT_OFFSET(KerningPairs, iKernAmount, 0x4);

	struct Font_s
	{
		const char* fontName; //OFS: 0x0 SIZE: 0x4
		int pixelHeight; //OFS: 0x4 SIZE: 0x4
		int isScalingAllowed; //OFS: 0x8 SIZE: 0x4
		int glyphCount; //OFS: 0xC SIZE: 0x4
		int kerningPairsCount; //OFS: 0x10 SIZE: 0x4
		Material* material; //OFS: 0x14 SIZE: 0x4
		Material* glowMaterial; //OFS: 0x18 SIZE: 0x4
		Glyph* glyphs; //OFS: 0x1C SIZE: 0x4
		KerningPairs* kerningPairs; //OFS: 0x20 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(Font_s, 0x24);
	ASSERT_STRUCT_OFFSET(Font_s, fontName, 0x0);
	ASSERT_STRUCT_OFFSET(Font_s, pixelHeight, 0x4);
	ASSERT_STRUCT_OFFSET(Font_s, isScalingAllowed, 0x8);
	ASSERT_STRUCT_OFFSET(Font_s, glyphCount, 0xC);
	ASSERT_STRUCT_OFFSET(Font_s, kerningPairsCount, 0x10);
	ASSERT_STRUCT_OFFSET(Font_s, material, 0x14);
	ASSERT_STRUCT_OFFSET(Font_s, glowMaterial, 0x18);
	ASSERT_STRUCT_OFFSET(Font_s, glyphs, 0x1C);
	ASSERT_STRUCT_OFFSET(Font_s, kerningPairs, 0x20);

	struct FontIconName
	{
		const char* string; //OFS: 0x0 SIZE: 0x4
		int hash; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(FontIconName, 0x8);
	ASSERT_STRUCT_OFFSET(FontIconName, string, 0x0);
	ASSERT_STRUCT_OFFSET(FontIconName, hash, 0x4);

	struct FontIconEntry
	{
		FontIconName fontIconName; //OFS: 0x0 SIZE: 0x8
		Material* fontIconMaterialHandle; //OFS: 0x8 SIZE: 0x4
		int fontIconSize; //OFS: 0xC SIZE: 0x4
		float xScale; //OFS: 0x10 SIZE: 0x4
		float yScale; //OFS: 0x14 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(FontIconEntry, 0x18);
	ASSERT_STRUCT_OFFSET(FontIconEntry, fontIconName, 0x0);
	ASSERT_STRUCT_OFFSET(FontIconEntry, fontIconMaterialHandle, 0x8);
	ASSERT_STRUCT_OFFSET(FontIconEntry, fontIconSize, 0xC);
	ASSERT_STRUCT_OFFSET(FontIconEntry, xScale, 0x10);
	ASSERT_STRUCT_OFFSET(FontIconEntry, yScale, 0x14);

	struct FontIconAlias
	{
		int aliasHash; //OFS: 0x0 SIZE: 0x4
		int buttonHash; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(FontIconAlias, 0x8);
	ASSERT_STRUCT_OFFSET(FontIconAlias, aliasHash, 0x0);
	ASSERT_STRUCT_OFFSET(FontIconAlias, buttonHash, 0x4);

	struct FontIcon
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		int numEntries; //OFS: 0x4 SIZE: 0x4
		int numAliasEntries; //OFS: 0x8 SIZE: 0x4
		FontIconEntry* fontIconEntry; //OFS: 0xC SIZE: 0x4
		FontIconAlias* fontIconAlias; //OFS: 0x10 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(FontIcon, 0x14);
	ASSERT_STRUCT_OFFSET(FontIcon, name, 0x0);
	ASSERT_STRUCT_OFFSET(FontIcon, numEntries, 0x4);
	ASSERT_STRUCT_OFFSET(FontIcon, numAliasEntries, 0x8);
	ASSERT_STRUCT_OFFSET(FontIcon, fontIconEntry, 0xC);
	ASSERT_STRUCT_OFFSET(FontIcon, fontIconAlias, 0x10);

	struct rectDef_s
	{
		float x; //OFS: 0x0 SIZE: 0x4
		float y; //OFS: 0x4 SIZE: 0x4
		float w; //OFS: 0x8 SIZE: 0x4
		float h; //OFS: 0xC SIZE: 0x4
		int horzAlign; //OFS: 0x10 SIZE: 0x4
		int vertAlign; //OFS: 0x14 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(rectDef_s, 0x18);
	ASSERT_STRUCT_OFFSET(rectDef_s, x, 0x0);
	ASSERT_STRUCT_OFFSET(rectDef_s, y, 0x4);
	ASSERT_STRUCT_OFFSET(rectDef_s, w, 0x8);
	ASSERT_STRUCT_OFFSET(rectDef_s, h, 0xC);
	ASSERT_STRUCT_OFFSET(rectDef_s, horzAlign, 0x10);
	ASSERT_STRUCT_OFFSET(rectDef_s, vertAlign, 0x14);

	struct windowDef_t
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		rectDef_s rect; //OFS: 0x4 SIZE: 0x18
		rectDef_s rectClient; //OFS: 0x1C SIZE: 0x18
		const char* group; //OFS: 0x34 SIZE: 0x4
		unsigned __int8 style; //OFS: 0x38 SIZE: 0x1
		unsigned __int8 border; //OFS: 0x39 SIZE: 0x1
		unsigned __int8 modal; //OFS: 0x3A SIZE: 0x1
		unsigned __int8 frameSides; //OFS: 0x3B SIZE: 0x1
		float frameTexSize; //OFS: 0x3C SIZE: 0x4
		float frameSize; //OFS: 0x40 SIZE: 0x4
		int ownerDraw; //OFS: 0x44 SIZE: 0x4
		int ownerDrawFlags; //OFS: 0x48 SIZE: 0x4
		float borderSize; //OFS: 0x4C SIZE: 0x4
		int staticFlags; //OFS: 0x50 SIZE: 0x4
		int dynamicFlags[1]; //OFS: 0x54 SIZE: 0x4
		int nextTime; //OFS: 0x58 SIZE: 0x4
		vec4_t foreColor; //OFS: 0x5C SIZE: 0x10
		vec4_t backColor; //OFS: 0x6C SIZE: 0x10
		vec4_t borderColor; //OFS: 0x7C SIZE: 0x10
		vec4_t outlineColor; //OFS: 0x8C SIZE: 0x10
		float rotation; //OFS: 0x9C SIZE: 0x4
		Material* background; //OFS: 0xA0 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(windowDef_t, 0xA4);
	ASSERT_STRUCT_OFFSET(windowDef_t, name, 0x0);
	ASSERT_STRUCT_OFFSET(windowDef_t, rect, 0x4);
	ASSERT_STRUCT_OFFSET(windowDef_t, rectClient, 0x1C);
	ASSERT_STRUCT_OFFSET(windowDef_t, group, 0x34);
	ASSERT_STRUCT_OFFSET(windowDef_t, style, 0x38);
	ASSERT_STRUCT_OFFSET(windowDef_t, border, 0x39);
	ASSERT_STRUCT_OFFSET(windowDef_t, modal, 0x3A);
	ASSERT_STRUCT_OFFSET(windowDef_t, frameSides, 0x3B);
	ASSERT_STRUCT_OFFSET(windowDef_t, frameTexSize, 0x3C);
	ASSERT_STRUCT_OFFSET(windowDef_t, frameSize, 0x40);
	ASSERT_STRUCT_OFFSET(windowDef_t, ownerDraw, 0x44);
	ASSERT_STRUCT_OFFSET(windowDef_t, ownerDrawFlags, 0x48);
	ASSERT_STRUCT_OFFSET(windowDef_t, borderSize, 0x4C);
	ASSERT_STRUCT_OFFSET(windowDef_t, staticFlags, 0x50);
	ASSERT_STRUCT_OFFSET(windowDef_t, dynamicFlags, 0x54);
	ASSERT_STRUCT_OFFSET(windowDef_t, nextTime, 0x58);
	ASSERT_STRUCT_OFFSET(windowDef_t, foreColor, 0x5C);
	ASSERT_STRUCT_OFFSET(windowDef_t, backColor, 0x6C);
	ASSERT_STRUCT_OFFSET(windowDef_t, borderColor, 0x7C);
	ASSERT_STRUCT_OFFSET(windowDef_t, outlineColor, 0x8C);
	ASSERT_STRUCT_OFFSET(windowDef_t, rotation, 0x9C);
	ASSERT_STRUCT_OFFSET(windowDef_t, background, 0xA0);

	struct ScriptCondition
	{
		bool fireOnTrue; //OFS: 0x0 SIZE: 0x1
		int constructID; //OFS: 0x4 SIZE: 0x4
		int blockID; //OFS: 0x8 SIZE: 0x4
		ScriptCondition* next; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(ScriptCondition, 0x10);
	ASSERT_STRUCT_OFFSET(ScriptCondition, fireOnTrue, 0x0);
	ASSERT_STRUCT_OFFSET(ScriptCondition, constructID, 0x4);
	ASSERT_STRUCT_OFFSET(ScriptCondition, blockID, 0x8);
	ASSERT_STRUCT_OFFSET(ScriptCondition, next, 0xC);

	struct Operand
	{
		AddressingMode mode; //OFS: 0x0 SIZE: 0x4
		unsigned __int16 imm; //OFS: 0x4 SIZE: 0x2
		unsigned __int16 addr; //OFS: 0x6 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(Operand, 0x8);
	ASSERT_STRUCT_OFFSET(Operand, mode, 0x0);
	ASSERT_STRUCT_OFFSET(Operand, imm, 0x4);
	ASSERT_STRUCT_OFFSET(Operand, addr, 0x6);

	union expressionRpnDataUnion
	{
		Operand constant; //OFS: 0x0 SIZE: 0x8
		void* cmd; //OFS: 0x1 SIZE: 0x4
		int cmdIdx; //OFS: 0x2 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(expressionRpnDataUnion, 0x8);

	struct expressionRpn
	{
		int type; //OFS: 0x0 SIZE: 0x4
		expressionRpnDataUnion data; //OFS: 0x4 SIZE: 0x8
	};
	ASSERT_STRUCT_SIZE(expressionRpn, 0xC);
	ASSERT_STRUCT_OFFSET(expressionRpn, type, 0x0);
	ASSERT_STRUCT_OFFSET(expressionRpn, data, 0x4);

	struct ExpressionStatement
	{
		char* filename; //OFS: 0x0 SIZE: 0x4
		int line; //OFS: 0x4 SIZE: 0x4
		int numRpn; //OFS: 0x8 SIZE: 0x4
		expressionRpn* rpn; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(ExpressionStatement, 0x10);
	ASSERT_STRUCT_OFFSET(ExpressionStatement, filename, 0x0);
	ASSERT_STRUCT_OFFSET(ExpressionStatement, line, 0x4);
	ASSERT_STRUCT_OFFSET(ExpressionStatement, numRpn, 0x8);
	ASSERT_STRUCT_OFFSET(ExpressionStatement, rpn, 0xC);

	struct GenericEventScript
	{
		ScriptCondition* prerequisites; //OFS: 0x0 SIZE: 0x4
		ExpressionStatement condition; //OFS: 0x4 SIZE: 0x10
		int type; //OFS: 0x14 SIZE: 0x4
		bool fireOnTrue; //OFS: 0x18 SIZE: 0x1
		const char* action; //OFS: 0x1C SIZE: 0x4
		int blockID; //OFS: 0x20 SIZE: 0x4
		int constructID; //OFS: 0x24 SIZE: 0x4
		GenericEventScript* next; //OFS: 0x28 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GenericEventScript, 0x2C);
	ASSERT_STRUCT_OFFSET(GenericEventScript, prerequisites, 0x0);
	ASSERT_STRUCT_OFFSET(GenericEventScript, condition, 0x4);
	ASSERT_STRUCT_OFFSET(GenericEventScript, type, 0x14);
	ASSERT_STRUCT_OFFSET(GenericEventScript, fireOnTrue, 0x18);
	ASSERT_STRUCT_OFFSET(GenericEventScript, action, 0x1C);
	ASSERT_STRUCT_OFFSET(GenericEventScript, blockID, 0x20);
	ASSERT_STRUCT_OFFSET(GenericEventScript, constructID, 0x24);
	ASSERT_STRUCT_OFFSET(GenericEventScript, next, 0x28);

	struct GenericEventHandler
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		GenericEventScript* eventScript; //OFS: 0x4 SIZE: 0x4
		GenericEventHandler* next; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GenericEventHandler, 0xC);
	ASSERT_STRUCT_OFFSET(GenericEventHandler, name, 0x0);
	ASSERT_STRUCT_OFFSET(GenericEventHandler, eventScript, 0x4);
	ASSERT_STRUCT_OFFSET(GenericEventHandler, next, 0x8);

	struct ItemKeyHandler
	{
		int key; //OFS: 0x0 SIZE: 0x4
		GenericEventScript* keyScript; //OFS: 0x4 SIZE: 0x4
		ItemKeyHandler* next; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(ItemKeyHandler, 0xC);
	ASSERT_STRUCT_OFFSET(ItemKeyHandler, key, 0x0);
	ASSERT_STRUCT_OFFSET(ItemKeyHandler, keyScript, 0x4);
	ASSERT_STRUCT_OFFSET(ItemKeyHandler, next, 0x8);

	struct textExp_s
	{
		ExpressionStatement textExp; //OFS: 0x0 SIZE: 0x10
	};
	ASSERT_STRUCT_SIZE(textExp_s, 0x10);
	ASSERT_STRUCT_OFFSET(textExp_s, textExp, 0x0);

	struct columnInfo_s
	{
		int elementStyle; //OFS: 0x0 SIZE: 0x4
		int maxChars; //OFS: 0x4 SIZE: 0x4
		rectDef_s rect; //OFS: 0x8 SIZE: 0x18
	};
	ASSERT_STRUCT_SIZE(columnInfo_s, 0x20);
	ASSERT_STRUCT_OFFSET(columnInfo_s, elementStyle, 0x0);
	ASSERT_STRUCT_OFFSET(columnInfo_s, maxChars, 0x4);
	ASSERT_STRUCT_OFFSET(columnInfo_s, rect, 0x8);

	struct MenuCell
	{
		int type; //OFS: 0x0 SIZE: 0x4
		int maxChars; //OFS: 0x4 SIZE: 0x4
		char* stringValue; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(MenuCell, 0xC);
	ASSERT_STRUCT_OFFSET(MenuCell, type, 0x0);
	ASSERT_STRUCT_OFFSET(MenuCell, maxChars, 0x4);
	ASSERT_STRUCT_OFFSET(MenuCell, stringValue, 0x8);

	struct MenuRow
	{
		MenuCell* cells; //OFS: 0x0 SIZE: 0x4
		char* eventName; //OFS: 0x4 SIZE: 0x4
		char* onFocusEventName; //OFS: 0x8 SIZE: 0x4
		bool disableArg; //OFS: 0xC SIZE: 0x1
		int status; //OFS: 0x10 SIZE: 0x4
		int name; //OFS: 0x14 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(MenuRow, 0x18);
	ASSERT_STRUCT_OFFSET(MenuRow, cells, 0x0);
	ASSERT_STRUCT_OFFSET(MenuRow, eventName, 0x4);
	ASSERT_STRUCT_OFFSET(MenuRow, onFocusEventName, 0x8);
	ASSERT_STRUCT_OFFSET(MenuRow, disableArg, 0xC);
	ASSERT_STRUCT_OFFSET(MenuRow, status, 0x10);
	ASSERT_STRUCT_OFFSET(MenuRow, name, 0x14);

	struct listBoxDef_s
	{
		int mousePos; //OFS: 0x0 SIZE: 0x4
		int cursorPos[1]; //OFS: 0x4 SIZE: 0x4
		int startPos[1]; //OFS: 0x8 SIZE: 0x4
		int endPos[1]; //OFS: 0xC SIZE: 0x4
		int drawPadding; //OFS: 0x10 SIZE: 0x4
		float elementWidth; //OFS: 0x14 SIZE: 0x4
		float elementHeight; //OFS: 0x18 SIZE: 0x4
		int numColumns; //OFS: 0x1C SIZE: 0x4
		float special; //OFS: 0x20 SIZE: 0x4
		columnInfo_s columnInfo[16]; //OFS: 0x24 SIZE: 0x200
		int notselectable; //OFS: 0x224 SIZE: 0x4
		int noScrollBars; //OFS: 0x228 SIZE: 0x4
		int usePaging; //OFS: 0x22C SIZE: 0x4
		vec4_t selectBorder; //OFS: 0x230 SIZE: 0x10
		vec4_t disableColor; //OFS: 0x240 SIZE: 0x10
		vec4_t focusColor; //OFS: 0x250 SIZE: 0x10
		vec4_t elementHighlightColor; //OFS: 0x260 SIZE: 0x10
		vec4_t elementBackgroundColor; //OFS: 0x270 SIZE: 0x10
		Material* selectIcon; //OFS: 0x280 SIZE: 0x4
		Material* backgroundItemListbox; //OFS: 0x284 SIZE: 0x4
		Material* highlightTexture; //OFS: 0x288 SIZE: 0x4
		int noBlinkingHighlight; //OFS: 0x28C SIZE: 0x4
		MenuRow* rows; //OFS: 0x290 SIZE: 0x4
		int maxRows; //OFS: 0x294 SIZE: 0x4
		int rowCount; //OFS: 0x298 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(listBoxDef_s, 0x29C);
	ASSERT_STRUCT_OFFSET(listBoxDef_s, mousePos, 0x0);
	ASSERT_STRUCT_OFFSET(listBoxDef_s, cursorPos, 0x4);
	ASSERT_STRUCT_OFFSET(listBoxDef_s, startPos, 0x8);
	ASSERT_STRUCT_OFFSET(listBoxDef_s, endPos, 0xC);
	ASSERT_STRUCT_OFFSET(listBoxDef_s, drawPadding, 0x10);
	ASSERT_STRUCT_OFFSET(listBoxDef_s, elementWidth, 0x14);
	ASSERT_STRUCT_OFFSET(listBoxDef_s, elementHeight, 0x18);
	ASSERT_STRUCT_OFFSET(listBoxDef_s, numColumns, 0x1C);
	ASSERT_STRUCT_OFFSET(listBoxDef_s, special, 0x20);
	ASSERT_STRUCT_OFFSET(listBoxDef_s, columnInfo, 0x24);
	ASSERT_STRUCT_OFFSET(listBoxDef_s, notselectable, 0x224);
	ASSERT_STRUCT_OFFSET(listBoxDef_s, noScrollBars, 0x228);
	ASSERT_STRUCT_OFFSET(listBoxDef_s, usePaging, 0x22C);
	ASSERT_STRUCT_OFFSET(listBoxDef_s, selectBorder, 0x230);
	ASSERT_STRUCT_OFFSET(listBoxDef_s, disableColor, 0x240);
	ASSERT_STRUCT_OFFSET(listBoxDef_s, focusColor, 0x250);
	ASSERT_STRUCT_OFFSET(listBoxDef_s, elementHighlightColor, 0x260);
	ASSERT_STRUCT_OFFSET(listBoxDef_s, elementBackgroundColor, 0x270);
	ASSERT_STRUCT_OFFSET(listBoxDef_s, selectIcon, 0x280);
	ASSERT_STRUCT_OFFSET(listBoxDef_s, backgroundItemListbox, 0x284);
	ASSERT_STRUCT_OFFSET(listBoxDef_s, highlightTexture, 0x288);
	ASSERT_STRUCT_OFFSET(listBoxDef_s, noBlinkingHighlight, 0x28C);
	ASSERT_STRUCT_OFFSET(listBoxDef_s, rows, 0x290);
	ASSERT_STRUCT_OFFSET(listBoxDef_s, maxRows, 0x294);
	ASSERT_STRUCT_OFFSET(listBoxDef_s, rowCount, 0x298);

	struct multiDef_s
	{
		const char* dvarList[32]; //OFS: 0x0 SIZE: 0x80
		const char* dvarStr[32]; //OFS: 0x80 SIZE: 0x80
		float dvarValue[32]; //OFS: 0x100 SIZE: 0x80
		int count; //OFS: 0x180 SIZE: 0x4
		int actionOnEnterPressOnly; //OFS: 0x184 SIZE: 0x4
		int strDef; //OFS: 0x188 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(multiDef_s, 0x18C);
	ASSERT_STRUCT_OFFSET(multiDef_s, dvarList, 0x0);
	ASSERT_STRUCT_OFFSET(multiDef_s, dvarStr, 0x80);
	ASSERT_STRUCT_OFFSET(multiDef_s, dvarValue, 0x100);
	ASSERT_STRUCT_OFFSET(multiDef_s, count, 0x180);
	ASSERT_STRUCT_OFFSET(multiDef_s, actionOnEnterPressOnly, 0x184);
	ASSERT_STRUCT_OFFSET(multiDef_s, strDef, 0x188);

	struct profileMultiDef_s
	{
		const char* profileVarList[32]; //OFS: 0x0 SIZE: 0x80
		const char* profileVarStr[32]; //OFS: 0x80 SIZE: 0x80
		float profileVarValue[32]; //OFS: 0x100 SIZE: 0x80
		int count; //OFS: 0x180 SIZE: 0x4
		int actionOnEnterPressOnly; //OFS: 0x184 SIZE: 0x4
		int strDef; //OFS: 0x188 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(profileMultiDef_s, 0x18C);
	ASSERT_STRUCT_OFFSET(profileMultiDef_s, profileVarList, 0x0);
	ASSERT_STRUCT_OFFSET(profileMultiDef_s, profileVarStr, 0x80);
	ASSERT_STRUCT_OFFSET(profileMultiDef_s, profileVarValue, 0x100);
	ASSERT_STRUCT_OFFSET(profileMultiDef_s, count, 0x180);
	ASSERT_STRUCT_OFFSET(profileMultiDef_s, actionOnEnterPressOnly, 0x184);
	ASSERT_STRUCT_OFFSET(profileMultiDef_s, strDef, 0x188);

	struct editFieldDef_s
	{
		int cursorPos[1]; //OFS: 0x0 SIZE: 0x4
		float minVal; //OFS: 0x4 SIZE: 0x4
		float maxVal; //OFS: 0x8 SIZE: 0x4
		float defVal; //OFS: 0xC SIZE: 0x4
		float range; //OFS: 0x10 SIZE: 0x4
		int maxChars; //OFS: 0x14 SIZE: 0x4
		int maxCharsGotoNext; //OFS: 0x18 SIZE: 0x4
		int maxPaintChars; //OFS: 0x1C SIZE: 0x4
		int paintOffset; //OFS: 0x20 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(editFieldDef_s, 0x24);
	ASSERT_STRUCT_OFFSET(editFieldDef_s, cursorPos, 0x0);
	ASSERT_STRUCT_OFFSET(editFieldDef_s, minVal, 0x4);
	ASSERT_STRUCT_OFFSET(editFieldDef_s, maxVal, 0x8);
	ASSERT_STRUCT_OFFSET(editFieldDef_s, defVal, 0xC);
	ASSERT_STRUCT_OFFSET(editFieldDef_s, range, 0x10);
	ASSERT_STRUCT_OFFSET(editFieldDef_s, maxChars, 0x14);
	ASSERT_STRUCT_OFFSET(editFieldDef_s, maxCharsGotoNext, 0x18);
	ASSERT_STRUCT_OFFSET(editFieldDef_s, maxPaintChars, 0x1C);
	ASSERT_STRUCT_OFFSET(editFieldDef_s, paintOffset, 0x20);

	struct enumDvarDef_s
	{
		const char* enumDvarName; //OFS: 0x0 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(enumDvarDef_s, 0x4);
	ASSERT_STRUCT_OFFSET(enumDvarDef_s, enumDvarName, 0x0);

	union focusDefData_t
	{
		listBoxDef_s* listBox; //OFS: 0x0 SIZE: 0x4
		multiDef_s* multi; //OFS: 0x1 SIZE: 0x4
		profileMultiDef_s* profileMulti; //OFS: 0x2 SIZE: 0x4
		editFieldDef_s* editField; //OFS: 0x3 SIZE: 0x4
		enumDvarDef_s* enumDvar; //OFS: 0x4 SIZE: 0x4
		void* data; //OFS: 0x5 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(focusDefData_t, 0x4);

	struct focusItemDef_s
	{
		const char* mouseEnterText; //OFS: 0x0 SIZE: 0x4
		const char* mouseExitText; //OFS: 0x4 SIZE: 0x4
		const char* mouseEnter; //OFS: 0x8 SIZE: 0x4
		const char* mouseExit; //OFS: 0xC SIZE: 0x4
		ItemKeyHandler* onKey; //OFS: 0x10 SIZE: 0x4
		focusDefData_t focusTypeData; //OFS: 0x14 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(focusItemDef_s, 0x18);
	ASSERT_STRUCT_OFFSET(focusItemDef_s, mouseEnterText, 0x0);
	ASSERT_STRUCT_OFFSET(focusItemDef_s, mouseExitText, 0x4);
	ASSERT_STRUCT_OFFSET(focusItemDef_s, mouseEnter, 0x8);
	ASSERT_STRUCT_OFFSET(focusItemDef_s, mouseExit, 0xC);
	ASSERT_STRUCT_OFFSET(focusItemDef_s, onKey, 0x10);
	ASSERT_STRUCT_OFFSET(focusItemDef_s, focusTypeData, 0x14);

	struct gameMsgDef_s
	{
		int gameMsgWindowIndex; //OFS: 0x0 SIZE: 0x4
		int gameMsgWindowMode; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(gameMsgDef_s, 0x8);
	ASSERT_STRUCT_OFFSET(gameMsgDef_s, gameMsgWindowIndex, 0x0);
	ASSERT_STRUCT_OFFSET(gameMsgDef_s, gameMsgWindowMode, 0x4);

	union textDefData_t
	{
		focusItemDef_s* focusItemDef; //OFS: 0x0 SIZE: 0x4
		gameMsgDef_s* gameMsgDef; //OFS: 0x1 SIZE: 0x4
		void* data; //OFS: 0x2 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(textDefData_t, 0x4);

	struct textDef_s
	{
		rectDef_s textRect[1]; //OFS: 0x0 SIZE: 0x18
		int alignment; //OFS: 0x18 SIZE: 0x4
		int fontEnum; //OFS: 0x1C SIZE: 0x4
		int itemFlags; //OFS: 0x20 SIZE: 0x4
		int textAlignMode; //OFS: 0x24 SIZE: 0x4
		float textalignx; //OFS: 0x28 SIZE: 0x4
		float textaligny; //OFS: 0x2C SIZE: 0x4
		float textscale; //OFS: 0x30 SIZE: 0x4
		float textpadding; //OFS: 0x34 SIZE: 0x4
		int textStyle; //OFS: 0x38 SIZE: 0x4
		vec4_t fontColor; //OFS: 0x3C SIZE: 0x10
		vec4_t glowColor; //OFS: 0x4C SIZE: 0x10
		vec4_t shadowColor; //OFS: 0x5C SIZE: 0x10
		float fontBlur; //OFS: 0x6C SIZE: 0x4
		float glowSize; //OFS: 0x70 SIZE: 0x4
		float shadowSize; //OFS: 0x74 SIZE: 0x4
		vec2_t shadowOffset; //OFS: 0x78 SIZE: 0x8
		const char* text; //OFS: 0x80 SIZE: 0x4
		textExp_s* textExpData; //OFS: 0x84 SIZE: 0x4
		textDefData_t textTypeData; //OFS: 0x88 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(textDef_s, 0x8C);
	ASSERT_STRUCT_OFFSET(textDef_s, textRect, 0x0);
	ASSERT_STRUCT_OFFSET(textDef_s, alignment, 0x18);
	ASSERT_STRUCT_OFFSET(textDef_s, fontEnum, 0x1C);
	ASSERT_STRUCT_OFFSET(textDef_s, itemFlags, 0x20);
	ASSERT_STRUCT_OFFSET(textDef_s, textAlignMode, 0x24);
	ASSERT_STRUCT_OFFSET(textDef_s, textalignx, 0x28);
	ASSERT_STRUCT_OFFSET(textDef_s, textaligny, 0x2C);
	ASSERT_STRUCT_OFFSET(textDef_s, textscale, 0x30);
	ASSERT_STRUCT_OFFSET(textDef_s, textpadding, 0x34);
	ASSERT_STRUCT_OFFSET(textDef_s, textStyle, 0x38);
	ASSERT_STRUCT_OFFSET(textDef_s, fontColor, 0x3C);
	ASSERT_STRUCT_OFFSET(textDef_s, glowColor, 0x4C);
	ASSERT_STRUCT_OFFSET(textDef_s, shadowColor, 0x5C);
	ASSERT_STRUCT_OFFSET(textDef_s, fontBlur, 0x6C);
	ASSERT_STRUCT_OFFSET(textDef_s, glowSize, 0x70);
	ASSERT_STRUCT_OFFSET(textDef_s, shadowSize, 0x74);
	ASSERT_STRUCT_OFFSET(textDef_s, shadowOffset, 0x78);
	ASSERT_STRUCT_OFFSET(textDef_s, text, 0x80);
	ASSERT_STRUCT_OFFSET(textDef_s, textExpData, 0x84);
	ASSERT_STRUCT_OFFSET(textDef_s, textTypeData, 0x88);

	struct imageDef_s
	{
		ExpressionStatement materialExp; //OFS: 0x0 SIZE: 0x10
	};
	ASSERT_STRUCT_SIZE(imageDef_s, 0x10);
	ASSERT_STRUCT_OFFSET(imageDef_s, materialExp, 0x0);

	struct ownerDrawDef_s
	{
		ExpressionStatement dataExp; //OFS: 0x0 SIZE: 0x10
	};
	ASSERT_STRUCT_SIZE(ownerDrawDef_s, 0x10);
	ASSERT_STRUCT_OFFSET(ownerDrawDef_s, dataExp, 0x0);

	union itemDefData_t
	{
		textDef_s* textDef; //OFS: 0x0 SIZE: 0x4
		imageDef_s* imageDef; //OFS: 0x1 SIZE: 0x4
		focusItemDef_s* blankButtonDef; //OFS: 0x2 SIZE: 0x4
		ownerDrawDef_s* ownerDrawDef; //OFS: 0x3 SIZE: 0x4
		void* data; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(itemDefData_t, 0x4);

	struct rectData_s
	{
		ExpressionStatement rectXExp; //OFS: 0x0 SIZE: 0x10
		ExpressionStatement rectYExp; //OFS: 0x10 SIZE: 0x10
		ExpressionStatement rectWExp; //OFS: 0x20 SIZE: 0x10
		ExpressionStatement rectHExp; //OFS: 0x30 SIZE: 0x10
	};
	ASSERT_STRUCT_SIZE(rectData_s, 0x40);
	ASSERT_STRUCT_OFFSET(rectData_s, rectXExp, 0x0);
	ASSERT_STRUCT_OFFSET(rectData_s, rectYExp, 0x10);
	ASSERT_STRUCT_OFFSET(rectData_s, rectWExp, 0x20);
	ASSERT_STRUCT_OFFSET(rectData_s, rectHExp, 0x30);

	struct animParamsDef_t
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		rectDef_s rectClient; //OFS: 0x4 SIZE: 0x18
		float borderSize; //OFS: 0x1C SIZE: 0x4
		vec4_t foreColor; //OFS: 0x20 SIZE: 0x10
		vec4_t backColor; //OFS: 0x30 SIZE: 0x10
		vec4_t borderColor; //OFS: 0x40 SIZE: 0x10
		vec4_t outlineColor; //OFS: 0x50 SIZE: 0x10
		float textScale; //OFS: 0x60 SIZE: 0x4
		float rotation; //OFS: 0x64 SIZE: 0x4
		GenericEventHandler* onEvent; //OFS: 0x68 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(animParamsDef_t, 0x6C);
	ASSERT_STRUCT_OFFSET(animParamsDef_t, name, 0x0);
	ASSERT_STRUCT_OFFSET(animParamsDef_t, rectClient, 0x4);
	ASSERT_STRUCT_OFFSET(animParamsDef_t, borderSize, 0x1C);
	ASSERT_STRUCT_OFFSET(animParamsDef_t, foreColor, 0x20);
	ASSERT_STRUCT_OFFSET(animParamsDef_t, backColor, 0x30);
	ASSERT_STRUCT_OFFSET(animParamsDef_t, borderColor, 0x40);
	ASSERT_STRUCT_OFFSET(animParamsDef_t, outlineColor, 0x50);
	ASSERT_STRUCT_OFFSET(animParamsDef_t, textScale, 0x60);
	ASSERT_STRUCT_OFFSET(animParamsDef_t, rotation, 0x64);
	ASSERT_STRUCT_OFFSET(animParamsDef_t, onEvent, 0x68);

	struct UIAnimInfo
	{
		int animStateCount; //OFS: 0x0 SIZE: 0x4
		animParamsDef_t** animStates; //OFS: 0x4 SIZE: 0x4
		animParamsDef_t currentAnimState; //OFS: 0x8 SIZE: 0x6C
		animParamsDef_t nextAnimState; //OFS: 0x74 SIZE: 0x6C
		int animating; //OFS: 0xE0 SIZE: 0x4
		int animStartTime; //OFS: 0xE4 SIZE: 0x4
		int animDuration; //OFS: 0xE8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(UIAnimInfo, 0xEC);
	ASSERT_STRUCT_OFFSET(UIAnimInfo, animStateCount, 0x0);
	ASSERT_STRUCT_OFFSET(UIAnimInfo, animStates, 0x4);
	ASSERT_STRUCT_OFFSET(UIAnimInfo, currentAnimState, 0x8);
	ASSERT_STRUCT_OFFSET(UIAnimInfo, nextAnimState, 0x74);
	ASSERT_STRUCT_OFFSET(UIAnimInfo, animating, 0xE0);
	ASSERT_STRUCT_OFFSET(UIAnimInfo, animStartTime, 0xE4);
	ASSERT_STRUCT_OFFSET(UIAnimInfo, animDuration, 0xE8);

	struct __declspec(align(8)) itemDef_s
	{
		windowDef_t window; //OFS: 0x0 SIZE: 0xA4
		int type; //OFS: 0xA4 SIZE: 0x4
		int dataType; //OFS: 0xA8 SIZE: 0x4
		int imageTrack; //OFS: 0xAC SIZE: 0x4
		const char* dvar; //OFS: 0xB0 SIZE: 0x4
		const char* profileVar; //OFS: 0xB4 SIZE: 0x4
		const char* dvarTest; //OFS: 0xB8 SIZE: 0x4
		const char* enableDvar; //OFS: 0xBC SIZE: 0x4
		int dvarFlags; //OFS: 0xC0 SIZE: 0x4
		itemDefData_t typeData; //OFS: 0xC4 SIZE: 0x4
		menuDef_t* parent; //OFS: 0xC8 SIZE: 0x4
		rectData_s* rectExpData; //OFS: 0xCC SIZE: 0x4
		ExpressionStatement visibleExp; //OFS: 0xD0 SIZE: 0x10
		unsigned __int64 showBits; //OFS: 0xE0 SIZE: 0x8
		unsigned __int64 hideBits; //OFS: 0xE8 SIZE: 0x8
		ExpressionStatement forecolorAExp; //OFS: 0xF0 SIZE: 0x10
		int ui3dWindowId; //OFS: 0x100 SIZE: 0x4
		GenericEventHandler* onEvent; //OFS: 0x104 SIZE: 0x4
		UIAnimInfo* animInfo; //OFS: 0x108 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(itemDef_s, 0x110);
	ASSERT_STRUCT_OFFSET(itemDef_s, window, 0x0);
	ASSERT_STRUCT_OFFSET(itemDef_s, type, 0xA4);
	ASSERT_STRUCT_OFFSET(itemDef_s, dataType, 0xA8);
	ASSERT_STRUCT_OFFSET(itemDef_s, imageTrack, 0xAC);
	ASSERT_STRUCT_OFFSET(itemDef_s, dvar, 0xB0);
	ASSERT_STRUCT_OFFSET(itemDef_s, profileVar, 0xB4);
	ASSERT_STRUCT_OFFSET(itemDef_s, dvarTest, 0xB8);
	ASSERT_STRUCT_OFFSET(itemDef_s, enableDvar, 0xBC);
	ASSERT_STRUCT_OFFSET(itemDef_s, dvarFlags, 0xC0);
	ASSERT_STRUCT_OFFSET(itemDef_s, typeData, 0xC4);
	ASSERT_STRUCT_OFFSET(itemDef_s, parent, 0xC8);
	ASSERT_STRUCT_OFFSET(itemDef_s, rectExpData, 0xCC);
	ASSERT_STRUCT_OFFSET(itemDef_s, visibleExp, 0xD0);
	ASSERT_STRUCT_OFFSET(itemDef_s, showBits, 0xE0);
	ASSERT_STRUCT_OFFSET(itemDef_s, hideBits, 0xE8);
	ASSERT_STRUCT_OFFSET(itemDef_s, forecolorAExp, 0xF0);
	ASSERT_STRUCT_OFFSET(itemDef_s, ui3dWindowId, 0x100);
	ASSERT_STRUCT_OFFSET(itemDef_s, onEvent, 0x104);
	ASSERT_STRUCT_OFFSET(itemDef_s, animInfo, 0x108);

	struct __declspec(align(8)) menuDef_t
	{
		windowDef_t window; //OFS: 0x0 SIZE: 0xA4
		const char* font; //OFS: 0xA4 SIZE: 0x4
		int fullScreen; //OFS: 0xA8 SIZE: 0x4
		int ui3dWindowId; //OFS: 0xAC SIZE: 0x4
		int itemCount; //OFS: 0xB0 SIZE: 0x4
		int fontIndex; //OFS: 0xB4 SIZE: 0x4
		int cursorItem[1]; //OFS: 0xB8 SIZE: 0x4
		int fadeCycle; //OFS: 0xBC SIZE: 0x4
		int priority; //OFS: 0xC0 SIZE: 0x4
		float fadeClamp; //OFS: 0xC4 SIZE: 0x4
		float fadeAmount; //OFS: 0xC8 SIZE: 0x4
		float fadeInAmount; //OFS: 0xCC SIZE: 0x4
		float blurRadius; //OFS: 0xD0 SIZE: 0x4
		int openSlideSpeed; //OFS: 0xD4 SIZE: 0x4
		int closeSlideSpeed; //OFS: 0xD8 SIZE: 0x4
		int openSlideDirection; //OFS: 0xDC SIZE: 0x4
		int closeSlideDirection; //OFS: 0xE0 SIZE: 0x4
		rectDef_s initialRectInfo; //OFS: 0xE4 SIZE: 0x18
		int openFadingTime; //OFS: 0xFC SIZE: 0x4
		int closeFadingTime; //OFS: 0x100 SIZE: 0x4
		int fadeTimeCounter; //OFS: 0x104 SIZE: 0x4
		int slideTimeCounter; //OFS: 0x108 SIZE: 0x4
		GenericEventHandler* onEvent; //OFS: 0x10C SIZE: 0x4
		ItemKeyHandler* onKey; //OFS: 0x110 SIZE: 0x4
		ExpressionStatement visibleExp; //OFS: 0x114 SIZE: 0x10
		unsigned __int64 showBits; //OFS: 0x128 SIZE: 0x8
		unsigned __int64 hideBits; //OFS: 0x130 SIZE: 0x8
		const char* allowedBinding; //OFS: 0x138 SIZE: 0x4
		const char* soundName; //OFS: 0x13C SIZE: 0x4
		int imageTrack; //OFS: 0x140 SIZE: 0x4
		int control; //OFS: 0x144 SIZE: 0x4
		vec4_t focusColor; //OFS: 0x148 SIZE: 0x10
		vec4_t disableColor; //OFS: 0x158 SIZE: 0x10
		ExpressionStatement rectXExp; //OFS: 0x168 SIZE: 0x10
		ExpressionStatement rectYExp; //OFS: 0x178 SIZE: 0x10
		itemDef_s** items; //OFS: 0x188 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(menuDef_t, 0x190);
	ASSERT_STRUCT_OFFSET(menuDef_t, window, 0x0);
	ASSERT_STRUCT_OFFSET(menuDef_t, font, 0xA4);
	ASSERT_STRUCT_OFFSET(menuDef_t, fullScreen, 0xA8);
	ASSERT_STRUCT_OFFSET(menuDef_t, ui3dWindowId, 0xAC);
	ASSERT_STRUCT_OFFSET(menuDef_t, itemCount, 0xB0);
	ASSERT_STRUCT_OFFSET(menuDef_t, fontIndex, 0xB4);
	ASSERT_STRUCT_OFFSET(menuDef_t, cursorItem, 0xB8);
	ASSERT_STRUCT_OFFSET(menuDef_t, fadeCycle, 0xBC);
	ASSERT_STRUCT_OFFSET(menuDef_t, priority, 0xC0);
	ASSERT_STRUCT_OFFSET(menuDef_t, fadeClamp, 0xC4);
	ASSERT_STRUCT_OFFSET(menuDef_t, fadeAmount, 0xC8);
	ASSERT_STRUCT_OFFSET(menuDef_t, fadeInAmount, 0xCC);
	ASSERT_STRUCT_OFFSET(menuDef_t, blurRadius, 0xD0);
	ASSERT_STRUCT_OFFSET(menuDef_t, openSlideSpeed, 0xD4);
	ASSERT_STRUCT_OFFSET(menuDef_t, closeSlideSpeed, 0xD8);
	ASSERT_STRUCT_OFFSET(menuDef_t, openSlideDirection, 0xDC);
	ASSERT_STRUCT_OFFSET(menuDef_t, closeSlideDirection, 0xE0);
	ASSERT_STRUCT_OFFSET(menuDef_t, initialRectInfo, 0xE4);
	ASSERT_STRUCT_OFFSET(menuDef_t, openFadingTime, 0xFC);
	ASSERT_STRUCT_OFFSET(menuDef_t, closeFadingTime, 0x100);
	ASSERT_STRUCT_OFFSET(menuDef_t, fadeTimeCounter, 0x104);
	ASSERT_STRUCT_OFFSET(menuDef_t, slideTimeCounter, 0x108);
	ASSERT_STRUCT_OFFSET(menuDef_t, onEvent, 0x10C);
	ASSERT_STRUCT_OFFSET(menuDef_t, onKey, 0x110);
	ASSERT_STRUCT_OFFSET(menuDef_t, visibleExp, 0x114);
	ASSERT_STRUCT_OFFSET(menuDef_t, showBits, 0x128);
	ASSERT_STRUCT_OFFSET(menuDef_t, hideBits, 0x130);
	ASSERT_STRUCT_OFFSET(menuDef_t, allowedBinding, 0x138);
	ASSERT_STRUCT_OFFSET(menuDef_t, soundName, 0x13C);
	ASSERT_STRUCT_OFFSET(menuDef_t, imageTrack, 0x140);
	ASSERT_STRUCT_OFFSET(menuDef_t, control, 0x144);
	ASSERT_STRUCT_OFFSET(menuDef_t, focusColor, 0x148);
	ASSERT_STRUCT_OFFSET(menuDef_t, disableColor, 0x158);
	ASSERT_STRUCT_OFFSET(menuDef_t, rectXExp, 0x168);
	ASSERT_STRUCT_OFFSET(menuDef_t, rectYExp, 0x178);
	ASSERT_STRUCT_OFFSET(menuDef_t, items, 0x188);

	struct MenuList
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		int menuCount; //OFS: 0x4 SIZE: 0x4
		menuDef_t** menus; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(MenuList, 0xC);
	ASSERT_STRUCT_OFFSET(MenuList, name, 0x0);
	ASSERT_STRUCT_OFFSET(MenuList, menuCount, 0x4);
	ASSERT_STRUCT_OFFSET(MenuList, menus, 0x8);

	struct LocalizeEntry
	{
		const char* value; //OFS: 0x0 SIZE: 0x4
		const char* name; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(LocalizeEntry, 0x8);
	ASSERT_STRUCT_OFFSET(LocalizeEntry, value, 0x0);
	ASSERT_STRUCT_OFFSET(LocalizeEntry, name, 0x4);

	struct TracerDef
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		tracerType_t type; //OFS: 0x4 SIZE: 0x4
		Material* material; //OFS: 0x8 SIZE: 0x4
		unsigned int drawInterval; //OFS: 0xC SIZE: 0x4
		float speed; //OFS: 0x10 SIZE: 0x4
		float beamLength; //OFS: 0x14 SIZE: 0x4
		float beamWidth; //OFS: 0x18 SIZE: 0x4
		float screwRadius; //OFS: 0x1C SIZE: 0x4
		float screwDist; //OFS: 0x20 SIZE: 0x4
		float fadeTime; //OFS: 0x24 SIZE: 0x4
		float fadeScale; //OFS: 0x28 SIZE: 0x4
		float texRepeatRate; //OFS: 0x2C SIZE: 0x4
		vec4_t colors[5]; //OFS: 0x30 SIZE: 0x50
	};
	ASSERT_STRUCT_SIZE(TracerDef, 0x80);
	ASSERT_STRUCT_OFFSET(TracerDef, name, 0x0);
	ASSERT_STRUCT_OFFSET(TracerDef, type, 0x4);
	ASSERT_STRUCT_OFFSET(TracerDef, material, 0x8);
	ASSERT_STRUCT_OFFSET(TracerDef, drawInterval, 0xC);
	ASSERT_STRUCT_OFFSET(TracerDef, speed, 0x10);
	ASSERT_STRUCT_OFFSET(TracerDef, beamLength, 0x14);
	ASSERT_STRUCT_OFFSET(TracerDef, beamWidth, 0x18);
	ASSERT_STRUCT_OFFSET(TracerDef, screwRadius, 0x1C);
	ASSERT_STRUCT_OFFSET(TracerDef, screwDist, 0x20);
	ASSERT_STRUCT_OFFSET(TracerDef, fadeTime, 0x24);
	ASSERT_STRUCT_OFFSET(TracerDef, fadeScale, 0x28);
	ASSERT_STRUCT_OFFSET(TracerDef, texRepeatRate, 0x2C);
	ASSERT_STRUCT_OFFSET(TracerDef, colors, 0x30);

	struct flameTable
	{
		float flameVar_streamChunkGravityStart; //OFS: 0x0 SIZE: 0x4
		float flameVar_streamChunkGravityEnd; //OFS: 0x4 SIZE: 0x4
		float flameVar_streamChunkMaxSize; //OFS: 0x8 SIZE: 0x4
		float flameVar_streamChunkStartSize; //OFS: 0xC SIZE: 0x4
		float flameVar_streamChunkEndSize; //OFS: 0x10 SIZE: 0x4
		float flameVar_streamChunkStartSizeRand; //OFS: 0x14 SIZE: 0x4
		float flameVar_streamChunkEndSizeRand; //OFS: 0x18 SIZE: 0x4
		float flameVar_streamChunkDistScalar; //OFS: 0x1C SIZE: 0x4
		float flameVar_streamChunkDistSwayScale; //OFS: 0x20 SIZE: 0x4
		float flameVar_streamChunkDistSwayVelMax; //OFS: 0x24 SIZE: 0x4
		float flameVar_streamChunkSpeed; //OFS: 0x28 SIZE: 0x4
		float flameVar_streamChunkDecel; //OFS: 0x2C SIZE: 0x4
		float flameVar_streamChunkVelocityAddScale; //OFS: 0x30 SIZE: 0x4
		float flameVar_streamChunkDuration; //OFS: 0x34 SIZE: 0x4
		float flameVar_streamChunkDurationScaleMaxVel; //OFS: 0x38 SIZE: 0x4
		float flameVar_streamChunkDurationVelScalar; //OFS: 0x3C SIZE: 0x4
		float flameVar_streamChunkSizeSpeedScale; //OFS: 0x40 SIZE: 0x4
		float flameVar_streamChunkSizeAgeScale; //OFS: 0x44 SIZE: 0x4
		float flameVar_streamChunkSpawnFireIntervalStart; //OFS: 0x48 SIZE: 0x4
		float flameVar_streamChunkSpawnFireIntervalEnd; //OFS: 0x4C SIZE: 0x4
		float flameVar_streamChunkSpawnFireMinLifeFrac; //OFS: 0x50 SIZE: 0x4
		float flameVar_streamChunkSpawnFireMaxLifeFrac; //OFS: 0x54 SIZE: 0x4
		float flameVar_streamChunkFireMinLifeFrac; //OFS: 0x58 SIZE: 0x4
		float flameVar_streamChunkFireMinLifeFracStart; //OFS: 0x5C SIZE: 0x4
		float flameVar_streamChunkFireMinLifeFracEnd; //OFS: 0x60 SIZE: 0x4
		float flameVar_streamChunkDripsMinLifeFrac; //OFS: 0x64 SIZE: 0x4
		float flameVar_streamChunkDripsMinLifeFracStart; //OFS: 0x68 SIZE: 0x4
		float flameVar_streamChunkDripsMinLifeFracEnd; //OFS: 0x6C SIZE: 0x4
		float flameVar_streamChunkRotationRange; //OFS: 0x70 SIZE: 0x4
		float flameVar_streamSizeRandSinWave; //OFS: 0x74 SIZE: 0x4
		float flameVar_streamSizeRandCosWave; //OFS: 0x78 SIZE: 0x4
		float flameVar_streamDripsChunkInterval; //OFS: 0x7C SIZE: 0x4
		float flameVar_streamDripsChunkMinFrac; //OFS: 0x80 SIZE: 0x4
		float flameVar_streamDripsChunkRandFrac; //OFS: 0x84 SIZE: 0x4
		float flameVar_streamSmokeChunkInterval; //OFS: 0x88 SIZE: 0x4
		float flameVar_streamSmokeChunkMinFrac; //OFS: 0x8C SIZE: 0x4
		float flameVar_streamSmokeChunkRandFrac; //OFS: 0x90 SIZE: 0x4
		float flameVar_streamChunkCullDistSizeFrac; //OFS: 0x94 SIZE: 0x4
		float flameVar_streamChunkCullMinLife; //OFS: 0x98 SIZE: 0x4
		float flameVar_streamChunkCullMaxLife; //OFS: 0x9C SIZE: 0x4
		float flameVar_streamFuelSizeStart; //OFS: 0xA0 SIZE: 0x4
		float flameVar_streamFuelSizeEnd; //OFS: 0xA4 SIZE: 0x4
		float flameVar_streamFuelLength; //OFS: 0xA8 SIZE: 0x4
		float flameVar_streamFuelNumSegments; //OFS: 0xAC SIZE: 0x4
		float flameVar_streamFuelAnimLoopTime; //OFS: 0xB0 SIZE: 0x4
		float flameVar_streamFlameSizeStart; //OFS: 0xB4 SIZE: 0x4
		float flameVar_streamFlameSizeEnd; //OFS: 0xB8 SIZE: 0x4
		float flameVar_streamFlameLength; //OFS: 0xBC SIZE: 0x4
		float flameVar_streamFlameNumSegments; //OFS: 0xC0 SIZE: 0x4
		float flameVar_streamFlameAnimLoopTime; //OFS: 0xC4 SIZE: 0x4
		float flameVar_streamPrimaryLightRadius; //OFS: 0xC8 SIZE: 0x4
		float flameVar_streamPrimaryLightRadiusFlutter; //OFS: 0xCC SIZE: 0x4
		float flameVar_streamPrimaryLightR; //OFS: 0xD0 SIZE: 0x4
		float flameVar_streamPrimaryLightG; //OFS: 0xD4 SIZE: 0x4
		float flameVar_streamPrimaryLightB; //OFS: 0xD8 SIZE: 0x4
		float flameVar_streamPrimaryLightFlutterR; //OFS: 0xDC SIZE: 0x4
		float flameVar_streamPrimaryLightFlutterG; //OFS: 0xE0 SIZE: 0x4
		float flameVar_streamPrimaryLightFlutterB; //OFS: 0xE4 SIZE: 0x4
		float flameVar_fireLife; //OFS: 0xE8 SIZE: 0x4
		float flameVar_fireLifeRand; //OFS: 0xEC SIZE: 0x4
		float flameVar_fireSpeedScale; //OFS: 0xF0 SIZE: 0x4
		float flameVar_fireSpeedScaleRand; //OFS: 0xF4 SIZE: 0x4
		float flameVar_fireVelocityAddZ; //OFS: 0xF8 SIZE: 0x4
		float flameVar_fireVelocityAddZRand; //OFS: 0xFC SIZE: 0x4
		float flameVar_fireVelocityAddSideways; //OFS: 0x100 SIZE: 0x4
		float flameVar_fireGravity; //OFS: 0x104 SIZE: 0x4
		float flameVar_fireGravityEnd; //OFS: 0x108 SIZE: 0x4
		float flameVar_fireMaxRotVel; //OFS: 0x10C SIZE: 0x4
		float flameVar_fireFriction; //OFS: 0x110 SIZE: 0x4
		float flameVar_fireEndSizeAdd; //OFS: 0x114 SIZE: 0x4
		float flameVar_fireStartSizeScale; //OFS: 0x118 SIZE: 0x4
		float flameVar_fireEndSizeScale; //OFS: 0x11C SIZE: 0x4
		float flameVar_fireBrightness; //OFS: 0x120 SIZE: 0x4
		float flameVar_dripsLife; //OFS: 0x124 SIZE: 0x4
		float flameVar_dripsLifeRand; //OFS: 0x128 SIZE: 0x4
		float flameVar_dripsSpeedScale; //OFS: 0x12C SIZE: 0x4
		float flameVar_dripsSpeedScaleRand; //OFS: 0x130 SIZE: 0x4
		float flameVar_dripsVelocityAddZ; //OFS: 0x134 SIZE: 0x4
		float flameVar_dripsVelocityAddZRand; //OFS: 0x138 SIZE: 0x4
		float flameVar_dripsVelocityAddSideways; //OFS: 0x13C SIZE: 0x4
		float flameVar_dripsGravity; //OFS: 0x140 SIZE: 0x4
		float flameVar_dripsGravityEnd; //OFS: 0x144 SIZE: 0x4
		float flameVar_dripsMaxRotVel; //OFS: 0x148 SIZE: 0x4
		float flameVar_dripsFriction; //OFS: 0x14C SIZE: 0x4
		float flameVar_dripsEndSizeAdd; //OFS: 0x150 SIZE: 0x4
		float flameVar_dripsStartSizeScale; //OFS: 0x154 SIZE: 0x4
		float flameVar_dripsEndSizeScale; //OFS: 0x158 SIZE: 0x4
		float flameVar_dripsBrightness; //OFS: 0x15C SIZE: 0x4
		float flameVar_smokeLife; //OFS: 0x160 SIZE: 0x4
		float flameVar_smokeLifeRand; //OFS: 0x164 SIZE: 0x4
		float flameVar_smokeSpeedScale; //OFS: 0x168 SIZE: 0x4
		float flameVar_smokeVelocityAddZ; //OFS: 0x16C SIZE: 0x4
		float flameVar_smokeGravity; //OFS: 0x170 SIZE: 0x4
		float flameVar_smokeGravityEnd; //OFS: 0x174 SIZE: 0x4
		float flameVar_smokeMaxRotation; //OFS: 0x178 SIZE: 0x4
		float flameVar_smokeMaxRotVel; //OFS: 0x17C SIZE: 0x4
		float flameVar_smokeFriction; //OFS: 0x180 SIZE: 0x4
		float flameVar_smokeEndSizeAdd; //OFS: 0x184 SIZE: 0x4
		float flameVar_smokeStartSizeAdd; //OFS: 0x188 SIZE: 0x4
		float flameVar_smokeOriginSizeOfsZScale; //OFS: 0x18C SIZE: 0x4
		float flameVar_smokeOriginOfsZ; //OFS: 0x190 SIZE: 0x4
		float flameVar_smokeFadein; //OFS: 0x194 SIZE: 0x4
		float flameVar_smokeFadeout; //OFS: 0x198 SIZE: 0x4
		float flameVar_smokeMaxAlpha; //OFS: 0x19C SIZE: 0x4
		float flameVar_smokeBrightness; //OFS: 0x1A0 SIZE: 0x4
		float flameVar_smokeOriginOffset; //OFS: 0x1A4 SIZE: 0x4
		float flameVar_collisionSpeedScale; //OFS: 0x1A8 SIZE: 0x4
		float flameVar_collisionVolumeScale; //OFS: 0x1AC SIZE: 0x4
		const char* name; //OFS: 0x1B0 SIZE: 0x4
		Material* fire; //OFS: 0x1B4 SIZE: 0x4
		Material* smoke; //OFS: 0x1B8 SIZE: 0x4
		Material* heat; //OFS: 0x1BC SIZE: 0x4
		Material* drips; //OFS: 0x1C0 SIZE: 0x4
		Material* streamFuel; //OFS: 0x1C4 SIZE: 0x4
		Material* streamFuel2; //OFS: 0x1C8 SIZE: 0x4
		Material* streamFlame; //OFS: 0x1CC SIZE: 0x4
		Material* streamFlame2; //OFS: 0x1D0 SIZE: 0x4
		const char* flameOffLoopSound; //OFS: 0x1D4 SIZE: 0x4
		const char* flameIgniteSound; //OFS: 0x1D8 SIZE: 0x4
		const char* flameOnLoopSound; //OFS: 0x1DC SIZE: 0x4
		const char* flameCooldownSound; //OFS: 0x1E0 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(flameTable, 0x1E4);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkGravityStart, 0x0);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkGravityEnd, 0x4);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkMaxSize, 0x8);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkStartSize, 0xC);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkEndSize, 0x10);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkStartSizeRand, 0x14);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkEndSizeRand, 0x18);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkDistScalar, 0x1C);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkDistSwayScale, 0x20);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkDistSwayVelMax, 0x24);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkSpeed, 0x28);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkDecel, 0x2C);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkVelocityAddScale, 0x30);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkDuration, 0x34);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkDurationScaleMaxVel, 0x38);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkDurationVelScalar, 0x3C);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkSizeSpeedScale, 0x40);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkSizeAgeScale, 0x44);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkSpawnFireIntervalStart, 0x48);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkSpawnFireIntervalEnd, 0x4C);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkSpawnFireMinLifeFrac, 0x50);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkSpawnFireMaxLifeFrac, 0x54);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkFireMinLifeFrac, 0x58);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkFireMinLifeFracStart, 0x5C);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkFireMinLifeFracEnd, 0x60);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkDripsMinLifeFrac, 0x64);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkDripsMinLifeFracStart, 0x68);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkDripsMinLifeFracEnd, 0x6C);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkRotationRange, 0x70);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamSizeRandSinWave, 0x74);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamSizeRandCosWave, 0x78);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamDripsChunkInterval, 0x7C);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamDripsChunkMinFrac, 0x80);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamDripsChunkRandFrac, 0x84);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamSmokeChunkInterval, 0x88);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamSmokeChunkMinFrac, 0x8C);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamSmokeChunkRandFrac, 0x90);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkCullDistSizeFrac, 0x94);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkCullMinLife, 0x98);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkCullMaxLife, 0x9C);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamFuelSizeStart, 0xA0);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamFuelSizeEnd, 0xA4);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamFuelLength, 0xA8);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamFuelNumSegments, 0xAC);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamFuelAnimLoopTime, 0xB0);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamFlameSizeStart, 0xB4);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamFlameSizeEnd, 0xB8);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamFlameLength, 0xBC);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamFlameNumSegments, 0xC0);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamFlameAnimLoopTime, 0xC4);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamPrimaryLightRadius, 0xC8);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamPrimaryLightRadiusFlutter, 0xCC);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamPrimaryLightR, 0xD0);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamPrimaryLightG, 0xD4);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamPrimaryLightB, 0xD8);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamPrimaryLightFlutterR, 0xDC);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamPrimaryLightFlutterG, 0xE0);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamPrimaryLightFlutterB, 0xE4);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_fireLife, 0xE8);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_fireLifeRand, 0xEC);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_fireSpeedScale, 0xF0);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_fireSpeedScaleRand, 0xF4);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_fireVelocityAddZ, 0xF8);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_fireVelocityAddZRand, 0xFC);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_fireVelocityAddSideways, 0x100);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_fireGravity, 0x104);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_fireGravityEnd, 0x108);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_fireMaxRotVel, 0x10C);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_fireFriction, 0x110);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_fireEndSizeAdd, 0x114);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_fireStartSizeScale, 0x118);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_fireEndSizeScale, 0x11C);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_fireBrightness, 0x120);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_dripsLife, 0x124);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_dripsLifeRand, 0x128);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_dripsSpeedScale, 0x12C);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_dripsSpeedScaleRand, 0x130);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_dripsVelocityAddZ, 0x134);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_dripsVelocityAddZRand, 0x138);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_dripsVelocityAddSideways, 0x13C);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_dripsGravity, 0x140);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_dripsGravityEnd, 0x144);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_dripsMaxRotVel, 0x148);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_dripsFriction, 0x14C);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_dripsEndSizeAdd, 0x150);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_dripsStartSizeScale, 0x154);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_dripsEndSizeScale, 0x158);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_dripsBrightness, 0x15C);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_smokeLife, 0x160);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_smokeLifeRand, 0x164);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_smokeSpeedScale, 0x168);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_smokeVelocityAddZ, 0x16C);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_smokeGravity, 0x170);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_smokeGravityEnd, 0x174);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_smokeMaxRotation, 0x178);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_smokeMaxRotVel, 0x17C);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_smokeFriction, 0x180);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_smokeEndSizeAdd, 0x184);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_smokeStartSizeAdd, 0x188);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_smokeOriginSizeOfsZScale, 0x18C);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_smokeOriginOfsZ, 0x190);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_smokeFadein, 0x194);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_smokeFadeout, 0x198);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_smokeMaxAlpha, 0x19C);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_smokeBrightness, 0x1A0);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_smokeOriginOffset, 0x1A4);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_collisionSpeedScale, 0x1A8);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_collisionVolumeScale, 0x1AC);
	ASSERT_STRUCT_OFFSET(flameTable, name, 0x1B0);
	ASSERT_STRUCT_OFFSET(flameTable, fire, 0x1B4);
	ASSERT_STRUCT_OFFSET(flameTable, smoke, 0x1B8);
	ASSERT_STRUCT_OFFSET(flameTable, heat, 0x1BC);
	ASSERT_STRUCT_OFFSET(flameTable, drips, 0x1C0);
	ASSERT_STRUCT_OFFSET(flameTable, streamFuel, 0x1C4);
	ASSERT_STRUCT_OFFSET(flameTable, streamFuel2, 0x1C8);
	ASSERT_STRUCT_OFFSET(flameTable, streamFlame, 0x1CC);
	ASSERT_STRUCT_OFFSET(flameTable, streamFlame2, 0x1D0);
	ASSERT_STRUCT_OFFSET(flameTable, flameOffLoopSound, 0x1D4);
	ASSERT_STRUCT_OFFSET(flameTable, flameIgniteSound, 0x1D8);
	ASSERT_STRUCT_OFFSET(flameTable, flameOnLoopSound, 0x1DC);
	ASSERT_STRUCT_OFFSET(flameTable, flameCooldownSound, 0x1E0);

	struct WeaponCamoSet
	{
		GfxImage* solidCamoImage; //OFS: 0x0 SIZE: 0x4
		GfxImage* patternCamoImage; //OFS: 0x4 SIZE: 0x4
		vec2_t patternOffset; //OFS: 0x8 SIZE: 0x8
		float patternScale; //OFS: 0x10 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(WeaponCamoSet, 0x14);
	ASSERT_STRUCT_OFFSET(WeaponCamoSet, solidCamoImage, 0x0);
	ASSERT_STRUCT_OFFSET(WeaponCamoSet, patternCamoImage, 0x4);
	ASSERT_STRUCT_OFFSET(WeaponCamoSet, patternOffset, 0x8);
	ASSERT_STRUCT_OFFSET(WeaponCamoSet, patternScale, 0x10);

	struct WeaponCamoMaterial
	{
		unsigned __int16 replaceFlags; //OFS: 0x0 SIZE: 0x2
		unsigned __int16 numBaseMaterials; //OFS: 0x2 SIZE: 0x2
		Material** baseMaterials; //OFS: 0x4 SIZE: 0x4
		Material** camoMaterials; //OFS: 0x8 SIZE: 0x4
		float shaderConsts[8]; //OFS: 0xC SIZE: 0x20
	};
	ASSERT_STRUCT_SIZE(WeaponCamoMaterial, 0x2C);
	ASSERT_STRUCT_OFFSET(WeaponCamoMaterial, replaceFlags, 0x0);
	ASSERT_STRUCT_OFFSET(WeaponCamoMaterial, numBaseMaterials, 0x2);
	ASSERT_STRUCT_OFFSET(WeaponCamoMaterial, baseMaterials, 0x4);
	ASSERT_STRUCT_OFFSET(WeaponCamoMaterial, camoMaterials, 0x8);
	ASSERT_STRUCT_OFFSET(WeaponCamoMaterial, shaderConsts, 0xC);

	struct WeaponCamoMaterialSet
	{
		unsigned int numMaterials; //OFS: 0x0 SIZE: 0x4
		WeaponCamoMaterial* materials; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(WeaponCamoMaterialSet, 0x8);
	ASSERT_STRUCT_OFFSET(WeaponCamoMaterialSet, numMaterials, 0x0);
	ASSERT_STRUCT_OFFSET(WeaponCamoMaterialSet, materials, 0x4);

	struct WeaponCamo
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		GfxImage* solidBaseImage; //OFS: 0x4 SIZE: 0x4
		GfxImage* patternBaseImage; //OFS: 0x8 SIZE: 0x4
		WeaponCamoSet* camoSets; //OFS: 0xC SIZE: 0x4
		unsigned int numCamoSets; //OFS: 0x10 SIZE: 0x4
		WeaponCamoMaterialSet* camoMaterials; //OFS: 0x14 SIZE: 0x4
		unsigned int numCamoMaterials; //OFS: 0x18 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(WeaponCamo, 0x1C);
	ASSERT_STRUCT_OFFSET(WeaponCamo, name, 0x0);
	ASSERT_STRUCT_OFFSET(WeaponCamo, solidBaseImage, 0x4);
	ASSERT_STRUCT_OFFSET(WeaponCamo, patternBaseImage, 0x8);
	ASSERT_STRUCT_OFFSET(WeaponCamo, camoSets, 0xC);
	ASSERT_STRUCT_OFFSET(WeaponCamo, numCamoSets, 0x10);
	ASSERT_STRUCT_OFFSET(WeaponCamo, camoMaterials, 0x14);
	ASSERT_STRUCT_OFFSET(WeaponCamo, numCamoMaterials, 0x18);

	struct WeaponDef
	{
		const char* szOverlayName; //OFS: 0x0 SIZE: 0x4
		XModel** gunXModel; //OFS: 0x4 SIZE: 0x4
		XModel* handXModel; //OFS: 0x8 SIZE: 0x4
		const char* szModeName; //OFS: 0xC SIZE: 0x4
		unsigned __int16* notetrackSoundMapKeys; //OFS: 0x10 SIZE: 0x4
		unsigned __int16* notetrackSoundMapValues; //OFS: 0x14 SIZE: 0x4
		int playerAnimType; //OFS: 0x18 SIZE: 0x4
		weapType_t weapType; //OFS: 0x1C SIZE: 0x4
		weapClass_t weapClass; //OFS: 0x20 SIZE: 0x4
		PenetrateType penetrateType; //OFS: 0x24 SIZE: 0x4
		ImpactType impactType; //OFS: 0x28 SIZE: 0x4
		weapInventoryType_t inventoryType; //OFS: 0x2C SIZE: 0x4
		weapFireType_t fireType; //OFS: 0x30 SIZE: 0x4
		weapClipType_t clipType; //OFS: 0x34 SIZE: 0x4
		barrelType_t barrelType; //OFS: 0x38 SIZE: 0x4
		int itemIndex; //OFS: 0x3C SIZE: 0x4
		const char* parentWeaponName; //OFS: 0x40 SIZE: 0x4
		int iJamFireTime; //OFS: 0x44 SIZE: 0x4
		int overheatWeapon; //OFS: 0x48 SIZE: 0x4
		float overheatRate; //OFS: 0x4C SIZE: 0x4
		float cooldownRate; //OFS: 0x50 SIZE: 0x4
		float overheatEndVal; //OFS: 0x54 SIZE: 0x4
		bool coolWhileFiring; //OFS: 0x58 SIZE: 0x1
		bool fuelTankWeapon; //OFS: 0x59 SIZE: 0x1
		int iTankLifeTime; //OFS: 0x5C SIZE: 0x4
		OffhandClass offhandClass; //OFS: 0x60 SIZE: 0x4
		OffhandSlot offhandSlot; //OFS: 0x64 SIZE: 0x4
		weapStance_t stance; //OFS: 0x68 SIZE: 0x4
		const FxEffectDef* viewFlashEffect; //OFS: 0x6C SIZE: 0x4
		const FxEffectDef* worldFlashEffect; //OFS: 0x70 SIZE: 0x4
		const FxEffectDef* barrelCooldownEffect; //OFS: 0x74 SIZE: 0x4
		int barrelCooldownMinCount; //OFS: 0x78 SIZE: 0x4
		vec3_t vViewFlashOffset; //OFS: 0x7C SIZE: 0xC
		vec3_t vWorldFlashOffset; //OFS: 0x88 SIZE: 0xC
		const char* pickupSound; //OFS: 0x94 SIZE: 0x4
		const char* pickupSoundPlayer; //OFS: 0x98 SIZE: 0x4
		const char* ammoPickupSound; //OFS: 0x9C SIZE: 0x4
		const char* ammoPickupSoundPlayer; //OFS: 0xA0 SIZE: 0x4
		const char* projectileSound; //OFS: 0xA4 SIZE: 0x4
		const char* pullbackSound; //OFS: 0xA8 SIZE: 0x4
		const char* pullbackSoundPlayer; //OFS: 0xAC SIZE: 0x4
		const char* fireSound; //OFS: 0xB0 SIZE: 0x4
		const char* fireSoundPlayer; //OFS: 0xB4 SIZE: 0x4
		const char* fireLoopSound; //OFS: 0xB8 SIZE: 0x4
		const char* fireLoopSoundPlayer; //OFS: 0xBC SIZE: 0x4
		const char* fireLoopEndSound; //OFS: 0xC0 SIZE: 0x4
		const char* fireLoopEndSoundPlayer; //OFS: 0xC4 SIZE: 0x4
		const char* fireStartSound; //OFS: 0xC8 SIZE: 0x4
		const char* fireStopSound; //OFS: 0xCC SIZE: 0x4
		const char* fireKillcamSound; //OFS: 0xD0 SIZE: 0x4
		const char* fireStartSoundPlayer; //OFS: 0xD4 SIZE: 0x4
		const char* fireStopSoundPlayer; //OFS: 0xD8 SIZE: 0x4
		const char* fireKillcamSoundPlayer; //OFS: 0xDC SIZE: 0x4
		const char* fireLastSound; //OFS: 0xE0 SIZE: 0x4
		const char* fireLastSoundPlayer; //OFS: 0xE4 SIZE: 0x4
		const char* emptyFireSound; //OFS: 0xE8 SIZE: 0x4
		const char* emptyFireSoundPlayer; //OFS: 0xEC SIZE: 0x4
		const char* crackSound; //OFS: 0xF0 SIZE: 0x4
		const char* whizbySound; //OFS: 0xF4 SIZE: 0x4
		const char* meleeSwipeSound; //OFS: 0xF8 SIZE: 0x4
		const char* meleeSwipeSoundPlayer; //OFS: 0xFC SIZE: 0x4
		const char* meleeHitSound; //OFS: 0x100 SIZE: 0x4
		const char* meleeMissSound; //OFS: 0x104 SIZE: 0x4
		const char* rechamberSound; //OFS: 0x108 SIZE: 0x4
		const char* rechamberSoundPlayer; //OFS: 0x10C SIZE: 0x4
		const char* reloadSound; //OFS: 0x110 SIZE: 0x4
		const char* reloadSoundPlayer; //OFS: 0x114 SIZE: 0x4
		const char* reloadEmptySound; //OFS: 0x118 SIZE: 0x4
		const char* reloadEmptySoundPlayer; //OFS: 0x11C SIZE: 0x4
		const char* reloadStartSound; //OFS: 0x120 SIZE: 0x4
		const char* reloadStartSoundPlayer; //OFS: 0x124 SIZE: 0x4
		const char* reloadEndSound; //OFS: 0x128 SIZE: 0x4
		const char* reloadEndSoundPlayer; //OFS: 0x12C SIZE: 0x4
		const char* rotateLoopSound; //OFS: 0x130 SIZE: 0x4
		const char* rotateLoopSoundPlayer; //OFS: 0x134 SIZE: 0x4
		const char* rotateStopSound; //OFS: 0x138 SIZE: 0x4
		const char* rotateStopSoundPlayer; //OFS: 0x13C SIZE: 0x4
		const char* deploySound; //OFS: 0x140 SIZE: 0x4
		const char* deploySoundPlayer; //OFS: 0x144 SIZE: 0x4
		const char* finishDeploySound; //OFS: 0x148 SIZE: 0x4
		const char* finishDeploySoundPlayer; //OFS: 0x14C SIZE: 0x4
		const char* breakdownSound; //OFS: 0x150 SIZE: 0x4
		const char* breakdownSoundPlayer; //OFS: 0x154 SIZE: 0x4
		const char* finishBreakdownSound; //OFS: 0x158 SIZE: 0x4
		const char* finishBreakdownSoundPlayer; //OFS: 0x15C SIZE: 0x4
		const char* detonateSound; //OFS: 0x160 SIZE: 0x4
		const char* detonateSoundPlayer; //OFS: 0x164 SIZE: 0x4
		const char* nightVisionWearSound; //OFS: 0x168 SIZE: 0x4
		const char* nightVisionWearSoundPlayer; //OFS: 0x16C SIZE: 0x4
		const char* nightVisionRemoveSound; //OFS: 0x170 SIZE: 0x4
		const char* nightVisionRemoveSoundPlayer; //OFS: 0x174 SIZE: 0x4
		const char* altSwitchSound; //OFS: 0x178 SIZE: 0x4
		const char* altSwitchSoundPlayer; //OFS: 0x17C SIZE: 0x4
		const char* raiseSound; //OFS: 0x180 SIZE: 0x4
		const char* raiseSoundPlayer; //OFS: 0x184 SIZE: 0x4
		const char* firstRaiseSound; //OFS: 0x188 SIZE: 0x4
		const char* firstRaiseSoundPlayer; //OFS: 0x18C SIZE: 0x4
		const char* adsRaiseSoundPlayer; //OFS: 0x190 SIZE: 0x4
		const char* adsLowerSoundPlayer; //OFS: 0x194 SIZE: 0x4
		const char* putawaySound; //OFS: 0x198 SIZE: 0x4
		const char* putawaySoundPlayer; //OFS: 0x19C SIZE: 0x4
		const char* overheatSound; //OFS: 0x1A0 SIZE: 0x4
		const char* overheatSoundPlayer; //OFS: 0x1A4 SIZE: 0x4
		const char* adsZoomSound; //OFS: 0x1A8 SIZE: 0x4
		const char* shellCasing; //OFS: 0x1AC SIZE: 0x4
		const char* shellCasingPlayer; //OFS: 0x1B0 SIZE: 0x4
		const char** bounceSound; //OFS: 0x1B4 SIZE: 0x4
		const char* standMountedWeapdef; //OFS: 0x1B8 SIZE: 0x4
		const char* crouchMountedWeapdef; //OFS: 0x1BC SIZE: 0x4
		const char* proneMountedWeapdef; //OFS: 0x1C0 SIZE: 0x4
		int standMountedIndex; //OFS: 0x1C4 SIZE: 0x4
		int crouchMountedIndex; //OFS: 0x1C8 SIZE: 0x4
		int proneMountedIndex; //OFS: 0x1CC SIZE: 0x4
		const FxEffectDef* viewShellEjectEffect; //OFS: 0x1D0 SIZE: 0x4
		const FxEffectDef* worldShellEjectEffect; //OFS: 0x1D4 SIZE: 0x4
		const FxEffectDef* viewLastShotEjectEffect; //OFS: 0x1D8 SIZE: 0x4
		const FxEffectDef* worldLastShotEjectEffect; //OFS: 0x1DC SIZE: 0x4
		vec3_t vViewShellEjectOffset; //OFS: 0x1E0 SIZE: 0xC
		vec3_t vWorldShellEjectOffset; //OFS: 0x1EC SIZE: 0xC
		vec3_t vViewShellEjectRotation; //OFS: 0x1F8 SIZE: 0xC
		vec3_t vWorldShellEjectRotation; //OFS: 0x204 SIZE: 0xC
		Material* reticleCenter; //OFS: 0x210 SIZE: 0x4
		Material* reticleSide; //OFS: 0x214 SIZE: 0x4
		int iReticleCenterSize; //OFS: 0x218 SIZE: 0x4
		int iReticleSideSize; //OFS: 0x21C SIZE: 0x4
		int iReticleMinOfs; //OFS: 0x220 SIZE: 0x4
		activeReticleType_t activeReticleType; //OFS: 0x224 SIZE: 0x4
		vec3_t vStandMove; //OFS: 0x228 SIZE: 0xC
		vec3_t vStandRot; //OFS: 0x234 SIZE: 0xC
		vec3_t vDuckedOfs; //OFS: 0x240 SIZE: 0xC
		vec3_t vDuckedMove; //OFS: 0x24C SIZE: 0xC
		vec3_t vDuckedSprintOfs; //OFS: 0x258 SIZE: 0xC
		vec3_t vDuckedSprintRot; //OFS: 0x264 SIZE: 0xC
		vec2_t vDuckedSprintBob; //OFS: 0x270 SIZE: 0x8
		float fDuckedSprintCycleScale; //OFS: 0x278 SIZE: 0x4
		vec3_t vSprintOfs; //OFS: 0x27C SIZE: 0xC
		vec3_t vSprintRot; //OFS: 0x288 SIZE: 0xC
		vec2_t vSprintBob; //OFS: 0x294 SIZE: 0x8
		float fSprintCycleScale; //OFS: 0x29C SIZE: 0x4
		vec3_t vLowReadyOfs; //OFS: 0x2A0 SIZE: 0xC
		vec3_t vLowReadyRot; //OFS: 0x2AC SIZE: 0xC
		vec3_t vRideOfs; //OFS: 0x2B8 SIZE: 0xC
		vec3_t vRideRot; //OFS: 0x2C4 SIZE: 0xC
		vec3_t vDtpOfs; //OFS: 0x2D0 SIZE: 0xC
		vec3_t vDtpRot; //OFS: 0x2DC SIZE: 0xC
		vec2_t vDtpBob; //OFS: 0x2E8 SIZE: 0x8
		float fDtpCycleScale; //OFS: 0x2F0 SIZE: 0x4
		vec3_t vMantleOfs; //OFS: 0x2F4 SIZE: 0xC
		vec3_t vMantleRot; //OFS: 0x300 SIZE: 0xC
		vec3_t vSlideOfs; //OFS: 0x30C SIZE: 0xC
		vec3_t vSlideRot; //OFS: 0x318 SIZE: 0xC
		vec3_t vDuckedRot; //OFS: 0x324 SIZE: 0xC
		vec3_t vProneOfs; //OFS: 0x330 SIZE: 0xC
		vec3_t vProneMove; //OFS: 0x33C SIZE: 0xC
		vec3_t vProneRot; //OFS: 0x348 SIZE: 0xC
		vec3_t vStrafeMove; //OFS: 0x354 SIZE: 0xC
		vec3_t vStrafeRot; //OFS: 0x360 SIZE: 0xC
		float fPosMoveRate; //OFS: 0x36C SIZE: 0x4
		float fPosProneMoveRate; //OFS: 0x370 SIZE: 0x4
		float fStandMoveMinSpeed; //OFS: 0x374 SIZE: 0x4
		float fDuckedMoveMinSpeed; //OFS: 0x378 SIZE: 0x4
		float fProneMoveMinSpeed; //OFS: 0x37C SIZE: 0x4
		float fPosRotRate; //OFS: 0x380 SIZE: 0x4
		float fPosProneRotRate; //OFS: 0x384 SIZE: 0x4
		float fStandRotMinSpeed; //OFS: 0x388 SIZE: 0x4
		float fDuckedRotMinSpeed; //OFS: 0x38C SIZE: 0x4
		float fProneRotMinSpeed; //OFS: 0x390 SIZE: 0x4
		XModel** worldModel; //OFS: 0x394 SIZE: 0x4
		XModel* worldClipModel; //OFS: 0x398 SIZE: 0x4
		XModel* rocketModel; //OFS: 0x39C SIZE: 0x4
		XModel* mountedModel; //OFS: 0x3A0 SIZE: 0x4
		XModel* additionalMeleeModel; //OFS: 0x3A4 SIZE: 0x4
		Material* fireTypeIcon; //OFS: 0x3A8 SIZE: 0x4
		Material* hudIcon; //OFS: 0x3AC SIZE: 0x4
		weaponIconRatioType_t hudIconRatio; //OFS: 0x3B0 SIZE: 0x4
		Material* indicatorIcon; //OFS: 0x3B4 SIZE: 0x4
		weaponIconRatioType_t indicatorIconRatio; //OFS: 0x3B8 SIZE: 0x4
		Material* ammoCounterIcon; //OFS: 0x3BC SIZE: 0x4
		weaponIconRatioType_t ammoCounterIconRatio; //OFS: 0x3C0 SIZE: 0x4
		ammoCounterClipType_t ammoCounterClip; //OFS: 0x3C4 SIZE: 0x4
		int iStartAmmo; //OFS: 0x3C8 SIZE: 0x4
		int iMaxAmmo; //OFS: 0x3CC SIZE: 0x4
		int shotCount; //OFS: 0x3D0 SIZE: 0x4
		const char* szSharedAmmoCapName; //OFS: 0x3D4 SIZE: 0x4
		int iSharedAmmoCapIndex; //OFS: 0x3D8 SIZE: 0x4
		int iSharedAmmoCap; //OFS: 0x3DC SIZE: 0x4
		bool unlimitedAmmo; //OFS: 0x3E0 SIZE: 0x1
		bool ammoCountClipRelative; //OFS: 0x3E1 SIZE: 0x1
		int damage[6]; //OFS: 0x3E4 SIZE: 0x18
		float damageRange[6]; //OFS: 0x3FC SIZE: 0x18
		int minPlayerDamage; //OFS: 0x414 SIZE: 0x4
		float damageDuration; //OFS: 0x418 SIZE: 0x4
		float damageInterval; //OFS: 0x41C SIZE: 0x4
		int playerDamage; //OFS: 0x420 SIZE: 0x4
		int iMeleeDamage; //OFS: 0x424 SIZE: 0x4
		int iDamageType; //OFS: 0x428 SIZE: 0x4
		unsigned __int16 explosionTag; //OFS: 0x42C SIZE: 0x2
		int iFireDelay; //OFS: 0x430 SIZE: 0x4
		int iMeleeDelay; //OFS: 0x434 SIZE: 0x4
		int meleeChargeDelay; //OFS: 0x438 SIZE: 0x4
		int iDetonateDelay; //OFS: 0x43C SIZE: 0x4
		int iSpinUpTime; //OFS: 0x440 SIZE: 0x4
		int iSpinDownTime; //OFS: 0x444 SIZE: 0x4
		float spinRate; //OFS: 0x448 SIZE: 0x4
		const char* spinLoopSound; //OFS: 0x44C SIZE: 0x4
		const char* spinLoopSoundPlayer; //OFS: 0x450 SIZE: 0x4
		const char* startSpinSound; //OFS: 0x454 SIZE: 0x4
		const char* startSpinSoundPlayer; //OFS: 0x458 SIZE: 0x4
		const char* stopSpinSound; //OFS: 0x45C SIZE: 0x4
		const char* stopSpinSoundPlayer; //OFS: 0x460 SIZE: 0x4
		bool applySpinPitch; //OFS: 0x464 SIZE: 0x1
		int iFireTime; //OFS: 0x468 SIZE: 0x4
		int iLastFireTime; //OFS: 0x46C SIZE: 0x4
		int iRechamberTime; //OFS: 0x470 SIZE: 0x4
		int iRechamberBoltTime; //OFS: 0x474 SIZE: 0x4
		int iHoldFireTime; //OFS: 0x478 SIZE: 0x4
		int iDetonateTime; //OFS: 0x47C SIZE: 0x4
		int iMeleeTime; //OFS: 0x480 SIZE: 0x4
		int iBurstDelayTime; //OFS: 0x484 SIZE: 0x4
		int meleeChargeTime; //OFS: 0x488 SIZE: 0x4
		int iReloadTimeRight; //OFS: 0x48C SIZE: 0x4
		int iReloadTimeLeft; //OFS: 0x490 SIZE: 0x4
		int reloadShowRocketTime; //OFS: 0x494 SIZE: 0x4
		int iReloadEmptyTimeLeft; //OFS: 0x498 SIZE: 0x4
		int iReloadAddTime; //OFS: 0x49C SIZE: 0x4
		int iReloadEmptyAddTime; //OFS: 0x4A0 SIZE: 0x4
		int iReloadQuickAddTime; //OFS: 0x4A4 SIZE: 0x4
		int iReloadQuickEmptyAddTime; //OFS: 0x4A8 SIZE: 0x4
		int iReloadStartTime; //OFS: 0x4AC SIZE: 0x4
		int iReloadStartAddTime; //OFS: 0x4B0 SIZE: 0x4
		int iReloadEndTime; //OFS: 0x4B4 SIZE: 0x4
		int iDropTime; //OFS: 0x4B8 SIZE: 0x4
		int iRaiseTime; //OFS: 0x4BC SIZE: 0x4
		int iAltDropTime; //OFS: 0x4C0 SIZE: 0x4
		int quickDropTime; //OFS: 0x4C4 SIZE: 0x4
		int quickRaiseTime; //OFS: 0x4C8 SIZE: 0x4
		int iFirstRaiseTime; //OFS: 0x4CC SIZE: 0x4
		int iEmptyRaiseTime; //OFS: 0x4D0 SIZE: 0x4
		int iEmptyDropTime; //OFS: 0x4D4 SIZE: 0x4
		int sprintInTime; //OFS: 0x4D8 SIZE: 0x4
		int sprintLoopTime; //OFS: 0x4DC SIZE: 0x4
		int sprintOutTime; //OFS: 0x4E0 SIZE: 0x4
		int lowReadyInTime; //OFS: 0x4E4 SIZE: 0x4
		int lowReadyLoopTime; //OFS: 0x4E8 SIZE: 0x4
		int lowReadyOutTime; //OFS: 0x4EC SIZE: 0x4
		int contFireInTime; //OFS: 0x4F0 SIZE: 0x4
		int contFireLoopTime; //OFS: 0x4F4 SIZE: 0x4
		int contFireOutTime; //OFS: 0x4F8 SIZE: 0x4
		int dtpInTime; //OFS: 0x4FC SIZE: 0x4
		int dtpLoopTime; //OFS: 0x500 SIZE: 0x4
		int dtpOutTime; //OFS: 0x504 SIZE: 0x4
		int crawlInTime; //OFS: 0x508 SIZE: 0x4
		int crawlForwardTime; //OFS: 0x50C SIZE: 0x4
		int crawlBackTime; //OFS: 0x510 SIZE: 0x4
		int crawlRightTime; //OFS: 0x514 SIZE: 0x4
		int crawlLeftTime; //OFS: 0x518 SIZE: 0x4
		int crawlOutFireTime; //OFS: 0x51C SIZE: 0x4
		int crawlOutTime; //OFS: 0x520 SIZE: 0x4
		int slideInTime; //OFS: 0x524 SIZE: 0x4
		int deployTime; //OFS: 0x528 SIZE: 0x4
		int breakdownTime; //OFS: 0x52C SIZE: 0x4
		int iFlourishTime; //OFS: 0x530 SIZE: 0x4
		int nightVisionWearTime; //OFS: 0x534 SIZE: 0x4
		int nightVisionWearTimeFadeOutEnd; //OFS: 0x538 SIZE: 0x4
		int nightVisionWearTimePowerUp; //OFS: 0x53C SIZE: 0x4
		int nightVisionRemoveTime; //OFS: 0x540 SIZE: 0x4
		int nightVisionRemoveTimePowerDown; //OFS: 0x544 SIZE: 0x4
		int nightVisionRemoveTimeFadeInStart; //OFS: 0x548 SIZE: 0x4
		int fuseTime; //OFS: 0x54C SIZE: 0x4
		int aiFuseTime; //OFS: 0x550 SIZE: 0x4
		int lockOnRadius; //OFS: 0x554 SIZE: 0x4
		int lockOnSpeed; //OFS: 0x558 SIZE: 0x4
		bool requireLockonToFire; //OFS: 0x55C SIZE: 0x1
		bool noAdsWhenMagEmpty; //OFS: 0x55D SIZE: 0x1
		bool avoidDropCleanup; //OFS: 0x55E SIZE: 0x1
		unsigned int stackFire; //OFS: 0x560 SIZE: 0x4
		float stackFireSpread; //OFS: 0x564 SIZE: 0x4
		float stackFireAccuracyDecay; //OFS: 0x568 SIZE: 0x4
		const char* stackSound; //OFS: 0x56C SIZE: 0x4
		float autoAimRange; //OFS: 0x570 SIZE: 0x4
		float aimAssistRange; //OFS: 0x574 SIZE: 0x4
		bool mountableWeapon; //OFS: 0x578 SIZE: 0x1
		float aimPadding; //OFS: 0x57C SIZE: 0x4
		float enemyCrosshairRange; //OFS: 0x580 SIZE: 0x4
		bool crosshairColorChange; //OFS: 0x584 SIZE: 0x1
		float moveSpeedScale; //OFS: 0x588 SIZE: 0x4
		float adsMoveSpeedScale; //OFS: 0x58C SIZE: 0x4
		float sprintDurationScale; //OFS: 0x590 SIZE: 0x4
		weapOverlayReticle_t overlayReticle; //OFS: 0x594 SIZE: 0x4
		WeapOverlayInteface_t overlayInterface; //OFS: 0x598 SIZE: 0x4
		float overlayWidth; //OFS: 0x59C SIZE: 0x4
		float overlayHeight; //OFS: 0x5A0 SIZE: 0x4
		float fAdsBobFactor; //OFS: 0x5A4 SIZE: 0x4
		float fAdsViewBobMult; //OFS: 0x5A8 SIZE: 0x4
		bool bHoldBreathToSteady; //OFS: 0x5AC SIZE: 0x1
		float fHipSpreadStandMin; //OFS: 0x5B0 SIZE: 0x4
		float fHipSpreadDuckedMin; //OFS: 0x5B4 SIZE: 0x4
		float fHipSpreadProneMin; //OFS: 0x5B8 SIZE: 0x4
		float hipSpreadStandMax; //OFS: 0x5BC SIZE: 0x4
		float hipSpreadDuckedMax; //OFS: 0x5C0 SIZE: 0x4
		float hipSpreadProneMax; //OFS: 0x5C4 SIZE: 0x4
		float fHipSpreadDecayRate; //OFS: 0x5C8 SIZE: 0x4
		float fHipSpreadFireAdd; //OFS: 0x5CC SIZE: 0x4
		float fHipSpreadTurnAdd; //OFS: 0x5D0 SIZE: 0x4
		float fHipSpreadMoveAdd; //OFS: 0x5D4 SIZE: 0x4
		float fHipSpreadDuckedDecay; //OFS: 0x5D8 SIZE: 0x4
		float fHipSpreadProneDecay; //OFS: 0x5DC SIZE: 0x4
		float fHipReticleSidePos; //OFS: 0x5E0 SIZE: 0x4
		float fAdsIdleAmount; //OFS: 0x5E4 SIZE: 0x4
		float fHipIdleAmount; //OFS: 0x5E8 SIZE: 0x4
		float adsIdleSpeed; //OFS: 0x5EC SIZE: 0x4
		float hipIdleSpeed; //OFS: 0x5F0 SIZE: 0x4
		float fIdleCrouchFactor; //OFS: 0x5F4 SIZE: 0x4
		float fIdleProneFactor; //OFS: 0x5F8 SIZE: 0x4
		float fGunMaxPitch; //OFS: 0x5FC SIZE: 0x4
		float fGunMaxYaw; //OFS: 0x600 SIZE: 0x4
		float swayMaxAngle; //OFS: 0x604 SIZE: 0x4
		float swayLerpSpeed; //OFS: 0x608 SIZE: 0x4
		float swayPitchScale; //OFS: 0x60C SIZE: 0x4
		float swayYawScale; //OFS: 0x610 SIZE: 0x4
		float swayHorizScale; //OFS: 0x614 SIZE: 0x4
		float swayVertScale; //OFS: 0x618 SIZE: 0x4
		float swayShellShockScale; //OFS: 0x61C SIZE: 0x4
		float adsSwayMaxAngle; //OFS: 0x620 SIZE: 0x4
		float adsSwayLerpSpeed; //OFS: 0x624 SIZE: 0x4
		float adsSwayPitchScale; //OFS: 0x628 SIZE: 0x4
		float adsSwayYawScale; //OFS: 0x62C SIZE: 0x4
		bool sharedAmmo; //OFS: 0x630 SIZE: 0x1
		bool bRifleBullet; //OFS: 0x631 SIZE: 0x1
		bool armorPiercing; //OFS: 0x632 SIZE: 0x1
		bool bAirburstWeapon; //OFS: 0x633 SIZE: 0x1
		bool bBoltAction; //OFS: 0x634 SIZE: 0x1
		bool bUseAltTagFlash; //OFS: 0x635 SIZE: 0x1
		bool bUseAntiLagRewind; //OFS: 0x636 SIZE: 0x1
		bool bIsCarriedKillstreakWeapon; //OFS: 0x637 SIZE: 0x1
		bool aimDownSight; //OFS: 0x638 SIZE: 0x1
		bool bRechamberWhileAds; //OFS: 0x639 SIZE: 0x1
		bool bReloadWhileAds; //OFS: 0x63A SIZE: 0x1
		float adsViewErrorMin; //OFS: 0x63C SIZE: 0x4
		float adsViewErrorMax; //OFS: 0x640 SIZE: 0x4
		bool bCookOffHold; //OFS: 0x644 SIZE: 0x1
		bool bClipOnly; //OFS: 0x645 SIZE: 0x1
		bool bCanUseInVehicle; //OFS: 0x646 SIZE: 0x1
		bool bNoDropsOrRaises; //OFS: 0x647 SIZE: 0x1
		bool adsFireOnly; //OFS: 0x648 SIZE: 0x1
		bool cancelAutoHolsterWhenEmpty; //OFS: 0x649 SIZE: 0x1
		bool suppressAmmoReserveDisplay; //OFS: 0x64A SIZE: 0x1
		bool laserSight; //OFS: 0x64B SIZE: 0x1
		bool laserSightDuringNightvision; //OFS: 0x64C SIZE: 0x1
		bool bHideThirdPerson; //OFS: 0x64D SIZE: 0x1
		bool bHasBayonet; //OFS: 0x64E SIZE: 0x1
		bool bDualWield; //OFS: 0x64F SIZE: 0x1
		bool bExplodeOnGround; //OFS: 0x650 SIZE: 0x1
		bool bThrowBack; //OFS: 0x651 SIZE: 0x1
		bool bRetrievable; //OFS: 0x652 SIZE: 0x1
		bool bDieOnRespawn; //OFS: 0x653 SIZE: 0x1
		bool bNoThirdPersonDropsOrRaises; //OFS: 0x654 SIZE: 0x1
		bool bContinuousFire; //OFS: 0x655 SIZE: 0x1
		bool bNoPing; //OFS: 0x656 SIZE: 0x1
		bool bForceBounce; //OFS: 0x657 SIZE: 0x1
		bool bUseDroppedModelAsStowed; //OFS: 0x658 SIZE: 0x1
		bool bNoQuickDropWhenEmpty; //OFS: 0x659 SIZE: 0x1
		bool bKeepCrosshairWhenADS; //OFS: 0x65A SIZE: 0x1
		bool bUseOnlyAltWeaoponHideTagsInAltMode; //OFS: 0x65B SIZE: 0x1
		bool bAltWeaponAdsOnly; //OFS: 0x65C SIZE: 0x1
		bool bAltWeaponDisableSwitching; //OFS: 0x65D SIZE: 0x1
		Material* killIcon; //OFS: 0x660 SIZE: 0x4
		weaponIconRatioType_t killIconRatio; //OFS: 0x664 SIZE: 0x4
		bool flipKillIcon; //OFS: 0x668 SIZE: 0x1
		bool bNoPartialReload; //OFS: 0x669 SIZE: 0x1
		bool bSegmentedReload; //OFS: 0x66A SIZE: 0x1
		bool bNoADSAutoReload; //OFS: 0x66B SIZE: 0x1
		int iReloadAmmoAdd; //OFS: 0x66C SIZE: 0x4
		int iReloadStartAdd; //OFS: 0x670 SIZE: 0x4
		const char* szSpawnedGrenadeWeaponName; //OFS: 0x674 SIZE: 0x4
		const char* szDualWieldWeaponName; //OFS: 0x678 SIZE: 0x4
		unsigned int dualWieldWeaponIndex; //OFS: 0x67C SIZE: 0x4
		int iDropAmmoMin; //OFS: 0x680 SIZE: 0x4
		int iDropAmmoMax; //OFS: 0x684 SIZE: 0x4
		int iDropClipAmmoMin; //OFS: 0x688 SIZE: 0x4
		int iDropClipAmmoMax; //OFS: 0x68C SIZE: 0x4
		int iShotsBeforeRechamber; //OFS: 0x690 SIZE: 0x4
		bool blocksProne; //OFS: 0x694 SIZE: 0x1
		bool bShowIndicator; //OFS: 0x695 SIZE: 0x1
		int isRollingGrenade; //OFS: 0x698 SIZE: 0x4
		int useBallisticPrediction; //OFS: 0x69C SIZE: 0x4
		int isValuable; //OFS: 0x6A0 SIZE: 0x4
		int isTacticalInsertion; //OFS: 0x6A4 SIZE: 0x4
		bool isReviveWeapon; //OFS: 0x6A8 SIZE: 0x1
		bool bUseRigidBodyOnVehicle; //OFS: 0x6A9 SIZE: 0x1
		int iExplosionRadius; //OFS: 0x6AC SIZE: 0x4
		int iExplosionRadiusMin; //OFS: 0x6B0 SIZE: 0x4
		int iIndicatorRadius; //OFS: 0x6B4 SIZE: 0x4
		int iExplosionInnerDamage; //OFS: 0x6B8 SIZE: 0x4
		int iExplosionOuterDamage; //OFS: 0x6BC SIZE: 0x4
		float damageConeAngle; //OFS: 0x6C0 SIZE: 0x4
		int iProjectileSpeed; //OFS: 0x6C4 SIZE: 0x4
		int iProjectileSpeedUp; //OFS: 0x6C8 SIZE: 0x4
		int iProjectileSpeedRelativeUp; //OFS: 0x6CC SIZE: 0x4
		int iProjectileSpeedForward; //OFS: 0x6D0 SIZE: 0x4
		float fProjectileTakeParentVelocity; //OFS: 0x6D4 SIZE: 0x4
		int iProjectileActivateDist; //OFS: 0x6D8 SIZE: 0x4
		float projLifetime; //OFS: 0x6DC SIZE: 0x4
		float timeToAccelerate; //OFS: 0x6E0 SIZE: 0x4
		float projectileCurvature; //OFS: 0x6E4 SIZE: 0x4
		XModel* projectileModel; //OFS: 0x6E8 SIZE: 0x4
		weapProjExposion_t projExplosion; //OFS: 0x6EC SIZE: 0x4
		const FxEffectDef* projExplosionEffect; //OFS: 0x6F0 SIZE: 0x4
		bool projExplosionEffectForceNormalUp; //OFS: 0x6F4 SIZE: 0x1
		const FxEffectDef* projExplosionEffect2; //OFS: 0x6F8 SIZE: 0x4
		bool projExplosionEffect2ForceNormalUp; //OFS: 0x6FC SIZE: 0x1
		const FxEffectDef* projExplosionEffect3; //OFS: 0x700 SIZE: 0x4
		bool projExplosionEffect3ForceNormalUp; //OFS: 0x704 SIZE: 0x1
		const FxEffectDef* projExplosionEffect4; //OFS: 0x708 SIZE: 0x4
		bool projExplosionEffect4ForceNormalUp; //OFS: 0x70C SIZE: 0x1
		const FxEffectDef* projExplosionEffect5; //OFS: 0x710 SIZE: 0x4
		bool projExplosionEffect5ForceNormalUp; //OFS: 0x714 SIZE: 0x1
		const FxEffectDef* projDudEffect; //OFS: 0x718 SIZE: 0x4
		const char* projExplosionSound; //OFS: 0x71C SIZE: 0x4
		const char* projDudSound; //OFS: 0x720 SIZE: 0x4
		const char* mortarShellSound; //OFS: 0x724 SIZE: 0x4
		const char* tankShellSound; //OFS: 0x728 SIZE: 0x4
		bool bProjImpactExplode; //OFS: 0x72C SIZE: 0x1
		bool bProjSentientImpactExplode; //OFS: 0x72D SIZE: 0x1
		bool bProjExplodeWhenStationary; //OFS: 0x72E SIZE: 0x1
		bool bBulletImpactExplode; //OFS: 0x72F SIZE: 0x1
		WeapStickinessType stickiness; //OFS: 0x730 SIZE: 0x4
		WeapRotateType rotateType; //OFS: 0x734 SIZE: 0x4
		bool plantable; //OFS: 0x738 SIZE: 0x1
		bool hasDetonator; //OFS: 0x739 SIZE: 0x1
		bool timedDetonation; //OFS: 0x73A SIZE: 0x1
		bool bNoCrumpleMissile; //OFS: 0x73B SIZE: 0x1
		bool rotate; //OFS: 0x73C SIZE: 0x1
		bool bKeepRolling; //OFS: 0x73D SIZE: 0x1
		bool holdButtonToThrow; //OFS: 0x73E SIZE: 0x1
		bool offhandHoldIsCancelable; //OFS: 0x73F SIZE: 0x1
		bool freezeMovementWhenFiring; //OFS: 0x740 SIZE: 0x1
		float lowAmmoWarningThreshold; //OFS: 0x744 SIZE: 0x4
		bool bDisallowAtMatchStart; //OFS: 0x748 SIZE: 0x1
		float meleeChargeRange; //OFS: 0x74C SIZE: 0x4
		bool bUseAsMelee; //OFS: 0x750 SIZE: 0x1
		bool isCameraSensor; //OFS: 0x751 SIZE: 0x1
		bool isAcousticSensor; //OFS: 0x752 SIZE: 0x1
		bool isLaserSensor; //OFS: 0x753 SIZE: 0x1
		bool isHoldUseGrenade; //OFS: 0x754 SIZE: 0x1
		float* parallelBounce; //OFS: 0x758 SIZE: 0x4
		float* perpendicularBounce; //OFS: 0x75C SIZE: 0x4
		const FxEffectDef* projTrailEffect; //OFS: 0x760 SIZE: 0x4
		vec3_t vProjectileColor; //OFS: 0x764 SIZE: 0xC
		guidedMissileType_t guidedMissileType; //OFS: 0x770 SIZE: 0x4
		float maxSteeringAccel; //OFS: 0x774 SIZE: 0x4
		int projIgnitionDelay; //OFS: 0x778 SIZE: 0x4
		const FxEffectDef* projIgnitionEffect; //OFS: 0x77C SIZE: 0x4
		const char* projIgnitionSound; //OFS: 0x780 SIZE: 0x4
		float fAdsAimPitch; //OFS: 0x784 SIZE: 0x4
		float fAdsCrosshairInFrac; //OFS: 0x788 SIZE: 0x4
		float fAdsCrosshairOutFrac; //OFS: 0x78C SIZE: 0x4
		int adsGunKickReducedKickBullets; //OFS: 0x790 SIZE: 0x4
		float adsGunKickReducedKickPercent; //OFS: 0x794 SIZE: 0x4
		float fAdsGunKickPitchMin; //OFS: 0x798 SIZE: 0x4
		float fAdsGunKickPitchMax; //OFS: 0x79C SIZE: 0x4
		float fAdsGunKickYawMin; //OFS: 0x7A0 SIZE: 0x4
		float fAdsGunKickYawMax; //OFS: 0x7A4 SIZE: 0x4
		float fAdsGunKickAccel; //OFS: 0x7A8 SIZE: 0x4
		float fAdsGunKickSpeedMax; //OFS: 0x7AC SIZE: 0x4
		float fAdsGunKickSpeedDecay; //OFS: 0x7B0 SIZE: 0x4
		float fAdsGunKickStaticDecay; //OFS: 0x7B4 SIZE: 0x4
		float fAdsViewKickPitchMin; //OFS: 0x7B8 SIZE: 0x4
		float fAdsViewKickPitchMax; //OFS: 0x7BC SIZE: 0x4
		float fAdsViewKickMinMagnitude; //OFS: 0x7C0 SIZE: 0x4
		float fAdsViewKickYawMin; //OFS: 0x7C4 SIZE: 0x4
		float fAdsViewKickYawMax; //OFS: 0x7C8 SIZE: 0x4
		float fAdsRecoilReductionRate; //OFS: 0x7CC SIZE: 0x4
		float fAdsRecoilReductionLimit; //OFS: 0x7D0 SIZE: 0x4
		float fAdsRecoilReturnRate; //OFS: 0x7D4 SIZE: 0x4
		float fAdsViewScatterMin; //OFS: 0x7D8 SIZE: 0x4
		float fAdsViewScatterMax; //OFS: 0x7DC SIZE: 0x4
		float fAdsSpread; //OFS: 0x7E0 SIZE: 0x4
		int hipGunKickReducedKickBullets; //OFS: 0x7E4 SIZE: 0x4
		float hipGunKickReducedKickPercent; //OFS: 0x7E8 SIZE: 0x4
		float fHipGunKickPitchMin; //OFS: 0x7EC SIZE: 0x4
		float fHipGunKickPitchMax; //OFS: 0x7F0 SIZE: 0x4
		float fHipGunKickYawMin; //OFS: 0x7F4 SIZE: 0x4
		float fHipGunKickYawMax; //OFS: 0x7F8 SIZE: 0x4
		float fHipGunKickAccel; //OFS: 0x7FC SIZE: 0x4
		float fHipGunKickSpeedMax; //OFS: 0x800 SIZE: 0x4
		float fHipGunKickSpeedDecay; //OFS: 0x804 SIZE: 0x4
		float fHipGunKickStaticDecay; //OFS: 0x808 SIZE: 0x4
		float fHipViewKickPitchMin; //OFS: 0x80C SIZE: 0x4
		float fHipViewKickPitchMax; //OFS: 0x810 SIZE: 0x4
		float fHipViewKickMinMagnitude; //OFS: 0x814 SIZE: 0x4
		float fHipViewKickYawMin; //OFS: 0x818 SIZE: 0x4
		float fHipViewKickYawMax; //OFS: 0x81C SIZE: 0x4
		float fHipViewScatterMin; //OFS: 0x820 SIZE: 0x4
		float fHipViewScatterMax; //OFS: 0x824 SIZE: 0x4
		float fAdsViewKickCenterDuckedScale; //OFS: 0x828 SIZE: 0x4
		float fAdsViewKickCenterProneScale; //OFS: 0x82C SIZE: 0x4
		float fAntiQuickScopeTime; //OFS: 0x830 SIZE: 0x4
		float fAntiQuickScopeScale; //OFS: 0x834 SIZE: 0x4
		float fAntiQuickScopeSpreadMultiplier; //OFS: 0x838 SIZE: 0x4
		float fAntiQuickScopeSpreadMax; //OFS: 0x83C SIZE: 0x4
		float fAntiQuickScopeSwayFactor; //OFS: 0x840 SIZE: 0x4
		float fightDist; //OFS: 0x844 SIZE: 0x4
		float maxDist; //OFS: 0x848 SIZE: 0x4
		const char* accuracyGraphName[2]; //OFS: 0x84C SIZE: 0x8
		vec2_t* accuracyGraphKnots[2]; //OFS: 0x854 SIZE: 0x8
		vec2_t* originalAccuracyGraphKnots[2]; //OFS: 0x85C SIZE: 0x8
		int accuracyGraphKnotCount[2]; //OFS: 0x864 SIZE: 0x8
		int originalAccuracyGraphKnotCount[2]; //OFS: 0x86C SIZE: 0x8
		int iPositionReloadTransTime; //OFS: 0x874 SIZE: 0x4
		float leftArc; //OFS: 0x878 SIZE: 0x4
		float rightArc; //OFS: 0x87C SIZE: 0x4
		float topArc; //OFS: 0x880 SIZE: 0x4
		float bottomArc; //OFS: 0x884 SIZE: 0x4
		float accuracy; //OFS: 0x888 SIZE: 0x4
		float aiSpread; //OFS: 0x88C SIZE: 0x4
		float playerSpread; //OFS: 0x890 SIZE: 0x4
		float minTurnSpeed[2]; //OFS: 0x894 SIZE: 0x8
		float maxTurnSpeed[2]; //OFS: 0x89C SIZE: 0x8
		float pitchConvergenceTime; //OFS: 0x8A4 SIZE: 0x4
		float yawConvergenceTime; //OFS: 0x8A8 SIZE: 0x4
		float suppressTime; //OFS: 0x8AC SIZE: 0x4
		float maxRange; //OFS: 0x8B0 SIZE: 0x4
		float fAnimHorRotateInc; //OFS: 0x8B4 SIZE: 0x4
		float fPlayerPositionDist; //OFS: 0x8B8 SIZE: 0x4
		const char* szUseHintString; //OFS: 0x8BC SIZE: 0x4
		const char* dropHintString; //OFS: 0x8C0 SIZE: 0x4
		int iUseHintStringIndex; //OFS: 0x8C4 SIZE: 0x4
		int dropHintStringIndex; //OFS: 0x8C8 SIZE: 0x4
		float horizViewJitter; //OFS: 0x8CC SIZE: 0x4
		float vertViewJitter; //OFS: 0x8D0 SIZE: 0x4
		float cameraShakeScale; //OFS: 0x8D4 SIZE: 0x4
		int cameraShakeDuration; //OFS: 0x8D8 SIZE: 0x4
		int cameraShakeRadius; //OFS: 0x8DC SIZE: 0x4
		float explosionCameraShakeScale; //OFS: 0x8E0 SIZE: 0x4
		int explosionCameraShakeDuration; //OFS: 0x8E4 SIZE: 0x4
		int explosionCameraShakeRadius; //OFS: 0x8E8 SIZE: 0x4
		const char* szScript; //OFS: 0x8EC SIZE: 0x4
		float destabilizationRateTime; //OFS: 0x8F0 SIZE: 0x4
		float destabilizationCurvatureMax; //OFS: 0x8F4 SIZE: 0x4
		int destabilizeDistance; //OFS: 0x8F8 SIZE: 0x4
		float* locationDamageMultipliers; //OFS: 0x8FC SIZE: 0x4
		const char* fireRumble; //OFS: 0x900 SIZE: 0x4
		const char* meleeImpactRumble; //OFS: 0x904 SIZE: 0x4
		const char* reloadRumble; //OFS: 0x908 SIZE: 0x4
		const char* explosionRumble; //OFS: 0x90C SIZE: 0x4
		TracerDef* tracerType; //OFS: 0x910 SIZE: 0x4
		TracerDef* enemyTracerType; //OFS: 0x914 SIZE: 0x4
		float adsDofStart; //OFS: 0x918 SIZE: 0x4
		float adsDofEnd; //OFS: 0x91C SIZE: 0x4
		float hipDofStart; //OFS: 0x920 SIZE: 0x4
		float hipDofEnd; //OFS: 0x924 SIZE: 0x4
		float scanSpeed; //OFS: 0x928 SIZE: 0x4
		float scanAccel; //OFS: 0x92C SIZE: 0x4
		int scanPauseTime; //OFS: 0x930 SIZE: 0x4
		const char* flameTableFirstPerson; //OFS: 0x934 SIZE: 0x4
		const char* flameTableThirdPerson; //OFS: 0x938 SIZE: 0x4
		flameTable* flameTableFirstPersonPtr; //OFS: 0x93C SIZE: 0x4
		flameTable* flameTableThirdPersonPtr; //OFS: 0x940 SIZE: 0x4
		const FxEffectDef* tagFx_preparationEffect; //OFS: 0x944 SIZE: 0x4
		const FxEffectDef* tagFlash_preparationEffect; //OFS: 0x948 SIZE: 0x4
		bool doGibbing; //OFS: 0x94C SIZE: 0x1
		float maxGibDistance; //OFS: 0x950 SIZE: 0x4
		float altScopeADSTransInTime; //OFS: 0x954 SIZE: 0x4
		float altScopeADSTransOutTime; //OFS: 0x958 SIZE: 0x4
		int iIntroFireTime; //OFS: 0x95C SIZE: 0x4
		int iIntroFireLength; //OFS: 0x960 SIZE: 0x4
		const FxEffectDef* meleeSwipeEffect; //OFS: 0x964 SIZE: 0x4
		const FxEffectDef* meleeImpactEffect; //OFS: 0x968 SIZE: 0x4
		const FxEffectDef* meleeImpactNoBloodEffect; //OFS: 0x96C SIZE: 0x4
		const char* throwBackType; //OFS: 0x970 SIZE: 0x4
		WeaponCamo* weaponCamo; //OFS: 0x974 SIZE: 0x4
		float customFloat0; //OFS: 0x978 SIZE: 0x4
		float customFloat1; //OFS: 0x97C SIZE: 0x4
		float customFloat2; //OFS: 0x980 SIZE: 0x4
		int customBool0; //OFS: 0x984 SIZE: 0x4
		int customBool1; //OFS: 0x988 SIZE: 0x4
		int customBool2; //OFS: 0x98C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(WeaponDef, 0x990);
	ASSERT_STRUCT_OFFSET(WeaponDef, szOverlayName, 0x0);
	ASSERT_STRUCT_OFFSET(WeaponDef, gunXModel, 0x4);
	ASSERT_STRUCT_OFFSET(WeaponDef, handXModel, 0x8);
	ASSERT_STRUCT_OFFSET(WeaponDef, szModeName, 0xC);
	ASSERT_STRUCT_OFFSET(WeaponDef, notetrackSoundMapKeys, 0x10);
	ASSERT_STRUCT_OFFSET(WeaponDef, notetrackSoundMapValues, 0x14);
	ASSERT_STRUCT_OFFSET(WeaponDef, playerAnimType, 0x18);
	ASSERT_STRUCT_OFFSET(WeaponDef, weapType, 0x1C);
	ASSERT_STRUCT_OFFSET(WeaponDef, weapClass, 0x20);
	ASSERT_STRUCT_OFFSET(WeaponDef, penetrateType, 0x24);
	ASSERT_STRUCT_OFFSET(WeaponDef, impactType, 0x28);
	ASSERT_STRUCT_OFFSET(WeaponDef, inventoryType, 0x2C);
	ASSERT_STRUCT_OFFSET(WeaponDef, fireType, 0x30);
	ASSERT_STRUCT_OFFSET(WeaponDef, clipType, 0x34);
	ASSERT_STRUCT_OFFSET(WeaponDef, barrelType, 0x38);
	ASSERT_STRUCT_OFFSET(WeaponDef, itemIndex, 0x3C);
	ASSERT_STRUCT_OFFSET(WeaponDef, parentWeaponName, 0x40);
	ASSERT_STRUCT_OFFSET(WeaponDef, iJamFireTime, 0x44);
	ASSERT_STRUCT_OFFSET(WeaponDef, overheatWeapon, 0x48);
	ASSERT_STRUCT_OFFSET(WeaponDef, overheatRate, 0x4C);
	ASSERT_STRUCT_OFFSET(WeaponDef, cooldownRate, 0x50);
	ASSERT_STRUCT_OFFSET(WeaponDef, overheatEndVal, 0x54);
	ASSERT_STRUCT_OFFSET(WeaponDef, coolWhileFiring, 0x58);
	ASSERT_STRUCT_OFFSET(WeaponDef, fuelTankWeapon, 0x59);
	ASSERT_STRUCT_OFFSET(WeaponDef, iTankLifeTime, 0x5C);
	ASSERT_STRUCT_OFFSET(WeaponDef, offhandClass, 0x60);
	ASSERT_STRUCT_OFFSET(WeaponDef, offhandSlot, 0x64);
	ASSERT_STRUCT_OFFSET(WeaponDef, stance, 0x68);
	ASSERT_STRUCT_OFFSET(WeaponDef, viewFlashEffect, 0x6C);
	ASSERT_STRUCT_OFFSET(WeaponDef, worldFlashEffect, 0x70);
	ASSERT_STRUCT_OFFSET(WeaponDef, barrelCooldownEffect, 0x74);
	ASSERT_STRUCT_OFFSET(WeaponDef, barrelCooldownMinCount, 0x78);
	ASSERT_STRUCT_OFFSET(WeaponDef, vViewFlashOffset, 0x7C);
	ASSERT_STRUCT_OFFSET(WeaponDef, vWorldFlashOffset, 0x88);
	ASSERT_STRUCT_OFFSET(WeaponDef, pickupSound, 0x94);
	ASSERT_STRUCT_OFFSET(WeaponDef, pickupSoundPlayer, 0x98);
	ASSERT_STRUCT_OFFSET(WeaponDef, ammoPickupSound, 0x9C);
	ASSERT_STRUCT_OFFSET(WeaponDef, ammoPickupSoundPlayer, 0xA0);
	ASSERT_STRUCT_OFFSET(WeaponDef, projectileSound, 0xA4);
	ASSERT_STRUCT_OFFSET(WeaponDef, pullbackSound, 0xA8);
	ASSERT_STRUCT_OFFSET(WeaponDef, pullbackSoundPlayer, 0xAC);
	ASSERT_STRUCT_OFFSET(WeaponDef, fireSound, 0xB0);
	ASSERT_STRUCT_OFFSET(WeaponDef, fireSoundPlayer, 0xB4);
	ASSERT_STRUCT_OFFSET(WeaponDef, fireLoopSound, 0xB8);
	ASSERT_STRUCT_OFFSET(WeaponDef, fireLoopSoundPlayer, 0xBC);
	ASSERT_STRUCT_OFFSET(WeaponDef, fireLoopEndSound, 0xC0);
	ASSERT_STRUCT_OFFSET(WeaponDef, fireLoopEndSoundPlayer, 0xC4);
	ASSERT_STRUCT_OFFSET(WeaponDef, fireStartSound, 0xC8);
	ASSERT_STRUCT_OFFSET(WeaponDef, fireStopSound, 0xCC);
	ASSERT_STRUCT_OFFSET(WeaponDef, fireKillcamSound, 0xD0);
	ASSERT_STRUCT_OFFSET(WeaponDef, fireStartSoundPlayer, 0xD4);
	ASSERT_STRUCT_OFFSET(WeaponDef, fireStopSoundPlayer, 0xD8);
	ASSERT_STRUCT_OFFSET(WeaponDef, fireKillcamSoundPlayer, 0xDC);
	ASSERT_STRUCT_OFFSET(WeaponDef, fireLastSound, 0xE0);
	ASSERT_STRUCT_OFFSET(WeaponDef, fireLastSoundPlayer, 0xE4);
	ASSERT_STRUCT_OFFSET(WeaponDef, emptyFireSound, 0xE8);
	ASSERT_STRUCT_OFFSET(WeaponDef, emptyFireSoundPlayer, 0xEC);
	ASSERT_STRUCT_OFFSET(WeaponDef, crackSound, 0xF0);
	ASSERT_STRUCT_OFFSET(WeaponDef, whizbySound, 0xF4);
	ASSERT_STRUCT_OFFSET(WeaponDef, meleeSwipeSound, 0xF8);
	ASSERT_STRUCT_OFFSET(WeaponDef, meleeSwipeSoundPlayer, 0xFC);
	ASSERT_STRUCT_OFFSET(WeaponDef, meleeHitSound, 0x100);
	ASSERT_STRUCT_OFFSET(WeaponDef, meleeMissSound, 0x104);
	ASSERT_STRUCT_OFFSET(WeaponDef, rechamberSound, 0x108);
	ASSERT_STRUCT_OFFSET(WeaponDef, rechamberSoundPlayer, 0x10C);
	ASSERT_STRUCT_OFFSET(WeaponDef, reloadSound, 0x110);
	ASSERT_STRUCT_OFFSET(WeaponDef, reloadSoundPlayer, 0x114);
	ASSERT_STRUCT_OFFSET(WeaponDef, reloadEmptySound, 0x118);
	ASSERT_STRUCT_OFFSET(WeaponDef, reloadEmptySoundPlayer, 0x11C);
	ASSERT_STRUCT_OFFSET(WeaponDef, reloadStartSound, 0x120);
	ASSERT_STRUCT_OFFSET(WeaponDef, reloadStartSoundPlayer, 0x124);
	ASSERT_STRUCT_OFFSET(WeaponDef, reloadEndSound, 0x128);
	ASSERT_STRUCT_OFFSET(WeaponDef, reloadEndSoundPlayer, 0x12C);
	ASSERT_STRUCT_OFFSET(WeaponDef, rotateLoopSound, 0x130);
	ASSERT_STRUCT_OFFSET(WeaponDef, rotateLoopSoundPlayer, 0x134);
	ASSERT_STRUCT_OFFSET(WeaponDef, rotateStopSound, 0x138);
	ASSERT_STRUCT_OFFSET(WeaponDef, rotateStopSoundPlayer, 0x13C);
	ASSERT_STRUCT_OFFSET(WeaponDef, deploySound, 0x140);
	ASSERT_STRUCT_OFFSET(WeaponDef, deploySoundPlayer, 0x144);
	ASSERT_STRUCT_OFFSET(WeaponDef, finishDeploySound, 0x148);
	ASSERT_STRUCT_OFFSET(WeaponDef, finishDeploySoundPlayer, 0x14C);
	ASSERT_STRUCT_OFFSET(WeaponDef, breakdownSound, 0x150);
	ASSERT_STRUCT_OFFSET(WeaponDef, breakdownSoundPlayer, 0x154);
	ASSERT_STRUCT_OFFSET(WeaponDef, finishBreakdownSound, 0x158);
	ASSERT_STRUCT_OFFSET(WeaponDef, finishBreakdownSoundPlayer, 0x15C);
	ASSERT_STRUCT_OFFSET(WeaponDef, detonateSound, 0x160);
	ASSERT_STRUCT_OFFSET(WeaponDef, detonateSoundPlayer, 0x164);
	ASSERT_STRUCT_OFFSET(WeaponDef, nightVisionWearSound, 0x168);
	ASSERT_STRUCT_OFFSET(WeaponDef, nightVisionWearSoundPlayer, 0x16C);
	ASSERT_STRUCT_OFFSET(WeaponDef, nightVisionRemoveSound, 0x170);
	ASSERT_STRUCT_OFFSET(WeaponDef, nightVisionRemoveSoundPlayer, 0x174);
	ASSERT_STRUCT_OFFSET(WeaponDef, altSwitchSound, 0x178);
	ASSERT_STRUCT_OFFSET(WeaponDef, altSwitchSoundPlayer, 0x17C);
	ASSERT_STRUCT_OFFSET(WeaponDef, raiseSound, 0x180);
	ASSERT_STRUCT_OFFSET(WeaponDef, raiseSoundPlayer, 0x184);
	ASSERT_STRUCT_OFFSET(WeaponDef, firstRaiseSound, 0x188);
	ASSERT_STRUCT_OFFSET(WeaponDef, firstRaiseSoundPlayer, 0x18C);
	ASSERT_STRUCT_OFFSET(WeaponDef, adsRaiseSoundPlayer, 0x190);
	ASSERT_STRUCT_OFFSET(WeaponDef, adsLowerSoundPlayer, 0x194);
	ASSERT_STRUCT_OFFSET(WeaponDef, putawaySound, 0x198);
	ASSERT_STRUCT_OFFSET(WeaponDef, putawaySoundPlayer, 0x19C);
	ASSERT_STRUCT_OFFSET(WeaponDef, overheatSound, 0x1A0);
	ASSERT_STRUCT_OFFSET(WeaponDef, overheatSoundPlayer, 0x1A4);
	ASSERT_STRUCT_OFFSET(WeaponDef, adsZoomSound, 0x1A8);
	ASSERT_STRUCT_OFFSET(WeaponDef, shellCasing, 0x1AC);
	ASSERT_STRUCT_OFFSET(WeaponDef, shellCasingPlayer, 0x1B0);
	ASSERT_STRUCT_OFFSET(WeaponDef, bounceSound, 0x1B4);
	ASSERT_STRUCT_OFFSET(WeaponDef, standMountedWeapdef, 0x1B8);
	ASSERT_STRUCT_OFFSET(WeaponDef, crouchMountedWeapdef, 0x1BC);
	ASSERT_STRUCT_OFFSET(WeaponDef, proneMountedWeapdef, 0x1C0);
	ASSERT_STRUCT_OFFSET(WeaponDef, standMountedIndex, 0x1C4);
	ASSERT_STRUCT_OFFSET(WeaponDef, crouchMountedIndex, 0x1C8);
	ASSERT_STRUCT_OFFSET(WeaponDef, proneMountedIndex, 0x1CC);
	ASSERT_STRUCT_OFFSET(WeaponDef, viewShellEjectEffect, 0x1D0);
	ASSERT_STRUCT_OFFSET(WeaponDef, worldShellEjectEffect, 0x1D4);
	ASSERT_STRUCT_OFFSET(WeaponDef, viewLastShotEjectEffect, 0x1D8);
	ASSERT_STRUCT_OFFSET(WeaponDef, worldLastShotEjectEffect, 0x1DC);
	ASSERT_STRUCT_OFFSET(WeaponDef, vViewShellEjectOffset, 0x1E0);
	ASSERT_STRUCT_OFFSET(WeaponDef, vWorldShellEjectOffset, 0x1EC);
	ASSERT_STRUCT_OFFSET(WeaponDef, vViewShellEjectRotation, 0x1F8);
	ASSERT_STRUCT_OFFSET(WeaponDef, vWorldShellEjectRotation, 0x204);
	ASSERT_STRUCT_OFFSET(WeaponDef, reticleCenter, 0x210);
	ASSERT_STRUCT_OFFSET(WeaponDef, reticleSide, 0x214);
	ASSERT_STRUCT_OFFSET(WeaponDef, iReticleCenterSize, 0x218);
	ASSERT_STRUCT_OFFSET(WeaponDef, iReticleSideSize, 0x21C);
	ASSERT_STRUCT_OFFSET(WeaponDef, iReticleMinOfs, 0x220);
	ASSERT_STRUCT_OFFSET(WeaponDef, activeReticleType, 0x224);
	ASSERT_STRUCT_OFFSET(WeaponDef, vStandMove, 0x228);
	ASSERT_STRUCT_OFFSET(WeaponDef, vStandRot, 0x234);
	ASSERT_STRUCT_OFFSET(WeaponDef, vDuckedOfs, 0x240);
	ASSERT_STRUCT_OFFSET(WeaponDef, vDuckedMove, 0x24C);
	ASSERT_STRUCT_OFFSET(WeaponDef, vDuckedSprintOfs, 0x258);
	ASSERT_STRUCT_OFFSET(WeaponDef, vDuckedSprintRot, 0x264);
	ASSERT_STRUCT_OFFSET(WeaponDef, vDuckedSprintBob, 0x270);
	ASSERT_STRUCT_OFFSET(WeaponDef, fDuckedSprintCycleScale, 0x278);
	ASSERT_STRUCT_OFFSET(WeaponDef, vSprintOfs, 0x27C);
	ASSERT_STRUCT_OFFSET(WeaponDef, vSprintRot, 0x288);
	ASSERT_STRUCT_OFFSET(WeaponDef, vSprintBob, 0x294);
	ASSERT_STRUCT_OFFSET(WeaponDef, fSprintCycleScale, 0x29C);
	ASSERT_STRUCT_OFFSET(WeaponDef, vLowReadyOfs, 0x2A0);
	ASSERT_STRUCT_OFFSET(WeaponDef, vLowReadyRot, 0x2AC);
	ASSERT_STRUCT_OFFSET(WeaponDef, vRideOfs, 0x2B8);
	ASSERT_STRUCT_OFFSET(WeaponDef, vRideRot, 0x2C4);
	ASSERT_STRUCT_OFFSET(WeaponDef, vDtpOfs, 0x2D0);
	ASSERT_STRUCT_OFFSET(WeaponDef, vDtpRot, 0x2DC);
	ASSERT_STRUCT_OFFSET(WeaponDef, vDtpBob, 0x2E8);
	ASSERT_STRUCT_OFFSET(WeaponDef, fDtpCycleScale, 0x2F0);
	ASSERT_STRUCT_OFFSET(WeaponDef, vMantleOfs, 0x2F4);
	ASSERT_STRUCT_OFFSET(WeaponDef, vMantleRot, 0x300);
	ASSERT_STRUCT_OFFSET(WeaponDef, vSlideOfs, 0x30C);
	ASSERT_STRUCT_OFFSET(WeaponDef, vSlideRot, 0x318);
	ASSERT_STRUCT_OFFSET(WeaponDef, vDuckedRot, 0x324);
	ASSERT_STRUCT_OFFSET(WeaponDef, vProneOfs, 0x330);
	ASSERT_STRUCT_OFFSET(WeaponDef, vProneMove, 0x33C);
	ASSERT_STRUCT_OFFSET(WeaponDef, vProneRot, 0x348);
	ASSERT_STRUCT_OFFSET(WeaponDef, vStrafeMove, 0x354);
	ASSERT_STRUCT_OFFSET(WeaponDef, vStrafeRot, 0x360);
	ASSERT_STRUCT_OFFSET(WeaponDef, fPosMoveRate, 0x36C);
	ASSERT_STRUCT_OFFSET(WeaponDef, fPosProneMoveRate, 0x370);
	ASSERT_STRUCT_OFFSET(WeaponDef, fStandMoveMinSpeed, 0x374);
	ASSERT_STRUCT_OFFSET(WeaponDef, fDuckedMoveMinSpeed, 0x378);
	ASSERT_STRUCT_OFFSET(WeaponDef, fProneMoveMinSpeed, 0x37C);
	ASSERT_STRUCT_OFFSET(WeaponDef, fPosRotRate, 0x380);
	ASSERT_STRUCT_OFFSET(WeaponDef, fPosProneRotRate, 0x384);
	ASSERT_STRUCT_OFFSET(WeaponDef, fStandRotMinSpeed, 0x388);
	ASSERT_STRUCT_OFFSET(WeaponDef, fDuckedRotMinSpeed, 0x38C);
	ASSERT_STRUCT_OFFSET(WeaponDef, fProneRotMinSpeed, 0x390);
	ASSERT_STRUCT_OFFSET(WeaponDef, worldModel, 0x394);
	ASSERT_STRUCT_OFFSET(WeaponDef, worldClipModel, 0x398);
	ASSERT_STRUCT_OFFSET(WeaponDef, rocketModel, 0x39C);
	ASSERT_STRUCT_OFFSET(WeaponDef, mountedModel, 0x3A0);
	ASSERT_STRUCT_OFFSET(WeaponDef, additionalMeleeModel, 0x3A4);
	ASSERT_STRUCT_OFFSET(WeaponDef, fireTypeIcon, 0x3A8);
	ASSERT_STRUCT_OFFSET(WeaponDef, hudIcon, 0x3AC);
	ASSERT_STRUCT_OFFSET(WeaponDef, hudIconRatio, 0x3B0);
	ASSERT_STRUCT_OFFSET(WeaponDef, indicatorIcon, 0x3B4);
	ASSERT_STRUCT_OFFSET(WeaponDef, indicatorIconRatio, 0x3B8);
	ASSERT_STRUCT_OFFSET(WeaponDef, ammoCounterIcon, 0x3BC);
	ASSERT_STRUCT_OFFSET(WeaponDef, ammoCounterIconRatio, 0x3C0);
	ASSERT_STRUCT_OFFSET(WeaponDef, ammoCounterClip, 0x3C4);
	ASSERT_STRUCT_OFFSET(WeaponDef, iStartAmmo, 0x3C8);
	ASSERT_STRUCT_OFFSET(WeaponDef, iMaxAmmo, 0x3CC);
	ASSERT_STRUCT_OFFSET(WeaponDef, shotCount, 0x3D0);
	ASSERT_STRUCT_OFFSET(WeaponDef, szSharedAmmoCapName, 0x3D4);
	ASSERT_STRUCT_OFFSET(WeaponDef, iSharedAmmoCapIndex, 0x3D8);
	ASSERT_STRUCT_OFFSET(WeaponDef, iSharedAmmoCap, 0x3DC);
	ASSERT_STRUCT_OFFSET(WeaponDef, unlimitedAmmo, 0x3E0);
	ASSERT_STRUCT_OFFSET(WeaponDef, ammoCountClipRelative, 0x3E1);
	ASSERT_STRUCT_OFFSET(WeaponDef, damage, 0x3E4);
	ASSERT_STRUCT_OFFSET(WeaponDef, damageRange, 0x3FC);
	ASSERT_STRUCT_OFFSET(WeaponDef, minPlayerDamage, 0x414);
	ASSERT_STRUCT_OFFSET(WeaponDef, damageDuration, 0x418);
	ASSERT_STRUCT_OFFSET(WeaponDef, damageInterval, 0x41C);
	ASSERT_STRUCT_OFFSET(WeaponDef, playerDamage, 0x420);
	ASSERT_STRUCT_OFFSET(WeaponDef, iMeleeDamage, 0x424);
	ASSERT_STRUCT_OFFSET(WeaponDef, iDamageType, 0x428);
	ASSERT_STRUCT_OFFSET(WeaponDef, explosionTag, 0x42C);
	ASSERT_STRUCT_OFFSET(WeaponDef, iFireDelay, 0x430);
	ASSERT_STRUCT_OFFSET(WeaponDef, iMeleeDelay, 0x434);
	ASSERT_STRUCT_OFFSET(WeaponDef, meleeChargeDelay, 0x438);
	ASSERT_STRUCT_OFFSET(WeaponDef, iDetonateDelay, 0x43C);
	ASSERT_STRUCT_OFFSET(WeaponDef, iSpinUpTime, 0x440);
	ASSERT_STRUCT_OFFSET(WeaponDef, iSpinDownTime, 0x444);
	ASSERT_STRUCT_OFFSET(WeaponDef, spinRate, 0x448);
	ASSERT_STRUCT_OFFSET(WeaponDef, spinLoopSound, 0x44C);
	ASSERT_STRUCT_OFFSET(WeaponDef, spinLoopSoundPlayer, 0x450);
	ASSERT_STRUCT_OFFSET(WeaponDef, startSpinSound, 0x454);
	ASSERT_STRUCT_OFFSET(WeaponDef, startSpinSoundPlayer, 0x458);
	ASSERT_STRUCT_OFFSET(WeaponDef, stopSpinSound, 0x45C);
	ASSERT_STRUCT_OFFSET(WeaponDef, stopSpinSoundPlayer, 0x460);
	ASSERT_STRUCT_OFFSET(WeaponDef, applySpinPitch, 0x464);
	ASSERT_STRUCT_OFFSET(WeaponDef, iFireTime, 0x468);
	ASSERT_STRUCT_OFFSET(WeaponDef, iLastFireTime, 0x46C);
	ASSERT_STRUCT_OFFSET(WeaponDef, iRechamberTime, 0x470);
	ASSERT_STRUCT_OFFSET(WeaponDef, iRechamberBoltTime, 0x474);
	ASSERT_STRUCT_OFFSET(WeaponDef, iHoldFireTime, 0x478);
	ASSERT_STRUCT_OFFSET(WeaponDef, iDetonateTime, 0x47C);
	ASSERT_STRUCT_OFFSET(WeaponDef, iMeleeTime, 0x480);
	ASSERT_STRUCT_OFFSET(WeaponDef, iBurstDelayTime, 0x484);
	ASSERT_STRUCT_OFFSET(WeaponDef, meleeChargeTime, 0x488);
	ASSERT_STRUCT_OFFSET(WeaponDef, iReloadTimeRight, 0x48C);
	ASSERT_STRUCT_OFFSET(WeaponDef, iReloadTimeLeft, 0x490);
	ASSERT_STRUCT_OFFSET(WeaponDef, reloadShowRocketTime, 0x494);
	ASSERT_STRUCT_OFFSET(WeaponDef, iReloadEmptyTimeLeft, 0x498);
	ASSERT_STRUCT_OFFSET(WeaponDef, iReloadAddTime, 0x49C);
	ASSERT_STRUCT_OFFSET(WeaponDef, iReloadEmptyAddTime, 0x4A0);
	ASSERT_STRUCT_OFFSET(WeaponDef, iReloadQuickAddTime, 0x4A4);
	ASSERT_STRUCT_OFFSET(WeaponDef, iReloadQuickEmptyAddTime, 0x4A8);
	ASSERT_STRUCT_OFFSET(WeaponDef, iReloadStartTime, 0x4AC);
	ASSERT_STRUCT_OFFSET(WeaponDef, iReloadStartAddTime, 0x4B0);
	ASSERT_STRUCT_OFFSET(WeaponDef, iReloadEndTime, 0x4B4);
	ASSERT_STRUCT_OFFSET(WeaponDef, iDropTime, 0x4B8);
	ASSERT_STRUCT_OFFSET(WeaponDef, iRaiseTime, 0x4BC);
	ASSERT_STRUCT_OFFSET(WeaponDef, iAltDropTime, 0x4C0);
	ASSERT_STRUCT_OFFSET(WeaponDef, quickDropTime, 0x4C4);
	ASSERT_STRUCT_OFFSET(WeaponDef, quickRaiseTime, 0x4C8);
	ASSERT_STRUCT_OFFSET(WeaponDef, iFirstRaiseTime, 0x4CC);
	ASSERT_STRUCT_OFFSET(WeaponDef, iEmptyRaiseTime, 0x4D0);
	ASSERT_STRUCT_OFFSET(WeaponDef, iEmptyDropTime, 0x4D4);
	ASSERT_STRUCT_OFFSET(WeaponDef, sprintInTime, 0x4D8);
	ASSERT_STRUCT_OFFSET(WeaponDef, sprintLoopTime, 0x4DC);
	ASSERT_STRUCT_OFFSET(WeaponDef, sprintOutTime, 0x4E0);
	ASSERT_STRUCT_OFFSET(WeaponDef, lowReadyInTime, 0x4E4);
	ASSERT_STRUCT_OFFSET(WeaponDef, lowReadyLoopTime, 0x4E8);
	ASSERT_STRUCT_OFFSET(WeaponDef, lowReadyOutTime, 0x4EC);
	ASSERT_STRUCT_OFFSET(WeaponDef, contFireInTime, 0x4F0);
	ASSERT_STRUCT_OFFSET(WeaponDef, contFireLoopTime, 0x4F4);
	ASSERT_STRUCT_OFFSET(WeaponDef, contFireOutTime, 0x4F8);
	ASSERT_STRUCT_OFFSET(WeaponDef, dtpInTime, 0x4FC);
	ASSERT_STRUCT_OFFSET(WeaponDef, dtpLoopTime, 0x500);
	ASSERT_STRUCT_OFFSET(WeaponDef, dtpOutTime, 0x504);
	ASSERT_STRUCT_OFFSET(WeaponDef, crawlInTime, 0x508);
	ASSERT_STRUCT_OFFSET(WeaponDef, crawlForwardTime, 0x50C);
	ASSERT_STRUCT_OFFSET(WeaponDef, crawlBackTime, 0x510);
	ASSERT_STRUCT_OFFSET(WeaponDef, crawlRightTime, 0x514);
	ASSERT_STRUCT_OFFSET(WeaponDef, crawlLeftTime, 0x518);
	ASSERT_STRUCT_OFFSET(WeaponDef, crawlOutFireTime, 0x51C);
	ASSERT_STRUCT_OFFSET(WeaponDef, crawlOutTime, 0x520);
	ASSERT_STRUCT_OFFSET(WeaponDef, slideInTime, 0x524);
	ASSERT_STRUCT_OFFSET(WeaponDef, deployTime, 0x528);
	ASSERT_STRUCT_OFFSET(WeaponDef, breakdownTime, 0x52C);
	ASSERT_STRUCT_OFFSET(WeaponDef, iFlourishTime, 0x530);
	ASSERT_STRUCT_OFFSET(WeaponDef, nightVisionWearTime, 0x534);
	ASSERT_STRUCT_OFFSET(WeaponDef, nightVisionWearTimeFadeOutEnd, 0x538);
	ASSERT_STRUCT_OFFSET(WeaponDef, nightVisionWearTimePowerUp, 0x53C);
	ASSERT_STRUCT_OFFSET(WeaponDef, nightVisionRemoveTime, 0x540);
	ASSERT_STRUCT_OFFSET(WeaponDef, nightVisionRemoveTimePowerDown, 0x544);
	ASSERT_STRUCT_OFFSET(WeaponDef, nightVisionRemoveTimeFadeInStart, 0x548);
	ASSERT_STRUCT_OFFSET(WeaponDef, fuseTime, 0x54C);
	ASSERT_STRUCT_OFFSET(WeaponDef, aiFuseTime, 0x550);
	ASSERT_STRUCT_OFFSET(WeaponDef, lockOnRadius, 0x554);
	ASSERT_STRUCT_OFFSET(WeaponDef, lockOnSpeed, 0x558);
	ASSERT_STRUCT_OFFSET(WeaponDef, requireLockonToFire, 0x55C);
	ASSERT_STRUCT_OFFSET(WeaponDef, noAdsWhenMagEmpty, 0x55D);
	ASSERT_STRUCT_OFFSET(WeaponDef, avoidDropCleanup, 0x55E);
	ASSERT_STRUCT_OFFSET(WeaponDef, stackFire, 0x560);
	ASSERT_STRUCT_OFFSET(WeaponDef, stackFireSpread, 0x564);
	ASSERT_STRUCT_OFFSET(WeaponDef, stackFireAccuracyDecay, 0x568);
	ASSERT_STRUCT_OFFSET(WeaponDef, stackSound, 0x56C);
	ASSERT_STRUCT_OFFSET(WeaponDef, autoAimRange, 0x570);
	ASSERT_STRUCT_OFFSET(WeaponDef, aimAssistRange, 0x574);
	ASSERT_STRUCT_OFFSET(WeaponDef, mountableWeapon, 0x578);
	ASSERT_STRUCT_OFFSET(WeaponDef, aimPadding, 0x57C);
	ASSERT_STRUCT_OFFSET(WeaponDef, enemyCrosshairRange, 0x580);
	ASSERT_STRUCT_OFFSET(WeaponDef, crosshairColorChange, 0x584);
	ASSERT_STRUCT_OFFSET(WeaponDef, moveSpeedScale, 0x588);
	ASSERT_STRUCT_OFFSET(WeaponDef, adsMoveSpeedScale, 0x58C);
	ASSERT_STRUCT_OFFSET(WeaponDef, sprintDurationScale, 0x590);
	ASSERT_STRUCT_OFFSET(WeaponDef, overlayReticle, 0x594);
	ASSERT_STRUCT_OFFSET(WeaponDef, overlayInterface, 0x598);
	ASSERT_STRUCT_OFFSET(WeaponDef, overlayWidth, 0x59C);
	ASSERT_STRUCT_OFFSET(WeaponDef, overlayHeight, 0x5A0);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAdsBobFactor, 0x5A4);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAdsViewBobMult, 0x5A8);
	ASSERT_STRUCT_OFFSET(WeaponDef, bHoldBreathToSteady, 0x5AC);
	ASSERT_STRUCT_OFFSET(WeaponDef, fHipSpreadStandMin, 0x5B0);
	ASSERT_STRUCT_OFFSET(WeaponDef, fHipSpreadDuckedMin, 0x5B4);
	ASSERT_STRUCT_OFFSET(WeaponDef, fHipSpreadProneMin, 0x5B8);
	ASSERT_STRUCT_OFFSET(WeaponDef, hipSpreadStandMax, 0x5BC);
	ASSERT_STRUCT_OFFSET(WeaponDef, hipSpreadDuckedMax, 0x5C0);
	ASSERT_STRUCT_OFFSET(WeaponDef, hipSpreadProneMax, 0x5C4);
	ASSERT_STRUCT_OFFSET(WeaponDef, fHipSpreadDecayRate, 0x5C8);
	ASSERT_STRUCT_OFFSET(WeaponDef, fHipSpreadFireAdd, 0x5CC);
	ASSERT_STRUCT_OFFSET(WeaponDef, fHipSpreadTurnAdd, 0x5D0);
	ASSERT_STRUCT_OFFSET(WeaponDef, fHipSpreadMoveAdd, 0x5D4);
	ASSERT_STRUCT_OFFSET(WeaponDef, fHipSpreadDuckedDecay, 0x5D8);
	ASSERT_STRUCT_OFFSET(WeaponDef, fHipSpreadProneDecay, 0x5DC);
	ASSERT_STRUCT_OFFSET(WeaponDef, fHipReticleSidePos, 0x5E0);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAdsIdleAmount, 0x5E4);
	ASSERT_STRUCT_OFFSET(WeaponDef, fHipIdleAmount, 0x5E8);
	ASSERT_STRUCT_OFFSET(WeaponDef, adsIdleSpeed, 0x5EC);
	ASSERT_STRUCT_OFFSET(WeaponDef, hipIdleSpeed, 0x5F0);
	ASSERT_STRUCT_OFFSET(WeaponDef, fIdleCrouchFactor, 0x5F4);
	ASSERT_STRUCT_OFFSET(WeaponDef, fIdleProneFactor, 0x5F8);
	ASSERT_STRUCT_OFFSET(WeaponDef, fGunMaxPitch, 0x5FC);
	ASSERT_STRUCT_OFFSET(WeaponDef, fGunMaxYaw, 0x600);
	ASSERT_STRUCT_OFFSET(WeaponDef, swayMaxAngle, 0x604);
	ASSERT_STRUCT_OFFSET(WeaponDef, swayLerpSpeed, 0x608);
	ASSERT_STRUCT_OFFSET(WeaponDef, swayPitchScale, 0x60C);
	ASSERT_STRUCT_OFFSET(WeaponDef, swayYawScale, 0x610);
	ASSERT_STRUCT_OFFSET(WeaponDef, swayHorizScale, 0x614);
	ASSERT_STRUCT_OFFSET(WeaponDef, swayVertScale, 0x618);
	ASSERT_STRUCT_OFFSET(WeaponDef, swayShellShockScale, 0x61C);
	ASSERT_STRUCT_OFFSET(WeaponDef, adsSwayMaxAngle, 0x620);
	ASSERT_STRUCT_OFFSET(WeaponDef, adsSwayLerpSpeed, 0x624);
	ASSERT_STRUCT_OFFSET(WeaponDef, adsSwayPitchScale, 0x628);
	ASSERT_STRUCT_OFFSET(WeaponDef, adsSwayYawScale, 0x62C);
	ASSERT_STRUCT_OFFSET(WeaponDef, sharedAmmo, 0x630);
	ASSERT_STRUCT_OFFSET(WeaponDef, bRifleBullet, 0x631);
	ASSERT_STRUCT_OFFSET(WeaponDef, armorPiercing, 0x632);
	ASSERT_STRUCT_OFFSET(WeaponDef, bAirburstWeapon, 0x633);
	ASSERT_STRUCT_OFFSET(WeaponDef, bBoltAction, 0x634);
	ASSERT_STRUCT_OFFSET(WeaponDef, bUseAltTagFlash, 0x635);
	ASSERT_STRUCT_OFFSET(WeaponDef, bUseAntiLagRewind, 0x636);
	ASSERT_STRUCT_OFFSET(WeaponDef, bIsCarriedKillstreakWeapon, 0x637);
	ASSERT_STRUCT_OFFSET(WeaponDef, aimDownSight, 0x638);
	ASSERT_STRUCT_OFFSET(WeaponDef, bRechamberWhileAds, 0x639);
	ASSERT_STRUCT_OFFSET(WeaponDef, bReloadWhileAds, 0x63A);
	ASSERT_STRUCT_OFFSET(WeaponDef, adsViewErrorMin, 0x63C);
	ASSERT_STRUCT_OFFSET(WeaponDef, adsViewErrorMax, 0x640);
	ASSERT_STRUCT_OFFSET(WeaponDef, bCookOffHold, 0x644);
	ASSERT_STRUCT_OFFSET(WeaponDef, bClipOnly, 0x645);
	ASSERT_STRUCT_OFFSET(WeaponDef, bCanUseInVehicle, 0x646);
	ASSERT_STRUCT_OFFSET(WeaponDef, bNoDropsOrRaises, 0x647);
	ASSERT_STRUCT_OFFSET(WeaponDef, adsFireOnly, 0x648);
	ASSERT_STRUCT_OFFSET(WeaponDef, cancelAutoHolsterWhenEmpty, 0x649);
	ASSERT_STRUCT_OFFSET(WeaponDef, suppressAmmoReserveDisplay, 0x64A);
	ASSERT_STRUCT_OFFSET(WeaponDef, laserSight, 0x64B);
	ASSERT_STRUCT_OFFSET(WeaponDef, laserSightDuringNightvision, 0x64C);
	ASSERT_STRUCT_OFFSET(WeaponDef, bHideThirdPerson, 0x64D);
	ASSERT_STRUCT_OFFSET(WeaponDef, bHasBayonet, 0x64E);
	ASSERT_STRUCT_OFFSET(WeaponDef, bDualWield, 0x64F);
	ASSERT_STRUCT_OFFSET(WeaponDef, bExplodeOnGround, 0x650);
	ASSERT_STRUCT_OFFSET(WeaponDef, bThrowBack, 0x651);
	ASSERT_STRUCT_OFFSET(WeaponDef, bRetrievable, 0x652);
	ASSERT_STRUCT_OFFSET(WeaponDef, bDieOnRespawn, 0x653);
	ASSERT_STRUCT_OFFSET(WeaponDef, bNoThirdPersonDropsOrRaises, 0x654);
	ASSERT_STRUCT_OFFSET(WeaponDef, bContinuousFire, 0x655);
	ASSERT_STRUCT_OFFSET(WeaponDef, bNoPing, 0x656);
	ASSERT_STRUCT_OFFSET(WeaponDef, bForceBounce, 0x657);
	ASSERT_STRUCT_OFFSET(WeaponDef, bUseDroppedModelAsStowed, 0x658);
	ASSERT_STRUCT_OFFSET(WeaponDef, bNoQuickDropWhenEmpty, 0x659);
	ASSERT_STRUCT_OFFSET(WeaponDef, bKeepCrosshairWhenADS, 0x65A);
	ASSERT_STRUCT_OFFSET(WeaponDef, bUseOnlyAltWeaoponHideTagsInAltMode, 0x65B);
	ASSERT_STRUCT_OFFSET(WeaponDef, bAltWeaponAdsOnly, 0x65C);
	ASSERT_STRUCT_OFFSET(WeaponDef, bAltWeaponDisableSwitching, 0x65D);
	ASSERT_STRUCT_OFFSET(WeaponDef, killIcon, 0x660);
	ASSERT_STRUCT_OFFSET(WeaponDef, killIconRatio, 0x664);
	ASSERT_STRUCT_OFFSET(WeaponDef, flipKillIcon, 0x668);
	ASSERT_STRUCT_OFFSET(WeaponDef, bNoPartialReload, 0x669);
	ASSERT_STRUCT_OFFSET(WeaponDef, bSegmentedReload, 0x66A);
	ASSERT_STRUCT_OFFSET(WeaponDef, bNoADSAutoReload, 0x66B);
	ASSERT_STRUCT_OFFSET(WeaponDef, iReloadAmmoAdd, 0x66C);
	ASSERT_STRUCT_OFFSET(WeaponDef, iReloadStartAdd, 0x670);
	ASSERT_STRUCT_OFFSET(WeaponDef, szSpawnedGrenadeWeaponName, 0x674);
	ASSERT_STRUCT_OFFSET(WeaponDef, szDualWieldWeaponName, 0x678);
	ASSERT_STRUCT_OFFSET(WeaponDef, dualWieldWeaponIndex, 0x67C);
	ASSERT_STRUCT_OFFSET(WeaponDef, iDropAmmoMin, 0x680);
	ASSERT_STRUCT_OFFSET(WeaponDef, iDropAmmoMax, 0x684);
	ASSERT_STRUCT_OFFSET(WeaponDef, iDropClipAmmoMin, 0x688);
	ASSERT_STRUCT_OFFSET(WeaponDef, iDropClipAmmoMax, 0x68C);
	ASSERT_STRUCT_OFFSET(WeaponDef, iShotsBeforeRechamber, 0x690);
	ASSERT_STRUCT_OFFSET(WeaponDef, blocksProne, 0x694);
	ASSERT_STRUCT_OFFSET(WeaponDef, bShowIndicator, 0x695);
	ASSERT_STRUCT_OFFSET(WeaponDef, isRollingGrenade, 0x698);
	ASSERT_STRUCT_OFFSET(WeaponDef, useBallisticPrediction, 0x69C);
	ASSERT_STRUCT_OFFSET(WeaponDef, isValuable, 0x6A0);
	ASSERT_STRUCT_OFFSET(WeaponDef, isTacticalInsertion, 0x6A4);
	ASSERT_STRUCT_OFFSET(WeaponDef, isReviveWeapon, 0x6A8);
	ASSERT_STRUCT_OFFSET(WeaponDef, bUseRigidBodyOnVehicle, 0x6A9);
	ASSERT_STRUCT_OFFSET(WeaponDef, iExplosionRadius, 0x6AC);
	ASSERT_STRUCT_OFFSET(WeaponDef, iExplosionRadiusMin, 0x6B0);
	ASSERT_STRUCT_OFFSET(WeaponDef, iIndicatorRadius, 0x6B4);
	ASSERT_STRUCT_OFFSET(WeaponDef, iExplosionInnerDamage, 0x6B8);
	ASSERT_STRUCT_OFFSET(WeaponDef, iExplosionOuterDamage, 0x6BC);
	ASSERT_STRUCT_OFFSET(WeaponDef, damageConeAngle, 0x6C0);
	ASSERT_STRUCT_OFFSET(WeaponDef, iProjectileSpeed, 0x6C4);
	ASSERT_STRUCT_OFFSET(WeaponDef, iProjectileSpeedUp, 0x6C8);
	ASSERT_STRUCT_OFFSET(WeaponDef, iProjectileSpeedRelativeUp, 0x6CC);
	ASSERT_STRUCT_OFFSET(WeaponDef, iProjectileSpeedForward, 0x6D0);
	ASSERT_STRUCT_OFFSET(WeaponDef, fProjectileTakeParentVelocity, 0x6D4);
	ASSERT_STRUCT_OFFSET(WeaponDef, iProjectileActivateDist, 0x6D8);
	ASSERT_STRUCT_OFFSET(WeaponDef, projLifetime, 0x6DC);
	ASSERT_STRUCT_OFFSET(WeaponDef, timeToAccelerate, 0x6E0);
	ASSERT_STRUCT_OFFSET(WeaponDef, projectileCurvature, 0x6E4);
	ASSERT_STRUCT_OFFSET(WeaponDef, projectileModel, 0x6E8);
	ASSERT_STRUCT_OFFSET(WeaponDef, projExplosion, 0x6EC);
	ASSERT_STRUCT_OFFSET(WeaponDef, projExplosionEffect, 0x6F0);
	ASSERT_STRUCT_OFFSET(WeaponDef, projExplosionEffectForceNormalUp, 0x6F4);
	ASSERT_STRUCT_OFFSET(WeaponDef, projExplosionEffect2, 0x6F8);
	ASSERT_STRUCT_OFFSET(WeaponDef, projExplosionEffect2ForceNormalUp, 0x6FC);
	ASSERT_STRUCT_OFFSET(WeaponDef, projExplosionEffect3, 0x700);
	ASSERT_STRUCT_OFFSET(WeaponDef, projExplosionEffect3ForceNormalUp, 0x704);
	ASSERT_STRUCT_OFFSET(WeaponDef, projExplosionEffect4, 0x708);
	ASSERT_STRUCT_OFFSET(WeaponDef, projExplosionEffect4ForceNormalUp, 0x70C);
	ASSERT_STRUCT_OFFSET(WeaponDef, projExplosionEffect5, 0x710);
	ASSERT_STRUCT_OFFSET(WeaponDef, projExplosionEffect5ForceNormalUp, 0x714);
	ASSERT_STRUCT_OFFSET(WeaponDef, projDudEffect, 0x718);
	ASSERT_STRUCT_OFFSET(WeaponDef, projExplosionSound, 0x71C);
	ASSERT_STRUCT_OFFSET(WeaponDef, projDudSound, 0x720);
	ASSERT_STRUCT_OFFSET(WeaponDef, mortarShellSound, 0x724);
	ASSERT_STRUCT_OFFSET(WeaponDef, tankShellSound, 0x728);
	ASSERT_STRUCT_OFFSET(WeaponDef, bProjImpactExplode, 0x72C);
	ASSERT_STRUCT_OFFSET(WeaponDef, bProjSentientImpactExplode, 0x72D);
	ASSERT_STRUCT_OFFSET(WeaponDef, bProjExplodeWhenStationary, 0x72E);
	ASSERT_STRUCT_OFFSET(WeaponDef, bBulletImpactExplode, 0x72F);
	ASSERT_STRUCT_OFFSET(WeaponDef, stickiness, 0x730);
	ASSERT_STRUCT_OFFSET(WeaponDef, rotateType, 0x734);
	ASSERT_STRUCT_OFFSET(WeaponDef, plantable, 0x738);
	ASSERT_STRUCT_OFFSET(WeaponDef, hasDetonator, 0x739);
	ASSERT_STRUCT_OFFSET(WeaponDef, timedDetonation, 0x73A);
	ASSERT_STRUCT_OFFSET(WeaponDef, bNoCrumpleMissile, 0x73B);
	ASSERT_STRUCT_OFFSET(WeaponDef, rotate, 0x73C);
	ASSERT_STRUCT_OFFSET(WeaponDef, bKeepRolling, 0x73D);
	ASSERT_STRUCT_OFFSET(WeaponDef, holdButtonToThrow, 0x73E);
	ASSERT_STRUCT_OFFSET(WeaponDef, offhandHoldIsCancelable, 0x73F);
	ASSERT_STRUCT_OFFSET(WeaponDef, freezeMovementWhenFiring, 0x740);
	ASSERT_STRUCT_OFFSET(WeaponDef, lowAmmoWarningThreshold, 0x744);
	ASSERT_STRUCT_OFFSET(WeaponDef, bDisallowAtMatchStart, 0x748);
	ASSERT_STRUCT_OFFSET(WeaponDef, meleeChargeRange, 0x74C);
	ASSERT_STRUCT_OFFSET(WeaponDef, bUseAsMelee, 0x750);
	ASSERT_STRUCT_OFFSET(WeaponDef, isCameraSensor, 0x751);
	ASSERT_STRUCT_OFFSET(WeaponDef, isAcousticSensor, 0x752);
	ASSERT_STRUCT_OFFSET(WeaponDef, isLaserSensor, 0x753);
	ASSERT_STRUCT_OFFSET(WeaponDef, isHoldUseGrenade, 0x754);
	ASSERT_STRUCT_OFFSET(WeaponDef, parallelBounce, 0x758);
	ASSERT_STRUCT_OFFSET(WeaponDef, perpendicularBounce, 0x75C);
	ASSERT_STRUCT_OFFSET(WeaponDef, projTrailEffect, 0x760);
	ASSERT_STRUCT_OFFSET(WeaponDef, vProjectileColor, 0x764);
	ASSERT_STRUCT_OFFSET(WeaponDef, guidedMissileType, 0x770);
	ASSERT_STRUCT_OFFSET(WeaponDef, maxSteeringAccel, 0x774);
	ASSERT_STRUCT_OFFSET(WeaponDef, projIgnitionDelay, 0x778);
	ASSERT_STRUCT_OFFSET(WeaponDef, projIgnitionEffect, 0x77C);
	ASSERT_STRUCT_OFFSET(WeaponDef, projIgnitionSound, 0x780);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAdsAimPitch, 0x784);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAdsCrosshairInFrac, 0x788);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAdsCrosshairOutFrac, 0x78C);
	ASSERT_STRUCT_OFFSET(WeaponDef, adsGunKickReducedKickBullets, 0x790);
	ASSERT_STRUCT_OFFSET(WeaponDef, adsGunKickReducedKickPercent, 0x794);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAdsGunKickPitchMin, 0x798);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAdsGunKickPitchMax, 0x79C);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAdsGunKickYawMin, 0x7A0);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAdsGunKickYawMax, 0x7A4);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAdsGunKickAccel, 0x7A8);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAdsGunKickSpeedMax, 0x7AC);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAdsGunKickSpeedDecay, 0x7B0);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAdsGunKickStaticDecay, 0x7B4);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAdsViewKickPitchMin, 0x7B8);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAdsViewKickPitchMax, 0x7BC);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAdsViewKickMinMagnitude, 0x7C0);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAdsViewKickYawMin, 0x7C4);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAdsViewKickYawMax, 0x7C8);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAdsRecoilReductionRate, 0x7CC);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAdsRecoilReductionLimit, 0x7D0);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAdsRecoilReturnRate, 0x7D4);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAdsViewScatterMin, 0x7D8);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAdsViewScatterMax, 0x7DC);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAdsSpread, 0x7E0);
	ASSERT_STRUCT_OFFSET(WeaponDef, hipGunKickReducedKickBullets, 0x7E4);
	ASSERT_STRUCT_OFFSET(WeaponDef, hipGunKickReducedKickPercent, 0x7E8);
	ASSERT_STRUCT_OFFSET(WeaponDef, fHipGunKickPitchMin, 0x7EC);
	ASSERT_STRUCT_OFFSET(WeaponDef, fHipGunKickPitchMax, 0x7F0);
	ASSERT_STRUCT_OFFSET(WeaponDef, fHipGunKickYawMin, 0x7F4);
	ASSERT_STRUCT_OFFSET(WeaponDef, fHipGunKickYawMax, 0x7F8);
	ASSERT_STRUCT_OFFSET(WeaponDef, fHipGunKickAccel, 0x7FC);
	ASSERT_STRUCT_OFFSET(WeaponDef, fHipGunKickSpeedMax, 0x800);
	ASSERT_STRUCT_OFFSET(WeaponDef, fHipGunKickSpeedDecay, 0x804);
	ASSERT_STRUCT_OFFSET(WeaponDef, fHipGunKickStaticDecay, 0x808);
	ASSERT_STRUCT_OFFSET(WeaponDef, fHipViewKickPitchMin, 0x80C);
	ASSERT_STRUCT_OFFSET(WeaponDef, fHipViewKickPitchMax, 0x810);
	ASSERT_STRUCT_OFFSET(WeaponDef, fHipViewKickMinMagnitude, 0x814);
	ASSERT_STRUCT_OFFSET(WeaponDef, fHipViewKickYawMin, 0x818);
	ASSERT_STRUCT_OFFSET(WeaponDef, fHipViewKickYawMax, 0x81C);
	ASSERT_STRUCT_OFFSET(WeaponDef, fHipViewScatterMin, 0x820);
	ASSERT_STRUCT_OFFSET(WeaponDef, fHipViewScatterMax, 0x824);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAdsViewKickCenterDuckedScale, 0x828);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAdsViewKickCenterProneScale, 0x82C);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAntiQuickScopeTime, 0x830);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAntiQuickScopeScale, 0x834);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAntiQuickScopeSpreadMultiplier, 0x838);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAntiQuickScopeSpreadMax, 0x83C);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAntiQuickScopeSwayFactor, 0x840);
	ASSERT_STRUCT_OFFSET(WeaponDef, fightDist, 0x844);
	ASSERT_STRUCT_OFFSET(WeaponDef, maxDist, 0x848);
	ASSERT_STRUCT_OFFSET(WeaponDef, accuracyGraphName, 0x84C);
	ASSERT_STRUCT_OFFSET(WeaponDef, accuracyGraphKnots, 0x854);
	ASSERT_STRUCT_OFFSET(WeaponDef, originalAccuracyGraphKnots, 0x85C);
	ASSERT_STRUCT_OFFSET(WeaponDef, accuracyGraphKnotCount, 0x864);
	ASSERT_STRUCT_OFFSET(WeaponDef, originalAccuracyGraphKnotCount, 0x86C);
	ASSERT_STRUCT_OFFSET(WeaponDef, iPositionReloadTransTime, 0x874);
	ASSERT_STRUCT_OFFSET(WeaponDef, leftArc, 0x878);
	ASSERT_STRUCT_OFFSET(WeaponDef, rightArc, 0x87C);
	ASSERT_STRUCT_OFFSET(WeaponDef, topArc, 0x880);
	ASSERT_STRUCT_OFFSET(WeaponDef, bottomArc, 0x884);
	ASSERT_STRUCT_OFFSET(WeaponDef, accuracy, 0x888);
	ASSERT_STRUCT_OFFSET(WeaponDef, aiSpread, 0x88C);
	ASSERT_STRUCT_OFFSET(WeaponDef, playerSpread, 0x890);
	ASSERT_STRUCT_OFFSET(WeaponDef, minTurnSpeed, 0x894);
	ASSERT_STRUCT_OFFSET(WeaponDef, maxTurnSpeed, 0x89C);
	ASSERT_STRUCT_OFFSET(WeaponDef, pitchConvergenceTime, 0x8A4);
	ASSERT_STRUCT_OFFSET(WeaponDef, yawConvergenceTime, 0x8A8);
	ASSERT_STRUCT_OFFSET(WeaponDef, suppressTime, 0x8AC);
	ASSERT_STRUCT_OFFSET(WeaponDef, maxRange, 0x8B0);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAnimHorRotateInc, 0x8B4);
	ASSERT_STRUCT_OFFSET(WeaponDef, fPlayerPositionDist, 0x8B8);
	ASSERT_STRUCT_OFFSET(WeaponDef, szUseHintString, 0x8BC);
	ASSERT_STRUCT_OFFSET(WeaponDef, dropHintString, 0x8C0);
	ASSERT_STRUCT_OFFSET(WeaponDef, iUseHintStringIndex, 0x8C4);
	ASSERT_STRUCT_OFFSET(WeaponDef, dropHintStringIndex, 0x8C8);
	ASSERT_STRUCT_OFFSET(WeaponDef, horizViewJitter, 0x8CC);
	ASSERT_STRUCT_OFFSET(WeaponDef, vertViewJitter, 0x8D0);
	ASSERT_STRUCT_OFFSET(WeaponDef, cameraShakeScale, 0x8D4);
	ASSERT_STRUCT_OFFSET(WeaponDef, cameraShakeDuration, 0x8D8);
	ASSERT_STRUCT_OFFSET(WeaponDef, cameraShakeRadius, 0x8DC);
	ASSERT_STRUCT_OFFSET(WeaponDef, explosionCameraShakeScale, 0x8E0);
	ASSERT_STRUCT_OFFSET(WeaponDef, explosionCameraShakeDuration, 0x8E4);
	ASSERT_STRUCT_OFFSET(WeaponDef, explosionCameraShakeRadius, 0x8E8);
	ASSERT_STRUCT_OFFSET(WeaponDef, szScript, 0x8EC);
	ASSERT_STRUCT_OFFSET(WeaponDef, destabilizationRateTime, 0x8F0);
	ASSERT_STRUCT_OFFSET(WeaponDef, destabilizationCurvatureMax, 0x8F4);
	ASSERT_STRUCT_OFFSET(WeaponDef, destabilizeDistance, 0x8F8);
	ASSERT_STRUCT_OFFSET(WeaponDef, locationDamageMultipliers, 0x8FC);
	ASSERT_STRUCT_OFFSET(WeaponDef, fireRumble, 0x900);
	ASSERT_STRUCT_OFFSET(WeaponDef, meleeImpactRumble, 0x904);
	ASSERT_STRUCT_OFFSET(WeaponDef, reloadRumble, 0x908);
	ASSERT_STRUCT_OFFSET(WeaponDef, explosionRumble, 0x90C);
	ASSERT_STRUCT_OFFSET(WeaponDef, tracerType, 0x910);
	ASSERT_STRUCT_OFFSET(WeaponDef, enemyTracerType, 0x914);
	ASSERT_STRUCT_OFFSET(WeaponDef, adsDofStart, 0x918);
	ASSERT_STRUCT_OFFSET(WeaponDef, adsDofEnd, 0x91C);
	ASSERT_STRUCT_OFFSET(WeaponDef, hipDofStart, 0x920);
	ASSERT_STRUCT_OFFSET(WeaponDef, hipDofEnd, 0x924);
	ASSERT_STRUCT_OFFSET(WeaponDef, scanSpeed, 0x928);
	ASSERT_STRUCT_OFFSET(WeaponDef, scanAccel, 0x92C);
	ASSERT_STRUCT_OFFSET(WeaponDef, scanPauseTime, 0x930);
	ASSERT_STRUCT_OFFSET(WeaponDef, flameTableFirstPerson, 0x934);
	ASSERT_STRUCT_OFFSET(WeaponDef, flameTableThirdPerson, 0x938);
	ASSERT_STRUCT_OFFSET(WeaponDef, flameTableFirstPersonPtr, 0x93C);
	ASSERT_STRUCT_OFFSET(WeaponDef, flameTableThirdPersonPtr, 0x940);
	ASSERT_STRUCT_OFFSET(WeaponDef, tagFx_preparationEffect, 0x944);
	ASSERT_STRUCT_OFFSET(WeaponDef, tagFlash_preparationEffect, 0x948);
	ASSERT_STRUCT_OFFSET(WeaponDef, doGibbing, 0x94C);
	ASSERT_STRUCT_OFFSET(WeaponDef, maxGibDistance, 0x950);
	ASSERT_STRUCT_OFFSET(WeaponDef, altScopeADSTransInTime, 0x954);
	ASSERT_STRUCT_OFFSET(WeaponDef, altScopeADSTransOutTime, 0x958);
	ASSERT_STRUCT_OFFSET(WeaponDef, iIntroFireTime, 0x95C);
	ASSERT_STRUCT_OFFSET(WeaponDef, iIntroFireLength, 0x960);
	ASSERT_STRUCT_OFFSET(WeaponDef, meleeSwipeEffect, 0x964);
	ASSERT_STRUCT_OFFSET(WeaponDef, meleeImpactEffect, 0x968);
	ASSERT_STRUCT_OFFSET(WeaponDef, meleeImpactNoBloodEffect, 0x96C);
	ASSERT_STRUCT_OFFSET(WeaponDef, throwBackType, 0x970);
	ASSERT_STRUCT_OFFSET(WeaponDef, weaponCamo, 0x974);
	ASSERT_STRUCT_OFFSET(WeaponDef, customFloat0, 0x978);
	ASSERT_STRUCT_OFFSET(WeaponDef, customFloat1, 0x97C);
	ASSERT_STRUCT_OFFSET(WeaponDef, customFloat2, 0x980);
	ASSERT_STRUCT_OFFSET(WeaponDef, customBool0, 0x984);
	ASSERT_STRUCT_OFFSET(WeaponDef, customBool1, 0x988);
	ASSERT_STRUCT_OFFSET(WeaponDef, customBool2, 0x98C);

	struct WeaponAttachment
	{
		const char* szInternalName; //OFS: 0x0 SIZE: 0x4
		const char* szDisplayName; //OFS: 0x4 SIZE: 0x4
		eAttachment attachmentType; //OFS: 0x8 SIZE: 0x4
		eAttachmentPoint attachmentPoint; //OFS: 0xC SIZE: 0x4
		PenetrateType penetrateType; //OFS: 0x10 SIZE: 0x4
		weapFireType_t fireType; //OFS: 0x14 SIZE: 0x4
		int firstRaisePriority; //OFS: 0x18 SIZE: 0x4
		float fHipIdleAmount; //OFS: 0x1C SIZE: 0x4
		bool bAltWeaponAdsOnly; //OFS: 0x20 SIZE: 0x1
		bool bAltWeaponDisableSwitching; //OFS: 0x21 SIZE: 0x1
		float altScopeADSTransInTime; //OFS: 0x24 SIZE: 0x4
		float altScopeADSTransOutTime; //OFS: 0x28 SIZE: 0x4
		bool bSilenced; //OFS: 0x2C SIZE: 0x1
		bool bDualMag; //OFS: 0x2D SIZE: 0x1
		bool laserSight; //OFS: 0x2E SIZE: 0x1
		bool bInfraRed; //OFS: 0x2F SIZE: 0x1
		bool bUseAsMelee; //OFS: 0x30 SIZE: 0x1
		bool bDualWield; //OFS: 0x31 SIZE: 0x1
		bool sharedAmmo; //OFS: 0x32 SIZE: 0x1
		float fDamageRangeScale; //OFS: 0x34 SIZE: 0x4
		float fAdsZoomFov1; //OFS: 0x38 SIZE: 0x4
		float fAdsZoomFov2; //OFS: 0x3C SIZE: 0x4
		float fAdsZoomFov3; //OFS: 0x40 SIZE: 0x4
		float fAdsZoomInFrac; //OFS: 0x44 SIZE: 0x4
		float fAdsZoomOutFrac; //OFS: 0x48 SIZE: 0x4
		float fAdsTransInTimeScale; //OFS: 0x4C SIZE: 0x4
		float fAdsTransOutTimeScale; //OFS: 0x50 SIZE: 0x4
		float fAdsRecoilReductionRate; //OFS: 0x54 SIZE: 0x4
		float fAdsRecoilReductionLimit; //OFS: 0x58 SIZE: 0x4
		float fAdsViewKickCenterSpeedScale; //OFS: 0x5C SIZE: 0x4
		float fAdsIdleAmountScale; //OFS: 0x60 SIZE: 0x4
		bool swayOverride; //OFS: 0x64 SIZE: 0x1
		float swayMaxAngle; //OFS: 0x68 SIZE: 0x4
		float swayLerpSpeed; //OFS: 0x6C SIZE: 0x4
		float swayPitchScale; //OFS: 0x70 SIZE: 0x4
		float swayYawScale; //OFS: 0x74 SIZE: 0x4
		float swayHorizScale; //OFS: 0x78 SIZE: 0x4
		float swayVertScale; //OFS: 0x7C SIZE: 0x4
		bool adsSwayOverride; //OFS: 0x80 SIZE: 0x1
		float adsSwayMaxAngle; //OFS: 0x84 SIZE: 0x4
		float adsSwayLerpSpeed; //OFS: 0x88 SIZE: 0x4
		float adsSwayPitchScale; //OFS: 0x8C SIZE: 0x4
		float adsSwayYawScale; //OFS: 0x90 SIZE: 0x4
		float fAdsSwayHorizScale; //OFS: 0x94 SIZE: 0x4
		float fAdsSwayVertScale; //OFS: 0x98 SIZE: 0x4
		float adsMoveSpeedScale; //OFS: 0x9C SIZE: 0x4
		float fHipSpreadMinScale; //OFS: 0xA0 SIZE: 0x4
		float fHipSpreadMaxScale; //OFS: 0xA4 SIZE: 0x4
		float strafeRotR; //OFS: 0xA8 SIZE: 0x4
		float standMoveF; //OFS: 0xAC SIZE: 0x4
		vec3_t vStandRot; //OFS: 0xB0 SIZE: 0xC
		float fFireTimeScale; //OFS: 0xBC SIZE: 0x4
		float fReloadTimeScale; //OFS: 0xC0 SIZE: 0x4
		float fReloadEmptyTimeScale; //OFS: 0xC4 SIZE: 0x4
		float fReloadAddTimeScale; //OFS: 0xC8 SIZE: 0x4
		float fReloadQuickTimeScale; //OFS: 0xCC SIZE: 0x4
		float fReloadQuickEmptyTimeScale; //OFS: 0xD0 SIZE: 0x4
		float fReloadQuickAddTimeScale; //OFS: 0xD4 SIZE: 0x4
		bool mmsWeapon; //OFS: 0xD8 SIZE: 0x1
		bool mmsInScope; //OFS: 0xD9 SIZE: 0x1
		float mmsFOV; //OFS: 0xDC SIZE: 0x4
		float mmsAspect; //OFS: 0xE0 SIZE: 0x4
		float mmsMaxDist; //OFS: 0xE4 SIZE: 0x4
		float clipSizeScale; //OFS: 0xE8 SIZE: 0x4
		int iClipSize; //OFS: 0xEC SIZE: 0x4
		unsigned int stackFire; //OFS: 0xF0 SIZE: 0x4
		float stackFireSpread; //OFS: 0xF4 SIZE: 0x4
		float stackFireAccuracyDecay; //OFS: 0xF8 SIZE: 0x4
		unsigned int perks[2]; //OFS: 0xFC SIZE: 0x8
		float customFloat0; //OFS: 0x104 SIZE: 0x4
		float customFloat1; //OFS: 0x108 SIZE: 0x4
		float customFloat2; //OFS: 0x10C SIZE: 0x4
		int customBool0; //OFS: 0x110 SIZE: 0x4
		int customBool1; //OFS: 0x114 SIZE: 0x4
		int customBool2; //OFS: 0x118 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(WeaponAttachment, 0x11C);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, szInternalName, 0x0);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, szDisplayName, 0x4);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, attachmentType, 0x8);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, attachmentPoint, 0xC);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, penetrateType, 0x10);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, fireType, 0x14);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, firstRaisePriority, 0x18);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, fHipIdleAmount, 0x1C);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, bAltWeaponAdsOnly, 0x20);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, bAltWeaponDisableSwitching, 0x21);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, altScopeADSTransInTime, 0x24);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, altScopeADSTransOutTime, 0x28);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, bSilenced, 0x2C);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, bDualMag, 0x2D);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, laserSight, 0x2E);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, bInfraRed, 0x2F);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, bUseAsMelee, 0x30);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, bDualWield, 0x31);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, sharedAmmo, 0x32);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, fDamageRangeScale, 0x34);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, fAdsZoomFov1, 0x38);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, fAdsZoomFov2, 0x3C);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, fAdsZoomFov3, 0x40);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, fAdsZoomInFrac, 0x44);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, fAdsZoomOutFrac, 0x48);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, fAdsTransInTimeScale, 0x4C);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, fAdsTransOutTimeScale, 0x50);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, fAdsRecoilReductionRate, 0x54);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, fAdsRecoilReductionLimit, 0x58);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, fAdsViewKickCenterSpeedScale, 0x5C);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, fAdsIdleAmountScale, 0x60);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, swayOverride, 0x64);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, swayMaxAngle, 0x68);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, swayLerpSpeed, 0x6C);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, swayPitchScale, 0x70);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, swayYawScale, 0x74);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, swayHorizScale, 0x78);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, swayVertScale, 0x7C);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, adsSwayOverride, 0x80);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, adsSwayMaxAngle, 0x84);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, adsSwayLerpSpeed, 0x88);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, adsSwayPitchScale, 0x8C);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, adsSwayYawScale, 0x90);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, fAdsSwayHorizScale, 0x94);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, fAdsSwayVertScale, 0x98);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, adsMoveSpeedScale, 0x9C);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, fHipSpreadMinScale, 0xA0);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, fHipSpreadMaxScale, 0xA4);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, strafeRotR, 0xA8);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, standMoveF, 0xAC);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, vStandRot, 0xB0);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, fFireTimeScale, 0xBC);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, fReloadTimeScale, 0xC0);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, fReloadEmptyTimeScale, 0xC4);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, fReloadAddTimeScale, 0xC8);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, fReloadQuickTimeScale, 0xCC);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, fReloadQuickEmptyTimeScale, 0xD0);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, fReloadQuickAddTimeScale, 0xD4);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, mmsWeapon, 0xD8);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, mmsInScope, 0xD9);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, mmsFOV, 0xDC);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, mmsAspect, 0xE0);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, mmsMaxDist, 0xE4);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, clipSizeScale, 0xE8);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, iClipSize, 0xEC);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, stackFire, 0xF0);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, stackFireSpread, 0xF4);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, stackFireAccuracyDecay, 0xF8);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, perks, 0xFC);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, customFloat0, 0x104);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, customFloat1, 0x108);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, customFloat2, 0x10C);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, customBool0, 0x110);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, customBool1, 0x114);
	ASSERT_STRUCT_OFFSET(WeaponAttachment, customBool2, 0x118);

	struct WeaponAttachmentUnique
	{
		const char* szInternalName; //OFS: 0x0 SIZE: 0x4
		eAttachment attachmentType; //OFS: 0x4 SIZE: 0x4
		int siblingLink; //OFS: 0x8 SIZE: 0x4
		int childLink; //OFS: 0xC SIZE: 0x4
		int combinedAttachmentTypeMask; //OFS: 0x10 SIZE: 0x4
		const char* szAltWeaponName; //OFS: 0x14 SIZE: 0x4
		unsigned int altWeaponIndex; //OFS: 0x18 SIZE: 0x4
		const char* szDualWieldWeaponName; //OFS: 0x1C SIZE: 0x4
		unsigned int dualWieldWeaponIndex; //OFS: 0x20 SIZE: 0x4
		unsigned __int16* hideTags; //OFS: 0x24 SIZE: 0x4
		XModel* viewModel; //OFS: 0x28 SIZE: 0x4
		XModel* viewModelAdditional; //OFS: 0x2C SIZE: 0x4
		XModel* viewModelADS; //OFS: 0x30 SIZE: 0x4
		XModel* worldModel; //OFS: 0x34 SIZE: 0x4
		XModel* worldModelAdditional; //OFS: 0x38 SIZE: 0x4
		const char* viewModelTag; //OFS: 0x3C SIZE: 0x4
		const char* worldModelTag; //OFS: 0x40 SIZE: 0x4
		vec3_t viewModelOffsets; //OFS: 0x44 SIZE: 0xC
		vec3_t worldModelOffsets; //OFS: 0x50 SIZE: 0xC
		vec3_t viewModelRotations; //OFS: 0x5C SIZE: 0xC
		vec3_t worldModelRotations; //OFS: 0x68 SIZE: 0xC
		vec3_t viewModelAddOffsets; //OFS: 0x74 SIZE: 0xC
		vec3_t worldModelAddOffsets; //OFS: 0x80 SIZE: 0xC
		vec3_t viewModelAddRotations; //OFS: 0x8C SIZE: 0xC
		vec3_t worldModelAddRotations; //OFS: 0x98 SIZE: 0xC
		WeaponCamo* weaponCamo; //OFS: 0xA4 SIZE: 0x4
		bool disableBaseWeaponAttachment; //OFS: 0xA8 SIZE: 0x1
		bool disableBaseWeaponClip; //OFS: 0xA9 SIZE: 0x1
		bool overrideBaseWeaponAttachmentOffsets; //OFS: 0xAA SIZE: 0x1
		vec3_t viewModelOffsetBaseAttachment; //OFS: 0xAC SIZE: 0xC
		vec3_t worldModelOffsetBaseAttachment; //OFS: 0xB8 SIZE: 0xC
		Material* overlayMaterial; //OFS: 0xC4 SIZE: 0x4
		Material* overlayMaterialLowRes; //OFS: 0xC8 SIZE: 0x4
		weapOverlayReticle_t overlayReticle; //OFS: 0xCC SIZE: 0x4
		int iFirstRaiseTime; //OFS: 0xD0 SIZE: 0x4
		int iAltRaiseTime; //OFS: 0xD4 SIZE: 0x4
		int iAltDropTime; //OFS: 0xD8 SIZE: 0x4
		int iReloadAmmoAdd; //OFS: 0xDC SIZE: 0x4
		int iReloadStartAdd; //OFS: 0xE0 SIZE: 0x4
		bool bSegmentedReload; //OFS: 0xE4 SIZE: 0x1
		const char** szXAnims; //OFS: 0xE8 SIZE: 0x4
		int animationOverrides[3]; //OFS: 0xEC SIZE: 0xC
		float* locationDamageMultipliers; //OFS: 0xF8 SIZE: 0x4
		int soundOverrides; //OFS: 0xFC SIZE: 0x4
		const char* fireSound; //OFS: 0x100 SIZE: 0x4
		const char* fireSoundPlayer; //OFS: 0x104 SIZE: 0x4
		const char* fireLoopSound; //OFS: 0x108 SIZE: 0x4
		const char* fireLoopSoundPlayer; //OFS: 0x10C SIZE: 0x4
		const char* fireLoopEndSound; //OFS: 0x110 SIZE: 0x4
		const char* fireLoopEndSoundPlayer; //OFS: 0x114 SIZE: 0x4
		const char* fireStartSound; //OFS: 0x118 SIZE: 0x4
		const char* fireStopSound; //OFS: 0x11C SIZE: 0x4
		const char* fireStartSoundPlayer; //OFS: 0x120 SIZE: 0x4
		const char* fireStopSoundPlayer; //OFS: 0x124 SIZE: 0x4
		const char* fireLastSound; //OFS: 0x128 SIZE: 0x4
		const char* fireLastSoundPlayer; //OFS: 0x12C SIZE: 0x4
		const char* fireKillcamSound; //OFS: 0x130 SIZE: 0x4
		const char* fireKillcamSoundPlayer; //OFS: 0x134 SIZE: 0x4
		int effectOverrides; //OFS: 0x138 SIZE: 0x4
		const FxEffectDef* viewFlashEffect; //OFS: 0x13C SIZE: 0x4
		const FxEffectDef* worldFlashEffect; //OFS: 0x140 SIZE: 0x4
		TracerDef* tracerType; //OFS: 0x144 SIZE: 0x4
		TracerDef* enemyTracerType; //OFS: 0x148 SIZE: 0x4
		float adsDofStart; //OFS: 0x14C SIZE: 0x4
		float adsDofEnd; //OFS: 0x150 SIZE: 0x4
		int iAmmoIndex; //OFS: 0x154 SIZE: 0x4
		int iClipIndex; //OFS: 0x158 SIZE: 0x4
		bool bOverrideLeftHandIK; //OFS: 0x15C SIZE: 0x1
		bool bOverrideLeftHandProneIK; //OFS: 0x15D SIZE: 0x1
		vec3_t ikLeftHandOffset; //OFS: 0x160 SIZE: 0xC
		vec3_t ikLeftHandRotation; //OFS: 0x16C SIZE: 0xC
		vec3_t ikLeftHandProneOffset; //OFS: 0x178 SIZE: 0xC
		vec3_t ikLeftHandProneRotation; //OFS: 0x184 SIZE: 0xC
		float customFloat0; //OFS: 0x190 SIZE: 0x4
		float customFloat1; //OFS: 0x194 SIZE: 0x4
		float customFloat2; //OFS: 0x198 SIZE: 0x4
		int customBool0; //OFS: 0x19C SIZE: 0x4
		int customBool1; //OFS: 0x1A0 SIZE: 0x4
		int customBool2; //OFS: 0x1A4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(WeaponAttachmentUnique, 0x1A8);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, szInternalName, 0x0);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, attachmentType, 0x4);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, siblingLink, 0x8);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, childLink, 0xC);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, combinedAttachmentTypeMask, 0x10);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, szAltWeaponName, 0x14);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, altWeaponIndex, 0x18);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, szDualWieldWeaponName, 0x1C);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, dualWieldWeaponIndex, 0x20);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, hideTags, 0x24);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, viewModel, 0x28);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, viewModelAdditional, 0x2C);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, viewModelADS, 0x30);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, worldModel, 0x34);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, worldModelAdditional, 0x38);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, viewModelTag, 0x3C);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, worldModelTag, 0x40);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, viewModelOffsets, 0x44);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, worldModelOffsets, 0x50);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, viewModelRotations, 0x5C);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, worldModelRotations, 0x68);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, viewModelAddOffsets, 0x74);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, worldModelAddOffsets, 0x80);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, viewModelAddRotations, 0x8C);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, worldModelAddRotations, 0x98);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, weaponCamo, 0xA4);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, disableBaseWeaponAttachment, 0xA8);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, disableBaseWeaponClip, 0xA9);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, overrideBaseWeaponAttachmentOffsets, 0xAA);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, viewModelOffsetBaseAttachment, 0xAC);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, worldModelOffsetBaseAttachment, 0xB8);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, overlayMaterial, 0xC4);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, overlayMaterialLowRes, 0xC8);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, overlayReticle, 0xCC);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, iFirstRaiseTime, 0xD0);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, iAltRaiseTime, 0xD4);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, iAltDropTime, 0xD8);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, iReloadAmmoAdd, 0xDC);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, iReloadStartAdd, 0xE0);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, bSegmentedReload, 0xE4);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, szXAnims, 0xE8);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, animationOverrides, 0xEC);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, locationDamageMultipliers, 0xF8);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, soundOverrides, 0xFC);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, fireSound, 0x100);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, fireSoundPlayer, 0x104);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, fireLoopSound, 0x108);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, fireLoopSoundPlayer, 0x10C);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, fireLoopEndSound, 0x110);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, fireLoopEndSoundPlayer, 0x114);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, fireStartSound, 0x118);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, fireStopSound, 0x11C);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, fireStartSoundPlayer, 0x120);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, fireStopSoundPlayer, 0x124);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, fireLastSound, 0x128);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, fireLastSoundPlayer, 0x12C);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, fireKillcamSound, 0x130);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, fireKillcamSoundPlayer, 0x134);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, effectOverrides, 0x138);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, viewFlashEffect, 0x13C);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, worldFlashEffect, 0x140);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, tracerType, 0x144);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, enemyTracerType, 0x148);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, adsDofStart, 0x14C);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, adsDofEnd, 0x150);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, iAmmoIndex, 0x154);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, iClipIndex, 0x158);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, bOverrideLeftHandIK, 0x15C);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, bOverrideLeftHandProneIK, 0x15D);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, ikLeftHandOffset, 0x160);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, ikLeftHandRotation, 0x16C);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, ikLeftHandProneOffset, 0x178);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, ikLeftHandProneRotation, 0x184);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, customFloat0, 0x190);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, customFloat1, 0x194);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, customFloat2, 0x198);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, customBool0, 0x19C);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, customBool1, 0x1A0);
	ASSERT_STRUCT_OFFSET(WeaponAttachmentUnique, customBool2, 0x1A4);

	struct WeaponVariantDef
	{
		const char* szInternalName; //OFS: 0x0 SIZE: 0x4
		int iVariantCount; //OFS: 0x4 SIZE: 0x4
		WeaponDef* weapDef; //OFS: 0x8 SIZE: 0x4
		const char* szDisplayName; //OFS: 0xC SIZE: 0x4
		const char* szAltWeaponName; //OFS: 0x10 SIZE: 0x4
		const char* szAttachmentUnique; //OFS: 0x14 SIZE: 0x4
		WeaponAttachment** attachments; //OFS: 0x18 SIZE: 0x4
		WeaponAttachmentUnique** attachmentUniques; //OFS: 0x1C SIZE: 0x4
		const char** szXAnims; //OFS: 0x20 SIZE: 0x4
		unsigned __int16* hideTags; //OFS: 0x24 SIZE: 0x4
		XModel** attachViewModel; //OFS: 0x28 SIZE: 0x4
		XModel** attachWorldModel; //OFS: 0x2C SIZE: 0x4
		const char** attachViewModelTag; //OFS: 0x30 SIZE: 0x4
		const char** attachWorldModelTag; //OFS: 0x34 SIZE: 0x4
		float attachViewModelOffsets[24]; //OFS: 0x38 SIZE: 0x60
		float attachWorldModelOffsets[24]; //OFS: 0x98 SIZE: 0x60
		float attachViewModelRotations[24]; //OFS: 0xF8 SIZE: 0x60
		float attachWorldModelRotations[24]; //OFS: 0x158 SIZE: 0x60
		vec3_t stowedModelOffsets; //OFS: 0x1B8 SIZE: 0xC
		vec3_t stowedModelRotations; //OFS: 0x1C4 SIZE: 0xC
		unsigned int altWeaponIndex; //OFS: 0x1D0 SIZE: 0x4
		int iAttachments; //OFS: 0x1D4 SIZE: 0x4
		bool bIgnoreAttachments; //OFS: 0x1D8 SIZE: 0x1
		int iClipSize; //OFS: 0x1DC SIZE: 0x4
		int iReloadTime; //OFS: 0x1E0 SIZE: 0x4
		int iReloadEmptyTime; //OFS: 0x1E4 SIZE: 0x4
		int iReloadQuickTime; //OFS: 0x1E8 SIZE: 0x4
		int iReloadQuickEmptyTime; //OFS: 0x1EC SIZE: 0x4
		int iAdsTransInTime; //OFS: 0x1F0 SIZE: 0x4
		int iAdsTransOutTime; //OFS: 0x1F4 SIZE: 0x4
		int iAltRaiseTime; //OFS: 0x1F8 SIZE: 0x4
		const char* szAmmoDisplayName; //OFS: 0x1FC SIZE: 0x4
		const char* szAmmoName; //OFS: 0x200 SIZE: 0x4
		int iAmmoIndex; //OFS: 0x204 SIZE: 0x4
		const char* szClipName; //OFS: 0x208 SIZE: 0x4
		int iClipIndex; //OFS: 0x20C SIZE: 0x4
		float fAimAssistRangeAds; //OFS: 0x210 SIZE: 0x4
		float fAdsSwayHorizScale; //OFS: 0x214 SIZE: 0x4
		float fAdsSwayVertScale; //OFS: 0x218 SIZE: 0x4
		float fAdsViewKickCenterSpeed; //OFS: 0x21C SIZE: 0x4
		float fHipViewKickCenterSpeed; //OFS: 0x220 SIZE: 0x4
		float fAdsZoomFov1; //OFS: 0x224 SIZE: 0x4
		float fAdsZoomFov2; //OFS: 0x228 SIZE: 0x4
		float fAdsZoomFov3; //OFS: 0x22C SIZE: 0x4
		float fAdsZoomInFrac; //OFS: 0x230 SIZE: 0x4
		float fAdsZoomOutFrac; //OFS: 0x234 SIZE: 0x4
		float fOverlayAlphaScale; //OFS: 0x238 SIZE: 0x4
		float fOOPosAnimLength[2]; //OFS: 0x23C SIZE: 0x8
		bool bSilenced; //OFS: 0x244 SIZE: 0x1
		bool bDualMag; //OFS: 0x245 SIZE: 0x1
		bool bInfraRed; //OFS: 0x246 SIZE: 0x1
		bool bTVGuided; //OFS: 0x247 SIZE: 0x1
		unsigned int perks[2]; //OFS: 0x248 SIZE: 0x8
		bool bAntiQuickScope; //OFS: 0x250 SIZE: 0x1
		Material* overlayMaterial; //OFS: 0x254 SIZE: 0x4
		Material* overlayMaterialLowRes; //OFS: 0x258 SIZE: 0x4
		Material* dpadIcon; //OFS: 0x25C SIZE: 0x4
		weaponIconRatioType_t dpadIconRatio; //OFS: 0x260 SIZE: 0x4
		bool noAmmoOnDpadIcon; //OFS: 0x264 SIZE: 0x1
		bool mmsWeapon; //OFS: 0x265 SIZE: 0x1
		bool mmsInScope; //OFS: 0x266 SIZE: 0x1
		float mmsFOV; //OFS: 0x268 SIZE: 0x4
		float mmsAspect; //OFS: 0x26C SIZE: 0x4
		float mmsMaxDist; //OFS: 0x270 SIZE: 0x4
		vec3_t ikLeftHandIdlePos; //OFS: 0x274 SIZE: 0xC
		vec3_t ikLeftHandOffset; //OFS: 0x280 SIZE: 0xC
		vec3_t ikLeftHandRotation; //OFS: 0x28C SIZE: 0xC
		bool bUsingLeftHandProneIK; //OFS: 0x298 SIZE: 0x1
		vec3_t ikLeftHandProneOffset; //OFS: 0x29C SIZE: 0xC
		vec3_t ikLeftHandProneRotation; //OFS: 0x2A8 SIZE: 0xC
		vec3_t ikLeftHandUiViewerOffset; //OFS: 0x2B4 SIZE: 0xC
		vec3_t ikLeftHandUiViewerRotation; //OFS: 0x2C0 SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(WeaponVariantDef, 0x2CC);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, szInternalName, 0x0);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, iVariantCount, 0x4);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, weapDef, 0x8);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, szDisplayName, 0xC);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, szAltWeaponName, 0x10);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, szAttachmentUnique, 0x14);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, attachments, 0x18);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, attachmentUniques, 0x1C);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, szXAnims, 0x20);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, hideTags, 0x24);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, attachViewModel, 0x28);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, attachWorldModel, 0x2C);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, attachViewModelTag, 0x30);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, attachWorldModelTag, 0x34);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, attachViewModelOffsets, 0x38);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, attachWorldModelOffsets, 0x98);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, attachViewModelRotations, 0xF8);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, attachWorldModelRotations, 0x158);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, stowedModelOffsets, 0x1B8);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, stowedModelRotations, 0x1C4);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, altWeaponIndex, 0x1D0);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, iAttachments, 0x1D4);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, bIgnoreAttachments, 0x1D8);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, iClipSize, 0x1DC);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, iReloadTime, 0x1E0);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, iReloadEmptyTime, 0x1E4);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, iReloadQuickTime, 0x1E8);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, iReloadQuickEmptyTime, 0x1EC);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, iAdsTransInTime, 0x1F0);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, iAdsTransOutTime, 0x1F4);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, iAltRaiseTime, 0x1F8);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, szAmmoDisplayName, 0x1FC);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, szAmmoName, 0x200);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, iAmmoIndex, 0x204);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, szClipName, 0x208);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, iClipIndex, 0x20C);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, fAimAssistRangeAds, 0x210);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, fAdsSwayHorizScale, 0x214);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, fAdsSwayVertScale, 0x218);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, fAdsViewKickCenterSpeed, 0x21C);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, fHipViewKickCenterSpeed, 0x220);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, fAdsZoomFov1, 0x224);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, fAdsZoomFov2, 0x228);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, fAdsZoomFov3, 0x22C);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, fAdsZoomInFrac, 0x230);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, fAdsZoomOutFrac, 0x234);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, fOverlayAlphaScale, 0x238);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, fOOPosAnimLength, 0x23C);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, bSilenced, 0x244);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, bDualMag, 0x245);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, bInfraRed, 0x246);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, bTVGuided, 0x247);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, perks, 0x248);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, bAntiQuickScope, 0x250);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, overlayMaterial, 0x254);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, overlayMaterialLowRes, 0x258);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, dpadIcon, 0x25C);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, dpadIconRatio, 0x260);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, noAmmoOnDpadIcon, 0x264);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, mmsWeapon, 0x265);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, mmsInScope, 0x266);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, mmsFOV, 0x268);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, mmsAspect, 0x26C);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, mmsMaxDist, 0x270);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, ikLeftHandIdlePos, 0x274);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, ikLeftHandOffset, 0x280);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, ikLeftHandRotation, 0x28C);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, bUsingLeftHandProneIK, 0x298);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, ikLeftHandProneOffset, 0x29C);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, ikLeftHandProneRotation, 0x2A8);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, ikLeftHandUiViewerOffset, 0x2B4);
	ASSERT_STRUCT_OFFSET(WeaponVariantDef, ikLeftHandUiViewerRotation, 0x2C0);

	struct SndVolumeGroup
	{
		char name[32]; //OFS: 0x0 SIZE: 0x20
		char parentName[32]; //OFS: 0x20 SIZE: 0x20
		unsigned int id; //OFS: 0x40 SIZE: 0x4
		int parentIndex; //OFS: 0x44 SIZE: 0x4
		SndMenuCategory category; //OFS: 0x48 SIZE: 0x4
		unsigned __int16 attenuationSp; //OFS: 0x4C SIZE: 0x2
		unsigned __int16 attenuationMp; //OFS: 0x4E SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(SndVolumeGroup, 0x50);
	ASSERT_STRUCT_OFFSET(SndVolumeGroup, name, 0x0);
	ASSERT_STRUCT_OFFSET(SndVolumeGroup, parentName, 0x20);
	ASSERT_STRUCT_OFFSET(SndVolumeGroup, id, 0x40);
	ASSERT_STRUCT_OFFSET(SndVolumeGroup, parentIndex, 0x44);
	ASSERT_STRUCT_OFFSET(SndVolumeGroup, category, 0x48);
	ASSERT_STRUCT_OFFSET(SndVolumeGroup, attenuationSp, 0x4C);
	ASSERT_STRUCT_OFFSET(SndVolumeGroup, attenuationMp, 0x4E);

	struct SndCurve
	{
		char name[32]; //OFS: 0x0 SIZE: 0x20
		unsigned int id; //OFS: 0x20 SIZE: 0x4
		vec2_t points[8]; //OFS: 0x24 SIZE: 0x40
	};
	ASSERT_STRUCT_SIZE(SndCurve, 0x64);
	ASSERT_STRUCT_OFFSET(SndCurve, name, 0x0);
	ASSERT_STRUCT_OFFSET(SndCurve, id, 0x20);
	ASSERT_STRUCT_OFFSET(SndCurve, points, 0x24);

	struct SndPan
	{
		char name[32]; //OFS: 0x0 SIZE: 0x20
		unsigned int id; //OFS: 0x20 SIZE: 0x4
		float front; //OFS: 0x24 SIZE: 0x4
		float back; //OFS: 0x28 SIZE: 0x4
		float center; //OFS: 0x2C SIZE: 0x4
		float lfe; //OFS: 0x30 SIZE: 0x4
		float left; //OFS: 0x34 SIZE: 0x4
		float right; //OFS: 0x38 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(SndPan, 0x3C);
	ASSERT_STRUCT_OFFSET(SndPan, name, 0x0);
	ASSERT_STRUCT_OFFSET(SndPan, id, 0x20);
	ASSERT_STRUCT_OFFSET(SndPan, front, 0x24);
	ASSERT_STRUCT_OFFSET(SndPan, back, 0x28);
	ASSERT_STRUCT_OFFSET(SndPan, center, 0x2C);
	ASSERT_STRUCT_OFFSET(SndPan, lfe, 0x30);
	ASSERT_STRUCT_OFFSET(SndPan, left, 0x34);
	ASSERT_STRUCT_OFFSET(SndPan, right, 0x38);

	struct SndDuckGroup
	{
		char name[32]; //OFS: 0x0 SIZE: 0x20
		unsigned int id; //OFS: 0x20 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(SndDuckGroup, 0x24);
	ASSERT_STRUCT_OFFSET(SndDuckGroup, name, 0x0);
	ASSERT_STRUCT_OFFSET(SndDuckGroup, id, 0x20);

	struct SndContext
	{
		unsigned int type; //OFS: 0x0 SIZE: 0x4
		unsigned int values[8]; //OFS: 0x4 SIZE: 0x20
	};
	ASSERT_STRUCT_SIZE(SndContext, 0x24);
	ASSERT_STRUCT_OFFSET(SndContext, type, 0x0);
	ASSERT_STRUCT_OFFSET(SndContext, values, 0x4);

	struct SndMaster
	{
		char name[32]; //OFS: 0x0 SIZE: 0x20
		unsigned int id; //OFS: 0x20 SIZE: 0x4
		int lowE; //OFS: 0x24 SIZE: 0x4
		float lowG; //OFS: 0x28 SIZE: 0x4
		float lowF; //OFS: 0x2C SIZE: 0x4
		float lowQ; //OFS: 0x30 SIZE: 0x4
		int peak1E; //OFS: 0x34 SIZE: 0x4
		float peak1G; //OFS: 0x38 SIZE: 0x4
		float peak1F; //OFS: 0x3C SIZE: 0x4
		float peak1Q; //OFS: 0x40 SIZE: 0x4
		int peak2E; //OFS: 0x44 SIZE: 0x4
		float peak2G; //OFS: 0x48 SIZE: 0x4
		float peak2F; //OFS: 0x4C SIZE: 0x4
		float peak2Q; //OFS: 0x50 SIZE: 0x4
		int hiE; //OFS: 0x54 SIZE: 0x4
		float hiG; //OFS: 0x58 SIZE: 0x4
		float hiF; //OFS: 0x5C SIZE: 0x4
		float hiQ; //OFS: 0x60 SIZE: 0x4
		float eqG; //OFS: 0x64 SIZE: 0x4
		int compE; //OFS: 0x68 SIZE: 0x4
		float compPG; //OFS: 0x6C SIZE: 0x4
		float compMG; //OFS: 0x70 SIZE: 0x4
		float compT; //OFS: 0x74 SIZE: 0x4
		float compR; //OFS: 0x78 SIZE: 0x4
		float compTA; //OFS: 0x7C SIZE: 0x4
		float compTR; //OFS: 0x80 SIZE: 0x4
		int limitE; //OFS: 0x84 SIZE: 0x4
		float limitPG; //OFS: 0x88 SIZE: 0x4
		float limitMG; //OFS: 0x8C SIZE: 0x4
		float limitT; //OFS: 0x90 SIZE: 0x4
		float limitR; //OFS: 0x94 SIZE: 0x4
		float limitTA; //OFS: 0x98 SIZE: 0x4
		float limitTR; //OFS: 0x9C SIZE: 0x4
		float busReverbG; //OFS: 0xA0 SIZE: 0x4
		float busFxG; //OFS: 0xA4 SIZE: 0x4
		float busVoiceG; //OFS: 0xA8 SIZE: 0x4
		float busPfutzG; //OFS: 0xAC SIZE: 0x4
		float busHdrfxG; //OFS: 0xB0 SIZE: 0x4
		float busUiG; //OFS: 0xB4 SIZE: 0x4
		float busMusicG; //OFS: 0xB8 SIZE: 0x4
		float busMovieG; //OFS: 0xBC SIZE: 0x4
		float busVcsG; //OFS: 0xC0 SIZE: 0x4
		int busReverbE; //OFS: 0xC4 SIZE: 0x4
		int busFxE; //OFS: 0xC8 SIZE: 0x4
		int busVoiceE; //OFS: 0xCC SIZE: 0x4
		int busPfutzE; //OFS: 0xD0 SIZE: 0x4
		int busHdrfxE; //OFS: 0xD4 SIZE: 0x4
		int busUiE; //OFS: 0xD8 SIZE: 0x4
		int busMusicE; //OFS: 0xDC SIZE: 0x4
		int busMovieE; //OFS: 0xE0 SIZE: 0x4
		int hdrfxCompE; //OFS: 0xE4 SIZE: 0x4
		int voiceEqE; //OFS: 0xE8 SIZE: 0x4
		int voiceCompE; //OFS: 0xEC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(SndMaster, 0xF0);
	ASSERT_STRUCT_OFFSET(SndMaster, name, 0x0);
	ASSERT_STRUCT_OFFSET(SndMaster, id, 0x20);
	ASSERT_STRUCT_OFFSET(SndMaster, lowE, 0x24);
	ASSERT_STRUCT_OFFSET(SndMaster, lowG, 0x28);
	ASSERT_STRUCT_OFFSET(SndMaster, lowF, 0x2C);
	ASSERT_STRUCT_OFFSET(SndMaster, lowQ, 0x30);
	ASSERT_STRUCT_OFFSET(SndMaster, peak1E, 0x34);
	ASSERT_STRUCT_OFFSET(SndMaster, peak1G, 0x38);
	ASSERT_STRUCT_OFFSET(SndMaster, peak1F, 0x3C);
	ASSERT_STRUCT_OFFSET(SndMaster, peak1Q, 0x40);
	ASSERT_STRUCT_OFFSET(SndMaster, peak2E, 0x44);
	ASSERT_STRUCT_OFFSET(SndMaster, peak2G, 0x48);
	ASSERT_STRUCT_OFFSET(SndMaster, peak2F, 0x4C);
	ASSERT_STRUCT_OFFSET(SndMaster, peak2Q, 0x50);
	ASSERT_STRUCT_OFFSET(SndMaster, hiE, 0x54);
	ASSERT_STRUCT_OFFSET(SndMaster, hiG, 0x58);
	ASSERT_STRUCT_OFFSET(SndMaster, hiF, 0x5C);
	ASSERT_STRUCT_OFFSET(SndMaster, hiQ, 0x60);
	ASSERT_STRUCT_OFFSET(SndMaster, eqG, 0x64);
	ASSERT_STRUCT_OFFSET(SndMaster, compE, 0x68);
	ASSERT_STRUCT_OFFSET(SndMaster, compPG, 0x6C);
	ASSERT_STRUCT_OFFSET(SndMaster, compMG, 0x70);
	ASSERT_STRUCT_OFFSET(SndMaster, compT, 0x74);
	ASSERT_STRUCT_OFFSET(SndMaster, compR, 0x78);
	ASSERT_STRUCT_OFFSET(SndMaster, compTA, 0x7C);
	ASSERT_STRUCT_OFFSET(SndMaster, compTR, 0x80);
	ASSERT_STRUCT_OFFSET(SndMaster, limitE, 0x84);
	ASSERT_STRUCT_OFFSET(SndMaster, limitPG, 0x88);
	ASSERT_STRUCT_OFFSET(SndMaster, limitMG, 0x8C);
	ASSERT_STRUCT_OFFSET(SndMaster, limitT, 0x90);
	ASSERT_STRUCT_OFFSET(SndMaster, limitR, 0x94);
	ASSERT_STRUCT_OFFSET(SndMaster, limitTA, 0x98);
	ASSERT_STRUCT_OFFSET(SndMaster, limitTR, 0x9C);
	ASSERT_STRUCT_OFFSET(SndMaster, busReverbG, 0xA0);
	ASSERT_STRUCT_OFFSET(SndMaster, busFxG, 0xA4);
	ASSERT_STRUCT_OFFSET(SndMaster, busVoiceG, 0xA8);
	ASSERT_STRUCT_OFFSET(SndMaster, busPfutzG, 0xAC);
	ASSERT_STRUCT_OFFSET(SndMaster, busHdrfxG, 0xB0);
	ASSERT_STRUCT_OFFSET(SndMaster, busUiG, 0xB4);
	ASSERT_STRUCT_OFFSET(SndMaster, busMusicG, 0xB8);
	ASSERT_STRUCT_OFFSET(SndMaster, busMovieG, 0xBC);
	ASSERT_STRUCT_OFFSET(SndMaster, busVcsG, 0xC0);
	ASSERT_STRUCT_OFFSET(SndMaster, busReverbE, 0xC4);
	ASSERT_STRUCT_OFFSET(SndMaster, busFxE, 0xC8);
	ASSERT_STRUCT_OFFSET(SndMaster, busVoiceE, 0xCC);
	ASSERT_STRUCT_OFFSET(SndMaster, busPfutzE, 0xD0);
	ASSERT_STRUCT_OFFSET(SndMaster, busHdrfxE, 0xD4);
	ASSERT_STRUCT_OFFSET(SndMaster, busUiE, 0xD8);
	ASSERT_STRUCT_OFFSET(SndMaster, busMusicE, 0xDC);
	ASSERT_STRUCT_OFFSET(SndMaster, busMovieE, 0xE0);
	ASSERT_STRUCT_OFFSET(SndMaster, hdrfxCompE, 0xE4);
	ASSERT_STRUCT_OFFSET(SndMaster, voiceEqE, 0xE8);
	ASSERT_STRUCT_OFFSET(SndMaster, voiceCompE, 0xEC);

	struct SndSidechainDuck
	{
		char name[32]; //OFS: 0x0 SIZE: 0x20
		unsigned int id; //OFS: 0x20 SIZE: 0x4
		float g; //OFS: 0x24 SIZE: 0x4
		float f; //OFS: 0x28 SIZE: 0x4
		float q; //OFS: 0x2C SIZE: 0x4
		float ta; //OFS: 0x30 SIZE: 0x4
		float tr; //OFS: 0x34 SIZE: 0x4
		float _tf; //OFS: 0x38 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(SndSidechainDuck, 0x3C);
	ASSERT_STRUCT_OFFSET(SndSidechainDuck, name, 0x0);
	ASSERT_STRUCT_OFFSET(SndSidechainDuck, id, 0x20);
	ASSERT_STRUCT_OFFSET(SndSidechainDuck, g, 0x24);
	ASSERT_STRUCT_OFFSET(SndSidechainDuck, f, 0x28);
	ASSERT_STRUCT_OFFSET(SndSidechainDuck, q, 0x2C);
	ASSERT_STRUCT_OFFSET(SndSidechainDuck, ta, 0x30);
	ASSERT_STRUCT_OFFSET(SndSidechainDuck, tr, 0x34);
	ASSERT_STRUCT_OFFSET(SndSidechainDuck, _tf, 0x38);

	struct SndFutz
	{
		char name[32]; //OFS: 0x0 SIZE: 0x20
		unsigned int id; //OFS: 0x20 SIZE: 0x4
		float bpfF; //OFS: 0x24 SIZE: 0x4
		float bpfQ; //OFS: 0x28 SIZE: 0x4
		float lsG; //OFS: 0x2C SIZE: 0x4
		float lsF; //OFS: 0x30 SIZE: 0x4
		float lsQ; //OFS: 0x34 SIZE: 0x4
		float dist; //OFS: 0x38 SIZE: 0x4
		float preG; //OFS: 0x3C SIZE: 0x4
		float postG; //OFS: 0x40 SIZE: 0x4
		float th; //OFS: 0x44 SIZE: 0x4
		float tg; //OFS: 0x48 SIZE: 0x4
		float clippre; //OFS: 0x4C SIZE: 0x4
		float clippost; //OFS: 0x50 SIZE: 0x4
		float blend; //OFS: 0x54 SIZE: 0x4
		unsigned int startAliasId; //OFS: 0x58 SIZE: 0x4
		unsigned int stopAliasId; //OFS: 0x5C SIZE: 0x4
		unsigned int loopAliasId; //OFS: 0x60 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(SndFutz, 0x64);
	ASSERT_STRUCT_OFFSET(SndFutz, name, 0x0);
	ASSERT_STRUCT_OFFSET(SndFutz, id, 0x20);
	ASSERT_STRUCT_OFFSET(SndFutz, bpfF, 0x24);
	ASSERT_STRUCT_OFFSET(SndFutz, bpfQ, 0x28);
	ASSERT_STRUCT_OFFSET(SndFutz, lsG, 0x2C);
	ASSERT_STRUCT_OFFSET(SndFutz, lsF, 0x30);
	ASSERT_STRUCT_OFFSET(SndFutz, lsQ, 0x34);
	ASSERT_STRUCT_OFFSET(SndFutz, dist, 0x38);
	ASSERT_STRUCT_OFFSET(SndFutz, preG, 0x3C);
	ASSERT_STRUCT_OFFSET(SndFutz, postG, 0x40);
	ASSERT_STRUCT_OFFSET(SndFutz, th, 0x44);
	ASSERT_STRUCT_OFFSET(SndFutz, tg, 0x48);
	ASSERT_STRUCT_OFFSET(SndFutz, clippre, 0x4C);
	ASSERT_STRUCT_OFFSET(SndFutz, clippost, 0x50);
	ASSERT_STRUCT_OFFSET(SndFutz, blend, 0x54);
	ASSERT_STRUCT_OFFSET(SndFutz, startAliasId, 0x58);
	ASSERT_STRUCT_OFFSET(SndFutz, stopAliasId, 0x5C);
	ASSERT_STRUCT_OFFSET(SndFutz, loopAliasId, 0x60);

	struct SndDriverGlobals
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		unsigned int groupCount; //OFS: 0x4 SIZE: 0x4
		SndVolumeGroup* groups; //OFS: 0x8 SIZE: 0x4
		unsigned int curveCount; //OFS: 0xC SIZE: 0x4
		SndCurve* curves; //OFS: 0x10 SIZE: 0x4
		unsigned int panCount; //OFS: 0x14 SIZE: 0x4
		SndPan* pans; //OFS: 0x18 SIZE: 0x4
		unsigned int duckGroupCount; //OFS: 0x1C SIZE: 0x4
		SndDuckGroup* duckGroups; //OFS: 0x20 SIZE: 0x4
		unsigned int contextCount; //OFS: 0x24 SIZE: 0x4
		SndContext* contexts; //OFS: 0x28 SIZE: 0x4
		unsigned int masterCount; //OFS: 0x2C SIZE: 0x4
		SndMaster* masters; //OFS: 0x30 SIZE: 0x4
		unsigned int voiceDuckCount; //OFS: 0x34 SIZE: 0x4
		SndSidechainDuck* voiceDucks; //OFS: 0x38 SIZE: 0x4
		unsigned int futzCount; //OFS: 0x3C SIZE: 0x4
		SndFutz* futzes; //OFS: 0x40 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(SndDriverGlobals, 0x44);
	ASSERT_STRUCT_OFFSET(SndDriverGlobals, name, 0x0);
	ASSERT_STRUCT_OFFSET(SndDriverGlobals, groupCount, 0x4);
	ASSERT_STRUCT_OFFSET(SndDriverGlobals, groups, 0x8);
	ASSERT_STRUCT_OFFSET(SndDriverGlobals, curveCount, 0xC);
	ASSERT_STRUCT_OFFSET(SndDriverGlobals, curves, 0x10);
	ASSERT_STRUCT_OFFSET(SndDriverGlobals, panCount, 0x14);
	ASSERT_STRUCT_OFFSET(SndDriverGlobals, pans, 0x18);
	ASSERT_STRUCT_OFFSET(SndDriverGlobals, duckGroupCount, 0x1C);
	ASSERT_STRUCT_OFFSET(SndDriverGlobals, duckGroups, 0x20);
	ASSERT_STRUCT_OFFSET(SndDriverGlobals, contextCount, 0x24);
	ASSERT_STRUCT_OFFSET(SndDriverGlobals, contexts, 0x28);
	ASSERT_STRUCT_OFFSET(SndDriverGlobals, masterCount, 0x2C);
	ASSERT_STRUCT_OFFSET(SndDriverGlobals, masters, 0x30);
	ASSERT_STRUCT_OFFSET(SndDriverGlobals, voiceDuckCount, 0x34);
	ASSERT_STRUCT_OFFSET(SndDriverGlobals, voiceDucks, 0x38);
	ASSERT_STRUCT_OFFSET(SndDriverGlobals, futzCount, 0x3C);
	ASSERT_STRUCT_OFFSET(SndDriverGlobals, futzes, 0x40);

	struct FxImpactEntry
	{
		const FxEffectDef* nonflesh[32]; //OFS: 0x0 SIZE: 0x80
		const FxEffectDef* flesh[4]; //OFS: 0x80 SIZE: 0x10
	};
	ASSERT_STRUCT_SIZE(FxImpactEntry, 0x90);
	ASSERT_STRUCT_OFFSET(FxImpactEntry, nonflesh, 0x0);
	ASSERT_STRUCT_OFFSET(FxImpactEntry, flesh, 0x80);

	struct FxImpactTable
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		FxImpactEntry* table; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(FxImpactTable, 0x8);
	ASSERT_STRUCT_OFFSET(FxImpactTable, name, 0x0);
	ASSERT_STRUCT_OFFSET(FxImpactTable, table, 0x4);

	struct RawFile
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		int len; //OFS: 0x4 SIZE: 0x4
		const char* buffer; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(RawFile, 0xC);
	ASSERT_STRUCT_OFFSET(RawFile, name, 0x0);
	ASSERT_STRUCT_OFFSET(RawFile, len, 0x4);
	ASSERT_STRUCT_OFFSET(RawFile, buffer, 0x8);

	struct StringTableCell
	{
		const char* string; //OFS: 0x0 SIZE: 0x4
		int hash; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(StringTableCell, 0x8);
	ASSERT_STRUCT_OFFSET(StringTableCell, string, 0x0);
	ASSERT_STRUCT_OFFSET(StringTableCell, hash, 0x4);

	struct StringTable
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		int columnCount; //OFS: 0x4 SIZE: 0x4
		int rowCount; //OFS: 0x8 SIZE: 0x4
		StringTableCell* values; //OFS: 0xC SIZE: 0x4
		__int16* cellIndex; //OFS: 0x10 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(StringTable, 0x14);
	ASSERT_STRUCT_OFFSET(StringTable, name, 0x0);
	ASSERT_STRUCT_OFFSET(StringTable, columnCount, 0x4);
	ASSERT_STRUCT_OFFSET(StringTable, rowCount, 0x8);
	ASSERT_STRUCT_OFFSET(StringTable, values, 0xC);
	ASSERT_STRUCT_OFFSET(StringTable, cellIndex, 0x10);

	struct LbColumnDef
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		int colId; //OFS: 0x4 SIZE: 0x4
		int dwColIndex; //OFS: 0x8 SIZE: 0x4
		bool hidden; //OFS: 0xC SIZE: 0x1
		const char* statName; //OFS: 0x10 SIZE: 0x4
		LbColType type; //OFS: 0x14 SIZE: 0x4
		int precision; //OFS: 0x18 SIZE: 0x4
		LbAggType agg; //OFS: 0x1C SIZE: 0x4
		const char* localization; //OFS: 0x20 SIZE: 0x4
		int uiCalColX; //OFS: 0x24 SIZE: 0x4
		int uiCalColY; //OFS: 0x28 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(LbColumnDef, 0x2C);
	ASSERT_STRUCT_OFFSET(LbColumnDef, name, 0x0);
	ASSERT_STRUCT_OFFSET(LbColumnDef, colId, 0x4);
	ASSERT_STRUCT_OFFSET(LbColumnDef, dwColIndex, 0x8);
	ASSERT_STRUCT_OFFSET(LbColumnDef, hidden, 0xC);
	ASSERT_STRUCT_OFFSET(LbColumnDef, statName, 0x10);
	ASSERT_STRUCT_OFFSET(LbColumnDef, type, 0x14);
	ASSERT_STRUCT_OFFSET(LbColumnDef, precision, 0x18);
	ASSERT_STRUCT_OFFSET(LbColumnDef, agg, 0x1C);
	ASSERT_STRUCT_OFFSET(LbColumnDef, localization, 0x20);
	ASSERT_STRUCT_OFFSET(LbColumnDef, uiCalColX, 0x24);
	ASSERT_STRUCT_OFFSET(LbColumnDef, uiCalColY, 0x28);

	struct LeaderboardDef
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		unsigned int id; //OFS: 0x4 SIZE: 0x4
		int columnCount; //OFS: 0x8 SIZE: 0x4
		int dwColumnCount; //OFS: 0xC SIZE: 0x4
		int xpColId; //OFS: 0x10 SIZE: 0x4
		int prestigeColId; //OFS: 0x14 SIZE: 0x4
		LbColumnDef* columns; //OFS: 0x18 SIZE: 0x4
		LbUpdateType updateType; //OFS: 0x1C SIZE: 0x4
		int trackTypes; //OFS: 0x20 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(LeaderboardDef, 0x24);
	ASSERT_STRUCT_OFFSET(LeaderboardDef, name, 0x0);
	ASSERT_STRUCT_OFFSET(LeaderboardDef, id, 0x4);
	ASSERT_STRUCT_OFFSET(LeaderboardDef, columnCount, 0x8);
	ASSERT_STRUCT_OFFSET(LeaderboardDef, dwColumnCount, 0xC);
	ASSERT_STRUCT_OFFSET(LeaderboardDef, xpColId, 0x10);
	ASSERT_STRUCT_OFFSET(LeaderboardDef, prestigeColId, 0x14);
	ASSERT_STRUCT_OFFSET(LeaderboardDef, columns, 0x18);
	ASSERT_STRUCT_OFFSET(LeaderboardDef, updateType, 0x1C);
	ASSERT_STRUCT_OFFSET(LeaderboardDef, trackTypes, 0x20);

	struct gump_info_t
	{
		char* name; //OFS: 0x0 SIZE: 0x4
		int size; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(gump_info_t, 0x8);
	ASSERT_STRUCT_OFFSET(gump_info_t, name, 0x0);
	ASSERT_STRUCT_OFFSET(gump_info_t, size, 0x4);

	struct overlay_info_t
	{
		char* name; //OFS: 0x0 SIZE: 0x4
		int size; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(overlay_info_t, 0x8);
	ASSERT_STRUCT_OFFSET(overlay_info_t, name, 0x0);
	ASSERT_STRUCT_OFFSET(overlay_info_t, size, 0x4);

	struct XGlobals
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		int xanimStreamBufferSize; //OFS: 0x4 SIZE: 0x4
		int cinematicMaxWidth; //OFS: 0x8 SIZE: 0x4
		int cinematicMaxHeight; //OFS: 0xC SIZE: 0x4
		int extracamResolution; //OFS: 0x10 SIZE: 0x4
		vec4_t screenClearColor; //OFS: 0x14 SIZE: 0x10
		int bigestGumpSize; //OFS: 0x24 SIZE: 0x4
		int gumpsCount; //OFS: 0x28 SIZE: 0x4
		gump_info_t gumps[32]; //OFS: 0x2C SIZE: 0x100
		int bigestOverlaySize; //OFS: 0x12C SIZE: 0x4
		int overlayCount; //OFS: 0x130 SIZE: 0x4
		overlay_info_t overlays[32]; //OFS: 0x134 SIZE: 0x100
	};
	ASSERT_STRUCT_SIZE(XGlobals, 0x234);
	ASSERT_STRUCT_OFFSET(XGlobals, name, 0x0);
	ASSERT_STRUCT_OFFSET(XGlobals, xanimStreamBufferSize, 0x4);
	ASSERT_STRUCT_OFFSET(XGlobals, cinematicMaxWidth, 0x8);
	ASSERT_STRUCT_OFFSET(XGlobals, cinematicMaxHeight, 0xC);
	ASSERT_STRUCT_OFFSET(XGlobals, extracamResolution, 0x10);
	ASSERT_STRUCT_OFFSET(XGlobals, screenClearColor, 0x14);
	ASSERT_STRUCT_OFFSET(XGlobals, bigestGumpSize, 0x24);
	ASSERT_STRUCT_OFFSET(XGlobals, gumpsCount, 0x28);
	ASSERT_STRUCT_OFFSET(XGlobals, gumps, 0x2C);
	ASSERT_STRUCT_OFFSET(XGlobals, bigestOverlaySize, 0x12C);
	ASSERT_STRUCT_OFFSET(XGlobals, overlayCount, 0x130);
	ASSERT_STRUCT_OFFSET(XGlobals, overlays, 0x134);

	struct ddlMemberDef_t
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		int size; //OFS: 0x4 SIZE: 0x4
		int offset; //OFS: 0x8 SIZE: 0x4
		int type; //OFS: 0xC SIZE: 0x4
		int externalIndex; //OFS: 0x10 SIZE: 0x4
		unsigned int rangeLimit; //OFS: 0x14 SIZE: 0x4
		unsigned int serverDelta; //OFS: 0x18 SIZE: 0x4
		unsigned int clientDelta; //OFS: 0x1C SIZE: 0x4
		int arraySize; //OFS: 0x20 SIZE: 0x4
		int enumIndex; //OFS: 0x24 SIZE: 0x4
		int permission; //OFS: 0x28 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(ddlMemberDef_t, 0x2C);
	ASSERT_STRUCT_OFFSET(ddlMemberDef_t, name, 0x0);
	ASSERT_STRUCT_OFFSET(ddlMemberDef_t, size, 0x4);
	ASSERT_STRUCT_OFFSET(ddlMemberDef_t, offset, 0x8);
	ASSERT_STRUCT_OFFSET(ddlMemberDef_t, type, 0xC);
	ASSERT_STRUCT_OFFSET(ddlMemberDef_t, externalIndex, 0x10);
	ASSERT_STRUCT_OFFSET(ddlMemberDef_t, rangeLimit, 0x14);
	ASSERT_STRUCT_OFFSET(ddlMemberDef_t, serverDelta, 0x18);
	ASSERT_STRUCT_OFFSET(ddlMemberDef_t, clientDelta, 0x1C);
	ASSERT_STRUCT_OFFSET(ddlMemberDef_t, arraySize, 0x20);
	ASSERT_STRUCT_OFFSET(ddlMemberDef_t, enumIndex, 0x24);
	ASSERT_STRUCT_OFFSET(ddlMemberDef_t, permission, 0x28);

	struct ddlHash_t
	{
		int hash; //OFS: 0x0 SIZE: 0x4
		int index; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(ddlHash_t, 0x8);
	ASSERT_STRUCT_OFFSET(ddlHash_t, hash, 0x0);
	ASSERT_STRUCT_OFFSET(ddlHash_t, index, 0x4);

	struct ddlStructDef_t
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		int size; //OFS: 0x4 SIZE: 0x4
		int memberCount; //OFS: 0x8 SIZE: 0x4
		ddlMemberDef_t* members; //OFS: 0xC SIZE: 0x4
		ddlHash_t* hashTable; //OFS: 0x10 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(ddlStructDef_t, 0x14);
	ASSERT_STRUCT_OFFSET(ddlStructDef_t, name, 0x0);
	ASSERT_STRUCT_OFFSET(ddlStructDef_t, size, 0x4);
	ASSERT_STRUCT_OFFSET(ddlStructDef_t, memberCount, 0x8);
	ASSERT_STRUCT_OFFSET(ddlStructDef_t, members, 0xC);
	ASSERT_STRUCT_OFFSET(ddlStructDef_t, hashTable, 0x10);

	struct ddlEnumDef_t
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		int memberCount; //OFS: 0x4 SIZE: 0x4
		const char** members; //OFS: 0x8 SIZE: 0x4
		ddlHash_t* hashTable; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(ddlEnumDef_t, 0x10);
	ASSERT_STRUCT_OFFSET(ddlEnumDef_t, name, 0x0);
	ASSERT_STRUCT_OFFSET(ddlEnumDef_t, memberCount, 0x4);
	ASSERT_STRUCT_OFFSET(ddlEnumDef_t, members, 0x8);
	ASSERT_STRUCT_OFFSET(ddlEnumDef_t, hashTable, 0xC);

	struct ddlDef_t
	{
		int version; //OFS: 0x0 SIZE: 0x4
		int size; //OFS: 0x4 SIZE: 0x4
		ddlStructDef_t* structList; //OFS: 0x8 SIZE: 0x4
		int structCount; //OFS: 0xC SIZE: 0x4
		ddlEnumDef_t* enumList; //OFS: 0x10 SIZE: 0x4
		int enumCount; //OFS: 0x14 SIZE: 0x4
		ddlDef_t* next; //OFS: 0x18 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(ddlDef_t, 0x1C);
	ASSERT_STRUCT_OFFSET(ddlDef_t, version, 0x0);
	ASSERT_STRUCT_OFFSET(ddlDef_t, size, 0x4);
	ASSERT_STRUCT_OFFSET(ddlDef_t, structList, 0x8);
	ASSERT_STRUCT_OFFSET(ddlDef_t, structCount, 0xC);
	ASSERT_STRUCT_OFFSET(ddlDef_t, enumList, 0x10);
	ASSERT_STRUCT_OFFSET(ddlDef_t, enumCount, 0x14);
	ASSERT_STRUCT_OFFSET(ddlDef_t, next, 0x18);

	struct ddlRoot_t
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		ddlDef_t* ddlDef; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(ddlRoot_t, 0x8);
	ASSERT_STRUCT_OFFSET(ddlRoot_t, name, 0x0);
	ASSERT_STRUCT_OFFSET(ddlRoot_t, ddlDef, 0x4);

	struct GlassDef
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		int maxHealth; //OFS: 0x4 SIZE: 0x4
		float thickness; //OFS: 0x8 SIZE: 0x4
		float minShardSize; //OFS: 0xC SIZE: 0x4
		float maxShardSize; //OFS: 0x10 SIZE: 0x4
		float shardLifeProbablility; //OFS: 0x14 SIZE: 0x4
		int maxShards; //OFS: 0x18 SIZE: 0x4
		Material* pristineMaterial; //OFS: 0x1C SIZE: 0x4
		Material* crackedMaterial; //OFS: 0x20 SIZE: 0x4
		Material* shardMaterial; //OFS: 0x24 SIZE: 0x4
		const char* crackSound; //OFS: 0x28 SIZE: 0x4
		const char* shatterShound; //OFS: 0x2C SIZE: 0x4
		const char* autoShatterShound; //OFS: 0x30 SIZE: 0x4
		const FxEffectDef* crackEffect; //OFS: 0x34 SIZE: 0x4
		const FxEffectDef* shatterEffect; //OFS: 0x38 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GlassDef, 0x3C);
	ASSERT_STRUCT_OFFSET(GlassDef, name, 0x0);
	ASSERT_STRUCT_OFFSET(GlassDef, maxHealth, 0x4);
	ASSERT_STRUCT_OFFSET(GlassDef, thickness, 0x8);
	ASSERT_STRUCT_OFFSET(GlassDef, minShardSize, 0xC);
	ASSERT_STRUCT_OFFSET(GlassDef, maxShardSize, 0x10);
	ASSERT_STRUCT_OFFSET(GlassDef, shardLifeProbablility, 0x14);
	ASSERT_STRUCT_OFFSET(GlassDef, maxShards, 0x18);
	ASSERT_STRUCT_OFFSET(GlassDef, pristineMaterial, 0x1C);
	ASSERT_STRUCT_OFFSET(GlassDef, crackedMaterial, 0x20);
	ASSERT_STRUCT_OFFSET(GlassDef, shardMaterial, 0x24);
	ASSERT_STRUCT_OFFSET(GlassDef, crackSound, 0x28);
	ASSERT_STRUCT_OFFSET(GlassDef, shatterShound, 0x2C);
	ASSERT_STRUCT_OFFSET(GlassDef, autoShatterShound, 0x30);
	ASSERT_STRUCT_OFFSET(GlassDef, crackEffect, 0x34);
	ASSERT_STRUCT_OFFSET(GlassDef, shatterEffect, 0x38);

	struct Glass
	{
		unsigned int numCellIndices; //OFS: 0x0 SIZE: 0x4
		unsigned __int16 cellIndices[6]; //OFS: 0x4 SIZE: 0xC
		GlassDef* glassDef; //OFS: 0x10 SIZE: 0x4
		unsigned int index; //OFS: 0x14 SIZE: 0x4
		unsigned int brushModel; //OFS: 0x18 SIZE: 0x4
		vec3_t origin; //OFS: 0x1C SIZE: 0xC
		vec3_t angles; //OFS: 0x28 SIZE: 0xC
		vec3_t absmin; //OFS: 0x34 SIZE: 0xC
		vec3_t absmax; //OFS: 0x40 SIZE: 0xC
		bool isPlanar; //OFS: 0x4C SIZE: 0x1
		unsigned __int8 numOutlineVerts; //OFS: 0x4D SIZE: 0x1
		unsigned __int8 binormalSign; //OFS: 0x4E SIZE: 0x1
		vec2_t* outline; //OFS: 0x50 SIZE: 0x4
		vec3_t outlineAxis[3]; //OFS: 0x54 SIZE: 0x24
		vec3_t outlineOrigin; //OFS: 0x78 SIZE: 0xC
		float uvScale; //OFS: 0x84 SIZE: 0x4
		float thickness; //OFS: 0x88 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(Glass, 0x8C);
	ASSERT_STRUCT_OFFSET(Glass, numCellIndices, 0x0);
	ASSERT_STRUCT_OFFSET(Glass, cellIndices, 0x4);
	ASSERT_STRUCT_OFFSET(Glass, glassDef, 0x10);
	ASSERT_STRUCT_OFFSET(Glass, index, 0x14);
	ASSERT_STRUCT_OFFSET(Glass, brushModel, 0x18);
	ASSERT_STRUCT_OFFSET(Glass, origin, 0x1C);
	ASSERT_STRUCT_OFFSET(Glass, angles, 0x28);
	ASSERT_STRUCT_OFFSET(Glass, absmin, 0x34);
	ASSERT_STRUCT_OFFSET(Glass, absmax, 0x40);
	ASSERT_STRUCT_OFFSET(Glass, isPlanar, 0x4C);
	ASSERT_STRUCT_OFFSET(Glass, numOutlineVerts, 0x4D);
	ASSERT_STRUCT_OFFSET(Glass, binormalSign, 0x4E);
	ASSERT_STRUCT_OFFSET(Glass, outline, 0x50);
	ASSERT_STRUCT_OFFSET(Glass, outlineAxis, 0x54);
	ASSERT_STRUCT_OFFSET(Glass, outlineOrigin, 0x78);
	ASSERT_STRUCT_OFFSET(Glass, uvScale, 0x84);
	ASSERT_STRUCT_OFFSET(Glass, thickness, 0x88);

	struct Glasses
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		unsigned int numGlasses; //OFS: 0x4 SIZE: 0x4
		Glass* glasses; //OFS: 0x8 SIZE: 0x4
		unsigned __int8* workMemory; //OFS: 0xC SIZE: 0x4
		unsigned int workMemorySize; //OFS: 0x10 SIZE: 0x4
		unsigned int smallAllocatorBlocks; //OFS: 0x14 SIZE: 0x4
		unsigned int maxGroups; //OFS: 0x18 SIZE: 0x4
		unsigned int maxShards; //OFS: 0x1C SIZE: 0x4
		unsigned int maxPhysics; //OFS: 0x20 SIZE: 0x4
		unsigned int shardMemorySize; //OFS: 0x24 SIZE: 0x4
		unsigned int maxFreeCmd; //OFS: 0x28 SIZE: 0x4
		unsigned int numSlots; //OFS: 0x2C SIZE: 0x4
		unsigned int numVerts; //OFS: 0x30 SIZE: 0x4
		unsigned int numIndices; //OFS: 0x34 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(Glasses, 0x38);
	ASSERT_STRUCT_OFFSET(Glasses, name, 0x0);
	ASSERT_STRUCT_OFFSET(Glasses, numGlasses, 0x4);
	ASSERT_STRUCT_OFFSET(Glasses, glasses, 0x8);
	ASSERT_STRUCT_OFFSET(Glasses, workMemory, 0xC);
	ASSERT_STRUCT_OFFSET(Glasses, workMemorySize, 0x10);
	ASSERT_STRUCT_OFFSET(Glasses, smallAllocatorBlocks, 0x14);
	ASSERT_STRUCT_OFFSET(Glasses, maxGroups, 0x18);
	ASSERT_STRUCT_OFFSET(Glasses, maxShards, 0x1C);
	ASSERT_STRUCT_OFFSET(Glasses, maxPhysics, 0x20);
	ASSERT_STRUCT_OFFSET(Glasses, shardMemorySize, 0x24);
	ASSERT_STRUCT_OFFSET(Glasses, maxFreeCmd, 0x28);
	ASSERT_STRUCT_OFFSET(Glasses, numSlots, 0x2C);
	ASSERT_STRUCT_OFFSET(Glasses, numVerts, 0x30);
	ASSERT_STRUCT_OFFSET(Glasses, numIndices, 0x34);

	struct EmblemLayer
	{
		int cost; //OFS: 0x0 SIZE: 0x4
		int unlockLevel; //OFS: 0x4 SIZE: 0x4
		int unlockPLevel; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(EmblemLayer, 0xC);
	ASSERT_STRUCT_OFFSET(EmblemLayer, cost, 0x0);
	ASSERT_STRUCT_OFFSET(EmblemLayer, unlockLevel, 0x4);
	ASSERT_STRUCT_OFFSET(EmblemLayer, unlockPLevel, 0x8);

	struct EmblemCategory
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		const char* description; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(EmblemCategory, 0x8);
	ASSERT_STRUCT_OFFSET(EmblemCategory, name, 0x0);
	ASSERT_STRUCT_OFFSET(EmblemCategory, description, 0x4);

	struct EmblemIconType
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		const char* description; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(EmblemIconType, 0x8);
	ASSERT_STRUCT_OFFSET(EmblemIconType, name, 0x0);
	ASSERT_STRUCT_OFFSET(EmblemIconType, description, 0x4);

	struct EmblemBGCategory
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		const char* description; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(EmblemBGCategory, 0x8);
	ASSERT_STRUCT_OFFSET(EmblemBGCategory, name, 0x0);
	ASSERT_STRUCT_OFFSET(EmblemBGCategory, description, 0x4);

	struct EmblemIcon
	{
		GfxImage* image; //OFS: 0x0 SIZE: 0x4
		const char* description; //OFS: 0x4 SIZE: 0x4
		float outlineSize; //OFS: 0x8 SIZE: 0x4
		int cost; //OFS: 0xC SIZE: 0x4
		int unlockLevel; //OFS: 0x10 SIZE: 0x4
		int unlockPLevel; //OFS: 0x14 SIZE: 0x4
		int unclassifyAt; //OFS: 0x18 SIZE: 0x4
		int sortKey; //OFS: 0x1C SIZE: 0x4
		unsigned __int16 iconType; //OFS: 0x20 SIZE: 0x2
		unsigned __int16 category; //OFS: 0x22 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(EmblemIcon, 0x24);
	ASSERT_STRUCT_OFFSET(EmblemIcon, image, 0x0);
	ASSERT_STRUCT_OFFSET(EmblemIcon, description, 0x4);
	ASSERT_STRUCT_OFFSET(EmblemIcon, outlineSize, 0x8);
	ASSERT_STRUCT_OFFSET(EmblemIcon, cost, 0xC);
	ASSERT_STRUCT_OFFSET(EmblemIcon, unlockLevel, 0x10);
	ASSERT_STRUCT_OFFSET(EmblemIcon, unlockPLevel, 0x14);
	ASSERT_STRUCT_OFFSET(EmblemIcon, unclassifyAt, 0x18);
	ASSERT_STRUCT_OFFSET(EmblemIcon, sortKey, 0x1C);
	ASSERT_STRUCT_OFFSET(EmblemIcon, iconType, 0x20);
	ASSERT_STRUCT_OFFSET(EmblemIcon, category, 0x22);

	struct EmblemBackground
	{
		Material* material; //OFS: 0x0 SIZE: 0x4
		const char* description; //OFS: 0x4 SIZE: 0x4
		int cost; //OFS: 0x8 SIZE: 0x4
		int unlockLevel; //OFS: 0xC SIZE: 0x4
		int unlockPLevel; //OFS: 0x10 SIZE: 0x4
		int unclassifyAt; //OFS: 0x14 SIZE: 0x4
		int sortKey; //OFS: 0x18 SIZE: 0x4
		unsigned __int16 bgCategory; //OFS: 0x1C SIZE: 0x2
		int mtxIndex; //OFS: 0x20 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(EmblemBackground, 0x24);
	ASSERT_STRUCT_OFFSET(EmblemBackground, material, 0x0);
	ASSERT_STRUCT_OFFSET(EmblemBackground, description, 0x4);
	ASSERT_STRUCT_OFFSET(EmblemBackground, cost, 0x8);
	ASSERT_STRUCT_OFFSET(EmblemBackground, unlockLevel, 0xC);
	ASSERT_STRUCT_OFFSET(EmblemBackground, unlockPLevel, 0x10);
	ASSERT_STRUCT_OFFSET(EmblemBackground, unclassifyAt, 0x14);
	ASSERT_STRUCT_OFFSET(EmblemBackground, sortKey, 0x18);
	ASSERT_STRUCT_OFFSET(EmblemBackground, bgCategory, 0x1C);
	ASSERT_STRUCT_OFFSET(EmblemBackground, mtxIndex, 0x20);

	struct EmblemSet
	{
		int colorCount; //OFS: 0x0 SIZE: 0x4
		int layerCount; //OFS: 0x4 SIZE: 0x4
		EmblemLayer layers[32]; //OFS: 0x8 SIZE: 0x180
		int categoryCount; //OFS: 0x188 SIZE: 0x4
		EmblemCategory categories[16]; //OFS: 0x18C SIZE: 0x80
		int iconTypeCount; //OFS: 0x20C SIZE: 0x4
		EmblemIconType iconTypes[16]; //OFS: 0x210 SIZE: 0x80
		int bgCategoryCount; //OFS: 0x290 SIZE: 0x4
		EmblemBGCategory bgCategories[16]; //OFS: 0x294 SIZE: 0x80
		int iconCount; //OFS: 0x314 SIZE: 0x4
		EmblemIcon icons[1024]; //OFS: 0x318 SIZE: 0x9000
		int backgroundCount; //OFS: 0x9318 SIZE: 0x4
		EmblemBackground backgrounds[580]; //OFS: 0x931C SIZE: 0x5190
		int backgroundLookupCount; //OFS: 0xE4AC SIZE: 0x4
		__int16 backgroundLookup[580]; //OFS: 0xE4B0 SIZE: 0x488
	};
	ASSERT_STRUCT_SIZE(EmblemSet, 0xE938);
	ASSERT_STRUCT_OFFSET(EmblemSet, colorCount, 0x0);
	ASSERT_STRUCT_OFFSET(EmblemSet, layerCount, 0x4);
	ASSERT_STRUCT_OFFSET(EmblemSet, layers, 0x8);
	ASSERT_STRUCT_OFFSET(EmblemSet, categoryCount, 0x188);
	ASSERT_STRUCT_OFFSET(EmblemSet, categories, 0x18C);
	ASSERT_STRUCT_OFFSET(EmblemSet, iconTypeCount, 0x20C);
	ASSERT_STRUCT_OFFSET(EmblemSet, iconTypes, 0x210);
	ASSERT_STRUCT_OFFSET(EmblemSet, bgCategoryCount, 0x290);
	ASSERT_STRUCT_OFFSET(EmblemSet, bgCategories, 0x294);
	ASSERT_STRUCT_OFFSET(EmblemSet, iconCount, 0x314);
	ASSERT_STRUCT_OFFSET(EmblemSet, icons, 0x318);
	ASSERT_STRUCT_OFFSET(EmblemSet, backgroundCount, 0x9318);
	ASSERT_STRUCT_OFFSET(EmblemSet, backgrounds, 0x931C);
	ASSERT_STRUCT_OFFSET(EmblemSet, backgroundLookupCount, 0xE4AC);
	ASSERT_STRUCT_OFFSET(EmblemSet, backgroundLookup, 0xE4B0);

	struct GSC_OBJ
	{
		char magic[8];
		unsigned int source_crc;
		unsigned int include_offset;
		unsigned int animtree_offset;
		unsigned int cseg_offset;
		unsigned int stringtablefixup_offset;
		unsigned int exports_offset;
		unsigned int imports_offset;
		unsigned int fixup_offset;
		unsigned int profile_offset;
		unsigned int cseg_size;
		unsigned __int16 name;
		unsigned __int16 stringtablefixup_count;
		unsigned __int16 exports_count;
		unsigned __int16 imports_count;
		unsigned __int16 fixup_count;
		unsigned __int16 profile_count;
		char include_count;
		char animtree_count;
		char flags;
	};

	struct ScriptParseTree
	{
		const char* name;
		int len;
		GSC_OBJ* obj;
	};
	ASSERT_STRUCT_SIZE(ScriptParseTree, 0xC);
	ASSERT_STRUCT_OFFSET(ScriptParseTree, name, 0x0);
	ASSERT_STRUCT_OFFSET(ScriptParseTree, len, 0x4);
	ASSERT_STRUCT_OFFSET(ScriptParseTree, obj, 0x8);

	struct KeyValuePair
	{
		int keyHash; //OFS: 0x0 SIZE: 0x4
		int namespaceHash; //OFS: 0x4 SIZE: 0x4
		const char* value; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(KeyValuePair, 0xC);
	ASSERT_STRUCT_OFFSET(KeyValuePair, keyHash, 0x0);
	ASSERT_STRUCT_OFFSET(KeyValuePair, namespaceHash, 0x4);
	ASSERT_STRUCT_OFFSET(KeyValuePair, value, 0x8);

	struct KeyValuePairs
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		int numVariables; //OFS: 0x4 SIZE: 0x4
		KeyValuePair* keyValuePairs; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(KeyValuePairs, 0xC);
	ASSERT_STRUCT_OFFSET(KeyValuePairs, name, 0x0);
	ASSERT_STRUCT_OFFSET(KeyValuePairs, numVariables, 0x4);
	ASSERT_STRUCT_OFFSET(KeyValuePairs, keyValuePairs, 0x8);

	struct view_limits_t
	{
		float horizSpanLeft; //OFS: 0x0 SIZE: 0x4
		float horizSpanRight; //OFS: 0x4 SIZE: 0x4
		float vertSpanUp; //OFS: 0x8 SIZE: 0x4
		float vertSpanDown; //OFS: 0xC SIZE: 0x4
		float horizResistLeft; //OFS: 0x10 SIZE: 0x4
		float horizResistRight; //OFS: 0x14 SIZE: 0x4
		float vertResistUp; //OFS: 0x18 SIZE: 0x4
		float vertResistDown; //OFS: 0x1C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(view_limits_t, 0x20);
	ASSERT_STRUCT_OFFSET(view_limits_t, horizSpanLeft, 0x0);
	ASSERT_STRUCT_OFFSET(view_limits_t, horizSpanRight, 0x4);
	ASSERT_STRUCT_OFFSET(view_limits_t, vertSpanUp, 0x8);
	ASSERT_STRUCT_OFFSET(view_limits_t, vertSpanDown, 0xC);
	ASSERT_STRUCT_OFFSET(view_limits_t, horizResistLeft, 0x10);
	ASSERT_STRUCT_OFFSET(view_limits_t, horizResistRight, 0x14);
	ASSERT_STRUCT_OFFSET(view_limits_t, vertResistUp, 0x18);
	ASSERT_STRUCT_OFFSET(view_limits_t, vertResistDown, 0x1C);

	struct GraphFloat
	{
		char name[64]; //OFS: 0x0 SIZE: 0x40
		vec2_t knots[32]; //OFS: 0x40 SIZE: 0x100
		int knotCount; //OFS: 0x140 SIZE: 0x4
		float scale; //OFS: 0x144 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GraphFloat, 0x148);
	ASSERT_STRUCT_OFFSET(GraphFloat, name, 0x0);
	ASSERT_STRUCT_OFFSET(GraphFloat, knots, 0x40);
	ASSERT_STRUCT_OFFSET(GraphFloat, knotCount, 0x140);
	ASSERT_STRUCT_OFFSET(GraphFloat, scale, 0x144);

	struct VehicleParameter
	{
		float m_speed_max; //OFS: 0x0 SIZE: 0x4
		float m_accel_max; //OFS: 0x4 SIZE: 0x4
		float m_reverse_scale; //OFS: 0x8 SIZE: 0x4
		float m_steer_angle_max; //OFS: 0xC SIZE: 0x4
		float m_steer_angle_speed_scale; //OFS: 0x10 SIZE: 0x4
		float m_steer_speed; //OFS: 0x14 SIZE: 0x4
		float m_wheel_radius; //OFS: 0x18 SIZE: 0x4
		float m_susp_spring_k; //OFS: 0x1C SIZE: 0x4
		float m_susp_damp_k; //OFS: 0x20 SIZE: 0x4
		float m_susp_adj; //OFS: 0x24 SIZE: 0x4
		float m_susp_hard_limit; //OFS: 0x28 SIZE: 0x4
		float m_susp_min_height; //OFS: 0x2C SIZE: 0x4
		float m_tire_fric_fwd; //OFS: 0x30 SIZE: 0x4
		float m_tire_fric_side; //OFS: 0x34 SIZE: 0x4
		float m_tire_fric_brake; //OFS: 0x38 SIZE: 0x4
		float m_tire_fric_hand_brake; //OFS: 0x3C SIZE: 0x4
		float m_body_mass; //OFS: 0x40 SIZE: 0x4
		float m_roll_stability; //OFS: 0x44 SIZE: 0x4
		float m_pitch_stability; //OFS: 0x48 SIZE: 0x4
		float m_pitch_roll_resistance; //OFS: 0x4C SIZE: 0x4
		float m_yaw_resistance; //OFS: 0x50 SIZE: 0x4
		float m_upright_strength; //OFS: 0x54 SIZE: 0x4
		float m_tilt_fakey; //OFS: 0x58 SIZE: 0x4
		float m_peel_out_max_speed; //OFS: 0x5C SIZE: 0x4
		float m_tire_damp_coast; //OFS: 0x60 SIZE: 0x4
		float m_tire_damp_brake; //OFS: 0x64 SIZE: 0x4
		float m_tire_damp_hand; //OFS: 0x68 SIZE: 0x4
		float m_auto_hand_brake_min_speed; //OFS: 0x6C SIZE: 0x4
		TractionType m_traction_type; //OFS: 0x70 SIZE: 0x4
		const char* m_name; //OFS: 0x74 SIZE: 0x4
		vec3_t m_bbox_min; //OFS: 0x78 SIZE: 0xC
		vec3_t m_bbox_max; //OFS: 0x84 SIZE: 0xC
		vec3_t m_mass_center_offset; //OFS: 0x90 SIZE: 0xC
		vec3_t m_buoyancybox_min; //OFS: 0x9C SIZE: 0xC
		vec3_t m_buoyancybox_max; //OFS: 0xA8 SIZE: 0xC
		float m_water_speed_max; //OFS: 0xB4 SIZE: 0x4
		float m_water_accel_max; //OFS: 0xB8 SIZE: 0x4
		float m_water_turn_accel; //OFS: 0xBC SIZE: 0x4
		float m_water_turn_speed_max; //OFS: 0xC0 SIZE: 0x4
		float m_water_ebrake_power; //OFS: 0xC4 SIZE: 0x4
		vec3_t m_boat_motor_offset; //OFS: 0xC8 SIZE: 0xC
		float m_boat_speed_rise; //OFS: 0xD4 SIZE: 0x4
		float m_boat_speed_tilt; //OFS: 0xD8 SIZE: 0x4
		float m_boat_side_fric_scale; //OFS: 0xDC SIZE: 0x4
		float m_boat_forward_fric_scale; //OFS: 0xE0 SIZE: 0x4
		float m_boat_vertical_fric_scale; //OFS: 0xE4 SIZE: 0x4
		float m_jump_force; //OFS: 0xE8 SIZE: 0x4
		float m_tire_fric_side_max; //OFS: 0xEC SIZE: 0x4
		bool m_drive_on_walls; //OFS: 0xF0 SIZE: 0x1
		float m_linear_drag_scale; //OFS: 0xF4 SIZE: 0x4
		float m_angular_drag_scale; //OFS: 0xF8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(VehicleParameter, 0xFC);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_speed_max, 0x0);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_accel_max, 0x4);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_reverse_scale, 0x8);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_steer_angle_max, 0xC);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_steer_angle_speed_scale, 0x10);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_steer_speed, 0x14);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_wheel_radius, 0x18);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_susp_spring_k, 0x1C);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_susp_damp_k, 0x20);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_susp_adj, 0x24);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_susp_hard_limit, 0x28);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_susp_min_height, 0x2C);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_tire_fric_fwd, 0x30);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_tire_fric_side, 0x34);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_tire_fric_brake, 0x38);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_tire_fric_hand_brake, 0x3C);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_body_mass, 0x40);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_roll_stability, 0x44);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_pitch_stability, 0x48);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_pitch_roll_resistance, 0x4C);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_yaw_resistance, 0x50);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_upright_strength, 0x54);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_tilt_fakey, 0x58);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_peel_out_max_speed, 0x5C);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_tire_damp_coast, 0x60);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_tire_damp_brake, 0x64);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_tire_damp_hand, 0x68);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_auto_hand_brake_min_speed, 0x6C);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_traction_type, 0x70);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_name, 0x74);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_bbox_min, 0x78);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_bbox_max, 0x84);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_mass_center_offset, 0x90);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_buoyancybox_min, 0x9C);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_buoyancybox_max, 0xA8);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_water_speed_max, 0xB4);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_water_accel_max, 0xB8);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_water_turn_accel, 0xBC);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_water_turn_speed_max, 0xC0);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_water_ebrake_power, 0xC4);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_boat_motor_offset, 0xC8);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_boat_speed_rise, 0xD4);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_boat_speed_tilt, 0xD8);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_boat_side_fric_scale, 0xDC);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_boat_forward_fric_scale, 0xE0);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_boat_vertical_fric_scale, 0xE4);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_jump_force, 0xE8);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_tire_fric_side_max, 0xEC);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_drive_on_walls, 0xF0);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_linear_drag_scale, 0xF4);
	ASSERT_STRUCT_OFFSET(VehicleParameter, m_angular_drag_scale, 0xF8);

	struct VehicleDriveBySound
	{
		int apex; //OFS: 0x0 SIZE: 0x4
		const char* name; //OFS: 0x4 SIZE: 0x4
		unsigned int alias; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(VehicleDriveBySound, 0xC);
	ASSERT_STRUCT_OFFSET(VehicleDriveBySound, apex, 0x0);
	ASSERT_STRUCT_OFFSET(VehicleDriveBySound, name, 0x4);
	ASSERT_STRUCT_OFFSET(VehicleDriveBySound, alias, 0x8);

	struct VehicleEngineSound
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		unsigned int alias; //OFS: 0x4 SIZE: 0x4
		float params[5]; //OFS: 0x8 SIZE: 0x14
	};
	ASSERT_STRUCT_SIZE(VehicleEngineSound, 0x1C);
	ASSERT_STRUCT_OFFSET(VehicleEngineSound, name, 0x0);
	ASSERT_STRUCT_OFFSET(VehicleEngineSound, alias, 0x4);
	ASSERT_STRUCT_OFFSET(VehicleEngineSound, params, 0x8);

	struct VehicleGearData
	{
		float minRPM; //OFS: 0x0 SIZE: 0x4
		float maxRPM; //OFS: 0x4 SIZE: 0x4
		float ratio; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(VehicleGearData, 0xC);
	ASSERT_STRUCT_OFFSET(VehicleGearData, minRPM, 0x0);
	ASSERT_STRUCT_OFFSET(VehicleGearData, maxRPM, 0x4);
	ASSERT_STRUCT_OFFSET(VehicleGearData, ratio, 0x8);

	struct VehicleEngine
	{
		float idleRpms; //OFS: 0x0 SIZE: 0x4
		float maxRpms; //OFS: 0x4 SIZE: 0x4
		float maxTorque; //OFS: 0x8 SIZE: 0x4
		float brakingCoeff; //OFS: 0xC SIZE: 0x4
		vec4_t loadFadeParams; //OFS: 0x10 SIZE: 0x10
		float loadScale; //OFS: 0x20 SIZE: 0x4
		float loadSmoothing; //OFS: 0x24 SIZE: 0x4
		float throttleLag; //OFS: 0x28 SIZE: 0x4
		float pitchScale; //OFS: 0x2C SIZE: 0x4
		VehicleEngineSound onload[5]; //OFS: 0x30 SIZE: 0x8C
		VehicleEngineSound offload[5]; //OFS: 0xBC SIZE: 0x8C
		int numGears; //OFS: 0x148 SIZE: 0x4
		int loopLastGear; //OFS: 0x14C SIZE: 0x4
		VehicleGearData gears[10]; //OFS: 0x150 SIZE: 0x78
	};
	ASSERT_STRUCT_SIZE(VehicleEngine, 0x1C8);
	ASSERT_STRUCT_OFFSET(VehicleEngine, idleRpms, 0x0);
	ASSERT_STRUCT_OFFSET(VehicleEngine, maxRpms, 0x4);
	ASSERT_STRUCT_OFFSET(VehicleEngine, maxTorque, 0x8);
	ASSERT_STRUCT_OFFSET(VehicleEngine, brakingCoeff, 0xC);
	ASSERT_STRUCT_OFFSET(VehicleEngine, loadFadeParams, 0x10);
	ASSERT_STRUCT_OFFSET(VehicleEngine, loadScale, 0x20);
	ASSERT_STRUCT_OFFSET(VehicleEngine, loadSmoothing, 0x24);
	ASSERT_STRUCT_OFFSET(VehicleEngine, throttleLag, 0x28);
	ASSERT_STRUCT_OFFSET(VehicleEngine, pitchScale, 0x2C);
	ASSERT_STRUCT_OFFSET(VehicleEngine, onload, 0x30);
	ASSERT_STRUCT_OFFSET(VehicleEngine, offload, 0xBC);
	ASSERT_STRUCT_OFFSET(VehicleEngine, numGears, 0x148);
	ASSERT_STRUCT_OFFSET(VehicleEngine, loopLastGear, 0x14C);
	ASSERT_STRUCT_OFFSET(VehicleEngine, gears, 0x150);

	struct VehicleAntenna
	{
		float springK; //OFS: 0x0 SIZE: 0x4
		float damp; //OFS: 0x4 SIZE: 0x4
		float length; //OFS: 0x8 SIZE: 0x4
		float gravity; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(VehicleAntenna, 0x10);
	ASSERT_STRUCT_OFFSET(VehicleAntenna, springK, 0x0);
	ASSERT_STRUCT_OFFSET(VehicleAntenna, damp, 0x4);
	ASSERT_STRUCT_OFFSET(VehicleAntenna, length, 0x8);
	ASSERT_STRUCT_OFFSET(VehicleAntenna, gravity, 0xC);

	struct VehicleDef
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		__int16 type; //OFS: 0x4 SIZE: 0x2
		int remoteControl; //OFS: 0x8 SIZE: 0x4
		int bulletDamage; //OFS: 0xC SIZE: 0x4
		int armorPiercingDamage; //OFS: 0x10 SIZE: 0x4
		int grenadeDamage; //OFS: 0x14 SIZE: 0x4
		int projectileDamage; //OFS: 0x18 SIZE: 0x4
		int projectileSplashDamage; //OFS: 0x1C SIZE: 0x4
		int heavyExplosiveDamage; //OFS: 0x20 SIZE: 0x4
		__int16 cameraMode; //OFS: 0x24 SIZE: 0x2
		int autoRecenterOnAccel; //OFS: 0x28 SIZE: 0x4
		int thirdPersonDriver; //OFS: 0x2C SIZE: 0x4
		int thirdPersonUseVehicleRoll; //OFS: 0x30 SIZE: 0x4
		int thirdPersonCameraPitchVehicleRelative; //OFS: 0x34 SIZE: 0x4
		int thirdPersonCameraHeightWorldRelative; //OFS: 0x38 SIZE: 0x4
		float thirdPersonCameraRange; //OFS: 0x3C SIZE: 0x4
		float thirdPersonCameraMinPitchClamp; //OFS: 0x40 SIZE: 0x4
		float thirdPersonCameraMaxPitchClamp; //OFS: 0x44 SIZE: 0x4
		float thirdPersonCameraHeight[2]; //OFS: 0x48 SIZE: 0x8
		float thirdPersonCameraPitch[2]; //OFS: 0x50 SIZE: 0x8
		int cameraAlwaysAutoCenter; //OFS: 0x58 SIZE: 0x4
		float cameraAutoCenterLerpRate; //OFS: 0x5C SIZE: 0x4
		float cameraAutoCenterMaxLerpRate; //OFS: 0x60 SIZE: 0x4
		float thirdPersonCameraSpringDistance; //OFS: 0x64 SIZE: 0x4
		float thirdPersonCameraSpringTime; //OFS: 0x68 SIZE: 0x4
		float thirdPersonCameraHandbrakeTurnRateInc; //OFS: 0x6C SIZE: 0x4
		float cameraFOV; //OFS: 0x70 SIZE: 0x4
		float cameraRollFraction; //OFS: 0x74 SIZE: 0x4
		vec3_t tagPlayerOffset; //OFS: 0x78 SIZE: 0xC
		int killcamCollision; //OFS: 0x84 SIZE: 0x4
		float killcamDist; //OFS: 0x88 SIZE: 0x4
		float killcamZDist; //OFS: 0x8C SIZE: 0x4
		float killcamMinDist; //OFS: 0x90 SIZE: 0x4
		float killcamZTargetOffset; //OFS: 0x94 SIZE: 0x4
		float killcamFOV; //OFS: 0x98 SIZE: 0x4
		float killcamNearBlur; //OFS: 0x9C SIZE: 0x4
		float killcamNearBlurStart; //OFS: 0xA0 SIZE: 0x4
		float killcamNearBlurEnd; //OFS: 0xA4 SIZE: 0x4
		float killcamFarBlur; //OFS: 0xA8 SIZE: 0x4
		float killcamFarBlurStart; //OFS: 0xAC SIZE: 0x4
		float killcamFarBlurEnd; //OFS: 0xB0 SIZE: 0x4
		int isDrivable; //OFS: 0xB4 SIZE: 0x4
		int numberOfSeats; //OFS: 0xB8 SIZE: 0x4
		int numberOfGunners; //OFS: 0xBC SIZE: 0x4
		int seatSwitchOrder[11]; //OFS: 0xC0 SIZE: 0x2C
		int driverControlledGunPos; //OFS: 0xEC SIZE: 0x4
		float entryPointRadius[5]; //OFS: 0xF0 SIZE: 0x14
		float texScrollScale; //OFS: 0x104 SIZE: 0x4
		float wheelRotRate; //OFS: 0x108 SIZE: 0x4
		float extraWheelRotScale; //OFS: 0x10C SIZE: 0x4
		int wheelChildTakesSteerYaw; //OFS: 0x110 SIZE: 0x4
		float maxSpeed; //OFS: 0x114 SIZE: 0x4
		float maxSpeedVertical; //OFS: 0x118 SIZE: 0x4
		float accel; //OFS: 0x11C SIZE: 0x4
		float accelVertical; //OFS: 0x120 SIZE: 0x4
		float rotRate; //OFS: 0x124 SIZE: 0x4
		float rotAccel; //OFS: 0x128 SIZE: 0x4
		float maxBodyPitch; //OFS: 0x12C SIZE: 0x4
		float maxBodyRoll; //OFS: 0x130 SIZE: 0x4
		float collisionDamage; //OFS: 0x134 SIZE: 0x4
		float collisionSpeed; //OFS: 0x138 SIZE: 0x4
		float suspensionTravel; //OFS: 0x13C SIZE: 0x4
		float heliCollisionScalar; //OFS: 0x140 SIZE: 0x4
		float viewPitchOffset; //OFS: 0x144 SIZE: 0x4
		float viewInfluence; //OFS: 0x148 SIZE: 0x4
		float tiltFromAcceleration[2]; //OFS: 0x14C SIZE: 0x8
		float tiltFromDeceleration[2]; //OFS: 0x154 SIZE: 0x8
		float tiltFromVelocity[2]; //OFS: 0x15C SIZE: 0x8
		float tiltSpeed[2]; //OFS: 0x164 SIZE: 0x8
		const char* turretWeapon; //OFS: 0x16C SIZE: 0x4
		view_limits_t turretViewLimits; //OFS: 0x170 SIZE: 0x20
		float turretRotRate; //OFS: 0x190 SIZE: 0x4
		int turretClampPlayerView; //OFS: 0x194 SIZE: 0x4
		int turretLockTurretToPlayerView; //OFS: 0x198 SIZE: 0x4
		const char* gunnerWeapon[4]; //OFS: 0x19C SIZE: 0x10
		unsigned __int16 gunnerWeaponIndex[4]; //OFS: 0x1AC SIZE: 0x8
		float gunnerRotRate; //OFS: 0x1B4 SIZE: 0x4
		vec2_t gunnerRestAngles[4]; //OFS: 0x1B8 SIZE: 0x20
		view_limits_t passengerViewLimits[6]; //OFS: 0x1D8 SIZE: 0xC0
		const char* sndNames[2]; //OFS: 0x298 SIZE: 0x8
		unsigned int sndIndices[2]; //OFS: 0x2A0 SIZE: 0x8
		const char* sndMaterialNames[3]; //OFS: 0x2A8 SIZE: 0xC
		float skidSpeedMin; //OFS: 0x2B4 SIZE: 0x4
		float skidSpeedMax; //OFS: 0x2B8 SIZE: 0x4
		const char* futzName; //OFS: 0x2BC SIZE: 0x4
		float futzBlend; //OFS: 0x2C0 SIZE: 0x4
		int animType; //OFS: 0x2C4 SIZE: 0x4
		const char* animSet; //OFS: 0x2C8 SIZE: 0x4
		int scriptedAnimationEntry; //OFS: 0x2CC SIZE: 0x4
		float mantleAngles[4]; //OFS: 0x2D0 SIZE: 0x10
		unsigned __int16 extraWheelTags[4]; //OFS: 0x2E0 SIZE: 0x8
		unsigned __int16 driverHideTag; //OFS: 0x2E8 SIZE: 0x2
		XModel* attachmentModels[4]; //OFS: 0x2EC SIZE: 0x10
		unsigned __int16 attachmentTags[4]; //OFS: 0x2FC SIZE: 0x8
		XModel* deathAttachmentModels[4]; //OFS: 0x304 SIZE: 0x10
		unsigned __int16 deathAttachmentTags[4]; //OFS: 0x314 SIZE: 0x8
		float tracerOffset[2]; //OFS: 0x31C SIZE: 0x8
		XModel* model; //OFS: 0x324 SIZE: 0x4
		XModel* viewModel; //OFS: 0x328 SIZE: 0x4
		XModel* deathModel; //OFS: 0x32C SIZE: 0x4
		XModel* enemyModel; //OFS: 0x330 SIZE: 0x4
		float modelSwapDelay; //OFS: 0x334 SIZE: 0x4
		const FxEffectDef* exhaustFx; //OFS: 0x338 SIZE: 0x4
		int oneExhaust; //OFS: 0x33C SIZE: 0x4
		const FxEffectDef* treadFx[32]; //OFS: 0x340 SIZE: 0x80
		const FxEffectDef* deathFx; //OFS: 0x3C0 SIZE: 0x4
		unsigned __int16 deathFxTag; //OFS: 0x3C4 SIZE: 0x2
		const char* deathFxSound; //OFS: 0x3C8 SIZE: 0x4
		const FxEffectDef* lightFx[4]; //OFS: 0x3CC SIZE: 0x10
		unsigned __int16 lightFxTag[4]; //OFS: 0x3DC SIZE: 0x8
		const FxEffectDef* friendlyLightFx; //OFS: 0x3E4 SIZE: 0x4
		unsigned __int16 friendlyLightFxTag; //OFS: 0x3E8 SIZE: 0x2
		const FxEffectDef* enemyLightFx; //OFS: 0x3EC SIZE: 0x4
		unsigned __int16 enemyLightFxTag; //OFS: 0x3F0 SIZE: 0x2
		float radiusDamageMin; //OFS: 0x3F4 SIZE: 0x4
		float radiusDamageMax; //OFS: 0x3F8 SIZE: 0x4
		float radiusDamageRadius; //OFS: 0x3FC SIZE: 0x4
		const char* shootShock; //OFS: 0x400 SIZE: 0x4
		const char* shootRumble; //OFS: 0x404 SIZE: 0x4
		float deathQuakeScale; //OFS: 0x408 SIZE: 0x4
		float deathQuakeDuration; //OFS: 0x40C SIZE: 0x4
		float deathQuakeRadius; //OFS: 0x410 SIZE: 0x4
		const char* rumbleType; //OFS: 0x414 SIZE: 0x4
		float rumbleScale; //OFS: 0x418 SIZE: 0x4
		float rumbleDuration; //OFS: 0x41C SIZE: 0x4
		float rumbleRadius; //OFS: 0x420 SIZE: 0x4
		float rumbleBaseTime; //OFS: 0x424 SIZE: 0x4
		float rumbleAdditionalTime; //OFS: 0x428 SIZE: 0x4
		int healthDefault; //OFS: 0x42C SIZE: 0x4
		int healthMin; //OFS: 0x430 SIZE: 0x4
		int healthMax; //OFS: 0x434 SIZE: 0x4
		int eTeam; //OFS: 0x438 SIZE: 0x4
		int boostAccelMultiplier; //OFS: 0x43C SIZE: 0x4
		float boostDuration; //OFS: 0x440 SIZE: 0x4
		float boostSpeedIncrease; //OFS: 0x444 SIZE: 0x4
		int addToCompass; //OFS: 0x448 SIZE: 0x4
		int addToCompassEnemy; //OFS: 0x44C SIZE: 0x4
		const char* compassIcon; //OFS: 0x450 SIZE: 0x4
		Material* compassIconMaterial; //OFS: 0x454 SIZE: 0x4
		const char* gasButtonName; //OFS: 0x458 SIZE: 0x4
		int gasButton; //OFS: 0x45C SIZE: 0x4
		const char* reverseBrakeButtonName; //OFS: 0x460 SIZE: 0x4
		int reverseBrakeButton; //OFS: 0x464 SIZE: 0x4
		const char* handBrakeButtonName; //OFS: 0x468 SIZE: 0x4
		int handBrakeButton; //OFS: 0x46C SIZE: 0x4
		const char* attackButtonName; //OFS: 0x470 SIZE: 0x4
		int attackButton; //OFS: 0x474 SIZE: 0x4
		const char* attackSecondaryButtonName; //OFS: 0x478 SIZE: 0x4
		int attackSecondaryButton; //OFS: 0x47C SIZE: 0x4
		const char* boostButtonName; //OFS: 0x480 SIZE: 0x4
		int boostButton; //OFS: 0x484 SIZE: 0x4
		const char* moveUpButtonName; //OFS: 0x488 SIZE: 0x4
		int moveUpButton; //OFS: 0x48C SIZE: 0x4
		const char* moveDownButtonName; //OFS: 0x490 SIZE: 0x4
		int moveDownButton; //OFS: 0x494 SIZE: 0x4
		const char* switchSeatButtonName; //OFS: 0x498 SIZE: 0x4
		int switchSeatButton; //OFS: 0x49C SIZE: 0x4
		const char* steerGraphName; //OFS: 0x4A0 SIZE: 0x4
		GraphFloat* steerGraph; //OFS: 0x4A4 SIZE: 0x4
		const char* accelGraphName; //OFS: 0x4A8 SIZE: 0x4
		GraphFloat* accelGraph; //OFS: 0x4AC SIZE: 0x4
		int isNitrous; //OFS: 0x4B0 SIZE: 0x4
		int isFourWheelSteering; //OFS: 0x4B4 SIZE: 0x4
		int useCollmap; //OFS: 0x4B8 SIZE: 0x4
		float radius; //OFS: 0x4BC SIZE: 0x4
		float minHeight; //OFS: 0x4C0 SIZE: 0x4
		float maxHeight; //OFS: 0x4C4 SIZE: 0x4
		float max_fric_tilt_angle; //OFS: 0x4C8 SIZE: 0x4
		float max_fric_tilt; //OFS: 0x4CC SIZE: 0x4
		int noDirectionalDamage; //OFS: 0x4D0 SIZE: 0x4
		int fakeBodyStabilizer; //OFS: 0x4D4 SIZE: 0x4
		float vehHelicopterBoundsRadius; //OFS: 0x4D8 SIZE: 0x4
		float vehHelicopterDecelerationFwd; //OFS: 0x4DC SIZE: 0x4
		float vehHelicopterDecelerationSide; //OFS: 0x4E0 SIZE: 0x4
		float vehHelicopterDecelerationUp; //OFS: 0x4E4 SIZE: 0x4
		float vehHelicopterTiltFromControllerAxes; //OFS: 0x4E8 SIZE: 0x4
		float vehHelicopterTiltFromFwdAndYaw; //OFS: 0x4EC SIZE: 0x4
		float vehHelicopterTiltFromFwdAndYaw_VelAtMaxTilt; //OFS: 0x4F0 SIZE: 0x4
		float vehHelicopterTiltMomentum; //OFS: 0x4F4 SIZE: 0x4
		int vehHelicopterQuadRotor; //OFS: 0x4F8 SIZE: 0x4
		int vehHelicopterAccelTwardsView; //OFS: 0x4FC SIZE: 0x4
		float maxRotorArmMovementAngle; //OFS: 0x500 SIZE: 0x4
		float maxRotorArmRotationAngle; //OFS: 0x504 SIZE: 0x4
		int vehHelicopterMaintainHeight; //OFS: 0x508 SIZE: 0x4
		int vehHelicopterMaintainMaxHeight; //OFS: 0x50C SIZE: 0x4
		float vehHelicopterMaintainHeightLimit; //OFS: 0x510 SIZE: 0x4
		float vehHelicopterMaintainHeightAccel; //OFS: 0x514 SIZE: 0x4
		float vehHelicopterMaintainHeightMinimum; //OFS: 0x518 SIZE: 0x4
		float vehHelicopterMaintainHeightMaximum; //OFS: 0x51C SIZE: 0x4
		float vehHelicopterMaintainCeilingMinimum; //OFS: 0x520 SIZE: 0x4
		int joltVehicle; //OFS: 0x524 SIZE: 0x4
		int joltVehicleDriver; //OFS: 0x528 SIZE: 0x4
		float joltMaxTime; //OFS: 0x52C SIZE: 0x4
		float joltTime; //OFS: 0x530 SIZE: 0x4
		float joltWaves; //OFS: 0x534 SIZE: 0x4
		float joltIntensity; //OFS: 0x538 SIZE: 0x4
		VehicleParameter nitrousVehParams; //OFS: 0x53C SIZE: 0xFC
		float driveBySoundRadius[2]; //OFS: 0x638 SIZE: 0x8
		VehicleDriveBySound driveBySounds[40]; //OFS: 0x640 SIZE: 0x1E0
		int doFootSteps; //OFS: 0x820 SIZE: 0x4
		int isSentient; //OFS: 0x824 SIZE: 0x4
		VehicleEngine engine; //OFS: 0x828 SIZE: 0x1C8
		VehicleAntenna antenna[2]; //OFS: 0x9F0 SIZE: 0x20
		char* csvInclude; //OFS: 0xA10 SIZE: 0x4
		float customFloat0; //OFS: 0xA14 SIZE: 0x4
		float customFloat1; //OFS: 0xA18 SIZE: 0x4
		float customFloat2; //OFS: 0xA1C SIZE: 0x4
		int customBool0; //OFS: 0xA20 SIZE: 0x4
		int customBool1; //OFS: 0xA24 SIZE: 0x4
		int customBool2; //OFS: 0xA28 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(VehicleDef, 0xA2C);
	ASSERT_STRUCT_OFFSET(VehicleDef, name, 0x0);
	ASSERT_STRUCT_OFFSET(VehicleDef, type, 0x4);
	ASSERT_STRUCT_OFFSET(VehicleDef, remoteControl, 0x8);
	ASSERT_STRUCT_OFFSET(VehicleDef, bulletDamage, 0xC);
	ASSERT_STRUCT_OFFSET(VehicleDef, armorPiercingDamage, 0x10);
	ASSERT_STRUCT_OFFSET(VehicleDef, grenadeDamage, 0x14);
	ASSERT_STRUCT_OFFSET(VehicleDef, projectileDamage, 0x18);
	ASSERT_STRUCT_OFFSET(VehicleDef, projectileSplashDamage, 0x1C);
	ASSERT_STRUCT_OFFSET(VehicleDef, heavyExplosiveDamage, 0x20);
	ASSERT_STRUCT_OFFSET(VehicleDef, cameraMode, 0x24);
	ASSERT_STRUCT_OFFSET(VehicleDef, autoRecenterOnAccel, 0x28);
	ASSERT_STRUCT_OFFSET(VehicleDef, thirdPersonDriver, 0x2C);
	ASSERT_STRUCT_OFFSET(VehicleDef, thirdPersonUseVehicleRoll, 0x30);
	ASSERT_STRUCT_OFFSET(VehicleDef, thirdPersonCameraPitchVehicleRelative, 0x34);
	ASSERT_STRUCT_OFFSET(VehicleDef, thirdPersonCameraHeightWorldRelative, 0x38);
	ASSERT_STRUCT_OFFSET(VehicleDef, thirdPersonCameraRange, 0x3C);
	ASSERT_STRUCT_OFFSET(VehicleDef, thirdPersonCameraMinPitchClamp, 0x40);
	ASSERT_STRUCT_OFFSET(VehicleDef, thirdPersonCameraMaxPitchClamp, 0x44);
	ASSERT_STRUCT_OFFSET(VehicleDef, thirdPersonCameraHeight, 0x48);
	ASSERT_STRUCT_OFFSET(VehicleDef, thirdPersonCameraPitch, 0x50);
	ASSERT_STRUCT_OFFSET(VehicleDef, cameraAlwaysAutoCenter, 0x58);
	ASSERT_STRUCT_OFFSET(VehicleDef, cameraAutoCenterLerpRate, 0x5C);
	ASSERT_STRUCT_OFFSET(VehicleDef, cameraAutoCenterMaxLerpRate, 0x60);
	ASSERT_STRUCT_OFFSET(VehicleDef, thirdPersonCameraSpringDistance, 0x64);
	ASSERT_STRUCT_OFFSET(VehicleDef, thirdPersonCameraSpringTime, 0x68);
	ASSERT_STRUCT_OFFSET(VehicleDef, thirdPersonCameraHandbrakeTurnRateInc, 0x6C);
	ASSERT_STRUCT_OFFSET(VehicleDef, cameraFOV, 0x70);
	ASSERT_STRUCT_OFFSET(VehicleDef, cameraRollFraction, 0x74);
	ASSERT_STRUCT_OFFSET(VehicleDef, tagPlayerOffset, 0x78);
	ASSERT_STRUCT_OFFSET(VehicleDef, killcamCollision, 0x84);
	ASSERT_STRUCT_OFFSET(VehicleDef, killcamDist, 0x88);
	ASSERT_STRUCT_OFFSET(VehicleDef, killcamZDist, 0x8C);
	ASSERT_STRUCT_OFFSET(VehicleDef, killcamMinDist, 0x90);
	ASSERT_STRUCT_OFFSET(VehicleDef, killcamZTargetOffset, 0x94);
	ASSERT_STRUCT_OFFSET(VehicleDef, killcamFOV, 0x98);
	ASSERT_STRUCT_OFFSET(VehicleDef, killcamNearBlur, 0x9C);
	ASSERT_STRUCT_OFFSET(VehicleDef, killcamNearBlurStart, 0xA0);
	ASSERT_STRUCT_OFFSET(VehicleDef, killcamNearBlurEnd, 0xA4);
	ASSERT_STRUCT_OFFSET(VehicleDef, killcamFarBlur, 0xA8);
	ASSERT_STRUCT_OFFSET(VehicleDef, killcamFarBlurStart, 0xAC);
	ASSERT_STRUCT_OFFSET(VehicleDef, killcamFarBlurEnd, 0xB0);
	ASSERT_STRUCT_OFFSET(VehicleDef, isDrivable, 0xB4);
	ASSERT_STRUCT_OFFSET(VehicleDef, numberOfSeats, 0xB8);
	ASSERT_STRUCT_OFFSET(VehicleDef, numberOfGunners, 0xBC);
	ASSERT_STRUCT_OFFSET(VehicleDef, seatSwitchOrder, 0xC0);
	ASSERT_STRUCT_OFFSET(VehicleDef, driverControlledGunPos, 0xEC);
	ASSERT_STRUCT_OFFSET(VehicleDef, entryPointRadius, 0xF0);
	ASSERT_STRUCT_OFFSET(VehicleDef, texScrollScale, 0x104);
	ASSERT_STRUCT_OFFSET(VehicleDef, wheelRotRate, 0x108);
	ASSERT_STRUCT_OFFSET(VehicleDef, extraWheelRotScale, 0x10C);
	ASSERT_STRUCT_OFFSET(VehicleDef, wheelChildTakesSteerYaw, 0x110);
	ASSERT_STRUCT_OFFSET(VehicleDef, maxSpeed, 0x114);
	ASSERT_STRUCT_OFFSET(VehicleDef, maxSpeedVertical, 0x118);
	ASSERT_STRUCT_OFFSET(VehicleDef, accel, 0x11C);
	ASSERT_STRUCT_OFFSET(VehicleDef, accelVertical, 0x120);
	ASSERT_STRUCT_OFFSET(VehicleDef, rotRate, 0x124);
	ASSERT_STRUCT_OFFSET(VehicleDef, rotAccel, 0x128);
	ASSERT_STRUCT_OFFSET(VehicleDef, maxBodyPitch, 0x12C);
	ASSERT_STRUCT_OFFSET(VehicleDef, maxBodyRoll, 0x130);
	ASSERT_STRUCT_OFFSET(VehicleDef, collisionDamage, 0x134);
	ASSERT_STRUCT_OFFSET(VehicleDef, collisionSpeed, 0x138);
	ASSERT_STRUCT_OFFSET(VehicleDef, suspensionTravel, 0x13C);
	ASSERT_STRUCT_OFFSET(VehicleDef, heliCollisionScalar, 0x140);
	ASSERT_STRUCT_OFFSET(VehicleDef, viewPitchOffset, 0x144);
	ASSERT_STRUCT_OFFSET(VehicleDef, viewInfluence, 0x148);
	ASSERT_STRUCT_OFFSET(VehicleDef, tiltFromAcceleration, 0x14C);
	ASSERT_STRUCT_OFFSET(VehicleDef, tiltFromDeceleration, 0x154);
	ASSERT_STRUCT_OFFSET(VehicleDef, tiltFromVelocity, 0x15C);
	ASSERT_STRUCT_OFFSET(VehicleDef, tiltSpeed, 0x164);
	ASSERT_STRUCT_OFFSET(VehicleDef, turretWeapon, 0x16C);
	ASSERT_STRUCT_OFFSET(VehicleDef, turretViewLimits, 0x170);
	ASSERT_STRUCT_OFFSET(VehicleDef, turretRotRate, 0x190);
	ASSERT_STRUCT_OFFSET(VehicleDef, turretClampPlayerView, 0x194);
	ASSERT_STRUCT_OFFSET(VehicleDef, turretLockTurretToPlayerView, 0x198);
	ASSERT_STRUCT_OFFSET(VehicleDef, gunnerWeapon, 0x19C);
	ASSERT_STRUCT_OFFSET(VehicleDef, gunnerWeaponIndex, 0x1AC);
	ASSERT_STRUCT_OFFSET(VehicleDef, gunnerRotRate, 0x1B4);
	ASSERT_STRUCT_OFFSET(VehicleDef, gunnerRestAngles, 0x1B8);
	ASSERT_STRUCT_OFFSET(VehicleDef, passengerViewLimits, 0x1D8);
	ASSERT_STRUCT_OFFSET(VehicleDef, sndNames, 0x298);
	ASSERT_STRUCT_OFFSET(VehicleDef, sndIndices, 0x2A0);
	ASSERT_STRUCT_OFFSET(VehicleDef, sndMaterialNames, 0x2A8);
	ASSERT_STRUCT_OFFSET(VehicleDef, skidSpeedMin, 0x2B4);
	ASSERT_STRUCT_OFFSET(VehicleDef, skidSpeedMax, 0x2B8);
	ASSERT_STRUCT_OFFSET(VehicleDef, futzName, 0x2BC);
	ASSERT_STRUCT_OFFSET(VehicleDef, futzBlend, 0x2C0);
	ASSERT_STRUCT_OFFSET(VehicleDef, animType, 0x2C4);
	ASSERT_STRUCT_OFFSET(VehicleDef, animSet, 0x2C8);
	ASSERT_STRUCT_OFFSET(VehicleDef, scriptedAnimationEntry, 0x2CC);
	ASSERT_STRUCT_OFFSET(VehicleDef, mantleAngles, 0x2D0);
	ASSERT_STRUCT_OFFSET(VehicleDef, extraWheelTags, 0x2E0);
	ASSERT_STRUCT_OFFSET(VehicleDef, driverHideTag, 0x2E8);
	ASSERT_STRUCT_OFFSET(VehicleDef, attachmentModels, 0x2EC);
	ASSERT_STRUCT_OFFSET(VehicleDef, attachmentTags, 0x2FC);
	ASSERT_STRUCT_OFFSET(VehicleDef, deathAttachmentModels, 0x304);
	ASSERT_STRUCT_OFFSET(VehicleDef, deathAttachmentTags, 0x314);
	ASSERT_STRUCT_OFFSET(VehicleDef, tracerOffset, 0x31C);
	ASSERT_STRUCT_OFFSET(VehicleDef, model, 0x324);
	ASSERT_STRUCT_OFFSET(VehicleDef, viewModel, 0x328);
	ASSERT_STRUCT_OFFSET(VehicleDef, deathModel, 0x32C);
	ASSERT_STRUCT_OFFSET(VehicleDef, enemyModel, 0x330);
	ASSERT_STRUCT_OFFSET(VehicleDef, modelSwapDelay, 0x334);
	ASSERT_STRUCT_OFFSET(VehicleDef, exhaustFx, 0x338);
	ASSERT_STRUCT_OFFSET(VehicleDef, oneExhaust, 0x33C);
	ASSERT_STRUCT_OFFSET(VehicleDef, treadFx, 0x340);
	ASSERT_STRUCT_OFFSET(VehicleDef, deathFx, 0x3C0);
	ASSERT_STRUCT_OFFSET(VehicleDef, deathFxTag, 0x3C4);
	ASSERT_STRUCT_OFFSET(VehicleDef, deathFxSound, 0x3C8);
	ASSERT_STRUCT_OFFSET(VehicleDef, lightFx, 0x3CC);
	ASSERT_STRUCT_OFFSET(VehicleDef, lightFxTag, 0x3DC);
	ASSERT_STRUCT_OFFSET(VehicleDef, friendlyLightFx, 0x3E4);
	ASSERT_STRUCT_OFFSET(VehicleDef, friendlyLightFxTag, 0x3E8);
	ASSERT_STRUCT_OFFSET(VehicleDef, enemyLightFx, 0x3EC);
	ASSERT_STRUCT_OFFSET(VehicleDef, enemyLightFxTag, 0x3F0);
	ASSERT_STRUCT_OFFSET(VehicleDef, radiusDamageMin, 0x3F4);
	ASSERT_STRUCT_OFFSET(VehicleDef, radiusDamageMax, 0x3F8);
	ASSERT_STRUCT_OFFSET(VehicleDef, radiusDamageRadius, 0x3FC);
	ASSERT_STRUCT_OFFSET(VehicleDef, shootShock, 0x400);
	ASSERT_STRUCT_OFFSET(VehicleDef, shootRumble, 0x404);
	ASSERT_STRUCT_OFFSET(VehicleDef, deathQuakeScale, 0x408);
	ASSERT_STRUCT_OFFSET(VehicleDef, deathQuakeDuration, 0x40C);
	ASSERT_STRUCT_OFFSET(VehicleDef, deathQuakeRadius, 0x410);
	ASSERT_STRUCT_OFFSET(VehicleDef, rumbleType, 0x414);
	ASSERT_STRUCT_OFFSET(VehicleDef, rumbleScale, 0x418);
	ASSERT_STRUCT_OFFSET(VehicleDef, rumbleDuration, 0x41C);
	ASSERT_STRUCT_OFFSET(VehicleDef, rumbleRadius, 0x420);
	ASSERT_STRUCT_OFFSET(VehicleDef, rumbleBaseTime, 0x424);
	ASSERT_STRUCT_OFFSET(VehicleDef, rumbleAdditionalTime, 0x428);
	ASSERT_STRUCT_OFFSET(VehicleDef, healthDefault, 0x42C);
	ASSERT_STRUCT_OFFSET(VehicleDef, healthMin, 0x430);
	ASSERT_STRUCT_OFFSET(VehicleDef, healthMax, 0x434);
	ASSERT_STRUCT_OFFSET(VehicleDef, eTeam, 0x438);
	ASSERT_STRUCT_OFFSET(VehicleDef, boostAccelMultiplier, 0x43C);
	ASSERT_STRUCT_OFFSET(VehicleDef, boostDuration, 0x440);
	ASSERT_STRUCT_OFFSET(VehicleDef, boostSpeedIncrease, 0x444);
	ASSERT_STRUCT_OFFSET(VehicleDef, addToCompass, 0x448);
	ASSERT_STRUCT_OFFSET(VehicleDef, addToCompassEnemy, 0x44C);
	ASSERT_STRUCT_OFFSET(VehicleDef, compassIcon, 0x450);
	ASSERT_STRUCT_OFFSET(VehicleDef, compassIconMaterial, 0x454);
	ASSERT_STRUCT_OFFSET(VehicleDef, gasButtonName, 0x458);
	ASSERT_STRUCT_OFFSET(VehicleDef, gasButton, 0x45C);
	ASSERT_STRUCT_OFFSET(VehicleDef, reverseBrakeButtonName, 0x460);
	ASSERT_STRUCT_OFFSET(VehicleDef, reverseBrakeButton, 0x464);
	ASSERT_STRUCT_OFFSET(VehicleDef, handBrakeButtonName, 0x468);
	ASSERT_STRUCT_OFFSET(VehicleDef, handBrakeButton, 0x46C);
	ASSERT_STRUCT_OFFSET(VehicleDef, attackButtonName, 0x470);
	ASSERT_STRUCT_OFFSET(VehicleDef, attackButton, 0x474);
	ASSERT_STRUCT_OFFSET(VehicleDef, attackSecondaryButtonName, 0x478);
	ASSERT_STRUCT_OFFSET(VehicleDef, attackSecondaryButton, 0x47C);
	ASSERT_STRUCT_OFFSET(VehicleDef, boostButtonName, 0x480);
	ASSERT_STRUCT_OFFSET(VehicleDef, boostButton, 0x484);
	ASSERT_STRUCT_OFFSET(VehicleDef, moveUpButtonName, 0x488);
	ASSERT_STRUCT_OFFSET(VehicleDef, moveUpButton, 0x48C);
	ASSERT_STRUCT_OFFSET(VehicleDef, moveDownButtonName, 0x490);
	ASSERT_STRUCT_OFFSET(VehicleDef, moveDownButton, 0x494);
	ASSERT_STRUCT_OFFSET(VehicleDef, switchSeatButtonName, 0x498);
	ASSERT_STRUCT_OFFSET(VehicleDef, switchSeatButton, 0x49C);
	ASSERT_STRUCT_OFFSET(VehicleDef, steerGraphName, 0x4A0);
	ASSERT_STRUCT_OFFSET(VehicleDef, steerGraph, 0x4A4);
	ASSERT_STRUCT_OFFSET(VehicleDef, accelGraphName, 0x4A8);
	ASSERT_STRUCT_OFFSET(VehicleDef, accelGraph, 0x4AC);
	ASSERT_STRUCT_OFFSET(VehicleDef, isNitrous, 0x4B0);
	ASSERT_STRUCT_OFFSET(VehicleDef, isFourWheelSteering, 0x4B4);
	ASSERT_STRUCT_OFFSET(VehicleDef, useCollmap, 0x4B8);
	ASSERT_STRUCT_OFFSET(VehicleDef, radius, 0x4BC);
	ASSERT_STRUCT_OFFSET(VehicleDef, minHeight, 0x4C0);
	ASSERT_STRUCT_OFFSET(VehicleDef, maxHeight, 0x4C4);
	ASSERT_STRUCT_OFFSET(VehicleDef, max_fric_tilt_angle, 0x4C8);
	ASSERT_STRUCT_OFFSET(VehicleDef, max_fric_tilt, 0x4CC);
	ASSERT_STRUCT_OFFSET(VehicleDef, noDirectionalDamage, 0x4D0);
	ASSERT_STRUCT_OFFSET(VehicleDef, fakeBodyStabilizer, 0x4D4);
	ASSERT_STRUCT_OFFSET(VehicleDef, vehHelicopterBoundsRadius, 0x4D8);
	ASSERT_STRUCT_OFFSET(VehicleDef, vehHelicopterDecelerationFwd, 0x4DC);
	ASSERT_STRUCT_OFFSET(VehicleDef, vehHelicopterDecelerationSide, 0x4E0);
	ASSERT_STRUCT_OFFSET(VehicleDef, vehHelicopterDecelerationUp, 0x4E4);
	ASSERT_STRUCT_OFFSET(VehicleDef, vehHelicopterTiltFromControllerAxes, 0x4E8);
	ASSERT_STRUCT_OFFSET(VehicleDef, vehHelicopterTiltFromFwdAndYaw, 0x4EC);
	ASSERT_STRUCT_OFFSET(VehicleDef, vehHelicopterTiltFromFwdAndYaw_VelAtMaxTilt, 0x4F0);
	ASSERT_STRUCT_OFFSET(VehicleDef, vehHelicopterTiltMomentum, 0x4F4);
	ASSERT_STRUCT_OFFSET(VehicleDef, vehHelicopterQuadRotor, 0x4F8);
	ASSERT_STRUCT_OFFSET(VehicleDef, vehHelicopterAccelTwardsView, 0x4FC);
	ASSERT_STRUCT_OFFSET(VehicleDef, maxRotorArmMovementAngle, 0x500);
	ASSERT_STRUCT_OFFSET(VehicleDef, maxRotorArmRotationAngle, 0x504);
	ASSERT_STRUCT_OFFSET(VehicleDef, vehHelicopterMaintainHeight, 0x508);
	ASSERT_STRUCT_OFFSET(VehicleDef, vehHelicopterMaintainMaxHeight, 0x50C);
	ASSERT_STRUCT_OFFSET(VehicleDef, vehHelicopterMaintainHeightLimit, 0x510);
	ASSERT_STRUCT_OFFSET(VehicleDef, vehHelicopterMaintainHeightAccel, 0x514);
	ASSERT_STRUCT_OFFSET(VehicleDef, vehHelicopterMaintainHeightMinimum, 0x518);
	ASSERT_STRUCT_OFFSET(VehicleDef, vehHelicopterMaintainHeightMaximum, 0x51C);
	ASSERT_STRUCT_OFFSET(VehicleDef, vehHelicopterMaintainCeilingMinimum, 0x520);
	ASSERT_STRUCT_OFFSET(VehicleDef, joltVehicle, 0x524);
	ASSERT_STRUCT_OFFSET(VehicleDef, joltVehicleDriver, 0x528);
	ASSERT_STRUCT_OFFSET(VehicleDef, joltMaxTime, 0x52C);
	ASSERT_STRUCT_OFFSET(VehicleDef, joltTime, 0x530);
	ASSERT_STRUCT_OFFSET(VehicleDef, joltWaves, 0x534);
	ASSERT_STRUCT_OFFSET(VehicleDef, joltIntensity, 0x538);
	ASSERT_STRUCT_OFFSET(VehicleDef, nitrousVehParams, 0x53C);
	ASSERT_STRUCT_OFFSET(VehicleDef, driveBySoundRadius, 0x638);
	ASSERT_STRUCT_OFFSET(VehicleDef, driveBySounds, 0x640);
	ASSERT_STRUCT_OFFSET(VehicleDef, doFootSteps, 0x820);
	ASSERT_STRUCT_OFFSET(VehicleDef, isSentient, 0x824);
	ASSERT_STRUCT_OFFSET(VehicleDef, engine, 0x828);
	ASSERT_STRUCT_OFFSET(VehicleDef, antenna, 0x9F0);
	ASSERT_STRUCT_OFFSET(VehicleDef, csvInclude, 0xA10);
	ASSERT_STRUCT_OFFSET(VehicleDef, customFloat0, 0xA14);
	ASSERT_STRUCT_OFFSET(VehicleDef, customFloat1, 0xA18);
	ASSERT_STRUCT_OFFSET(VehicleDef, customFloat2, 0xA1C);
	ASSERT_STRUCT_OFFSET(VehicleDef, customBool0, 0xA20);
	ASSERT_STRUCT_OFFSET(VehicleDef, customBool1, 0xA24);
	ASSERT_STRUCT_OFFSET(VehicleDef, customBool2, 0xA28);

	struct MemoryBlock
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		bool mainMem; //OFS: 0x4 SIZE: 0x1
		bool videoMem; //OFS: 0x5 SIZE: 0x1
		bool streamMem; //OFS: 0x6 SIZE: 0x1
		unsigned int size; //OFS: 0x8 SIZE: 0x4
		unsigned int alignment; //OFS: 0xC SIZE: 0x4
		unsigned __int8* data; //OFS: 0x10 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(MemoryBlock, 0x14);
	ASSERT_STRUCT_OFFSET(MemoryBlock, name, 0x0);
	ASSERT_STRUCT_OFFSET(MemoryBlock, mainMem, 0x4);
	ASSERT_STRUCT_OFFSET(MemoryBlock, videoMem, 0x5);
	ASSERT_STRUCT_OFFSET(MemoryBlock, streamMem, 0x6);
	ASSERT_STRUCT_OFFSET(MemoryBlock, size, 0x8);
	ASSERT_STRUCT_OFFSET(MemoryBlock, alignment, 0xC);
	ASSERT_STRUCT_OFFSET(MemoryBlock, data, 0x10);

	struct AddonMapEnts
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		char* entityString; //OFS: 0x4 SIZE: 0x4
		int numEntityChars; //OFS: 0x8 SIZE: 0x4
		MapTriggers trigger; //OFS: 0xC SIZE: 0x18
		ClipInfo* info; //OFS: 0x24 SIZE: 0x4
		unsigned int numSubModels; //OFS: 0x28 SIZE: 0x4
		cmodel_t* cmodels; //OFS: 0x2C SIZE: 0x4
		GfxBrushModel* models; //OFS: 0x30 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(AddonMapEnts, 0x34);
	ASSERT_STRUCT_OFFSET(AddonMapEnts, name, 0x0);
	ASSERT_STRUCT_OFFSET(AddonMapEnts, entityString, 0x4);
	ASSERT_STRUCT_OFFSET(AddonMapEnts, numEntityChars, 0x8);
	ASSERT_STRUCT_OFFSET(AddonMapEnts, trigger, 0xC);
	ASSERT_STRUCT_OFFSET(AddonMapEnts, info, 0x24);
	ASSERT_STRUCT_OFFSET(AddonMapEnts, numSubModels, 0x28);
	ASSERT_STRUCT_OFFSET(AddonMapEnts, cmodels, 0x2C);
	ASSERT_STRUCT_OFFSET(AddonMapEnts, models, 0x30);

	struct SkinnedVertsDef
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		unsigned int maxSkinnedVerts; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(SkinnedVertsDef, 0x8);
	ASSERT_STRUCT_OFFSET(SkinnedVertsDef, name, 0x0);
	ASSERT_STRUCT_OFFSET(SkinnedVertsDef, maxSkinnedVerts, 0x4);

	struct Qdb
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		int len; //OFS: 0x4 SIZE: 0x4
		unsigned __int8* buffer; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(Qdb, 0xC);
	ASSERT_STRUCT_OFFSET(Qdb, name, 0x0);
	ASSERT_STRUCT_OFFSET(Qdb, len, 0x4);
	ASSERT_STRUCT_OFFSET(Qdb, buffer, 0x8);

	struct Slug
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		int len; //OFS: 0x4 SIZE: 0x4
		unsigned __int8* buffer; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(Slug, 0xC);
	ASSERT_STRUCT_OFFSET(Slug, name, 0x0);
	ASSERT_STRUCT_OFFSET(Slug, len, 0x4);
	ASSERT_STRUCT_OFFSET(Slug, buffer, 0x8);

	struct FootstepTableDef
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		unsigned int sndAliasTable[32][7]; //OFS: 0x4 SIZE: 0x380
	};
	ASSERT_STRUCT_SIZE(FootstepTableDef, 0x384);
	ASSERT_STRUCT_OFFSET(FootstepTableDef, name, 0x0);
	ASSERT_STRUCT_OFFSET(FootstepTableDef, sndAliasTable, 0x4);

	struct FootstepFXTableDef
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		const FxEffectDef* footstepFX[32]; //OFS: 0x4 SIZE: 0x80
	};
	ASSERT_STRUCT_SIZE(FootstepFXTableDef, 0x84);
	ASSERT_STRUCT_OFFSET(FootstepFXTableDef, name, 0x0);
	ASSERT_STRUCT_OFFSET(FootstepFXTableDef, footstepFX, 0x4);

	struct ZBarrierBoard
	{
		XModel* pBoardModel; //OFS: 0x0 SIZE: 0x4
		XModel* pAlternateBoardModel; //OFS: 0x4 SIZE: 0x4
		XModel* pUpgradedBoardModel; //OFS: 0x8 SIZE: 0x4
		const char* pTearAnim; //OFS: 0xC SIZE: 0x4
		const char* pBoardAnim; //OFS: 0x10 SIZE: 0x4
		const FxEffectDef* repairEffect1; //OFS: 0x14 SIZE: 0x4
		const FxEffectDef* repairEffect2; //OFS: 0x18 SIZE: 0x4
		vec3_t repairEffect1Offset; //OFS: 0x1C SIZE: 0xC
		vec3_t repairEffect2Offset; //OFS: 0x28 SIZE: 0xC
		unsigned int boardRepairSound; //OFS: 0x34 SIZE: 0x4
		unsigned int boardRepairHoverSound; //OFS: 0x38 SIZE: 0x4
		unsigned int pauseAndRepeatRepSound; //OFS: 0x3C SIZE: 0x4
		float minPause; //OFS: 0x40 SIZE: 0x4
		float maxPause; //OFS: 0x44 SIZE: 0x4
		unsigned __int16 zombieBoardTearStateName; //OFS: 0x48 SIZE: 0x2
		unsigned __int16 zombieBoardTearSubStateName; //OFS: 0x4A SIZE: 0x2
		unsigned int numRepsToPullProBoard; //OFS: 0x4C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(ZBarrierBoard, 0x50);
	ASSERT_STRUCT_OFFSET(ZBarrierBoard, pBoardModel, 0x0);
	ASSERT_STRUCT_OFFSET(ZBarrierBoard, pAlternateBoardModel, 0x4);
	ASSERT_STRUCT_OFFSET(ZBarrierBoard, pUpgradedBoardModel, 0x8);
	ASSERT_STRUCT_OFFSET(ZBarrierBoard, pTearAnim, 0xC);
	ASSERT_STRUCT_OFFSET(ZBarrierBoard, pBoardAnim, 0x10);
	ASSERT_STRUCT_OFFSET(ZBarrierBoard, repairEffect1, 0x14);
	ASSERT_STRUCT_OFFSET(ZBarrierBoard, repairEffect2, 0x18);
	ASSERT_STRUCT_OFFSET(ZBarrierBoard, repairEffect1Offset, 0x1C);
	ASSERT_STRUCT_OFFSET(ZBarrierBoard, repairEffect2Offset, 0x28);
	ASSERT_STRUCT_OFFSET(ZBarrierBoard, boardRepairSound, 0x34);
	ASSERT_STRUCT_OFFSET(ZBarrierBoard, boardRepairHoverSound, 0x38);
	ASSERT_STRUCT_OFFSET(ZBarrierBoard, pauseAndRepeatRepSound, 0x3C);
	ASSERT_STRUCT_OFFSET(ZBarrierBoard, minPause, 0x40);
	ASSERT_STRUCT_OFFSET(ZBarrierBoard, maxPause, 0x44);
	ASSERT_STRUCT_OFFSET(ZBarrierBoard, zombieBoardTearStateName, 0x48);
	ASSERT_STRUCT_OFFSET(ZBarrierBoard, zombieBoardTearSubStateName, 0x4A);
	ASSERT_STRUCT_OFFSET(ZBarrierBoard, numRepsToPullProBoard, 0x4C);

	struct ZBarrierDef
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		unsigned int generalRepairSound1; //OFS: 0x4 SIZE: 0x4
		unsigned int generalRepairSound2; //OFS: 0x8 SIZE: 0x4
		unsigned int upgradedGeneralRepairSound1; //OFS: 0xC SIZE: 0x4
		unsigned int upgradedGeneralRepairSound2; //OFS: 0x10 SIZE: 0x4
		unsigned int delayBetweenRepSounds; //OFS: 0x14 SIZE: 0x4
		float delayBetweenRepSoundsDuration; //OFS: 0x18 SIZE: 0x4
		unsigned int earthquakeOnRepair; //OFS: 0x1C SIZE: 0x4
		float earthquakeMinScale; //OFS: 0x20 SIZE: 0x4
		float earthquakeMaxScale; //OFS: 0x24 SIZE: 0x4
		float earthquakeMinDuration; //OFS: 0x28 SIZE: 0x4
		float earthquakeMaxDuration; //OFS: 0x2C SIZE: 0x4
		float earthquakeRadius; //OFS: 0x30 SIZE: 0x4
		int numBoardsInBarrier; //OFS: 0x34 SIZE: 0x4
		unsigned int autoHideOpenPieces; //OFS: 0x38 SIZE: 0x4
		unsigned int taunts; //OFS: 0x3C SIZE: 0x4
		unsigned int reachThroughAttacks; //OFS: 0x40 SIZE: 0x4
		unsigned __int16 zombieTauntAnimState; //OFS: 0x44 SIZE: 0x2
		unsigned __int16 zombieReachThroughAnimState; //OFS: 0x46 SIZE: 0x2
		int numAttackSlots; //OFS: 0x48 SIZE: 0x4
		float attackSpotHorzOffset; //OFS: 0x4C SIZE: 0x4
		ZBarrierBoard boards[6]; //OFS: 0x50 SIZE: 0x1E0
	};
	ASSERT_STRUCT_SIZE(ZBarrierDef, 0x230);
	ASSERT_STRUCT_OFFSET(ZBarrierDef, name, 0x0);
	ASSERT_STRUCT_OFFSET(ZBarrierDef, generalRepairSound1, 0x4);
	ASSERT_STRUCT_OFFSET(ZBarrierDef, generalRepairSound2, 0x8);
	ASSERT_STRUCT_OFFSET(ZBarrierDef, upgradedGeneralRepairSound1, 0xC);
	ASSERT_STRUCT_OFFSET(ZBarrierDef, upgradedGeneralRepairSound2, 0x10);
	ASSERT_STRUCT_OFFSET(ZBarrierDef, delayBetweenRepSounds, 0x14);
	ASSERT_STRUCT_OFFSET(ZBarrierDef, delayBetweenRepSoundsDuration, 0x18);
	ASSERT_STRUCT_OFFSET(ZBarrierDef, earthquakeOnRepair, 0x1C);
	ASSERT_STRUCT_OFFSET(ZBarrierDef, earthquakeMinScale, 0x20);
	ASSERT_STRUCT_OFFSET(ZBarrierDef, earthquakeMaxScale, 0x24);
	ASSERT_STRUCT_OFFSET(ZBarrierDef, earthquakeMinDuration, 0x28);
	ASSERT_STRUCT_OFFSET(ZBarrierDef, earthquakeMaxDuration, 0x2C);
	ASSERT_STRUCT_OFFSET(ZBarrierDef, earthquakeRadius, 0x30);
	ASSERT_STRUCT_OFFSET(ZBarrierDef, numBoardsInBarrier, 0x34);
	ASSERT_STRUCT_OFFSET(ZBarrierDef, autoHideOpenPieces, 0x38);
	ASSERT_STRUCT_OFFSET(ZBarrierDef, taunts, 0x3C);
	ASSERT_STRUCT_OFFSET(ZBarrierDef, reachThroughAttacks, 0x40);
	ASSERT_STRUCT_OFFSET(ZBarrierDef, zombieTauntAnimState, 0x44);
	ASSERT_STRUCT_OFFSET(ZBarrierDef, zombieReachThroughAnimState, 0x46);
	ASSERT_STRUCT_OFFSET(ZBarrierDef, numAttackSlots, 0x48);
	ASSERT_STRUCT_OFFSET(ZBarrierDef, attackSpotHorzOffset, 0x4C);
	ASSERT_STRUCT_OFFSET(ZBarrierDef, boards, 0x50);

	union XAssetHeader
	{
		XModelPieces* xmodelPieces; //OFS: 0x0 SIZE: 0x4
		PhysPreset* physPreset; //OFS: 0x1 SIZE: 0x4
		PhysConstraints* physConstraints; //OFS: 0x2 SIZE: 0x4
		DestructibleDef* destructibleDef; //OFS: 0x3 SIZE: 0x4
		XAnimParts* parts; //OFS: 0x4 SIZE: 0x4
		XModel* model; //OFS: 0x5 SIZE: 0x4
		Material* material; //OFS: 0x6 SIZE: 0x4
		MaterialPixelShader* pixelShader; //OFS: 0x7 SIZE: 0x4
		MaterialVertexShader* vertexShader; //OFS: 0x8 SIZE: 0x4
		MaterialTechniqueSet* techniqueSet; //OFS: 0x9 SIZE: 0x4
		GfxImage* image; //OFS: 0xA SIZE: 0x4
		//SndBank* sound; //OFS: 0xB SIZE: 0x4
		SndPatch* soundPatch; //OFS: 0xC SIZE: 0x4
		clipMap_t* clipMap; //OFS: 0xD SIZE: 0x4
		ComWorld* comWorld; //OFS: 0xE SIZE: 0x4
		GameWorldSp* gameWorldSp; //OFS: 0xF SIZE: 0x4
		GameWorldMp* gameWorldMp; //OFS: 0x10 SIZE: 0x4
		MapEnts* mapEnts; //OFS: 0x11 SIZE: 0x4
		GfxWorld* gfxWorld; //OFS: 0x12 SIZE: 0x4
		GfxLightDef* lightDef; //OFS: 0x13 SIZE: 0x4
		Font_s* font; //OFS: 0x14 SIZE: 0x4
		FontIcon* fontIcon; //OFS: 0x15 SIZE: 0x4
		MenuList* menuList; //OFS: 0x16 SIZE: 0x4
		menuDef_t* menu; //OFS: 0x17 SIZE: 0x4
		LocalizeEntry* localize; //OFS: 0x18 SIZE: 0x4
		WeaponVariantDef* weapon; //OFS: 0x19 SIZE: 0x4
		WeaponAttachment* attachment; //OFS: 0x1A SIZE: 0x4
		WeaponAttachmentUnique* attachmentUnique; //OFS: 0x1B SIZE: 0x4
		WeaponCamo* weaponCamo; //OFS: 0x1C SIZE: 0x4
		SndDriverGlobals* sndDriverGlobals; //OFS: 0x1D SIZE: 0x4
		const FxEffectDef* fx; //OFS: 0x1E SIZE: 0x4
		FxImpactTable* impactFx; //OFS: 0x1F SIZE: 0x4
		RawFile* rawfile; //OFS: 0x20 SIZE: 0x4
		StringTable* stringTable; //OFS: 0x21 SIZE: 0x4
		LeaderboardDef* leaderboardDef; //OFS: 0x22 SIZE: 0x4
		XGlobals* xGlobals; //OFS: 0x23 SIZE: 0x4
		ddlRoot_t* ddlRoot; //OFS: 0x24 SIZE: 0x4
		Glasses* glasses; //OFS: 0x25 SIZE: 0x4
		EmblemSet* emblemSet; //OFS: 0x26 SIZE: 0x4
		ScriptParseTree* scriptParseTree; //OFS: 0x27 SIZE: 0x4
		KeyValuePairs* keyValuePairs; //OFS: 0x28 SIZE: 0x4
		VehicleDef* vehicleDef; //OFS: 0x29 SIZE: 0x4
		MemoryBlock* memoryBlock; //OFS: 0x2A SIZE: 0x4
		AddonMapEnts* addonMapEnts; //OFS: 0x2B SIZE: 0x4
		TracerDef* tracerDef; //OFS: 0x2C SIZE: 0x4
		SkinnedVertsDef* skinnedVertsDef; //OFS: 0x2D SIZE: 0x4
		Qdb* qdb; //OFS: 0x2E SIZE: 0x4
		Slug* slug; //OFS: 0x2F SIZE: 0x4
		FootstepTableDef* footstepTableDef; //OFS: 0x30 SIZE: 0x4
		FootstepFXTableDef* footstepFXTableDef; //OFS: 0x31 SIZE: 0x4
		ZBarrierDef* zbarrierDef; //OFS: 0x32 SIZE: 0x4
		void* data; //OFS: 0x33 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(XAssetHeader, 0x4);

	struct XAsset
	{
		XAssetType type; //OFS: 0x0 SIZE: 0x4
		XAssetHeader header; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(XAsset, 0x8);
	ASSERT_STRUCT_OFFSET(XAsset, type, 0x0);
	ASSERT_STRUCT_OFFSET(XAsset, header, 0x4);

	struct XAssetEntry
	{
		XAsset asset; //OFS: 0x0 SIZE: 0x8
		unsigned __int8 zoneIndex; //OFS: 0x8 SIZE: 0x1
		bool inuse; //OFS: 0x9 SIZE: 0x1
		unsigned __int16 nextHash; //OFS: 0xA SIZE: 0x2
		unsigned __int16 nextOverride; //OFS: 0xC SIZE: 0x2
		unsigned __int16 usageFrame; //OFS: 0xE SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(XAssetEntry, 0x10);
	ASSERT_STRUCT_OFFSET(XAssetEntry, asset, 0x0);
	ASSERT_STRUCT_OFFSET(XAssetEntry, zoneIndex, 0x8);
	ASSERT_STRUCT_OFFSET(XAssetEntry, inuse, 0x9);
	ASSERT_STRUCT_OFFSET(XAssetEntry, nextHash, 0xA);
	ASSERT_STRUCT_OFFSET(XAssetEntry, nextOverride, 0xC);
	ASSERT_STRUCT_OFFSET(XAssetEntry, usageFrame, 0xE);

}