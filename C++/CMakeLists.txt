cmake_minimum_required(VERSION 3.14)
project(leetcode LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_COMPILER clang++)

# Find GoogleTest
find_package(GTest REQUIRED)
enable_testing()

# Collect source files
file(GLOB SRC_FILES "src/*.cc")
file(GLOB TEST_FILES "tests/*.cc")

# Create the test executable
add_executable(tests ${SRC_FILES} ${TEST_FILES})
target_link_libraries(tests GTest::gtest_main)
target_compile_options(
  tests PRIVATE -Wall -Wextra -Wpedantic -g -O2
)
target_link_options(tests PRIVATE -fsanitize=address)

# Enable GoogleTest discovery
include(GoogleTest)
gtest_discover_tests(tests)
