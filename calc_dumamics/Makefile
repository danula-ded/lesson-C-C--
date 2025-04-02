CC = gcc
CFLAGS = -Wall
PROGRAM = program.exe
DLL = math_functions.dll

all: $(DLL) $(PROGRAM)

$(DLL): math_functions.c math_functions.h
	$(CC) -shared -o $(DLL) math_functions.c

$(PROGRAM): main.c $(DLL)
	$(CC) $(CFLAGS) -o $(PROGRAM) main.c -L. -lmath_functions

clean:
	del $(PROGRAM) $(DLL)