CXX = g++
CXXFLAGS = -Wall -std=c++11

TARGET = media_player_program.exe
SRCS = main.cpp Song.cpp Video.cpp
OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del *.o $(TARGET) 