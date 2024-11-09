cmake_minimum_required(VERSION 3.29)
project(Ambulance_Management_System)

set(CMAKE_CXX_STANDARD 14)

add_executable(Ambulance_Management_System main.cpp
        data_structures/synthetic_stack.h
        data_structures/synthetic_queue.h
        data_structures/synthetic_queue.cpp
        data_structures/synthetic_stack.cpp
        data_structures/LinkedList.cpp
        data_structures/LinkedList.h
        data_structures/SyntheticNode.cpp
        data_structures/SyntheticNode.h
        data_structures/PatientQueue.cpp
        data_structures/PatientQueue.h)
