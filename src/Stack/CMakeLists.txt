cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 17)

set(Stack_source
        StackIterator.cpp
        StackIterator.h
        Stack.cpp
        Stack.h
        )

add_library(Stack ${Stack_source})

target_link_libraries(Stack Interface)

target_include_directories(Stack PRIVATE ../Interface)