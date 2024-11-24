//
// Created by youss on 17-Nov-24.
//

#pragma once
#include <string>
#include "Car.h"
#include "Hospital.h"
#include "ReadingHelper.h"
#define ORG Organizer::GetInstance()
using namespace std;



class Organizer {
private:
    ifstream InputFile;
    string FileName;
	Hospital** hospitals;
	LinkedQueue<Request*> requests;
	LinkedQueue<Request*> cancellations;
	priQueue<Car* > outCars;
    priQueue<Car* > backCars;
	static Organizer* instance;  /// Singleton Design Pattern
private:
    Organizer()
        : FileName("D:/University/Year 2/Semester 1/data structure/Project/Ambulance-Management-System/Includes/InputText.txt")
        , requests(), cancellations(), outCars(), backCars(), hospitals(nullptr){};

	Organizer(const Organizer& other) = delete;
    
    /*
    void simulateTimeStep(int timeStep){}

    void handleCarArrival(Car* car){}

    // void assignPatientToCar(Patient* patient, Car* car){}

    void collectStatistics(){}

    void produceOutputFile(string fileName){}

    void callUIUpdate(int timeStep){}
    */



public:
    static Organizer* GetInstance();

    /*
	LinkedQueue<Request*> getRequests()      { return requests; }
	LinkedQueue<Request*> getCancellations() { return cancellations; }
	LinkedQueue<Car*>     getOutCars()       { return outCars; }
	LinkedQueue<Car*>     getBackCars()      { return backCars; }
    */

	void setHospital(Hospital** hospitals) { this->hospitals = hospitals; }

	void setRequests(const LinkedQueue<Request*>& requests) { this->requests = requests; }

    void printOutCars()
    {
		outCars.print();
    }

    void printBackCars()
    {
		backCars.print();
    }

    void sendRequests(int timeStep);

	void runSimulation(int timeSteps);

    void receive(Car* car);

	void sendBack();

	void returnCar();

	void sendCarToHospital(Car* car);

    void loadInputFile();
};


















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



