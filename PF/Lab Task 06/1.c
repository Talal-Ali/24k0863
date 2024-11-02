#include <stdio.h>
int main()
{
	int input, sum;
	sum =0;
	printf("Enter your number: ");
	do{
		scanf("%d", &input);
		sum += input;
		printf("\nYour sum is: %d\n", sum);
	}while(input !=0 );
}
