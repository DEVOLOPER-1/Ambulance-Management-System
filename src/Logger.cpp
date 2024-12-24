//
// Created by youss on 24-Dec-24.
//

#include "../Includes/Logger.h"


void Logger::CalcPickupTime(int AT, int DistanceBetPatientHospital, int CarSpeed) {
    PT = AT + (DistanceBetPatientHospital / CarSpeed);
}

void Logger::CalcWaitingTime(int PT, int QT) {
    WT = PT - QT;
}

void Logger::CalcFinishTime(int PT, int DistanceBetPatientHospital, int CarSpeed) {
    FT = PT + (DistanceBetPatientHospital / CarSpeed);
}


void Logger::CalcBusyTime() {
    // car_busy_time = 2 * ( DistanceBetPatientHospital / CarSpeed); // 2 as the car will go and come back
    // or
    car_busy_time = FT - AT;
}

void Logger::setQT(int QT) {
    this->QT = QT;
}

void Logger::setAT(int AT) {
    this->AT = AT;
}

void Logger::setPT(int PT) {
    this->PT = PT;
}

void Logger::setWT(int WT) {
    this->WT = WT;
}


void Logger::setFT(int FT) {
    this->FT = FT;
}


void Logger::setDistanceBetPatientHospital(int DistanceBetPatientHospital) {
    this->DistanceBetPatientHospital = DistanceBetPatientHospital;
}

int Logger::getQT() const {
    return QT;
}

int Logger::getAT() const {
    return AT;
}

int Logger::getPT() const {
    return PT;
}


int Logger::getWT() const {
    return WT;
}


int Logger::getFT() const {
    return FT;
}

int Logger::getBusynessTime() const {
    return car_busy_time;
}

