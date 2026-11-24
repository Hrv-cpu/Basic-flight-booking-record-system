#include "BookingClass.h"
#include <string>

BookingClass::BookingClass(string pid, string fc, string dat, string sc) {passenger_id = pid, flight_code = fc, date = dat, seat_class = sc;}

string BookingClass::getPassengerId() const {
    return passenger_id;
}
string BookingClass::getFlightCode() const {
    return flight_code;
}
string BookingClass::getDate() const {
    return date;
}
string BookingClass::getSeatClass() const {
    return seat_class;
}