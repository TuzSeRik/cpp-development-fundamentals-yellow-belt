#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    // Saving pre-calculated array of factorials to use them after
    const int factorial[] = {
            1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600,
    };

    int number;
    cin >> number;
    vector<int> numbers(number);
    vector<string> permutations(factorial[number]);
    for (auto& item : numbers)
        item = number--;
    // Iterating through all permutations and saving them in string with spaces between numbers
    for (int i = 0; i < factorial[numbers.size()]; ++i) {
        next_permutation(begin(numbers), end(numbers));
        // I forgot about prev_permutation, so here is "not elegant" solution
        string phrase;
        for (const auto& num : numbers)
            phrase += (to_string(num)+" ");
        permutations.push_back(phrase);
    }
    // Sorting permutations in strings with reversed iterators
    sort(rbegin(permutations), rend(permutations));

    for (const auto& phrase : permutations)
            cout << phrase << endl;

    return 0;
}
