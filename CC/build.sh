#!/usr/bin/env bash

# Directories
LIB_DIR="lib"
TEST_DIR="tests"
BUILD_DIR="build"

# Compiler and flags (use arrays)
CXX=("clang++")
CXX_FLAGS=("-std=c++23" "-Wall" "-Wextra")
GTEST_FLAGS=("-I${GTEST_DEV}" "-lgtest" "-lgtest_main")

# Ensure the build directory exists
create_dir() {
  if [ ! -d "$BUILD_DIR" ]; then
    mkdir -p "$BUILD_DIR"
  fi
}

# Find all test files
get_test_files() {
  find "$LIB_DIR" "$TEST_DIR" -name "*_test.cc"
}

# Find all library files excluding *_test.cc
get_lib_files() {
  find "$LIB_DIR" -name "*.cc" ! -name "*_test.cc"
}

# Compile the library files
build_lib() {
  create_dir
  for file in $(get_lib_files); do
    output_file="$BUILD_DIR/$(basename "${file%.cc}.o")"
    echo "Compiling $file -> $output_file"
    "${CXX[@]}" "${CXX_FLAGS[@]}" -c "$file" -o "$output_file"
  done
}

# Compile and build a specific test file
build_test() {
  local file="$1"
  local test_name
  local output_file

  test_name=$(basename "${file%.cc}")
  output_file="$BUILD_DIR/$test_name"

  if grep -q "ListNode" "$file"; then
    echo "Compiling $file with linked_list.o -> $output_file"
    "${CXX[@]}" "${CXX_FLAGS[@]}" "${GTEST_FLAGS[@]}" "$BUILD_DIR/linked_list.o" "$file" -o "$output_file"
  else
    echo "Compiling $file -> $output_file"
    "${CXX[@]}" "${CXX_FLAGS[@]}" "${GTEST_FLAGS[@]}" "$file" -o "$output_file"
  fi
}

# Build all tests
build_all() {
  create_dir
  build_lib
  for file in $(get_test_files); do
    build_test "$file"
  done
}

# Run all tests
run_all() {
  for file in "$BUILD_DIR"/*; do
    if [[ ! "$file" =~ \.o$ ]]; then
      echo "Running $file"
      "$file"
    fi
  done
}

# Clean build directory
clean() {
  if [ -d "$BUILD_DIR" ]; then
    echo "Cleaning $BUILD_DIR"
    rm -rf "$BUILD_DIR"
  fi
}

# Command-line arguments handling
case "$1" in
build-all)
  build_all
  ;;
build-test)
  if [ -n "$2" ]; then
    build_test "$2"
  else
    echo "Usage: $0 build-test <test_file_path>"
    exit 1
  fi
  ;;
build-lib)
  build_lib
  ;;
run-all)
  run_all
  ;;
clean)
  clean
  ;;
*)
  echo "Usage: $0 <build-all|build-test|build-lib|run-all|clean>"
  exit 1
  ;;
esac
