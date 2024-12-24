#pragma once
#include "../Includes/Organizer.h"
#include <iostream>
#include<thread>

using namespace std;

Organizer* Organizer::instance = nullptr;

Organizer* Organizer::GetInstance()
{
    if (!instance) instance = new Organizer();
    return instance;
}

void Organizer::setHospital(Hospital **&HospitalsArray) {
    this->hospitals = HospitalsArray;
}

void Organizer::setRequests(LinkedQueue<Request*> &requests) {
    this->requests = requests;
}

void Organizer::setCancellationRequestQ(LinkedQueue<CancellationRequest*> &CancellationRequests) {
    this->cancellations = CancellationRequests ;
}
void Organizer::SetHospitalsCount(int HospitalsCount) {
    this->HospitalsCount = HospitalsCount;
}
void Organizer::SetCancellationsCount(int CancellationsCount) {
    this->CancellationsCount = CancellationsCount;
}

void Organizer::setTotalCars_in_AllHospitals(int TotalCars_in_AllHospitals) {
    this->TotalCars_in_AllHospitals = TotalCars_in_AllHospitals;
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
    Request* request;
    Car* car;
    int pri;
    backCars.dequeue(car, pri);
    car->dropOff(request);
    finishedRequests.enqueue(request);
    hospitals[car->getHospitalID() - 1]->receive(car);
}


void Organizer::printCars()
{
	cout << "----------------------------------------------" << endl;
	cout << outCars.GetMembersCount() << " ==> Out Cars";
	if (outCars.GetMembersCount())
	{
		cout << ": ";
		outCars.print();
	}
    cout << "\n" << backCars.GetMembersCount() << " <== Back Cars";
    if (backCars.GetMembersCount())
    {
		cout << ": ";
		backCars.print();
    }
	cout << "\n----------------------------------------------" << endl;
}

void Organizer::printFinishedRequests()
{
	cout << finishedRequests.GetMembersCount() << " Finished Requests";
	if (finishedRequests.GetMembersCount())
	{
		cout << ": ";
		finishedRequests.print();
	}
	cout << endl;
}

void Organizer::print()
{
	printCars();
	printFinishedRequests();
}

Hospital* Organizer::getHospital(int index)
{
	return hospitals[index];
}

// public methods
void Organizer::distributeRequests(int timeStep)
{
	// if (requests.isEmpty()) return;
	Request* request;
	while (requests.peek(request) && request->getRequestTime() == timeStep) 
    {
		requests.dequeue(request);
		int HospitalID = request->getNearestHospital();
		hospitals[HospitalID - 1]->receive(request);
	}
}
void Organizer::runSimulation() {
    int timestep = 1; 
    UI ui;
    cout << "Simulation Starts...\n";

    while (true) { 
        // cout << "\nCurrent Timestep: " << timestep << endl;

        //ui.DisplayTimestep(timestep);
        //ui.DisplayHospital(hospitals[1]);

        distributeRequests(timestep);

		ui.display(timestep);

        handleHospitals(timestep);
       
        handleCars(timestep);

        
        this_thread::sleep_for(5s);

        
        if (isSimulationComplete()) {TotalSimulationTime = timestep;  break;}

        timestep++;
    }

   
}

bool Organizer::isSimulationComplete() {
    // Check if all requests are processed and no cars are in transit
    return finishedRequests.GetMembersCount() == PatientsCount;
}


void Organizer::handleHospitals(int timeStep)
{
    for (int i = 0; i < this->HospitalsCount; i++)
        hospitals[i]->handleRequests(timeStep);
}

