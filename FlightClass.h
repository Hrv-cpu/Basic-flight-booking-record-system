#ifndef FLIGHTCLASS_H
#define FLIGHTCLASS_H
#include <string>

using namespace std;

class FlightClass {
    private:
        string flight_code;
        string destination;
        int duration;

    public:
        FlightClass(string fc, string dest, int dur);

        void displayFlight(string seat_class) const;
        
        string getFlightCode() const;
        string getDestination() const;
        int getDuration() const;
};

#endif