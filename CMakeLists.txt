cmake_minimum_required(VERSION 3.29)
project(TicTacToe_GAME_)

set(CMAKE_CXX_STANDARD 20)

add_executable(TicTacToe_GAME_ main.cpp
        Board.cpp
        Board.h
        CellState.h
        Player.h
        HumanPlayer.cpp
        HumanPlayer.h
        Game.cpp
        Game.h
        AIPlayer.cpp
        AIPlayer.h)
