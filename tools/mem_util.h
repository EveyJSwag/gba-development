
////////////////////////////////////////////////////////
// A LOT OF THE DEFINITIONS AND NAMING STRUCTURES ARE //
// COPIED FROM TONC's TUTORIAL                        //
////////////////////////////////////////////////////////
#ifndef MEM_UTIL_H
#define MEM_UTIL_H

////////////////////
// TYPEDEF/MACROS //
////////////////////
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef volatile u32 uv32;
typedef u16 COLOR;
#define INLINE static inline
#define ALIGN4 __attribute__((aligned(4)))

//////////////////////
// MEMORY ADDRESSES //
//////////////////////
#define MEM_IO          0x04000000
#define MEM_IO_VCOUNT   0x0006
#define PAL_RAM         0x05000000
#define MEM_VRAM        0x06000000
#define OBJ_PAL         0x0200
#define MEM_OAM         0x07000000

///////////////////
// DISPLAY MODES //
///////////////////
/*########################
*** DISPLAY MODE GUIDE ***
  0-2: SPRITE/TILE BASED
  3-5: BITMAP      BASED
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
#define CLR_TEAL   ((CLR_GREEN) | (CLR_BLUE))
#define CLR_WHITE  ((CLR_RED) | (CLR_GREEN) | (CLR_BLUE))
// COLOR MAKER
INLINE COLOR MAKE_COLOR(u32 redAmt, u32 greenAmt, u32 blueAmt)
{ return  (blueAmt << 10) | (greenAmt << 5) | redAmt; }


//////////////////////////////////
// OBJECT ATTRIBUTE DEFINITIONS //
//////////////////////////////////
/*#############################

******************************
*** OBJECT ATTRIBUTE GUIDE ***
******************************

TILES:
~ DEFINITION: '8x8 pixel bitmap'
~ TYPES:
   S-TILE: (4 bits per pixel) (16 colors/16 Palettes)
     32 BYTES LONG (0x20h)
   D-TILE: (8 bits per pixel) (256 colors/1 Palette)
     64 BYTES LONG (0x40h)

CHARBLOCK (TILE-BLOCKS):
~ DEFINITION: 'Where all of the tiles are stored' 0x4000h bytes long
~ SPECS
    ROOM FOR 512 TILES (16384 BYTES)
    MATRIX OF 32 X 16 S-TILES | 16 X 16/32 X 8 D-TILES
    6 TOTAL CHARBLOCKS FOR VRAM (96KB(98304) bytes)
      0-3 BACKGROUNDS
      4-5 SPRITES

#############################*/

//**integer = 4 bytes / 8 integers = 32 bytes**//
typedef struct  { u32 data[8]; } TILE;
typedef struct TILE8 { u32 data[16]; } TILE8;

typedef TILE CHARBLOCK[512];

/******************************
******* OAM DEFINITIONS *******
******************************/
//////////////////
// ORAM STRUCTS //
//////////////////
typedef struct OBJ_ATTR
{
    u16 attr0;
    u16 attr1;
    u16 attr2;
    s16 fill;
} ALIGN4 OBJ_ATTR;

typedef struct OBJ_AFFINE
{
    u16 fill0[3];
    s16 pa;
    u16 fill1[3];
    s16 pb;
    u16 fill2[3];
    s16 pc;
    u16 fill3[3];
    s16 pd;
} ALIGN4 OBJ_AFFINE;

////////////
//*ATTR 0*//
////////////
/*
xxxx xxxx xxxx xxxx
sscm ggoo yyyy yyyy
*/
// Normal Rendering
#define ATTR0_REG       0
// Y
#define ATTR0_Y_MASK 0x00FF
// OM
#define ATTR0_AFF       0x0100
#define ATTR0_HIDE      0x0200
#define ATTR0_AFF_DBL   0x0300
// GM
#define ATTR0_BLEND     0x0400
#define ATTR0_WINDOW    0x0800
// Mos
#define ATTR0_MOSAIC    0x1000
// CM
#define ATTR0_4BPP      0x0000
#define ATTR0_8BPP      0x2000
// Shape
#define ATTR0_SQUARE    0x0000
#define ATTR0_WIDE      0x4000
#define ATTR0_TALL      0x8000
////////////
//*ATTR 1*//
////////////
/*
xxxx xxxx xxxx xxxx
ssvh ---x xxxx xxxx
--AA AAA- ---- ----
*/
// X
#define ATTR1_X_MASK    0x01FF
// HF/VF
#define ATTR1_HFILP     0x1000
#define ATTR1_VFLIP     0x2000
// SZ
#define ATTR1_SIZE_8x8   0
#define ATTR1_SIZE_16x16 0x4000
#define ATTR1_SIZE_32x32 0x8000
#define ATTR1_SIZE_64x64 0xC000

