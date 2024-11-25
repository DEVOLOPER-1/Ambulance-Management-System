//
// Created by youss on 17-Nov-24.
//

#pragma once
#include <string>
#include "Car.h"
#include "Hospital.h"
#include "ReadingHelper.h"
#include "../ds/Stack.h"
#include"UI.h"
#define ORG Organizer::GetInstance()
using namespace std;



class Organizer {
private:
    ifstream InputFile;
    string FileName;
	int** hospitals_distances;
	int HospitalsCount;
	int PatientsCount;
	int CancellationsCount;
	Hospital* hospitals;
	LinkedQueue<Request>* requests;
	LinkedQueue<CancellationRequest>* cancellations;
	priQueue<Car* > outCars;
    priQueue<Car* > backCars;
	static Organizer* instance;  /// Singleton Design Pattern
private:
    Organizer()
        : FileName("E:\\Coding\\C++\\Ambulance-Management-System\\Includes\\InputText.txt")
        , requests(), cancellations(), outCars(), backCars(), hospitals(nullptr){};

	Organizer(const Organizer& other) = delete;

    // methods to handle cars
    void sendBack();

    void returnCar();

public:
    static Organizer* GetInstance();

	void setHospital( Hospital* &HospitalsArray);
	void SetHospitalsDistances( int ** &hospitals_distances);
	void SetHospitalsCount(int HospitalsCount);
	void setRequests( LinkedQueue<Request>* &requests);
	void setCancellationRequestQ( LinkedQueue<CancellationRequest>* &CancellationRequests );
	void SetPatientsCount(int PatientsCount);
	void SetCancellationsCount(int CancellationsCount);


    void printOutCars()
    {
		outCars.print(); // beta version
    }

    void printBackCars()
    {
		backCars.print(); // beta version
    }

	// methods to handle requests
    void distributeRequests(int timeStep);

	// methods to handle cars
	void handleCars(int timeSteps);

    void receive(Car* car);

	// methods to handle input file (Scenario)
    void loadInputFile();
	

	void SetDataMembersValues();
};





/*
void simulateTimeStep(int timeStep){}

void handleCarArrival(Car* car){}

// void assignPatientToCar(Patient* patient, Car* car){}

void collectStatistics(){}

void produceOutputFile(string fileName){}

void callUIUpdate(int timeStep){}
*/






/*
LinkedQueue<Request*> getRequests()      { return requests; }
LinkedQueue<Request*> getCancellations() { return cancellations; }
LinkedQueue<Car*>     getOutCars()       { return outCars; }
LinkedQueue<Car*>     getBackCars()      { return backCars; }
*/





//Deprecated
    
//     void loadInputFile() {
//         
//         cout<<"Reading File....."<<endl;
//         this->InputFile.open(FileName);
//         if (InputFile.is_open()) {
//             string Currentline,NextLine;
//             int SectionCounter{0};
//
//             while (getline(InputFile, Currentline)) {
//                 while (getline(InputFile, NextLine, ' ')) {
//                     if (Currentline.empty()) {
//                         SectionCounter++;
//                         cout << "Section Counter -> " << SectionCounter << endl;
//                         continue;
//                     }
//
//                     // Process sections based on the SectionCounter
//                     if (SectionCounter == 0) {
//                         cout << "### HOSPITALS ###" << endl;
//                         cout << Currentline << endl;
//                     } else if (SectionCounter == 1) {
//                         cout << "### DISTANCE_MATRIX ###" << endl;
//                         cout << Currentline << endl;
//                     } else if (SectionCounter == 2) {
//                         cout << "### CAR_DISTRIBUTION ###" << endl;
//                         cout << Currentline << endl;
//                     } else if (SectionCounter == 3) {
//                         cout << "### REQUESTS ###" << endl;
//                         cout << Currentline << endl;
//                     } else if (SectionCounter == 4) {
//                         cout << "### CANCELLATIONS ###" << endl;
//                         cout << Currentline << endl;
//                     }
//     }
// }
//             InputFile.close();
//         }
//         
//     }



