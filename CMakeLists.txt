cmake_minimum_required(VERSION 3.5)

project(algorithm-cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(algorithm-cpp list.h algorithm.h main.cpp)

install(TARGETS algorithm-cpp
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
