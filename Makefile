# ==============================================================
# Makefile pour physics-engine + SDL3 (Linux)
# ==============================================================

# Nom de l'exécutable
TARGET   := physics-engine
BUILD    := build
SRC      := src
INCLUDE  := include

# Sources et objets
SOURCES  := $(wildcard $(SRC)/*.cpp)
OBJECTS  := $(SOURCES:$(SRC)/%.cpp=$(BUILD)/%.o)
DEPENDS  := $(OBJECTS:.o=.d)

# Compilateur et flags de base
CXX      := g++               # ou clang++
CXXFLAGS := -std=c++20 -I$(INCLUDE) -Wall -Wextra -Wpedantic
CXXFLAGS += -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align
CXXFLAGS += -Wconversion -Wsign-conversion -Wnull-dereference

# Flags SDL3 via pkg-config (la méthode officielle)
SDL_FLAGS := $(shell pkg-config --cflags sdl3)
LDLIBS    := $(shell pkg-config --libs sdl3)

# Mode Debug par défaut
CXXFLAGS += -O0 -g3 -DDEBUG
LDFLAGS  :=

# ==============================================================
# Règles principales
# ==============================================================

.PHONY: all clean run asan ubsan tsan release

all: $(BUILD)/$(TARGET)

# Compilation avec AddressSanitizer + UBSan (recommandé en dev !)
asan: CXXFLAGS += -fsanitize=address,leak -fno-omit-frame-pointer
asan: LDFLAGS  += -fsanitize=address,leak
asan: clean all

ubsan: CXXFLAGS += -fsanitize=undefined -fno-omit-frame-pointer
ubsan: LDFLAGS  += -fsanitize=undefined
ubsan: clean all

tsan: CXXFLAGS += -fsanitize=thread
tsan: LDFLAGS  += -fsanitize=thread
tsan: clean all

# Build optimisée
release: CXXFLAGS += -O3 -march=native -DNDEBUG
release: LDFLAGS  += -flto
release: clean all

# Lier l'exécutable
$(BUILD)/$(TARGET): $(OBJECTS) | $(BUILD)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS) $(LDLIBS)
	@echo "Build terminé → $@"

# Compiler les .cpp → .o
$(BUILD)/%.o: $(SRC)/%.cpp | $(BUILD)
	$(CXX) $(CXXFLAGS) $(SDL_FLAGS) -MMD -MP -c $< -o $@

# Créer le dossier build s'il n'existe pas
$(BUILD):
	mkdir -p $(BUILD)

# Inclure les dépendances automatiques
-include $(DEPENDS)

# Nettoyer
clean:
	rm -rf $(BUILD)

# Lancer l'exécutable
run: all
	./$(BUILD)/$(TARGET)

# ==============================================================
# Infos
# ==============================================================

info:
	@echo "Sources trouvés : $(words $(SOURCES))"
	@pkg-config --cflags --libs sdl3

help:
	@echo "Cibles disponibles :"
	@echo "  all      → build normale (debug)"
	@echo "  asan     → avec AddressSanitizer + LeakSanitizer (recommandé !)"
	@echo "  ubsan    → avec UndefinedBehaviorSanitizer"
	@echo "  tsan     → avec ThreadSanitizer"
	@echo "  release  → build optimisée (-O3 + LTO)"
	@echo "  clean    → supprimer build/"
	@echo "  run      → compiler et lancer"
