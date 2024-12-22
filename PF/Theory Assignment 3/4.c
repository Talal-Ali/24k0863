#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int* ratings;
	int totalscore;
}employee;

void inputEmployees(int** ratings, int numEmployees, int numPeriods)
{
	int i,j, rating;
	
	for(i=0; i<numEmployees; i++)
	{
		for(j=0; j<numPeriods; j++)
		{
			do
			{
				printf("Enter your rating for employee #%d, period#%d\n", i+1, j+1);
				scanf("%d", &rating);
				if(rating>10 || rating <1)
				{
					printf("Incorrect input\n");
				}
			}while(rating>10 || rating <1);
			
			ratings[i][j] = rating;
		}
	}
	
}

void displayPerformance(int** ratings, int numEmployees, int numPeriods) 
 {
	int i,j;
	for(i=0; i<numEmployees; i++)
	{
		for(j=0; j<numPeriods; j++)
		{
			printf("Employee number %d has a rating of %d on evaluation period %d\n", i+1, ratings[i][j], j+1);
		}
	}
 }
 
int findEmployeeOfTheYear(int** ratings, int numEmployees, int numPeriods)
 {
	int i, j, sum=0;
	employee e;
	double *temp = (double *) malloc(numEmployees * sizeof(double));
	for(i=0; i<numEmployees; i++){
		for(j=0; j<numPeriods; j++)
		{
			sum+= ratings[i][j];
			e.totalscore = sum;	
		}
		
		temp[i] = (double) sum/numPeriods;
		sum =0;
	}
	
	
	
	int lindex = 0;
	double largest = temp[0];
	for(i=0; i<numEmployees; i++)
	{
		if(temp[i] > largest)
		{
	 		largest = temp[i];
	 		lindex = i;
		}
	}
	free(temp);
	return lindex;
 }
 
int findHighestRatedPeriod(int** ratings, int numEmployees, int numPeriods) 
{
	int i,j, row, col, sum =0;
	double highest = 0.0;
	for(i=0; i< numPeriods; i++)
	{
		for(j=0; j<numEmployees; j++)
		{
			sum += ratings[j][i];
			
		}
		double avg = (double)sum / numEmployees;

        if (avg > highest) { 
            highest = avg;
            col = j;
        }
	}
	return col;
}

int findWorstPerformingEmployee(int** ratings, int numEmployees, int numPeriods)
 {
	int i, j, sum=0;
	double *temp = (double *) malloc(numEmployees * sizeof(double));
	for(i=0; i<numEmployees; i++){
		for(j=0; j<numPeriods; j++)
		{
			sum+= ratings[i][j];	
		}
		
		temp[i] = (double) sum/numPeriods;
		sum =0;
	}
	int sindex = 0;
	double smallest = temp[0];
	for(i=0; i<numEmployees; i++)
	{
		if(temp[i] < smallest)
		{
	 		smallest = temp[i];
	 		sindex = i;
		}
	}
	free(temp);
	return sindex;
 }
 
int main()
{
	int i;
	printf("Enter Number of Employees and then Number of periods\n");
	int numEmployees, numPeriods, input;
	scanf("%d %d", &numEmployees, &numPeriods);
	int** ratings = (int** ) malloc(sizeof(int*) * numEmployees);
	for(i=0; i<numEmployees; i++)
	{
		ratings[i] = (int* ) malloc(sizeof(int) * numPeriods);
	}
	inputEmployees(ratings, numEmployees, numPeriods);
	displayPerformance(ratings, numEmployees, numPeriods);
	int eoty = findEmployeeOfTheYear(ratings, numEmployees, numPeriods);
	int fhrp = findHighestRatedPeriod(ratings, numEmployees, numPeriods);
	int fwpe = findWorstPerformingEmployee(ratings, numEmployees, numPeriods);
	printf("Employee of the year is number : %d\n", eoty+1);
	printf("Highest Rated Period is: %d\n", fhrp+1);
	printf("Worst employee number is: %d", fwpe+1);
	for(i = 0; i < numEmployees; i++)
    {
        free(ratings[i]);
    }
    free(ratings);
}