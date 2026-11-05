#include <iostream>
#include <cstring>
using namespace std;

class Person {
private:
    char name[64];
    int age;
    char address[64];
    double basicSalary;
    double allowance;
    double grossSalary;

public:
    Person() : age(0), basicSalary(0), allowance(0), grossSalary(0) {
        name[0] = '\0';
        address[0] = '\0';
    }

    Person(const char n[], int a, const char addr[], double bSalary, double allow) {
        strncpy(name, n, 63);
        name[63] = '\0';
        age = a;
        strncpy(address, addr, 63);
        address[63] = '\0';
        basicSalary = bSalary;
        allowance = allow;
        grossSalary = basicSalary + allowance;
    }

    int getAge() const { return age; }

    void displaySalarySlip() const {
        cout << "\n---------------- SALARY SLIP ----------------\n";
        cout << "Name        : " << name << endl;
        cout << "Age         : " << age << endl;
        cout << "Address     : " << address << endl;
        cout << "Basic Pay   : $" << basicSalary << endl;
        cout << "Allowance   : $" << allowance << endl;
        cout << "Gross Salary: $" << grossSalary << endl;
        cout << "---------------------------------------------\n";
    }
};

inline void findAgeExtremes(Person persons[], int size, int &youngest, int &eldest) {
    youngest = persons[0].getAge();
    eldest = persons[0].getAge();
    for (int i = 1; i < size; i++) {
        if (persons[i].getAge() < youngest) youngest = persons[i].getAge();
        if (persons[i].getAge() > eldest) eldest = persons[i].getAge();
    }
}

int main() {
    Person group[10] = {
        Person("Alice", 25, "12 Main St", 3000, 500),
        Person("Bob", 30, "45 Park Ave", 4000, 600),
        Person("Charlie", 22, "89 Broadway", 2500, 400),
        Person("Diana", 45, "12 Elm St", 5500, 800),
        Person("Ethan", 29, "67 Maple St", 3800, 500),
        Person("Fiona", 34, "23 Pine St", 4200, 650),
        Person("George", 19, "90 Oak St", 2000, 300),
        Person("Hannah", 50, "11 Cedar Rd", 6000, 1000),
        Person("Ian", 41, "34 Birch Ln", 5000, 750),
        Person("Julia", 28, "78 Lake Rd", 3600, 450)
    };

    int minAge, maxAge;
    findAgeExtremes(group, 10, minAge, maxAge);

    cout << "Youngest Person Age: " << minAge << " years" << endl;
    cout << "Eldest Person Age  : " << maxAge << " years" << endl;

    cout << "\nDisplaying Salary Slip for Person 1:";
    group[0].displaySalarySlip();

    return 0;
}
