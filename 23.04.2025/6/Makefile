CXX = g++
CXXFLAGS = -Wall -std=c++11

TARGET = employee_work_program.exe
SRCS = main.cpp Manager.cpp Intern.cpp
OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del *.o $(TARGET) 