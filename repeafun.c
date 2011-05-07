#include <stdio.h>

typedef void (*callback_t) (void *);
void repeat(callback_t, void *);
void say_hello(void *);
void count_numbers(void *);

void repeat(callback_t f, void *para)
{
    f(para);
}

int main(int argc, const char *argv[])
{
    repeat(say_hello, "Guys");
    repeat(count_numbers, (void *) 4);
    return 0;
}

void say_hello(void *str)
{
    printf("Hello %s\n", (const char *)str);
}

void count_numbers(void * num)
{
    int i;
    for (i = 0; i < (int) num; i++) 
    {
        printf("%d",i);
    }
    printf("\n");
}
