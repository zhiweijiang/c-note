#ifndef _MAIN_H_
#define _MAIN_H_

typedef unsigned int u32_t;
typedef unsigned char u8_t;

typedef struct
{
    int w;
    int h;
    int bbp;

    void  *memo;
}fbscr_t;

int init_screen(void);
int fb_one_pixel(int x, int y, u32_t color);
#endif
