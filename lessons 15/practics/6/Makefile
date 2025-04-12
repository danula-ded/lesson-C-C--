CXX = g++
CXXFLAGS =

TARGET = program6
SOURCES = main.cpp library.cpp
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = library.h

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean