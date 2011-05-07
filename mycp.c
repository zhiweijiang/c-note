#include <stdio.h>
#include <stdlib.h>

int  mycp(char *scr, char *des);

int main(int argc, const char *argv[])
{
    int error;

    error= mycp(argv[1], argv[2]);
    if(error == -1)
    {
        perror("no crear new file");
        exit(0);
    }
    return 0;
}

int  mycp(char *scr, char *des)
{   
    FILE *fps = NULL;
    FILE *fpd = NULL;
    char buf[4096];
    int size;

    fps= fopen(scr, "rb+");
    if(!fps)
    {
        perror("fps");
        return -1;
    }
    fpd = fopen(des, "wb+");
    if(!fpd)
    {
        perror("fpd");
        return -1;
    }
    while(size = fread(buf, 1, 4096, fps))
    {   
        fwrite(buf, 1, size, fpd);
    }
    fclose(fps);
    fclose(fpd); 

    return 0;
    
}
