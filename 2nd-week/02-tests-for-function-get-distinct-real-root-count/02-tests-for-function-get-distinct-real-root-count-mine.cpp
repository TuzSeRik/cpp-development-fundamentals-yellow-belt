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
// Tested function
int GetDistinctRealRootCount(double a, double b, double c);
// Separating test cases by zero arguments and writing tests for every possible sign combination
void TestRootsOfZeroC() {
    double a = 2, b = 2, c = 0;
    Assert(GetDistinctRealRootCount(a, b, c) == 2, "C == 0, A, B > 0");
    Assert(GetDistinctRealRootCount(a, -b, c) == 2, "C == 0, A > 0, B < 0");
    Assert(GetDistinctRealRootCount(-a, b, c) == 2, "C == 0, A < 0, B > 0");
    Assert(GetDistinctRealRootCount(-a, -b, c) == 2, "C == 0, A, B < 0");
}

void TestRootsOfZeroB() {
    double a = 2, b = 0, c = 2;
    Assert(GetDistinctRealRootCount(a, b, c) == 0, "B == 0, A, C > 0");
    Assert(GetDistinctRealRootCount(a, b, -c) == 2, "B == 0, A > 0, C < 0");
    Assert(GetDistinctRealRootCount(-a, b, c) == 2, "B == 0, A < 0, C > 0");
    Assert(GetDistinctRealRootCount(-a, b, -c) == 0, "B == 0, A, C < 0");
}

void TestRootsOfZeroBC() {
    double a = 2, b = 0, c = 0;
    Assert(GetDistinctRealRootCount(a, b, c) == 1, "B, C == 0, A > 0");
    Assert(GetDistinctRealRootCount(-a, b, c) == 1, "B, C == 0, A < 0");
}

void TestRootsOfZeroA() {
    double a = 0, b = 2, c = 2;
    Assert(GetDistinctRealRootCount(a, b, c) == 1, "A == 0, B, C > 0");
    Assert(GetDistinctRealRootCount(a, b, -c) == 1, "A == 0, B > 0, C < 0");
    Assert(GetDistinctRealRootCount(a, -b, c) == 1, "A == 0, B < 0, C > 0");
    Assert(GetDistinctRealRootCount(a, -b, -c) == 1, "A == 0, B, C < 0");
}

void TestRootsOfZeroAC() {
    double a = 0, b = 2, c = 0;
    Assert(GetDistinctRealRootCount(a, b, c) == 1, "A, C == 0, B > 0");
    Assert(GetDistinctRealRootCount(a, -b, c) == 1, "A, C == 0, B < 0");
}

void TestRootsOfZeroAB() {
    double a = 0, b = 0, c = 2;
    Assert(GetDistinctRealRootCount(a, b, c) == 0, "A, B == 0, C > 0");
    Assert(GetDistinctRealRootCount(a, b, -c) == 0, "A, B == 0, C < 0");
}
// Tests for full equation, separated by D value
void TestRootsOfDAfterZero() {
    double a, b, c;
    {
        a = 2, b = 8, c = 2;
        Assert(GetDistinctRealRootCount(a, b, c) == 2, "A, B, C > 0");
    }
    {
        a = 2, b = 2, c = 2;
        Assert(GetDistinctRealRootCount(a, b, -c) == 2, "A, B > 0, C < 0");
    }
    {
        a = 2, b = 8, c = 2;
        Assert(GetDistinctRealRootCount(a, -b, c) == 2, "A, C > 0 B < 0");
    }
    {
        a = 2, b = 2, c = 2;
        Assert(GetDistinctRealRootCount(a, -b, -c) == 2, "A > 0, B, C < 0");
    }
    {
        a = 2, b = 2, c = 2;
        Assert(GetDistinctRealRootCount(-a, b, c) == 2, "A < 0, B, C > 0");
    }
    {
        a = 2, b = 8, c = 2;
        Assert(GetDistinctRealRootCount(-a, b, -c) == 2, "B > 0, A, C < 0");
    }
    {
        a = 2, b = 2, c = 2;
        Assert(GetDistinctRealRootCount(-a, -b, c) == 2, "A, B < 0, C > 0");
    }
    {
        a = 2, b = 8, c = 2;
        Assert(GetDistinctRealRootCount(-a, -b, -c) == 2, "A, B, C < 0");
    }
}

void TestRootsOfDEqualZero() {
    double a, b, c;
    {
        a = 2, b = 4, c = 2;
        Assert(GetDistinctRealRootCount(a, b, c) == 1, "A, B, C > 0");
    }
    {
        a = 2, b = 4, c = 2;
        Assert(GetDistinctRealRootCount(a, -b, c) == 1, "A, C > 0 B < 0");
    }
    {
        a = 2, b = 4, c = 2;
        Assert(GetDistinctRealRootCount(-a, b, -c) == 1, "B > 0, A, C < 0");
    }
    {
        a = 2, b = 4, c = 2;
        Assert(GetDistinctRealRootCount(-a, -b, -c) == 1, "A, B, C < 0");
    }
}

void TestRootsOfDBelowZero() {
    double a, b, c;
    {
        a = 2, b = 2, c = 2;
        Assert(GetDistinctRealRootCount(a, b, c) == 0, "A, B, C > 0");
    }
    {
        a = 2, b = 2, c = 2;
        Assert(GetDistinctRealRootCount(a, -b, c) == 0, "A, C > 0 B < 0");
    }
    {
        a = 2, b = 2, c = 2;
        Assert(GetDistinctRealRootCount(-a, b, -c) == 0, "B > 0, A, C < 0");
    }
    {
        a = 2, b = 2, c = 2;
        Assert(GetDistinctRealRootCount(-a, -b, -c) == 0, "A, B, C < 0");
    }
}
// TestAll inlined in main function
int main() {
    TestRunner runner;
    runner.RunTest(TestRootsOfZeroC, "C == 0");
    runner.RunTest(TestRootsOfZeroB, "B == 0");
    runner.RunTest(TestRootsOfZeroBC, "B, C == 0");
    runner.RunTest(TestRootsOfZeroA, "A == 0");
    runner.RunTest(TestRootsOfZeroAC, "A, C ==0");
    runner.RunTest(TestRootsOfZeroAB, "A, B == 0");
    runner.RunTest(TestRootsOfDAfterZero, "D > 0");
    runner.RunTest(TestRootsOfDEqualZero, "D == 0");
    runner.RunTest(TestRootsOfDBelowZero, "D < 0");

    return 0;
}
