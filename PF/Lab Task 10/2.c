#include <stdio.h>
#include <math.h>
struct co
{
	int x;
	int y;
};
float distance(int x1, int y1, int x2, int y2)
{
	struct co c1, c2;
	c1.x = x1;
	c1.y = y1;
	c2.x = x2;
	c2.y = y2;
	
	int diffx = c1.x - c2.x;
	int diffy = c1.y - c2.y;
	
	int sum = pow(diffx, 2) + pow(diffy, 2);
	float result = pow(sum, 0.5);
	return result;
}
int rect(struct co c, int xmax, int xmin, int ymax, int ymin)
{
	if(c.x <= xmax && c.x>= xmin && c.y <= ymax && c.y >= ymin)
	{
		printf("\nInside the rectangle");
	}
	else
	{
		printf("\nOutside the rectangle");
	}
}
int main()
{
	struct co c1, c2;
	c1.x = 2;
	c1.y = 3;
	c2.x = 4;
	c2.y = 5;
	float dis = distance(c1.x, c1.y, c2.x, c2.y);
	printf("The distance is: %.3lf ", dis);
	rect(c1, 15, -2, 3, -1);
}
