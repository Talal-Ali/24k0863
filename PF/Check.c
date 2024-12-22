#include <stdio.h>
#include <stdlib.h>

void input(char *string) {
    int i = 0;
    char thisinput;

    while (1) {
        scanf("%c", &thisinput);

        // Reallocate memory for one additional character
        char *temp = realloc(string, i + 2); // +2 for current char and null-terminator
        if (temp == NULL) {
            printf("Memory allocation failed\n");
            free(string);
            exit(1);
        }
        string = temp;

        // Store the character
        string[i] = thisinput;

        // Break the loop on newline
        if (thisinput == '\n') {
            string[i] = '\0'; // Replace newline with null-terminator
            break;
        }

        i++;
    }

    printf("You entered: %s\n", string);
    free(string);
}

int main() {
    char *string = (char *)malloc(1); // Allocate initial memory
    if (string == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    input(string);
    return 0;
}
