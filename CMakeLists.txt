cmake_minimum_required(VERSION 3.10)

Project(OOP-1)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES 
programa/main.cpp
programa/funkcijos.cpp)

add_executable(programa1 ${SOURCES})