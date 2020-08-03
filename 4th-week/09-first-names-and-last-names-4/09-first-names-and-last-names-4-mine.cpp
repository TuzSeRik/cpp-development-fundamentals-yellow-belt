#include <map>
#include <string>

using namespace std;

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        firstNameHistory[year] = first_name;
    }

    void ChangeLastName(int year, const string& last_name) {
        lastNameHistory[year] = last_name;
    }

    string GetFullName(int year) {
        string firstName;
        string lastName;
        // The needed name is always name before first name after needed year,
        // unless year after is the first entry in map
        firstName = (firstNameHistory.upper_bound(year) != begin(firstNameHistory))
                ? prev(firstNameHistory.upper_bound(year))->second : "";
        lastName = (lastNameHistory.upper_bound(year) != begin(lastNameHistory))
                ? prev(lastNameHistory.upper_bound(year))->second : "";

        if (firstName.empty() && lastName.empty())
            return "Incognito";
        if (lastName.empty())
            return firstName + " with unknown last name";
        if (firstName.empty())
            return lastName + " with unknown first name";

        return firstName + " " + lastName;
    }
private:
    map<int, string> firstNameHistory;
    map<int, string> lastNameHistory;
};
