#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int size = 2;
    int count = 0;
    char** strings = (char**)malloc(size * sizeof(char*));

    printf("Enter strings (type 'STOP' to end):\n");
    while (1) {
        char buffer[100];
        scanf("%s", buffer);

        if (strcmp(buffer, "STOP") == 0) {
            break;
        }
        if (count == size) {
            size *= 2;
            strings = (char**)realloc(strings, size * sizeof(char*));
            
        }

        strings[count] = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(strings[count], buffer);
        count++;
    }

    printf("\nYou entered:\n");
    for (int i = 0; i < count; i++) {
        printf("%s\n", strings[i]);
        free(strings[i]);
    }

    free(strings);

}
