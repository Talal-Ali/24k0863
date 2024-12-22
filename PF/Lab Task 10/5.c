#include<stdio.h>
void bubblesort(int arr[], int len) {
    if (len == 1)
        return;

	int i, temp;
    for (i = 0; i < len - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }

    bubblesort(arr, len - 1);
}
int main()
{
	int i;
	int sample[] = {64, 72, 1, 14, 13};
	bubblesort(sample, sizeof(sample)/sizeof(sample[0]));
	for(i=0; i<5; i++)
	{
		printf("%d ", sample[i]);
	}
}