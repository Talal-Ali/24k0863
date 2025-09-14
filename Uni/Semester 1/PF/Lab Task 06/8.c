#include<stdio.h>
int main()
{
	int n, i, fact =1;
	scanf("%d", &n);
	
	if(n>=0)
	{
		for(i =n; i>0; i--)
		{
			fact*= i;
		}
		printf("%d", fact);
	}
	else{
		printf("Value should be positive");
	}
}
