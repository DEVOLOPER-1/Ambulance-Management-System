#include "../Includes/UI.h"
#include "../Includes/Organizer.h"

void UI::display(int timestep)
{
	DisplayTimestep(timestep);
	ORG->getHospital(0)->print();
	ORG->print();
	cout << endl;
}

void UI::DisplayTimestep(int timestep)
{
    cout << setw(120) << setfill('#') << "" << endl;
    cout << "Timestep: " << timestep << endl;

}

