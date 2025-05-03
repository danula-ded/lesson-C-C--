CXX = g++
CXXFLAGS = -Wall -std=c++11

TARGET = shape_program.exe
SRCS = Shape.cpp Circle.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del *.o $(TARGET) 