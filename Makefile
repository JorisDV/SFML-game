# Windows only

CXX = g++
CXXFLAGS = -Wall -Wextra -Wpedantic -g -std=c++20
CPPFLAGS = -Iinclude -Iexternal/SFML-3.0.2/include
LDFLAGS = -Lexternal/SFML-3.0.2/lib
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system

SFML_DIR = external/SFML-3.0.2
SFML_BIN = $(SFML_DIR)/bin

SRC_DIR = src
OBJ_DIR = build
TARGET = $(OBJ_DIR)/main.exe

SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC))
DEP = $(OBJ:.o=.d)

all: $(TARGET)

$(OBJ_DIR):
	if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)

$(TARGET): $(OBJ) | $(OBJ_DIR)
	$(CXX) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $(TARGET)
	@copy /Y "$(SFML_BIN)\sfml-system-3.dll" "$(OBJ_DIR)\"
	@copy /Y "$(SFML_BIN)\sfml-window-3.dll" "$(OBJ_DIR)\"
	@copy /Y "$(SFML_BIN)\sfml-graphics-3.dll" "$(OBJ_DIR)\"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -MMD -MP -c $< -o $@

run: $(TARGET)
	.\$(TARGET)

clean:
	if exist $(OBJ_DIR) rmdir /S /Q $(OBJ_DIR)

-include $(DEP)

.PHONY: all run clean