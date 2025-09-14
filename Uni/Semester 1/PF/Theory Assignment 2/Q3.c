#include<stdio.h>
#include<string.h>
int main()
{
	char words[100][100], temp[100];
    int count[256] = {0}, cou =0;
    int i, j;
    temp[0] = '\0';
    
    printf("Enter words (type 'END' to stop):\n");
    for (i = 0; i < 100; i++) {
        scanf("%s", words[i]);
		int len = strlen(words[i]);
        if (strcmp(words[i], "END") == 0) {
            break;
        }
        for (j = 0; words[i][j] != '\0'; j++) {
            if (count[(int)words[i][j]] == 0) {
                count[(int)words[i][j]] += 1;
                cou+= (len-count[(int)words[i][j]]);
                char ch[2] = {words[i][j], '\0'};
                strcat(temp, ch);
            }
            
        }
        printf("%s\n", temp);
        temp[0] = '\0';
        printf("%d\n", cou);
        for(j=0;j<256;j++)
    		count[j] = 0;
    	cou=0;
    }
}
