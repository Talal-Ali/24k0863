#include<stdio.h>
#include<string.h>

int main()
{
	int i, flag = 1, len, result, thisnum;
	char inp[1000];
	do
	{
		scanf("%s", inp);
		for(i=0;inp[i] != '\0'; i++)
		{
			if(inp[i] < '0' || inp[i]>'9')
			{
				flag = 0;
			}
		}
	}while(!flag);
	len = strlen(inp);
	int max=0, min = 10;
	for(i=0;inp[i] != '\0'; i++)
	{
		thisnum = inp[i] - '0';
		if(thisnum>max) max = thisnum;
		if(thisnum<min) min = thisnum;
	}
	if(len%2)
	{
		result = (min*10) + max;
		
	}
	else
	{
		result = (max*10) + min;
	}
	printf("%d", result);
}
