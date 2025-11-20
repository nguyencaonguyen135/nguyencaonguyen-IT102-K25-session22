#include <stdio.h>

#define MAX 100

struct Student {
    char name[50];
    int age;
    float grade;
};

void inputStudent(struct Student students[], int *n);
void displayStudents(struct Student students[], int n);
void averageGrade(struct Student students[], int n);

int main() {
    struct Student students[MAX];
    int n = 0;
    int choice;

    do {
        printf("\n----- MENU -----\n");
        printf("1. Nhap thong tin hoc sinh\n");
        printf("2. Hien thi thong tin hoc sinh\n");
        printf("3. Tinh diem trung binh cua tat ca hoc sinh\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                inputStudent(students, &n);
                break;
            case 2:
                displayStudents(students, n);
                break;
            case 3:
                averageGrade(students, n);
                break;
            case 0:
                printf("Thoat chuong trinh...\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }

    } while(choice != 0);

    return 0;
}

void inputStudent(struct Student students[], int *n) {
    printf("Nhap so luong hoc sinh: ");
    scanf("%d", n);

    for(int i = 0; i < *n; i++) {
        printf("\n--- Hoc sinh %d ---\n", i + 1);

        printf("Nhap ten: ");
        getchar(); 
        fgets(students[i].name, 50, stdin);

        printf("Nhap tuoi: ");
        scanf("%d", &students[i].age);

        printf("Nhap diem: ");
        scanf("%f", &students[i].grade);
    }
}

void displayStudents(struct Student students[], int n) {
    if(n == 0) {
        printf("Chua co du lieu!\n");
        return;
    }

    printf("\n=== Danh sach hoc sinh ===\n");
    for(int i = 0; i < n; i++) {
        printf("Hoc sinh %d:\n", i + 1);
        printf("Ten  : %s", students[i].name);
        printf("Tuoi : %d\n", students[i].age);
        printf("Diem : %.2f\n\n", students[i].grade);
    }
}

void averageGrade(struct Student students[], int n) {
    if(n == 0) {
        printf("Chua co du lieu!\n");
        return;
    }

    float sum = 0;
    for(int i = 0; i < n; i++) {
        sum += students[i].grade;
    }

    printf("Diem trung binh cua tat ca hoc sinh: %.2f\n", sum / n);
}

