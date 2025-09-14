#include <stdio.h>
#include<ctype.h>
int main() {
	char str[100];
	int i, flag =1;
	

	printf("Enter a string: ");
	scanf("%[A-Za-z]", str);
	for(i=0;str[i] != '\0';i++)
	{
		if (isprint(str[i])== 0)
			flag = 0;
	}
	if (flag)
	{
		printf("You entered: %s\n", str);
	}
	else
		printf("Error");

}