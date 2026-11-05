#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Unary Pre-increment
    Complex& operator++() {
        ++real;
        ++imag;
        return *this;
    }

    // Unary Pre-decrement
    Complex& operator--() {
        --real;
        --imag;
        return *this;
    }

    // Binary +
    Complex operator+(const Complex &c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    // Binary -
    Complex operator-(const Complex &c) const {
        return Complex(real - c.real, imag - c.imag);
    }

    void display() const {
        cout << real << (imag >= 0 ? " + " : " - ") << abs(imag) << "i" << endl;
    }
};

int main() {
    Complex c1(4.5, 3.2), c2(2.1, 1.5);

    cout << "c1 = "; c1.display();
    cout << "c2 = "; c2.display();

    Complex c3 = c1 + c2;
    cout << "\nc1 + c2 = "; c3.display();

    Complex c4 = c1 - c2;
    cout << "c1 - c2 = "; c4.display();

    ++c1;
    cout << "\nAfter ++c1, c1 = "; c1.display();

    --c2;
    cout << "After --c2, c2 = "; c2.display();

    return 0;
}
