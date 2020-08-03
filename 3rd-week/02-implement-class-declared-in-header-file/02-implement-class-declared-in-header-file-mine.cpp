#include <sstream>

#include "phone_number.h"
// Transfer string to stringstream and then linearly process it
PhoneNumber::PhoneNumber(const string& international_number) {
    stringstream input;
    input << international_number;

    if (input.peek() == '+' && input.str().find('-') != string::npos) {
        input.ignore(1);
        getline(input, country_code_, '-');
    }
    else
        throw invalid_argument("Country code problems");

    if (input.str().find('-') != string::npos) {
        getline(input, city_code_, '-');
    }
    else
        throw invalid_argument("City code problems");

    if (!input.eof())
        getline(input, local_number_);
    else
        throw invalid_argument("Local number problems");
    // Don't forget to check that there actually was something between dashes
    if (country_code_.empty() || city_code_.empty() || local_number_.empty())
        throw invalid_argument("Some of fields are empty");
}

string PhoneNumber::GetCountryCode() const {
    return country_code_;
}

string PhoneNumber::GetCityCode() const {
    return city_code_;
}

string PhoneNumber::GetLocalNumber() const {
    return local_number_;
}

string PhoneNumber::GetInternationalNumber() const {
    return "+" + country_code_ + "-" + city_code_ + "-" + local_number_;
}
