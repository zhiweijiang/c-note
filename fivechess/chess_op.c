#include <stdio.h>
#include "main.h"

extern int porrorx;
extern int porrory;
extern int mx;
extern int my;
extern fbsrc_t fb_v;

u32_t cirbg_save[28*28] ={0};
char flag = 0;
u32_t current_color = 0;
char current_player = 0;
char chess_board[B_Y*B_X];

int check_one(int x, int y)
{
    int i = 0;
    int j = 0;
    int counter = 0;
    int who = 0;
    int m[4] = {1,0,1,1};
    int n[4] = {0,1,-1,1};
    int sx = x;
    int sy = y;
    
    who = chess_board[x+y*B_X];
    if(who == 0)
    {
        return 0;
    }
    for (j = 0; j < 4; j++) 
    {   
        x = sx;
        y = sy;
        counter = 1;
        for (i = 1; i < 5; i++) 
        {
            x += m[j];
            y += n[j];
            if(chess_board[x+y*B_X] == who)
            {
                counter ++;
            }
            else
            {
                break;
            }
        }
        if(counter == 5)
        {
            return who;
        }
    }
    return 0;
}

int check_win(void)
{
    int i = 0;
    int j = 0;
    int winner = 0;

    for (j = 0; j < B_Y; j++) 
    {
        for (i = 0; i < B_X; i++) 
        {
            winner = check_one(i, j);
            if(winner > 0)
            {
                return winner;
            }
        }
    }
    return 0;
}
int save_cirbg(int x, int y)
{
    int i = 0;
    int j = 0;

    for (j = 0; j < 28; j++) 
    {
        for (i = 0; i < 28; i++) 
        {
            cirbg_save[i+j*28] = *((u32_t *)fb_v.memo+x-14+i+(y+j-14)*fb_v.w);
        }
    }

    return 0;
}


int  chess_do(void)
{
    int x = mx;
    int y = my;
    
    int lx = 0;
    int ly = 0;
    int i= 0;
    
    int winner = 0;

    if(flag == 0)
    {
        print_board();
        flag = 0xff;
        return 0;
    }
    if((x < ST_X) ||(x > ST_X + SPACE*(B_X -1)))
    {
        if((x>40)&&(x<80)&&(y>80)&&(y<120))
        {
            current_color = BLACK;
            current_player = 1;
        }
     else if((x>40)&&(x<80)&&(y>180)&&(y<220))
        {
            current_color = WHITE;
            current_player = 2;
        } 
        return 0;
    }
    if((y < ST_Y) ||(y > ST_Y + SPACE*(B_Y -1)))
    {
        return 0;
    }
    x = (x-ST_X)%SPACE;
    y = (y-ST_Y)%SPACE;

    if(x < SPACE/2)
    {
        x = mx -x;
    }
    else
    {
        x = mx -x +SPACE;
    }
    if(y < SPACE/2)
    {
        y = my - y;
    }
    else
    {
        y = my -y +SPACE;
    }
    lx = (x-ST_X)/SPACE;
    ly = (y-ST_Y)/SPACE;
    
    chess_board[lx+ly*B_X] = current_player;
    
    porrorx = x;
    porrory = y;
    save_cirbg(x, y);
    fb_circle(x, y, 13, current_color);
   
    winner = check_win();
    if(winner >0)
    {
        if(winner == 1)
           {
           for (i = 0; i < 2; i++) 
            {    
              fb_line(26+i,502,30+i,500,0x00ff0000);
              fb_line(30+i,500,30+i,530,0x00ff0000);
              fb_line(26,530-i,34,530-i,0x00ff0000);
            }
           }
        else
        {
        for (i = 0; i < 2; i++) 
        {
        fb_circle_s(25,505+i,5,0x00ff0000);
        fb_line(20+i,530,30+i,505,0x00ff0000);
        fb_line(20,530-i,30,530-i,0x00ff0000);
        }
        }
        for (i = 0; i < 2; i++) 
        {
        fb_line(40+i,500,45+i,530,0x00ff0000);
        fb_line(45+i,530,50+i,500,0x00ff0000);
        fb_line(50+i,500,55+i,530,0x00ff0000);
        fb_line(55+i,530,60+i,500,0x00ff0000);
        fb_circle(68,503,2,0x00ff0000);
        fb_line(67+i,508,67+i,530,0x00ff0000);
        fb_line(74+i,510,74+i,530,0x00ff0000);
        fb_line(94-i,510,94-i,530,0x00ff0000);
        fb_circle_s(84,510+i,10,0x00ff0000);
        }
        

        return winner;
    }
   
   return 0;
}
