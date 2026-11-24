#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include "Booking.h"
#include "Flight.h"

using namespace std;

vector<Flight> readFlights(string flightFile) {

    vector<Flight> flights;
    string line, flightCode, destination;
    int duration = 0;

    ifstream in(flightFile);
    while(getline(in, line)) 
    {
        stringstream ss(line);
        
        ss >> flightCode >> destination >> duration;
        flights.emplace_back(flightCode, destination, duration);
    }
    in.close();

    return flights;
}

map<string, map<string, vector<Booking>>> readBookings(string bookingFile) {

    map<string, map<string, vector<Booking>>> bookings;
    string line, passengerId, flightCode, date, seatClass;

    ifstream in(bookingFile);
    while(getline(in, line)) 
    {
        stringstream ss(line);

        ss >> passengerId >> flightCode >> date >> seatClass;
        bookings[passengerId][date].emplace_back(passengerId, flightCode, date, seatClass);

    }
    in.close();

    return bookings;
}