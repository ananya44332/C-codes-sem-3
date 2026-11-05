#include <iostream>
#include <cmath>
using namespace std;

// Area of Circle
double AREA(double radius) {
    return M_PI * radius * radius;
}

// Area of Rectangle
double AREA(double length, double width) {
    return length * width;
}

// Area of Triangle (Heron's Formula)
double AREA(double a, double b, double c) {
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {
    cout << "Area of Circle (r = 5): " << AREA(5.0) << endl;
    cout << "Area of Rectangle (10 x 4): " << AREA(10.0, 4.0) << endl;
    cout << "Area of Triangle (sides 3, 4, 5): " << AREA(3.0, 4.0, 5.0) << endl;
    return 0;
}
