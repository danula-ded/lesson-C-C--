CXX = g++
CXXFLAGS = -Wall -std=c++11

TARGET = virtual_destructor_program.exe
SRCS = main.cpp Derived.cpp
OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del *.o $(TARGET) 