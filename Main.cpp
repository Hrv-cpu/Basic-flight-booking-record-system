#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "DataReader.cpp"
#include <map>

using namespace std;

map<string, string> Requests;
string passenger_id_requests = "", date_requests = "";
string line_requests;

string ReturnRequests() {
    int overall_flight = 0;

    for (auto pair : Requests) {
        if (pair.second == "") {
            cout << "\nPassenger ID: " << pair.first;
            for (Flight f : FlightList) {
                if (f.getPid() == pair.first) {
                    f.displayFlight();
                    overall_flight += 1;
                }
            }
            cout << "\nOverall Flights: " << overall_flight << "\n";
            overall_flight = 0;
        }
        else {
            cout << "\nPassenger ID: " << pair.first;
            for (Flight f : FlightList) {
                if (f.getPid() == pair.first && f.getDate() == pair.second) {
                    f.displayFlight();
                }
            }
        }
        
    }
    
}

string ReadRequests() {

    ifstream in("requests.txt");
    while(getline(in, line)) {
        passenger_id_requests = "";
        date_requests = "";
        stringstream ss(line);

        ss >> passenger_id_requests >> date_requests;
        //cout << passenger_id_requests << "\n" << date_requests << "\n\n";
        Requests.insert({passenger_id_requests, date_requests});
        
    }
    in.close();
}

int main() {

    string menuChoice = "";

    ReadBookings();
    ReadFlights();
    ReadRequests();
    
    while (true) {

        cout << "\nEnter menu option:\n   1. Generate itinerary from requests\n   2. Exit\n";
        cin >> menuChoice;
        if (menuChoice == "1") {
            ReturnRequests();
        }
        else if (menuChoice == "2") {
            break;
        }
        else {
            cout << "\n##Please enter a valid number##\n"; 
        }
    };

    return 0;
}