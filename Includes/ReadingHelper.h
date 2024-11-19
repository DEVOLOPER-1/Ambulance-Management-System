//
// Created by youss on 19-Nov-24.
//

#ifndef READINGHELPER_H
#define READINGHELPER_H
#define RH ReadingHelper::getInstance()
#include <iostream>
#include <fstream>
#include <sstream>
#include<string>
using namespace std;

class ReadingHelper {
private:
    int HospitalsCount;
    int** DistancesMatrix;
    Hospital* HospitalsArray;
    int row = 0 ;
    int col = 0;
    int HospitalsCounter = 0 ;
    int SpecialCarSpeed;
    int NormalCarSpeed;
    static ReadingHelper* instance;

public:
    static ReadingHelper* getInstance() {
        
        if (instance == nullptr)
            instance = new ReadingHelper();
        return instance;
    }

    void Build2DMatrix_and_HospitalsArray(int & token) {
        // Allocate memory for the 2D matrix
        HospitalsArray = new Hospital[token]();
        DistancesMatrix = new int*[token];
        for (int i = 0; i < token; i++) {
            DistancesMatrix[i] = new int[token];
        }
    }

    void SetNoOfHospitals(int &Counts) {
        RH->HospitalsCount = Counts ;
        RH->Build2DMatrix_and_HospitalsArray(HospitalsCount);
    }

    void Tokenizer(string& line, int& SectionNumber) {
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
                    RH->SpecialCarSpeed = stoi(token) ;
                    cout<<"SpecialCarSpeed -> "<<RH->SpecialCarSpeed<<endl; ;
                    count+=1;
                }
                else if(count==1) {
                    RH->NormalCarSpeed = stoi(token) ;
                    cout<<"NormalCarSpeed -> "<<RH->NormalCarSpeed<<endl; ;
                }
                

            }
        }

        else if (SectionNumber == 1) {
            int counter = 0 ;
            int ScarNumber = 0;
            int NcarNumber = 0 ;
            while (getline(stream , token , delimiter)) {
                if (counter%2 == 0) {
                    cout<<"Scars "<<token<<endl;

                    ScarNumber = stoi(token);
                    counter++;
                }else {
                    cout<<"Ncars "<<token<<endl;

                    NcarNumber = stoi(token);
                    counter++;
                    HospitalsArray[RH->HospitalsCounter] = Hospital(RH->HospitalsCounter , ScarNumber , NcarNumber , RH->SpecialCarSpeed , RH->NormalCarSpeed);
                    RH->HospitalsCounter++;

                }

            }
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
ReadingHelper* ReadingHelper::instance = nullptr;


#endif //READINGHELPER_H
