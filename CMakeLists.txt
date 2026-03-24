cmake_minimum_required(VERSION 3.10)

Project(OOP-1)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES 
main.cpp
funkcijos.cpp)

file(GLOB TXT_FILES "${CMAKE_SOURCE_DIR}/*.txt")
file(COPY ${TXT_FILES} DESTINATION ${CMAKE_BINARY_DIR})

add_executable(programa1 ${SOURCES})