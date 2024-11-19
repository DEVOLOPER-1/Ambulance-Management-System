//
// Created by youss on 17-Nov-24.
//

#ifndef ORGANIZER_H
#define ORGANIZER_H
#define RH ReadingHelper::getInstance()
#include <iostream>
#include <fstream>
#include <sstream>
#include<string>
#include "Car.h"
#include "Hospital.h"
#include "ReadingHelper.h"
#define ORG Organizer::GetInstance()
using namespace std;
namespace fs = std::filesystem;






class Organizer {
private:
    ifstream InputFile;
    string FileName;
    static Organizer* instance; 
private:
    Organizer()
    : FileName("..\\InputText.txt") {
    }
    
    void simulateTimeStep(int timeStep){}

    void handleCarArrival(Car* car){}

    // void assignPatientToCar(Patient* patient, Car* car){}

    void collectStatistics(){}

    void produceOutputFile(string fileName){}

    void callUIUpdate(int timeStep){}




public:
    static Organizer* GetInstance() {
        if (instance==nullptr){instance = new Organizer();}
        return instance;
    }

    void loadInputFile() {
        cout << "Reading File....." << endl;
        this->InputFile.open(FileName);
        if (!InputFile.is_open()) {
            cout << "Failed Openinig!" << endl;
            return;
        }

        string line;
        int sectionCounter = -1;

        while (getline(InputFile, line )) {
            
            if (line.empty()) {
                sectionCounter++;
                cout << "Section Counter -> " << sectionCounter << endl;
                continue;
            }

            if (sectionCounter == 0) {
                cout << "DISTANCE_MATRIX" << endl;
                RH->Tokenizer(line , sectionCounter);
                cout << line << endl;
            } else if (sectionCounter == 1) {
                cout << "CAR_DISTRIBUTION" << endl;
                RH->Tokenizer(line , sectionCounter);
                // cout << line << endl;
            } else if (sectionCounter == 2) {
                cout << "REQUESTS" << endl;
                cout << line << endl;
            } else if (sectionCounter == 3) {
                cout << "CANCELLATIONS" << endl;
                cout << line << endl;
            }
            else {
                cout<<line.length()<<" -> "<<line<<endl;
                if(line.length()<=2) {
                    int Hospitals;
                    Hospitals = stoi(line);
                    cout<<"Hospitals Count -> "<<Hospitals<<endl;
                    RH->SetNoOfHospitals(Hospitals);
                }
                else {
                    int sec = -1 ;
                    cout<<"Cars Speeds -> "<<line<<endl;
                    RH->Tokenizer(line , sec);
                }
                
            }
        }

        InputFile.close();
        cout << "File Reading Completed." << endl;
    }
};
Organizer* Organizer::instance = nullptr ;


#endif //ORGANIZER_H















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



