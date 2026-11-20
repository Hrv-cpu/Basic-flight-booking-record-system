#include <string>

using namespace std;

class Flight {
    private:
        string passenger_id;
        string date;
        string flight_code;
        string destination;
        int duration;
        string seat_class;

    public:
        Flight(string pid, string dat, string fc, string des, int dur, string sc) {
            passenger_id = pid;
            date = dat;
            flight_code = fc;
            destination = des;
            duration = dur;
            seat_class = sc;
        }

        void displayFlight() {
            cout << "\n  Date: " << date;
            cout << "\n    " << flight_code << " " << destination << " " << "(" << duration << " mins): " << seat_class;
            cout << "\n  Total Flights: \n";
        }

        string getPid() {
            return passenger_id;
        }

        string getFC() {
            return flight_code;
        }

        string getDate() {
            return date;
        }

        void setDest(string des) {
            destination = des;
        }

        void setDur(int dur) {
            duration = dur;
        }
};