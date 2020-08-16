#include "../tools/mem_util.h"


int main()
{

    REG_DISPCNT = DCNT_BG2 | DCNT_MODE3;

    obj_pal_mem[0] = CLR_PURPLE;
    pal_mem[0] = CLR_PURPLE;
    obj_pal_mem[1] = CLR_RED;
    pal_mem[1] = CLR_RED;
    obj_pal_mem[2] = CLR_GREEN;
    pal_mem[2] = MAKE_COLOR(0, 31, 31);
    while(1);

    return 0;
}
