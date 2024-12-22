#include <stdio.h>
int minmax(int * arr)
{
    int *ptr = arr;
    int size = sizeof(arr) / sizeof(arr[0]);
    int min = *ptr, max = *ptr;
    
    
    for (ptr = arr; ptr < arr + size; ptr++) {
        if (*ptr < min) {
            min = *ptr;
        }
        if (*ptr > max) {
            max = *ptr;
        }
    }
    printf("Min %d\n", min);
    printf("Max %d", max);
}
int main() {
     int arr[] = {99,6,8,1};
     minmax(arr);

}
