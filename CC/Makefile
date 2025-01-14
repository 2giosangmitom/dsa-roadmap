# Compiler and flags
CXX := clang++
CXX_FLAGS := -std=c++23 -Wall -Wextra
GTEST_FLAGS := -lgtest -lgtest_main

# Files
LIB_FILES = lib/linked_list.cc

# Ensure build directory
create_dir:
	@mkdir -p build

# Build library
build-lib: create_dir
	@for file in $(LIB_FILES); do \
		echo "Compiling $$file -> build/$$(basename $$file .cc).o"; \
		$(CXX) $(CXX_FLAGS) -c $$file -o build/$$(basename $$file .cc).o; \
	done

# Build a specific test file
build-test: create_dir
	@if [ -z "$(file)" ]; then \
		echo "Usage: make build file=./path/to/your_test.cc"; \
		exit 1; \
	fi
	@echo "Compiling $(file) -> build/$(notdir $(file:.cc=))"
	@$(CXX) $(CXX_FLAGS) $(GTEST_FLAGS) $(file) -o build/$(notdir $(file:.cc=))
