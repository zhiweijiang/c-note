#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10 

int binary_num(int num);
void init_num(int a[], int n);
void sort_num(int a[], int n);

struct num 
{
  int num;
  int b_num;
};

typedef struct num NUM;

int main(int argc, const char *argv[])
{
    int num[N];
    int i;

    init_num(num, N);
    printf("init num:\n");
    for (i = 0; i < N; i++)
    {
      printf("%5d",  num[i]);
    }
    printf("\n");
    sort_num(num, N);
    printf("After sort:\n");
    for (i = 0; i < N; i++) 
    {
        printf("%5d", num[i]);
    }
    printf("\n");
    return 0;
}


int binary_num(int num)
{
    unsigned int mask = 0x01;
    int i = 0;
    int j = 0;

    for (i = 0; i < sizeof(int)*8; i++) 
    {
       j +=((num&mask)!= 0? 1: 0);
       mask <<= 1;
    }
    return j;
}


void sort_num(int a[], int n)
{
    int i, j;
    int k, tmp = 0;
    NUM num[n];
    
    for (i = 0; i < n; i++) 
    {
        num[i].num = a[i];
    }
    for (i = 0; i < n; i++) 
    {
        num[i].b_num=binary_num(a[i]);
    }
    for (i = 0; i < n-1; i++) 
    {   
        k = i;
        for (j = i+1; j < n; j++) 
        {       
            
            if((num[j].b_num<num[k].b_num) || ((num[j].b_num == num[k].b_num)&&num[j].num<num[k].num))
            {
            k = j;
            }
        }
        if(k != i)
        {
        tmp = num[k].num;
        num[k].num = num[i].num;
        num[i].num =tmp;
        }
    }
    for (i = 0; i < n; i++) 
    {
        a[i] = num[i].num;
    }
}

void init_num(int a[], int n)
{   
    int i;

    srand(time(NULL));
    for (i = 0; i < n; i++) 
    {
        a[i] = rand()%(8*n)-4*n;
    }
}
