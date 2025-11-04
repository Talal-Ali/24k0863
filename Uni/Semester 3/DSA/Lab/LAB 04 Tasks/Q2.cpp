#include <iostream>
#include <string>

using namespace std;

void selectionSort(int arr[], int size, int &swapCount) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
            swapCount++; 
        }
    }
}

int main() {
    int numbers[] = {5, 2, 8, 1, 9, 4, 6, 7, 3, 0};
    int swapCount = 0;
    int size = sizeof(numbers) / sizeof(numbers[0]);

    selectionSort(numbers, size, swapCount);

    cout << "Numbers sorted:\n";
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << endl;
    }
    cout << "Number of swaps performed: " << swapCount << endl;
    return 0;
}