#include <stdio.h>
int main()
{
	int oldval, val, flag, yr, rnum, i;
	char roll[7];
	
	flag =0;
	//Authentication
	do
	{
		scanf("%s", &roll);
		
		if(roll[0] == '2' )
		{
			if(roll[1] == '1')
			{
				yr = 21;
			}
			else if( roll[1] == '2')
			{
				yr = 22;
			}
			else if(roll[1] == '3')
			{
				yr = 23; 
			}
			else if(roll[1] == '4')
			{
				yr = 24;
			}
		}
		if (roll[2] == 'k' && yr>=21 && yr<= 24)
		{	
			for(i=3; i<7; i++)
			{
				if(roll[i] >='0' && roll[i] <='9')
				{
					flag = 1;
				}
			}
			
		}
		if(flag ==0)
		{
			
			printf("invalid ID");
		}
	
	} while(flag=0);
	
	// QS working
	int a = roll[3] - '0';
	int c = roll[4] - '0';
	
	printf("%d %d", a, c);

}

