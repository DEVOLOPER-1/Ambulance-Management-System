cmake_minimum_required(VERSION 3.29)
project(Ambulance_Management_System)

set(CMAKE_CXX_STANDARD 17)

add_executable(Ambulance_Management_System main.cpp
         "Includes/Car.h" "Includes/Request.h" "ds/LinkedQueue.h" "ds/priQueue.h" "ds/Node.h" "ds/LinkedList.h"
        Includes/Organizer.h "Includes/Hospital.h" "Includes/UI.h"
        Includes/ReadingHelper.h
)
