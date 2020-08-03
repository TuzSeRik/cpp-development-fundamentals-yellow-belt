#include "query.h"

istream& operator >> (istream& is, Query& q) {
    map<string, QueryType> code_to_type = {{"NEW_BUS", QueryType::NewBus},
                                           {"BUSES_FOR_STOP", QueryType::BusesForStop},
                                           {"STOPS_FOR_BUS", QueryType::StopsForBus},
                                           {"ALL_BUSES", QueryType::AllBuses}};
    string operation_code;
    cin >> operation_code;
    q.type = code_to_type[operation_code];
    // Adding unnecessary complexity according to a task
    if (q.type == QueryType::NewBus || q.type == QueryType::StopsForBus) {
        cin >> q.bus;

        if (q.type == QueryType::NewBus) {
            int stop_count;
            cin >> stop_count;
            q.stops.resize(stop_count);
            for (string &stop : q.stops) {
                cin >> stop;
            }
        }
    }
    else if (q.type == QueryType::BusesForStop)
        cin >> q.stop;

    return is;
}
