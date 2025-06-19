CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2
TARGET = cuyugan_andrelee_cyclic
SOURCE = cuyugan_andrelee_cyclic.cpp

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCE)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run 