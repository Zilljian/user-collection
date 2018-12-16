cmake_minimum_required(VERSION 3.13)
project(collection)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)

add_executable(collection main.cpp)

target_link_libraries(collection Interface)
target_link_libraries(collection Stack)
target_link_libraries(collection Vector)
target_link_libraries(collection Tree)


target_include_directories(collection PRIVATE src/Interface)
target_include_directories(collection PRIVATE src/Stack)
target_include_directories(collection PRIVATE src/Tree)
target_include_directories(collection PRIVATE src/Vector)