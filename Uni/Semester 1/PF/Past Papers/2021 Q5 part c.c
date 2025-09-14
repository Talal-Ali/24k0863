#include <stdio.h>
#include <string.h>

void check(char *str, char *pattern) {
    int slen = strlen(str);
    int tlen = strlen(pattern);

    if (slen == 0 || tlen == 0) return;

    int i = 0, j = 0;
    int star_idx = -1, match_idx = 0;

    while (i < slen) {
        // If characters match or pattern has '?'
        if (j < tlen && (pattern[j] == str[i] || pattern[j] == '?')) {
            i++;
            j++;
        }
        // If pattern has '*', remember its position
        else if (j < tlen && pattern[j] == '*') {
            star_idx = j;
            match_idx = i;
            j++;  // Move past '*' in the pattern
        }
        // If mismatch happens, backtrack if '*' was found
        else if (star_idx != -1) {
            j = star_idx + 1;   // Skip past the '*' in the pattern
            i = match_idx + 1;  // Try the next character in the string
            match_idx = i;
        }
        // If no match, return early
        else {
            printf("No match\n");
            return;
        }
    }

    // Skip remaining '*' characters in the pattern
    while (j < tlen && pattern[j] == '*') {
        j++;
    }

    // If all characters in the pattern are consumed, it's a match
    if (j == tlen) {
        printf("Match\n");
    } else {
        printf("No match\n");
    }
}

int main() {
    char str[] = "xxxxxyxyyyyxyxyxxxy";
    char pattern[] = "x***x";
    check(str, pattern);
    return 0;
}
