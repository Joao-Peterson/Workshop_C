
main : main.o imprime.o
	gcc main.o imprime.o -o main

main.o : main.c
	gcc -c main.c -o main.o

imprime.o : imprime.c
	gcc -c imprime.c -o imprime.o
