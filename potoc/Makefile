CC=gcc
CFLAGS=-pthread
all: my_program
my_program: my_program.o
	$(CC) -o my_program my_program.o $(CFLAGS)
my_program.o: my_program.c
	$(CC) -c my_program.c $(CFLAGS)
clean:
	rm -f my_program my_program.o