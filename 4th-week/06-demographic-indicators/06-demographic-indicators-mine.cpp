#include <vector>
#include <numeric>
#include <functional>
#include <iostream>

using namespace std;
// Solution is pretty straight-forward and abstract - for every required group print group name and median age
// To do this, create vector of every needed pair condition-name
vector<pair<function<bool(Person)>, string>> groups = {
        {{[](Person subject) -> bool {
            return true;}}, ""},
        {{[](Person subject) -> bool {
            return subject.gender == Gender::FEMALE;}}, "females"},
        {{[](Person subject) -> bool {
            return subject.gender == Gender::MALE;}}, "males"},
        {{[](Person subject) -> bool {
            return subject.gender == Gender::FEMALE && subject.is_employed;}}, "employed females"},
        {{[](Person subject) -> bool {
            return subject.gender == Gender::FEMALE && !subject.is_employed;}}, "unemployed females"},
        {{[](Person subject) -> bool {
            return subject.gender == Gender::MALE && subject.is_employed;}}, "employed males"},
        {{[](Person subject) -> bool {
            return subject.gender == Gender::MALE && !subject.is_employed;}}, "unemployed males"}
};
// Now just get all group members by partitioning with conditions from vector
// and output connected group name with resulting median age
// It is pretty elegant but unefficient algorithm
// It could be improved and still stay elegant by replacing conditions with iterators,
// gained as in author's solution - by 1 full and 2 partial partitioning
void PrintStats(vector<Person> persons) {
    for (const auto& group : groups)
        cout << "Median age" << (group.second.empty() ? "" : " for " + group.second) << " = "
        << ComputeMedianAge(begin(persons), partition(begin(persons), end(persons), group.first)) << endl;
}
