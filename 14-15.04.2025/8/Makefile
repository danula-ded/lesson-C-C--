CXX = g++
CXXFLAGS = -Wall -std=c++11

TARGET = account_program.exe
SRCS = Account.cpp SavingsAccount.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del *.o $(TARGET) 