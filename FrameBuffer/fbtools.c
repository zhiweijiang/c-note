#include <stdio.h>
#include <math.h>
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

int fb_one_pixel(PFBDEV pFbdev, int x, int y, u32_t color)
{
    int i;
    u32_t *p = (u32_t *)pFbdev->fb_mem;
    
    i = x + y*pFbdev->fb_var.xres;

    p[i] = color;

    return 0;
}


int swap(int *a, int *b)
{
    int tmp;

    *a = tmp;
    *a = *b;
    *b = tmp;

    return 0;
}

int fb_line(PFBDEV pFbdev, int x1, int y1, int x2, int y2, u32_t color)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int p = 0;
    int inc;

    inc = ((dx*dy)>0)? 1:-1;
    if(abs(dx) > abs(dy))
    {
    if(dx<0)
        {
            swap(&x1, &x2);
            swap(&y1, &y2);
            dx = -dx;
            dy = -dy;
        }
        dy = (dy>0)? dy:-dy;
        p = 2*dy - dx;
    while(x1 <= x2)
    {   
        fb_one_pixel(pFbdev, x1, y1, color);
        if(p > 0)
        {
            y1 += inc;
            p += 2*(dy-dx);
        }
        else
        {
            p += 2*dy;    
        }
        x1++;
    }
    }
    else
    {
    if(dy<0)
        {
            swap(&x1, &x2);
            swap(&y1, &y2);
            dx = -dx;
            dy = -dy;
        }
        dx = (dx>0)? dx:-dx;
        p = 2*dx - dy;
    while(y1 <= y2)
    {   
        fb_one_pixel(pFbdev, x1, y1, color);
        if(p > 0)
        {
            x1 += inc;
            p += 2*(dx-dy);
        }
        else
        {
            p += 2*dx;    
        }
        y1++;
    }
    }
    return 0;
}

int fb_cirle(PFBDEV pFbdev, int x0, int y0, int r, u32_t color)
{
    int x = 0;
    int y = r;
    int p = 3 - 2*r;

    while(y >= x)
    {
        fb_one_pixel(pFbdev, x0+x, y0+y, color);
        fb_one_pixel(pFbdev, x0+y, y0+x, color);
        fb_one_pixel(pFbdev, x0-x, y0+y, color);
        fb_one_pixel(pFbdev, x0-y, y0+x, color);
        fb_one_pixel(pFbdev, x0+x, y0-y, color);
        fb_one_pixel(pFbdev, x0+y, y0-x, color);
        fb_one_pixel(pFbdev, x0-x, y0-y, color);
        fb_one_pixel(pFbdev, x0-y, y0-x, color);
       
        if(p >= 0)
        {   
            p += (4*(x-y) + 10); 
            y -= 1;
        }
        else
        {
            p += (4*x + 6);
        }
        x++;
    }

    return 0;
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
    
    fb_memset((void *)(fbdev.fb_mem + fbdev.fb_mem_offset), 0, fbdev.fb_fix.smem_len);
    fb_one_pixel(&fbdev, 200, 200, 0xff00000);
    fb_line(&fbdev, 100,50,180,400, 0x00ff00);
    fb_cirle(&fbdev, 200,200,50, 0x0fff0);
    fb_close(&fbdev);

    return 0;
}

#endif
