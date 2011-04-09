#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

void init_aaray(int p[],int n);
void butte_aaray(int p[],int n);
void print_aaray(int p[],int n);


int main(int argc, const char *argv[])
{    
    int array[N];

   init_array(array,N);
   puts("The original:");
   print_array(array,N);
   butte_array(array,N);
   puts("The sorted:");
     print_array(array,N);
    printf("\n");
    return 0;
}

void init_array(int p[], int n)     
{
    int i = 0;
    
    srand(time(NULL));

    for (i = 0; i < n; i++) 
    {
        p[i] = (rand()%200);
    }
}


void print_array(int p[], int n)
{
    int i = 0;
     
    for (i = 0; i < n; i++) 
    {
        if((i % 10)== 0)
        {
            printf("\n");
        }
            printf("%4d",p[i]); 
    }
    printf("\n");
}


void butte_array(int p[], int n)
{
    int i = 0;
    int j = 0;
    int temp = 0;
    for (i = 0; i < n; i++) 
    {
        for (j= i+1; j<n;j++) 
        {
            if (p[i] < p[j])
            {
            temp = p[i];
            p[i] = p[j];
            p[j] =temp;
            }
        }
    }
}
