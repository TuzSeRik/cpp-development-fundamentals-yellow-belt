#include <algorithm>

#include "sum_reverse_sort.h"
// Simple task to introduce "modules" in C++. This is implementation of previously declared functions
int Sum(int x, int y) {
    return x + y;
}

string Reverse(string s) {
    reverse(begin(s), end(s));
    return s;
}
void Sort(vector<int>& nums) {
    sort(begin(nums), end(nums));
}
