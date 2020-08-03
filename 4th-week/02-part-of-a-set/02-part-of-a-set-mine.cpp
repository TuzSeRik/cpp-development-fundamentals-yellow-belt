#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border) {
    vector<T> result;
    // Find element which be bigger than border
    auto borderIterator = find_if(begin(elements), end(elements), [border](T element) -> bool {
        return element > border;
    });
    // Using se orderliness to make a vector of elements after border
    for (auto it = borderIterator; it != end(elements) ; it++) {
        result.push_back(*it);
    }

    return result;
}
