cmake_minimum_required (VERSION 3.11)
project (algorithms CXX)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -ansi -pedantic -Wall")
endif()

add_library(linklist linklist.cpp linklist.h)
add_library(stack stack.hpp)
add_library(squeue squeue.hpp)
add_executable()
