CXX = g++
CXXFLAGS = -Wall -std=c++11

TARGET = employee_program.exe
SRCS = Employee.cpp Manager.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del *.o $(TARGET) 