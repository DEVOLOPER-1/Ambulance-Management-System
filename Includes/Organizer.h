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
#include "Includes/Car.h"
using namespace std;

class ReadingHelper {
private:
    int HospitalsCount;
    int** DistancesMatrix;
    int row = 0 ;
    int col = 0;
    float SpecialCarSpeed;
    float NormalCarSpeed;
    static ReadingHelper* instance;

public:
    static ReadingHelper* getInstance() {
        
        if (instance == nullptr)
            instance = new ReadingHelper();
        return instance;
    }

    void Build2DMatrix(int & token) {
        // Allocate memory for the 2D matrix
        DistancesMatrix = new int*[token];
        for (int i = 0; i < token; i++) {
            DistancesMatrix[i] = new int[token];
        }
    }

    void SetNoOfHospitals(int &Counts) {
        RH->HospitalsCount = Counts ;
        RH->Build2DMatrix(HospitalsCount);
    }

    static void Tokenizer(string& line, int& SectionNumber) {
        string token;
        istringstream stream(line);
        char delimiter{' '};
        if (SectionNumber == 0) {
            while (getline(stream, token, delimiter)) {
                cout << "Token"
                     << " -> " << token << endl;
                int distance = stoi(token);
                cout<<distance<<" -> "<<RH->row<<RH->col<<endl;
                RH->DistancesMatrix[RH->row][RH->col] = distance;
                RH->col++;
                if (RH->col == RH->HospitalsCount) {
                    RH->col = 0;
                    RH->row++;
                }
            }
        }
            else if (SectionNumber==-1) {
                int count = 0 ;
                while (getline(stream, token, delimiter)) {
                if (count == 0 ){
                    RH->SpecialCarSpeed = stof(token) ;
                    
                    cout<<"SpecialCarSpeed -> "<<RH->SpecialCarSpeed<<endl; ;

                    count+=1;
                }
                else if(count==1) {
                    RH->NormalCarSpeed = stof(token) ;
                    cout<<"NormalCarSpeed -> "<<RH->NormalCarSpeed<<endl; ;
                }
                

            }
        }

        else if (SectionNumber == 1) {
            
        }
    }

private:
    ReadingHelper() : HospitalsCount(0), DistancesMatrix(nullptr) {}
    ReadingHelper(const ReadingHelper&) = delete;
    ReadingHelper& operator=(const ReadingHelper&) = delete;
    ~ReadingHelper() {
        if (DistancesMatrix) {
            for (int i = 0; i < HospitalsCount; ++i) {
                delete[] DistancesMatrix[i];
            }
            delete[] DistancesMatrix; 
        }
    }

};



class Organizer {
private:
    ifstream InputFile;
    string FileName;
private:
        
    void simulateTimeStep(int timeStep){}

    void handleCarArrival(Car* car){}

    // void assignPatientToCar(Patient* patient, Car* car){}

    void collectStatistics(){}

    void produceOutputFile(string fileName){}

    void callUIUpdate(int timeStep){}




public:
    Organizer(): FileName("E:\\Coding\\C++\\Ambulance-Management-System\\InputText.txt") {}
    

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
                cout << line << endl;
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


ReadingHelper* ReadingHelper::instance = nullptr;

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



