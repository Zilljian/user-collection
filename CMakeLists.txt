cmake_minimum_required(VERSION 3.13)
project(collection)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_SOURCE_DIR src)

add_subdirectory(src)
#add_subdirectory(src/Vector)

set(SOURCE_EXE main.cpp)

add_executable(collection main.cpp)

#target_link_libraries(collection src/Interface)
#target_link_libraries(collection src/Stack)
#target_link_libraries(collection src/Tree)
#target_link_libraries(collection src/Vector)
target_link_libraries(collection src)

target_include_directories(collection PRIVATE src/Interface)
target_include_directories(collection PRIVATE src/Stack)
target_include_directories(collection PRIVATE src/Tree)
target_include_directories(collection PRIVATE src/Vector)