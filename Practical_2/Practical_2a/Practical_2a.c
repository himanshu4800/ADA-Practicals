#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++){ 
        L[i] = arr[left + i];}
    for (int j = 0; j < n2; j++){
         R[j] = arr[mid + 1 + j];}

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) {
        arr[k++] = L[i++];}
    while (j < n2){ 
        arr[k++] = R[j++];}

    free(L);
    free(R);
}
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
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

        clock_t start = clock();
        for (int j = 0; j < 1000; j++) {
            generateRandomArray(arr, n);
            mergeSort(arr, 0, n - 1);
        }


        clock_t end = clock();

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC/1000.0;
        printf("%d,%.8f\n", n, time_taken);

        free(arr);
    }

    return 0;
}
