#include <vector>
#include <algorithm>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
    // If range contains less than 2 elements (end iterator is same as begin iterator or stands next to it)
    // then stop execution
    if (range_begin == range_end || range_begin + 1 == range_end)
        return;
    // Split range in two (using RandomIt operators)
    auto
    leftHalf = {range_begin, (range_begin + ((range_end - range_begin) / 2))},
    rightHalf = {(range_begin + ((range_end - range_begin) / 2)), range_end};
    // Call function on parts iterators
    MergeSort(begin(leftHalf), end(leftHalf));
    MergeSort(begin(rightHalf), end(rightHalf));
    // Then merge result into provided range iterators
    merge(begin(leftHalf), end(leftHalf), begin(rightHalf), end(rightHalf), range_begin);
}
