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

# Find all .cc files except _test.cc
file(GLOB_RECURSE LIB_SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/lib/*.cc")
list(FILTER LIB_SRC_FILES EXCLUDE REGEX ".*_test.cc$")

# Global interface target for all object files
add_library(lib_objects INTERFACE)

foreach(LIB_SRC IN LISTS LIB_SRC_FILES)
  get_filename_component(LIB_OBJ "${LIB_SRC}" NAME_WE)
  add_library(${LIB_OBJ} OBJECT "${LIB_SRC}")
  target_compile_options(${LIB_OBJ} PRIVATE ${COMMON_WARNINGS} ${ASAN_FLAGS})

  # Link object files to the global interface library
  target_link_libraries(lib_objects INTERFACE $<TARGET_OBJECTS:${LIB_OBJ}>)
endforeach()

# Collect all test files
file(GLOB_RECURSE TEST_FILES "${CMAKE_CURRENT_SOURCE_DIR}/**/*_test.cc")

foreach(TEST_FILE IN LISTS TEST_FILES)
  get_filename_component(TEST_NAME "${TEST_FILE}" NAME_WE)
  add_executable(${TEST_NAME} "${TEST_FILE}")

  target_link_libraries(${TEST_NAME} PRIVATE GTest::gtest_main)
  target_link_libraries(${TEST_NAME} PRIVATE lib_objects)

  target_compile_options(${TEST_NAME} PRIVATE ${COMMON_WARNINGS} ${ASAN_FLAGS})
  target_link_options(${TEST_NAME} PRIVATE ${ASAN_FLAGS})

  gtest_discover_tests(${TEST_NAME})
endforeach()
