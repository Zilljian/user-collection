cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 17)

set(Interface_source
        Collection.cpp
        Collection.h
        Iterator.cpp
        Iterator.h
        Node.cpp
        Node.h
        )
add_library(Interface ${Interface_source})