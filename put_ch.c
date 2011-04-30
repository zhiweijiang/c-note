#include <stdio.h>
#include <string.h>


void put_ch(char *str);

int main(int argc, const char *argv[])
{
    char str[] = "abdcdfjienga";

    put_ch(str);
    return 0;
}

void put_ch(char *str)
{
    int i = 0, j = 0;
    int flag = 0;

    while(i < strlen(str))
    {
        for (j = i; j < strlen(str)-1; j++) 
        {
            if(str[j+1] == str[i])
            {
                flag = 1;
                break;
            }
            else 
             flag = 0;
        }
        if(0 == flag)
        {
            printf("%c\n", str[i]);
            break;
        }
        i ++;
    }
}
