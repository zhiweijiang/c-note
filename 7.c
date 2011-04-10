#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
#define M 10


void init_array(int p[][M]);
void print_array(int p[][M]);
void sort_array(int p[][M]);
int main(int argc, const char *argv[])
{
    
    int array[N][M];
    init_array(array );
    puts("The init:");
    print_array(array);
    sort_array(array);
    puts("The sort:");
    print_array(array);

    return 0;
}



void init_array(int p[][M])     
{
    int i = 0;
    
    srand(time(NULL));

    for (i = 0; i < M*N; i++) 
    {
        p[0][i] = (rand()%(2*M*N));
    }
}


void print_array(int p[][M])
{
    int i = 0;
     
    for (i = 0; i < M*N; i++) 
    {
        if((i % 10)== 0)
        {
            printf("\n");
        }
            printf("%5d",p[0][i]); 
    }
    printf("\n");
}


void sort_array(int p[][M])
{
    int i = 0;
    int j = 0;
    int temp = 0;
    for (i = 0; i < M*N; i++) 
    {
        for (j= i+1; j<M*N;j++) 
        {
            if (p[0][i] < p[0][j])
            {
            temp = p[0][i];
            p[0][i] = p[0][j];
            p[0][j] =temp;
            }
        }
    }
}

