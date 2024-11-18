#include <iostream>
#include <thread>
#include <climits>
#include "Includes/Car.h"
#include "Includes/Request.h"
#include "Includes/Organizer.h"
using namespace std;


int main()
{

	Organizer Organize;
	Organize.loadInputFile();
	// int timestep = 0;
	// Request* request = new Request(3, 150);
	// Car car(50);
	// while (++timestep <= 10) {
	// 	cout << "Timestep: " << timestep << endl;
	// 	car.work(request, timestep);
	//
	// 	this_thread::sleep_for(2s);  
	// 	//for (unsigned long i = 0; i < ULONG_MAX; i++) {}
	// 	cout << "\n====================" << endl;
	// }
	// delete request;
}