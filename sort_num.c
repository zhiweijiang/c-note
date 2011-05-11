#include <stdio.h>
#include <string.h>

void adjust_num(int a[], int n);

int main(int argc, const char *argv[])
{
    int num[10];
    int i;

    puts("Please input 10 number:");
    for (i = 0; i < 10; i++) 
    {
        scanf("%d", &num[i]);
    }
    printf("The number:\n");
    for (i = 0; i < 10; i++) 
    {
        printf("%d ", num[i]);
    }
    printf("\n");
    puts("The adjust number:");
    adjust_num(num, 10);
    for (i = 0; i < 10; i++) 
    {
       printf("%d ", num[i]);
    }
    printf("\n");

    return 0;
}


void adjust_num(int a[], int n)
{
    int i=0,j=n-1;
    int temp;

  while(i<j)
  {
    while(a[i]%2 !=0) i++;
    while(a[j]%2 ==0) j--;
    if(i<j)
    {
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
    i++;
    j--;
    }
  }
}
