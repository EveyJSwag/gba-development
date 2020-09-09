#include <stdio.h>
#include <string.h>
#include "../tools/mem_util.h"
#include "../tools/input.h"
#include "../tools/game_properties.h"
#include "../tools/game_characters.h"

int main()
{


/*
    PLAYER player1;

    u32 testPic[16] = {
    0x53535353,
    0x53535353,
    0x53535353,
    0x53535353,
    0x53535353,
    0x53535353,
    0x53535353,
    0x53535353,
    0x83838383,
    0x83838383,
    0x83838383,
    0x83838383,
    0x83838383,
    0x83838383,
    0x83838383,
    0x83838383
    };
*/
    REG_DISPCNT = 0x1000 | 0x0040;

    ///////////////////////////////////////
    // PUT SOME COLORS INTO THE PALLETTE //
    ///////////////////////////////////////
    obj_pal_mem[0] = MAKE_COLOR(0,14,0);
    obj_pal_mem[1] = CLR_BLUE;
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
    //memcpy(&tile_mem[5][0], testPic, 32);
    memcpy(&tile_mem[5][0], BALL, 32);
    memcpy(&tile_mem[6][0], PONG_STICK_VID, 64);

/*
    ///////////////////////////////////////
    // SET THE INITIAL PLAYER ATTRIBUTES //
    ///////////////////////////////////////
    player1.playerPos.POS_X = 20;
    player1.playerPos.POS_Y = 20;

    ///////////////////////////////////////////////
    // SET THE INITIAL ATTRIBUTES FOR THE SPRITE //
    ///////////////////////////////////////////////
    OBJ_ATTR blkOneAttr;
    blkOneAttr.attr0 = 20; // INITIAL Y POS
    blkOneAttr.attr1 = 20; // INITIAL X POS
    blkOneAttr.attr2 = 1 << 9;
    oam_mem[0] = blkOneAttr;
*/
    while(1){
        vsync();
        /*       // VSYNC TO PREVENT TEARING
        setState();     // READ KEY INPUTS
        if (key_curr_press(KEY_DOWN))
            changePos(&player1, 0, 2, &blkOneAttr);
        if (key_curr_press(KEY_RIGHT))
            changePos(&player1, 2, 0, &blkOneAttr);
        if (key_curr_press(KEY_UP))
            changePos(&player1, 0, -2, &blkOneAttr);
        if (key_curr_press(KEY_LEFT))
            changePos(&player1, -2, 0, &blkOneAttr);
        */
    }
    return 0;
}
