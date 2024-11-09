//
// Created by youss on 08-Nov-24.
//

#include "PatientQueue.h"



void PatientQueue:: PatientDataHandler(const PatientData & PatientObj , int N0_0f_Patients) {
    PatientData* EP_Patients = new PatientData[N0_0f_Patients]; // where SIZE is the number of PatientData objects
    int counter = 0 ;
    int array_counter = 0 ;
    if (PatientObj.CaseType == "EP") {
        EP_Patients[array_counter] = PatientObj;
        array_counter++;
        // EP->Enqueue(PatientData) ;
        counter++;
    }
        
    if (PatientObj.CaseType == "NP") {NP->Enqueue(PatientObj); counter++;} 
    if (PatientObj.CaseType == "SP") {SP->Enqueue(PatientObj) ; counter++;}
    if (counter == N0_0f_Patients) {
        //Sort the patients array
        //Push the objects of the array into the queue after sorting
        //I think it's easier but it takes high memory
        Sort_EP_Patients_Array(&EP_Patients , 0 , array_counter);
            
        for (int i = array_counter ; -1 > i<= array_counter ; i--) {
            EP->Enqueue(EP_Patients[i]);
            // delete EP_Patients[i]; not working properly
    
        }
        cout<<"EP Patients are sorted and pushed successfully to the queue!\n";
    
        delete[] EP_Patients;
    }
}


PatientData* PatientQueue:: Get_A_Patient() {
    if (! EP->IsEmpty()){
        EP->get_most_front_one();
        EP->Dequeue();
    }
    if (! SP->IsEmpty()) {
        SP->get_most_front_one();
        SP->Dequeue();
    }
    if (! NP->IsEmpty()) {
        NP->get_most_front_one();
        NP->Dequeue();
    }
    else {
        throw out_of_range("No Patients Al Hamdullilah !");
    }
}

void PatientQueue::Sort_EP_Patients_Array(PatientData* Patientsarray[] , int  beginning , int ending) {
    if (ending<beginning) {
        throw exception();
    }
    int pivot = Partition(Patientsarray , beginning , ending);
    Sort_EP_Patients_Array(Patientsarray , beginning , pivot-1);
    Sort_EP_Patients_Array(Patientsarray , pivot+1 , ending);

}

int PatientQueue::Partition(PatientData* Patientsarray[] , int  beginning , int ending) {
    int pivot = Patientsarray[ending]->CaseSeverity;
    int i = beginning-1 ;
    for (int j = beginning ; j <=ending ;j++ ) {
        if (Patientsarray[j]->CaseSeverity<pivot){
            i++;
            PatientData * temp = Patientsarray[i] ;
            Patientsarray[i] = Patientsarray[j];
            Patientsarray[j] = temp ;
        }
    }
    i++;
    PatientData * temp = Patientsarray[i] ;
    Patientsarray[i] = Patientsarray[ending];
    Patientsarray[ending] = temp ;

    return i ;
}

PatientQueue::PatientQueue() {
    SP = new queue<PatientData>;
    EP = new queue<PatientData>;
    NP = new queue<PatientData>;
}

PatientQueue::~PatientQueue() {
    SP->ClearQueue();
    EP->ClearQueue();
    NP->ClearQueue();
    delete SP;
    delete NP;
    delete EP;
}
