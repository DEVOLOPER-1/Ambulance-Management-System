#pragma once
#include "Request.h"
#include <iostream>
using namespace std;


class Car
{
	Request* request;
	int speed;
	string status;
	int nextPickupTime;
	int nextDropOffTime;

	void setStatus(string status) { this->status = status; }

public:
	Car(int speed) : request(nullptr), speed(speed), status("Ready"), nextPickupTime(0), nextDropOffTime(0) {}

	void assign(int timestep, Request* request)
	{
		this->request = request;
		setStatus("Assigned");
		nextPickupTime = timestep + (request->getDistance() / speed);
		nextDropOffTime = nextPickupTime + (request->getDistance() / speed);
	}

	void pickUp()
	{
		setStatus("Loaded");

	}

	void dropOff()
	{
		setStatus("Ready");
		request = nullptr;
	}

	void work(Request* request, int timestep)
	{
		if (status == "Ready" && timestep == request->getRequestTime())
		{
			assign(timestep, request);
		}
		else if (status == "Assigned" && timestep == nextPickupTime)
		{
			pickUp();
		}
		else if (status == "Loaded" && timestep == nextDropOffTime)
		{
			dropOff();
		}
		cout << "Car status: " << status << endl;
	}

};