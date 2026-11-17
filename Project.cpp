#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Passenger.h"
#include "Flight.h"

using namespace std;

int ReadFlights() {
    string line;
    string flight_code, destination;
    int duration;

    ifstream MyReadFile("flights.txt");
    while(getline(MyReadFile, line)) 
    {
        stringstream ss(line);
        ss >> flight_code >> destination >> duration;
        //cout << flight_code << "\n" << destination << "\n" << duration << "\n\n";
    }

    MyReadFile.close();
}

int ReadBookings() {
    string line;
    string passenger_id, flight_code, date, seat_class;

    ifstream MyReadFile("bookings.txt");
    while(getline(MyReadFile, line)) 
    {
        stringstream ss(line);
        ss >> passenger_id >> flight_code >> date >> seat_class;
        //cout << passenger_id << "\n" << flight_code << "\n" << date << "\n" << seat_class << "\n\n";
    }

    MyReadFile.close();
}


int main() {
    ReadBookings();
    ReadFlights();

    vector<Flight> FlightList;
}