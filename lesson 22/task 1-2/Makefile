CXX = g++


SRCS = main.cpp animal.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = animal_program

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean 