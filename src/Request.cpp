//
// Created by youss on 22-Nov-24.
//
#pragma once
#include "../Includes/Request.h"
#include <iostream>
using namespace std;

Request::Request(string	PatientType, int RequestTime, int PatientID, int NearestHospital, int distance, int severity)
        : PatientType(PatientType), RequestTime(RequestTime), PatientID(PatientID), NearestHospital(NearestHospital)
        , distance(distance), severity(severity), PickupTime(0) {}

Request::	Request(string	PatientType, int RequestTime, int PatientID, int NearestHospital, int distance)
                : Request(PatientType, RequestTime, PatientID, NearestHospital, distance, 0) {}

string Request:: getPatientType() { return PatientType; }
int Request:: getRequestTime() { return RequestTime; }

int Request::getPatientID() { return PatientID; }
int Request::getPickupTime() { return PickupTime; }
int Request:: getNearestHospital() { return NearestHospital; }
int Request::getDistance() { return distance; }
int Request::getSeverity() { return severity; }
void Request::setPickupTime(int time) { PickupTime = time; }
