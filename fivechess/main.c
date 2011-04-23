#include <stdio.h>
#include "main.h"

int print_board(void)
{
    int i = 0;

    for (i = 0; i < B_Y; i++) 
    {
        fb_line(ST_X, ST_Y + i*SPACE, ST_X +(B_X -1)*SPACE, ST_Y+i*SPACE, 0xffffffff);
    }
    for (i = 0; i < B_X; i++) 
    {           
        fb_line(ST_X+i*SPACE, ST_Y, ST_X +i*SPACE, ST_Y+(B_Y-1)*SPACE, 0xffffffff);
    }
    
    return 0;
}

int main(int argc, const char *argv[])
{   
    init_screen();
   // fb_one_pixel(300,0,0x00ff0000);
   // fb_line(0,300, 800,500,0xffffff00);
   // fb_line(800,300,0,500,0x0ff00000);
   // fb_circle(200, 200, 150, 0x0ff00000); 
   // fb_line(300,700,500,0, 0xfffffff0);
   // fb_line(300,0,500,700,0xffffff00);
    print_board();
   return 0;
}
