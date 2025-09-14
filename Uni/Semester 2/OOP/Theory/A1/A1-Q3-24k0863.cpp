#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Customer {
    string fullName;
    int customerAge;
    string licenseCategory;
    string contactDetails;
    int customerId;

public:
    Customer(string fullName, int customerAge, string licenseCategory, string contactDetails, int customerId)
        : fullName(fullName), customerAge(customerAge), licenseCategory(licenseCategory), contactDetails(contactDetails), customerId(customerId) {}

    void modifyDetails(string newName, int newAge, string newLicenseCategory, string newContactDetails) {
        fullName = newName;
        customerAge = newAge;
        licenseCategory = newLicenseCategory;
        contactDetails = newContactDetails;
    }

    int getId() {
        return customerId;
    }

    string getLicenseCategory() {
        return licenseCategory;
    }

    void showDetails() {
        cout << "Name: " << fullName << " | Age: " << customerAge << " | ID: " << customerId
             << " | License: " << licenseCategory << " | Contact: " << contactDetails << endl;
    }
};

class Car {
    string vehicleModel;
    double pricePerDay;
    string licenseRequirement;
    string category;

public:
    Car(string vehicleModel, double pricePerDay, string licenseRequirement, string category)
        : vehicleModel(vehicleModel), pricePerDay(pricePerDay), licenseRequirement(licenseRequirement), category(category) {}

    bool checkEligibility(string licenseType) {
        return licenseType == "Full" || licenseType == licenseRequirement || (licenseType == "Intermediate" && licenseRequirement != "Full");
    }

    string getModel() {
        return vehicleModel;
    }

    string getCategory() {
        return category;
    }

    void showVehicleDetails() {
        cout << "Model: " << vehicleModel << " | Price per Day: $" << pricePerDay
             << " | Required License: " << licenseRequirement << " | Category: " << category << endl;
    }
};

class RentalService {
    vector<Customer> customers;
    vector<Car*> carFleet;

public:
    ~RentalService() {
        for (Car* car : carFleet) {
            delete car;
        }
    }

    void registerCustomer(string name, int age, string license, string contact, int id) {
        customers.emplace_back(name, age, license, contact, id);
        cout << "Customer registered successfully with ID: " << id << endl;
    }

    void updateCustomerDetails(int id, string name, int age, string license, string contact) {
        for (Customer& cust : customers) {
            if (cust.getId() == id) {
                cust.modifyDetails(name, age, license, contact);
                cout << "Customer details updated for ID: " << id << endl;
                return;
            }
        }
        cout << "Customer not found with ID: " << id << endl;
    }

    void addCar(string model, double price, string licenseReq, string category) {
        carFleet.push_back(new Car(model, price, licenseReq, category));
        cout << "Car added: " << model << endl;
    }

    void listAvailableCars() {
        cout << "\nAvailable Cars:\n";
        for (Car* car : carFleet) {
            car->showVehicleDetails();
        }
    }

    void rentCar(int customerId, string model) {
        Customer* customer = nullptr;
        for (Customer& cust : customers) {
            if (cust.getId() == customerId) {
                customer = &cust;
                break;
            }
        }

        if (!customer) {
            cout << "Customer not found with ID: " << customerId << endl;
            return;
        }

        for (Car* car : carFleet) {
            if (car->getModel() == model) {
                if (car->checkEligibility(customer->getLicenseCategory())) {
                    cout << "Car rented successfully by Customer ID: " << customerId << " (" << model << ")\n";
                    return;
                } else {
                    cout << "Customer not eligible to rent this car.\n";
                    return;
                }
            }
        }

        cout << "Car model not found.\n";
    }

    void mainMenu() {
        int choice;
        do {
            cout << "\n--- Vehicle Rental System ---\n";
            cout << "1. Register Customer\n";
            cout << "2. Update Customer Details\n";
            cout << "3. Add Car\n";
            cout << "4. View Available Cars\n";
            cout << "5. Rent a Car\n";
            cout << "6. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    string name, license, contact;
                    int age, id;
                    cout << "Enter Name: ";
                    cin.ignore();
                    getline(cin, name);
                    cout << "Enter Age: ";
                    cin >> age;
                    cout << "Enter License Type: ";
                    cin >> license;
                    cout << "Enter Contact Info: ";
                    cin >> contact;
                    cout << "Enter ID: ";
                    cin >> id;
                    registerCustomer(name, age, license, contact, id);
                    break;
                }
                case 2: {
                    int id, age;
                    string name, license, contact;
                    cout << "Enter Customer ID to update: ";
                    cin >> id;
                    cout << "Enter Updated Name: ";
                    cin.ignore();
                    getline(cin, name);
                    cout << "Enter Updated Age: ";
                    cin >> age;
                    cout << "Enter Updated License Type: ";
                    cin >> license;
                    cout << "Enter Updated Contact Info: ";
                    cin >> contact;
                    updateCustomerDetails(id, name, age, license, contact);
                    break;
                }
                case 3: {
                    string model, license, category;
                    double price;
                    cout << "Enter Car Model: ";
                    cin.ignore();
                    getline(cin, model);
                    cout << "Enter Rental Price per Day: ";
                    cin >> price;
                    cout << "Enter Required License Type: ";
                    cin >> license;
                    cout << "Enter Car Category (Learner/General): ";
                    cin >> category;
                    addCar(model, price, license, category);
                    break;
                }
                case 4:
                    listAvailableCars();
                    break;
                case 5: {
                    int id;
                    string model;
                    cout << "Enter Customer ID: ";
                    cin >> id;
                    cout << "Enter Car Model: ";
                    cin.ignore();
                    getline(cin, model);
                    rentCar(id, model);
                    break;
                }
                case 6:
                    cout << "Exiting system. Goodbye!\n";
                    break;
                default:
                    cout << "Invalid choice. Try again.\n";
            }
        } while (choice != 6);
    }
};

int main() {
    RentalService service;
    service.mainMenu();
    
}
