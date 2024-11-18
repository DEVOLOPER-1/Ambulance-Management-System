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
	LinkedQueue<Request*> NP_Requests;
	priQueue<Request*>    EP_Requests;
	LinkedQueue<Car*>     sCars;
	LinkedQueue<Car*>     nCars;

public:
	Hospital(int ID, int NumberOFsCars, int NumberOFnCars) : ID(ID)
	{
		for (int i = 0; i < NumberOFsCars; i++)
			sCars.enqueue(new Car("SC", 50)); // We will handle car speed later

		for (int i = 0; i < NumberOFnCars; i++)
			nCars.enqueue(new Car("NC", 50)); // We will handle car speed later
	}
};