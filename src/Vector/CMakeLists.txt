cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 17)

set(Vector_source
        VecIterator.cpp
        VecIterator.h
        Vector.cpp
        Vector.h
        )


add_library(Vector ${Vector_source})

target_link_libraries(Vector Interface)

target_include_directories(Vector PRIVATE ../Interface)
