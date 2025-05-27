cmake_minimum_required(VERSION 3.16)
project(leetcode-cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Warnings for all targets
set(COMMON_WARNINGS -Wall -Wextra -Wpedantic)

# Enable ASAN only in Debug builds
set(ASAN_COMPILE_FLAGS "")
set(ASAN_LINK_FLAGS "")
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  set(ASAN_COMPILE_FLAGS -fsanitize=address -fno-omit-frame-pointer)
  set(ASAN_LINK_FLAGS -fsanitize=address)
endif()

# GoogleTest setup
enable_testing()
find_package(GTest REQUIRED)
include(GoogleTest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_compile_definitions(TEST_DATA_DIR="${CMAKE_CURRENT_SOURCE_DIR}/tests")

file(GLOB_RECURSE SRC_FILES src/*.cc)
file(GLOB_RECURSE LIB_FILES lib/*.cc)

# Compile all lib/*.cc files into a single OBJECT library
add_library(lib_objects OBJECT ${LIB_FILES})
target_compile_options(
  lib_objects PRIVATE ${COMMON_WARNINGS} ${ASAN_COMPILE_FLAGS}
)
target_link_options(lib_objects PRIVATE ${ASAN_LINK_FLAGS})
target_include_directories(
  lib_objects PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Build each solution file as its own testable executable
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
  target_link_libraries(${EXE_NAME} PRIVATE GTest::gtest GTest::gtest_main)

  gtest_discover_tests(${EXE_NAME})
endforeach()
