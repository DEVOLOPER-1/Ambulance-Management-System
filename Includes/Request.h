#pragma once
#include <iostream>
using namespace std;

class Request
{
	string	PatientType;
	int		RequestTime;
	int     PatientID;
	int		PickupTime;
	int     NearestHospital;
	int		distance;
	int		severity;

public:
	Request(string	PatientType, int RequestTime, int PatientID, int NearestHospital, int distance, int severity)
		: PatientType("Patient"), RequestTime(RequestTime), PatientID(PatientID), NearestHospital(NearestHospital)
		, distance(distance), severity(severity), PickupTime(0) {}

	Request(string	PatientType, int RequestTime, int PatientID, int NearestHospital, int distance)
		: Request(PatientType, RequestTime, PatientID, NearestHospital, distance, 0) {}

	// getters
	string getPatientType() { return PatientType; }
	int    getRequestTime() { return RequestTime; }
	int    getPatientID() { return PatientID; }
	int    getPickupTime() { return PickupTime; }
	int    getNearestHospital() { return NearestHospital; }
	int    getDistance() { return distance; }
	int    getSeverity() { return severity; }

	// setters
	void setPickupTime(int time) { PickupTime = time; }
};

// comparison operators (based on severity)

/*
bool operator< (Request r1, Request r2) { return r1.getSeverity() <  r2.getSeverity(); }
bool operator> (Request r1, Request r2) { return r1.getSeverity() >  r2.getSeverity(); }
bool operator<=(Request r1, Request r2) { return r1.getSeverity() <= r2.getSeverity(); }
bool operator>=(Request r1, Request r2) { return r1.getSeverity() >= r2.getSeverity(); }
bool operator==(Request r1, Request r2) { return r1.getSeverity() == r2.getSeverity(); }
bool operator!=(Request r1, Request r2) { return r1.getSeverity() != r2.getSeverity(); }
*/
