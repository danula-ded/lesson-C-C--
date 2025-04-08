CC = gcc
CFLAGS = -Wall
TARGET = program
OBJ = main.o game.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c game.h
	$(CC) $(CFLAGS) -c main.c

game.o: game.c game.h
	$(CC) $(CFLAGS) -c game.c

clean:
	rm -f $(OBJ) $(TARGET)