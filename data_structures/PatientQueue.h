//
// Created by youss on 08-Nov-24.
//

#ifndef PATIENTQUEUE_H
#define PATIENTQUEUE_H
using namespace std;
#include "synthetic_queue.h"
#include <bits/stdc++.h>

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
    synthetic_queue<PatientData> *SP = new synthetic_queue<PatientData>; //Special Patient Queue
    synthetic_queue<PatientData> *EP = new synthetic_queue<PatientData>; //Emergent Patient Queue
    synthetic_queue<PatientData> *NP = new synthetic_queue<PatientData>; //Normal Patient Queue

    PatientQueue();
    ~PatientQueue();
    
    int Partition(PatientData* Patientsarray[] , int  beginning , int ending);
    
    void Sort_EP_Patients_Array(PatientData* Patientsarray[] , int  beginning , int ending);

public:

    void PatientDataHandler(PatientData &PatientObj, int N0_0f_Patients);
    
    PatientData* Get_A_Patient() const;
};



#endif //PATIENTQUEUE_H
