#include <algorithm>
#include <vector>

using namespace std;
// Sorting vector to place all duplicates in chunks and removing them by unique algorithm
template <typename T>
void RemoveDuplicates(vector<T>& elements) {
    sort(begin(elements), end(elements));
    elements.erase(unique(begin(elements), end(elements)), end(elements));
}
