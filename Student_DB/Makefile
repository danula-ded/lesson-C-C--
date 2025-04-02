CC = gcc
CFLAGS = -Wall
TARGET = program
OBJ = main.o database.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c database.h
	$(CC) $(CFLAGS) -c main.c

database.o: database.c database.h
	$(CC) $(CFLAGS) -c database.c

clean:
	rm -f $(OBJ) $(TARGET)