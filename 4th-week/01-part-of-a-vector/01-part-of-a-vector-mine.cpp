#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void PrintVectorPart(const vector<int>& numbers) {
    // Getting border of a part
    auto border = find_if(begin(numbers), end(numbers), [](int n) -> bool {
        return n < 0;
    });
    // We don't need the border point, so if it's not the edge left point, we move one point left
    if (border != begin(numbers))
        border--;
    else
        return;
    for (auto it = border; it >= begin(numbers) ; it--) {
        cout << *it << " ";
    }
}
