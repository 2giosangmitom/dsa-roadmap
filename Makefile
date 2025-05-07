# Makefile for building and testing the project

# Generate build files using CMake
generate:
	cmake -B build

# Build the project
build: generate
	cmake --build build

# Run tests
test: build
	ctest --test-dir build

# Clean build files
clean:
	rm -rf build/

# Format code using clang-format
format:
	clang-format -i $(find src -name '*.hpp' -o -name '*.cc')

# Optimize build for release
release: generate
	cmake --build build --config Release

.PHONY: generate build test clean format release
