#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> SplitIntoWords(const string& s) {
    vector<string> result;
    // Comparing with 0 because of null-terminating in C++ strings
    auto iterator = begin(s);
    while (*iterator != 0) {
        auto cursor = find(iterator, end(s), ' ');
        result.emplace_back(iterator, cursor);
        if (*cursor != 0)
            iterator = ++cursor;
        else
            iterator = cursor;
    }

    return result;
}
