#include<iostream>

using namespace std;

void insertionsort(int arr[], int n){
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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
    
    int marks[] = {59, 44, 63, 78, 70, 68};

    cout << "Array before sorting:\n";
    printArray(marks, 6);
    cout << "After sorting:\n";

    insertionsort(marks, 6);
    printArray(marks, 6);

    return 0;
}