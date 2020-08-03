#pragma once

#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// I don't wanted to add this things, but it's required
struct BusesForStopResponse {
    string response;
};

ostream& operator <<(ostream& os, const BusesForStopResponse& r) ;

struct StopsForBusResponse {
    stringstream ss;
};
// Stringstream is easiest way to output stream by one command,
// but for unknown reason it adds unnecessary endl symbol
ostream& operator <<(ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse {
    stringstream ss;
};

ostream& operator <<(ostream& os, const AllBusesResponse& r);
