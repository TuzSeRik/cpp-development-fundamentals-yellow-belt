#include <vector>
#include <map>
#include <tuple>
#include <algorithm>

using namespace std;

bool operator <(Region lhs, Region rhs) {
    return tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population)
           < tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}

int FindMaxRepetitionCount(const vector<Region>& regions) {
    map<Region, int> repetitions;
    for (const auto& region : regions) {
        repetitions[region]++;
    }

    if (repetitions.empty())
        return 0;
    return max_element(begin(repetitions), end(repetitions),
            [](const auto& p1, const auto& p2) -> bool {
                return p1.second < p2.second;
    })->second;
}
