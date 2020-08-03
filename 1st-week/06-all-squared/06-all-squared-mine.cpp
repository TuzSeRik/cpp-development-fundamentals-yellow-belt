#include <vector>
#include <map>

using namespace std;
// Virtual functions declaration for task grader
template<typename T> vector<T> operator *(vector<T> lhs, vector<T> rhs);
template<typename X, typename Y> pair<X, Y> operator *(pair<X, Y> lhs, pair<X, Y> rhs);
template<typename X, typename Y> map<X, Y> operator *(map<X, Y> lhs, map<X, Y> rhs);
template<typename T> T Sqr(T v);

template<typename T>
vector<T> operator *(vector<T> lhs, vector<T> rhs) {
    vector<T> result;
    for (int i = 0; i < rhs.size(); ++i) {
        result.push_back(lhs[i] * rhs[i]);
    }

    return result;
}

template<typename X, typename Y>
pair<X, Y> operator *(pair<X, Y> lhs, pair<X, Y> rhs) {
    return make_pair(lhs.first * rhs.first, lhs.second * rhs.second);
}
// Using while with iterators because of impossibility of linear for iteration through two maps
template<typename X, typename Y>
map<X, Y> operator *(map<X, Y> lhs, map<X, Y> rhs) {
    map<X, Y> result = lhs;
    auto lhsIterator = begin(lhs), rhsIterator = begin(rhs);
    while (lhsIterator != end(lhs)) {
        result[lhsIterator->first] = lhsIterator->second * rhsIterator->second;
        lhsIterator++;
        rhsIterator++;
    }

    return result;
}

template<typename T>
T Sqr(T v) {
    return v * v;
}
