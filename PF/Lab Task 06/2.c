#include <stdio.h>
int main()
{
	int n, lcm;
	scanf(" %d", &n);
	lcm =1;
	while(n>lcm && n !=1)
	{
		
		if (n%lcm == 0 && lcm !=1)
		{
			printf("Is not a prime number");
			break;
		}
		//printf("%d\n", lcm);
		lcm++;
	}
	if(lcm == n){
		printf("Prime number");
	}
	
}
