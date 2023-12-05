#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Khai bao cau truc
struct Book {
  char ten[100];
  char tacgia[100];
  float gia;
};

// Nhap thong tin sach
void nhap(struct Book *s) {
  printf("Nhập tên sách: ");
  fgets(s->ten, sizeof(s->ten), stdin);
  s->ten[strcspn(s->ten, "\n")] = '\0'; 

  printf("Nhập tác giả: ");
  fgets(s->tacgia, sizeof(s->tacgia), stdin);
  s->tacgia[strcspn(s->tacgia, "\n")] = '\0'; 

  printf("Nhập giá sách: ");
  scanf("%f", &s->gia);

  if (s->gia < 0) {
    printf("Giá sách phải là số dương.\n");
    return;
  }
}

// Hien thi thong tin
void xuat(struct Book *s) {
  printf("Tên sách: %s\n", s->ten);
  printf("Tác giả: %s\n", s->tacgia);

  if (s->gia < 0) {
    printf("Giá sách phải là số dương.\n");
    return;
  }

  printf("Giá sách: %.2f\n", s->gia);
}

// Cap phat dong mang Book
struct Book *capphat(int n) {
  struct Book *arr = (struct Book *)malloc(n * sizeof(struct Book));
  if (arr == NULL) {
    printf("Không thể cấp phát đủ bộ nhớ.\n");
    return NULL;
  }
  return arr;
}

// Giai phong bo nho mang Book
void giaiphong(struct Book *arr) {
  free(arr);
}

int main() {
  // So luong sach
  int n;
  printf("Nhập số lượng sách: ");
  scanf("%d", &n);
  getchar(); 

  // Cap phat mang cho Book
  struct Book *arr = capphat(n);

  // Nhap thong tin sach
  for (int i = 0; i < n; i++) {
    nhap(&arr[i]);
  }

  // Hien thi thong tin sach
  for (int i = 0; i < n; i++) {
    xuat(&arr[i]);
  }

  // Giai phong bo nho
  giaiphong(arr);

  return 0;
}
