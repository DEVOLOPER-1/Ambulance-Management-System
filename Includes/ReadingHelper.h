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
#include "../ds/LinkedQueue.h"
using namespace std;
class Hospital;
class ReadingHelper {
private:
    LinkedQueue<Request*> Requests;
    LinkedQueue<CancellationRequest*> CancellationRequests;
    int HospitalsCount;
    int** DistancesMatrix;
    int NoOfPatients;
    Hospital** HospitalsArray; //Hospital* HospitalsArray -> Hospital* HospitalsArray[] -> Hospital HospitalsArray[HospitalsCount]
    int row ;
    int col ;
    int HospitalsCounter ;
    int SpecialCarSpeed;
    int NormalCarSpeed;
    string PatientDataArray[6];
    int NoOfCancellations;
    int TotalCars_in_AllHospitals;
    static ReadingHelper* instance;

public:
    static ReadingHelper* getInstance();
    void Tokenizer(string& line, int SectionNumber);
    void SetNoOfHospitals(int Counts);
    int** &GetDistancesMatrix();
    Hospital** &GetHospitalsArray();
    int GetScarSpeed() const;
    int GetNcarSpeed()const;
    int GetNoOfHospitals()const;
    int GetNoOfCancellations()const;
    int GetNoOfPatients()const;
    int GetTotalCars_in_AllHospitals()const;
    LinkedQueue<Request*> &GetRequestsQueue();
    LinkedQueue<CancellationRequest*> &GetCancellationRequestsQueue();
    

private:
    ReadingHelper() : HospitalsCount(0), DistancesMatrix(nullptr) ,  SpecialCarSpeed( 0),NormalCarSpeed(0),
    NoOfCancellations(0) , NoOfPatients(0) , HospitalsArray(nullptr) , HospitalsCounter(0) ,row(0) , col(0) ,
    TotalCars_in_AllHospitals(0) {}
    // ReadingHelper(const ReadingHelper&) = delete;
    // ReadingHelper& operator=(const ReadingHelper&) = delete;
    void Build2DMatrix_and_HospitalsArray(int token);

    void DeleteMatrix(int ** Matrix2D , int rows);
    void DeleteMatrix(Hospital**array );
    ~ReadingHelper() {
        DeleteMatrix(DistancesMatrix , HospitalsCount);
        // DeleteMatrix(HospitalsArray);
    }


};