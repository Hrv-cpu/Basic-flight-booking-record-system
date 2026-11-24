#include "Booking.h"
#include <string>

Booking::Booking(string passengerId, string flightCode, string date, string seatClass) {passengerId_ = passengerId, flightCode_ = flightCode, date_ = date, seatClass_ = seatClass;}

string Booking::getPassengerId() const {
    return passengerId_;
}
string Booking::getFlightCode() const {
    return flightCode_;
}
string Booking::getDate() const {
    return date_;
}
string Booking::getSeatClass() const {
    return seatClass_;
}