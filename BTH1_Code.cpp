#include<bits/stdc++.h>
using namespace std;

struct SINHVIEN
{
    string MASV;
    string HODEM;
    string TEN;
    int NAMSINH;
    float DIEMTK;
};

struct Node 
{
    SINHVIEN infor;
    Node *next; //Khai báo con trỏ kiểu struct
};

typedef Node *TRO;

//Khai bao cac ham

//Ham khoi tao
void Initialize(TRO &L) {
    L = NULL;
}

//Ham check ds rong
int Empty(TRO L) {
    return L == NULL;
}

//Ham khoi tao mot sinh vien
void NhapSV(SINHVIEN &sv) {
    cout << "Nhap ma sv: "; fflush(stdin); getline(cin ,sv.MASV);
    if(sv.MASV.compare("***") == 0) {
        return;
    }
    cout << "Ho dem: "; fflush(stdin); getline(cin, sv.HODEM);
    cout << "Ten: "; fflush(stdin); getline(cin, sv.TEN);
    cout << "Nam sinh:"; cin >> sv.NAMSINH;
    cout << "Diem TK: "; cin >> sv.DIEMTK;
    cin.ignore();
}

//Ham khoi tao ds sinh vien
void NhapDsSV(TRO &L) {
    Initialize(L);
    SINHVIEN X;
    TRO P, Q;
    int i=1;
    do{
        cout << "\tNhap SV: " << i++ << endl;
        NhapSV(X);
        if(X.MASV.compare("***") == 0) {
            return;
        }
        P = new (Node);
        P->infor = X;
        P->next = NULL;
        if(L == NULL) L = P;
        else Q->next = P;

        Q = P;
    }while(1);
}

void HienThiDsSV(TRO L) {
    if(L == NULL) {
        cout << "Danh sach rong" << endl;
        return;
    }
    cout << setw(5) << "STT" << setw(10) << "Ma SV" << setw(25) << "Ho va ten" << setw(10) << "Nam sinh" << setw(10) << "Diem TK" << endl;
    TRO Q = L;
    int i = 1;
    while (Q != NULL)
    {
        SINHVIEN X = Q->infor;
        cout << setw(5) << i++ << setw(10) << X.MASV << setw(17) << X.HODEM << setw(8) << X.TEN  << setw(10) << X.NAMSINH << setw(10) << X.DIEMTK << endl;
        Q = Q->next;
    }
    
}

int main() {
    TRO L;
    NhapDsSV(L);
    HienThiDsSV(L);

}

