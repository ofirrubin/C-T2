CC = gcc
AR = ar
FLAGS = -Wall -g

all: main

main: main.o my_mat.a
	$(CC) $(FLAGS) -o main main.o my_mat.a
my_mat.a: my_mat.o
	$(AR) -rcs my_mat.a my_mat.o
main.o: main.c my_mat.h
	$(CC) $(FLAGS) -c main.c
my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c my_mat.c

.PHONY: all clean
clean: 
	rm -f *.o *.a *.gch main
	
