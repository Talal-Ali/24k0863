#include<stdio.h>

void com(int *array1, int *array2, int len1, int len2) {
    int *ptr1, *ptr2;
    int found = 0;
    
    for (ptr1 = array1; ptr1 < array1 + len1; ptr1++) {
        for (ptr2 = array2; ptr2 < array2 + len2; ptr2++) {
            if (*ptr1 == *ptr2) {
                printf("%d ", *ptr1);
                found = 1;
                break;
            }
        }
    }
    
}

int main() {
    int array1[] = {1, 2, 3, 4, 5};
    int array2[] = {4, 1, 8, 9, 0};
    
    int len1 = sizeof(array1) / sizeof(array1[0]);
    int len2 = sizeof(array2) / sizeof(array2[0]);
    
    printf("Common elements:");
    com(array1, array2, len1, len2);
    
}
