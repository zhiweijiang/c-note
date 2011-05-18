#include "common.h"

typedef struct
{
    int dx; 
    int dy;
    int dz;
    int button;
}mevent_t;

static u32_t save_cursor[C_WIDTH*C_HIGHT];


extern int mouse_open(const char *mdev);
extern int mouse_parse(int fd, mevent_t * mevent);

extern int mouse_draw(const pinfo_t fb, int x, int y);
extern int mouse_restore(const pinfo_t fb, int x, int y);

extern int mouse_test(pinfo_t fb);


int init_fb(pinfo_t fb);
int fb_pixel(pinfo_t fb, int x, int y, u32_t color);

static u32_t cursor_pixel[C_WIDTH * C_HIGHT] = 
{
    BORD,T___,T___,T___,T___,T___,T___,T___,T___,T___,
    BORD,BORD,T___,T___,T___,T___,T___,T___,T___,T___,  
    BORD,X___,BORD,T___,T___,T___,T___,T___,T___,T___,
    BORD,X___,X___,BORD,T___,T___,T___,T___,T___,T___,
    BORD,X___,X___,X___,BORD,T___,T___,T___,T___,T___,
    BORD,X___,X___,X___,X___,BORD,T___,T___,T___,T___,
    BORD,X___,X___,X___,X___,X___,BORD,T___,T___,T___,
    BORD,X___,X___,X___,X___,X___,X___,BORD,T___,T___,
    BORD,X___,X___,X___,X___,X___,X___,X___,BORD,T___,
    BORD,X___,X___,X___,X___,X___,X___,X___,X___,BORD,
    BORD,X___,X___,X___,X___,X___,BORD,BORD,BORD,BORD,
    BORD,X___,X___,BORD,X___,X___,BORD,T___,T___,T___,
    BORD,X___,BORD,T___,BORD,X___,X___,BORD,T___,T___,
    BORD,BORD,T___,T___,BORD,X___,X___,BORD,T___,T___,
    T___,T___,T___,T___,T___,BORD,X___,X___,BORD,T___,
    T___,T___,T___,T___,T___,BORD,X___,X___,BORD,T___,
    T___,T___,T___,T___,T___,T___,BORD,BORD,T___,T___
};


