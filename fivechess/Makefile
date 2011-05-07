CFLAG = -Wall -c -fPIC
LDFLAG =-shared
src = $(wildcard *.c)
obj = $(patsubst %.c, %.o, $(src))
CC = gcc    
target = libfive.so
all:$(obj)
		$(CC) $(obj) $(LDFLAG) -o $(target)
%.o:%.c
		$(CC) $(CFLAG) -o $@ $<

.PHONY:clean
clean:
		rm -f *.o
		rm -f $(target)

