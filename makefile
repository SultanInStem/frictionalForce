# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Iinclude

# SFML directories
SFML_INCLUDE = -Iinclude/SFML
SFML_LIB = -Llib -lsfml-graphics -lsfml-window -lsfml-system

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Source and Object files
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
EXECUTABLE = $(BIN_DIR)/main

# Default target
all: $(EXECUTABLE)

# Create the executable by linking object files
$(EXECUTABLE): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(OBJECTS) -o $@ $(SFML_LIB)

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDE) -c $< -o $@

# Clean up
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Phony targets
.PHONY: all clean