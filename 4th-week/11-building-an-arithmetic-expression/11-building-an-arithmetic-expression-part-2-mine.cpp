#include <deque>
#include <string>
#include <iostream>

using namespace std;

int main() {
    // Using deque because of need to manipulate front elements and string because of simplicity
    deque<string> statement;
    int a, n;
    cin >> a >> n;
    statement.push_back(to_string(a));
    // Saving previous sign requires special variable outside the cycle
    string previousSign, sign;
    int operand;
    for (int i = 0; i < n; ++i) {
        cin >> sign >> operand;
        // Braces should be added only when we adding multiplication and division after simple plus and minus
        if ((previousSign == "+" || previousSign == "-") && (sign == "*" || sign == "/")) {
            statement.push_front("(");
            statement.push_back(")");
        }
        statement.push_back(" " + sign + " " + to_string(operand));
        previousSign = sign;
    }

    for (const auto& part : statement)
        cout << part;

    return 0;
}
