#include<bits/stdc++.h>
using namespace std;


void input(int a[], int n) {
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
}

void vunDong(int a[], int k, int n) {
    //Những nút có con
    if(k <= n/2 - 1) {
        //Nút cha k sẽ quản lý 2 nút con của nó là 2k + 1 và 2k + 2
        int j = 2 * k + 1;
        //Thực hiện so sánh 2 nút con và lưu lại vị trí của nút con có giá trị lớn hơn
        if(j < n - 1 && a[j] > a[j+1]) {
            j = j + 1;
        }
        //So sánh và hoán đổi giá trị của nút con có giá trị max và nút cha
        if(a[k] > a[j]) {
            swap(a[k], a[j]);
            vunDong(a, j, n);
        }
    }
}

void taoDongDauTien(int a[], int n) {
    //chỉ vun đống cho những nút có con
    for(int k = n/2 - 1; k >= 0; k--) 
        vunDong(a, k, n);
}

void heapSort(int a[], int n) {
    taoDongDauTien(a, n);
    for(int i=n; i>=2; i--) {
        swap(a[0], a[i-1]);
        //Vun đống đồng thời loại bỏ đi nút cuối cùng vì nó đã max rồi
        vunDong(a, 0, i-1);
    }
}

void output(int a[], int n) {
    for(int i=0; i<n; i++){
        cout << a[i] << ' ';
    } 
    cout << endl;
}

int main() {
   int n;
   cout << "Nhap so phan tu n = "; cin >> n;
   int a[n];
   input(a, n);
   heapSort(a, n);
   cout << "====Day sau khi duoc sap xep tang dan====" << endl;
   output(a, n);
}