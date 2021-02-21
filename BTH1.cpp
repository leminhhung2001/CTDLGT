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
    Node *next;
};
//Định nghĩa con trỏ kiểu Node
typedef Node *TRO;

//Khai bao cac ham can thiet

//Ham khoi tao danh sach rong
void Initialize(TRO &L) {
    L = NULL;
}


//Ham kiem tra danh sach rong
int Empty(TRO L) {
    return L == NULL;
}


//Nhap thong tin mot sinh vien
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


//Nhap ds sinh vien
void NhapDS(TRO &L) {
    Initialize(L);
    SINHVIEN X;
    TRO Q, P;
    int i=1;
    do {
        cout << "\tNhap sv thu: " << i << endl;
        NhapSV(X);
        if(X.MASV.compare("***") == 0) {
            return;
        }

        P = new (Node);
        P->infor = X;
        P->next = NULL;
        if(L == NULL) L = P;//Gán Node
        else Q->next = P;//Gán địa chỉ

        Q = P;
        i++;
    }while(i);
}

//Hien thi danh sach sinh vien
void HienThiDS(TRO L) {
    if(L == NULL) {
        cout << "Danh sach rong" << endl;
        return;
    }

    cout << setw(5) << "STT" << setw(10) << "Ma SV" << setw(25) << "Ho va ten" << setw(10) << "Nam sinh" << setw(10) << "Diem TK" << endl;
    TRO Q = L;
    int i = 0;
    while (Q != NULL)
    {
        SINHVIEN X = Q->infor;
        cout << setw(5) << i+1 << setw(10) << X.MASV << setw(17) << X.HODEM << setw(8) << X.TEN  << setw(10) << X.NAMSINH << setw(10) << X.DIEMTK << endl;
        Q = Q->next;
    }
    
}

int main(){
    TRO L;
    
    NhapDS(L);
    HienThiDS(L);
}


