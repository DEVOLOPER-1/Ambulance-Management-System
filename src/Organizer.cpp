#pragma once
#include "../Includes/Organizer.h"
#include <iostream>
using namespace std;

Organizer* Organizer::instance = nullptr;

Organizer* Organizer::GetInstance()
{
    if (!instance) instance = new Organizer();
    return instance;
}

void Organizer::setHospital(Hospital *&HospitalsArray) {
    this->hospitals = HospitalsArray;
}

void Organizer::setRequests(LinkedQueue<Request> *&requests) {
    this->requests = requests;
}

void Organizer::setCancellationRequestQ(LinkedQueue<CancellationRequest> *&CancellationRequests) {
    this->cancellations = CancellationRequests ;
}
void Organizer::SetHospitalsCount(int HospitalsCount) {
    this->HospitalsCount = HospitalsCount;
}
void Organizer::SetCancellationsCount(int CancellationsCount) {
    this->CancellationsCount = CancellationsCount;
}
void Organizer::SetPatientsCount(int PatientsCount) {
    this->PatientsCount = PatientsCount;
}

void Organizer::SetHospitalsDistances(int **&hospitals_distances) {
    this->hospitals_distances = hospitals_distances;
}


// private methods
void Organizer::sendBack()
{
    Car* car;
    int pri;
    outCars.dequeue(car, pri);
    car->pickUp();
    backCars.enqueue(car, -(car->getDroppedOffTime()));
}

void Organizer::returnCar()
{
    Car* car;
    int pri;
    backCars.dequeue(car, pri);
    car->dropOff();
    hospitals[car->getHospitalID() - 1].receive(car);
}

// public methods
void Organizer::distributeRequests(int timeStep)
{
	// if (requests.isEmpty()) return;
	Request* request;
	while (requests->peek(*request) && request->getRequestTime() == timeStep) 
    {
		requests->dequeue(*request);
		int HospitalID = request->getNearestHospital();
		hospitals[HospitalID - 1].receive(request);
	}
}

void Organizer::handleCars(int timeSteps)
{
	// sendRequests(timeSteps);
	Car* car;
	int pri;
    cout << "\nOut Cars: ";
	outCars.print();
	cout << "\nBack Cars: ";
	backCars.print();

    while (outCars.peek(car, pri) && (car->getPickedUpTime() == timeSteps))
    {
        sendBack();
    }
    while (backCars.peek(car, pri) && (car->getDroppedOffTime() == timeSteps))
	{
		returnCar();
	}
}

void Organizer::receive(Car* car) { outCars.enqueue(car, -(car->getPickedUpTime())); }

void Organizer::loadInputFile()
{
    cout << "Reading File....." << endl;
    this->InputFile.open(FileName);
    if (!InputFile.is_open()) {
        cout << "Failed Opening!" << endl;
        return;
    }

    string line;
    int sectionCounter = -1;

    while (getline(InputFile, line)) {

        if (line.empty()) {
            sectionCounter++;
            cout << "Section Counter -> " << sectionCounter << endl;
            continue;
        }

        if (sectionCounter == 0) {
            cout << "DISTANCE_MATRIX" << endl;
            RH->Tokenizer(line, sectionCounter);
            cout << line << endl;
        }
        else if (sectionCounter == 1) {
            cout << "CAR_DISTRIBUTION" << endl;
            RH->Tokenizer(line, sectionCounter);
            // cout << line << endl;
        }
        else if (sectionCounter == 2) {
            cout << "REQUESTS" << endl;
            RH->Tokenizer(line , sectionCounter);
            // cout << line << endl;
        }
        else if (sectionCounter == 3) {
            cout << "CANCELLATIONS" << endl;
            RH->Tokenizer(line , sectionCounter);
        }
        else {
            cout << line.length() << " -> " << line << endl;
            if (line.length() <= 2) {
                int Hospitals;
                Hospitals = stoi(line);
                cout << "Hospitals Count -> " << Hospitals << endl;
                RH->SetNoOfHospitals(Hospitals);
            }
            else {
                int sec = -1;
                cout << "Cars Speeds -> " << line << endl;
                RH->Tokenizer(line, sec);
            }

        }
    }
    SetDataMembersValues();
    InputFile.close();
    cout << "File Reading Completed." << endl;
}

void Organizer::SetDataMembersValues() {
    setHospital(RH->GetHospitalsArray());
    setRequests(RH->GetRequestsQueue());
    setCancellationRequestQ(RH->GetCancellationRequestsQueue());
    SetHospitalsDistances(RH->GetDistancesMatrix());
    SetHospitalsCount(RH->GetNoOfHospitals());
    SetPatientsCount(RH->GetNoOfPatients());
    SetCancellationsCount(RH->GetNoOfCancellations());
    cout<<"All Organizer Data Members are done !"<<endl;
    
}

// Request* Organizer::GenerateRequests(int timeStep) {
//     LinkedList<Request> *temp=  RH->GetRequestsLinkedList();
//     Request* temp_request =  temp->TraverseReuests(timeStep);
//     if (temp_request->getPickupTime() ==timeStep) {
//         
//     }
// }