int init_fb(pinfo_t fb)
{
    int fd;

    if((fd = open("/dev/fb0", O_RDWR)) < 0)
    {
        perror("fb0");
        return -1;
    }

    struct fb_var_screeninfo fb_var;

    if((ioctl(fd, FBIOGET_VSCREENINFO, &fb_var) < 0))
    {
        perror("ioctl");
        return -1;
    }
    fb->w = fb_var.xres;
    fb->h = fb_var.yres;
    fb->bpp = fb_var.bits_per_pixel;
    printf("w:%d\th:%d\tbpp:%d\n", fb->w, fb->h, fb->bpp);

    fb->fbmem = mmap(NULL, ((fb->w)*(fb->h)*(fb->bpp)/8), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if(fb->fbmem == MAP_FAILED)
    {
        perror("mmap");
        return -1;
    }

    close(fd);
    memset(fb->fbmem, 0, (fb->w)*(fb->h)*(fb->bpp)/8);
    return 0;
}

int fb_pixel(pinfo_t fb, int x, int y, u32_t color)
{
    u32_t *p;

    p = (u32_t *) ((char *)fb->fbmem +((fb->w*y+x)*fb->bpp)/8);
    *p = color;

    return 0;
}

int fb_cirle(pinfo_t fb, int x0, int y0, int r, u32_t color)
{
    int x = 0;
    int y = r;
    int p = 3 - 2*r;
    
    while(y >= x)
    {
        fb_pixel(fb, x0+x, y0+y, color);
        fb_pixel(fb, x0+y, y0+x, color);
        fb_pixel(fb, x0-x, y0+y, color); 
        fb_pixel(fb, x0+x, y0-y, color);
        fb_pixel(fb, x0-y, y0+x, color);
        fb_pixel(fb, x0-x, y0-y, color);
        fb_pixel(fb, x0+y, y0-x, color);
        fb_pixel(fb, x0-y, y0-x, color);
        if(p >= 0)
        {
            y --;
            p += (4*(x-y) + 10); 
        }
        else
        {
            p += (4*x + 6);
        }
        x++;
    }
    
    return 0;
}


int mouse_test(pinfo_t fb)
{
    int fd;
    mevent_t mevent;
    int m_x = fb->w/2;
    int m_y = fb->h/2;
    int i,j;
    int flag = 0;

    if((fd = mouse_open("/dev/input/mice")) < 0)
    {
        perror("open");
        exit(1);
    }
    mouse_draw(fb, m_x, m_y);

    u8_t buf[] = {0xf3,0xc8,0xf3,0x64,0xf3,0x50};

    if(write(fd, buf, sizeof(buf)) < sizeof(buf))
    {
        perror("write");
        fprintf(stderr, "鼠标将不知支持滚轮\n");
    }

    while(1)
    {
        if(mouse_parse(fd, &mevent) == 0)
        {
  //        printf("dx = %d\tdy = %d\tdz = %d\t", mevent.dx, mevent.dy, mevent.dz);
            
            mouse_restore(fb, m_x, m_y);
            m_x += mevent.dx;
            m_y += mevent.dy;
            m_x=((m_x<0)? 0:m_x);
            m_y=((m_y<0)? 0:m_y);
            if(m_x > (fb->w - C_WIDTH))
            {
                m_x = fb->w -C_WIDTH;
            }
            if(m_y > (fb->h - C_HIGHT))
            {
                m_y = fb->h - C_HIGHT;
            }
  //        printf("mx = %d\tmy = %d\n", m_x, m_y);
            switch(mevent.button)
            {
                case 1:
                {
                    i = 50;
                    while(i > 25)
                    {
                        fb_cirle(fb, m_x, m_y, i, 0x0fff);
                        i--;
                    }
                    for (j = m_y -1; j < m_y+2; j++) 
                    {
                        for (i = m_x - 25; i < m_x + 25; i++) 
                        {
                            fb_pixel(fb, i, j, 0xff00);
                        }
                    } 
                    for (j = m_y -25; j < m_y+25; j++) 
                    {
                        for (i = m_x - 1; i < m_x + 2; i++) 
                        {
                            fb_pixel(fb, i, j, 0xff00);
                        }
                    }   
                    break;
                 }
                case 2:
                {   
                    for (j = m_y -50; j < m_y + 50; j++) 
                    {
                        for (i = (m_y-j-50)/2; i <= (50+j-m_y)/2; i++) 
                        {
                            fb_pixel(fb, m_x+i/2, j, 0xff000);
                        }
                    }
                    fb_cirle(fb, m_x, m_y, 250, 0x0fff); 
                    break;
                 }
                case 4:
                {
                    flag = 1;
                    for (j = m_y - 12; j < m_y + 12; j++) 
                    {
                        for (i = -75; i < 75; i++) 
                        {
                            fb_pixel(fb, m_x+i, j, 0x0ff);
                        }
                    }
                    break;
                }
                case 0:
                    if(1 == flag)
                        exit(0);
                    break;   
                default:
                    break;
            }
          mouse_draw(fb, m_x, m_y);
        }
            else
                ;
    }
    close(fd);
    return 0;
}


int mouse_open(const char *mdev)
{
      if(mdev == NULL)
          mdev = "/dev/input/mice";
      return(open(mdev, O_RDWR | O_NONBLOCK)); 
}
   
#define READ_MOUSE 8

int mouse_parse(int fd, mevent_t *mevent)
{
      char buf[READ_MOUSE];
      int n;
        
      if((n = read(fd, buf, READ_MOUSE)) > 0)
      {
          mevent->button = buf[0]&0x07;
          mevent->dx = buf[1];
          mevent->dy = -buf[2];
          mevent->dz = buf[3];
      }
      else
          return -1;
  
  return 0;
}


static int mouse_save(const pinfo_t fb, int x, int y)
{
    int i,j;

    for (j = 0; j < C_HIGHT; j++) 
    {
        for (i = 0; i < C_WIDTH; i++)
        {
            save_cursor[i+j*C_WIDTH] = *(u32_t *)(fb->fbmem+((x+i)+(y+j)*fb->w)*fb->bpp/8);
        }
    }
    
    return 0;
}

int mouse_draw(const pinfo_t fb, int x, int y)
{
    int i,j;

    mouse_save(fb, x, y);

    for (j = 0; j < C_HIGHT; j++) 
    {
        for (i = 0; i < C_WIDTH; i++) {
            if(cursor_pixel[i+j*C_WIDTH] != T___)
                fb_pixel(fb, x+i, y+j, cursor_pixel[i+j*C_WIDTH]);
        }
    }

    return 0;
}

int mouse_restore(const pinfo_t fb, int x, int y)
{
    int i, j;

    for (j = 0; j < C_HIGHT; j++) 
    {
        for (i = 0; i < C_WIDTH; i++)
        {
                fb_pixel(fb, x+i, y+j, save_cursor[i+j*C_WIDTH]);
        }
    }
    
    return 0;

}

int main(int argc, const char *argv[])
{   
    fb_info fb;

    if(init_fb(&fb) < 0)
    {
        perror("init_fb");
        exit(1);
    }
    mouse_test(&fb);
    return 0;
}
