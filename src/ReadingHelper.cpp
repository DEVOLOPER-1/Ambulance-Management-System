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
    HospitalsArray = new Hospital*[token+1];
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
            // cout << "Token"
            //     << " -> " << token << endl;
            int distance = stoi(token);
            // cout << distance << " -> " << row << col << endl;
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
                // cout << "SpecialCarSpeed -> " << SpecialCarSpeed << endl; ;
                count += 1;
            }
            else if (count == 1) {
                NormalCarSpeed = stoi(token);
                // cout << "NormalCarSpeed -> " << NormalCarSpeed << endl; ;
            }


        }
    }

    else if (SectionNumber == 1) {
        int counter = 0;
        int ScarNumber = 0;
        int NcarNumber = 0;
        while (getline(stream, token, delimiter)) {
            if (counter % 2 == 0) {
                // cout << "Scars " << token << endl;

                ScarNumber = stoi(token);
                Total_S_Cars_in_AllHospitals += ScarNumber ;
                counter++;
            }
            else {
                // cout << "Ncars " << token << endl;

                NcarNumber = stoi(token);
                counter++;
                Total_N_Cars_in_AllHospitals += NcarNumber;
                HospitalsArray[HospitalsCounter] = new Hospital(
                    HospitalsCounter + 1,
                    ScarNumber,
                    NcarNumber,
                    SpecialCarSpeed,
                    NormalCarSpeed);
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

                        // cout << TokenCounter << " -> " << token << endl;
                        PatientDataArray[TokenCounter] = token;
                        TokenCounter++;
                    }
                    if ((PatientDataArray[0] == "EP" && TokenCounter == 6)|| (PatientDataArray[0] != "EP"&&TokenCounter==5)) {
                        // Ensure that we have enough data to create a request
                            if (PatientDataArray[0] == "EP") {
                                Total_EP_Patients_in_AllHospitals+=1;
                                
                                Request* temp = new Request(
                                    PatientDataArray[0],
                                    stoi(PatientDataArray[1]),
                                    stoi(PatientDataArray[2]),
                                    stoi(PatientDataArray[3]),
                                    stoi(PatientDataArray[4]),
                                    stoi(PatientDataArray[5])
                                );
                                Requests.enqueue(temp);
                                // cout << "Catched in EP\n";
                            }
                            else if (PatientDataArray[0] == "NP") {
                                
                                Total_NP_Patients_in_AllHospitals++;
                                
                                Request* temp = new Request(
                                    PatientDataArray[0],
                                    stoi(PatientDataArray[1]),
                                    stoi(PatientDataArray[2]),
                                    stoi(PatientDataArray[3]),
                                    stoi(PatientDataArray[4])
                                );
                                Requests.enqueue(temp);
                                // cout << "Catched in NP\n";
                            }
                            else if (PatientDataArray[0] == "SP") {

                                Total_SP_Patients_in_AllHospitals++;
                                
                                Request* temp = new Request(
                                    PatientDataArray[0],
                                    stoi(PatientDataArray[1]),
                                    stoi(PatientDataArray[2]),
                                    stoi(PatientDataArray[3]),
                                    stoi(PatientDataArray[4])
                                );
                                Requests.enqueue(temp);
                                // cout << "Catched in SP\n";
                            }
                        }

                    }
                }
            }
        }
    else if(SectionNumber == 3) {
        int counter = 0;
        int cancel_request[3] = {0}; // [0] -> Time , [1] -> PID , [2] -> HID
        while(getline(stream , token , delimiter)) {
            if (line.length()<=2) NoOfCancellations = stoi(token);
            else {
                if (counter < 3) {
                    cancel_request[counter] = stoi(token);
                    counter++;
                }
                if (counter == 3) {
                    CancellationRequest* temp = new CancellationRequest(cancel_request[0] , cancel_request[1] , cancel_request[2]);
                    CancellationRequests.enqueue(temp);
                    // cout<<cancel_request[0]<<" "<<cancel_request[1]<<" "<<cancel_request[2]<<endl;
                    counter = 0;
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


void ReadingHelper::DeleteMatrix( Hospital**array) {
    if (array) {
        for (int i = 0; i < HospitalsCount; ++i) {
            delete HospitalsArray[i];
        }
        delete[] HospitalsArray;
    }
    }




int **  &ReadingHelper::GetDistancesMatrix() {return DistancesMatrix;}
Hospital** &ReadingHelper::GetHospitalsArray() {return HospitalsArray;}
int ReadingHelper::GetScarSpeed() const{return SpecialCarSpeed;}
int ReadingHelper::GetNcarSpeed() const{return NormalCarSpeed;}
LinkedQueue<Request*> &ReadingHelper::GetRequestsQueue() {return Requests;}
SpecialLinkedQueue<CancellationRequest *> &ReadingHelper::GetCancellationRequestsQueue() {return CancellationRequests;}
int ReadingHelper::GetNoOfCancellations() const {
    return NoOfCancellations;
}
int ReadingHelper::GetNoOfHospitals() const {
    return HospitalsCount;
}
int * ReadingHelper::GetTotalNoOfPatients() const {
    int* totalpatients = new int [3];
    totalpatients[0] = Total_EP_Patients_in_AllHospitals;
    totalpatients[1] = Total_SP_Patients_in_AllHospitals;
    totalpatients[2] = Total_NP_Patients_in_AllHospitals;
    return totalpatients;
}

int* ReadingHelper::GetTotalCars_in_AllHospitals() const {
    int* totalCars = new int[2];
    totalCars[0] = Total_S_Cars_in_AllHospitals;
    totalCars[1] = Total_N_Cars_in_AllHospitals;
    return totalCars;
}