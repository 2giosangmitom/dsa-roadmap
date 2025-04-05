cmake_minimum_required(VERSION 3.14)

project("LeetCode_Cpp" LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Compiler warnings and sanitizer flags
set(COMMON_WARNINGS "-Wall" "-Wextra" "-Wpedantic" "-Werror" "-g")
set(ASAN_FLAGS "-fsanitize=address")

# Enable testing and find GTest
enable_testing()
find_package(GTest REQUIRED)
include(GoogleTest)

# Source files for libraries in src/lib/ (exclude _test.cc files)
file(GLOB_RECURSE LIB_SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/lib/*.cc")
list(FILTER LIB_SRC_FILES EXCLUDE REGEX ".*_test.cc$")

# Compile library files into .o
foreach(LIB_SRC IN LISTS LIB_SRC_FILES)
  get_filename_component(LIB_OBJ "${LIB_SRC}" NAME_WE)
  set(LIB_OBJ_FILE "${CMAKE_BINARY_DIR}/lib/${LIB_OBJ}.o")

  add_library(${LIB_OBJ} OBJECT "${LIB_SRC}")
  target_compile_options(${LIB_OBJ} PRIVATE ${COMMON_WARNINGS} ${ASAN_FLAGS})
endforeach()

# Collect all test files ending with _test.cc (excluding from lib)
file(
  GLOB_RECURSE
  TEST_FILES
  CONFIGURE_DEPENDS
  "${CMAKE_CURRENT_SOURCE_DIR}/**/*_test.cc"
)

foreach(TEST_FILE IN LISTS TEST_FILES)
  # Extract test name from the filename
  get_filename_component(TEST_NAME "${TEST_FILE}" NAME_WE)

  # Define the test executable
  add_executable(${TEST_NAME} "${TEST_FILE}")

  # Link GTest, library object files, and apply flags locally
  target_link_libraries(${TEST_NAME} PRIVATE GTest::gtest_main)
  target_link_libraries(${TEST_NAME} PRIVATE ${LIB_OBJ})
  target_compile_options(${TEST_NAME} PRIVATE ${COMMON_WARNINGS} ${ASAN_FLAGS})
  target_link_options(${TEST_NAME} PRIVATE ${ASAN_FLAGS})

  # Discover tests with ctest
  gtest_discover_tests(${TEST_NAME})
endforeach()
