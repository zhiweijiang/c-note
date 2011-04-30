#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10 

int b_num(int num);
void init_num(int a[], int n);
void sort_num(int a[], int n);

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


int b_num(int num)
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
    
    for (i = 0; i < n-1; i++) 
    {   
        k = i;
        for (j = i+1; j < n; j++) 
        {       
            
            if((b_num(a[j])<b_num(a[k])) || ((b_num(a[j])==b_num(a[k]))&&a[j]<a[k]))
            {
            k = j;
            }
        }
        if(k != i)
        {
        tmp = a[k];
        a[k] = a[i];
        a[i] =tmp;
        }
    }
}

void init_num(int a[], int n)
{   
    int i;

    srand(time(NULL));
    for (i = 0; i < n; i++) 
    {
        a[i] = rand()%(4*n);
    }
}
