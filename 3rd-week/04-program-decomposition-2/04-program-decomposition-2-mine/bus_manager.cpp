#include "bus_manager.h"

using namespace std;

// The whole task is an example how to make simple code much more harder by oversplitting it to many parts
void BusManager::AddBus(const string& bus, const vector<string>& stops) {
    for (const auto& stop : stops) {
        stops_to_buses[bus].push_back(stop);
        buses_to_stops[stop].push_back(bus);
    }
}

BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const {
    BusesForStopResponse r;
    if (buses_to_stops.count(stop) == 0) {
        r.response = "No stop";
    }
    else {
        for (const string& bus : buses_to_stops.at(stop)) {
            r.response += bus + " ";
        }
    }

    return r;
}

StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const {
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
AllBusesResponse BusManager::GetAllBuses() const {
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
