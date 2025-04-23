CXX = g++


, SRCS = main.cpp employee.cpp manager.cpp intern.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = employee_program

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean 