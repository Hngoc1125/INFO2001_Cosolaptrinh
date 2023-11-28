// Quan ly danh sach sinh vien
#include<stdio.h>
#include<string.h>

struct Student{
    char id[9];
    char fullname[30];
    int age;
    float grade;
};

void inputStudents(struct Student students[], int n){
    int i;
    for(i = 0; i < n; i++){
        printf("Nhap thong tin sinh vien thu %d\n", i+1);
        printf("Ma sinh vien: ");
        fgets(students[i].id, 9, stdin);
        printf("Ho ten sinh vien: ");
        fgets(students[i].fullname, 30, stdin);
        printf("Tuoi sinh vien: ");
        scanf("%d", &students[i].age);
        printf("Diem GPA: ");
        scanf("%f", &students[i].grade);
        getchar(); 
    }
}

void displayStudents(struct Student students[], int n){
    int i;
    for(i = 0; i < n; i++){
        printf("Thong tin sinh vien thu %d\n", i+1);
        printf("Ma sinh vien: %s", students[i].id);
        printf("Ho ten sinh vien: %s", students[i].fullname);
        printf("Tuoi sinh vien: %d\n", students[i].age);
        printf("Diem GPA: %.2f\n", students[i].grade);
    }
}

int main(){
    struct Student students[41];
    int n = 41;
    
    inputStudents(students, n);
    
    printf("\nDanh sach sinh vien:\n");
    displayStudents(students, n);
    
    
    int studentIndex;
    printf("\nNhap so thu tu sinh vien can sua: ");
    scanf("%d", &studentIndex);
    getchar(); 
    
    return 0;
}
