CC = gcc
OBJ = main.o  utils.o

all: main

main: $(OBJ)
	$(CC) -o main $(OBJ)

main.o: main.c utils.h
utils.o: utils.c utils.h

clean:
	rm -f *.o main
