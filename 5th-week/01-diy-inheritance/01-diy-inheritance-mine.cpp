#include <iostream>

using namespace std;
// The day I realized that including <string> is not required
class Animal {
public:
    Animal(const string& name) : Name(name) {}

    const string Name;
};

class Dog : public Animal {
public:
    Dog(const string& name) : Animal(name){}

    void Bark() {
        cout << Name << " barks: woof!" << endl;
    }
};
