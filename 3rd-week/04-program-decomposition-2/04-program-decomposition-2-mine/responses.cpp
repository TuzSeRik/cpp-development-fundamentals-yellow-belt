#include "responses.h"

ostream& operator <<(ostream& os, const BusesForStopResponse& r) {
    os << r.response;

    return os;
}
// Stringstream is easiest way to output stream by one command,
// but for unknown reason it adds unnecessary endl symbol
ostream& operator <<(ostream& os, const StopsForBusResponse& r) {
    string output = r.ss.str();
    cout << output.erase(output.size()-1, 1);

    return os;
}

ostream& operator <<(ostream& os, const AllBusesResponse& r) {
    string output = r.ss.str();
    cout << output.erase(output.size()-1, 1);

    return os;
}
