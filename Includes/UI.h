//
// Created by youss on 25-Nov-24.
//
#pragma once
#ifndef UI_H
#define UI_H
// #include "Decorators.h"
#include<iostream>
#include <iomanip>
using namespace std;

class UI {
public:
    
    void display(int timestep);

    void DisplayTimestep(int timestep);
    
    // void DisplayHospital(Hospital* hosp){
    //     cout<<endl;
    //     cout << "Hospital ID : " << hosp->GetHospitalID()<< endl; 
    //     cout << "  EP requests : " << hosp->GetEPRequestsCount() << endl;
    //     cout << "  SP requests : " << hosp->GetSPRequestsCount() << endl;
    //     cout << "  NP requests : " << hosp->GetNPRequestsCount() << endl;
    // }
    //
    // void display_out_cars(LinkedQueue<Car*> out_cars){ // show out cars
    //     cout << "out cars : ";
    //     if (out_cars.isEmpty()){
    //         cout << "no out cars";
    //     } 
    //     else{
    //         out_cars.print(); 
    //     }
    // }
    //
    // void display_back_cars(LinkedQueue<Car*> back_cars){ // show back cars
    //     cout << "back cars : ";
    //     if (back_cars.isEmpty()){
    //         cout << "no back cars";
    //     } 
    //     else{
    //         back_cars.print(); 
    //     }
    // }
    //
    // void print_output_screen(int timestep, Hospital* hosp, LinkedQueue<Car*> out_cars, LinkedQueue<Car*> back_cars){
    //     DisplayTimestep(timestep); // Show timestep
    //     DisplayHospital(hosp); // Show hospital status
    //     display_out_cars(out_cars);   // Show out cars
    //     display_back_cars(back_cars); // Show back cars
    // }

 
};

#endif //UI_H
