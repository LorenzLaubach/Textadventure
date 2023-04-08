cmake_minimum_required(VERSION 3.16)
project(Textadventure_test)

add_executable(test_random_numbers src/test_random_numbers.cpp)

target_include_directories(test_random_numbers PUBLIC ../include)