#include<stdio.h>
#include<math.h>

float area(int r)
{
	float ar = M_PI * pow(r, 2);
	return ar;
}
int main()
{
	int r;
	printf("Enter radius: ");
	scanf("%d", &r);
	float result = area(r);
	printf("Area: ");
	printf("%f", result);
}