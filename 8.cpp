#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
    int rollNo;
    string name;

public:
    void getStudentData() {
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cin.ignore();
        cout << "Enter Student Name: ";
        getline(cin, name);
    }

    void displayStudentData() const {
        cout << "\nRoll No: " << rollNo << endl;
        cout << "Name   : " << name << endl;
    }
};

class Exam : public Student {
protected:
    double marks[6];

public:
    void getMarks() {
        getStudentData();
        cout << "Enter marks for 6 subjects:\n";
        for (int i = 0; i < 6; i++) {
            cout << "Subject " << i + 1 << ": ";
            cin >> marks[i];
        }
    }

    void displayMarks() const {
        displayStudentData();
        cout << "Marks: ";
        for (int i = 0; i < 6; i++) {
            cout << marks[i] << " ";
        }
        cout << endl;
    }
};

class Result : public Exam {
private:
    double totalMarks;
    double percentage;

public:
    void calculateResult() {
        getMarks();
        totalMarks = 0;
        for (int i = 0; i < 6; i++) {
            totalMarks += marks[i];
        }
        percentage = totalMarks / 6.0;
    }

    void displayResult() const {
        displayMarks();
        cout << "Total Marks: " << totalMarks << " / 600" << endl;
        cout << "Percentage : " << percentage << "%" << endl;
    }
};

int main() {
    Result studentResult;
    studentResult.calculateResult();
    cout << "\n================ RESULT ================";
    studentResult.displayResult();
    return 0;
}
