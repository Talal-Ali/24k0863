#include <iostream>
#include <string>
using namespace std;

class OutOfBoundsException {
public:
    string message;
    OutOfBoundsException(string msg) {
        message=msg;
    }
};

template <typename T>
class SmartArray {
private:
    T* data;
    int size;

public:
    SmartArray(int s) {
        size=s;
        data=new T[size];
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw OutOfBoundsException("Invalid index access attempted!");
        }
        return data[index];
    }

    ~SmartArray() {
        delete[] data;
    }
};

int main() {
    int n;
    cout<<"Array size: ";
    cin>>n;

    SmartArray<int> intArray(n);
    cout<<"Enter elements: ";
    for (int i=0; i < n; i++) {
        cin>>intArray[i];
    }

    try {
        cout<<"Accessing index 2: "<<intArray[2]<<endl;

        cout<<"Accessing index 5: "<<intArray[5]<<endl;
    } 
    catch (OutOfBoundsException e) {
        cout<<"OutOfBoundsException caught: "<<e.message<<endl;
    }

    SmartArray<string> strArray(3);
    cout<<"\nEnter 3 strings: ";
    for (int i=0; i < 3; i++) {
        cin>>strArray[i];
    }

    try {
        cout<<"Accessing string index 1: "<<strArray[1]<<endl;

        cout<<"Accessing string index 3: "<<strArray[3]<<endl;
    } 
    catch (OutOfBoundsException e) {
        cout<<"OutOfBoundsException caught: "<<e.message<<endl;
    }

    return 0;
}
