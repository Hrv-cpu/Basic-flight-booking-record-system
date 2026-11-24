#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "DataReader.cpp"
#include "BookingClass.h"
#include "FlightClass.h"
#include <map>

using namespace std;

map<string, string> Requests;
string passenger_id_requests = "", date_requests = "";
string line_requests;

void ReturnRequests() {
    int overall_flight = 0;
    int total_flight = 0;

    for (auto pair : Requests) {
        string reqPassengerId = pair.first;
        string reqPassengerDate = pair.second;

        if (reqPassengerDate == "") {

            cout << "\nPassenger ID: " << pair.first;
            for (int i = 0; i < BookingVec.size(); i++) {

                auto firstBooking = BookingVec[i];

                if (firstBooking.getPassengerId() == reqPassengerId) {

                    string targetDate = firstBooking.getDate();

                    cout << "\n  Date " << targetDate << ":";
                    for (int j = i; j < BookingVec.size();) {

                        auto currentBooking = BookingVec[j];

                        if (currentBooking.getPassengerId() == reqPassengerId && currentBooking.getDate() == targetDate) {
                            for (auto &f : FlightVec) {
                                if (f.getFlightCode() == currentBooking.getFlightCode()) {

                                    f.displayFlight(currentBooking.getSeatClass());
                                    total_flight += 1;
                                    overall_flight += 1;
                                    break;
                                }
                            }
                            BookingVec.erase(BookingVec.begin() + j);
                        } 
                        else { j++; }
                    }

                    cout << "\n  Total Flights: " << total_flight << "\n";
                    total_flight = 0;
                    i--; // Adjust index since firstBooking was erased
                }
            }

            cout << "\n  Overall Flights: " << overall_flight;
            overall_flight = 0;
        }

        else {

            cout << "\nPassenger ID: " << reqPassengerId;
            cout << "\n  Date " << reqPassengerDate << ":";

            for (auto b : BookingVec) {
                if (reqPassengerId == b.getPassengerId() && reqPassengerDate == b.getDate()) {
                    for (auto f : FlightVec){
                        if (b.getFlightCode() == f.getFlightCode()) {

                            f.displayFlight(b.getSeatClass());
                            total_flight += 1;
                        };
                    }
                }
            }
            cout << "\n  Total Flights: " << total_flight << "\n";
            total_flight = 0;
        } 
    }
}

void ReadRequests() {

    ifstream in("requests.txt");
    while(getline(in, line_requests)) {

        passenger_id_requests = "";
        date_requests = "";
        stringstream ss(line_requests);

        ss >> passenger_id_requests >> date_requests;
        Requests.insert({passenger_id_requests, date_requests});
        
    }
    in.close();
}

int main() {
    ReadBookings();
    ReadFlights();
    ReadRequests();
    ReturnRequests();

    return 0;
}