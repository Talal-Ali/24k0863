#include<stdio.h>
typedef struct cars
{
	int manuyear;
	char model[50];
	int price;
	int mileage;
} car;
void searchbymodel(car *cars, int len, char *mod)
{
	int i;
	for(i=0; i< len; i++)
	{
		if(!strcmp(cars[i].model, mod))
		{
			printf("%d %s %d %d\n", cars[i].manuyear, cars[i].model, cars[i].price, cars[i].mileage);
		}
	}
}
void searchbyyear(car *cars, int len, int y)
{
	int i;
	for(i=0; i< len; i++)
	{
		if(cars[i].manuyear == y)
		{
			printf("%d %s %d %d\n", cars[i].manuyear, cars[i].model, cars[i].price, cars[i].mileage);
		}
	}
}

int main()
{
	car cars[4];
	int i;
	for(i=0; i<4; i++)
	{
		scanf("%d %s %d %d", &cars[i].manuyear, cars[i].model, &cars[i].mileage, &cars[i].price);
	}
	printf("Search by model\n");
	char m[50];
	scanf("%s", m);
	searchbymodel(cars, 4, m);
	printf("Search by year\n");
	int y;
	scanf("%d", &y);
	searchbyyear(cars, 4, y);
}