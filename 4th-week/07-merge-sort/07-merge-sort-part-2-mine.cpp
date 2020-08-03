#include <vector>
#include <algorithm>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
    if (range_end - range_begin < 3)
        return;
    // Split range in three (using RandomIt operators)
    vector<typename RandomIt::value_type>
    leftPart = {range_begin, (range_begin + ((range_end - range_begin) / 3))},
    middlePart = {(range_begin + ((range_end - range_begin) / 3)), (range_begin + (2 *(range_end - range_begin) / 3))},
    rightPart = {(range_begin + (2 *(range_end - range_begin) / 3)), range_end};
    // Call function on parts iterators
    MergeSort(begin(leftPart), end(leftPart));
    MergeSort(begin(middlePart), end(middlePart));
    MergeSort(begin(rightPart), end(rightPart));
    // Then merge result into buffet and then into provided range iterators
    vector<typename RandomIt::value_type> temp;
    merge(begin(leftPart), end(leftPart), begin(middlePart), end(middlePart), back_inserter(temp));
    merge(begin(temp), end(temp), begin(rightPart), end(rightPart), range_begin);
}
