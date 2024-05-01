a.out: main.o doble.o
		gcc main.o doble.o
main.o: main.c
		gcc -c main.c
doble.o: doble.c
		gcc -c doble.c
run: a.out
		./a.out
clear:
		rm a.out main.o doble.o