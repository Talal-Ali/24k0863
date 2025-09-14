#include<stdio.h>
int main()
{
	int i,j, n,lcm =1;
	scanf("%d", &n);
	for(i=2; i<=n; i++)
	{
		
		for(j=2; j<=i/2; j++)
		{
			if(i%j == 0)
			{
				lcm = 0;
				
			}
			
		}
		
		if(lcm)
		{
			printf("%d ", i);
		}
		lcm =1;
	}
}
