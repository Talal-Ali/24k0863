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
	int a,b,t;
	a=0;
	b=1;
	t=0;
	if(lcm == n){
		t = a+b;
		printf(" %d", a);
		while(t<n)
		{
			printf(" %d", t);
			t=a+b;
			a=b;
			b=t;
			
		}
	}
	
}
