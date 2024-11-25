//
// Created by youss on 25-Nov-24.
//
#pragma once
#ifndef UI_H
#define UI_H
// #include "Decorators.h"
#include<iostream>
#include <iomanip>
#include "Hospital.h"
#include "../ds/LinkedQueue.h"
using namespace std;


class UI {
public:
    void DisplayTimeStep(int TimeStep) {
        cout<<"Time Step: "<< TimeStep<<endl;
        cout<<setw(120)<<setfill('-')<<""<<endl;
    }

    void DisplayHospital(Hospital*h) {
        cout<<setw(50)<<setfill('-')<<" Hospital #"<< h->GetHospitalID()<<" Data"<<setw(50)<<setfill('-')<<"";
        cout<<h->GetEPRequestsCount()<<" EP Requests: "; //Will be continued later
        cout<<h->GetSPRequestsCount()<<" SP Requests: ";
        cout<<h->GetNPRequestsCount()<<" NP Requests: ";
    }
    
};



#endif //UI_H
