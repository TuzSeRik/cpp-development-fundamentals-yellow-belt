#pragma once

#include <map>
#include <vector>
#include <unordered_set>
#include <algorithm>

#include "date.h"

class Database {
public:
    void Add(const Date& date, const string& event);

    void Print(ostream& os) const;
    // Implementing template method in header file
    template<typename Predicate>
    int RemoveIf(const Predicate& predicate) {
        size_t result = 0;
        // Using deletion-while-iterating method
        auto it = begin(db);
        while (it != end(db)){
            auto border = stable_partition(begin(it->second), end(it->second),
                                           [it, predicate](const string &event) -> bool {
                                               return predicate(it->first, event);
                                           });
            auto tmp = it->second.size();
            // Saving changed vector and set
            it->second = {border, end(it->second)};
            elements[it->first] = {begin(it->second), end(it->second)};
            // Calculating size difference
            result += tmp - it->second.size();
            // If zero events remains on date - delete date and go next, else just go next
            if (it->second.empty())
                it = db.erase(it);
            else
                it++;
        }

        return result;
    }

    template<typename Predicate>
    vector<string> FindIf(const Predicate& predicate) const {
        vector<string> result;
        // Simple find, returning vector with all events, returning true for predicate
        for (const auto& entry : db)
            for (const auto& event : entry.second)
                if (predicate(entry.first, event)) {
                    result.push_back(entry.first.toString() + " " + event);
                }

        return result;
    }

    [[nodiscard]] string Last(const Date& date) const;

private:
    // Map with vector to save order, map with set to check uniqueness with less operations;
    map<Date, vector<string>> db;
    map<Date, unordered_set<string>> elements;
};
