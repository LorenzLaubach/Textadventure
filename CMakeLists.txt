cmake_minimum_required(VERSION 3.21)
project(Textadventure)


set(CMAKE_CXX_STANDARD 17)
include_directories(
        ./include
)

add_executable(untitled main.cpp include/objects.h include/printing.h include/enemies.h ASCII/troll.h)
