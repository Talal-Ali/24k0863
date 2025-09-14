#include<stdio.h>
#include<stdlib.h>

#define MAX_ROWS 200
#define INT_MAX 100000000
//int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
//    int sum =0;
//    int min = triangle[0][0];
//    if(*(triangleColSize)==1)
//    {
//        
//        for(int i=0; i<triangleSize; i++)
//        {
//            sum+= triangle[i][0];
//        }
//        min = sum;
//    }
//    else
//    {
//       
//        int i=0,j=0;
//        for(i=0; i<triangleSize-1; i++)
//        {
//            j=i;
//            int count = 0;
//            sum =0;
//            while(count <= 1)
//            {
//            	int thisval = triangle[i+1][j+count];
//                printf("Root x = %d, y= %d, value: %d\n", i+1, j+1, thisval);
//                sum+=triangle[i+1][j+count];
//                if(min>sum)
//                {
//                    min = sum;
//                }
//                count++;
//            }
//        }
//    }
//    return min;
//}
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    int sum = triangle[0][0];
    int min = triangle[0][0];
    
    if (*(triangleColSize) == 1) {
        for (int i = 0; i < triangleSize; i++) {
            sum += triangle[i][0];
        }
        min = sum;
    } else {
        for (int i = 0; i < triangleSize - 1; i++) { // Correct loop range for rows
            int j = i;
            int count = 0;
            int rowMin = INT_MAX; // Track minimum sum for the current row
            while (count <= 1) {
                int thisval = triangle[i + 1][j + count]; // Correct indexing for next row
                printf("Root x = %d, y= %d, value: %d\n", i + 2, j + count + 1, thisval); // Correct debugging information
                int tempSum = sum + thisval; // Add current value to cumulative sum
                if (rowMin > tempSum) {
                    rowMin = tempSum; // Update row minimum
                }
                count++;
            }
            sum = rowMin; // Update cumulative sum to the row minimum
            if (min > sum) {
                min = sum; // Update global minimum
            }
        }
    }
    return min;
}


void main() {
    // Test case 1
    int rows1 = 4;
    int cols1[] = {1, 2, 3, 4};
    int** triangle1 = (int**)malloc(rows1 * sizeof(int*));
    triangle1[0] = (int[]){2};
    triangle1[1] = (int[]){3, 4};
    triangle1[2] = (int[]){6, 5, 7};
    triangle1[3] = (int[]){4, 1, 8, 3};
    int result1 = minimumTotal(triangle1, rows1, cols1);
    printf("Output for triangle1: %d\n", result1); // Expected output: 11

    // Test case 2
    int rows2 = 1;
    int cols2[] = {1};
    int** triangle2 = (int**)malloc(rows2 * sizeof(int*));
    triangle2[0] = (int[]){-10};
    int result2 = minimumTotal(triangle2, rows2, cols2);
    printf("Output for triangle2: %d\n", result2); // Expected output: -10

    // Free allocated memory
    free(triangle1);
    free(triangle2);
}