#define ATTR1_SIZE_16x8  0
#define ATTR1_SIZE_32x8  0x4000
#define ATTR1_SIZE_32x16 0x8000
#define ATTR1_SIZE_64x32 0xC000

#define ATTR1_SIZE_8x16  0
#define ATTR1_SIZE_8x32  0x4000
#define ATTR1_SIZE_16x32 0x8000
#define ATTR1_SIZE_32x64 0xC000

// A-ID
#define ATTR1_AFF_ID_MASK   0x3E00
#define ATTR1_AFF_ID_SHIFT  9
#define ATTR1_AFF_ID(n)     ((n) << ATTR1_AFF_ID_SHIFT)

////////////
//*ATTR 2*//
////////////
/*
xxxx xxxx xxxx xxxx
BBBB PPTT TTTT TTTT
*/
// TID
#define ATTR2_ID_MASK 0x03FF
// Prioirity
#define ATTR2_PRIO_MASK     0x0C00
#define ATTR2_PRIO_SHIFT    10
#define ATTR2_PRIO(n)       ((n) << ATTR2_PRIO_SHIFT)
// Palette-bank
#define ATTR2_PALBANK_MASK  0xF000
#define ATTR2_PALBANK_SHIFT 12
#define ATTR2_PALBANK(n)    ((n) << ATTR2_PALBANK_SHIFT)

//////////////////////////
// USEFUL OAM FUNCTIONS //
//////////////////////////
#define BF_PREP(x, name)    ( ((x) << name##_SHIFT ) & name##_MASK )
#define BF_GET (x, name)    ( ((x) & name##_MASK) >> name##_SHIFT)
#define BF_SET (x, y, name) (y = ((y) & ~name##_MASK ) | BF_PREP(x, name))

///////////////////////
// PAL MEMORY ARRAYS //
///////////////////////
#define pal_mem ((u16*)PAL_RAM)
#define obj_pal_mem ((u16*)(PAL_RAM+OBJ_PAL))
#define oam_mem ((OBJ_ATTR*)MEM_OAM)
//define oam_mem ((u16*)MEM_OAM)
/////////////////////////
// VIDEO MEMORY ARRAYS //
/////////////////////////
#define vid_mem ((u16*)MEM_VRAM)
#define tile_mem ((CHARBLOCK*)MEM_VRAM)
/////////////
// V-SYNC //
////////////
#define VCOUNT (MEM_IO + MEM_IO_VCOUNT)
#define vcount_num *(volatile u16*)(VCOUNT)
INLINE void vsync(){
    while(vcount_num >= 160);
    while(vcount_num < 160);
}
//static void vsync();

////////////////////
// KEYPAD SECTION //
////////////////////

//#define REG_KEYINPUT *(volatile u16*)(MEM_IO + 0x0130)

/*
---- --xx xxxx xxxx
0    3    F    F
*/
/*
extern  u16 __key_curr, __key_prev;
u16 __key_curr = 0;
u16 __key_prev = 0;
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
    __key_prev = __key_curr;
    __key_curr = (~(REG_KEYINPUT)) & (KEY_MASK);
}

INLINE u32 key_curr_press   (u32 key) { return  __key_curr & key; }
INLINE u32 key_curr_lift    (u32 key) { return ~__key_curr & key; }
INLINE u32 key_prev_press   (u32 key) { return  __key_prev & key; }
INLINE u32 key_prev_lift    (u32 key) { return ~__key_prev & key; }

#endif
*/
#endif
