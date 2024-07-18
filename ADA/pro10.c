#include <stdio.h>
#include <stdlib.h>
#include <time.h>
swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

partition(int arr[], int low, int high) {
	int pivot = arr[high];
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++){
		if (arr[j] < pivot) {
		i++;
		swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high){ 
	if (low < high) {
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}
generateRandomNumber() {
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
	quickSort(arr, 0, n - 1);
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
