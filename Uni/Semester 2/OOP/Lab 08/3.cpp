#include <iostream>
#include <string>
using namespace std;

class Doctor;

class Patient {
private:
    string name;
    int age;
    string medicalHistory;

public:
    Patient(string patientName, int patientAge, string patientHistory)
        : name(patientName), age(patientAge), medicalHistory(patientHistory) {}

    string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    string getMedicalHistory() const {
        return medicalHistory;
    }

    friend class Doctor;  
};

class Doctor {
private:
    string name;
    string specialty;

public:
    Doctor(string doctorName, string doctorSpecialty) : name(doctorName), specialty(doctorSpecialty) {}
    void updateMedicalHistory(Patient &patient, string newMedicalHistory) {
        patient.medicalHistory = newMedicalHistory;
        cout << "Medical history updated for " << patient.getName() << endl;
    }
    void displayPatientDetails(const Patient &patient) {
        cout << "Patient's Name: " << patient.getName() << endl;
        cout << "Patient's Age: " << patient.getAge() << endl;
        cout << "Patient's Medical History: " << patient.getMedicalHistory() << endl;
    }
};

int main() {
    Patient patient("Ahmed", 60, "No known medical conditions");
    Doctor doctor("Laiba", "Cardiology");
    cout << "Initial patient details:" << endl;
    doctor.displayPatientDetails(patient);
    doctor.updateMedicalHistory(patient, "Diagnosed with Cancer");
    cout << "\nUpdated patient details:" << endl;
    doctor.displayPatientDetails(patient);

    return 0;
}
