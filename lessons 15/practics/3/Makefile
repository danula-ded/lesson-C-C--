CXX = g++
CXXFLAGS = -std=c++17 -Wall

all: rectangle

rectangle: main.o rectangle.o
	$(CXX) $(CXXFLAGS) -o rectangle main.o rectangle.o

main.o: main.cpp rectangle.h
	$(CXX) $(CXXFLAGS) -c main.cpp

rectangle.o: rectangle.cpp rectangle.h
	$(CXX) $(CXXFLAGS) -c rectangle.cpp

clean:
	rm -f *.o rectangle 