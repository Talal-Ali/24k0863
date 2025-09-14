#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Enter the length of the string: ");
    int len;
    scanf("%d", &len);
    char* str = (char*)malloc((len + 1) * sizeof(char));
    printf("Enter the string: ");
    scanf("%s", str);
    
    int isPalindrome = 1;
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            isPalindrome = 0;
            break;
        }
    }
    if (isPalindrome) {
        printf("The string \"%s\" is a palindrome.\n", str);
    } else {
        printf("The string \"%s\" is not a palindrome.\n", str);
    }
    free(str);

    return 0;
}
