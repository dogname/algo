cmake_minimum_required (VERSION 3.11)
project (algorithms CXX)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ansi -pedantic -Wall -std=c++11")
endif()

add_library(strassen strassen.cpp strassen.h)
add_executable(test test.cpp)
target_link_libraries(test strassen)
