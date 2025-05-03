CXX = g++
CXXFLAGS = -Wall -std=c++11

TARGET = vehicle_program.exe
SRCS = Vehicle.cpp Engine.cpp Car.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del *.o $(TARGET) 