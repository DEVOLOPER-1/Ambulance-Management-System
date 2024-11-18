#include <iostream>
#include <thread>
#include <climits>
#include "Includes/Car.h"
#include "Includes/Request.h"
using namespace std;


int main()
{
	int timestep = 0;
	Request* request = new Request("Patient", 0, 1, 1, 10, 5); // (PatientType, RequestTime, PatientID, NearestHospital, distance, severity
	Car car(50);
	while (++timestep <= 10) {
		cout << "Timestep: " << timestep << endl;
		car.work(request, timestep);

		this_thread::sleep_for(2s);  
		//for (unsigned long i = 0; i < ULONG_MAX; i++) {}
		cout << "\n====================" << endl;
	}
	delete request;
}