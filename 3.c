#include <stdio.h>

int main(int argc, const char *argv[])
{
    int i = 0;
    int j = 0;
    int temp;
    int k = 0;
    int a[10]={1,2,5,8,0,-1,12,43,21,10};
    puts("The init number:");
    for (i = 0; i < 10; i++) 
    {
        printf("%4d",a[i]);
    }
    for (i = 0; i < 9; i++) 
    {
        k = 9-i;
        for (j = 0; j < 9 - i;  j++ ) 
        {
            if(a[j]<a[k])
            {
             k = j;
            }
        }
        if(k!= 9 - i)
        {
          temp = a[9-i];
          a[9-i] = a[k];
          a[k] = temp; 
        }
    }
    printf("\nFrom to the sorting:\n");
        i = 0;
    while(i < 10)
    {
        printf("%4d",a[i]);   
        i ++;
    }
        printf("\n");
    return 0;
}
