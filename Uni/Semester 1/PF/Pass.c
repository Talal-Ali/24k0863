#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int textfile(char * username, char* password)
{
	FILE *ptr = fopen("data.txt", "r");
	if(ptr == NULL)
	{
		printf("File not found");
		return 0;
	}
	char line[200];
	int i =0;
	while(fgets(line, sizeof(line), ptr) != NULL)
	{
		line[strcspn(line, "\n")] = 0;
		if(i%2 == 0)
		{
		
			if(!strcmp(line, username))
			{
				
				if(i%2!=1)
				{
					if(!strcmp(line, password))
					{
						fclose(ptr);
						return 1;
					}
				}
			}
		}
		i++;
	}
	fclose(ptr);
	return 0;
}
void inputhandling(char *un, char *pas)
{
	int i=0;
	char thisinput;
	do{
		scanf("%c", &thisinput);	
		i++;
		realloc(un, i);
		un[i-1] = thisinput;
	}while(thisinput != '\n');
	un[strcspn(un, "\n")] = 0;
	i=0;
	do{
		scanf("%c", &thisinput);	
		i++;
		realloc(pas, i);
		pas[i-1] = thisinput;
	}while(thisinput != '\n');
	pas[strcspn(pas, "\n")] = 0;
}
int main()
{
	char *un = (char *) malloc(100 * sizeof(char));
	char *pas = (char *) malloc(100 * sizeof(char));
	
	puts("Enter your username and then your password\n");
	
	fgets(un, 100, stdin);
	un[strcspn(un, "\n")] = 0;
	fgets(pas, 100, stdin);
	pas[strcspn(pas, "\n")] = 0;
	printf("\n");
	int result = textfile(un, pas);
	if(result)
	{
		printf("Success");
	}
	else
	{
		printf("Not Successful");
	}
	free(un);
	free(pas);
}