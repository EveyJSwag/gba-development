#include <stdio.h>
#include <string.h>
#include "../tools/mem_util.h"
#include "../tools/input.h"
#include "../tools/game_properties.h"
#include "../tools/game_characters.h"

int main()
{


    REG_DISPCNT = 0x1000 | 0x0040;

    ///////////////////////////////////////
    // PUT SOME COLORS INTO THE PALLETTE //
    ///////////////////////////////////////
    obj_pal_mem[0] = MAKE_COLOR(0,14,0);
    obj_pal_mem[1] = CLR_RED;
    obj_pal_mem[2] = CLR_TEAL;
    obj_pal_mem[3] = CLR_GREEN;
    obj_pal_mem[4] = CLR_WHITE;
    obj_pal_mem[5] = CLR_PURPLE;
    obj_pal_mem[6] = CLR_YELLOW;
    obj_pal_mem[7] = MAKE_COLOR(31, 15, 15);
    obj_pal_mem[8] = MAKE_COLOR(0, 31, 15);
    obj_pal_mem[9] = CLR_RED;
    obj_pal_mem[10] = MAKE_COLOR(5, 25, 4);

    //////////////////////////////////////
    // COPY SOME SAMPLE TILES INTO VRAM //
    //////////////////////////////////////
    memcpy(&tile_mem[5][0], BALL, 32);
    memcpy(&tile_mem[5][1], PONG_STICK_VID, 64);


    //////////////
    // PLAYER 1 //
    //////////////
    PLAYER player1;
    player1.playerPos.POS_X = 0;
    player1.playerPos.POS_Y = 0;
    player1.height = 16;
    player1.width  =  3;

    OBJ_ATTR PONG_STICK_ATTR;
    PONG_STICK_ATTR.attr0 = (2 << 14);
    PONG_STICK_ATTR.attr1 = 0;
    PONG_STICK_ATTR.attr2 = 513;
    oam_mem[0] = PONG_STICK_ATTR;
    short yValue = 0;

    //////////
    // BALL //
    //////////
    PLAYER ball;
    ball.playerPos.POS_X = SCREEN_WIDTH/2;
    ball.playerPos.POS_Y = SCREEN_LENGTH/2;
    ball.playerVector.SPEED_X = 3;
    ball.playerVector.SPEED_Y = -6;
    ball.height = 8;
    ball.width = 8;
    OBJ_ATTR BALL_ATTR;
    BALL_ATTR.attr0 = 0;
    BALL_ATTR.attr1 = 0;
    BALL_ATTR.attr2 = 512;
    changePosAttr(&BALL_ATTR, ball.playerPos.POS_X, ball.playerPos.POS_Y, 1);


    while(1)
    {
        vsync();
        setState();
        if (key_curr_press(KEY_DOWN))
            yValue = 2;
        if (key_curr_press(KEY_UP))
            yValue = -2;

        if ( (ball.playerPos.POS_X + ball.playerVector.SPEED_X) >= (SCREEN_WIDTH - ball.width) )
            ball.playerVector.SPEED_X *= -1;

        if ( (ball.playerPos.POS_Y + ball.playerVector.SPEED_Y) >= (SCREEN_LENGTH - ball.height) )
            ball.playerVector.SPEED_Y *= -1;


        changePos(&player1, &PONG_STICK_ATTR, 0, yValue, 0);
        changePos(&ball,    &BALL_ATTR, ball.playerVector.SPEED_X, ball.playerVector.SPEED_Y, 1);
        yValue = 0;
    }
    return 0;
}
