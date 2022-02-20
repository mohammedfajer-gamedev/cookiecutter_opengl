SRC_DIR = src
BUILD_DIR = build

CC = g++

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp $(SRC_DIR)/glad.c)
OBJ_NAME = program

INCLUDE_DIR = -Iinclude
LIBRARY_PATHS = -Llib


COMPILER_FLAGS = -std=c++17 -O0 -g -Wall

LINKER_FLAGS = -lopengl32 -lglfw3 -lgdi32 -lglew32

all:
	$(CC) -o $(BUILD_DIR)/$(OBJ_NAME) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(SRC_FILES) $(COMPILER_FLAGS) $(LINKER_FLAGS)