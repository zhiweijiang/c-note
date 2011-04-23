#this is for link

scr = manage-system.c print_test.c
para =-o main -Wall
main:$(scr) 
		gcc $(scr) $(para)
clean:
		rm -rf *.o
		rm -rf main
		rm -rf ~*
