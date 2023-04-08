cmake_minimum_required(VERSION 3.16)
project(Textadventure)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")

add_executable(${PROJECT_NAME}
        main.cpp
        src/Game.cpp
        src/map.cpp
        src/Player.cpp
        include/common/random_generator.h
        include/items/item.h
        )

target_include_directories(${PROJECT_NAME} PUBLIC
        include)

add_subdirectory(test)

