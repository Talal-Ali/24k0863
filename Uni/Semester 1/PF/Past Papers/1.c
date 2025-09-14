#include<stdio.h>
#include<string.h>

int* recursion(int arr[], int len)
{
	static int i=0;
	int sum[2];
	if(i==len)
	{
		return *sum;
	}
	if(i%2==0)
	{
		sum[0]+= arr[i];
	}
	else
	{
		sum[1] += arr[i];
	}
	i++;
	recursion(arr, len);
}
int main()
{
	int arr[] = {1,2,3,4,5,6};
	int len = sizeof(arr)/sizeof(arr[0]);
	int sum[2] = recursion(arr, len);
	printf("sum at odd index %d", sum[1]);
	printf("sum at even index %d", sum[0]);
}