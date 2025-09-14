#include <iostream>
using namespace std;

class HomeAssistant;
class EnergyMonitor;

class SmartDevice {
private:
    string deviceName;
    double powerUsage;
    bool status;
    
public:
    SmartDevice(string name, double power) : deviceName(name), powerUsage(power), status(false) {}
    
    friend class HomeAssistant;
    friend class EnergyMonitor;
    
    bool getStatus() {
        return status;
    }
    
    double getPowerUsage() {
        return powerUsage;
    }
    
    string getDeviceName() {
        return deviceName;
    }
};

class HomeAssistant {
public:
    void turnOn(SmartDevice &device) {
        device.status = true;
        cout << device.getDeviceName() << " is turned ON." << endl;
    }
    
    void turnOff(SmartDevice &device) {
        device.status = false;
        cout << device.getDeviceName() << " is turned OFF." << endl;
    }
};

class EnergyMonitor {
public:
    double calculateTotalEnergy(SmartDevice devices[], int size) {
        double totalEnergy = 0;
        for (int i = 0; i < size; ++i) {
            if (devices[i].getStatus()) {
                totalEnergy += devices[i].getPowerUsage();
            }
        }
        return totalEnergy;
    }
};

int main() {
    SmartDevice devices[] = {
        SmartDevice("Light", 100),
        SmartDevice("Fan", 150),
        SmartDevice("Air Conditioner", 2000)
    };
    
    int numDevices = sizeof(devices) / sizeof(devices[0]);
    
    HomeAssistant assistant;
    assistant.turnOn(devices[0]);  
    assistant.turnOn(devices[1]);  
    assistant.turnOff(devices[2]);

    EnergyMonitor monitor;
    double totalEnergy = monitor.calculateTotalEnergy(devices, numDevices);
    
    cout << "Total energy consumption of active devices: " << totalEnergy << " watts." << endl;

    return 0;
}
