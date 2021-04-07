cmake_minimum_required(VERSION 3.17)
project(FiveInARow)

set(CMAKE_CXX_STANDARD 14)

add_executable(FiveInARow
        main.cpp Board/Board.cpp Board/Board.h Game/Game.cpp Game/Game.h Interaction/Console.cpp Interaction/Console.h)
