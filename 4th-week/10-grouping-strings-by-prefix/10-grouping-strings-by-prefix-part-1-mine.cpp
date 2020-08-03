#include <vector>
#include <string>
#include <algorithm>

using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
        RandomIt range_begin, RandomIt range_end,
        char prefix) {
    // Creating arguments to algorithms. For right iterator we use prefix + 1,
    // because letter is smaller than any string starting with this letter
    // and next letter is bigger than any string starting with previous one
    string border = {prefix}, nextToBorder = {static_cast<char>(prefix + 1)};

    auto
    left = lower_bound(range_begin, range_end, border),
    right = lower_bound(range_begin, range_end, nextToBorder);

    return make_pair(left, right);
}
