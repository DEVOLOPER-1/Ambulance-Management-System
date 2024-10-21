cmake_minimum_required(VERSION 3.29)
project(Ambulance_Management_System)

set(CMAKE_CXX_STANDARD 26)

add_executable(Ambulance_Management_System main.cpp
        Stack.h
        Stack.cpp
        queue.cpp)
