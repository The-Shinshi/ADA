#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void selectionSort(int arr[], int n)
{
	int i, j, minIndex, temp;
	for (i = 0; i < n - 1; i++) {
		minIndex = i;
		for (j = i + 1; j < n; j++) {
			if (arr[j] < arr[minIndex])
				{
					minIndex = j;
				}
		}

		temp = arr[minIndex];
		arr[minIndex] = arr[i];
		arr[i] = temp;
	}
}

int generateRandomNumber() {
	return rand() % 1000;
}

int main() {
	int n = 6000;
	int* arr = (int*)malloc(n * sizeof(int));
	srand(time(NULL));
	printf("Random numbers for n = %d:\n", n); 
	for (int i = 0; i < n; i++) {
		arr[i] = generateRandomNumber();
		printf("%d ", arr[i]);
	}
	printf("\n");
	clock_t start = clock();
	selectionSort(arr, n);
	clock_t end = clock();
	double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("\nTime taken to sort for n = %d: %lf seconds\n\n", n, time_taken);
	printf("Sorted numbers for n = %d:\n", n); 
	for(int i = 0; i < n; i++) {
	printf("%d ", arr[i]);
}
printf("\n\n");
return 0;
}
