CXX = g++


SRCS = main.cpp vehicle.cpp car.cpp truck.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = vehicle_program

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean 