#include <stdio.h>

#define MAX 100

// C?u trúc ngày sinh
struct NgaySinh {
    int ngay;
    int thang;
    int nam;
};

// C?u trúc sinh viên
struct SinhVien {
    char maSV[20];
    char hoTen[50];
    struct NgaySinh ns;
    char diaChi[100];
    char dienThoai[15];
};

// Hàm nh?p 1 sinh viên
void nhapSinhVien(struct SinhVien *sv) {
    getchar(); // Xóa b? d?m

    printf("Nhap ma sinh vien: ");
    fgets(sv->maSV, 20, stdin);

    printf("Nhap ho va ten: ");
    fgets(sv->hoTen, 50, stdin);

    printf("Nhap ngay sinh (ngay thang nam): ");
    scanf("%d %d %d", &sv->ns.ngay, &sv->ns.thang, &sv->ns.nam);

    getchar(); // Xóa b? d?m

    printf("Nhap dia chi: ");
    fgets(sv->diaChi, 100, stdin);

    printf("Nhap so dien thoai: ");
    fgets(sv->dienThoai, 15, stdin);
}

// Hàm hi?n th? 1 sinh viên
void hienThiSinhVien(struct SinhVien sv) {
    printf("\n--- Thong tin sinh vien ---\n");
    printf("Ma SV      : %s", sv.maSV);
    printf("Ho ten     : %s", sv.hoTen);
    printf("Ngay sinh  : %02d/%02d/%04d\n", sv.ns.ngay, sv.ns.thang, sv.ns.nam);
    printf("Dia chi    : %s", sv.diaChi);
    printf("Dien thoai : %s\n", sv.dienThoai);
}

int main() {
    struct SinhVien ds[MAX];
    int n;

    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\n=== Nhap sinh vien %d ===\n", i + 1);
        nhapSinhVien(&ds[i]);
    }

    printf("\n======= DANH SACH SINH VIEN =======\n");
    for (int i = 0; i < n; i++) {
        hienThiSinhVien(ds[i]);
    }

    return 0;
}

