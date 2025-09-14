#include <stdio.h>
#include <string.h>

void Slogan(char slogans[][100], int num_slogans) {
    char letters[256];
    int lettercount[256];   
    int i, j, k;


    for (i = 0; i < 256; i++) {
        lettercount[i] = 0;
    }

    
    for (i = 0; i < num_slogans; i++) {
        printf("For \"%s\": {", slogans[i]);

        
        for (j = 0; j < strlen(slogans[i]); j++) {
            char thisletter = slogans[i][j];
            lettercount[(int)thisletter]++;
        }

        
        for (k = 0; k < 256; k++) {
            if (lettercount[k] > 0) {
                printf("' %c': %d, ", k, lettercount[k]);
            }
        }
        printf("\b\b}\n");  

        
        for (k = 0; k < 256; k++) {
            lettercount[k] = 0;
        }
    }
}

int main() {
    char slogans[3][100] = {
        "buy now",
        "save big",
        "limited offer"
    };

    
    Slogan(slogans, 3);

}

