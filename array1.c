//sap xep mang
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//bubble_sort
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
//selection_sort
void selection_sort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

int main() {
    int n = 10000;  
    int arr[n];

    
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }

    // Bubble Sort
    clock_t start_bubble = clock();
    bubble_sort(arr, n);
    clock_t end_bubble = clock();
    double time_bubble = (double)(end_bubble - start_bubble) / CLOCKS_PER_SEC;

    // Selection Sort
    clock_t start_selection = clock();
    selection_sort(arr, n);
    clock_t end_selection = clock();
    double time_selection = (double)(end_selection - start_selection) / CLOCKS_PER_SEC;

    
    printf("Bubble Sort: %.6f seconds\n", time_bubble);
    printf("Selection Sort: %.6f seconds\n", time_selection);

    return 0;
}
