#include<stdio.h>
#include<stdlib.h>

int main()
{
	int m=1,n, number, sum=0, x=0, y=0;
	int i, j;
	printf("Enter your number of columns: ");
	scanf("%d", &n);
	int** matrix = (int**) malloc(m*sizeof(int*));
	matrix[m - 1] = (int*) malloc(n * sizeof(int));
	while(1){
		scanf("%d", &number);
		if(number == -1)
		{
			break;
		}
		matrix[x][y] = number;
		y++;
		if(y==n)
		{
			m++;
			matrix = (int**)realloc(matrix, m*sizeof(int*));
			matrix[m-1] = (int* ) malloc(n*sizeof(int));
			y=0;
			x++;
		}
		
	}

	if(x<3 || n< 3)
	{
		printf("Insufficient Elements for summation.\n");
		for(i=0; i<m; i++)
		{
			free(matrix[i]);
		}
		free(matrix);
		return 0;
	}
	int ** result = (int**) malloc((m-2)*sizeof(int*));
	for(i=0; i<x-2; i++)
	{
		result[i] = (int*) malloc((n-2)* sizeof(int));
	}
	printf("Your matrix\n");
	for(i=0;i<x; i++)
	{
		for(j=0;j<n; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("Your result\n");
	int cx, cy;
	for (i = 0; i < x - 2; i++) {
	    for (j = 0; j < n - 2; j++) {
	        result[i][j] = 0;
	        for (cx = i; cx < i + 3; cx++) {
	            for (cy = j; cy < j + 3; cy++) {
	                result[i][j] += matrix[cx][cy];
	            }
	        }
	        printf("%d ", result[i][j]);
	    }
	    printf("\n");
	}

	
	
	for (i = 0; i < m; i++) {
	    free(matrix[i]);
	}
	free(matrix);
	
	for (i = 0; i < x - 2; i++) {
	    free(result[i]);
	}
	free(result);

}
