#include <iostream>
#include <cstdint>

using namespace std;

int main() {
    unsigned int n;
    uint64_t r, result = 0;
    cin >> n >> r;
    // Using uint64_t for r to make equation result be casted to uint64_t;
    for (unsigned int i = 0; i < n; ++i) {
        unsigned int a, b, c;
        cin >> a >> b >> c;
        result += r * a * b * c;
    }

    cout << result << endl;
}
