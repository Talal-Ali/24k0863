#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int size, int target, int &comparisons) {
    int low = 0, high = size - 1;
    comparisons = 0;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        comparisons++;
        if (arr[high] == arr[low]) break;

        int pos = low + ((target - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        if (pos < low || pos > high) break;

        if (arr[pos] == target)
            return pos;
        else if (arr[pos] < target)
            low = pos + 1;
        else
            high = pos - 1;
    }

    return -1;
}

int binarySearch(int arr[], int size, int target, int &comparisons) {
    int left = 0, right = size - 1;
    comparisons = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        comparisons++;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main() {
    int prices[] = {10, 20, 30, 40, 50, 60, 70, 80};
    int size1 = sizeof(prices) / sizeof(prices[0]);

    int priceToFind;
    cout << "Enter product price to search: ";
    cin >> priceToFind;

    int interpComparisons = 0;
    int pos = interpolationSearch(prices, size1, priceToFind, interpComparisons);

    if (pos != -1)
        cout << "Price found at position " << pos << endl;
    else
        cout << "Price not available" << endl;

    cout << "\n--- Comparison: Searching for 45 ---" << endl;
    int data[] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
    int size2 = sizeof(data) / sizeof(data[0]);
    int target = 45;

    int binaryComparisons = 0, interpolationComparisons = 0;

    int binIndex = binarySearch(data, size2, target, binaryComparisons);
    int interpIndex = interpolationSearch(data, size2, target, interpolationComparisons);

    cout << "Binary Search comparisons: " << binaryComparisons << endl;
    cout << "Interpolation Search comparisons: " << interpolationComparisons << endl;

    if (binaryComparisons < interpolationComparisons)
        cout << "Binary Search is more efficient in this case." << endl;
    else if (interpolationComparisons < binaryComparisons)
        cout << "Interpolation Search is more efficient in this case." << endl;
    else
        cout << "Both searches performed equally well." << endl;

    return 0;
}
