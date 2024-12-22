#include<stdio.h>
#include<stdlib.h>

void fibi(int* arr, int size)
{
	int i;
	for(i=0; i<size; i++)
	{
		if(i==0)
		{
			arr[i] = 0;
		}
		if(i==1)
		{
			arr[i] = 1;
		}
		if(i!=0 && i !=1)
		{
			arr[i] = arr[i-1]+ arr[i-2];
		}
		printf("%d ", arr[i]);
	}
}
int main()
{
	int size;
	printf("Enter size of array\n");
	scanf("%d", &size);
	int* arr = (int *) malloc(size * sizeof(int));
	fibi(arr, size);
	free(arr);
}