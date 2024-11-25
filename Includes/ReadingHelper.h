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
    LinkedList<Request>* Requests= new LinkedList<Request>;
    LinkedList<CancellationRequest> *CancellationRequests = new LinkedList<CancellationRequest>;
    int HospitalsCount;
    int** DistancesMatrix;
    int NoOfPatients;
    Hospital* HospitalsArray;
    int row = 0 ;
    int col = 0;
    int HospitalsCounter = 0 ;
    int SpecialCarSpeed;
    int NormalCarSpeed;
    string PatientDataArray[6];
    int NoOfCancellations;
    static ReadingHelper* instance;

public:
    static ReadingHelper* getInstance();
    void Tokenizer(string& line, int SectionNumber);
    void SetNoOfHospitals(int Counts);
    int** &GetDistancesMatrix();
    Hospital* &GetHospitalsArray();
    int GetScarSpeed() const;
    int GetNcarSpeed()const;
    int GetNoOfHospitals()const;
    int GetNoOfCancellations()const;
    int GetNoOfPatients()const;
    LinkedList<Request>* &GetRequestsLinkedList();
    LinkedList<CancellationRequest>* &GetCancellationRequestsLinkedList();
    

private:
    ReadingHelper() : HospitalsCount(0), DistancesMatrix(nullptr) ,  SpecialCarSpeed( 0),NormalCarSpeed(0),
    NoOfCancellations(0) , NoOfPatients(0) , HospitalsArray(nullptr){}
    // ReadingHelper(const ReadingHelper&) = delete;
    // ReadingHelper& operator=(const ReadingHelper&) = delete;
    void Build2DMatrix_and_HospitalsArray(int token);

    void DeleteMatrix(int ** Matrix2D , int rows);
    void DeleteMatrix(Hospital*array );
    ~ReadingHelper() {
        DeleteMatrix(DistancesMatrix , HospitalsCount);
        DeleteMatrix(HospitalsArray);
    }
        
    


};