void Organizer::handleCars(int timeSteps)
{
	// sendRequests(timeSteps);
	Car* car;
	int pri;

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
            // cout << "Section Counter -> " << sectionCounter << endl;
            continue;
        }

        if (sectionCounter == 0) {
            // cout << "DISTANCE_MATRIX" << endl;
            RH->Tokenizer(line, sectionCounter);
            // cout << line << endl;
        }
        else if (sectionCounter == 1) {
            // cout << "CAR_DISTRIBUTION" << endl;
            RH->Tokenizer(line, sectionCounter);
            // cout << line << endl;
        }
        else if (sectionCounter == 2) {
            // cout << "REQUESTS" << endl;
            RH->Tokenizer(line , sectionCounter);
            // cout << line << endl;
        }
        else if (sectionCounter == 3) {
            // cout << "CANCELLATIONS" << endl;
            RH->Tokenizer(line , sectionCounter);
        }
        else {
            // cout << line.length() << " -> " << line << endl;
            if (line.length() <= 2) {
                int Hospitals;
                Hospitals = stoi(line);
                // cout << "Hospitals Count -> " << Hospitals << endl;
                RH->SetNoOfHospitals(Hospitals);
            }
            else {
                // cout << "Cars Speeds -> " << line << endl;
                RH->Tokenizer(line, sectionCounter);
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
    setTotalCars_in_AllHospitals(RH->GetTotalCars_in_AllHospitals());
    // RH->
    //cout<<"All Organizer Data Members are done !"<<endl;
    
}

Organizer::I_H_M_R Organizer::GetI_H_M_R(int *array, int length) {
    I_H_M_R ihmr;
    int min = INT_MAX;
    ihmr.min_index = 0;
    ihmr.CollisionsCount = 0;
    ihmr.collisioned_Hospitals_indices = new int[length];
    for (int i = 0; i < length; i++) {
        if (array[i] < min) {
            min = array[i];
            ihmr.min_index = i;
            ihmr.CollisionsCount = 0; // reset collisions count
        } else if (array[i] == min) {
            ihmr.collisioned_Hospitals_indices[ihmr.CollisionsCount] = i;
            ihmr.CollisionsCount++;
        }
    }
    if (ihmr.CollisionsCount > 0 ) ihmr.min_index = -1 ;
    return ihmr;
}


void Organizer::ReAssignBetterHospital(Request *request) {
    int CurrentAssignedHospitalID = request->getNearestHospital() -1 ; // zero based indexing as r. is counting from 1  // Alias OldAssignedHospitalID = C_A_H_I_D
    int * DistancesAwayOfC_A_H_I_D = hospitals_distances[CurrentAssignedHospitalID];
    int * EpRequestsCountsForEachHospital = new int[HospitalsCount]; //iam not considering the hospital we are in already

    for (int i = 0 ; i<HospitalsCount ; i++) {
        if (DistancesAwayOfC_A_H_I_D[i] == 0 || i == CurrentAssignedHospitalID) {
            EpRequestsCountsForEachHospital[i] = INT_MAX; 
            continue;
        }
        EpRequestsCountsForEachHospital[i] = hospitals[i]->GetEPRequestsCount();
    }
    
    I_H_M_R result = GetI_H_M_R(EpRequestsCountsForEachHospital , HospitalsCount-1);

    if (result.min_index!= -1)
        hospitals[result.min_index]->receive(request);

    else {
        int nearest_hospital = -1;
        int min_distance = INT_MAX;

        for (int j = 0; j < result.CollisionsCount; j++) {
            int hospital_index = result.collisioned_Hospitals_indices[j];
            if (DistancesAwayOfC_A_H_I_D[hospital_index] < min_distance) {
                min_distance = DistancesAwayOfC_A_H_I_D[hospital_index];
                nearest_hospital = hospital_index;
            }
        }
        if (nearest_hospital != -1) {
            hospitals[nearest_hospital]->receive(request);
        }
    }
    delete[] EpRequestsCountsForEachHospital;
    delete[] result.collisioned_Hospitals_indices;
}

void Organizer::collectStatistics() {
    cout << "Collecting Statistics..." << endl;
    int total_waiting_time = 0;
    int total_busy_time = 0;
    Request* request;
    LinkedQueue<Request*> temp_queue = finishedRequests;
    while (!temp_queue.isEmpty()) {
        temp_queue.dequeue(request);
        Logger* logger = request->GetLogger();
        total_waiting_time += logger->getWT();
        total_busy_time += logger->getBusynessTime();
    }
    int avgWaitingTime = total_waiting_time / PatientsCount;
    int avgCarsBusynessTime = total_busy_time / TotalCars_in_AllHospitals ;
    int average_utilization = (avgCarsBusynessTime / TotalSimulationTime)*100;
    cout << "Statistics Collected." << endl;
}

// Request* Organizer::GenerateRequests(int timeStep) {
//     LinkedList<Request> *temp=  RH->GetRequestsLinkedList();
//     Request* temp_request =  temp->TraverseReuests(timeStep);
//     if (temp_request->getPickupTime() ==timeStep) {
//         
//     }
// }