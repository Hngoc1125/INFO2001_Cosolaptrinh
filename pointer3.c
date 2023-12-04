#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Khai báo cấu trúc
struct Book {
  char ten[100];
  char tacgia[100];
  float gia;
};

// Nhập thông tin sách
void nhap(struct Book *s) {
  printf("Nhập tên sách: ");
  fgets(s->ten, sizeof(s->ten), stdin);
  s->ten[strcspn(s->ten, "\n")] = '\0'; // Xóa ký tự xuống dòng

  printf("Nhập tác giả: ");
  fgets(s->tacgia, sizeof(s->tacgia), stdin);
  s->tacgia[strcspn(s->tacgia, "\n")] = '\0'; // Xóa ký tự xuống dòng

  printf("Nhập giá sách: ");
  scanf("%f", &s->gia);

  if (s->gia < 0) {
    printf("Giá sách phải là số dương.\n");
    return;
  }
}

// Hiển thị thông tin
void xuat(struct Book *s) {
  printf("Tên sách: %s\n", s->ten);
  printf("Tác giả: %s\n", s->tacgia);

  if (s->gia < 0) {
    printf("Giá sách phải là số dương.\n");
    return;
  }

  printf("Giá sách: %.2f\n", s->gia);
}

// Cấp phát động mảng Book
struct Book *capphat(int n) {
  struct Book *arr = (struct Book *)malloc(n * sizeof(struct Book));
  if (arr == NULL) {
    printf("Không thể cấp phát đủ bộ nhớ.\n");
    return NULL;
  }
  return arr;
}

// Giải phóng bộ nhớ mảng Book
void giaiphong(struct Book *arr) {
  free(arr);
}

int main() {
  // Số lượng sách
  int n;
  printf("Nhập số lượng sách: ");
  scanf("%d", &n);
  getchar(); // Đọc ký tự xuống dòng sau khi nhập số lượng sách

  // Cấp phát mảng Book
  struct Book *arr = capphat(n);

  // Nhập thông tin sách
  for (int i = 0; i < n; i++) {
    nhap(&arr[i]);
  }

  // Hiển thị thông tin sách
  for (int i = 0; i < n; i++) {
    xuat(&arr[i]);
  }

  // Giải phóng bộ nhớ
  giaiphong(arr);

  return 0;
}