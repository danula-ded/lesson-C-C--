CXX = g++
CXXFLAGS = -std=c++17 -Wall
TARGET = task_manager.exe

SRCS = main.cpp task.cpp task_manager.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	del /F /Q $(OBJS) $(TARGET) 