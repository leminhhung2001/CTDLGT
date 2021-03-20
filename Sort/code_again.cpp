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
void quickSort(int a[], int left, int right) {
    if(left < right) {
        int k = (left + right) / 2;
        int t = a[k];
        int i = left, j = right;
        do {
            //Lặp đến khi nào mà nó lớn hơn bằng t
            while(a[i] < t) i++;

            //Lặp đến khi nào mà nó bé hơn bằng t
            while(a[j] > t) j--;

            //Thực hiện việc swap a[i] và a[j] nếu 2 phần tử này thõa mãn điều kiện
            if(i <= j) {
                swap(a[i], a[j]);
                i++;
                j--;
            }
        }while(i <= j);
        quickSort(a, left, j);
        quickSort(a, i, right);
    }

}

int main() {
   int n;
   cout << "Nhap so phan tu n = "; cin >> n;
   int a[n];
   input(a, n);
   quickSort(a, 0, n-1);
   cout << "====Day sau khi duoc sap xep tang dan====" << endl;
   output(a, n);
    
}