#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isNumPalindrome(int num) {
    int orig = num, rev = 0;
    while (num > 0) {
        rev = rev * 10 + (num % 10);
        num /= 10;
    }
    return orig == rev;
}

bool isStrPalindrome(string str) {
    string revStr = str;
    reverse(revStr.begin(), revStr.end());
    return str == revStr;
}

int main() {
    int num;
    string str;

    cout << "Enter an integer: ";
    cin >> num;
    if (isNumPalindrome(num))
        cout << num << " is a Palindrome Number.\n";
    else
        cout << num << " is NOT a Palindrome Number.\n";

    cout << "Enter a string: ";
    cin >> str;
    if (isStrPalindrome(str))
        cout << str << " is a Palindrome String.\n";
    else
        cout << str << " is NOT a Palindrome String.\n";

    return 0;
}
