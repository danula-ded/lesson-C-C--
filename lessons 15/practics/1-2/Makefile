CXX = g++
CXXFLAGS = -std=c++17 -Wall

all: student

student: main.o student.o
	$(CXX) $(CXXFLAGS) -o student main.o student.o

main.o: main.cpp student.h
	$(CXX) $(CXXFLAGS) -c main.cpp

student.o: student.cpp student.h
	$(CXX) $(CXXFLAGS) -c student.cpp

clean:
	rm -f *.o student 