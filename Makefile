CC := g++

INC_DIR := inc
SRC_DIR := src
OBJ_DIR := bin

LIBS := -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio

CXXFLAGS := -O3 -std=c++14 -Wall -I$(INC_DIR) -fsanitize=leak
LDFLAGS  := $(LIBS)

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

OUT  = main

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) -c -o $@ $< $(CXXFLAGS)

$(OUT): $(OBJ_FILES)
	$(CC) -o $@ $^ $(LDFLAGS)

.PHONY: clean

clean:
	rm -rf $(OBJ_DIR)/*.o $(OUT)
