cmake_minimum_required(VERSION 3.19)
project(gobang)

set(CMAKE_CXX_STANDARD 14)

add_executable(gobang main.cpp gobang.h map_print.h function.h)