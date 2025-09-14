#include <stdio.h>

int main() {
    int n, i, j;
    printf("Enter a number: ");
    do{
    	scanf("%d", &n);
	}
    while(n%2 == 0);

    for(i = n; i >= 1; i -= 2) {
        for(j = 1; j <= i; j++) {
            printf("%d ", i);
        }
        printf("\n");
    }
    
}

