#include<bits/stdc++.h>
using namespace std;
// int main() {
//     int a[] = {10, 30, 15, 70, 17, -26, 80};
//     int n = 7;
//     for(int i=1; i<n; i++) {
//         int t = a[i];
//         int j = i - 1;
//         while(j >= 0 && t > a[j]) {
//             a[j+1] = a[j];
//             j = j - 1;
//         }
//         a[j+1] = t;  
//     }
// }

int main() {
    int a[] = {15, 25, 2, 10, -30, 8, 6, 10, 7, 1};
    for(int i=0; i<9; i++){
        for(int j=9; j>i; j--) {
            if(a[j] > a[j-1]){
                swap(a[j], a[j-1]);
            }
        }

        for(int i=0; i<10; i++) cout << a[i] << " ";
        cout << endl;
    }
        
    

}















// cout << "Lan thu: " << i << endl;
//         for(int i=0; i<n; i++) cout << a[i] << " ";
//         cout << endl;

// for(int i=0; i<n-1; i++) {
    //     for(int j=n-1; j>i; j--) {
    //         if(a[j] > a[j-1]) {
    //             swap(a[j], a[j-1]);
    //         }
    //     }
    //     cout << "Lan thu: " << i << endl;
    //     for(int i=0; i<n; i++) cout << a[i] << " ";
    //     cout << endl;
    // }