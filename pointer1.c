#include <stdio.h>
#include <stdlib.h>

int main() {
    // Khai bao mang 
  int arr[5];
  // Khai bao con tro
  int *ptr = arr;

  // Nhap gia tri cho mang
  for (int i = 0; i < 5; i++) {
    printf("Nhập giá trị phần tử thứ %d: ", i + 1);
    scanf("%d", &arr[i]);
  }

  // In gia tri
  printf("Giá trị của mảng: \n");
  for (int i = 0; i < 5; i++) {
    printf("arr[%d] = %d\n", i, arr[i]);
  }

  // Tim kiem phan tu
  int x;
  printf("Nhập giá trị cần tìm kiếm: ");
  scanf("%d", &x);

  for (int i = 0; i < 5; i++) {
    if (arr[i] == x) {
      printf("Tìm thấy phần tử %d tại vị trí %d\n", x, i);
      break;
    }
  }

  return 0;
}

