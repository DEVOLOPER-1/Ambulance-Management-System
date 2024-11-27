#pragma once
#include "../Includes/Hospital.h"
#include "../Includes/Organizer.h"

void Hospital::send(Car* car)
{
	ORG->receive(car);
}

Hospital::Hospital(int ID, int NumberOFsCars, int NumberOFnCars, const int ScarSpeed, const int NcarSpeed) : ID(ID), EP_Requests(), NP_Requests(), SP_Requests(), sCars(), nCars()
{
	for (int i = 0; i < NumberOFsCars; i++)
		sCars.enqueue(new Car("SC", ScarSpeed, this->ID, i +1)); // We will handle car speed later

	for (int i = 0; i < NumberOFnCars; i++)
		nCars.enqueue(new Car("NC", NcarSpeed, this->ID, i +1)); // We will handle car speed later
}

void Hospital::receive(Request* request)
{
	if (request->getPatientType() == "NP")
		NP_Requests.enqueue(request);

	else if (request->getPatientType() == "SP")
		SP_Requests.enqueue(request);

	else
		EP_Requests.enqueue(request, request->getSeverity());
}

void Hospital::handleRequests(int timestep)
{
	int priority;
	Request* request;
	Car* car;
	while (EP_Requests.peek(request, priority) && (nCars.peek(car) || sCars.peek(car)))
	{
		EP_Requests.dequeue(request, priority);
		nCars.peek(car) ? nCars.dequeue(car) : sCars.dequeue(car);
		car->assign(timestep, request);
		send(car);
		// if there is a request the hospital should report it to the organizer --|><| S O O N |><|--
	}
	while (SP_Requests.peek(request) && sCars.peek(car))
	{
		SP_Requests.dequeue(request);
		sCars.dequeue(car);
		car->assign(timestep, request);
		send(car);
	}
	while (NP_Requests.peek(request) && nCars.peek(car))
	{
		NP_Requests.dequeue(request);
		nCars.dequeue(car);
		car->assign(timestep, request);
		send(car);
	}
}

void Hospital::receive(Car* car)
{
	// handling car status will be done in the organizer --|><| S O O N |><|--
	if (car->getCarType() == "SC")
		sCars.enqueue(car);
	else
		nCars.enqueue(car);
}

void Hospital::print()
{
	cout << "\n============== Hospital #" << ID << " data ==============\n";
	cout << EP_Requests.GetMembersCount() << " EP Requests";
	if (EP_Requests.GetMembersCount())
	{
		cout << ": ";
		EP_Requests.print();
	}

	cout << "\n" << NP_Requests.GetMembersCount() << " NP Requests";
	if (NP_Requests.GetMembersCount())
	{
		cout << ": ";
		NP_Requests.print();
	}

	cout << "\n" << SP_Requests.GetMembersCount() << " SP Requests";
	if (SP_Requests.GetMembersCount())
	{
		cout << ": ";
		SP_Requests.print();
	}

	cout << "\nFree Cars: " << sCars.GetMembersCount() << " SCars, " << nCars.GetMembersCount() << " NCars";

	cout << "\n============ Hospital #" << ID << " data end ============\n";
}

int Hospital::GetHospitalID() const{
	return ID;
}

int Hospital::GetEPRequestsCount() {
	return EP_Requests.GetMembersCount();
}
int Hospital::GetNPRequestsCount() {
	return NP_Requests.GetMembersCount();
}
int Hospital::GetSPRequestsCount() {
	return SP_Requests.GetMembersCount();
}


