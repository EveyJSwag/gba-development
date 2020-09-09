#ifndef GAME_PROP
#define GAME_PROP
#include "mem_util.h"

typedef struct VECTOR
{
    u16 SPEED_X;
    u16 SPEED_Y;
} VECTOR;

typedef struct POSITION
{
    u32 POS_X;
    u32 POS_Y;
} POSITION;

typedef struct PLAYER
{
    POSITION playerPos;
    VECTOR   playerVector;
} PLAYER;

void changePos ( PLAYER* player, u16 speed_x, u16 speed_y, OBJ_ATTR* objAttr);
void updateAttr (OBJ_ATTR* objAttr, u16 xPos, u16 yPos);

#endif
