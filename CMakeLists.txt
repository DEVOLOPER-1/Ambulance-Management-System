cmake_minimum_required(VERSION 3.28.1)
project(Ambulance_Management_System)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(Ambulance_Management_System "Main.cpp"
         "Includes/Car.h" "Includes/Request.h" "ds/LinkedQueue.h" "ds/PriQueue.h" "ds/Node.h" "ds/LinkedList.h"
        Includes/Organizer.h "Includes/Hospital.h"
        Includes/ReadingHelper.h
 "src/Hospital.cpp" "src/Organizer.cpp" "src/ReadingHelper.cpp"
        src/Request.cpp
 "src/Hospital.cpp" "src/Organizer.cpp" "src/ReadingHelper.cpp"
        src/Car.cpp
        ds/Stack.h
        Includes/Decorators.h
        Includes/UI.h
        src/UI.cpp
        src/Logger.cpp
        Includes/Logger.h
)


#>>>>>>> CarAssign-BetaVersion
#<<<<<<< HEAD "src/Car.cpp"