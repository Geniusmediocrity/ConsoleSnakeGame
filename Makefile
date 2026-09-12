SRC_DIR   := src
BUILD_DIR := build
BIN_DIR   := bin
INC_DIR := inc

CXX := g++
CXX_FLAGS := -std=c++23 -Wall -Wextra -Werror -Wpedantic -O2 -pedantic -I$(INC_DIR)
LD_FLAGS := -lncurses

SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SOURCES))
TARGET := $(BIN_DIR)/snake

# === Product ===

.PHONY: all
all: $(TARGET)

# Building executable file
$(TARGET): $(OBJECTS) | $(BIN_DIR)
	$(CXX) $(LD_FLAGS) $^ -o $@

# Building object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	@mkdir -p $(dir $@)
	$(CXX) $(CXX_FLAGS) -c $< -o $@

# Creating directories
$(BUILD_DIR) $(BIN_DIR):
	mkdir -p $@

# === Cleaning up the binaries and executables ===
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

# === Installing in system (/usr/sbin) ===
.PHONY: install
install: $(TARGET)
	sudo install -D -m755 $(TARGET) /usr/sbin/

# === Running the game ===
.PHONY: run
run: $(TARGET)
	./$(TARGET) || /usr/sbin/$(TARGET) || echo "OS error 2:\nThere is no such file or directory. Please notice that you've successfully build and link the executable file"
