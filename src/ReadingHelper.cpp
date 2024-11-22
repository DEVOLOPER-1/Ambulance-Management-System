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
    RH->HospitalsCount = Counts;
    RH->Build2DMatrix_and_HospitalsArray(HospitalsCount);
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
            cout << distance << " -> " << RH->row << RH->col << endl;
            RH->DistancesMatrix[RH->row][RH->col] = distance;
            RH->col++;
            if (RH->col == RH->HospitalsCount) {
                RH->col = 0;
                RH->row++;
            }
        }
    }
    else if (SectionNumber == -1) {
        int count = 0;
        while (getline(stream, token, delimiter)) {
            if (count == 0) {
                RH->SpecialCarSpeed = stoi(token);
                cout << "SpecialCarSpeed -> " << RH->SpecialCarSpeed << endl; ;
                count += 1;
            }
            else if (count == 1) {
                RH->NormalCarSpeed = stoi(token);
                cout << "NormalCarSpeed -> " << RH->NormalCarSpeed << endl; ;
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
                HospitalsArray[RH->HospitalsCounter] = Hospital(RH->HospitalsCounter, ScarNumber, NcarNumber, RH->SpecialCarSpeed, RH->NormalCarSpeed);
                RH->HospitalsCounter++;

            }
    
        }
    }

    else if(SectionNumber==2) {
        string PatientDataArray[6];
        int TokenCounter = 0 ;
        while (getline(stream , token , delimiter)) {
                if (TokenCounter<6) {
                    cout<<TokenCounter<<" -> "<<token<<endl;
                    PatientDataArray[TokenCounter] = token ;
                    TokenCounter++;
                }
        }
    }
}


void ReadingHelper:: DeleteMatrix(int ** Matrix2D , int rows) {
    if (Matrix2D) {
        for (int i = 0; i < rows; ++i) {
            delete[] Matrix2D[i];
        }
        delete[] Matrix2D;
    }
}


void ReadingHelper::DeleteMatrix( Hospital*array) {
    if (array) 
            delete [] array;
        
    }

