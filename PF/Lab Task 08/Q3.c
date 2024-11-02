#include <stdio.h>
int main()
{
	int matrix[3][3], i, j, minRow, sp;
    
    printf("Enter the numbers of the matrix:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    
    for(i = 0; i < 3; i++) {
        minRow = matrix[i][0];
        int colIndex = 0;
        
        
        for(j = 1; j < 3; j++) {
            if(matrix[i][j] < minRow) {
                minRow = matrix[i][j];
                colIndex = j;
            }
        }

        
        sp = 1;
        for(j = 0; j < 3; j++) {
            if(matrix[j][colIndex] > minRow) {
                sp = 0;
                break;
            }
        }

        if(sp) {
            printf("Saddle point found at (%d, %d): %d\n", i, colIndex, minRow);
        }
    }

    if(!sp) {
        printf("No saddle point found.\n");
    }

    
}
