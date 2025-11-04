#include<iostream>

using namespace std;

void bubblesort(int arr[], int size){
    for(int i = 0; i < size - 1; i++){
        bool swapped = false;

        for(int j = 0; j < size - i - 1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }
        if(!swapped){
            break;
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[10];

    cout << "Enter 10 integers:\n";
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }

    cout << "Array before sorting:\n";
    printArray(arr, 10);

    bubblesort(arr, 10);

    cout << "Array after sorting:\n";
    printArray(arr, 10);
    
    return 0;
}