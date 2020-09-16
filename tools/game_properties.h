#ifndef GAME_PROP
#define GAME_PROP
#include "mem_util.h"

typedef struct VECTOR
{
    signed short SPEED_X;
    signed short SPEED_Y;
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
    u16      height;
    u16      width;
} PLAYER;

#define POS_MASK_X 0x01FF
#define POS_MASK_Y 0x00FF

#define LOWER_BOUND_Y 124
#define UPPER_BOUND_Y 0

void changePos  ( PLAYER* player, OBJ_ATTR* objAttr, int speed_x, int speed_y, int attrIndex);

void hideSprite ( OBJ_ATTR* objAttr, int index);

void updateAttr (OBJ_ATTR* objAttr, u16 xPos, u16 yPos);

void changePosAttr(OBJ_ATTR* objAttr, u16 x, u16 y, int attrIndex);




#endif
