#include<bits/stdc++.h>
using namespace std;

void input(int a[], int n) {
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
}

void bubbleSort(int a[], int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=n-1; j>i; j--) {
            if(a[j] < a[j-1]) {
                int tg = a[j];
                a[j] = a[j-1];
                a[j-1] = tg;
            }
        }
    }
}

void output(int a[], int n) {
    for(int i=0; i<n; i++){
        cout << a[i] << ' ';
    } 
    cout << endl;
}
int main() {
    //int a[] = {9 11 3 7 14 8 6 45};
   // int n = sizeof(a)/sizeof(int);
   int n;
   cout << "Nhap so phan tu n = "; cin >> n;
   int a[n];
   input(a, n);
   bubbleSort(a, n);
   cout << "====Day sau khi duoc sap xep tang dan====" << endl;
   output(a, n);
    
}