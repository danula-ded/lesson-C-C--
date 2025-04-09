CC = gcc
LIB = libmath.so

all: $(LIB) main

$(LIB): math_functions.o
	$(CC) -shared -o $(LIB) math_functions.o

math_functions.o: math_functions.c math_functions.h
	$(CC) -c math_functions.c

main: main.o libmath.dll.a
	$(CC) -o main main.o -L. -lmath

main.o: main.c math_functions.h
	$(CC) -c main.c

run: main
	LD_LIBRARY_PATH=. ./main

clean:
	rm -f *.o *.so main
