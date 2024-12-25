#pragma once
#include <iostream>
#include "Logger.h"
using namespace std;

class CancellationRequest {
private:
	int PID;
	int Time;
	int HID;
	
public:
	CancellationRequest();
	CancellationRequest(int Time , int PID , int HID);
	int GetPID()const;
	int GeTTime()const;
	int GetHID()const;
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
	Logger * logger;

public:
	Request();
	Request(string	PatientType, int RequestTime, int PatientID, int NearestHospital, int distance, int severity); // EP

	Request(string	PatientType, int RequestTime, int PatientID, int NearestHospital, int distance); // NP , SP
	// getters
	string getPatientType();
	int    getRequestTime();
	int    getPatientID() ;
	int    getPickupTime() ;
	int    getNearestHospital() ;
	int    getDistance() ;
	int    getSeverity() ;
	Logger* GetLogger();
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
