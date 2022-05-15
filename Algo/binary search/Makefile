CXX = g++
FLAGS = -std=c++11 -O2 -Wall -g 


TARGET = binary_test

all: $(TARGET)

$(TARGET):main.cpp
	$(CXX) main.cpp -o $@ $(FLAGS)

clean:
	rm -rf $(TARGET)