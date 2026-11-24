#ifndef FLIGHT_H
#define FLIGHT_H
#include <string>

using namespace std;

class Flight {
    private:
        string flightCode_;
        string destination_;
        int duration_;

    public:
        Flight(string flightCode, string destination, int duration);

        void displayFlight(string seatClass) const;
        
        string getFlightCode() const;
        string getDestination() const;
        int getDuration() const;
};

#endif