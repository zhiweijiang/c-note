#include <stdio.h>

int main(int argc, const char *argv[])
{
    char a[10] ={0,1,2,3,4,5,6,7,8,9};
   
   union node
   {
   int i;
   char c[3];
   }b;
   b.i = 0x010230;
   printf("%d\n",b.c[0]);
   printf("%p\n",&b.i);
   printf("%p\n",&b.c[0]);
   printf("%p\n",&b.c[1]);
    int  *p = (int *) (a+2);
    int  i = *p;
    printf("%x\n", i);
    return 0;
}
