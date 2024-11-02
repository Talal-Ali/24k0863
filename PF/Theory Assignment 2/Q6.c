#include<stdio.h>
int Move(int num)
{
	return num%5;
}
int main()
{
	printf("Enter your match stick number:\n");
	int n;
	do{
		scanf("%d",&n);
	}while(n<0);
	int st = Move(n);
	if(st)
	{
		printf("move stick %d to win", st);
	}
	else
	{
		printf("Cannot win");
	}
	
	
}