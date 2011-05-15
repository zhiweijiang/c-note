#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/user.h>
#include "fbtools.h"
#define TURE 1
#define FALSE 0
#define MAX(x,y)  ((x)>(y)? x:y)
#define MIN(x,y)  ((x)<(y)? x:y)


int fb_open(PFBDEV pFbdev)
{
    pFbdev->fb = open(pFbdev->dev, O_RDWR);
    if(pFbdev->fb < 0)
    {
        perror("pFbdev->dev");
        return FALSE;
    }
    if(-1 == ioctl(pFbdev->fb, FBIOPUT_VSCREENINFO, &(pFbdev->fb_var)))
    {
        perror("ioctl FBIOGET_VSCREENINFO");
        return FALSE;
    }
    if(-1 == ioctl(pFbdev->fb, FBIOGET_FSCREENINFO, &(pFbdev->fb_fix)))
    {
        perror("ioctl FBIOGET_FSCREENINFO");
        return FALSE;
    }
    pFbdev->fb_mem_offset = (unsigned long)(pFbdev->fb_fix.smem_start) &(~PAGE_MASK);
    pFbdev->fb_mem = (unsigned long int)mmap(NULL, pFbdev->fb_fix.smem_len + pFbdev->fb_mem_offset, PROT_READ | PROT_WRITE, MAP_SHARED, pFbdev->fb, 0);
    if(-1L == (long) pFbdev->fb_mem)
    {
        perror("mmap");
        return FALSE;
    }

    return TURE;
}

int fb_close(PFBDEV pFbdev)
{
    close(pFbdev->fb);
    pFbdev->fb = -1;
}

int get_display_depth(PFBDEV pFbdev)
{
    if(pFbdev <= 0)
    {
        perror("fb device");
        return FALSE;
    }
    return pFbdev->fb_var.bits_per_pixel;
}

void fb_memset(void *addr, int c, size_t len)
{
    memset(addr, c, len);
}

#define DEBUG
#ifdef DEBUG

int main(int argc, const char *argv[])
{
    FBDEV fbdev;

    memset(&fbdev, 0, sizeof(FBDEV));
    strcpy(fbdev.dev, "/dev/fb0");
    if(fb_open(&fbdev) == FALSE) {
        perror("fb_open");
        return 0;
    }
    fb_close(&fbdev);

    return 0;
}

#endif
