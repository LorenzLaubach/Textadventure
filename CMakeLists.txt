cmake_minimum_required(VERSION 3.16)
project(Textadventure)


set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")

# Create Library of the source files
add_library(adventureLib
        src/Enemy.cpp
#        include/Enemy.h
        src/Game.cpp
#        include/Game.h
        src/map.cpp
#        include/map.h
        src/Player.cpp
#        include/Player.h
        include/common.hpp
        include/printing.hpp
        )

# Executable of main
add_executable(${PROJECT_NAME} main.cpp)

# link the library to the executable
target_link_libraries(${PROJECT_NAME} adventureLib)

# link headers to the library
target_include_directories(adventureLib PUBLIC include)

#target_include_directories(${PROJECT_NAME} PRIVATE include)

