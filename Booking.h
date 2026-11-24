#ifndef BOOKINGCLASS_H
#define BOOKINGCLASS_H
#include <string>

using namespace std;

class Booking {
    private:
        string passengerId_;
        string flightCode_;
        string date_;
        string seatClass_;

    public:
        Booking(string passengerId, string flightCode, string date, string seatClass);

        string getPassengerId() const;
        string getFlightCode() const;
        string getDate() const;
        string getSeatClass() const;
};

#endif