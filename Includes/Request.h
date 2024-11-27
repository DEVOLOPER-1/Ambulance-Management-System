#pragma once
#include <iostream>
using namespace std;

class CancellationRequest {
private:
	int PID;
	int Time;
	
public:
	CancellationRequest();
	CancellationRequest(int Time , int PID);
	int GetPID()const;
	int GETTime()const;
};


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
	Request();
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

// stream operators
ostream& operator<<(ostream& os, Request* r);

// comparison operators (based on severity)

/*
bool operator< (Request r1, Request r2) { return r1.getSeverity() <  r2.getSeverity(); }
bool operator> (Request r1, Request r2) { return r1.getSeverity() >  r2.getSeverity(); }
bool operator<=(Request r1, Request r2) { return r1.getSeverity() <= r2.getSeverity(); }
bool operator>=(Request r1, Request r2) { return r1.getSeverity() >= r2.getSeverity(); }
bool operator==(Request r1, Request r2) { return r1.getSeverity() == r2.getSeverity(); }
bool operator!=(Request r1, Request r2) { return r1.getSeverity() != r2.getSeverity(); }
*/
