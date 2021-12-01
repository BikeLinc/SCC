CC = g++
TARGET = SCC
OBJS = $(wildcard src/*.cpp)

all:
	$(CC) $(OBJS) -o $(TARGET) -std=c++11

clean:
	rm -rf $(TARGET)