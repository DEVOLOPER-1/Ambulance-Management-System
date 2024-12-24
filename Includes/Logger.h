//
// Created by youss on 24-Dec-24.
//

#ifndef LOGGER_H
#define LOGGER_H
using namespace std;


class Logger {
private:
    int QT ; //Request Time
    int AT ; //Assignment Time
    int PT ; //Pickup Time
    int WT ; //patient waiting time
    int FT ; //Finsih time
    int DistanceBetPatientHospital;
    int car_busy_time;
public:
    Logger() : QT(0), AT(0), PT(0), WT(0), FT(0), car_busy_time(0) , DistanceBetPatientHospital(0) {}
    
    void CalcPickupTime(int AT , int DistanceBetPatientHospital , int CarSpeed);
    void CalcWaitingTime(int PT , int QT);
    void CalcFinishTime(int PT , int DistanceBetPatientHospital , int CarSpeed);
    void CalcBusyTime();
    
    void setQT(int QT);
    void setAT(int AT);
    void setPT(int PT);
    void setWT(int WT);
    void setFT(int FT);
    void setDistanceBetPatientHospital (int DistanceBetPatientHospital);
    

    int getQT() const;
    int getAT() const ;
    int getPT() const ;
    int getWT() const ;
    int getFT() const ;
    int getBusynessTime() const;
};



#endif //LOGGER_H
