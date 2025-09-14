#include<stdio.h>
#include<stdlib.h>

typedef struct salaryrecords{
	char name[50];
	char id[50];
	int salary;
}salaryrecord;


int main()
{
	FILE *ptr = fopen("Example.bin", "wb");
	int i;
	int total = 0;
	salaryrecord sr[3];
	for(i=0; i<3; i++)
	{
		scanf("%s", sr[i].name);
		scanf("%s", sr[i].id);
		scanf("%d", &sr[i].salary);
		fwrite(&sr[i], sizeof(salaryrecord), 1, ptr);
	}
	fclose(ptr);
	salaryrecord temp;
	ptr = fopen("Example.bin", "rb");
	for(i=0; i<3; i++)
	{
		fread(&temp, sizeof(salaryrecord), 1, ptr);
		total += temp.salary;
	}
	fclose(ptr);
	printf("\nTotal: %d", total);
}