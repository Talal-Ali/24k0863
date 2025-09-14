#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

class Data {
    char name[100]; // Use fixed-size array instead of string
    int id;
public:
    Data(const char* n, int i) {
        strncpy(name, n, sizeof(name));
        name[sizeof(name) - 1] = '\0';
        id = i;
    }
    Data() {}
    const char* getName() { return name; }
    int getId() { return id; }
};

class Note {
    string filename;
public:
    Note(string f): filename(f) {}

    void wrt(Data &data) {
        fstream file;
        file.open(filename, ios::out | ios::app | ios::binary);
        file.write((char*)&data, sizeof(Data)); // write full object safely
        file.close();
    }

    void read() {
        fstream file;
        Data d("",000);
        file.open(filename, ios::in | ios::binary);
        //file.seekg(0, ios::beg);
        while (file.read((char*)&d, sizeof(Data))) {
            cout << d.getName() << " " << d.getId() << endl;
        }
        file.close();
    }
};

int main() {
    Data d1("Hello", 123);
    Note n("Bin.bin");
    n.wrt(d1);
    n.read();
}
