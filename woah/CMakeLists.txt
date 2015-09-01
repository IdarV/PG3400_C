cmake_minimum_required(VERSION 3.3)
project(woah)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -std=c11")

set(SOURCE_FILES main.c)
add_executable(woah ${SOURCE_FILES})