#include <iostream>
#include <cmath>
using namespace std;

class Shape {
private:
    double radius;
    double length;
    double width;

public:
    // Constructor for Rectangle
    Shape(double l, double w) : radius(0), length(l), width(w) {
        cout << "Rectangle object created." << endl;
    }

    // Constructor for Circle
    Shape(double r) : radius(r), length(0), width(0) {
        cout << "Circle object created." << endl;
    }

    double calcPerimeterRectangle() {
        return 2 * (length + width);
    }

    double calcPerimeterCircle() {
        return 2 * M_PI * radius;
    }

    ~Shape() {
        cout << "Shape object destroyed." << endl;
    }
};

int main() {
    Shape rect(10.0, 5.0);
    cout << "Perimeter of Rectangle: " << rect.calcPerimeterRectangle() << endl;

    Shape circ(7.0);
    cout << "Perimeter of Circle: " << circ.calcPerimeterCircle() << endl;

    return 0;
}
