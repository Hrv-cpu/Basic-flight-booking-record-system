#include "Flight.h"
#include <iostream>

using namespace std;

Flight::Flight(string flightCode, string destination, int duration) {
    flightCode_ = flightCode;
    destination_ = destination;
    duration_ = duration;
}

string Flight::getFlightCode() const {
    return flightCode_;
}
string Flight::getDestination() const {
    return destination_;
}
int Flight::getDuration() const {
    return duration_;
}

void Flight::displayFlight(string seatClass) const {
    cout << "\n    " << flightCode_ << " " << destination_ << " (" << duration_ << " mins): " << seatClass;
}