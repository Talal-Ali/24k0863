#include <stdio.h>
#include <stdlib.h>

int main() {
    int start, numElements;
    printf("Enter the start value: ");
    scanf("%d", &start);
    printf("Enter the number of elements: ");
    scanf("%d", &numElements);

    int* array = (int*)malloc(numElements * sizeof(int));
    

    for (int i = 0; i < numElements; i++) {
        array[i] = start + i;
    }

    printf("The array is:\n");
    for (int i = 0; i < numElements; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);

}
