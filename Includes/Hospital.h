#pragma once
#include "Car.h"
#include "Request.h"
#include "../ds/LinkedQueue.h"
#include "../ds/priQueue.h"
#include <iostream>
using namespace std;


class Hospital
{
	int ID;
	LinkedQueue<Request*> SP_Requests;
	LinkedQueue<Request*> NP_Requests; // We will change the data structure to a derived class of LinkedQueue with the ability to cancel
	priQueue<Request*>    EP_Requests;
	LinkedQueue<Car*>     sCars;
	LinkedQueue<Car*>     nCars;

	void send(Car* car);

public:
	Hospital(){};
	Hospital(int ID, int NumberOFsCars, int NumberOFnCars, const int ScarSpeed, const int NcarSpeed);

	void receive(Request* request);
	
	void handleRequests(int timestep);

	void receive(Car* car);
	
	int GetHospitalID() const;
	
	int GetSPRequestsCount();
	int GetNPRequestsCount();
	int GetEPRequestsCount();
};

