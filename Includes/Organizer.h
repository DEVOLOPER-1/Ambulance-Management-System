//
// Created by youss on 17-Nov-24.
//

#pragma once
#include <string>
#include "Car.h"
#include "Hospital.h"
#include "ReadingHelper.h"
#include"Request.h"
#define ORG Organizer::GetInstance()
using namespace std;



class Organizer {
private:
    ifstream InputFile;
    string FileName;
	LinkedQueue<Request*> requests;
	LinkedQueue<Request*> cancellations;
	LinkedQueue<Car* > outCars;
    LinkedQueue<Car* > backCars;
    static Organizer* instance; 
private:
    Organizer()
        : FileName("E:\\Coding\\C++\\Ambulance-Management-System\\Includes\\InputText.txt")
        , requests(), cancellations(), outCars(), backCars() {};

	Organizer(const Organizer& other) = delete;
	Hospital* FindAlternateHospital(Request* EPPatient) {
		
	}
	// void assignPatientToCar(Request* patient, Car* car) {
	// 	
	// }
	// void GenerateTimeStep(){}
     
     // Request* GenerateRequests(int timeStep);
     //
     // void handleCarArrival(Car* car){}
     //
     //
     // void collectStatistics(){}
     //
     // void produceOutputFile(string fileName){}
     //
     // void callUIUpdate(int timeStep){}
     



public:
    static Organizer* GetInstance();

    void receive(Car* car);

	void sendBack();

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



