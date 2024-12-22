#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void Concat(char * str1, char * str2, int size1, int size2)
{
	char * neww =  (char*)malloc((size1+ size2+1)*sizeof(char));
	if(neww == NULL)
	{
		printf("Memory allocation error");
		return;
	}
	printf("string 1 %s, string 2 %s", str1, str2);
	strcpy(neww,strcat(str1,str2));
	printf("\nstring concatenated %s", neww);
	char c;
	
	while(1)
	{
		scanf(" %c", &c);
		if(c == 'Q'|| c== 'q')
		{
			break;
		}
		
		neww = (char *)realloc(neww,(strlen(neww)+1)*sizeof(char));
		if(neww == NULL)
		{
			printf("Memory re-allocation error");
			return;
		}
		neww[strlen(neww)] = c;
		neww[strlen(neww)+1] = '\0';
	}
	printf("new string %s", neww);
	free(neww);
}

int main()
{
	char str1[] = "Hello";
	char str2[] = "World";
	int size1 = 5;
	int size2 = 5;
	Concat(str1, str2, size1, size2);
}