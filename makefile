CC = g++
CXXFLAGS = -std=c++11 -Wall
LDFLAGS = -lglfw -lGLEW -lGL

TARGET = main
SOURCES = src/*
HEADERS = include/*

all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	$(CC) $(CXXFLAGS) -o $(TARGET) $(SOURCES) $(LDFLAGS)

clean:
	rm -f $(TARGET)
