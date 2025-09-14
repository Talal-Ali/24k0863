#include <stdio.h>


void inputing(int max)
{
	static int count =0;
	int inp;
	printf("\nEnter your temperature: ");
	scanf("%d", &inp);
	if(inp>max)
	{
		count++;
		printf("Exceeded amount %d\n", count);
	}
}
int main()
{
	const int m = 70;
	int i;
	for(i=0; i<10; i++)
	{
		inputing(m);
	}
	
}