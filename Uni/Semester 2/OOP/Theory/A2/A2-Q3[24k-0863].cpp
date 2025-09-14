#include <iostream>
using namespace std;

class Vehicle {
protected:
    int id;
    static int deliveryn;
    int eff;

public:
    Vehicle(int i, int e) : id(i), eff(e) {
        deliveryn++;
    }

    virtual ~Vehicle() {
        deliveryn--;
    }

    virtual void calculateroute(string destination) = 0;
    virtual int deliveryTime(int distance, int speed) = 0;
    virtual void move() = 0;

    virtual void command(string cmd, int packageID) {
        cout << "Base vehicle command for " << cmd << " on package " << packageID << endl;
    }

    static int getnum() {
        return deliveryn;
    }

    friend bool operator==(Vehicle &v1, Vehicle &v2) {
        return (v1.eff == v2.eff);
    }

    friend bool resolveConflict(Vehicle& v1, Vehicle& v2);
};

int Vehicle::deliveryn = 0;

class RamzanDrone : public Vehicle {
public:
    RamzanDrone(int i, int e) : Vehicle(i, e) {}

    void calculateroute(string destination) override {
        cout << "Finding route to " << destination << endl;
    }

    int deliveryTime(int distance, int speed) override {
        return (distance / speed);
    }

    void command(string cmd, int packageID) override {
        Vehicle::command(cmd, packageID);
        cout << "Drone " << id << " executing command: " << cmd << " for package " << packageID << endl;
    }

    void command(string cmd, int packageID, string urgencyLevel) {
        if (urgencyLevel == "urgent") {
            cout << "Drone " << id << " urgently delivering the package " << packageID << endl;
        } else {
            cout << "Drone " << id << " delivering at normal speed " << packageID << endl;
        }
    }

    void move() override {
        cout << "Drone " << id << " flying to destination." << endl;
    }
};

class RamzanTimeShip : public Vehicle {
public:
    RamzanTimeShip(int i, int e) : Vehicle(i, e) {}

    void calculateroute(string destination) override {
        cout << "Finding time to " << destination << endl;
    }

    int deliveryTime(int distance, int speed) override {
        return (distance / speed);
    }

    void command(string cmd, int packageID) override {
        Vehicle::command(cmd, packageID);
        cout << "TimeShip " << id << " executing command: " << cmd << " for package " << packageID << endl;
    }

    void command(string cmd, int packageID, string urgencyLevel) {
        if (urgencyLevel == "urgent") {
            cout << "TimeShip " << id << " urgently delivering through history " << packageID << endl;
        } else {
            cout << "TimeShip " << id << " normally delivering through history " << packageID << endl;
        }
    }

    void move() override {
        cout << "TimeShip " << id << " traveling through time." << endl;
    }
};

class RamzanHyperPod : public Vehicle {
public:
    RamzanHyperPod(int i, int e) : Vehicle(i, e) {}

    void calculateroute(string destination) override {
        cout << "Finding underground route to " << destination << endl;
    }

    int deliveryTime(int distance, int speed) override {
        return (distance / speed);
    }

    void command(string cmd, int packageID) override {
        Vehicle::command(cmd, packageID);
        cout << "HyperPod " << id << " executing command: " << cmd << " for package " << packageID << endl;
    }

    void move() override {
        cout << "HyperPod " << id << " speeding through underground network." << endl;
    }
};

bool resolveConflict(Vehicle& v1, Vehicle& v2) {
    cout << "Resolving conflict between " << v1.id << " and " << v2.id << endl;
    return v1.eff < v2.eff;
}

int main() {
    RamzanDrone drone(101, 20);
    RamzanTimeShip timeship(102, 30);
    RamzanHyperPod hyperpod(103, 40);

    drone.calculateroute("Shahre Faisal");
    timeship.calculateroute("1950");
    hyperpod.calculateroute("Underground Tunnel");

    cout << "Drone Delivery Time: " << drone.deliveryTime(4, 20) << " hours" << endl;
    cout << "TimeShip Delivery Time: " << timeship.deliveryTime(3, 25) << " hours" << endl;
    cout << "HyperPod Delivery Time: " << hyperpod.deliveryTime(2, 30) << " hours" << endl;

    drone.command("Deliver", 101);
    timeship.command("Deliver", 102);
    hyperpod.command("Deliver", 103);

    drone.command("Deliver", 101, "urgent");
    timeship.command("Deliver", 102, "urgent");
    hyperpod.command("Deliver", 103);

    resolveConflict(drone, timeship);

    cout << "Total Active Deliveries: " << Vehicle::getnum() << endl;

}
