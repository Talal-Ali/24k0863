#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Enter the number of strings: ");
    int numStrings;
    scanf("%d", &numStrings);

    char* result = (char*)malloc(1 * sizeof(char));
    
    result[0] = '\0';

    printf("Enter your strings:\n");
    for (int i = 0; i < numStrings; i++) {
        char buffer[100];
        scanf("%s", buffer);
        result = (char*)realloc(result, (strlen(result) + strlen(buffer) + 1) * sizeof(char));

        strcat(result, buffer);
    }
    printf("\nThe concatenated string is: %s\n", result);
    free(result);

}
