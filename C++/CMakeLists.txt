cmake_minimum_required(VERSION 3.14)

project("LeetCode C++")

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Werror -g")

# Source files
file(GLOB SRC_FILES "**/*.cc")

# Enable testing
find_package(GTest REQUIRED)
enable_testing()

add_executable(leetcode_test ${SRC_FILES})
target_link_libraries(leetcode_test GTest::gtest_main)

# Link ASAN
target_compile_options(leetcode_test PRIVATE -fsanitize=address)
target_link_options(leetcode_test PRIVATE -fsanitize=address)

# Enable GoogleTest discovery for ctest command
include(GoogleTest)
gtest_discover_tests(leetcode_test)
