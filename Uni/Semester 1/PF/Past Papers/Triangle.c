#include<stdio.h>


int main()
{
	int rows = 4;
//	for(int i=0; i<rows; i++)
//	{
//		for(int j = 0; j<rows-i; j++)
//		{
//			printf(" ");
//		}
//		for(int j = 0; j<=i; j++)
//		{
//			printf("*");
//		}printf("\n");
//	}
	
	
//	for(int i=rows; i>0; i--)
//	{
//		for(int j =0; j<=i; j++)
//			printf("*");
//		printf("\n");
//	}
//for(int i=1; i<=rows; i++)
//	{
//		printf("\n");
//		for(int j=1; j<=rows-i;j++)
//		{
//			printf(" ");
//		}
//		for(int j=0; j< 2*i-1; j++)
//		{
//			printf("*");
//		}
//	}
 for(int i=rows; i>0; i--)
	{
		printf("\n");
		for(int j= rows-i; j>0; j--)
		{
			printf(" ");
		}
		for(int j=2*i-1;j>0; j--)
		{
			printf("*");
		}
	}
	
	
}