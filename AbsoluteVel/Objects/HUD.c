#include "HUD.h"
#include "Player.h"

ObjectHUD *HUD;

void (*HUD_DrawNumbersBase10)(Vector2 *drawPos, int32 value, int32 digitCount) = NULL;

void HUD_Draw(void)
{
    RSDK_THIS(HUD);
    EntityPlayer *player = RSDK_GET_ENTITY(SceneInfo->currentScreenID, Player);

    Object *debugMode = Mod.FindObject("DebugMode");

    if (debugMode && HUD_DrawNumbersBase10) {
        if (player->camera) {
            player->camera->center = player->position;
            Vector2 debugPos;

            // Draw this (its drawn when debug mode is on by default
            if (RSDK_GET_ENTITY(SLOT_PLAYER1, Player)->classID != debugMode->classID) {
                // Draw Player YVel
                debugPos.x = TO_FIXED(85);
                debugPos.y = TO_FIXED(74);
                HUD_DrawNumbersBase10(&debugPos, abs(player->velocity.y >> 0x0C), 4);

                // Draw Player XVel
                debugPos.x -= 0x90000;
                HUD_DrawNumbersBase10(&debugPos, abs(player->onGround ? (player->groundVel >> 0x0C) : (player->velocity.x >> 0x0C)), 4);
            }
        }
    }
    Mod.Super(HUD->classID, SUPER_DRAW, NULL);
}
