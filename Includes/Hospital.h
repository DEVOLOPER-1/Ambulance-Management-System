#pragma once
#include "Car.h"
#include "Request.h"
#include "../ds/LinkedQueue.h"
#include "../ds/PriQueue.h"
#include <iostream>

#include "ReadingHelper.h"
using namespace std;

class ReadingHelper;

class Hospital
{
	int ID;
	LinkedQueue<Request*> SP_Requests;
	SpecialLinkedQueue<Request*> NP_Requests;
	PriQueue<Request*>    EP_Requests;
	LinkedQueue<Car*>     sCars;
	LinkedQueue<Car*>     nCars;

	void send(Car* car);

public:
	Hospital(){};
	Hospital(int ID, int NumberOFsCars, int NumberOFnCars, const int ScarSpeed, const int NcarSpeed);

	void receive(Request* request);

	bool handleNPCancellations(int PatientID);
	
	void handleRequests(int timestep);

	void receive(Car* car);
	
	void print();

	int GetHospitalID() const;
	
	int GetSPRequestsCount();
	int GetNPRequestsCount();
	int GetEPRequestsCount();
};

