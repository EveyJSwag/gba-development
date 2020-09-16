#include "game_properties.h"
#include "mem_util.h"

void changePos ( PLAYER* player, OBJ_ATTR* objAttr, int speed_x, int speed_y, int attrIndex)
{
    int prev_pos_x = player->playerPos.POS_X;
    int prev_pos_y = player->playerPos.POS_Y;
    player->playerPos.POS_X = prev_pos_x + speed_x;
    player->playerPos.POS_Y = prev_pos_y + speed_y;

    if ((prev_pos_x + (int)speed_x)<=0)
        player->playerPos.POS_X = 0;

    if ((prev_pos_x + (int)speed_x)>= (SCREEN_WIDTH - player->width))
        player->playerPos.POS_X = SCREEN_WIDTH - player->width;

    if ((prev_pos_y + (int)speed_y) <= 0 )
        player->playerPos.POS_Y = 0;

    if ((prev_pos_y + (int)speed_y) >= (SCREEN_LENGTH - player->height))
        player->playerPos.POS_Y = SCREEN_LENGTH - player->height;

    changePosAttr(objAttr, player->playerPos.POS_X, player->playerPos.POS_Y, attrIndex);
}

void updateAttr (OBJ_ATTR* objAttr, u16 xPos, u16 yPos)
{
    objAttr->attr0 = yPos;
    objAttr->attr1 = xPos;
    oam_mem[0] = *objAttr;
}



void hideSprite ( OBJ_ATTR* objAttr, int index ){
    objAttr->attr0 |= (2 << 8);
    oam_mem[index] = *objAttr;
}


void changePosAttr(OBJ_ATTR* objAttr, u16 x, u16 y, int attrIndex)
{
    u16 a0 = objAttr->attr0; u16 a1 = objAttr->attr1;
    a0&=(~POS_MASK_Y); a1&=(~POS_MASK_X);
    objAttr->attr0 = (a0 | (y & POS_MASK_Y) ); objAttr->attr1= (a1 | (x & POS_MASK_X) );
    oam_mem[attrIndex] = *objAttr;
}
