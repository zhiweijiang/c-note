#include <stdio.h>
#include "main.h"

int main(int argc, const char *argv[])
{
    init_screen();
    fb_one_pixel(200, 200, 0x00ff0000);    
    return 0;
}
