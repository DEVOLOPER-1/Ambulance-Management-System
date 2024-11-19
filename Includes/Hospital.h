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

public:
	Hospital(int ID, int NumberOFsCars, int NumberOFnCars) : ID(ID), SP_Requests(), NP_Requests(), EP_Requests(), sCars(), nCars()
	{
		for (int i = 0; i < NumberOFsCars; i++)
			sCars.enqueue(new Car("SC", 50)); // We will handle car speed later

		for (int i = 0; i < NumberOFnCars; i++)
			nCars.enqueue(new Car("NC", 50)); // We will handle car speed later
	}

	void receive(Request* request)
	{
		if (request->getPatientType() == "NP")
			NP_Requests.enqueue(request);
		else if (request->getPatientType() == "SP")
			SP_Requests.enqueue(request);
		else
			EP_Requests.enqueue(request, request->getSeverity());
	}

	void handleRequests(int timestep)
	{
		int priority;
		Request* request;
		Car* car;
		while (EP_Requests.peek(request, priority) && (nCars.peek(car) || sCars.peek(car)))
		{
			EP_Requests.dequeue(request, priority);
			nCars.peek(car) ? nCars.dequeue(car) : sCars.dequeue(car);
			car->assign(timestep, request); // report the car to the organizer --|><| S O O N |><|--
			// if there is a request the hospital should report it to the organizer --|><| S O O N |><|--
		}
		while (SP_Requests.peek(request) && sCars.peek(car))
		{
			SP_Requests.dequeue(request);
			sCars.dequeue(car);
			car->assign(timestep, request); // report the car to the organizer --|><| S O O N |><|--
		}
		while (NP_Requests.peek(request) && nCars.peek(car))
		{
			NP_Requests.dequeue(request);
			nCars.dequeue(car);
			car->assign(timestep, request); // report the car to the organizer --|><| S O O N |><|--
		}
	}

	void receive(Car* car)
	{
		// handling car status will be done in the organizer --|><| S O O N |><|--
		if (car->getCarType() == "SC")
			sCars.enqueue(car);
		else
			nCars.enqueue(car);
	}
};

