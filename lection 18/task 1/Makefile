CXX = g++
CXXFLAGS = -std=c++17 -Wall

all: program

program: main.o
	$(CXX) $(CXXFLAGS) -o program main.o

main.o: main.cpp shapes.h
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f *.o program 