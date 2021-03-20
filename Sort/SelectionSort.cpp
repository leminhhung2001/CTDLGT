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
void selectionSort(int a[], int n) {
    for(int i=0; i<n-1; i++) {
        //Gán lại vị trí ban đầu của i cho m
        int m = i;
        for(int j=i+1; j<n; j++) {
            if(a[j] < a[m]) {
                m = j;
            }
        }
        if(m != i) {
            int tg = a[i];
            a[i] = a[m];
            a[m] = tg;
        }
    }
}

int main() {
   int n;
   cout << "Nhap so phan tu n = "; cin >> n;
   int a[n];
   input(a, n);
   selectionSort(a, n);
   cout << "====Day sau khi duoc sap xep tang dan====" << endl;
   output(a, n);
    
}