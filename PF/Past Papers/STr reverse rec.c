#include<stdio.h>
#include<string.h>

void reverseSentence(char* str) {
    // Base case: if the string is empty or contains only one word
    if (*str == '\0') {
        return;
    }
	char* space = strchr(str, ' ');

    // If there's a space, call reverseSentence recursively for the next word
    if (space != NULL) {
        *space = '\0';  // Temporarily terminate the first word
        reverseSentence(space + 1);  // Recursively reverse the rest
        printf("%s ", str);  // Print the first word after recursion
    } else {
        // If no space is found (last word), just print the word
        printf("%s ", str);
    }
}

int main()
{
	char str[] = "Choti lulli 69";
	reverseSentence(str);
}