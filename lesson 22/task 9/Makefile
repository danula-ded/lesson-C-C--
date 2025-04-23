CXX = g++


SRCS = main.cpp song.cpp video.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = playable_program

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean 