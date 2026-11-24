#include "FlightClass.h"
#include <iostream>

using namespace std;

FlightClass::FlightClass(string fc, string dest, int dur) {
    flight_code = fc;
    destination = dest;
    duration = dur;
}

string FlightClass::getFlightCode() const{
    return flight_code;
}
string FlightClass::getDestination() const {
    return destination;
}
int FlightClass::getDuration() const {
    return duration;
}

void FlightClass::displayFlight(string seat_class) const {
    cout << "\n    " << flight_code << " " << destination << " (" << duration << " mins): " << seat_class;
}

