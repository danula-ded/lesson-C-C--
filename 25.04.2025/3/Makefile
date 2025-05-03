CXX = g++
CXXFLAGS = -std=c++17 -Wall -fexec-charset=CP866
TARGET = unique_elements.exe

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	del /F /Q $(OBJS) $(TARGET) 