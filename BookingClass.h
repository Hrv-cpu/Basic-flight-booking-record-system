#ifndef BOOKINGCLASS_H
#define BOOKINGCLASS_H
#include <string>

using namespace std;

class BookingClass {
    private:
        string passenger_id;
        string flight_code;
        string date;
        string seat_class;

    public:
        BookingClass(string pid, string fc, string dat, string sc);

        string getPassengerId() const;
        string getFlightCode() const;
        string getDate() const;
        string getSeatClass() const;
};

#endif