#include<stdio.h>

int isprime(int n)
{
	int i, flag =1;
	for(i=2;i<n;i++)
	{
		if(n%i == 0)
		{
			flag = 0;
		}
	}
	return flag;
}
int main()
{
	int n;
	scanf("%d", &n);
	(isprime(n))? printf("Prime") : printf("Not Prime");
}