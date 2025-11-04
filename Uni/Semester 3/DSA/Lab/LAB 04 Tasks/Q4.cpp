#include<iostream>
#include<string>
#include <cstdlib>
#include <ctime>
#include <utility> // for std::swap

using namespace std;

// Corrected Shell Sort implementation
void shellsort(int arr[], int n, int &swapcount) {
    swapcount = 0; // Reset swap count for each call
    int gap_seq[] = {10, 5, 2, 1}; // A more effective gap sequence
    
    cout << "Gap sequence: ";
    for (int gap : gap_seq) {
        cout << gap << " ";
    }
    cout << endl;

    for (int gap : gap_seq) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                swapcount++; // This is technically a shift
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

// Corrected Insertion Sort
void insertionsort(int arr[], int n, int &shiftcount) {
    shiftcount = 0; // Reset shift count for each call
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            shiftcount++;
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

int main() {
    srand(static_cast<unsigned int>(time(0)));
    int arr[20];
    int swapCount = 0;

    for (int i = 0; i < 20; i++) {
        arr[i] = rand() % 100 + 1;
    }

    cout << "Original array:\n";
    printArray(arr, 20);
    cout << endl;

    int arr_copy_shell[20];
    for(int i = 0; i < 20; i++) {
        arr_copy_shell[i] = arr[i];
    }
    shellsort(arr_copy_shell, 20, swapCount);
    cout << "Array after shell sort:" << endl;
    printArray(arr_copy_shell, 20);
    cout << "Shifts/Swaps in Shell Sort: " << swapCount << endl;
    
    cout << "------------------------------------------\n";

    int arr_copy_insertion[20];
    for(int i = 0; i < 20; i++) {
        arr_copy_insertion[i] = arr[i];
    }
    int shiftCount = 0;
    insertionsort(arr_copy_insertion, 20, shiftCount);
    cout << "Array after insertion sort:" << endl;
    printArray(arr_copy_insertion, 20);
    cout << "Shifts in Insertion Sort: " << shiftCount << endl;

    cout << "------------------------------------------\n";

    if (swapCount < shiftCount)
        cout << "Shell Sort is faster (fewer shifts) on this dataset.\n";
    else if (swapCount > shiftCount)
        cout << "Insertion Sort is faster (fewer shifts) on this dataset.\n";
    else
        cout << "Both sorts performed similarly in terms of shifts.\n";

    return 0;
}