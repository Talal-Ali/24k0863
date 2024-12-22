#include<stdio.h>
#include<stdlib.h>

typedef struct employees
{
	char name[50];
	char id[50];
	int salary;
}employee;

typedef struct departments
{
	char depname[50];
	char depid[50];
	employee e[10];
}department;

void totalSalary(department d)
{
	int total=0, i;
	for(i=0; i<10; i++)
	{
		total += d.e[i].salary;
	}
	printf("\nTotal Salary in this department:%d", total);
}

int main()
{
	int i;
	department d;
	strcpy(d.depid, "001");
	strcpy(d.depname, "CS");
	for(i=0;i<10;i++)
	{
		scanf("%s", d.e[i].id);
		scanf("%s", d.e[i].name);
		scanf("%d", &d.e[i].salary);
	}
	totalSalary(d);
}