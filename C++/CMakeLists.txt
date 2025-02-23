cmake_minimum_required(VERSION 3.14)
project(leetcode LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Enable testing
enable_testing()

# Find GoogleTest
find_package(GTest REQUIRED)

# Collect source files
file(GLOB SRC_FILES CONFIGURE_DEPENDS "src/*.cc")
file(GLOB TEST_FILES CONFIGURE_DEPENDS "tests/*.cc")
file(GLOB LIB_FILES CONFIGURE_DEPENDS "lib/*.cc")

# Create a static library for reusable components
add_library(leetcode_lib STATIC ${LIB_FILES})
target_compile_options(leetcode_lib PRIVATE -Wall -Wextra -Wpedantic)

# Create the test executable
add_executable(tests ${SRC_FILES} ${TEST_FILES})
target_link_libraries(tests PRIVATE leetcode_lib GTest::gtest_main)

# Additional compiler warnings
target_compile_options(tests PRIVATE -Wall -Wextra -Wpedantic -Wshadow -Wconversion -Werror -g)

# Optional sanitizers
if(CMAKE_BUILD_TYPE MATCHES Debug)
  target_compile_options(tests PRIVATE -fsanitize=address,undefined)
  target_link_options(tests PRIVATE -fsanitize=address,undefined)
endif()

# Enable GoogleTest discovery
include(GoogleTest)
gtest_discover_tests(tests)
