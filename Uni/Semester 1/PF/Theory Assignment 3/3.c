#include<stdio.h>
#include<stdlib.h>
#include <string.h>
void input(char * string)
{
	int i=0;
	char thisinput;
	do{
		scanf("%c", &thisinput);	
		i++;
		realloc(string, i);
		string[i-1] = thisinput;
	}while(thisinput != '\n');
	if(thisinput == '\n')
	{
		string[i] = '\0';
	}
	
}
int validateEmail(char* email)
{
	int i, atflag = 0, dotflag = 0, atcount =0;
	int len = strlen(email);
	if(len ==1)
		return 0;
	for(i=0; i<len; i++)
	{
		if(email[i] == '@')
		{
			atflag =1;
			atcount++;
			
		}
		if(atflag)
		{
			if(email[i] == '.')
			{
				dotflag = 1;
			}
		}
		
	}
	if((atcount ==1) && dotflag)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int main()
{
	char * string = (char* ) malloc(sizeof(char));
	input(string);
	int result = validateEmail(string);
	if(result)
	{
		printf("Valid Email");
	}
	else
	{
		printf("Invalid Email");
	}
	free(string);
}