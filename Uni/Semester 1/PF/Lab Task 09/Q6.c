#include<stdio.h>
#include<string.h>

void reverse(char *str)
{
	int len = strlen(str),i;
	char temp[len + 1];
    
    for(i = 0; i < len; i++) {
        temp[i] = str[len - 1 - i];
    }
	temp[len] = '\0';
	printf("%s", temp);
}
int main()
{
	char str[] = "Hello World";
	reverse(str);
}