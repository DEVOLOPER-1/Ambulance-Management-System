//
// Created by youss on 08-Nov-24.
//

#ifndef PATIENTQUEUE_H
#define PATIENTQUEUE_H
using namespace std;
#include "queue.h"
#include<string>

class PatientData {
private:
    string CaseType;
    int RequestTime;
    int PatientID;
    int HospitalID;
    int CaseSeverity;
public:
    PatientData(string CaseTpe , int RequestTime , int PatientID , int HospitalID , int CaseSeverity);



    string  GetCaseType() const;
    int  GetRequestTime() const;

    int GetPatientID() const;
    int  GetHospitalID() const;
    int  GetCaseSeverity() const;
    
    // ~PatientData();
};


class PatientQueue {
private:
    queue<PatientData> *SP = new queue<PatientData>; //Special Patient Queue
    queue<PatientData> *EP = new queue<PatientData>; //Emergent Patient Queue
    queue<PatientData> *NP = new queue<PatientData>; //Normal Patient Queue

    PatientQueue();
    ~PatientQueue();
    
    int Partition(PatientData* Patientsarray[] , int  beginning , int ending);
    
    void Sort_EP_Patients_Array(PatientData* Patientsarray[] , int  beginning , int ending);

public:

    void PatientDataHandler(PatientData &PatientObj, int N0_0f_Patients);
    
    PatientData* Get_A_Patient() const;
};



#endif //PATIENTQUEUE_H
