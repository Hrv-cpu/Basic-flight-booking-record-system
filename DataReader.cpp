#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Flight.h"

using namespace std;

vector<Flight> FlightList;
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
        for (Flight &f : FlightList)
        {
            if(f.getFC() == flight_code)
            {
                f.setDest(destination);
                f.setDur(duration);
            }
        }
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
        Flight flight(passenger_id, date, flight_code, "", 0, seat_class);
        FlightList.push_back(flight);

    }
    in.close();
}