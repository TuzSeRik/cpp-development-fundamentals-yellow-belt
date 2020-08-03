#pragma once

#include <iostream>

using namespace std;

class Date {
public:
    Date() = default;

    Date(const int& year, const int& month, const int& day) : year(year), month(month), day(day) {}

    [[nodiscard]] int Year() const;

    [[nodiscard]] int Month() const;

    [[nodiscard]] int Day() const;

    [[nodiscard]] string toString() const;

private:
    int year, month, day;
};

istream& operator >>(istream& is, Date& date);

ostream& operator <<(ostream& os, const Date& date);

bool operator ==(const Date& lhs, const Date& rhs);

bool operator !=(const Date& lhs, const Date& rhs);

bool operator >(const Date& lhs, const Date& rhs);

bool operator >=(const Date& lhs, const Date& rhs);

bool operator <(const Date& lhs, const Date& rhs);

bool operator <=(const Date& lhs, const Date& rhs);

Date ParseDate(istream& is);
