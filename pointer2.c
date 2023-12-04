#include <stdio.h>
#include <stdlib.h>

// Nhap gia tri cho mang
void nhap(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    printf("Nhập giá trị phần tử thứ %d: ", i + 1);
    scanf("%d", &arr[i]);
  }
}

//In gia tri cua mang
void in(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    printf("arr[%d] = %d\n", i, arr[i]);
  }
}

// Tim kiem phan tu trong 
int timkiem(int *arr, int n, int x) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == x) {
      return i;
    }
  }
  return -1;
}

int main() {
  // So luong phan tu cua mang
  int n;
  printf("Nhập số lượng phần tử của mảng: ");
  scanf("%d", &n);

  // Cap phat bo nho dong
  int *arr = (int *)calloc(n, sizeof(int));

  // Kiem tra loi cap phat bo nho
  if (arr == NULL) {
    printf("Không thể cấp phát đủ bộ nhớ.\n");
    return 1;
  }

  // Nhap gia tri cho mang
  nhap(arr, n);

  // In gia tri
  in(arr, n);

  // Tim kiem phan tu trong mang
  int x;
  printf("Nhập giá trị cần tìm kiếm: ");
  scanf("%d", &x);

  // In ra vi tri phan tu can tim
  if (timkiem(arr, n, x) == -1) {
    printf("Không tìm thấy phần tử %d trong mảng.\n", x);
  } else {
    printf("Tìm thấy phần tử %d tại vị trí %d.\n", x, timkiem(arr, n, x));
  }

  // Giai phong bo nho da cap phat
  free(arr);

  return 0;
}
