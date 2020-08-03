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
// Function we testing
bool IsPalindrom(const string& str);
// Absolutely stupid task to test something you don't know working how,
// so here is copy-pasted tests from discussion forum
void TestSomething() {
    Assert(IsPalindrom(""), "Empty string is palindrome");
    Assert(IsPalindrom(" "), "Any one symbol is palindrome");
    Assert(!IsPalindrom("a123321b"), "Lasts symbols are included");
    Assert(!IsPalindrom("123ab321"), "Middle symbols are included");
    Assert(!IsPalindrom("ab1 1b a"), "Spaces are included");
    Assert(IsPalindrom(""), "Test empty string is palindrom");
    Assert( IsPalindrom("a"), "Test one symbol string is palindrom");
    Assert( IsPalindrom("AbcaaacbA"), "Test regular palindrom 1");
    Assert( IsPalindrom("madam"), "Test regular palindrom 2");
    Assert( IsPalindrom("level"), "Test regular palindrom 2");
    Assert( !IsPalindrom("baobab"), "Test regular palindrom 2");
    Assert( IsPalindrom("wasitacaroracatisaw"), "Test regular palindrom 2");
    Assert( !IsPalindrom("wasitacaroracatisaW"), "Test regular palindrom 2");
    Assert( !IsPalindrom("QWERTYUIOPASDFGHJKLZXCVBNMmnbvcxzlkjhgfdsapoiuytrewq"), "Test regular palindrom 2");
    Assert( !IsPalindrom("abcd"), "Test not a palindrom");
    Assert( !IsPalindrom("bbbbbbbadbbbbbbb"), "Test not a palindrom");
    Assert( IsPalindrom("ab cdc ba"), "Test palindrome string with spaces");
    Assert( !IsPalindrom("ab  cdc ba"), "Test palindrome string with spaces");
    Assert( !IsPalindrom("ab   cdc  ba"), "Test palindrome string with spaces");
    Assert( !IsPalindrom("ab   cdc  ba "), "Test palindrome string with spaces");
    Assert( !IsPalindrom("  ab   cdc  ba "), "Test palindrome string with spaces");
    Assert( !IsPalindrom("          aba"), "Test not a palindrome string with spaces 2");
    Assert( !IsPalindrom("          aba  "), "Test not a palindrome string with spaces 2");
    Assert( !IsPalindrom("\taba    "), "Test not a palindrome string with spaces 2");
    Assert( !IsPalindrom("\taba "), "Test not a palindrome string with spaces 2");
    Assert( !IsPalindrom("\taba  "), "Test not a palindrome string with spaces 2");
    Assert( !IsPalindrom("\taba   "), "Test not a palindrome string with spaces 2");
    Assert( !IsPalindrom("\taba     "), "Test not a palindrome string with spaces 2");
    AssertEqual(IsPalindrom(""), true, "empty string");
    AssertEqual(IsPalindrom(" "), true, "whitespace");
    AssertEqual(IsPalindrom("A"), true, "A");
    AssertEqual(IsPalindrom("&"), true, "&");
    AssertEqual(IsPalindrom("1"), true, "1");
    AssertEqual(IsPalindrom("121"), true, "121");
    AssertEqual(IsPalindrom("@@"), true, "@@");
    AssertEqual(IsPalindrom("!@# #@!"), true, "!@# #@!");
    AssertEqual(IsPalindrom("madam"), true, "madam");
    AssertEqual(IsPalindrom("baobab"), false, "baobab");
    AssertEqual(IsPalindrom(" weew "), true, " weew ");
    AssertEqual(IsPalindrom("f f ff f f"), true, "f f ff f f");
    AssertEqual(IsPalindrom("f f f f f"), true, "f f f f f");
    AssertEqual(IsPalindrom("A  L L A"), false, "A  L L A");
    AssertEqual(IsPalindrom("mada m"), false, "mada m");
    AssertEqual(IsPalindrom(" weew   "), false, " weew   ");
    AssertEqual(IsPalindrom("   weew "), false, "   weew ");
    AssertEqual(IsPalindrom("qwertyTrewq"), false, "qwertyTrewq");
    AssertEqual(IsPalindrom("qwertytrewq"), true, "qwertytrewq");
    AssertEqual(IsPalindrom("qwerttrewq"), true, "qwerttrewq");
    AssertEqual(IsPalindrom("qwertytrewQ"), false, "qwertytrewQ");
    AssertEqual(IsPalindrom("Q wer ewQ"), false, "Q wer ewQ");
    Assert(!IsPalindrom(" ABCCBA"), " ABCCBA");
    Assert(!IsPalindrom("ABCCBA "), "ABCCBA ");
    Assert(!IsPalindrom("ABCCB A"), "ABCCB A");
    Assert(!IsPalindrom("A BCCBA"), "A BCCBA");
    Assert(!IsPalindrom("AB CCBA"), "AB CCBA");
    Assert(!IsPalindrom("ABCC BA"), "ABCC BA");
    Assert(!IsPalindrom("AB CCBA"), "AB CCBA");
    Assert(!IsPalindrom("ABCcBA"), "ABCcBA");
    Assert(!IsPalindrom("ABC CbA"), "ABC CbA");
    Assert(!IsPalindrom("ABC cbA"), "ABC cbA");
    Assert(!IsPalindrom("wasitacaRoracatisaw"), "wasitacaRoracatisaw");
    Assert(!IsPalindrom("wasitacAroracatisaw"), "wasitacAroracatisaw");
    Assert(!IsPalindrom("wasitaCaroracatisaw"), "wasitaCaroracatisaw");
    Assert(!IsPalindrom("wasitAcaroracatisaw"), "wasitAcaroracatisaw");
    Assert(!IsPalindrom("wasiTacaroracatisaw"), "wasiTacaroracatisaw");
    Assert(!IsPalindrom("wasItacaroracatisaw"), "wasItacaroracatisaw");
    Assert(!IsPalindrom("waSitacaroracatisaw"), "waSitacaroracatisaw");
    Assert(!IsPalindrom("wAsitacaroracatisaw"), "wAsitacaroracatisaw");
    Assert(!IsPalindrom("wasitacaRracatisaw"), "wasitacaRoracatisaw");
    Assert(!IsPalindrom("wasitacArracatisaw"), "wasitacAroracatisaw");
    Assert(!IsPalindrom("wasitaCarracatisaw"), "wasitaCaroracatisaw");
    Assert(!IsPalindrom("wasitAcarracatisaw"), "wasitAcaroracatisaw");
    Assert(!IsPalindrom("wasiTacarracatisaw"), "wasiTacaroracatisaw");
    Assert(!IsPalindrom("wasItacarracatisaw"), "wasItacaroracatisaw");
    Assert(!IsPalindrom("waSitacarracatisaw"), "waSitacaroracatisaw");
    Assert(!IsPalindrom("wAsitacarracatisaw"), "wAsitacaroracatisaw");
    Assert(!IsPalindrom("ZBCDmadamDCBA"), "ABCDmadamDCBA");
    Assert(!IsPalindrom("ABCDmadamDCBZ"), "ABCDmadamDCBZ");
    Assert(IsPalindrom("madam"), "madam");
    Assert(IsPalindrom("wasitacaroracatisaw"), "wasitacaroracatisaw");
    Assert(IsPalindrom("a a"), "a a");
    Assert(IsPalindrom("a"), "TestSingle");
    Assert(IsPalindrom(""), "TestEmpty");
}

int main() {
    TestRunner runner;
    runner.RunTest(TestSomething, "Something");

    return 0;
}
