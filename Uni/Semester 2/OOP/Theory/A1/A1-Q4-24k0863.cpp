#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Payment {
    int studentID;
    bool isPaid;

public:
    Payment(int id) : studentID(id), isPaid(false) {}

    void pay() { isPaid = true; }
    bool isPaymentComplete() { return isPaid; }
};

class Student {
    int studentID;
    string name;
    Payment payment;

public:
    Student(int id, string& n) : studentID(id), name(n), payment(id) {}

    void paySemesterFee() { payment.pay(); }
    bool hasPaidFee() { return payment.isPaymentComplete(); }
    int getID() { return studentID; }
    string getName() { return name; }
};

class Route {
    int routeID;
    vector<string> stops;

public:
    Route(int id) : routeID(id) {}

    void addStop(string& stop) { stops.push_back(stop); }
    vector<string>& getStops() { return stops; }
};

class Bus {
    int busID;
    vector<int> attendanceRecord;

public:
    Bus(int id) : busID(id) {}

    void recordAttendance(int studentID) {
        attendanceRecord.push_back(studentID);
        cout << "Attendance recorded for Student ID: " << studentID << endl;
    }

    void displayAttendance() {
        cout << "Attendance Record for Bus ID: " << busID << endl;
        for (int id : attendanceRecord) {
            cout << "Student ID: " << id << " | Present: Yes" << endl;
        }
    }

    int getBusID() {
        return busID;
    }
};

class TransportationSystem {
    vector<Student> students;
    vector<Route> routes;
    vector<Bus> buses;

public:
    void registerStudent(int id, string name) {
        students.emplace_back(id, name);
        cout << "Student Registered: " << name << " (ID: " << id << ")" << endl;
    }

    bool getStudentByID(int id, Student& foundStudent) {
        for (auto& student : students) {
            if (student.getID() == id) {
                foundStudent = student;
                return true;
            }
        }
        return false;
    }

    bool getBusByID(int id, Bus& foundBus) {
        for (auto& bus : buses) {
            if (bus.getBusID() == id) {
                foundBus = bus;
                return true;
            }
        }
        return false;
    }

    void addRoute(int id) {
        routes.emplace_back(id);
        cout << "Route added with ID: " << id << endl;
    }

    void addBus(int id) {
        buses.emplace_back(id);
        cout << "Bus added with ID: " << id << endl;
    }

    void verifyPaymentAndRecordAttendance(int studentID, int busID) {
        for (auto& student : students) {
            if (student.getID() == studentID) {
                if (student.hasPaidFee()) {
                    for (auto& bus : buses) {
                        if (bus.getBusID() == busID) {
                            bus.recordAttendance(studentID);
                            return;
                        }
                    }
                    cout << "Bus not found." << endl;
                } else {
                    cout << "Payment is pending for Student ID: " << studentID << endl;
                }
                return;
            }
        }
        cout << "Student not found." << endl;
    }

    void displayBusAttendance(int busID) {
        for (auto& bus : buses) {
            if (bus.getBusID() == busID) {
                bus.displayAttendance();
                return;
            }
        }
        cout << "Bus not found." << endl;
    }

    void payStudentFee(int studentID) {
        for (auto& student : students) {
            if (student.getID() == studentID) {
                student.paySemesterFee();
                cout << "Student ID " << studentID << " has paid the semester fee." << endl;
                return;
            }
        }
        cout << "Student not found." << endl;
    }
};

int main() {
    TransportationSystem system;

    system.registerStudent(1, "Ali");
    system.registerStudent(2, "Ahmed");

    system.addRoute(101);
    system.addBus(1);

    system.verifyPaymentAndRecordAttendance(1, 1);
    system.verifyPaymentAndRecordAttendance(2, 1);

    system.payStudentFee(1);
    system.payStudentFee(2);

    system.verifyPaymentAndRecordAttendance(1, 1);
    system.verifyPaymentAndRecordAttendance(2, 1);

    system.displayBusAttendance(1);


}