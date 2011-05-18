#ifndef _FBTOOLS_H_
#define _FBTOOLS_H_
#include <linux/fb.h>

typedef struct fbdev
{
    int fb;
    unsigned long fb_mem_offset;
    unsigned long fb_mem;
    struct fb_fix_screeninfo fb_fix;
    struct fb_var_screeninfo fb_var;
    char dev[20];
}FBDEV, *PFBDEV;

typedef unsigned int  u32_t;

int fb_open(PFBDEV pFbdev);

int fb_close(PFBDEV pFbdev);

int get_display_depth(PFBDEV pFbdev);

int fb_one_pixel(PFBDEV pFbdev, int x, int y, u32_t color);

int fb_line(PFBDEV pFbdev, int x1, int y1, int x2, int y2, u32_t color);

int fb_cirle(PFBDEV pFbdev, int x0, int y0, int r, u32_t color);

void fb_memset(void *addr, int c, size_t lenj);

#endif
