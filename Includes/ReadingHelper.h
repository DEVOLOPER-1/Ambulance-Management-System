//
// Created by youss on 19-Nov-24.
//
#pragma once
#define RH ReadingHelper::getInstance()
#include "Hospital.h"
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
    static ReadingHelper* getInstance();

    void Build2DMatrix_and_HospitalsArray(int& token);

    void SetNoOfHospitals(int& Counts);

    void Tokenizer(string& line, int& SectionNumber);

private:
    ReadingHelper() : HospitalsCount(0), DistancesMatrix(nullptr) {}
    ReadingHelper(const ReadingHelper&) = delete;
    ReadingHelper& operator=(const ReadingHelper&) = delete;
    ~ReadingHelper()
    {
        if (DistancesMatrix) {
            for (int i = 0; i < HospitalsCount; ++i) {
                delete[] DistancesMatrix[i];
            }
            delete[] DistancesMatrix;
        }
    }

};