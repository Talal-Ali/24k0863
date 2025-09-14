#include <stdio.h> 
#define MAX_SIZE 5 
int* getMinMax(int *array, const int size); 
int main()  { 
int array[MAX_SIZE] = {1, -2, 3, -1, 9}; 
int *resultArr =getMinMax(array,  MAX_SIZE); 
printf("Min value in array: %d\n", resultArr[0]); 
printf("Max value in array: %d\n", resultArr[1]); 
free(resultArr); 
return 0;} 
int* getMinMax(int *numbers, const int size) { 
    int *temp = (int*) malloc(size*sizeof(int));
    int min=numbers[0];
    int max = numbers[0];
    for (int i = 0; i < size; i++)
    {
        if (numbers[i]<min)
        {
            min = numbers[i];
        }
        if (numbers[i]>max)
        {
            max = numbers[i];
        }
    }
    
    temp[0] = min;
    temp[1] = max;
    numbers = temp;
    return temp;
}