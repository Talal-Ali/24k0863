#include<stdio.h>
void encryptMessage(char str[100], int n)
{
	int i;
	for(i=0;str[i] != '\0'; i++)
	{
		str[i] += n;
		
	}
	printf("Encrypted: %s\n", str);
}
void decryptMessage(char str[100], int n)
{
	int i;
	for(i=0;str[i] != '\0'; i++)
	{
		str[i] -= n;
		
	}
	printf("Decrypted: %s\n", str);
}
int main()
{
	char str[100];
	printf("Enter your string: ");
	scanf("%s", str);
	int n;
	printf("Enter your shift number: ");
	scanf("%d", &n);
	encryptMessage(str, n);
	decryptMessage(str, n);
}