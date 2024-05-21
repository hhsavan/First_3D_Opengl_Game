CC = g++
CXXFLAGS = -std=c++11 -Wall
LDFLAGS = -lglfw -lGLEW -lGL

TARGET = main
SOURCES = main.cpp

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CXXFLAGS) -o $(TARGET) $(SOURCES) $(LDFLAGS)

clean:
	rm -f $(TARGET)
