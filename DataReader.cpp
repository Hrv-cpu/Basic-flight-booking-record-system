#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "BookingClass.cpp"
#include "FlightClass.cpp"

using namespace std;

vector<FlightClass> FlightVec;
vector<BookingClass> BookingVec;
string line;
string passenger_id = "", flight_code = "", date = "", seat_class = "", destination = "";
int duration = 0;

void ReadFlights() {

    ifstream in("flights.txt");
    while(getline(in, line)) 
    {
        stringstream ss(line);
        
        ss >> flight_code >> destination >> duration;
        //cout << flight_code << "\n" << destination << "\n" << duration << "\n\n";
        FlightVec.emplace_back(flight_code, destination, duration);
    }
    in.close();
}

void ReadBookings() {

    ifstream in("bookings.txt");
    while(getline(in, line)) 
    {
        stringstream ss(line);
        ss >> passenger_id >> flight_code >> date >> seat_class;
        //cout << passenger_id << "\n" << flight_code << "\n" << date << "\n" << seat_class << "\n\n";
        BookingVec.emplace_back(passenger_id, flight_code, date, seat_class);

    }
    in.close();
}