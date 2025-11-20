#include <stdio.h>
#include <string.h>

#define MAX 100

struct NgayDat {
    int ngay;
    int thang;
    int nam;
};

struct DonHang {
    char maDH[20];
    char tenKH[50];
    struct NgayDat ngayDat;
    float tongTien;
    char trangThai[20]; 
};

void nhapDonHang(struct DonHang *dh) {
    getchar();

    printf("Nhap ma don hang: ");
    fgets(dh->maDH, 20, stdin);

    printf("Nhap ten khach hang: ");
    fgets(dh->tenKH, 50, stdin);

    printf("Nhap ngay dat (dd mm yyyy): ");
    scanf("%d %d %d", &dh->ngayDat.ngay, &dh->ngayDat.thang, &dh->ngayDat.nam);

    printf("Nhap tong tien: ");
    scanf("%f", &dh->tongTien);
    getchar();

    printf("Nhap trang thai (Dang xu ly / Da giao / Huy): ");
    fgets(dh->trangThai, 20, stdin);
}

void hienThiDonHang(struct DonHang dh) {
    printf("\nMa DH     : %s", dh.maDH);
    printf("Ten KH    : %s", dh.tenKH);
    printf("Ngay dat  : %02d/%02d/%04d\n", dh.ngayDat.ngay, dh.ngayDat.thang, dh.ngayDat.nam);
    printf("Tong tien : %.2f\n", dh.tongTien);
    printf("Trang thai: %s\n", dh.trangThai);
}

void hienThiTatCa(struct DonHang ds[], int n) {
    if (n == 0) {
        printf("Khong co don hang!\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        printf("\n---- Don hang %d ----\n", i + 1);
        hienThiDonHang(ds[i]);
    }
}

void capNhatTrangThai(struct DonHang ds[], int n) {
    char ma[20];
    getchar();
    printf("Nhap ma don hang can cap nhat: ");
    fgets(ma, 20, stdin);

    for (int i = 0; i < n; i++) {
        if (strncmp(ds[i].maDH, ma, strlen(ma) - 1) == 0) {
            printf("Nhap trang thai moi: ");
            fgets(ds[i].trangThai, 20, stdin);

            printf("Cap nhat thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay don hang!\n");
}

void xoaDonHang(struct DonHang ds[], int *n) {
    char ma[20];
    getchar();

    printf("Nhap ma don hang can xoa: ");
    fgets(ma, 20, stdin);

    for (int i = 0; i < *n; i++) {
        if (strncmp(ds[i].maDH, ma, strlen(ma) - 1) == 0) {
            for (int j = i; j < *n - 1; j++) {
                ds[j] = ds[j + 1];
            }
            (*n)--;
            printf("Xoa thanh cong!\n");
            return;
        }
    }

    printf("Khong tim thay don hang!\n");
}

void sapXepTheoTongTien(struct DonHang ds[], int n) {
    int chon;
    printf("1. Tang dan\n");
    printf("2. Giam dan\n");
    printf("Chon kieu sap xep: ");
    scanf("%d", &chon);

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int swap = 0;
            if (chon == 1 && ds[i].tongTien > ds[j].tongTien)
                swap = 1;
            if (chon == 2 && ds[i].tongTien < ds[j].tongTien)
                swap = 1;

            if (swap) {
                struct DonHang temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
    printf("Sap xep thanh cong!\n");
}

void timKiemTheoMa(struct DonHang ds[], int n) {
    char ma[20];
    getchar();

    printf("Nhap ma don hang can tim: ");
    fgets(ma, 20, stdin);

    for (int i = 0; i < n; i++) {
        if (strncmp(ds[i].maDH, ma, strlen(ma) - 1) == 0) {
            printf("Tim thay don hang:\n");
            hienThiDonHang(ds[i]);
            return;
        }
    }

    printf("Khong tim thay don hang!\n");
}

int main() {
    struct DonHang ds[MAX];
    int n = 0;
    int choice;

    do {
        printf("\n===== MENU QUAN LY DON HANG =====\n");
        printf("1. Nhap don hang moi\n");
        printf("2. Hien thi tat ca don hang\n");
        printf("3. Cap nhat trang thai don hang\n");
        printf("4. Xoa don hang theo ma\n");
        printf("5. Sap xep don hang theo tong tien\n");
        printf("6. Tim kiem don hang theo ma\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (n < MAX) {
                    nhapDonHang(&ds[n]);
                    n++;
                } else {
                    printf("Danh sach day!\n");
                }
                break;
            case 2:
                hienThiTatCa(ds, n);
                break;
            case 3:
                capNhatTrangThai(ds, n);
                break;
            case 4:
                xoaDonHang(ds, &n);
                break;
            case 5:
                sapXepTheoTongTien(ds, n);
                break;
            case 6:
                timKiemTheoMa(ds, n);
                break;
            case 0:
                printf("Thoat chuong trinh...\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }

    } while (choice != 0);

    return 0;
}

