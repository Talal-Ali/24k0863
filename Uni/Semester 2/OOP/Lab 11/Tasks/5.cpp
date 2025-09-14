#include <iostream>
#include <string>
using namespace std;

template <typename T>
T findMax(const T arr[], int size) {
    if (size <= 0) {
        throw invalid_argument("Array size must be positive");
    }
    
    T maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

template <typename T>
void printArray(const T arr[], int size) {
    cout<<"Array: [";
    for (int i = 0; i < size; i++) {
        cout<<arr[i];
        if (i < size - 1) cout<<", ";
    }
    cout<<"]"<<endl;
}

int main() {
    int intArr[] = {10, 20, 5, 30, 25};
    int intSize = sizeof(intArr) / sizeof(intArr[0]);
    printArray(intArr, intSize);
    cout<<"Maximum: "<<findMax(intArr, intSize)<<endl<<endl;

    string strArr[] = {"Apple", "Mango", "Banana", "Peach"};
    int strSize = sizeof(strArr) / sizeof(strArr[0]);
    printArray(strArr, strSize);
    cout<<"Maximum: "<<findMax(strArr, strSize)<<endl;

    return 0;
}