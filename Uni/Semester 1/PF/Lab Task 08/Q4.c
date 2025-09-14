#include <stdio.h>

int main() {
    int a[3][3], b[3][3], result[3][3], i, j, k;
    
    printf("Enter the numbers of the first matrix:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    printf("Enter the numbers of the second matrix:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            result[i][j] = 0;
            for(k = 0; k < 3; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("Resultant matrix after multiplication:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

}

