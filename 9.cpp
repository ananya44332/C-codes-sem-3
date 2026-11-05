#include <iostream>
using namespace std;

class ClassB; // Forward declaration

class ClassA {
private:
    int valA;

public:
    ClassA(int v) : valA(v) {}
    void display() const { cout << "ClassA value: " << valA << endl; }
    friend void swapValues(ClassA &a, ClassB &b);
};

class ClassB {
private:
    int valB;

public:
    ClassB(int v) : valB(v) {}
    void display() const { cout << "ClassB value: " << valB << endl; }
    friend void swapValues(ClassA &a, ClassB &b);
};

void swapValues(ClassA &a, ClassB &b) {
    int temp = a.valA;
    a.valA = b.valB;
    b.valB = temp;
}

int main() {
    ClassA objA(100);
    ClassB objB(200);

    cout << "Before Swap:\n";
    objA.display();
    objB.display();

    swapValues(objA, objB);

    cout << "\nAfter Swap:\n";
    objA.display();
    objB.display();

    return 0;
}
