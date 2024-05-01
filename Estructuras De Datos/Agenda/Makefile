a.out: main.o agenda.o
	gcc main.o agenda.o
main.o: main.c
	gcc -c main.c
agenda.o: agenda.c
	gcc -c agenda.c
run: a.out
	./a.out
clear:
	rm a.out main.o agenda.o
