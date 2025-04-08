CC = gcc
CFLAGS = -Wall
TARGET = program
OBJ = main.o math_functions.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c math_functions.h
	$(CC) $(CFLAGS) -c main.c

math_functions.o: math_functions.c math_functions.h
	$(CC) $(CFLAGS) -c math_functions.c

clean:
	rm -f $(OBJ) $(TARGET)