cmake_minimum_required(VERSION 3.21)
project(Textadventure)


set(CMAKE_CXX_STANDARD 14)

#add_executable(textadventure main.cpp include/objects.h include/printing.h include/enemies.h ASCII/troll.h include/common.h)

ADD_EXECUTABLE(${PROJECT_NAME} main.cpp)

TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PRIVATE ./include/)