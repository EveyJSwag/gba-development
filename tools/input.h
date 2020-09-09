#ifndef __INPUT__
#define __INPUT__

#include "mem_util.h"

#define MEM_IO_KEY  0x04000000
#define REG_KEYINPUT *(volatile u16*)(MEM_IO_KEY + 0x0130)

/*
---- --xx xxxx xxxx
0    3    F    F
*/
extern  u16 key_curr, key_prev;
u16 key_curr = 0;
u16 key_prev = 0;
INLINE void setState();

#define KEY_MASK    0x03FF
#define KEY_A       1
#define KEY_B       2
#define KEY_SELECT  4
#define KEY_START   8
#define KEY_RIGHT   16
#define KEY_LEFT    32
#define KEY_UP      64
#define KEY_DOWN    128
#define KEY_R       256
#define KEY_L       512


INLINE void setState (){
    key_prev = key_curr;
    key_curr = (~(REG_KEYINPUT)) & (KEY_MASK);
}

INLINE u32 key_curr_press   (u32 key) { return  key_curr & key; }
INLINE u32 key_curr_lift    (u32 key) { return ~key_curr & key; }
INLINE u32 key_prev_press   (u32 key) { return  key_prev & key; }
INLINE u32 key_prev_lift    (u32 key) { return ~key_prev & key; }


#endif
