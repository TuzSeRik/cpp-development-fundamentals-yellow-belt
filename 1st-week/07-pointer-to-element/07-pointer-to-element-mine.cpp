#include <map>

using namespace std;

template<typename X, typename Y>
Y& GetRefStrict(map<X, Y>& mp, X key) {
    if (mp.count(key )== 0)
        throw runtime_error("");

    return mp[key];
}
