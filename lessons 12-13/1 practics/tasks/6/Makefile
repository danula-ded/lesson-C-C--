CC = gcc
CFLAGS = -Wall

OBJS = main.o string_utils.o file_utils.o

all: main

main: $(OBJS)
	$(CC) -o main $(OBJS)

main.o: main.c string_utils.h file_utils.h
string_utils.o: string_utils.c string_utils.h
file_utils.o: file_utils.c file_utils.h

clean:
	del *.o main.exe
