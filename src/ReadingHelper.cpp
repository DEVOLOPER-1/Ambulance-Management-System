#include "../Includes/ReadingHelper.h"
#include "../ds/LinkedList.h"
ReadingHelper* ReadingHelper::instance = nullptr;

ReadingHelper* ReadingHelper::getInstance()
{

    if (instance == nullptr)
        instance = new ReadingHelper();
    return instance;
}


void ReadingHelper::Build2DMatrix_and_HospitalsArray(int token)
{
    // Allocate memory for the 2D matrix
    HospitalsArray = new Hospital[token]();
    DistancesMatrix = new int* [token];
    for (int i = 0; i < token; i++) {
        DistancesMatrix[i] = new int[token];
    }
}

void ReadingHelper::SetNoOfHospitals(int Counts)
{
    HospitalsCount = Counts;
    Build2DMatrix_and_HospitalsArray(HospitalsCount);
}

void ReadingHelper::Tokenizer(string& line, int SectionNumber) {
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



    else if (SectionNumber == 2) {
        int TokenCounter = 0;

        while (getline(stream, token, delimiter)) {
            if (line.length() < 3) {
                    NoOfPatients = stoi(token);  // Safely convert to integer
            }
            else {
                if (!token.empty()) {

                    if (TokenCounter < 6) {

                        cout << TokenCounter << " -> " << token << endl;
                        PatientDataArray[TokenCounter] = token;
                        TokenCounter++;
                    }
                    if ((PatientDataArray[0] == "EP" && TokenCounter == 6)|| (PatientDataArray[0] != "EP"&&TokenCounter==5)) {
                        // Ensure that we have enough data to create a request
                            if (PatientDataArray[0] == "EP") {
                                Request* temp = new Request(
                                    PatientDataArray[0],
                                    stoi(PatientDataArray[1]),
                                    stoi(PatientDataArray[2]),
                                    stoi(PatientDataArray[3]),
                                    stoi(PatientDataArray[4]),
                                    stoi(PatientDataArray[5])
                                );
                                Requests->enqueue(*temp);
                                cout << "Catched in EP\n";
                            }
                            else if (PatientDataArray[0] == "NP") {
                                Request* temp = new Request(
                                    PatientDataArray[0],
                                    stoi(PatientDataArray[1]),
                                    stoi(PatientDataArray[2]),
                                    stoi(PatientDataArray[3]),
                                    stoi(PatientDataArray[4])
                                );
                                Requests->enqueue(*temp);
                                cout << "Catched in NP\n";
                            }
                            else if (PatientDataArray[0] == "SP") {
                                Request* temp = new Request(
                                    PatientDataArray[0],
                                    stoi(PatientDataArray[1]),
                                    stoi(PatientDataArray[2]),
                                    stoi(PatientDataArray[3]),
                                    stoi(PatientDataArray[4])
                                );
                                Requests->enqueue(*temp);
                                cout << "Catched in SP\n";
                            }
                        }

                    }
                }
            }
        }
    else if(SectionNumber == 3) {
        int counter = 0;
        int CRTime = 0;
        int CRId = 0;
        while(getline(stream , token , delimiter)) {
            if (line.length()<=2) NoOfCancellations = stoi(token);
            else {

                if (counter%2 == 0) {
                    CRTime = stoi(token);
                    counter++;
                }
                else{
                    CRId = stoi(token);
                    cout<<"Time "<<CRTime<<" ID "<<CRId<<endl;
                    CancellationRequest* temp = new CancellationRequest(CRTime , CRId);
                    CancellationRequests->enqueue(*temp);
                    cout<<"Time "<<temp->GETTime()<<" ID "<<temp->GetPID()<<endl;

                    cout<<"Catched in the list"<<endl;
                }
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




int **  &ReadingHelper::GetDistancesMatrix() {return DistancesMatrix;}
Hospital* &ReadingHelper::GetHospitalsArray() {return HospitalsArray;}
int ReadingHelper::GetScarSpeed() const{return SpecialCarSpeed;}
int ReadingHelper::GetNcarSpeed() const{return NormalCarSpeed;}
LinkedQueue<Request>* &ReadingHelper::GetRequestsQueue() {return Requests;}
LinkedQueue<CancellationRequest>* &ReadingHelper::GetCancellationRequestsQueue() {return CancellationRequests;}
int ReadingHelper::GetNoOfCancellations() const {
    return NoOfCancellations;
}
int ReadingHelper::GetNoOfHospitals() const {
    return HospitalsCount;
}
int ReadingHelper::GetNoOfPatients() const {
    return NoOfPatients;
}

