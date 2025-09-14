#include <stdio.h>

int linearSearch(int arr[], int size, int search, int i) {
    if (i >= size)
        return -1;
    if (arr[i] == search)
        return i;
    return linearSearch(arr, size, search, i + 1);
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12};
    int size = sizeof(arr) / sizeof(arr[0]);
    int search;
    printf("Enter your search term: ");
    scanf("%d", &search);
    int result = linearSearch(arr, size, search, 0);
    if (result != -1)
        printf("Found at index %d\n", result);
    else
        printf("Not found in the array\n");
}
