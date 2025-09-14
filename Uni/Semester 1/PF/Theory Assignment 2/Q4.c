#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int char_compare(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}
int main()
{
	char * transactions[] = {"bat", "ate", "tan", "eat", "tea", "nat"};
	char temp[100][100];
	int i, j;
	int row = sizeof(transactions) / sizeof(transactions[0]);
	for(i=0; i<100; i++)
	{
		for(j=0;j<100;j++)
			temp[i][j] = '\0';
	}	
	for(i=0; i<row; i++)
	{
		for(j=0; transactions[i][j] != '\0'; j++)
		{
			strcpy(temp[i], transactions[i]);
			qsort(temp[i], strlen(temp[i]), sizeof(char), char_compare);
		}
	}
	int gr[100] = {0};
	for(i=0; i<row; i++)
	{
		if (gr[i]==1) continue;
		printf("[\"%s\"", transactions[i]);
    	gr[i] = 1;
		 for (j = i + 1; j < row; j++) {
            if (!gr[j] && !strcmp(temp[i], temp[j])) {
                printf(", \"%s\"", transactions[j]);
                gr[j] = 1;
            }
	}
	printf("]\n");
	}
}
