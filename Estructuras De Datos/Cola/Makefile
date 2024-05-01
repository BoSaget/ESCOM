a.out: main.o queue.o
		gcc main.o queue.o
main.o: main.c
		gcc -c main.c
queue.o: queue.c
		gcc -c queue.c
run: a.out
		./a.out
clear:
		rm a.out main.o queue.o
