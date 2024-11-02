#include<stdio.h>
int main()
{
	int arr[100];
    int i = 0, j;
    int number;
    scanf("%d", &number);
    while (number > 0) {
        arr[i] = number % 2;
        number = number / 2;
        i++;
    }
    printf("Binary: ");
    
    for (j = i - 1; j >= 0; j--)
        printf("%d", arr[j]);
    int num =0, mult =1;
      for (j = 0; j < i; j++) {  // Construct the integer from binary array
        num += arr[j] * mult;
        mult *= 10;
    }
	printf("\n%d", num);
}

