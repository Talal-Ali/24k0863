#include<stdio.h>
#include<stdlib.h>

int main()
{
	printf("Enter your rows and then columns\n");
	int row, col, i, j, num;
	scanf("%d", &row);
	scanf("%d", &col);
	int** arr = (int**) malloc(row* sizeof(int*));
	for(i=0; i<row; i++)
	{
		arr[i] = (int *)malloc(col * sizeof(int));
	}
	int** temp = (int**) malloc(col* sizeof(int*));
	for(i=0; i<col; i++)
	{
		temp[i] = (int *)malloc(row * sizeof(int));
	}
	printf("Enter your numbers\n");
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
		{
			scanf("%d", &num);
			arr[i][j] = num;
		}
	}
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
		{
			temp[j][i] = arr[i][j];
		}
	}
	
	printf("Your original array\n");
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("Your transposed array\n");
	for(i=0; i<col; i++)
	{
		for(j=0; j<row; j++)
		{
			printf("%d ", temp[i][j]);
		}
		printf("\n");
	}
	
	for(i=0; i<row; i++)
	{
		free(arr[i]);
	}
	free(arr);
	
	for(i=0; i<col; i++)
	{
		free(temp[i]);
	}
	free(temp);
}