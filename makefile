#modify this makefile so that it will work for this new assignment
CC=g++

all: main

main: main.o 
	$(CC) -o main main.o

main.o: main.cpp
	$(CC) -c main.cpp

clean: 
	rm -f main *.o *.out
