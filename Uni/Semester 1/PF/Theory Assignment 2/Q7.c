#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int Search(char array[6][5], const char thisstr[100]) {
    int count = 0;
    int i, j, k;

    for (i = 0; i < strlen(thisstr); i++) {
        int found = 0;
        for (k = 0; k < 6; k++) {
            for (j = 0; j < 5; j++) {
                if (array[k][j] == thisstr[i]) {
                    found = 1;
                    count++;
                    break;
                }
            }
            if (found) break;
        }
    }
    return count == strlen(thisstr);
}

int main() {
    int i, j, k, thischar, score = 0, count = 0;
    char arr[6][5];
    char inp[5];
    char thisstr[100];
    srand(time(NULL));
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            arr[i][j] = rand() % 26 + 'A';
        }
    }
    printf("Enter your ID (i.e. 0863): ");
    scanf("%4s", inp);
    for (i = 0; inp[i] != '\0'; i++) {
        arr[5][i] = inp[i];
    }
    arr[5][4] = 'Q';
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 5; j++) {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }

    printf("The game has begun\n");

    do {
        int alpha;
        do {
            alpha = 1;
            printf("Enter a string to search (or type EXIT to quit): ");
            fgets(thisstr, sizeof(thisstr), stdin);
            thisstr[strcspn(thisstr, "\n")] = '\0';

            for (i = 0; thisstr[i]; i++) {
                if (!isalpha(thisstr[i])) {
                    printf("String must be only in characters\n");
                    alpha = 0;
                    break;
                }
                thisstr[i] = toupper(thisstr[i]);
            }
        } while (!alpha);

        if (strcmp(thisstr, "EXIT") == 0) break;

        if (strlen(thisstr) > 25) {
            printf("Invalid Input\n");
            continue;
        }
        if (Search(arr, thisstr)) {
        		if(count!=0)
					printf("Does match: %d\n", ++score);
        		count++;
        } else{
				if(count!=0)
					printf("Does not match: %d\n", --score);
				count++;
        }
    } while (1);
}

