#include<iostream>
using namespace std;

class HR;

class Employee {
private:
    string name;
    double salary;
    int workHours;
public:
    Employee(string n, double s, int w) : name(n), salary(s), workHours(w) {}

    friend class HR;
    friend void finalsal(Employee& e, double hourlyrate, double bonus = 0);

    void displaySalary() {
        cout << "Employee: " << name << "\nSalary: " << salary << endl;
    }
};

class HR {
public:
    void updateSalary(Employee& e, double sal) {
        e.salary = sal;
    }
};

void finalsal(Employee& e, double hourlyrate, double bonus) {
    e.salary = bonus + hourlyrate * e.workHours;
}

int main() {
    Employee e("Abdullah Kamran", 1200, 12);

    e.displaySalary();

    HR hr;
    hr.updateSalary(e, 1500);

    e.displaySalary();

    finalsal(e, 15, 120);

    e.displaySalary();

    return 0;
}
