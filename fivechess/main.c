#include <stdio.h>
#include <unistd.h>
#include "main.h"

int main(int argc, const char *argv[])
{
    init_screen();
    //fb_one_pixel(400, 100, 0x00ffff00);
    //fb_line(300, 300, 100, 100, 0x0077ff00);
    //fb_line(0, 600, 1000, 400, 0x0000ff77);
    //fb_line(300, 300, 400, 767, 0x0033ff22);
    //fb_line(300, 300, 200, 767, 0x0000ff22);
    //fb_line(400, 700, 0, 300, 0x0000ffaa);
    //fb_circle(600, 150, 100, 0x00aa00cc);
    fb_circle_s(500, 600, 150, 0x000ff000);

    //print_board(0x00ffffff);

    //int i;
    //for (i = 0; i < 1000; i++) 
    //{
        //save_bg(i, 600);
        //draw_cursor(i, 600);

        //usleep(10000);
        //restore(i, 600);
    //}
    //save_bg(500, 600);
    //draw_cursor(500, 600);

    //sleep(2);
    //restore(500, 600);
    //draw_cursor(530, 600);

    mouse_doing();

    return 0;
}
