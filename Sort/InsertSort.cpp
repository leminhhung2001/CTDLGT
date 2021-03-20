#include<bits/stdc++.h>
using namespace std;


void input(int a[], int n) {
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
}


void output(int a[], int n) {
    for(int i=0; i<n; i++){
        cout << a[i] << ' ';
    } 
    cout << endl;
}
void insertSort(int a[], int n) {
    for(int i=1; i<n; i++) {
        int t = a[i];
        int j = i - 1;
        //Lấy t đi so sánh với từng phần tử bên dãy đích, nếu TMĐK thì đẩy phần tử của dãy đích sang bên phải
        //1 VT
        while (j >= 0 && t < a[j])
        {
            a[j+1] = a[j];
            j -= 1;
        }
        a[j+1] = t;
    }
}

int main() {
   int n;
   cout << "Nhap so phan tu n = "; cin >> n;
   int a[n];
   input(a, n);
   insertSort(a, n);
   cout << "====Day sau khi duoc sap xep tang dan====" << endl;
   output(a, n);
    
}