#include "game_properties.h"
#include "mem_util.h"

void changePos ( PLAYER* player, u16 speed_x, u16 speed_y, OBJ_ATTR* objAttr)
{
    int prev_pos_x = player->playerPos.POS_X;
    int prev_pos_y = player->playerPos.POS_Y;
    player->playerPos.POS_X = prev_pos_x + speed_x;
    player->playerPos.POS_Y = prev_pos_y + speed_y;
    updateAttr(objAttr, player->playerPos.POS_X, player->playerPos.POS_Y);
}

void updateAttr (OBJ_ATTR* objAttr, u16 xPos, u16 yPos)
{
    objAttr->attr0 = yPos;
    objAttr->attr1 = xPos;
    oam_mem[0] = *objAttr;
}
