#include <iostream>
#include <iomanip>
#include <memory>
#include <cmath>

using namespace std;
// Base class for all figures
class Figure {
public:
    virtual string Name() = 0;

    virtual double Perimeter() = 0;

    virtual double Area() = 0;
};
// Just sequentially implement abstract class three times
class Triangle : public Figure {
public:
    Triangle(double a, double b, double c) : a(a), b(b), c(c) {}

    string Name() override {
        return "TRIANGLE";
    }

    double Perimeter() override {
        return p;
    }

    double Area() override {
        return sqrt(p / 2 * (p / 2 - a) * (p / 2 - b) * (p / 2 - c));
    }

private:
    const double a, b, c, p = a + b + c;
};

class Rect : public Figure {
public:
    Rect(double a, double b) : a(a), b(b) {}

    string Name() override {
        return "RECT";
    }

    double Perimeter() override {
        return (a + b) * 2;
    }

    double Area() override {
        return a * b;
    }

private:
    const double a, b;
};

class Circle : public Figure {
public:
    Circle(double r) : r(r) {}

    string Name() override {
        return "CIRCLE";
    }

    double Perimeter() override {
        return 2 * r * 3.14;
    }

    double Area() override {
        return 3.14 * pow(r, 2);
    }

private:
    const double r;
};

shared_ptr<Figure> CreateFigure(istream& input) {
    string figure;
    input >> figure;

    if (figure == "TRIANGLE") {
        double a, b, c;
        input >> a >> b >> c;
        return make_shared<Triangle>(a, b, c);
    }

    if (figure == "RECT") {
        double a, b;
        input >> a >> b;
        return make_shared<Rect>(a, b);
    }

    if (figure == "CIRCLE") {
        double r;
        input >> r;
        return make_shared<Circle>(r);
    }

    return shared_ptr<Figure>();
}
