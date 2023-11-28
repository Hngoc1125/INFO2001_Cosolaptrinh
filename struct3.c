//struct.03
#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

struct Employee {
    int id;
    char name[50];
    char position[50];
    float salary;
};

struct EmployeeList {
    struct Employee employees[MAX_EMPLOYEES];
    int count;
};

void addEmployee(struct EmployeeList *list, int id, const char *name, const char *position, float salary) {
    if (list->count >= MAX_EMPLOYEES) {
        printf("Danh sach nhan vien da day. Khong the them nua.\n");
        return;
    }

    struct Employee *employee = &list->employees[list->count];
    employee->id = id;
    strcpy(employee->name, name);
    strcpy(employee->position, position);
    employee->salary = salary;

    list->count++;

    printf("Them nhan vien thanh cong.\n");
}

void removeEmployee(struct EmployeeList *list, int id) {
    int foundIndex = -1;

    for (int i = 0; i < list->count; i++) {
        if (list->employees[i].id == id) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        printf("Khong tim thay nhan vien co ma so %d.\n", id);
        return;
    }

    for (int i = foundIndex; i < list->count - 1; i++) {
        list->employees[i] = list->employees[i + 1];
    }

    list->count--;

    printf("Xoa nhan vien thanh cong.\n");
}

void displayEmployees(const struct EmployeeList *list) {
    if (list->count == 0) {
        printf("Danh sach nhan vien rong.\n");
        return;
    }

    printf("Danh sach nhan vien:\n");
    for (int i = 0; i < list->count; i++) {
        const struct Employee *employee = &list->employees[i];
        printf("Ma so: %d\n", employee->id);
        printf("Ten: %s\n", employee->name);
        printf("Chuc vu: %s\n", employee->position);
        printf("Luong: %.2f\n", employee->salary);
        printf("-----------------------\n");
    }
}

int compareEmployees(const void *a, const void *b) {
    const struct Employee *employeeA = (const struct Employee *)a;
    const struct Employee *employeeB = (const struct Employee *)b;

    return employeeA->id - employeeB->id;
}

void sortEmployees(struct EmployeeList *list) {
    qsort(list->employees, list->count, sizeof(struct Employee), compareEmployees);
    printf("Sap xep nhan vien thanh cong.\n");
}

int main() {
    struct EmployeeList employeeList;
    employeeList.count = 0;

    int choice;
    do {
        printf("\nQUAN LY NHAN SU\n");
        printf("1. Them nhan vien\n");
        printf("2. Xoa nhan vien\n");
        printf("3. Hien thi danh sach nhan vien\n");
        printf("4. Sap xep nhan vien\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            int id;
            char name[50];
            char position[50];
            float salary;

            printf("Nhap ma nhan vien: ");
            scanf("%d", &id);
            printf("Nhap ten nhan vien: ");
            scanf("%s", &name);
            printf("Nhap chuc vu: ");
            scanf("%s", &position);
            
            printf("Nhap luong: ");
            scanf("%f", &salary);

            addEmployee(&employeeList, id, name, position, salary);
            break;
        }
        case 2: {
            int id;
            printf("Nhap ma nhan vien can xoa: ");
            scanf("%d", &id);
            removeEmployee(&employeeList, id);
            break;
        }
        case 3:
            displayEmployees(&employeeList);
            break;
        case 4:
            sortEmployees(&employeeList);
            break;
               case 0:
            printf("Ket thuc chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le. Vui long nhap lai.\n");
            break;
        }
    } while (choice != 0);

    return 0;
}