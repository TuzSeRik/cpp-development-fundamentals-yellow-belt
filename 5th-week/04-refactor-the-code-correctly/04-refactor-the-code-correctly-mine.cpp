#include <iostream>
#include <string>
#include <vector>

using namespace std;
// Adding base class to all three types of persons
class Human {
public:
    // Adding base constructor with Name and "Type", which helps reduce all methods to one implementation
    Human(const string& name, const string& type) : Name(name), type(type) {}
    // Reducing boilerplate
    ostream& Printer() const {
        return cout << type << ": " << Name;
    }
    // Using added "Type" abstraction to simplify all walks to one default
    // (because they differs only by part, mentioning person's type)
    virtual void Walk(const string& destination) const {
        cout << type << ": " << Name << " walks to: " << destination << endl;
    }
    // Storing common variables to base class
    const string Name;
    const string type;
};

class Student : public Human{
public:
    // Now using base class constructor with every class, initialising type by hands
    Student(const string& name, const string& favouriteSong) : Human(name, "Student"),
                                                               FavouriteSong(favouriteSong) {}
    // The only overridden "Walk", because it contains two actions instead of one,
    // which we call from base class
    void Walk(const string& destination) const override {
        Human::Walk(destination);
        SingSong();
    }

    void SingSong() const {
        Printer() << " sings a song: " << FavouriteSong << endl;
    }

    void Learn() const {
        Printer() << " learns" << endl;
    }

    const string FavouriteSong;
};

class Teacher : public Human {
public:
    Teacher(const string& name, const string& subject) : Human(name, "Teacher"), Subject(subject) {}

    void Teach() const {
        Printer() << " teaches: " << Subject << endl;
    }

    const string Subject;
};

class Policeman : public Human {
public:
    Policeman(const string& name) : Human(name, "Policeman") {}
    // By using base class and "Type", we can have only one implementation of "Check",
    // which fits all needs
    void Check(const Human& h) const {
        Printer() << " checks " << h.type << ". " << h.type << "'s Name is: " << h.Name << endl;
    }
};
// As previously, because of base class, we can have only one implementation of function
// to work with all classes
void VisitPlaces(const Human& h, const vector<string>& places) {
    for (const auto& p : places) {
        h.Walk(p);
    }
}
// Also I added const modifiers to ensure security of data and comments.
// I also could add getters to variables, but with const modifiers it seems unnecessary
int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}
