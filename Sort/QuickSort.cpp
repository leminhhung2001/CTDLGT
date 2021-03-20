#include<bits/stdc++.h>
using namespace std;

void quickSort(int a[], int left, int right) {
    if(left < right) {

        int k = (left + right) / 2;
        int t = a[k];
        int i = left, j = right;

        do {
            while(a[i] > t) i+= 1;
            while(a[j] < t) j-= 1;

            if(i <= j) {
                swap(a[i], a[j]);
                i += 1;
                j -= 1;
            }
        } while(i <= j);

        for(int i=0; i<10; i++) cout << a[i] << ' ';
        cout << endl;
        cout << "i = " << i << endl;
        cout << "j = " << j << endl;

        quickSort(a, left, j);
        quickSort(a, i, right);
    }
}

int main() {
    int a[] = {15, 25, 2, 10, -30, 8, 6, 10, 7, 1};
    int n = sizeof(a)/sizeof(int);
    quickSort(a, 0, n-1);
    // for(int i=0; i<n; i++) cout << a[i] << ' ';
    // cout << endl;
    
}