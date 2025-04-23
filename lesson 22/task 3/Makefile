CXX = g++

SRCS = main.cpp circle.cpp rectangle.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = shape_program

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean 