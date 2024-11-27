//
// Created by youss on 22-Nov-24.
//
#pragma once
#include "../Includes/Request.h"
#include <iostream>
using namespace std;
Request::Request() : PatientType(""), RequestTime(0), PatientID(0), NearestHospital(0), distance(0), severity(0), PickupTime(0) {}

Request::Request(string	PatientType, int RequestTime, int PatientID, int NearestHospital, int distance, int severity)
        : PatientType(PatientType), RequestTime(RequestTime), PatientID(PatientID), NearestHospital(NearestHospital)
        , distance(distance), severity(severity), PickupTime(0) {}

Request::Request(string	PatientType, int RequestTime, int PatientID, int NearestHospital, int distance)
                : Request(PatientType, RequestTime, PatientID, NearestHospital, distance, 0) {}

string Request::getPatientType() { return PatientType; }
int Request::getRequestTime() { return RequestTime; }

int Request::getPatientID() { return PatientID; }
int Request::getPickupTime() { return PickupTime; }
int Request:: getNearestHospital() { return NearestHospital; }
int Request::getDistance() { return distance; }
int Request::getSeverity() { return severity; }
void Request::setPickupTime(int time) { PickupTime = time; }





CancellationRequest::CancellationRequest():PID(0) , Time(0){}
CancellationRequest::CancellationRequest(int Time, int PID) :PID(PID) , Time(Time){}
int CancellationRequest::GETTime()const{return Time;}
int CancellationRequest::GetPID()const{return PID;}

ostream& operator<<(ostream& os, Request* r)
{
    os << r->getPatientID();
	return os;
}
