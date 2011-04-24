#include <stdio.h>
#include "main.h"

extern int porrorx;
extern int porrory;
extern int mx;
extern int my;
extern fbsrc_t fb_v;
u32_t cirbg_save[28*28] ={0};
char flag = 0;

int save_cirbg(int x, int y)
{
    int i = 0;
    int j = 0;

    for (j = 0; j < 28; j++) 
    {
        for (i = 0; i < 28; i++) 
        {
            cirbg_save[i+j*28] = *((u32_t *)fb_v.memo+x-14+i+(y+j-14)*fb_v.w);
        }
    }

    return 0;
}


int  chess_do(void)
{
    int x = mx;
    int y = my;
    
    if(flag == 0)
    {
        print_board();
        flag = 0xff;
        return 0;
    }
    if((x < ST_X) ||(x > ST_X + SPACE*(B_X -1)))
    {
        return 0;
    }
    if((y < ST_Y) ||(y > ST_Y + SPACE*(B_Y -1)))
    {
        return 0;
    }
    x = (x-ST_X)%SPACE;
    y = (y-ST_Y)%SPACE;
    if(x < SPACE/2)
    {
        x = mx -x;
    }
    else
    {
        x = mx -x +SPACE;
    }
    if(y < SPACE/2)
    {
        y = my - y;
    }
    else
    {
        y = my -y +SPACE;
    }
    porrorx = x;
    porrory = y;
    save_cirbg(x, y);
    fb_circle(x, y, 13, 0x00ff0000);
    return 0;
}
