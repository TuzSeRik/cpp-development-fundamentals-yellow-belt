#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;
// Start of copied unit testing framework
template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
    os << "{";
    bool first = true;
    for (const auto& kv : m) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u;
        if (!hint.empty()) {
            os << " hint: " << hint;
        }
        throw runtime_error(os.str());
    }
}

void Assert(bool b, const string& hint) {
    AssertEqual(b, true, hint);
}

class TestRunner {
public:
    template <class TestFunc>
    void RunTest(TestFunc func, const string& test_name) {
        try {
            func();
            cerr << test_name << " OK" << endl;
        } catch (exception& e) {
            ++fail_count;
            cerr << test_name << " fail: " << e.what() << endl;
        } catch (...) {
            ++fail_count;
            cerr << "Unknown exception caught" << endl;
        }
    }

    ~TestRunner() {
        if (fail_count > 0) {
            cerr << fail_count << " unit tests failed. Terminate" << endl;
            exit(1);
        }
    }

private:
    int fail_count = 0;
};
// End of copied unit testing framework
// Simple tests according to tasks
void TestDefault() {
    Rational rational;
    Assert(rational.Numerator() == 0 && rational.Denominator() == 1, "Default is 0/1");
}

void TestReduction() {
    Rational rational;
    rational = Rational(4, 4);
    Assert(rational.Numerator() == 1 && rational.Denominator() == 1, "Equal numerator and denominator reducing to 1/1");
    rational = Rational(6, 9);
    Assert(rational.Numerator() == 2 && rational.Denominator() == 3, "6/9 -> 2/3");
    rational = Rational(17, 3);
    Assert(rational.Numerator() == 17 && rational.Denominator() == 3, "17/3 -> 17/3");
}

void TestNegatives() {
    Rational rational;
    rational = Rational(-3, 1);
    Assert(rational.Numerator() == -3 && rational.Denominator() == 1, "-3/1 -> -3/1");
    rational = Rational(2, -5);
    Assert(rational.Numerator() == -2 && rational.Denominator() == 5, "2/-5 -> -2/5");
}

void TestPositives() {
    Rational rational;
    rational = Rational(2, 3);
    Assert(rational.Numerator() == 2 && rational.Denominator() == 3, "2/3 -> 2/3");
    rational = Rational(-2, -3);
    Assert(rational.Numerator() == 2 && rational.Denominator() == 3, "-2/-3 -> 2/3");
}

void TestZeros() {
    Rational rational(0, 100);
    Assert(rational.Numerator() == 0 && rational.Denominator() == 1, "0/X -> 0/1");
}

int main() {
    TestRunner runner;
    runner.RunTest(TestDefault, "Default");
    runner.RunTest(TestReduction, "Reduction");
    runner.RunTest(TestNegatives, "Negatives");
    runner.RunTest(TestPositives, "Positives");
    runner.RunTest(TestZeros, "Zeros");

    return 0;
}
