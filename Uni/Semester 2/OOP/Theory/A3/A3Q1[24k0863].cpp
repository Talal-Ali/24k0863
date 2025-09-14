#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class User {
protected:
    string name;
    string cnic;
    string email;
    bool paid;

public:
    User(string n, string c, string e) {
        name = n;
        cnic = c;
        email = e;
        paid = false;
    }

    virtual ~User() {}

    virtual float calculateFare(bool isAC) = 0;

    virtual string getRole() = 0;

    string getName() {
        return name;
    }

    string getCnic() {
        return cnic;
    }

    bool hasPaid() {
        return paid;
    }

    void makePayment() {
        paid = true;
    }

    void saveToFile(string filename) {
        ofstream file(filename, ios::app);

        if (!file) {
            throw runtime_error("Could not open file!");
        }

        file << name << endl;
        file << cnic << endl;
        file << email << endl;

        file.close();
    }
};


class Student : public User {
public:
    Student(string n, string c, string e) : User(n, c, e) {}

    float calculateFare(bool isAC) override {
        if (isAC) {
            return 700;
        } else {
            return 500;
        }
    }

    string getRole() override {
        return "Student";
    }
};


class Faculty : public User {
public:
    Faculty(string n, string c, string e) : User(n, c, e) {}

    float calculateFare(bool isAC) override {
        if (isAC) {
            return 10000;
        } else {
            return 8000;
        }
    }

    string getRole() override {
        return "Faculty";
    }
};


class Driver {
    string name;
    string license;

public:
    Driver(string n, string l) {
        name = n;
        license = l;
    }

    string getName() {
        return name;
    }
};


class Route {
    string start;
    string end;
    float distance;

public:
    Route(string s, string e, float d) {
        start = s;
        end = e;
        distance = d;
    }

    bool isLong() {
        return distance > 20;
    }
};


class Vehicle {
    Driver driver;
    Route* route;
    int capacity;
    bool isAC;
    string type;
    vector<User*> passengers;

public:
    Vehicle(Driver d, Route* r, int c, bool ac, string t)
        : driver(d), route(r), capacity(c), isAC(ac), type(t) {}

    bool bookSeat(User* user) {
        if (!user->hasPaid()) {
            throw runtime_error("Payment not completed.");
        }

        if (passengers.size() >= capacity) {
            throw runtime_error("No seats available.");
        }

        for (User* u : passengers) {
            if (u == user) {
                throw runtime_error("User already booked.");
            }
        }

        passengers.push_back(user);
        return true;
    }

    float getFare(User* user) {
        return user->calculateFare(isAC);
    }
};


class Transporter {
    string name;
    vector<Vehicle*> vehicles;

public:
    Transporter(string n) {
        name = n;
    }

    void addVehicle(Vehicle* v) {
        vehicles.push_back(v);
    }
};

class Booking {
    int id;
    Vehicle* vehicle;
    User* user;
    Route* route;

public:
    Booking(int i, Vehicle* v, User* u, Route* r) {
        id = i;
        vehicle = v;
        user = u;
        route = r;
    }

    void saveToFile(string filename) {
        ofstream file(filename, ios::app);

        if (!file) {
            throw runtime_error("Booking file error.");
        }

        file << "Booking ID: " << id << endl;

        file.close();
    }
};

class TransportManagement {
    vector<User*> users;
    vector<Driver*> drivers;
    vector<Route*> routes;
    vector<Vehicle*> vehicles;

public:
    ~TransportManagement() {
        for (auto u : users) delete u;
        for (auto d : drivers) delete d;
        for (auto r : routes) delete r;
        for (auto v : vehicles) delete v;
    }

    void registerStudent(string name, string cnic, string email) {
        users.push_back(new Student(name, cnic, email));
    }

    void registerFaculty(string name, string cnic, string email) {
        users.push_back(new Faculty(name, cnic, email));
    }

    void addDriver(string name, string license) {
        drivers.push_back(new Driver(name, license));
    }

    void addRoute(string start, string end, float distance) {
        routes.push_back(new Route(start, end, distance));
    }

    void addVehicle(int driverIndex, int routeIndex, int capacity, bool isAC, string type) {
        if (driverIndex >= drivers.size() || routeIndex >= routes.size()) {
            throw runtime_error("Invalid index.");
        }

        vehicles.push_back(new Vehicle(*drivers[driverIndex], routes[routeIndex], capacity, isAC, type));
    }

    void makePayment(string cnic) {
        for (auto u : users) {
            if (u->getCnic() == cnic) {
                u->makePayment();
                cout << "Payment completed for " << u->getName() << endl;
                return;
            }
        }

        throw runtime_error("User not found.");
    }

    void bookSeat(string name, int vehicleIndex) {
        if (vehicleIndex >= vehicles.size()) {
            throw runtime_error("Vehicle not found.");
        }

        for (User* u : users) {
            if (u->getName() == name) {
                vehicles[vehicleIndex]->bookSeat(u);
                return;
            }
        }

        throw runtime_error("User not found.");
    }

    vector<User*>& getUsers() {
        return users;
    }
};


int main() {
    TransportManagement system;

    system.registerStudent("Ahmed", "120987652", "ahmed@gmail.com");
    system.registerFaculty("Zain", "302945670", "zain@gmail.com");
    system.addDriver("Farhan", "1234567");
    system.addRoute("Campus", "Johar", 15.0);
    system.addVehicle(0, 0, 52, true, "Bus");

    try {
        system.makePayment("120987652");
        system.bookSeat("Ahmed", 0);

        for (User* u : system.getUsers()) {
            if (u->getName() == "Ahmed") {
                u->saveToFile("users.txt");
                break;
            }
        }

        cout << "User info saved to file successfully." << endl;

    } catch (runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }

}
