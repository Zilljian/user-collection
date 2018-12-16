cmake_minimum_required(VERSION 3.13)

set(Tree_source
        BreadthIterator.cpp
        BreadthIterator.h
        DepthIterator.cpp
        DepthIterator.h
        Tree.cpp
        Tree.h
        )
add_library(Tree ${Tree_source})

target_link_libraries(Tree Interface)

target_include_directories(Tree PRIVATE ../Interface)