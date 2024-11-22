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
	Request() : PatientType(""), RequestTime(0), PatientID(0), NearestHospital(0), distance(0), severity(0), PickupTime(0) {}

	Request(string	PatientType, int RequestTime, int PatientID, int NearestHospital, int distance, int severity);

	Request(string	PatientType, int RequestTime, int PatientID, int NearestHospital, int distance);

	// getters
	string getPatientType();
	int    getRequestTime();
	int    getPatientID() ;
	int    getPickupTime() ;
	int    getNearestHospital() ;
	int    getDistance() ;
	int    getSeverity() ;

	// setters
	void setPickupTime(int time) ;
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
