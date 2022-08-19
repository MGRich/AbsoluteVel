#include "../GameAPI/C/GameAPI/Game.h"

#include "Objects/Player.h"
#include "Objects/HUD.h"

#if RETRO_USE_MOD_LOADER
DLLExport bool32 LinkModLogic(EngineInfo *info, const char *id);
#endif

void InitModAPI(void)
{
    // Register Modded Objects
    MOD_REGISTER_OBJ_OVERLOAD(HUD, NULL, NULL, NULL, HUD_Draw, NULL, NULL, NULL, NULL, NULL);
    MOD_REGISTER_OBJ_OVERLOAD(Player, NULL, NULL, NULL, NULL, NULL, Player_StageLoad, NULL, NULL, NULL);

    // Get Public Funcs
     HUD_DrawNumbersBase10 = Mod.GetPublicFunction(NULL, "HUD_DrawNumbersBase10");
}

#if RETRO_USE_MOD_LOADER
#define ADD_PUBLIC_FUNC(func) Mod.AddPublicFunction(#func, (void *)(func))

void InitModAPI(void);

bool32 LinkModLogic(EngineInfo *info, const char *id)
{
#if MANIA_USE_PLUS
    LinkGameLogicDLL(info);
#else
    LinkGameLogicDLL(*info);
#endif

    globals = Mod.GetGlobals();

    modID = id;

    InitModAPI();

    return true;
}
#endif