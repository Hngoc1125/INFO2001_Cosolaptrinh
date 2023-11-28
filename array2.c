
#include <stdio.h>
#include <time.h>

// Linear Search
int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;  
        }
    }
    return -1;  
}

// Binary Search
int binarySearch(int arr[], int low, int high, int x) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) {
            return mid;  
        }

        if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;  
}

int main() {
    int arr[10];
    int i, searchValue, n = 10;

    
    printf("Nhap gia tri cho phan tu trong mang:\n");
    for (i = 0; i < n; i++) {
        printf("Nhap gia tri cho phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nMang vua nhap:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nNhap gia tri can tim: ");
    scanf("%d", &searchValue);
    int linearSearchResult = linearSearch(arr, n, searchValue);
    if (linearSearchResult != -1) {
        printf("Tim thay tai %d \n", linearSearchResult);
    } else {
        printf("Khong tim thay gia tri.\n");
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("\nMang sau khi sap xep:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nNhap gia tri can tim : ");
    scanf("%d", &searchValue);
    int binarySearchResult = binarySearch(arr, 0, n - 1, searchValue);
    if (binarySearchResult != -1) {
        printf("Tim thay tai %d \n", binarySearchResult);
    } else {
        printf("Khong tim thay gia tri.\n");
    }

    return 0;
}
