cmake_minimum_required (VERSION 3.11)
project (algorithms CXX)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -ansi  -Wall -std=c++11")
endif()

add_library(linklist linklist.cpp linklist.h)
add_executable(test main.cpp squeue.hpp stack.hpp bittree.hpp)
