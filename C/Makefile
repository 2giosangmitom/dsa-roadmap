# Compiler and flags
CC = clang
CFLAGS = -Wall -Wextra -g
LDFLAGS = -lcriterion

# Directories
SRC_DIR = src
TEST_DIR = tests
BUILD_DIR = build

# Source files
SRC = $(wildcard $(SRC_DIR)/*.c)
TEST_SRC = $(wildcard $(TEST_DIR)/*.c)

# Output executable
TARGET = $(BUILD_DIR)/tests

# Ensure build directory exists
ensure_dirs:
	@mkdir -p $(BUILD_DIR)

# Build the test executable
$(TARGET): ensure_dirs $(SRC) $(TEST_SRC)
	$(CC) $(CFLAGS) $(SRC) $(TEST_SRC) $(LDFLAGS) -o $(TARGET)

# Build everything
all: $(TARGET)

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR)

# Phony targets
.PHONY: ensure_dirs all clean
