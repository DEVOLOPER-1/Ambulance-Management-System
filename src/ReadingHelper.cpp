#include "../Includes/ReadingHelper.h"


ReadingHelper* ReadingHelper::instance = nullptr;

ReadingHelper* ReadingHelper::getInstance()
{

    if (instance == nullptr)
        instance = new ReadingHelper();
    return instance;
}

void ReadingHelper::Build2DMatrix_and_HospitalsArray(int& token)
{
    // Allocate memory for the 2D matrix
    HospitalsArray = new Hospital[token]();
    DistancesMatrix = new int* [token];
    for (int i = 0; i < token; i++) {
        DistancesMatrix[i] = new int[token];
    }
}

void ReadingHelper::SetNoOfHospitals(int& Counts)
{
    HospitalsCount = Counts;
    Build2DMatrix_and_HospitalsArray(HospitalsCount);
}

void ReadingHelper::Tokenizer(string& line, int& SectionNumber)
{
    string token;
    istringstream stream(line);
    char delimiter{ ' ' };
    if (SectionNumber == 0) {
        while (getline(stream, token, delimiter)) {
            cout << "Token"
                << " -> " << token << endl;
            int distance = stoi(token);
            cout << distance << " -> " << row << col << endl;
            DistancesMatrix[row][col] = distance;
            col++;
            if (col == HospitalsCount) {
                col = 0;
                row++;
            }
        }
    }
    else if (SectionNumber == -1) {
        int count = 0;
        while (getline(stream, token, delimiter)) {
            if (count == 0) {
                SpecialCarSpeed = stoi(token);
                cout << "SpecialCarSpeed -> " << SpecialCarSpeed << endl; ;
                count += 1;
            }
            else if (count == 1) {
                NormalCarSpeed = stoi(token);
                cout << "NormalCarSpeed -> " << NormalCarSpeed << endl; ;
            }


        }
    }

    else if (SectionNumber == 1) {
        int counter = 0;
        int ScarNumber = 0;
        int NcarNumber = 0;
        while (getline(stream, token, delimiter)) {
            if (counter % 2 == 0) {
                cout << "Scars " << token << endl;

                ScarNumber = stoi(token);
                counter++;
            }
            else {
                cout << "Ncars " << token << endl;

                NcarNumber = stoi(token);
                counter++;
                HospitalsArray[HospitalsCounter] = Hospital(HospitalsCounter, ScarNumber, NcarNumber, SpecialCarSpeed, NormalCarSpeed);
                HospitalsCounter++;

            }

        }
    }
}


