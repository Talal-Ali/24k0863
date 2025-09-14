#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Person {
    char name[50];
    int age;
    char country[30];
};

class BinaryHandler {
private:
    const char* filename;

public:
    BinaryHandler(const char* fname) {
        filename = fname;
    }

    void writeAll(const Person people[], int count) {
        ofstream file(filename, ios::binary | ios::out | ios::trunc);
        if (!file) {
            cerr << "Error opening file for writing.\n";
            return;
        }

        for (int i = 0; i < count; ++i) {
            file.write((char*)&people[i], sizeof(Person));
        }
        file.close();
    }

    void append(const Person people[], int count) {
        ofstream file(filename, ios::binary | ios::app);
        if (!file) {
            cerr << "Error opening file for appending.\n";
            return;
        }

        for (int i = 0; i < count; ++i) {
            file.write((char*)&people[i], sizeof(Person));
        }
        file.close();
    }

    void readAll() {
        ifstream file(filename, ios::binary);
        if (!file) {
            cerr << "Error opening file for reading.\n";
            return;
        }

        Person person;
        int index = 0;
        cout << "\n[DATA IN FILE]:\n";
        while (file.read((char*)&person, sizeof(Person))) {
            cout << index++ << ": " << person.name << ", " << person.age << ", " << person.country << "\n";
        }
        file.close();
    }

    void editRecord(int index, const Person& newPerson) {
        fstream file(filename, ios::binary | ios::in | ios::out);
        if (!file) {
            cerr << "Error opening file for editing.\n";
            return;
        }

        file.seekp(index * sizeof(Person), ios::beg);
        file.write((char*)&newPerson, sizeof(Person));
        file.close();
    }

    void deleteRecord(int index) {
        ifstream inFile(filename, ios::binary);
        ofstream tempFile("temp.bin", ios::binary);

        if (!inFile || !tempFile) {
            cerr << "Error opening file for deletion.\n";
            return;
        }

        Person person;
        int currentIndex = 0;
        while (inFile.read((char*)&person, sizeof(Person))) {
            if (currentIndex != index) {
                tempFile.write((char*)&person, sizeof(Person));
            }
            currentIndex++;
        }

        inFile.close();
        tempFile.close();

        remove(filename);
        rename("temp.bin", filename);
    }
};

int main() {
    BinaryHandler handler("people.dat");

    // 1. Overwrite with multiple records
    Person people[3] = {
        {"Alice", 30, "USA"},
        {"Bob", 25, "Canada"},
        {"Charlie", 28, "UK"}
    };
    handler.writeAll(people, 3);
    handler.readAll();

    // 2. Append more records
    Person newPeople[2] = {
        {"David", 35, "Germany"},
        {"Eve", 27, "France"}
    };
    handler.append(newPeople, 2);
    handler.readAll();

    // 3. Edit a record
    Person updated = {"Bob", 26, "Mexico"};
    handler.editRecord(1, updated);
    handler.readAll();

    // 4. Delete a record
    handler.deleteRecord(0);  // Delete Alice
    handler.readAll();

    return 0;
}
