#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, avg;
    int64_t sum = 0;
    vector<int> nums, indexes;

    cin >> n;
    for (unsigned int i = 0; i < n; ++i) {
        int item;
        cin >> item;
        sum += item;
        nums.push_back(item);
    }
    // Don't forget to rid off of unsigned operand
    avg = sum / static_cast<int>(nums.size());

    for (size_t j = 0; j < nums.size(); ++j) {
        if (nums[j] > avg)
            indexes.push_back(j);
    }

    cout << indexes.size() << endl;
    for (auto i : indexes)
        cout << i << " ";

    return 0;
}
