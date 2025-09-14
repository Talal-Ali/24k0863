#include<stdio.h>
#include<string.h>

typedef struct
{
	char name[50];
	int price;
	int quantity;
}items;

void Initialisation()
{
	int i;
	items it[8];
	for(i=0; i<8; i++)
	{
		printf("Enter the name of item\n");
		scanf("%s", it[i].name);
		printf("Enter price\n");
		scanf("%d", &it[i].price);
		printf("Enter quantity\n");
		scanf("%d", &it[i].quantity);
	}
	
}

void getinfo(items it[], int size)
{
	int i;
	char cheapness[][3];
	char t;
	for(i=0; i<size; i++)
	{
		t = it[i].price;
		if(t < 20)
		{
			strcpy(cheapness[0], it[i].name);
		}
		else if(t>= 20 && t<=100)
		{
			strcpy(cheapness[1],  it[i].name);
		}
		else if(t>100)
		{
			strcpy(cheapness[2],  it[i].name);
		}
	}
	
	
}