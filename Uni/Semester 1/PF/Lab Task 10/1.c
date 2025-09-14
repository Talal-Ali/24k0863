#include <stdio.h>
void search(int arr[], int i, int size)
{
	if(i == size)
	{
		return;
	}
	else
	{
		 printf("%d", arr[i]);
		 search(arr, ++i, size);
	}
}
int main()
{
	int arr[] = {9,2,3,4,5,6};
	int i = 0;
	search(arr, i, 5);
}