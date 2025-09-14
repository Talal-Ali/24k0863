#include <iostream>
#include <string>
using namespace std;

class HR;  
class Manager;  

class Employee {
private:
    string name;
    double salary;
    
public:
    Employee(string n, double s) : name(n), salary(s) {}
    
    friend class HR;  
    friend class Manager;  

    string getName() const {
        return name;
    }
    
    double getSalary() const {
        return salary;
    }
};

class HR {
public:
    void updateSalary(Employee &emp, double newSalary) {
        emp.salary = newSalary;
        cout << "Salary of " << emp.getName() << " updated to $" << emp.salary << endl;
    }
};

class Manager {
public:
    void viewSalary(Employee &emp) {
        cout << "Salary of " << emp.getName() << " is $" << emp.getSalary() << endl;
    }
};

int main() {
    Employee emp1("Shaheer", 50000);
    HR hr;
    hr.updateSalary(emp1, 60000);
    Manager mgr;
    mgr.viewSalary(emp1);

    return 0;
}
