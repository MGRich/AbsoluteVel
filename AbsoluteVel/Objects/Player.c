#include "GameAPI/Game.h"
#include "Player.h"

void Player_Draw(void) {
    RSDK_THIS(Player);
    self->drawGroup = 15;
    Mod.Super(Player->classID, SUPER_DRAW, NULL);
}