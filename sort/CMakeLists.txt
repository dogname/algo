cmake_minimum_required (VERSION 3.11)
project (algorithms CXX)

if (CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -ansi -pedantic -Wall")
endif()

add_library(sort sort.cpp)
add_executable(sort_test test.cpp)
target_link_libraries(sort_test sort)
