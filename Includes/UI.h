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

   void DisplayHospital(Hospital* h){
        cout << "hospital ID : " << h->GetHospitalID()<< endl; 
        cout << " status : " << endl;
        cout << "  EP requests : " << h->GetEPRequestsCount() << endl;
        cout << "  SP requests : " << h->GetSPRequestsCount() << endl;
        cout << "  NP requests : " << h->GetNPRequestsCount() << endl;
    }

    void DisplaySystemStatus(LinkedQueue<Car*> availableCars, priQueue<Car*> busyCars, LinkedQueue<Request*> pendingRequests){
        
        cout << "available cars : " << endl;
        availableCars.print(); // print linked queue of available cars
        cout << endl;
        cout << "busy cars : " << endl;
        busyCars.print(); // print priority queue of busy cars
        cout << endl;
        cout << "pending requests:" << endl;
        pendingRequests.print(); // print linked queue of pending requests
        cout << endl;
    }
};



#endif //UI_H
