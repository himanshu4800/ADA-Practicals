#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100000;
    }
}
int main() {
    int n_values[] = {10, 50, 100, 500, 1000, 3000, 5000, 6000, 7000, 8000};
    int num_values = sizeof(n_values) / sizeof(n_values[0]);
    printf("n,TimeTaken(seconds)\n");

    for (int i = 0; i < num_values; i++) {
        int n = n_values[i];
        int *arr = (int *)malloc(n * sizeof(int));
        if (arr == NULL) {
            printf("Memory allocation failed for n = %d\n", n);
            continue;
        }
        generateRandomArray(arr, n);

        clock_t start = clock();
        for (int j = 0; j < 1000; j++) {
            int *temp = (int *)malloc(n * sizeof(int));
            for (int k = 0; k < n; k++) temp[k] = arr[k];

            quickSort(temp, 0, n - 1);

            free(temp);
        }
        clock_t end = clock();

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC / 1000.0;

        printf("%d,%.8f\n", n, time_taken);

        free(arr);
    }

    return 0;
}
