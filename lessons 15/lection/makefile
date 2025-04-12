CXX = g++
CXXFLAGS = -Wall -g -std=c++11

all: main

main: main.o animal.o dog.o cat.o
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp animal.h dog.h cat.h
	$(CXX) $(CXXFLAGS) -c main.cpp

animal.o: animal.cpp animal.h
	$(CXX) $(CXXFLAGS) -c animal.cpp

dog.o: dog.cpp dog.h animal.h
	$(CXX) $(CXXFLAGS) -c dog.cpp

cat.o: cat.cpp cat.h animal.h
	$(CXX) $(CXXFLAGS) -c cat.cpp

clean:
	rm -f *.o main