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

	void setStatus(string status);

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


	void pickUp();

	void cancel(); // for NP requests only

	void dropOff();


	// stream operators
	friend ostream& operator<<(ostream& os, Car& c)  // we need to remove the friendship becuase it is not allowed in the project
	{
		os << c.getCarID();
		if (c.isAssigned())
			os << "_P" << c.getPatientID();
		return os;
	}

};