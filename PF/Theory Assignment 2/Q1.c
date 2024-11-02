#include <stdio.h>
int main()
{
	int inp, i, arr[5], thisinput;
	thisinput = 0;
	inp = 0;
	for(i=0; i<5; i++)
	{
		do
		{
			scanf("%d", &inp);
		}while(inp>=9999);
		arr[i] = inp;
		
	}
	for(i=0; i<5; i++)
	{
		printf("Element - %d: %d\n", i, arr[i]);
	}
	int secmin = 10000;
	int min = 9999;
	for(i=0; i<5; i++)
	{
		if(arr[i] < min)
        {
            secmin = min;
            min = arr[i];
        }
        else if(arr[i] < secmin)
        {
            secmin = arr[i];
        }
	}
	printf("Second smallest number: %d", secmin);
	
}
