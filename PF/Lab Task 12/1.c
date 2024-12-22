#include<stdio.h>
#include<stdlib.h>

int main()
{
	int size, i, sum=0;
	printf("ENter size\n");
	scanf("%d", &size);
	int *arr= (int* ) malloc(size * sizeof(int));
	printf("ENter your numbers\n");
	for(i=0; i<size; i++)
	{
		scanf("%d", &arr[i]);
		
	}
	for(i=0; i<size; i++)
	{
		sum+= arr[i];
	}
	printf("Sum is : %d", sum);
	free(arr);
}