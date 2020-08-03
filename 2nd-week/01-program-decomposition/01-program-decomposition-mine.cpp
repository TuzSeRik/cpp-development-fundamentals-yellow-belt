#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>

using namespace std;

enum class QueryType {
    NewBus,
    BusesForStop,
    StopsForBus,
    AllBuses
};

struct Query {
    QueryType type;
    string bus;
    string stop;
    vector<string> stops;
};

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
// I don't wanted to add this things, but it's required
struct BusesForStopResponse {
    string response;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
    os << r.response;

    return os;
}

struct StopsForBusResponse {
    stringstream ss;
};
    // Stringstream is easiest way to output stream by one command,
    // but for unknown reason it adds unnecessary endl symbol
ostream& operator << (ostream& os, const StopsForBusResponse& r) {
    string output = r.ss.str();
    cout << output.erase(output.size()-1, 1);

    return os;
}

struct AllBusesResponse {
    stringstream ss;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
    string output = r.ss.str();
    cout << output.erase(output.size()-1, 1);

    return os;
}
// The whole task is an example how to make simple code much more harder by oversplitting it to many parts
class BusManager {
public:
    void AddBus(const string& bus, const vector<string>& stops) {
        for (const auto& stop : stops) {
            stops_to_buses[bus].push_back(stop);
            buses_to_stops[stop].push_back(bus);
        }
    }

    [[nodiscard]] BusesForStopResponse GetBusesForStop(const string& stop) const {
        BusesForStopResponse r;
        if (buses_to_stops.count(stop) == 0) {
             r.response = "No stop";
        } else {
            for (const string& bus : buses_to_stops.at(stop)) {
                r.response += bus + " ";
            }
        }

        return r;
    }

    [[nodiscard]] StopsForBusResponse GetStopsForBus(const string& bus) const {
        StopsForBusResponse r;
        if (stops_to_buses.count(bus) == 0) {
            r.ss << "No bus" << endl;
        }
        else {
            for (const string& stop : stops_to_buses.at(bus)) {
                r.ss << "Stop " << stop << ": ";
                if (buses_to_stops.at(stop).size() == 1) {
                    r.ss << "no interchange";
                }
                else {
                    for (const string& other_bus : buses_to_stops.at(stop)) {
                        if (bus != other_bus) {
                            r.ss << other_bus << " ";
                        }
                    }
                }
                r.ss << endl;
            }
        }

        return r;
    }
    // All of this is just an old solution to original task, but with extra layer of complexity
    [[nodiscard]] AllBusesResponse GetAllBuses() const {
        AllBusesResponse r;
        if (stops_to_buses.empty()) {
            r.ss << "No buses" << endl;
        }
        else {
            for (const auto& bus_item : stops_to_buses) {
                r.ss << "Bus " << bus_item.first << ": ";
                for (const string& stop : bus_item.second) {
                    r.ss << stop << " ";
                }
                r.ss << endl;
            }
        }

        return r;
    }

private:
    map<string, vector<string>> buses_to_stops, stops_to_buses;
};

int main() {
    int query_count;
    Query q;

    cin >> query_count;

    BusManager bm;
    for (int i = 0; i < query_count; ++i) {
        cin >> q;
        switch (q.type) {
            case QueryType::NewBus:
                bm.AddBus(q.bus, q.stops);
                break;
            case QueryType::BusesForStop:
                cout << bm.GetBusesForStop(q.stop) << endl;
                break;
            case QueryType::StopsForBus:
                cout << bm.GetStopsForBus(q.bus) << endl;
                break;
            case QueryType::AllBuses:
                cout << bm.GetAllBuses() << endl;
                break;
        }
    }

    return 0;
}
