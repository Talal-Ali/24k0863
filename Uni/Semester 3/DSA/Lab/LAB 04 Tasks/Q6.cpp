#include <iostream>

using namespace std;

int binarySearch(const int arr[], int size, int target, int &comparisons) {
    int left = 0;
    int right = size - 1;
    comparisons = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        comparisons++;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    int rollNumbers[] = {101, 105, 110, 120, 135, 150};
    int size = sizeof(rollNumbers) / sizeof(rollNumbers[0]);

    int target;
    cout << "Enter roll number to search: ";
    cin >> target;

    int comparisons = 0;
    int result = binarySearch(rollNumbers, size, target, comparisons);

    if (result != -1) {
        cout << "Roll number found at index " << result << "." << endl;
    } else {
        cout << "Roll number not found." << endl;
    }

    cout << "Number of comparisons: " << comparisons << endl;

    return 0;
}