cmake_minimum_required(VERSION 3.29)
project(Ambulance_Management_System)

set(CMAKE_CXX_STANDARD 14)

add_executable(Ambulance_Management_System main.cpp
        Stack.h
        Stack.cpp
        queue.h
        queue.cpp
        LinkedList.cpp
        LinkedList.h
        Node.cpp
        Node.h)
