#include <stdio.h>
#include <string.h>

#define MAX 100

struct Contact {
    char name[50];
    char phoneNumber[15];
    char email[50];
};

void addContact(struct Contact contacts[], int *n);
void displayContacts(struct Contact contacts[], int n);
void searchContact(struct Contact contacts[], int n);
void deleteContact(struct Contact contacts[], int *n);

int main() {
    struct Contact contacts[MAX];
    int n = 0;
    int choice;

    do {
        printf("\n========== MENU ==========\n");
        printf("1. Them lien he moi\n");
        printf("2. Hien thi tat ca lien he\n");
        printf("3. Tim kiem theo ten\n");
        printf("4. Xoa lien he theo ten\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addContact(contacts, &n);
                break;
            case 2:
                displayContacts(contacts, n);
                break;
            case 3:
                searchContact(contacts, n);
                break;
            case 4:
                deleteContact(contacts, &n);
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

void addContact(struct Contact contacts[], int *n) {
    if (*n >= MAX) {
        printf("Danh ba da day!\n");
        return;
    }

    printf("\n--- Them lien he moi ---\n");
    getchar(); 
    printf("Nhap ten: ");
    fgets(contacts[*n].name, 50, stdin);

    printf("Nhap so dien thoai: ");
    fgets(contacts[*n].phoneNumber, 15, stdin);

    printf("Nhap email: ");
    fgets(contacts[*n].email, 50, stdin);

    (*n)++;
    printf("Da them thanh cong!\n");
}

void displayContacts(struct Contact contacts[], int n) {
    if (n == 0) {
        printf("Chua co lien he nao!\n");
        return;
    }

    printf("\n=== Danh sach lien he ===\n");
    for (int i = 0; i < n; i++) {
        printf("Lien he %d:\n", i + 1);
        printf("Ten: %s", contacts[i].name);
        printf("SDT: %s", contacts[i].phoneNumber);
        printf("Email: %s\n", contacts[i].email);
    }
}

void searchContact(struct Contact contacts[], int n) {
    if (n == 0) {
        printf("Khong co du lieu de tim!\n");
        return;
    }

    char searchName[50];
    getchar(); 
    printf("Nhap ten can tim: ");
    fgets(searchName, 50, stdin);

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strncmp(contacts[i].name, searchName, strlen(searchName)-1) == 0) {
            printf("\nTim thay:\n");
            printf("Ten: %s", contacts[i].name);
            printf("SDT: %s", contacts[i].phoneNumber);
            printf("Email: %s\n", contacts[i].email);
            found = 1;
        }
    }

    if (!found) printf("Khong tim thay lien he!\n");
}

void deleteContact(struct Contact contacts[], int *n) {
    if (*n == 0) {
        printf("Khong co du lieu de xoa!\n");
        return;
    }

    char deleteName[50];
    getchar();
    printf("Nhap ten can xoa: ");
    fgets(deleteName, 50, stdin);

    int found = 0;
    for (int i = 0; i < *n; i++) {
        if (strncmp(contacts[i].name, deleteName, strlen(deleteName)-1) == 0) {
            found = 1;
            for (int j = i; j < *n - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*n)--;
            printf("Da xoa lien he thanh cong!\n");
            return;
        }
    }

    if (!found) printf("Khong tim thay lien he de xoa!\n");
}

