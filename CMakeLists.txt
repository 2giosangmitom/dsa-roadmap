cmake_minimum_required(VERSION 3.14)
project("LeetCode_Cpp" LANGUAGES CXX VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_BUILD_TYPE Debug)

option(ENABLE_ASAN "Enable AddressSanitizer" ON)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
  add_compile_options(-Wno-\#warnings -Wall -Wextra -O0 -g)
  if(ENABLE_ASAN)
    add_compile_options(-fsanitize=address)
    add_link_options(-fsanitize=address)
  endif()
endif()

# Testing setup
enable_testing()
find_package(GTest REQUIRED)
include(GoogleTest)

# Library setup
file(GLOB_RECURSE LIB_SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/lib/*.cc")
list(FILTER LIB_SRC_FILES EXCLUDE REGEX ".*_test.cc$")

add_library(lib_objects OBJECT ${LIB_SRC_FILES})
target_include_directories(lib_objects PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/include)

# Tests setup
file(GLOB_RECURSE TEST_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/**/*_test.cc")

foreach(TEST_FILE IN LISTS TEST_FILES)
  get_filename_component(TEST_NAME "${TEST_FILE}" NAME_WE)
  add_executable(${TEST_NAME} "${TEST_FILE}")
  target_link_libraries(${TEST_NAME} PRIVATE GTest::gtest_main lib_objects)
  gtest_discover_tests(${TEST_NAME})
endforeach()
