#include <stdio.h>
#define N 10


void init_array(int *p, int n);
void j_game( int *p, int n);

int main(int argc, const char *argv[])
{
    int array[N];
     
    init_array(array, N);
    j_game(array, N);
    return 0;
}


void init_array(int *p, int n)
{
    int i = 0;

    for (i = 0; i < n; i++) 
    {
        p[i] = 1;
    }
}


void j_game( int *p, int n)
{
    int i = 0;
    int interval = 2;
    int out_counter = 0;
    int out_total = 0;

    while(out_total < n)
    {
    
        if(p[i] ==1)
        {
               out_counter++;
          if (out_counter == interval) 
              {
                 out_counter =0;
                 p[i] = 0;
                 out_total ++;
                 printf("%5d(out)\n", i+1);
             }
             else
             {
             printf("%5d",i+1);
             }
          }
          i++;
          i=i%n;
    }   

}
