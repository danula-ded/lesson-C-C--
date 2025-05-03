CXX = g++
CXXFLAGS = -Wall -std=c++11

TARGET = composition_program.exe
SRCS = Address.cpp Person.cpp Employee.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del *.o $(TARGET) 