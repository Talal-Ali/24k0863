#include<string.h>
#include<stdio.h>
/*
Question 1: 3D Array String Storage
Write a program to store and manipulate multiple sentences in a 3D array. The program should:

Allow the user to input sentences of up to 20 characters.
Store up to 3 sets of 5 sentences each.
Create a function that calculates the average length of words in each set of sentences.
*/
void average(char sent[3][20][5])
{
	int i,j,k;
	int count = 0, len[3][5];
	float avg;
	
	for(k=0;k<3;k++)
	{
		for(i=0;i<20;i++)
		{
			for(j=0;j<5;j++)
			{
				if(sent[k][i][j] >= 'a' && sent[k][i][j] <= 'z')
				{
					sent[k][i][j] -=32;
				}
			}
		}
	}
	
	for(k=0;k<3;k++)
	{
		for(j=0;j<5;j++)
		{
			len[k][j] = strlen(sent[k][j]);
			count += len[k][j];
			
		}
		avg = (float)count/(j++);
		printf("Average length of words in set %d: %.3lf\n", k + 1, avg);
		count =0;
	}
}
	int main()
	{
		char sent[3][20][5];
		int i,j,k;
		for(k=0;k<3;k++)
		{
			printf("\nNew Page\n");
			for(j=0;j<5;j++)
			{
				fgets(sent[k][j], 20, stdin);
            	sent[k][j][strcspn(sent[k][j], "\n")] = '\0';

			}
			
		}
		average(sent);
	}
