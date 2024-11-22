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

void Organizer::receive(Car* car) { outCars.enqueue(car); }

void Organizer::sendBack()
{
	Car* car;
	outCars.dequeue(car);
	backCars.enqueue(car);
}

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
            cout << line << endl;
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

    InputFile.close();
    cout << "File Reading Completed." << endl;
}
