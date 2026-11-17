#include <string>

using namespace std;

class Passenger {
    public:

        string passenger_id;
        
        int addFlight(auto date, string flight_code, string destination, int duration, string seat_class) {
            cout << "\n  Date: " << date;
            cout << "\n    " << flight_code << " " << destination << " " << "(" << duration << " mins): " << seat_class;
            cout << "\n  Total Flights: ";
        }
};