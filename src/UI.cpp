#include "../Includes/UI.h"
#include "../Includes/Organizer.h"

void UI::display(int timestep, int index)
{
	DisplayTimestep(timestep);
	ORG->getHospital(index)->print();
	ORG->print();
	cout << endl;
}

void UI::DisplayTimestep(int timestep)
{
    cout << setw(120) << setfill('#') << "" << endl;
    cout << "Timestep: " << timestep << endl;

}

