# ==========================================
# Student Management System - Makefile
# ==========================================

# Compilers
CXX = g++
CC = gcc

# Compiler Flags
CXXFLAGS = -std=c++17 -Wall -Iinclude -Ilibs/sqlite
CFLAGS = -Wall

# Directories
SRC_DIR = src
SQLITE_DIR = libs/sqlite
BUILD_DIR = build

# Source Files
CPP_SRC = $(wildcard $(SRC_DIR)/*.cpp)
CPP_OBJ = $(CPP_SRC:.cpp=.o)

SQLITE_SRC = $(SQLITE_DIR)/sqlite3.c
SQLITE_OBJ = $(SQLITE_DIR)/sqlite3.o

# Output Executable
TARGET = $(BUILD_DIR)/StudentManagementSystem.exe

# ==========================================
# Build
# ==========================================

all: $(TARGET)

$(TARGET): $(CPP_OBJ) $(SQLITE_OBJ)
	$(CXX) $(CPP_OBJ) $(SQLITE_OBJ) -o $(TARGET)

# Compile C++ files
$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile SQLite C file
$(SQLITE_OBJ): $(SQLITE_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

# ==========================================
# Run
# ==========================================

run: all
	$(TARGET)

# ==========================================
# Clean
# ==========================================

clean:
	-if exist src\*.o del /Q src\*.o
	-if exist libs\sqlite\*.o del /Q libs\sqlite\*.o
	-if exist build\StudentManagementSystem.exe del /Q build\StudentManagementSystem.exe