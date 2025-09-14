#include <iostream>
using namespace std;

template <typename T>
T maxElement(T* array, int size){
    T max=array[0];
    for(int i=1; i<size; i++){
        if(array[i]>max){
            max=array[i];
        }
    }
    return max;
}

int main(){
    int intArray[]={4,2,5,1,3};
    double doubleArray[]={3.14, 1.5, 2.7, 4.2};

    int maxInt=maxElement(intArray, 5);
    double maxDouble=maxElement(doubleArray, 4);

    cout<<"Max element in intArray: "<<maxInt<<endl;
    cout<<"Max element in doubleArray: "<<maxDouble<<endl;

    return 0;
}