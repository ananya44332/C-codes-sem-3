#include <iostream>
using namespace std;

void callByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "Inside Call by Value - a: " << a << ", b: " << b << endl;
}

void callByReference(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "Inside Call by Reference - a: " << a << ", b: " << b << endl;
}

int main() {
    int x = 10, y = 20;

    cout << "--- Before Swap ---" << endl;
    cout << "x = " << x << ", y = " << y << endl;

    cout << "\n--- Call by Value ---" << endl;
    callByValue(x, y);
    cout << "In Main after Call by Value - x: " << x << ", y: " << y << " (No change)" << endl;

    cout << "\n--- Call by Reference ---" << endl;
    callByReference(x, y);
    cout << "In Main after Call by Reference - x: " << x << ", y: " << y << " (Values modified)" << endl;

    return 0;
}
