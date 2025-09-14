#include <stdio.h>
int main()
{ 
	int values[4], input =0, i, j, x,y =0, max =0;
	char pref = ' ';
	printf("What type of histogram do you want?\n");
	do{
		scanf(" %c", &pref);
	}while(pref != 'h' && pref != 'v');
	
	printf("enter your values:\n");
	for(i=0; i<4; i++){
		do{
			scanf("%d", &input);
		}while(input<0);
		values[i] = input;
	}
	// Logic for x axis
	if(pref == 'h')
	{
		for(x=0; x<4; x++)
		{
			printf("Value %d: ", values[x]);
			for(y=0; y<values[x]; y++)
			{
					
				
				printf("*");
				
				
				
			}
			printf("\n");
		}
	}
	
	
	// Logic for y axis
	if(pref == 'v'){
		for(j =0; j<4; j++)
		{
			if (values[j] > max)
			{
				max = values[j];
			}
		}
		
		for(x = max; x>0; x--)
		{
			for (y=0; y<4; y++)
			{
				if(values[y] >= x)
				{
					printf("* ");
				}
				else
				{
					printf("  ");
				}
			}
			printf("\n");
		}
		printf("\n");
		for(i=0; i<4; i++)
		{
			printf("%d ", values[i]);
		}
	}
	
}
