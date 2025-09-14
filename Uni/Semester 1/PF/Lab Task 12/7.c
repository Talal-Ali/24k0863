#include <stdio.h>
#include <stdlib.h>

int main() {
    int r1, c1, r2, c2;
    
    do {
        printf("Enter dimensions for matrix 1: ");
        scanf("%d %d", &r1, &c1);
        printf("Enter dimensions for matrix 2: ");
        scanf("%d %d", &r2, &c2);
        printf("\n");
    } while (c1 != r2);

    int **arr1 = (int **) malloc(r1 * sizeof(int *));
    for (int i = 0; i < r1; i++) {
        arr1[i] = (int *) malloc(c1 * sizeof(int));
    }
    
    int **arr2 = (int **) malloc(r2 * sizeof(int *));
    for (int i = 0; i < r2; i++) {
        arr2[i] = (int *) malloc(c2 * sizeof(int));
    }

    printf("Enter elements for matrix 1 (%d x %d):\n", r1, c1);
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            scanf("%d", &arr1[i][j]);
        }
    }

    printf("Enter elements for matrix 2 (%d x %d):\n", r2, c2);
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            scanf("%d", &arr2[i][j]);
        }
    }

    int **result = (int **) malloc(r1 * sizeof(int *));
    for (int i = 0; i < r1; i++) {
        result[i] = (int *) malloc(c2 * sizeof(int));
    }

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    printf("\nResultant Matrix (Matrix 1 * Matrix 2):\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < r1; i++) {
        free(arr1[i]);
    }
    free(arr1);

    for (int i = 0; i < r2; i++) {
        free(arr2[i]);
    }
    free(arr2);

    for (int i = 0; i < r1; i++) {
        free(result[i]);
    }
    free(result);

}
