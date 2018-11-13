# Write this Makefile

myassm : main.o trans.o check.o
	gcc -o myassm main.o trans.o check.o 
main.o : main.c
	gcc -O -Wall -c main.c

trans.o : trans.c 
	gcc -O -Wall -c trans.c

check.o : check.c  
	gcc -O -Wall -c check.c

clean : 
	rm -f main.o trans.o check.o myassm
