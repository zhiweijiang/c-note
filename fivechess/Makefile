CFLAG = -Wall -c -fPIC
LDFLAG =-shared
src = $(wildcard *.c)
obj = $(patsubst %.c, %.o, $(src))
CC = gcc    
target = libfive.so
all:$(target) main.c
		$(CC) main.c $(target) -o main
$(target):$(obj)
		$(CC) $(obj) $(LDFLAG) -o $(target)
%.o:%.c
		$(CC) $(CFLAG) -o $@ $<
run:
		./main
.PHONY:clean
clean:
		rm -f *.o
		rm -f $(target)
		rm main
