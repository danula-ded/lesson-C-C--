CXX = g++
CXXFLAGS = -std=c++17 -Wall -fexec-charset=CP866
TARGET = autocomplete.exe

SRCS = main.cpp trie.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	del /F /Q $(OBJS) $(TARGET) 