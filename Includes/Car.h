#pragma once
#include "Request.h"
#include <iostream>
using namespace std;


class Car
{
	string CarType;
	int speed;
	int HospitalID;
	string status;
	Request* request;
	int nextPickupTime;
	int nextDropOffTime;

	void setStatus(string status) { this->status = status; }

public:
	// Constructor
	Car(string CarType, int speed, int HospitalID) : CarType(CarType), request(nullptr), speed(speed)
		, HospitalID(HospitalID), status("Ready"), nextPickupTime(0), nextDropOffTime(0) {}

	// Getters
	string getStatus() { return status; }

	string getCarType() { return CarType; }

	int getHospitalID() { return HospitalID; }

	int PatientID()
	{
		if (!request)
			return -1;

		return request->getPatientID();
	}

	// methods
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

	void cancel() { request = nullptr; }

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