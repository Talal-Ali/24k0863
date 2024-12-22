#include<stdio.h>
#include<string.h>

void inputdata(int arr[5][5], char ** dep)
{
	
	
	for(int i= 0; i<5; i++)
	{
		
		for(int j =0; j<5; j++)
		{
			printf("Enter department %s for month %d: ", dep[i], j+1);
			scanf("%d", &arr[i][j]);
		}
	}
}
void outputdata(int arr[5][5], char ** dep, char**month)
{
	for(int j=0; j<5; j++)
		{
			printf("%s", month[j]);
		}printf("\n");
	for(int i = 0;i< 5; i++)
	{
		printf("%s\t", dep[i]);
		
		for(int j=0;j<5;j++)
		{
			
			printf("%d ", arr[i][j]);
			
		}
		printf("\n");
	}
}


int main()
{
	char *departments[] = {"surgery", "emergency", "skin", "Covid-19", "Dentistry"};
	char *month[] = {"Jan ", "Feb ", "Mar ", "Apr ", "May "};
	int arr[5][5];
	inputdata(arr, departments);
	printf("\n");
	printf("---------------------Result---------------------\n");
	outputdata(arr, departments, month);
}