#pragma once

#include <map>
#include <string>
#include <vector>

#include "responses.h"

using namespace std;

class BusManager {
public:
    void AddBus(const string& bus, const vector<string>& stops);

    [[nodiscard]] BusesForStopResponse GetBusesForStop(const string& stop) const;

    [[nodiscard]] StopsForBusResponse GetStopsForBus(const string& bus) const;

    [[nodiscard]] AllBusesResponse GetAllBuses() const;

private:
    map<string, vector<string>> buses_to_stops, stops_to_buses;
};
