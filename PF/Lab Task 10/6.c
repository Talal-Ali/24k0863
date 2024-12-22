#include<stdio.h>
typedef struct pack
{
	char name[50];
	char dest[50];
	char duration[50];
	int cost;
	int seats;	
}p;
int main()
{
	p pa[2] = {{"Mountains", "K2", "7 days", 30000, 15},
			  {"Coastline", "Ormara", "3 days", 20000, 7}};
	for(int i = 0; i<2; i++)
	{
		printf("%s %s %s %d %d\n", pa[i].name, pa[i].dest, pa[i].duration, pa[i].cost, pa[i].seats);
	}
	
	printf("Enter your choice(0 or 1): ");
	int choice;
	do{
		scanf("%d", &choice);
	}while(choice<0 || choice >1);
	if(pa[choice].seats>0)
	{
		printf("You have been booked here is your bill: %d", pa[choice].cost);
		pa[choice].seats--;
		printf("\n%d Seats left", pa[choice].seats);
	}
	else
	{
		printf("Out of seats");
	}
	
}