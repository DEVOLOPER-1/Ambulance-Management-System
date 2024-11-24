#pragma once
#include "../Includes/Organizer.h"
#include <iostream>
using namespace std;

Organizer* Organizer::instance = nullptr;

Organizer* Organizer::GetInstance()
{
    if (!instance) instance = new Organizer();
    return instance;
}

void Organizer::sendRequests(int timeStep)
{
	if (requests.isEmpty()) return;
	Request* request;
	while (requests.peek(request) && request->getRequestTime() == timeStep) 
    {
		requests.dequeue(request);
		int HospitalID = request->getNearestHospital();
		hospitals[HospitalID - 1]->receive(request);
	}
}

void Organizer::runSimulation(int timeSteps)
{
	// sendRequests(timeSteps);
	Car* car;
	int pri;
    cout << "\nOut Cars: ";
	outCars.print();
	cout << "\nBack Cars: ";
	backCars.print();

    while (outCars.peek(car, pri) && (car->getPickedUpTime() == timeSteps))
    {
        sendBack();
    }
    while (backCars.peek(car, pri) && (car->getDroppedOffTime() == timeSteps))
	{
		returnCar();
	}
}

void Organizer::receive(Car* car) { outCars.enqueue(car, -(car->getPickedUpTime())); }

void Organizer::sendBack()
{
	Car* car;
    int pri;
	outCars.dequeue(car, pri);
    car->pickUp();
    backCars.enqueue(car, -(car->getDroppedOffTime()));
}

void Organizer::returnCar()
{
	Car* car;
    int pri;
	backCars.dequeue(car, pri);
	car->dropOff();
	sendCarToHospital(car);
}

void Organizer::sendCarToHospital(Car* car)
{
	hospitals[car->getHospitalID() - 1]->receive(car);
}

void Organizer::loadInputFile()
{
    cout << "Reading File....." << endl;
    this->InputFile.open(FileName);
    if (!InputFile.is_open()) {
        cout << "Failed Opening!" << endl;
        return;
    }

    string line;
    int sectionCounter = -1;

    while (getline(InputFile, line)) {

        if (line.empty()) {
            sectionCounter++;
            cout << "Section Counter -> " << sectionCounter << endl;
            continue;
        }

        if (sectionCounter == 0) {
            cout << "DISTANCE_MATRIX" << endl;
            RH->Tokenizer(line, sectionCounter);
            cout << line << endl;
        }
        else if (sectionCounter == 1) {
            cout << "CAR_DISTRIBUTION" << endl;
            RH->Tokenizer(line, sectionCounter);
            // cout << line << endl;
        }
        else if (sectionCounter == 2) {
            cout << "REQUESTS" << endl;
            cout << line << endl;
        }
        else if (sectionCounter == 3) {
            cout << "CANCELLATIONS" << endl;
            cout << line << endl;
        }
        else {
            cout << line.length() << " -> " << line << endl;
            if (line.length() <= 2) {
                int Hospitals;
                Hospitals = stoi(line);
                cout << "Hospitals Count -> " << Hospitals << endl;
                RH->SetNoOfHospitals(Hospitals);
            }
            else {
                int sec = -1;
                cout << "Cars Speeds -> " << line << endl;
                RH->Tokenizer(line, sec);
            }

        }
    }

    InputFile.close();
    cout << "File Reading Completed." << endl;
}
