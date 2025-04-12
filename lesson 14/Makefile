all: main

main: main.o book.o library.o
	g++ -o main main.o book.o library.o

main.o: main.cpp book.h library.h
	g++ -c main.cpp

book.o: book.cpp book.h
	g++ -c book.cpp

library.o: library.cpp library.h book.h
	g++ -c library.cpp

clean:
	rm -f *.o main