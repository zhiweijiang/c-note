#include <unistd.h>
#include <stdio.h>
#include "main.h"

int main(int argc, const char *argv[])
{   
    int i = 0;
    init_screen();
    print_board();
   // fb_one_pixel(300,0,0x00ff0000);
   // fb_line(0,300, 800,500,0xffffff00);
   // fb_line(800,300,0,500,0x0ff00000);
    for (i = 0; i < 2; i++) 
    {
        fb_circle(400+i*SPACE, 280, 13, 0xffffff);
        fb_circle(400, 250+2*i*SPACE, 13, 0x00ff0000);   
    }
   // fb_line(300,700,500,0, 0xfffffff0);
   // fb_line(300,0,500,700,0xffffff00);
    save_gb(521, 433);
    draw_cursor(521, 433);
    sleep(2);
    restore(521, 433);
    draw_cursor(403, 403);
    mouse_doing();
    return 0;
}
