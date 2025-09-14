#include<stdio.h>
#include<string.h>
void reversewords(char * str, int i)
{
	
	if(i<0)
	{
		return;
	}
	printf("%c", str[i]);
	i--;
	reversewords(str, i);
	
}

int main()
{
	char str[] = "Hello World";
	int len = strlen(str);
	reversewords(str, len);
}