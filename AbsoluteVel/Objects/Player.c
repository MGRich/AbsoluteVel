#include "Player.h"

ObjectPlayer *Player;

void (*Player_ChangeCharacter)(EntityPlayer *player, int32 character) = NULL;

void Player_StageLoad(void)
{
    Mod.Super(Player->classID, SUPER_STAGELOAD, NULL);

    SceneInfo->debugMode = true;
}