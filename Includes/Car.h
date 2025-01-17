#pragma once
#include "Request.h"
#include <iostream>
#include <string>
using namespace std;


class Car
{
	string CarType;
	int speed;
	int HospitalID;
	string CarID;
	string status;
	Request* request;
	int nextPickupTime;
	int nextDropOffTime;

	int calcDuration(int distance);
public:
	// Constructor
	Car(string CarType, int speed, int HospitalID, int car_number);

	// Getters
	string getStatus();

	string getCarType();

	int getHospitalID();

	int getPatientID();

	int getPickedUpTime();

	int getDroppedOffTime();

	string getCarID();

	bool isAssigned();

	// methods
	void assign(int timestep, Request* request);

	void setStatus(string status);

	void pickUp();

	void cancel(); // for NP requests only

	void dropOff(Request* &request);

	// void PrintCar(Car &c);

};
// ostream operators
ostream& operator<<(ostream& os, Car* c);  
