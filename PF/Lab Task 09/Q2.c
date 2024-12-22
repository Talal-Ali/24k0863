#include<stdio.h>
#include<string.h>

void Palin()
{
	int i,j,flag;
	char str[5][20];
	printf("Enter your list\n");
	for(i=0;i<5;i++)
	{
		
		scanf("%s", str[i]);
	}
	
	for(i=0; i<5; i++)
	{
		flag =0;
		for(j=0;j<strlen(str[i])/2;j++)
		{
			if(str[i][j] == str[i][strlen(str[i])-j-1])
			{
				flag = 1;
			}
			else
			{
				flag = 0;
				break;
			}
			
		}
		printf("Output:\n");
		(flag)? printf("Palindrome\n"): printf("Not Palindrome\n");
	}
}
int main()
{
	Palin();
	
}