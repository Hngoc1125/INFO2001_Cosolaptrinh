//Sap xep va tim kiem sinh vien
#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student {
    char id[10];
    char fullname[41];
    float grade;
};

void nhapSinhVien(struct Student *s) {
    printf("Nhap ma so sinh vien: ");
    fgets(s->id, sizeof(s->id), stdin);
    s->id[strcspn(s->id, "\n")] = '\0';

    printf("Nhap ho ten sinh vien: ");
    fgets(s->fullname, sizeof(s->fullname), stdin);
    s->fullname[strcspn(s->fullname, "\n")] = '\0';

    printf("Nhap diem trung binh sinh vien: ");
    scanf("%f", &s->grade);
    getchar(); // Xóa ký tự xuống dòng
}

void xuatSinhVien(struct Student *s) {
    printf("Ma so sinh vien: %s\n", s->id);
    printf("Ho ten sinh vien: %s\n", s->fullname);
    printf("Diem trung binh sinh vien: %.2f\n", s->grade);
}

void sapXepTen(struct Student *ds, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(ds[j].fullname, ds[j + 1].fullname) > 0) {
                struct Student temp = ds[j];
                ds[j] = ds[j + 1];
                ds[j + 1] = temp;
            }
        }
    }
}

void sapXepDiem(struct Student *ds, int n) {
    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (ds[j].grade < ds[min].grade) {
                min = j;
            }
        }
        struct Student temp = ds[i];
        ds[i] = ds[min];
        ds[min] = temp;
    }
}

int timKiemTen(struct Student *ds, int n, char *name) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int cmp = strcmp(ds[mid].fullname, name);
        if (cmp == 0) {
            return mid;
        } else if (cmp < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int timKiemID(struct Student *ds, int n, char *id) {
    for (int i = 0; i < n; i++) {
        if (strcmp(ds[i].id, id) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    struct Student danhSach[MAX_STUDENTS];
    int soLuongSinhVien = 0;

    printf("Nhap so luong sinh vien: ");
    scanf("%d", &soLuongSinhVien);
    getchar(); // Xóa ký tự xuống dòng

    if (soLuongSinhVien > MAX_STUDENTS) {
        printf("Vuot qua gioi han so luong sinh vien.\n");
        return 1;
    }

    for (int i = 0; i < soLuongSinhVien; i++) {
        printf("Nhap thong tin sinh vien thu %d:\n", i + 1);
        nhapSinhVien(&danhSach[i]);
    }

    return 0;
}
