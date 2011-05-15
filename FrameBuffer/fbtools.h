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

int fb_open(PFBDEV pFbdev);

int fb_close(PFBDEV pFbdev);

int get_display_depth(PFBDEV pFbdev);

void fb_memset(void *addr, int c, size_t lenj);

#endif
