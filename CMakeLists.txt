# DO NOT MODIFY

cmake_minimum_required(VERSION 3.13)
project(EECS348-Lab-7)


if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
    cmake_policy(SET CMP0135 NEW)
endif()

file(GLOB src *.c *.cpp)
list(FILTER src EXCLUDE REGEX ".*main\\.c(c|pp|xx)?")
add_subdirectory(tests)
add_library(assignment ${src})
