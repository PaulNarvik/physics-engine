# Variables
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj
BIN_DIR = $(BUILD_DIR)/bin
TARGET = $(BIN_DIR)/physics_engine

# Trouver tous les fichiers .cpp
SOURCES = $(shell find $(SRC_DIR) -name '*.cpp')
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# La première règle = règle par défaut quand on tape juste "make"
all: compile run

# Compilation
compile: $(TARGET)

# Lien de l'exécutable
$(TARGET): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(OBJECTS) -o $@

# Compilation des .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Exécution du programme (dépend de la compilation)
run: $(TARGET)
	@echo "Lancement de $(TARGET)..."
	./$(TARGET)

# Nettoyage
clean:
	rm -rf $(BUILD_DIR)

# Règles qui ne correspondent pas à des fichiers
.PHONY: all compile run clean