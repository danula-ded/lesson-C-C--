CXX = g++


SRCS = main.cpp base.cpp derived.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = base_program

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean 