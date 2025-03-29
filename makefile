CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -g

SRC = $(wildcard *.cpp)  # Finds all .cpp files
OBJS = $(SRC:.cpp=.o)
TARGET = game

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf *.o $(TARGET)
