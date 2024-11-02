#include<stdio.h>
int main()
{
	int n, thisnum, temp, total;
	scanf("%d", &n);
	temp =n;
	total =0;
	while(temp>0)
	{
		thisnum = temp%10;
		total += thisnum*thisnum*thisnum;
		temp /=10;
	}
	if(total == n)
	{
		printf("Armstrong number");
	}
	else
	{
		printf("Not an armstrong number");
	}
}
