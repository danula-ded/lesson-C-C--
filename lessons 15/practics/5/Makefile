CXX = g++
CXXFLAGS = -Wall

TARGET = program5
SOURCES = main.cpp counter.cpp
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = counter.h

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean