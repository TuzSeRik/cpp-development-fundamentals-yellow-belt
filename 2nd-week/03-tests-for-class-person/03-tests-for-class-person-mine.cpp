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
// Simple test to check that in all four cases we get what we want, because there is no border arguments
void TestIncognitos() {
    Person p;
    Assert(p.GetFullName(1) == "Incognito", "Clean request");
    p.ChangeFirstName(10, "Dmitriy");
    Assert(p.GetFullName(1) == "Incognito", "Name set");
    p.ChangeLastName(100, "Solodovnikov");
    Assert(p.GetFullName(1) == "Incognito", "Last Name set");
}

void TestOnlyNames() {
    Person p;
    p.ChangeFirstName(1, "Dmitriy");
    Assert(p.GetFullName(10) == "Dmitriy with unknown last name", "After first added name");
    p.ChangeFirstName(10, "Solod");
    Assert(p.GetFullName(100) == "Solod with unknown last name", "After second added name");
    p.ChangeFirstName(100, "TuzSeRik");
    Assert(p.GetFullName(50) == "Solod with unknown last name", "Between second and third added name");
}

void TestOnlyLastNames() {
    Person p;
    p.ChangeLastName(1, "Solodovnikov");
    Assert(p.GetFullName(10) == "Solodovnikov with unknown first name", "After first added last name");
    p.ChangeLastName(10, "Solod");
    Assert(p.GetFullName(100) == "Solod with unknown first name", "After second added last name");
    p.ChangeLastName(100, "TuzSeRik");
    Assert(p.GetFullName(50) == "Solod with unknown first name", "Between second and third added last name");
}

void TestFullNames() {
    Person p;
    p.ChangeLastName(1, "Solodovnikov");
    p.ChangeFirstName(5, "Dmitriy");
    Assert(p.GetFullName(10) == "Dmitriy Solodovnikov", "After first added full name");
    p.ChangeLastName(10, "Solod");
    Assert(p.GetFullName(7) == "Dmitriy Solodovnikov", "Between last name changes");
    p.ChangeLastName(100, "TuzSeRik");
    Assert(p.GetFullName(50) == "Dmitriy Solod", "Between second and third added last name");
    p.ChangeFirstName(6, "Gumbert");
    p.ChangeLastName(9, "Gumbert");
    Assert(p.GetFullName(9) == "Gumbert Gumbert", "Back-redacted full name");
}
// TestAll inlined in main function
int main() {
    TestRunner runner;
    runner.RunTest(TestIncognitos, "Incognitos");
    runner.RunTest(TestOnlyNames, "First names");
    runner.RunTest(TestOnlyLastNames, "Last names");
    runner.RunTest(TestFullNames, "Full names");

    return 0;
}
