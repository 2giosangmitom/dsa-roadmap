# Compiler and flags
CXX := clang++
CXX_FLAGS := -std=c++23 -Wall -Wextra
GTEST_FLAGS := -lgtest -lgtest_main

# Files
LIB_FILES = lib/linked_list.cc
BUILD_DIR = build

# Ensure build directory
create_dir:
	@mkdir -p $(BUILD_DIR)

# Build library
build-lib: create_dir
	@for file in $(LIB_FILES); do \
		echo "Compiling $$file -> $(BUILD_DIR)/$$(basename $$file .cc).o"; \
		$(CXX) $(CXX_FLAGS) -c $$file -o $(BUILD_DIR)/$$(basename $$file .cc).o; \
	done

# Build a specific test file
build-test: create_dir
	@if [ -z "$(file)" ]; then \
		echo "Usage: make build-test file=./path/to/your_test.cc"; \
		exit 1; \
	fi
	@echo "Compiling $(file) -> $(BUILD_DIR)/$(notdir $(file:.cc=))"
	@if grep -q '#include "linked_list.hpp"' $(file); then \
		$(CXX) $(CXX_FLAGS) $(GTEST_FLAGS) $(BUILD_DIR)/linked_list.o $(file) -o $(BUILD_DIR)/$(notdir $(file:.cc=)); \
	else \
		$(CXX) $(CXX_FLAGS) $(GTEST_FLAGS) $(file) -o $(BUILD_DIR)/$(notdir $(file:.cc=)); \
	fi
