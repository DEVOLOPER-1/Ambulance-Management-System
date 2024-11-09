cmake_minimum_required(VERSION 3.29)
project(Ambulance_Management_System)

set(CMAKE_CXX_STANDARD 14)

add_executable(Ambulance_Management_System main.cpp
        data_structures/Stack.h
        data_structures/Stack.cpp
        data_structures/queue.h
        data_structures/queue.cpp
        data_structures/LinkedList.cpp
        data_structures/LinkedList.h
        data_structures/Node.cpp
        data_structures/Node.h
        data_structures/PatientQueue.cpp
        data_structures/PatientQueue.h)
