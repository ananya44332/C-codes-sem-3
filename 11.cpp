#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
    int rollNo;
    string name;

public:
    void setStudent(int r, string n) {
        rollNo = r;
        name = n;
    }

    void displayStudent() const {
        cout << "Roll No: " << rollNo << "\nName   : " << name << endl;
    }
};

// Derived via Virtual Base Class to resolve diamond problem ambiguity
class Academic : virtual public Student {
protected:
    double academicScore;

public:
    void setAcademicScore(double score) {
        academicScore = score;
    }
};

class Sports : virtual public Student {
protected:
    double sportsScore;

public:
    void setSportsScore(double score) {
        sportsScore = score;
    }
};

class FinalResult : public Academic, public Sports {
private:
    double totalScore;

public:
    void calculateTotal() {
        totalScore = academicScore + sportsScore;
    }

    void displayFinalResult() {
        displayStudent();
        cout << "Academic Score : " << academicScore << endl;
        cout << "Sports Score   : " << sportsScore << endl;
        cout << "Total Marks    : " << totalScore << endl;
    }
};

int main() {
    FinalResult student;
    student.setStudent(101, "John Doe");
    student.setAcademicScore(88.5);
    student.setSportsScore(10.0);
    student.calculateTotal();

    cout << "========== FINAL STUDENT REPORT ==========\n";
    student.displayFinalResult();

    return 0;
}
