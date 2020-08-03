#include <vector>
#include <string>
#include <algorithm>

using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
        RandomIt range_begin, RandomIt range_end,
        const string& prefix) {
    // Range consists of iterator, pointing to first word which is not smaller than prefix
    // and iterator, pointing to first word which is bigger than any word with prefix -
    // word, starting with prefix with next last letter
    string border = prefix, nextToBorder = border;
    nextToBorder[prefix.size()-1]++;

    auto
    left = lower_bound(range_begin, range_end, border),
    right = lower_bound(range_begin, range_end, nextToBorder);

    return make_pair(left, right);
}
