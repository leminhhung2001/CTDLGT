#include<bits/stdc++.h>
using namespace std;

void Merge(int a[], int n, int b[], int m, int c[]) {
    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if(a[i] < b[j]) {
            c[k] = a[i];
            k++;
            i++;
        }
        else {
            c[k] = b[j];
            k++;
            j++;
        }
    }
    //Gán các phần tử còn lại vào mảng c
    while (i < n)
    {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j < m)
    {
        c[k] = b[j];
        k++;
        j++;
    }
}

int main() {
   int a[] = {12, 25, 28};
   int b[] = {3 , 9 , 15, 32, 39};
   int n = sizeof(a)/sizeof(int);
   int m = sizeof(a)/sizeof(int);
   int c[n+m];
   Merge(a, n, b, m, c);
   for(int i=0; i<n+m; i++) cout << c[i] << ' ';
   cout << endl;

}