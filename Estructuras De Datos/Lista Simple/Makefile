a.out: main.o simple.o
		gcc main.o simple.o
main.o: main.c
		gcc -c main.c
simple.o: simple.c
		gcc -c simple.c
run: a.out
		./a.out
clear:
		rm a.out main.o simple.o