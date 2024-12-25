//
// Created by youss on 17-Nov-24.
//

#pragma once
#include <string>
#include "Car.h"
#include "Hospital.h"
#include "ReadingHelper.h"
#include <fstream>
#include "../ds/Stack.h"
#include"UI.h"
#define ORG Organizer::GetInstance()
using namespace std;



class Organizer {
private:
    ifstream InputFile;
    string FileName;
	int** hospitals_distances;
	int HospitalsCount;
	int Total_EP_Patients_in_AllHospitals;
	int Total_SP_Patients_in_AllHospitals;
	int Total_NP_Patients_in_AllHospitals;
	int CancellationsCount;
	int Total_S_Cars_in_AllHospitals;
	int Total_N_Cars_in_AllHospitals;
	int TotalSimulationTime;
	Hospital** hospitals;
	LinkedQueue<Request*> requests;
	LinkedQueue<Request*> finishedRequests;
	SpecialLinkedQueue<CancellationRequest*> cancellations;
	priQueue<Car* > outCars;
    priQueue<Car* > backCars;
	static Organizer* instance;  /// Singleton Design Pattern

	int variableIndex;
	int index;
	bool running;
	bool silentMode;

private:
	Organizer();

	Organizer(const Organizer& other) = delete;

	struct I_H_M_R {
		int min_index;
		int * collisioned_Hospitals_indices;
		int CollisionsCount;
	};
	I_H_M_R GetI_H_M_R(int * array , int length); // ALias ===>    index of Hospital With Min Requests = I_H_M_R

	void collectStatistics();

    // methods to handle cars
    void sendBack();

    void returnCar();

	template<typename T>
	void produceOutputFile(bool IsPatientArray , T (& array)[4] , int CallCounter) {
		fstream OutputFile;
		if (CallCounter == 0) {
			OutputFile.open("E:\\Coding\\C++\\Ambulance-Management-System\\OutputFile.txt", ios::out); //write mode
		}
		else
			OutputFile.open("E:\\Coding\\C++\\Ambulance-Management-System\\OutputFile.txt", ios::app); //write mode
		if (OutputFile.is_open()){
			if (IsPatientArray) {
				if ( CallCounter == 0) {
					OutputFile << "FT" << " " << "PatientID" << " " << "QT" << " " << "WT" << endl<<endl;
					OutputFile << array[0] << " " << array[1] << " " << array[2] << " " << array[3] << endl;

				}
				OutputFile << array[0] << " " << array[1] << " " << array[2] << " " << array[3] << endl;
			}
			else {
				OutputFile<<endl;
				OutputFile <<"Patients: "<< (Total_EP_Patients_in_AllHospitals + Total_NP_Patients_in_AllHospitals + Total_SP_Patients_in_AllHospitals) 
				<<" [EP: " << Total_EP_Patients_in_AllHospitals << ", SP: " << Total_SP_Patients_in_AllHospitals << ", NP: " << Total_NP_Patients_in_AllHospitals << "]" << endl;

				OutputFile <<"Hospitals: "<< HospitalsCount <<endl;

				OutputFile <<"Cars: "<< Total_N_Cars_in_AllHospitals+Total_S_Cars_in_AllHospitals <<" [Scars: "<<Total_S_Cars_in_AllHospitals<<", Ncars: "<<Total_N_Cars_in_AllHospitals<<"]"<<endl;

				OutputFile<<"Average Waiting Time: "<< array[0] << endl;
				OutputFile<<"Average Cars Busyness Time: "<< array[1] << endl;
				OutputFile<<"Average Utilization: "<< array[2] << "%" << endl;
			}
		}
		OutputFile.close();
	}

public:
    static Organizer* GetInstance();

	void setHospital( Hospital** &HospitalsArray);
	void SetHospitalsDistances( int ** &hospitals_distances);
	void SetHospitalsCount(int HospitalsCount);
	void setRequests( LinkedQueue<Request*> &requests);
	void setCancellationRequests( SpecialLinkedQueue<CancellationRequest*> &CancellationRequests );
	void SetPatientsCount(int * PatientsCount);
	void SetCancellationsCount(int CancellationsCount);
	void setTotalCars_in_AllHospitals(int Total_S_Cars_in_AllHospitals , int Total_N_Cars_in_AllHospitals);
	void runSimulation();
	bool isSimulationComplete();  // Method to check if the simulation is done


	// methods to print data
	void printCars();

	void printFinishedRequests();

	void print();

	Hospital* getHospital(int index); // test sample for phase 1.2

	void handleCancellations(int timeStep); //method to handle cancellations
	
	// methods to handle requests
    void distributeRequests(int timeStep);

	// Methods to handle hospitals
	void handleHospitals(int timeStep);

	// methods to handle cars
	void handleCars(int timeSteps);

    void receive(Car* car);

	// methods to handle input file (Scenario)
	void getProgramMode();

    void loadInputFile();
	
	void ReAssignBetterHospital(Request* request);
	void SetDataMembersValues();

	// methods to handle output file
	void getInputs();
	
	void removeLastTimestep();

	// methods to run the program
	void run();

};

