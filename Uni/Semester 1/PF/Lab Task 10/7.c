#include<stdio.h>
void convcount(float m) {
	const float cfact = 0.001;
	float km = m * cfact;
	printf("%f meters is %f in kilometers", m, km);
    static int cc = 0;
    cc++;
    printf("Function has been called %d times\n", cc);
}
int main()
{
	convcount(5.0);
	convcount(6.0);
}