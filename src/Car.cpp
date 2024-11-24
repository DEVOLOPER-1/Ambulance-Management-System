#include "../Includes/Car.h"

void Car::setStatus(string status)
{
	this->status = status;
}

Car::Car(string CarType, int speed, int HospitalID, int car_number) : CarType(CarType), speed(speed)
		, HospitalID(HospitalID), request(nullptr), status("Ready"), nextPickupTime(0), nextDropOffTime(0)
{
	CarID = CarType + to_string(car_number) + "_H" + to_string(HospitalID);

}

string Car::getStatus() { return status; }

string Car::getCarType() { return CarType; }

int Car::getHospitalID() { return HospitalID; }

int Car::getPatientID()
{
	if (!request)
		return -1;

	return request->getPatientID();
}

int Car::getPickedUpTime() { return nextPickupTime; }

int Car::getDroppedOffTime() { return nextDropOffTime; }

void Car::assign(int timestep, Request* request)
{
	this->request = request;
	setStatus("Assigned");
	nextPickupTime = timestep + (request->getDistance() / speed);
	nextDropOffTime = nextPickupTime + (request->getDistance() / speed);
}

void Car::pickUp()
{
	setStatus("Loaded");

}

void Car::cancel()
{
	request = nullptr;
}

void Car::dropOff()
{
	setStatus("Ready");
	request = nullptr;
}

