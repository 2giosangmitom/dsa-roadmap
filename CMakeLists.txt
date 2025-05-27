cmake_minimum_required(VERSION 3.16)
project(leetcode-cpp LANGUAGES CXX)

# Settings
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Output directory: all built executables go to bin/
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Warnings and ASAN setup
set(COMMON_WARNINGS -Wall -Wextra -Wpedantic)
set(ASAN_COMPILE_FLAGS -fsanitize=address -fno-omit-frame-pointer)
set(ASAN_LINK_FLAGS -fsanitize=address)

# Test config
enable_testing()
find_package(GTest REQUIRED)
include(GoogleTest)

# Global include and macro
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_compile_definitions(TEST_DATA_DIR="${CMAKE_CURRENT_SOURCE_DIR}/tests")

# Gather files
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS src/*.cc lib/*_test.cc)
file(GLOB_RECURSE LIB_FILES CONFIGURE_DEPENDS lib/*.cc)
list(FILTER LIB_FILES EXCLUDE REGEX ".*_test.cc$") # exclude test files

# Object library for shared logic
add_library(lib_objects OBJECT ${LIB_FILES})
target_compile_options(
  lib_objects PRIVATE ${COMMON_WARNINGS} ${ASAN_COMPILE_FLAGS}
)
target_link_options(lib_objects PRIVATE ${ASAN_LINK_FLAGS})
target_include_directories(
  lib_objects PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Build each source/test file into a testable binary
foreach(SRC_FILE ${SRC_FILES})
  get_filename_component(EXE_NAME ${SRC_FILE} NAME_WE)

  add_executable(${EXE_NAME} ${SRC_FILE} $<TARGET_OBJECTS:lib_objects>)
  target_compile_options(
    ${EXE_NAME} PRIVATE ${COMMON_WARNINGS} ${ASAN_COMPILE_FLAGS}
  )
  target_link_options(${EXE_NAME} PRIVATE ${ASAN_LINK_FLAGS})
  target_include_directories(
    ${EXE_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
  )
  target_link_libraries(${EXE_NAME} PRIVATE GTest::gtest_main)

  gtest_discover_tests(${EXE_NAME})
endforeach()
