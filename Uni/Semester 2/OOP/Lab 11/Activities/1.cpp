#include <iostream>
using namespace std;

template <typename T, typename U>
void printValue(T value1, U value2){
    cout<<"Addition of integer and double: "<<value1+value2<<endl;
}

template <typename T>
void printValue(T value1){
    cout<<"Value: "<<value1<<endl;
}

int main(){
    int intValue=42;
    double doubleValue=3.14;
    char charValue='A';

    printValue(intValue, doubleValue);
    printValue(doubleValue);
    printValue(charValue);

    return 0;
}