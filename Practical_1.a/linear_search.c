#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100000;
    }
}

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
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
        int target = arr[n - 1];  

        clock_t start = clock();
        for (int j = 0; j < 1000; j++) {
            linearSearch(arr, n, target);
        }
        clock_t end = clock();

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC / 1000.0;

    
        printf("%d,%.8f\n", n, time_taken);

        free(arr);
    }

    return 0;
}


