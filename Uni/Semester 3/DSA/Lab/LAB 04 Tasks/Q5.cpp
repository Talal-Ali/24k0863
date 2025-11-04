#include <iostream>
#include <utility> // For std::swap

using namespace std;

void combSort(int arr[], int size, int &swapCount) {
    swapCount = 0;
    int gap = size;
    float shrink = 1.3;
    bool swapped = true;

    while (gap > 1 || swapped) {
        gap = static_cast<int>(gap / shrink);
        if (gap < 1) {
            gap = 1;
        }

        swapped = false;
        cout << "Current gap: " << gap << endl;

        for (int i = 0; i < size - gap; i++) {
            if (arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]);
                swapped = true;
                swapCount++;
            }
        }
    }
}

void bubbleSort(int arr[], int size, int &swapCount) {
    swapCount = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapCount++;
            }
        }
    }
}

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    const int SIZE = 9;
    int originalArr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    int combArr[SIZE];
    int bubbleArr[SIZE];
    
    // Create copies of the original array
    for (int i = 0; i < SIZE; ++i) {
        combArr[i] = originalArr[i];
        bubbleArr[i] = originalArr[i];
    }
    
    int combSwaps = 0, bubbleSwaps = 0;

    cout << "--- Comb Sort ---" << endl;
    combSort(combArr, SIZE, combSwaps);
    cout << "\nComb Sort result: ";
    printArray(combArr, SIZE);
    cout << "Swaps in Comb Sort: " << combSwaps << endl;

    cout << "\n--- Bubble Sort ---" << endl;
    bubbleSort(bubbleArr, SIZE, bubbleSwaps);
    cout << "\nBubble Sort result: ";
    printArray(bubbleArr, SIZE);
    cout << "Swaps in Bubble Sort: " << bubbleSwaps << endl;

    cout << "\n--- Comparison ---" << endl;
    if (combSwaps < bubbleSwaps)
        cout << "Comb Sort is faster (fewer swaps)." << endl;
    else if (combSwaps > bubbleSwaps)
        cout << "Bubble Sort is faster (fewer swaps)." << endl;
    else
        cout << "Both sorts performed similarly." << endl;

    return 0;
}