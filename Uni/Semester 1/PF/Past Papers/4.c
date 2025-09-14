#include<stdio.h>

int shapatar(int distance, int t1sp, int t2sp, int hsp)
{
	
	int sum =0;
	if(distance <=0)
	{
		return 0;
	}
	int curr = (hsp*distance)/(t1sp+t2sp);
	//distance -= (t1sp+t2sp);
	sum+= curr;
	return sum + shapatar(distance-(t1sp+t2sp), t1sp, t2sp, hsp);
}
int main()
{
	int r = shapatar(100, 50, 70, 80);
	printf("%d", r);
}