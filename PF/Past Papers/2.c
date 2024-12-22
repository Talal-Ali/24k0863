#include<stdio.h>
#include<string.h>
int main()
{
	char cnic[15];
	printf("Enter your cnic number: ");
	scanf("%s", cnic);
	int flag = 0, sum=0;
	for(int i = 0; i<15; i++)
	{
		int c = i;
		for(int j=0; j<=c; j++)
		{
			
			if(cnic[i] != '-')
			{
				printf(" ");
			}
			else
			{
				c--;
				
				
				
			}
			
		}
		if(cnic[i] != '-')
		{
			printf("%c", cnic[i]);	
			
			
		}	
		else
			{
				c--;
			}
		printf("\n");
	}
	printf("\n");
	for(int i=0; i<15; i++)
	{
		if(cnic[i] == '-')
		{
			flag = ~flag;
			if(flag)
			{
				if(cnic[i] == '-'){
					int num =(cnic[i]+'0');
					sum+=num;
				}
				
			}
		}
	}
	sum/=3;
	printf("%d", (sum));
}