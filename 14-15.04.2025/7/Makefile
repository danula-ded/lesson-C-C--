CXX = g++
CXXFLAGS = -Wall -std=c++11

TARGET = shapes_program.exe
SRCS = Rectangle.cpp Triangle.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del *.o $(TARGET) 