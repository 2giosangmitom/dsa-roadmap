# Compiler and flags
CC = clang
CFLAGS = -Wall -Wextra -g -std=c23
LDFLAGS = -lcriterion

# Directories
SRC_DIR = src
TEST_DIR = tests
LIB_DIR = lib
BUILD_DIR = build

# Source files
TEST_SRC = $(wildcard $(TEST_DIR)/*.c)

# Ensure needed directories
ensure_dirs:
	@mkdir -p build

# Build linked_list library
$(LIB_DIR)/linked_list: ensure_dirs
	$(CC) $(CFLAGS) -c $(LIB_DIR)/linked_list.c -o $(BUILD_DIR)/linked_list.o

all: $(LIB_DIR)/linked_list
	$(CC) $(CFLAGS) $(LDFLAGS) $(BUILD_DIR)/linked_list.o $(TEST_SRC) -o $(BUILD_DIR)/tests

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR)

# Phony targets
.PHONY: ensure_dirs clean all
