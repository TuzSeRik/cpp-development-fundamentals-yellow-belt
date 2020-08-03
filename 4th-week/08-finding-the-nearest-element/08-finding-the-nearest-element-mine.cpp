#include <set>

using namespace std;

set<int>::const_iterator FindNearestElement(
        const set<int>& numbers,
        int border) {
    // Finding first element after border
    const auto after = numbers.lower_bound(border);
    // If this element is the first in set, then return it
    if (after == begin(numbers))
        return after;
    // If it's not, then set contains one or more elements and we can take element before border
    const auto before = prev(after);
    // If there is no element after border, then return last element in set (element previous to end)
    if (after == end(numbers))
        return before;
    // If we have both elements, then return nearest
    return (border - *before <= *after - border) ? before : after;
}
