cmake_minimum_required(VERSION 3.14)
project("LeetCode_Cpp" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set default build type to Debug if not specified
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

option(ENABLE_ASAN "Enable AddressSanitizer" ON)

# Set compile flags based on compiler and build type
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
  set(CMAKE_CXX_FLAGS_DEBUG "-Wno-#warnings -Wall -Wextra -O0 -g")
  set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
  set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g -DNDEBUG")
  set(CMAKE_CXX_FLAGS_MINSIZEREL "-Os -DNDEBUG")
  if(ENABLE_ASAN)
    set(ASAN_FLAGS "-fsanitize=address")
  endif()
endif()

enable_testing()
find_package(GTest REQUIRED)
include(GoogleTest)

# Collect all source files in the lib directory, excluding test files
file(GLOB_RECURSE LIB_SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/lib/*.cc")
list(FILTER LIB_SRC_FILES EXCLUDE REGEX ".*_test.cc$")

add_library(lib_objects INTERFACE)

# Create object libraries for each source file
foreach(LIB_SRC IN LISTS LIB_SRC_FILES)
  get_filename_component(LIB_OBJ "${LIB_SRC}" NAME_WE)
  add_library(${LIB_OBJ} OBJECT "${LIB_SRC}")
  target_compile_options(${LIB_OBJ} PRIVATE ${ASAN_FLAGS})
  target_link_options(${LIB_OBJ} PRIVATE ${ASAN_FLAGS})
  target_link_libraries(lib_objects INTERFACE $<TARGET_OBJECTS:${LIB_OBJ}>)
endforeach()

# Collect all test files
file(GLOB_RECURSE TEST_FILES "${CMAKE_CURRENT_SOURCE_DIR}/**/*_test.cc")

# Create executables for each test file and link with GTest and lib_objects
foreach(TEST_FILE IN LISTS TEST_FILES)
  get_filename_component(TEST_NAME "${TEST_FILE}" NAME_WE)
  add_executable(${TEST_NAME} "${TEST_FILE}")
  target_link_libraries(${TEST_NAME} PRIVATE GTest::gtest_main lib_objects)
  target_compile_options(${TEST_NAME} PRIVATE ${ASAN_FLAGS})
  target_link_options(${TEST_NAME} PRIVATE ${ASAN_FLAGS})
  gtest_discover_tests(${TEST_NAME})
endforeach()
