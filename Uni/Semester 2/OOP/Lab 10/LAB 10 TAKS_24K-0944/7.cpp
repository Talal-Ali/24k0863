#include <iostream>
#include <fstream>

using namespace std;

struct Student {
    char name[50];
    int id;
    float gpa;
};

int main() {
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    ofstream outFile("students.dat", ios::binary);
    if (!outFile) {
        cerr << "Error opening students.dat for writing." << endl;
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        Student s;

        cout << "Enter name for student " << i + 1 << ": ";
        cin.getline(s.name, 50);

        cout << "Enter ID: ";
        cin >> s.id;

        cout << "Enter GPA: ";
        cin >> s.gpa;
        cin.ignore(); 

        outFile.write((char*)&s, sizeof(Student));
    }
    outFile.close();
    ifstream inFile("students.dat", ios::binary);
    if (!inFile) {
        cerr << "Error opening students.dat for reading." << endl;
        return 1;
    }
    cout << "\nStudent Records:\n";
    Student s;
    while (inFile.read((char*)&s, sizeof(Student))) {
        cout << "Name: " << s.name << "\n";
        cout << "ID: " << s.id << "\n";
        cout << "GPA: " << s.gpa << "\n";
        cout << "----------------------\n";
    }
    inFile.close();
}
