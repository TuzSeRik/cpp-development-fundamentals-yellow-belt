#include <deque>
#include <string>
#include <iostream>

using namespace std;

int main() {
    // Using deque because of need to manipulate front elements and string because of simplicity
    deque<string> statement;
    int a, n;
    cin >> a >> n;
    // Adding required braces to root argument, braces as separate elements
    statement.push_back("(");
    statement.push_back(to_string(a));
    statement.push_back(")");
    // Now adding parts with signs and operands and braces as separate elements
    for (int i = 0; i < n; ++i) {
        string sign;
        int operand;
        cin >> sign >> operand;
        statement.push_front("(");
        statement.push_back(" " + sign + " " + to_string(operand));
        statement.push_back(")");
        }
    // Now deleting last pair of braces as required, that's why we added braces as separate elements
    statement.pop_back();
    statement.pop_front();
    // Outputting result
    for (const auto& part : statement)
        cout << part;

    return 0;
}
