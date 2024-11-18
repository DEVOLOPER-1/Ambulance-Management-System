//
// Created by youss on 17-Nov-24.
//

#ifndef ORGANIZER_H
#define ORGANIZER_H
#include <iostream>
#include <fstream>
#include <string>
#include "Request.h"
#include "Car.h"
using namespace std;

class Organizer {

public:
    void loadInputFile(string fileName);

    void simulateTimeStep(int timeStep);

    void handleCarArrival(Car* car);

    void assignPatientToCar(Request* PatientRequest, Car* car);

    void collectStatistics();

    void produceOutputFile(string fileName);

    void callUIUpdate(int timeStep);





    
};



#endif //ORGANIZER_H
