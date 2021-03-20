#include<bits/stdc++.h>
using namespace std;

int timKiemTuanTu(int a[], int n, int k) {
    for(int i=0; i<n; i++) {
        if(a[i] == k) return i;
    }
    return -1;
}

int timKiemNhiPhan(int a[], int l, int r, int k) {
    if(l <= r) {
        int mid = (l + r) / 2;
        if(a[mid] == k) {
            return mid;
        }
        else if(a[mid] > k) {
            return timKiemNhiPhan(a, l, mid-1, k);
        }
        else
            return timKiemNhiPhan(a, mid+1, r, k);
    }
    //Không tìm thấy return -1
    return -1;
}

void hienThiMang(int a[], int n) {
    for(int i=0; i<n; i++) cout << a[i] << " ";
    cout << endl;
}
void sapMangGiamDan(int a[], int n) {
    for(int i=0; i<n-1; i++) {
        for(int j = n-1; j>i; j--) {
            if(a[j] > a[j-1]) {
                int tg = a[j];
                a[j] = a[j-1];
                a[j-1] = tg;
            }
        }
    }
}

int main() {
    int n, k;
    cout << "Nhap so phan tu cua mang n = "; cin >> n;
    int a[n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    cout << "=============MANG SAU KHI NHAP===============" << endl;
    hienThiMang(a, n);
    cout << "Mang sau khi da sap xep giam dan" << endl;
    sapMangGiamDan(a, n);
    hienThiMang(a, n);

    cout << "Nhap phan tu can tim kiem k =  "; cin >> k;
    int index = timKiemTuanTu(a, n, k);
    if(index == -1) 
        cout << "Khong co so " << k << " trong mang de tim kiem" << endl;
    else
        cout << "So " << k << " o vi tri thu " << index << " trong mang" << endl;


    int indexx = timKiemNhiPhan(a, 0, n-1, k);
    if(indexx == -1) 
        cout << "Khong co so " << k << " trong mang de tim kiem" << endl;
    else
        cout << "So " << k << " o vi tri thu " << indexx << " trong mang" << endl;
    

}