CC = gcc
AR = ar
FLAGS = -Wall -g

all: connections

connections: connections.o my_mat.a
	$(CC) $(FLAGS) -o connections connections.o my_mat.a
my_mat.a: my_mat.o
	$(AR) -rcs my_mat.a my_mat.o
connections.o: connections.c my_mat.h
	$(CC) $(FLAGS) -c connections.c
my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c my_mat.c

.PHONY: all clean
clean: 
	rm -f *.o *.a *.gch connections
	
