cmake_minimum_required(VERSION 3.16)
project(Textadventure)


set(CMAKE_CXX_STANDARD 14)

#add_executable(textadventure main.cpp include/objects.h include/printing.h include/enemies.h ASCII/troll.h include/common.h)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")

ADD_EXECUTABLE(${PROJECT_NAME} main.cpp include/Player.hpp include/map.hpp include/printing.h include/common.h include/enemies.h include/ASCII/sword.h)

TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PUBLIC ./include/)