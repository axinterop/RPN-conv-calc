cmake_minimum_required(VERSION 3.27)
project(project1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(project1
        ll-stack.cpp
        ll-stack.h
        main.cpp
        String.cpp)
