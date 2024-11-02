#include <stdio.h>

int main() {
    int fuel;
    float cost;
    const float rate = 1.50;

    cost = 0;

    do {
        printf("Enter litres of fuel (or 0 to stop): ");
        scanf("%d", &fuel);

        if (fuel > 0) {
            cost += fuel * rate;
        }
    } while (fuel != 0);

    printf("Total cost: $%.2f\n", cost);

    
}

