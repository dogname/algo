cmake_minimum_required (VERSION 3.11)
project (algorithms CXX)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -ansi -pedantic -Wall")
endif()

add_library(fmaxarray fmaxarray.cpp fmaxarray.h)
add_executable(test test.cpp)
target_link_libraries(test fmaxarray)
