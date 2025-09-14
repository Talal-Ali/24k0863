#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//Question required the addition of a 3x4 and a 4x3 matrix
void jam(int ** speed, int **jammer, int dob)
{
	int resultant[3][4];
	float sum =0;
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<4; j++)
		{
			resultant[i][j] = speed[i][j] + jammer[i][j];
			sum+= (float)resultant[i][j];
			
		}
		
	}
	sum/=12;
	if((int) sum >dob)
	{
		printf("Most devastating attack");
	}
	else
	{
		printf("Least devastating attack");
	}
}

int main()
{
	int ** speed = (int**) malloc(3*sizeof(int*));
	for(int i =0; i<3; i++)
	{
		speed[i] = (int*) malloc(4*sizeof(int));
	}
	
	int ** jac = (int**) malloc(3*sizeof(int*));
	for(int i =0; i<3; i++)
	{
		jac[i] = (int*) malloc(4*sizeof(int));
	}
	
	int lsisd, dob, msdby, bm, lsdhn, td;
	
	printf("Enter lsisd, dob, msdby, bm,lsdhn, td\n");
	scanf("%d %d %d %d %d", &lsisd, &dob, &msdby, &bm, &lsdhn, &td);
	
	speed = {{bm, 6, 10, lsdhn},
				{3,4,lsisd, 23},
				{td, 45, 100, msdby}
	};
	jac = { {1,0,12,100},
			{100,110,12,100},
			{11, 10, 112, 100}};
	int jammer
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<4; j++)
		{
			
		}
	}
	jam( speed, jac, dob);
	for(int i=0; i<3; i++)
	{
		free(speed[i]);
	}
	free(speed);
	for(int i=0; i<3; i++)
	{
		free(jammer[i]);
	}
	free(jammer);
	
}