#include <iostream>
using namespace std;

class InvalidAgeException {
public:
    string message;
    InvalidAgeException(string msg) {
        message=msg;
    }
};

class InvalidSalaryException {
public:
    string message;
    InvalidSalaryException(string msg) {
        message=msg;
    }
};

class InvalidHeightException {
public:
    string message;
    InvalidHeightException(string msg) {
        message=msg;
    }
};

class UserProfile {
private:
    int age;
    double salary;
    double height;

public:
    void setAge(int a) {
        if (a <= 0 || a >= 120) {
            throw InvalidAgeException("Age must be between 1 and 119");
        }
        age=a;
    }

    void setSalary(double s) {
        if (s <= 0) {
            throw InvalidSalaryException("Salary must be positive");
        }
        salary=s;
    }

    void setHeight(double h) {
        if (h <= 0) {
            throw InvalidHeightException("Height must be positive");
        }
        height=h;
    }
};

int main() {
    UserProfile user;
    int ageInput;
    double salaryInput, heightInput;

    cout<<"Enter age: ";
    cin>>ageInput;
    try {
        user.setAge(ageInput);
    } catch (InvalidAgeException e) {
        cout<<"InvalidAgeException caught: "<<e.message<<endl;
    }

    cout<<"Enter salary: ";
    cin>>salaryInput;
    try {
        user.setSalary(salaryInput);
    } catch (InvalidSalaryException e) {
        cout<<"InvalidSalaryException caught: "<<e.message<<endl;
    }

    cout<<"Enter height: ";
    cin>>heightInput;
    try {
        user.setHeight(heightInput);
    } catch (InvalidHeightException e) {
        cout<<"InvalidHeightException caught: "<<e.message<<endl;
    }

    return 0;
}
