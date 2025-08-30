#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100000;
    }
}
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}

int main() {
    int n_values[] = {10, 50, 100, 500, 1000, 2000, 3000, 4000};
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
            selectionSort(arr, n);
        }
        clock_t end = clock();

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC / 1000.0;

        printf("%d,%.8f\n", n, time_taken);

        free(arr);
    }

    return 0;
}
