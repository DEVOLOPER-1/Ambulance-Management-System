//
// Created by youss on 19-Nov-24.
//
#pragma once
#define RH ReadingHelper::getInstance()
#include "Hospital.h"
#include "Request.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include<string>
#include "../ds/LinkedList.h"
using namespace std;

class ReadingHelper {
private:
    LinkedList<Request>* Requests;
    int HospitalsCount;
    int** DistancesMatrix;
    int NoOfPatients;
    Hospital* HospitalsArray;
    int row = 0 ;
    int col = 0;
    int HospitalsCounter = 0 ;
    int SpecialCarSpeed;
    int NormalCarSpeed;
    static ReadingHelper* instance;

public:
    void InitializeRequestsList() ;
    static ReadingHelper* getInstance();

    void Build2DMatrix_and_HospitalsArray(int& token);

    void SetNoOfHospitals(int& Counts);

    void Tokenizer(string& line, int& SectionNumber);

private:
    ReadingHelper() : HospitalsCount(0), DistancesMatrix(nullptr) {}
    // ReadingHelper(const ReadingHelper&) = delete;
    // ReadingHelper& operator=(const ReadingHelper&) = delete;
    void DeleteMatrix(int ** Matrix2D , int rows);
    void DeleteMatrix(Hospital*array );
    ~ReadingHelper() {
        DeleteMatrix(DistancesMatrix , HospitalsCount);
        DeleteMatrix(HospitalsArray);
    }
        
    


};