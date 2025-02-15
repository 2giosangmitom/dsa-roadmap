cmake_minimum_required(VERSION 3.14)
project(leetcode LANGUAGES C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_COMPILER clang)

# Collect source files
file(GLOB SRC_FILES "src/*.c")
file(GLOB TEST_FILES "tests/*.c")
file(GLOB LIB_FILES "lib/*.c")

add_executable(tests ${LIB_FILES} ${SRC_FILES} ${TEST_FILES})
target_compile_options(
  tests PRIVATE -Wall -Wextra -Wpedantic -g -O2
)
target_link_options(tests PRIVATE -fsanitize=address -lcriterion)
