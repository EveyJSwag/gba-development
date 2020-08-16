
////////////////////////////////////////////////////////
// A LOT OF THE DEFINITIONS AND NAMING STRUCTURES ARE //
// COPIED FROM TONC's TUTORIAL                        //
////////////////////////////////////////////////////////
#ifndef MEM_UTIL_H
#define MEM_UTIL_H

/////////////
// TYPEDEF //
/////////////
typedef unsigned short u16;
typedef unsigned int u32;
typedef volatile u32 uv32;
typedef u16 COLOR;
#define INLINE static inline

//////////////////////
// MEMORY ADDRESSES //
//////////////////////
#define MEM_IO   0x04000000
#define PAL_RAM  0x05000000
#define MEM_VRAM 0x06000000
#define OBJ_PAL  0x0200

///////////////////
// DISPLAY MODES //
///////////////////
/*########################
*** DISPLAY MODE GUIDE ***
     0-2: SPRITE BASED
     3-5: BITMAP BASED
#########################*/
#define DCNT_MODE0 0x0000
#define DCNT_MODE1 0x0001
#define DCNT_MODE2 0x0002
#define DCNT_MODE3 0x0003
#define DCNT_MODE4 0x0004
#define DCNT_MODE5 0x0005

//////////////////////
// BACKGROUND MODES //
//////////////////////
#define DCNT_BG0 0x0100
#define DCNT_BG1 0x0200
#define DCNT_BG2 0x0400
#define DCNT_BG3 0x0800
#define DCNT_OBJ 0x1000

/////////////////////////
// DISPLAY MODE SWITCH //
/////////////////////////
#define REG_DISPCNT *((uv32*)(MEM_IO+0x0000))

///////////////////////
// PAL MEMORY ARRAYS //
///////////////////////
#define pal_mem ((u16*)PAL_RAM)
#define obj_pal_mem ((u16*)(PAL_RAM+OBJ_PAL))

////////////////////////
// VIDEO MEMORY ARRAY //
////////////////////////
#define vid_mem ((u16*)MEM_VRAM)

///////////////////////
// COLOR DEFINITIONS //
///////////////////////
/**********************
  oBBB BBGG GGGR RRRR
0x0000 0000 0000 0000
***********************/
#define CLR_RED   0x001F
#define CLR_GREEN 0x03E0
#define CLR_BLUE  0x7C00
#define CLR_PURPLE ((CLR_RED) | (CLR_BLUE))
#define CLR_YELLOW ((CLR_RED) | (CLR_GREEN))
#define CLR_TEAL   ((CLR_GREEN)) | (CLR_BLUE))
#define CLR_WHITE  ((CLR_RED) | (CLR_GREEN) | (CLR_BLUE))
INLINE COLOR MAKE_COLOR(u32 redAmt, u32 greenAmt, u32 blueAmt)
{ return  (blueAmt << 10) | (greenAmt << 5) | redAmt; }

#endif
