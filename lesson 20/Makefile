CXX = g++

all: main

main: main.o shape.o circle.o square.o triangle.o
	$(CXX) $(CXXFLAGS) -o main main.o shape.o circle.o square.o triangle.o

main.o: main.cpp shape.h circle.h square.h triangle.h
	$(CXX) $(CXXFLAGS) -c main.cpp

shape.o: shape.cpp shape.h
	$(CXX) $(CXXFLAGS) -c shape.cpp

circle.o: circle.cpp circle.h
	$(CXX) $(CXXFLAGS) -c circle.cpp

square.o: square.cpp square.h
	$(CXX) $(CXXFLAGS) -c square.cpp

triangle.o: triangle.cpp triangle.h
	$(CXX) $(CXXFLAGS) -c triangle.cpp

clean:
	rm -f *.o main 