cmake_minimum_required(VERSION 3.14)
project(leetcode LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Werror")

# Glob files
file(GLOB SRC_FILES "src/*.cc")
file(GLOB TESTS_FILES "tests/*.cc")
file(GLOB LIB_FILES "lib/*.cc")

# Enable testing
find_package(GTest REQUIRED)
enable_testing()

add_executable(tests ${SRC_FILES} ${TESTS_FILES} ${LIB_FILES})
target_link_libraries(tests GTest::gtest_main)

# Link ASAN
target_compile_options(tests PRIVATE -fsanitize=address)
target_link_options(tests PRIVATE -fsanitize=address)
