CC = g++
TARGET = SCC
OBJS = $(wildcard src/*.cpp)

all:
	$(CC) $(OBJS) -o ./build/$(TARGET)