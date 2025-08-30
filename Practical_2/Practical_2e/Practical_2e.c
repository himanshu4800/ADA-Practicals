#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100000;
    }
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
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
            bubbleSort(arr, n);
        }
        clock_t end = clock();

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC / 1000.0;

        printf("%d,%.8f\n", n, time_taken);

        free(arr);
    }

    return 0;
}
