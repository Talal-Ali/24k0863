#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

class User;
class Student;
class Teacher;
class Staff;

class Stop {
    int stopID;
    string stopName;
    int routeID;
public:
    Stop(int id, string name, int route) : stopID(id), stopName(name), routeID(route) {}
    void getStopDetails() const {
        cout << "Stop ID: " << stopID << ", Name: " << stopName << ", Route: " << routeID << endl;
    }
    int getStopID(){ 
        return stopID; 
    }
};

class AttendanceSystem {
    vector<pair<int, string>> attendanceRecords;
public:
    void recordAttendance(int userID, const string& timestamp) {
        attendanceRecords.push_back(make_pair(userID, timestamp));
        cout << "Attendance recorded for user ID: " << userID << " at " << timestamp << endl;
    }
    void displayAttendance() const {
        for (const auto& record : attendanceRecords) {
            cout << "User  ID: " << record.first << ", Time: " << record.second << endl;
        }
    }
};

class User {
protected:
    int userID;
    string name;
    float balance;
    bool isActive;
    int assignedStop;
public:
    User(int id, string n, float bal, bool active) : userID(id), name(n), balance(bal), isActive(active), assignedStop(0) {}
    virtual ~User () {}
    virtual void payFees(float amount) = 0;
    void assignStop(int stop) {
        assignedStop = stop;
        cout << "Stop " << stop << " assigned to user " << name << endl;
    }
    void displayUser() const {
        cout << "User  ID: " << userID << ", Name: " << name 
             << ", Balance: $" << balance << ", Active: " << (isActive ? "Yes" : "No")
             << ", Assigned Stop: " << assignedStop << endl;
    }
    int getUserID(){ 
        return userID; 
    }
    bool isUserActive(){ 
        return isActive; 
    }
};

class Student : public User {
public:
    Student(int id, string n) : User(id, n, 0.0, false) {}
    void payFees(float amount) override {
        balance += amount;
        isActive = balance >= 0;
        cout << "Student fees paid. Balance: $" << balance << endl;
    }
};

class Teacher : public User {
public:
    Teacher(int id, string n) : User(id, n, 0.0, false) {}
    void payFees(float amount) override {
        balance += amount;
        isActive = balance >= 0;
        cout << "Teacher fees paid. Balance: $" << balance << endl;
    }
};

class Staff : public User {
public:
    Staff(int id, string n) : User(id, n, 0.0, false) {}
    void payFees(float amount) override {
        balance += amount;
        isActive = balance >= 0;
        cout << "Staff fees paid. Balance: $" << balance << endl;
    }
};

class BusRoute {
    int routeID;
    string routeName;
    vector<Stop> stops;
public:
    BusRoute(int id, string name) : routeID(id), routeName(name) {}
    void addStop(const Stop& stop) { stops.push_back(stop); }
    void displayRoute() const {
        cout << "Route " << routeID << ": " << routeName << endl;
        for (const auto& stop : stops) { 
            stop.getStopDetails(); 
        }
    }
    bool operator==(const BusRoute& other) { 
        return routeID == other.routeID; 
    }
};

class TransportationSystem {
    vector<User*> users;
    vector<BusRoute> routes;
    AttendanceSystem attendance;
    static int userCount;

    User* findUserByID(int userID) {
        for (auto* user : users) {
            if (user->getUserID() == userID) {
                return user;
            }
        }
        return nullptr;
    }

public:
    void registerUser(User* user) {
        users.push_back(user);
        userCount++;
    }

    void assignStop(int userID, int stopID) {
        User* user = findUserByID(userID);
        if (user) {
            user->assignStop(stopID);
        }
    }

    void recordAttendance(int userID) {
        User* user = findUserByID(userID);
        if (user) {
            attendance.recordAttendance(userID, "current_time");
        }
    }

    void payFees(int userID, float amount) {
        User* user = findUserByID(userID);
        if (user) {
            user->payFees(amount);
        }
    }

    void displayAllUsers() const {
        for (const auto* user : users) {
            user->displayUser();
        }
    }

    void displayActiveUsers() const {
        cout << "Total Users: " << userCount << endl;
        for (auto* user : users) {
            if (user->isUserActive()) {
                user->displayUser();
            }
        }
    }

    void addBusRoute(const BusRoute& route) { routes.push_back(route); }
    void displayAllRoutes() const {
        for (const auto& route : routes) {
            route.displayRoute();
        }
    }
};

int TransportationSystem::userCount = 0;

int main() {
    TransportationSystem system;

    Student* s1 = new Student(1, "Alice");
    Teacher* t1 = new Teacher(2, "Bob");
    Staff* st1 = new Staff(3, "Charlie");

    system.registerUser(s1);
    system.registerUser(t1);
    system.registerUser(st1);

    system.payFees(1, 100);
    system.payFees(2, 150);
    system.payFees(3, 200);

    system.assignStop(1, 10);
    system.assignStop(2, 20);
    system.assignStop(3, 30);

    system.recordAttendance(1);
    system.recordAttendance(2);
    system.recordAttendance(3);

    BusRoute r1(1, "North Loop");
    r1.addStop(Stop(10, "Stop A", 1));
    r1.addStop(Stop(11, "Stop B", 1));

    system.addBusRoute(r1);

    system.displayActiveUsers();
    system.displayAllRoutes();

}
