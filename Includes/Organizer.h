//
// Created by youss on 17-Nov-24.
//

#ifndef ORGANIZER_H
#define ORGANIZER_H
#include <iostream>
#include <fstream>
#include <sstream>
#include<string>
using namespace std;

class ReadingHelper {
private:
    int HospitalsCount;
    int** DistancesMatrix;

public:
    static ReadingHelper& getInstance() {
        static ReadingHelper instance;
        return instance;
    }

    void Build2DMatrix(int & token) {
        // Allocate memory for the 2D matrix
        DistancesMatrix = new int*[HospitalsCount];
        for (int i = 0; i < HospitalsCount; i++) {
            DistancesMatrix[i] = new int[HospitalsCount];
        }
    }

    static void Tokenizer(string& line, int& SectionNumber) {
        ReadingHelper& instance = ReadingHelper::getInstance();
        if (SectionNumber == 0) {
            string token;
            istringstream stream(line);
            char delimiter{' '};
            int row  = 0 , col = 0 ;
            while (getline(stream, token, delimiter)) {
                cout << "Token"
                     << " -> " << token << endl;
                int distance = stoi(token);
                instance.DistancesMatrix[row][col] = distance;
                col++;
                if (col == instance.HospitalsCount) {
                    col = 0;
                    row++;
                }
                
            }
        } else {
            if (line.length() <= 2) {
                    instance.HospitalsCount = stoi(line);
                    instance.Build2DMatrix(instance.HospitalsCount);

            }
        }
    }

private:
    ReadingHelper() : HospitalsCount(0), DistancesMatrix(nullptr) {}
    ReadingHelper(const ReadingHelper&) = delete;
    ReadingHelper& operator=(const ReadingHelper&) = delete;
    // ~ReadingHelper() {
    //     
    // }
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
        ReadingHelper & instance = ReadingHelper::getInstance() ;

        while (getline(InputFile, line )) {
            
            if (line.empty()) {
                sectionCounter++;
                cout << "Section Counter -> " << sectionCounter << endl;
                continue;
            }

            if (sectionCounter == 0) {
                cout << "HOSPITALS" << endl;
                instance.Tokenizer(line , sectionCounter);
                cout << line << endl;
            } else if (sectionCounter == 1) {
                cout << "DISTANCE_MATRIX" << endl;
                cout << line << endl;
            } else if (sectionCounter == 2) {
                cout << "CAR_DISTRIBUTION" << endl;
                cout << line << endl;
            } else if (sectionCounter == 3) {
                cout << "REQUESTS" << endl;
                cout << line << endl;
            } else if (sectionCounter == 4) {
                cout << "CANCELLATIONS" << endl;
                cout << line << endl;
            }
            else {
                int Hospitals;
                cout<<line.length()<<" -> "<<line<<endl;
                if(0<=line.length()<=3) Hospitals = stoi(line);
            }
        }

        InputFile.close();
        cout << "File Reading Completed." << endl;
    }
};



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



