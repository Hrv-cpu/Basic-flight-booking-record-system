#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include "DataReader.cpp"
#include "Booking.h"
#include "Flight.h"

using namespace std;

void printItinerary(map<string, string> requests, vector<Flight> flights, map<string, map<string, vector<Booking>>> bookings) {
    int overallFlights = 0;
    int totalFlights = 0;

    for (auto requestPair : requests) {

        string reqPassengerId = requestPair.first;
        string reqPassengerDate = requestPair.second;

        cout << "\nPassenger ID: " << reqPassengerId;
        overallFlights = 0;

        for (auto datePair : bookings[reqPassengerId]) {

            string date = datePair.first;

            if (reqPassengerDate != "" && reqPassengerDate != date) continue;

            cout << "\n  Date " << date << ":";
            totalFlights = 0;

            // Loop 2: Inner vector (bookings on this date)
            for (auto booking : datePair.second) {
                for (auto flight : flights) {
                    if (flight.getFlightCode() == booking.getFlightCode()) {
                        flight.displayFlight(booking.getSeatClass());
                        totalFlights += 1;
                        overallFlights += 1;
                        break;
                    }
                }
            }

            cout << "\n  Total Flights: " << totalFlights << "\n";
        }

        if (reqPassengerDate == "") {
            cout << "\n  Overall Flights: " << overallFlights;
        }
    }
}

map<string, string> readRequests(string requestFile) {
  
    map<string, string> requests;
    string reqPassengerIdInput, reqDateInput, requestLine;

    ifstream in(requestFile);
    while (getline(in, requestLine)) {

        stringstream ss(requestLine);

        ss >> reqPassengerIdInput >> reqDateInput;
        requests.insert({reqPassengerIdInput, reqDateInput});
        
    }
    in.close();

    return requests;
}

int main() {
    printItinerary(readRequests("requests.txt"), readFlights("flights.txt"), readBookings("bookings.txt"));

    return 0;
}