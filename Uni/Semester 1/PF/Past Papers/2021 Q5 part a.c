#include<stdio.h>
#include<string.h>
void Reverse(char* str, int len)
{
	for(int i=0; i<(len/2);i++)
	{
		str[i] = str[i]+str[len-i-1];
		str[len-i-1] = str[i] - str[len-i-1];
		str[i] = str[i] - str[len-i-1];
	}
	printf("\n Reverse: %s\n", str);
}

int main()
{
	char *str = "Hello World";
	int len = strlen(str);
	Reverse(str, len);
}