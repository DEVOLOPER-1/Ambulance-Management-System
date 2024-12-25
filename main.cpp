
#include <iostream>
#include <thread>
#include <climits>
#include "Includes/Car.h"
#include "Includes/Request.h"
#include "Includes/Organizer.h"
using namespace std;

bool getProgramMode(){
	char answer;
	cout << "Please choose the way the Output file will be displayed\n(Y or y) for time step simulation\n(N or n) for silent mode: ";
	cin >> answer;
	while(answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n'){
			cout << "Invalid input, please enter (Y) for time step simulation, (N) for silent mode: ";
			cin >> answer;
	}
	if(answer == 'Y' || answer == 'y'){
			return false;
		}
		else
		{
			return true;
		}
	}


int main()
{
	ORG->loadInputFile();
	bool SilentMode = getProgramMode();


	//// Example: Manual testing of `cancelRequestAndReturnCar`
	//int testPatientID;
	//cout << "Enter a Patient ID to cancel their request and return the associated car: ";
	//cin >> testPatientID;
	//ORG->cancelRequestAndReturnCar(testPatientID);

	//Automated Testing


	ORG->runSimulation(SilentMode);
	

	//Hospital* hospitals[2];
	//hospitals[0] = new Hospital(1, 2, 2, 3, 2);
	//hospitals[1] = new Hospital(2, 2, 2, 3, 2);

	// ORG->setHospital(*hospitals);
	//
	// LinkedQueue<Request*> requests;
	// // dummy requests
	// requests.enqueue(new Request("NP", 2, 1, 1, 5));
	// requests.enqueue(new Request("SP", 3, 2, 1, 7));
	// requests.enqueue(new Request("EP", 4, 3, 1, 9, 3));
	// requests.enqueue(new Request("NP", 5, 4, 1, 5));
	// requests.enqueue(new Request("SP", 5, 5, 1, 7));
	// requests.enqueue(new Request("EP", 6, 6, 2, 9, 9));
	// requests.enqueue(new Request("NP", 7, 7, 2, 5));
	// requests.enqueue(new Request("SP", 8, 8, 2, 7));
	// requests.enqueue(new Request("EP", 9, 9, 2, 9, 6));
	// requests.enqueue(new Request("NP", 9, 10, 2, 5));
	// ORG->setRequests(requests);
	
	//int timestep = 0;
	//while (++timestep <= 100)
	//{
	//	cout << "Timestep: " << timestep << endl;
	//	ORG->distributeRequests(timestep);
	//	ORG->handleHospitals(timestep);
	//	if(timestep == 13)
	//		cout << "here\n";
	//	ORG->handleCars(timestep);
	//	
	//	//this_thread::sleep_for(2s);
	//	cout << "\n====================" << endl;
	//}
}


// deprecated
	/*

	*/