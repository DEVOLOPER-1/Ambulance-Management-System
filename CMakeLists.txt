cmake_minimum_required(VERSION 3.28.1)
project(Ambulance_Management_System)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(Ambulance_Management_System "Main.cpp"
         "Includes/Car.h" "Includes/Request.h" "ds/LinkedQueue.h" "ds/priQueue.h" "ds/Node.h" "ds/LinkedList.h"
        Includes/Organizer.h "Includes/Hospital.h" "Includes/UI.h"
        Includes/ReadingHelper.h
<<<<<<< HEAD
 "src/Hospital.cpp" "src/Organizer.cpp" "src/ReadingHelper.cpp"
        src/Request.cpp)
=======
 "src/Hospital.cpp" "src/Organizer.cpp" "src/ReadingHelper.cpp" "src/Car.cpp")
>>>>>>> CarAssign-BetaVersion
