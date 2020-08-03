#include <sstream>
#include "database.h"
// If event is inserted to set, then insert it to vector to preserve order
void Database::Add(const Date& date, const string& event) {
    if (elements[date].insert(event).second)
        db[date].push_back(event);
}
// Simple print
void Database::Print(ostream& os) const {
    for (const auto& [date, events] : db)
        for (const auto& event : events)
            os << date << " " << event << endl;
}
// Return last event of date, previous to bigger than provided, unless bigger is the first
string Database::Last(const Date& date) const {
    auto it = db.upper_bound(date);
    if (it == begin(db))
        return "No entries";
    --it;

    return it->first.toString() + " " + it->second.back();
}
