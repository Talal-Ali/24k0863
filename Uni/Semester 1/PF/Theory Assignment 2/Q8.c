#include<stdio.h>
#include<string.h>
int BinaryToDecimal(int n)
{
	int dec = 0,base = 1, temp = n, rem;
    while (temp > 0) {
        rem = temp % 10;
        if (rem != 0 && rem != 1) {
            printf("Invalid Input\n");
            return -1;
        }
        temp /= 10;
    }

    temp = n;

    while (temp > 0) {
        rem = temp % 10;
        dec += rem * base;
        base *= 2;
        temp /= 10;
    }

    return dec;
}
int DecimalToBinary(int n)
{
	int bin[10000], i=0,j,mult=1, num = 0;
	
	
	while(n>0)
	{
		bin[i] = n%2;
		
		num += mult * bin[i];
		mult*=10;
		i++;
		n /=2;
	}
	return num;

}
void DecimalToHexadecimal(int n)
{
	char hexa[10000], str='\0';
	int i=0,j,hex;
	while(n>0)
	{
		hex = n%16;
		if(hex <10)
		{
			hex+=48;
		}
		else{
			hex+=55;
		}
		
		hexa[i] = hex;
		i++;
		n/=16;
	}
	for(j=i-1; j>=0; j--)
	{
		printf("%c", hexa[j]);
	}
}
void HexadecimalToDecimal(char hex[])
{
	int i, val, len, dec = 0;
	len = strlen(hex);
	int temp = 0, base = 1;
	for(i=0; hex[i]!= '\0'; i++)
	{
		if(hex[i] >='a' && hex[i]<='f')
			{
				hex[i] -=32;
			}
	}
	for (i = 0; hex[i] != '\0'; i++) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            val = hex[i] - '0';
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            val = hex[i] - 65 + 10;
        } else {
            printf("Not Valid");
            return;
        }
        
        dec = dec * 16 + val;
        
    }
    
	printf("%d", dec);
	
}
void BinaryToHexadecimal(int number)
{
	int dec = BinaryToDecimal(number);
	DecimalToHexadecimal(dec);
}
void HexadecimalToBinary(char hex[])
{
	
	int i, val, len, dec = 0, j;
	len = strlen(hex);
	int temp = 0;
	for(i=0; hex[i]!= '\0'; i++)
	{
		if(hex[i] >='a' && hex[i]<='f')
			{
				hex[i] -=32;
			}
	}
	for (i = 0; hex[i] != '\0'; i++) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            val = hex[i] - '0';
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            val = hex[i] - 65 + 10;
        } else {
            printf("Not Valid");
            return;
        }
        
        dec = dec * 16 + val;
    }
   int bin[10000] = {0};
   i = 0;
    while (dec > 0) {
        bin[i] = dec % 2;
        i++;
        dec /= 2;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", bin[j]);
    }
	
	
}

int main()
{
	char hexnums[10000];
	int inp, menu, dec, bin;
	do
	{
		printf("\n\tConversion\t\nPress the keys corresponding to the index for following conversions\n1.BinaryToDecimal\n2.DecimalToBinary\n3.DecimalToHexadecimal\n4.HexadecimalToDecimal\n5.BinaryToHexadecimal\n6.HexadecimalToBinary\n7.Exit\n");
		scanf("%d", &menu);
		if(menu<1 || menu>7)
		{
			printf("Error, Input the correct prompt\n");
			continue;
		}
		else
		{
			switch(menu){
				case 1: do
						{
							scanf("%d", &inp);
							if(inp<0)
								printf("Negative numbers not allowed");
						}while(inp<0);
						dec = BinaryToDecimal(inp);
						printf("%d", dec);
						break;
				case 2:
						scanf("%d", &inp);
						bin = DecimalToBinary(inp);
						printf("%d", bin);
						break;
				case 3:
						do
						{
							scanf("%d", &inp);
							if(inp<0)
								printf("Negative numbers not allowed");
						}while(inp<0);
						DecimalToHexadecimal(inp);
						
						printf("%d", dec);break;
				case 4:
						scanf("%s", hexnums);
						HexadecimalToDecimal(hexnums);
						break;
				case 5:
						scanf("%d", &inp);
						BinaryToHexadecimal(inp);
						break;
				case 6:
						scanf("%s", hexnums);
						HexadecimalToBinary(hexnums);
						break;
				default:
						return 0;
						
						
			}
		}
	}while(menu!=7);
	
	
}