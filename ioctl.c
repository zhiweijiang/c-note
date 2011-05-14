#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/fb.h>
#include <sys/ioctl.h>

int main(int argc, const char *argv[])
{
    int fp;
    struct fb_var_screeninfo fb_var;

    fp = open("/dev/fb0", O_RDWR);
    if(fp < 0)
    {
        perror("fb");
        exit(0);
    }
    ioctl(fp, FBIOGET_VSCREENINFO, &fb_var);
    printf("width:%d\t length: %d\t bpp: %d\n ", fb_var.xres, fb_var.yres, fb_var.bits_per_pixel);
    
    close(fp);

    return 0;
}
