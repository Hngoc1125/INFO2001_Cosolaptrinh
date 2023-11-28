#include <stdio.h>

int main() {
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);

    // khai bao mang luu tru diem sinh vien
    float diem[n];

    // nhap diem cua sinh vien va tinh tong
    float tongDiem = 0;
    for (int i = 0; i < n; i++) {
        printf("Nhap diem cua sinh vien %d: ", i + 1);
        scanf("%f", &diem[i]);
        tongDiem += diem[i];
    }

    // tinh diem trung binh
    float diemTrungBinh = tongDiem / n;

    // in ra 
    printf("Diem trung binh cua lop la: %.2f\n", diemTrungBinh);

    return 0;
}