CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = fio_printer
OBJ = main.o functions.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c functions.h
	$(CC) $(CFLAGS) -c main.c

functions.o: functions.c functions.h
	$(CC) $(CFLAGS) -c functions.c

clean:
	rm -f $(OBJ) $(TARGET)