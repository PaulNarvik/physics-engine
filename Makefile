# Variables
CXX = g++                # Compilateur C++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude  # Flags : C++17, warnings, include dir
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj
BIN_DIR = $(BUILD_DIR)/bin
TARGET = $(BIN_DIR)/physics_engine

# Trouver tous les fichiers .cpp dans src/ et sous-dossiers
SOURCES = $(shell find $(SRC_DIR) -name '*.cpp')
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Règle par défaut : build tout
all: $(TARGET)

# Lier les objets pour créer l'exécutable
$(TARGET): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(OBJECTS) -o $@

# Compiler chaque .cpp en .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyer les fichiers build
clean:
	rm -rf $(BUILD_DIR)

# Phony targets (pas de fichiers réels)
.PHONY: all clean
