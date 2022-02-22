CXX = g++
CXXFLAGS = -Wall -std=c++11
SRC_DIR = src
BUILD_DIR = build

SRCS = $(SRC_DIR)/main.cpp $(SRC_DIR)/game.cpp $(SRC_DIR)/renderer.cpp
OBJS = $(BUILD_DIR)/main.o $(BUILD_DIR)/game.o $(BUILD_DIR)/renderer.o
TARGET = game_of_life

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	LDFLAGS = -framework OpenGL -framework GLUT
else
	LDFLAGS = -lGL -lGLU -lglut
endif

all: $(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

$(BUILD_DIR)/main.o: $(SRC_DIR)/main.cpp $(SRC_DIR)/game.h $(SRC_DIR)/renderer.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/main.cpp -o $(BUILD_DIR)/main.o

$(BUILD_DIR)/game.o: $(SRC_DIR)/game.cpp $(SRC_DIR)/game.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/game.cpp -o $(BUILD_DIR)/game.o

$(BUILD_DIR)/renderer.o: $(SRC_DIR)/renderer.cpp $(SRC_DIR)/renderer.h $(SRC_DIR)/game.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/renderer.cpp -o $(BUILD_DIR)/renderer.o

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all clean
