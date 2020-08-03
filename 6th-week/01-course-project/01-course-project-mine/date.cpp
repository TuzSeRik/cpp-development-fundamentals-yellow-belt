#include <iomanip>
#include <vector>

#include "date.h"

int Date::Year() const {
    return year;
}

int Date::Month() const {
    return month;
}

int Date::Day() const {
    return day;
}
// Universal method to convert date to string without operator << - I think using stringstream to get a string is a flaw
string Date::toString() const {
    return
    ((year >= 1000) ? to_string(year) :
        ((year >= 100) ? "0" + to_string(year) :
            ((year) >= 10) ? "00" + to_string(year) :
            "000" + to_string(year))) + "-" +
    ((month >= 10) ? to_string(month) : "0" + to_string(month)) + "-" +
    ((day >= 10) ? to_string(day) : "0" + to_string(day));
}

istream& operator >>(istream& is, Date& date) {
    int year, month, day;
    is >> year;
    is.ignore(1);
    is >> month;
    is.ignore(1);
    is >> day;

    date = Date(year, month, day);

    return is;
}

ostream& operator <<(ostream& os, const Date& date) {
    os << setw(4) << setfill('0') << date.Year() << "-"
       << setw(2) << setfill('0') << date.Month() << "-"
       << setw(2) << setfill('0') << date.Day();

    return os;
}
// Bunch of logical operators for date, comparing vectors
bool operator ==(const Date& lhs, const Date& rhs) {
    return vector<int>{lhs.Year(), lhs.Month(), lhs.Day()} ==
           vector<int>{rhs.Year(), rhs.Month(), rhs.Day()};
}

bool operator !=(const Date& lhs, const Date& rhs) {
    return vector<int>{lhs.Year(), lhs.Month(), lhs.Day()} !=
           vector<int>{rhs.Year(), rhs.Month(), rhs.Day()};
}

bool operator >(const Date& lhs, const Date& rhs) {
    return vector<int>{lhs.Year(), lhs.Month(), lhs.Day()} >
           vector<int>{rhs.Year(), rhs.Month(), rhs.Day()};
}

bool operator >=(const Date& lhs, const Date& rhs) {
    return vector<int>{lhs.Year(), lhs.Month(), lhs.Day()} >=
           vector<int>{rhs.Year(), rhs.Month(), rhs.Day()};
}

bool operator <(const Date& lhs, const Date& rhs) {
    return vector<int>{lhs.Year(), lhs.Month(), lhs.Day()} <
           vector<int>{rhs.Year(), rhs.Month(), rhs.Day()};
}

bool operator <=(const Date& lhs, const Date& rhs) {
    return vector<int>{lhs.Year(), lhs.Month(), lhs.Day()} <=
           vector<int>{rhs.Year(), rhs.Month(), rhs.Day()};
}

Date ParseDate(istream& is) {
    Date date;
    is >> date;

    return date;
}
