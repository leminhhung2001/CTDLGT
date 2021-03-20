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


//Xac dinh chieu dai ds
int Length(TRO L) {
    TRO Q = L;
    int n = 0;
    while (Q != NULL)
    {   
        Q = Q->next;
        n++;
    }
    return n;
}


//Xoa phan tu dau tien
void XoaSVDauTien(TRO &L) {
    if(L != NULL) {
        TRO Q = L;
        L = L->next;
        delete Q;
        cout << "Danh sach sau khi xoa SV" << endl;
        HienThiDsSV(L);
        return;
    }
    cout << "Danh sach rong, khong the xoa sinh vien" << endl;
}
//Ham tim kiem sinh vien theo MSV
TRO SearchByMSV(TRO L, string Masv) {
    TRO Q = L;
    while(Q != NULL && Q->infor.MASV.compare(Masv) != 0) {
        Q = Q->next;
    }
    return Q;
}


//Ham xoa sinh vien theo MSV
void Remove(TRO &L, TRO T) {
    TRO Q;
    if(L == T) {
        L = T->next;
    }
    else {
        Q = L; //Khi gán như này thì Q và L sẽ dùng chung địa chỉ
        while(Q->next != T) {
            Q = Q->next;
        }
        Q->next = T->next;
    }
    delete T;
}

//Ham xoa sinh vien co ma sv8089
void Xoa_sv8089(TRO &L) {
    //Tim sv8089 trong ds
    TRO Q = SearchByMSV(L, "sv8089");
    if(Q == NULL) {
        cout << "\tKhong co sinh vien ma sv8089 trong danh sach" << endl;
    }
    else {
        Remove(L, Q);
        cout << "\tDanh sach sau khi xoa sv8089" << endl;
        HienThiDsSV(L);
    }
}


//Ham bo sung sinh vien vao dau danh sach
void AddFirstStudent(TRO &L, SINHVIEN T) {
    TRO P;
    P = new (Node);
    P->infor = T;
    P->next = L;
    L = P;
}

void Insert(TRO &L, TRO Q, SINHVIEN X) {
    TRO P = new (Node);
    P->infor = X;
    P->next = Q->next;
    Q->next = P;//Day lui thằng Q lai va gan next cua Q bang P de cho P co the đứng sau Q(la index = 3 đấy hihih)
}

//Ham them sinh vien vao vi tri bat ki
void BoSung(TRO &L) {
    SINHVIEN X;
    cout << "\tNhap thong tin sinh vien can them" << endl;
    NhapSV(X);
    int k;
    cout << "Nhap VT can them: "; cin >> k;
    if(k == 1) AddFirstStudent(L, X);
    else {
        //Tim den nut k-1, Q tro vao nut nay
        TRO Q = L;
        int index = 1;
        while(index < k-1) {
            index++;
            Q = Q->next;
        }
        //Bo sung X vao nut sau nut tro boi Q
        Insert(L, Q, X);
    }
    cout << "\tDanh sach sinh vien sau khi add" << endl;
    HienThiDsSV(L);
    
}

//Tìm kiếm sinh viên bằng tên
TRO SearchByName(TRO L, string Ten) {
    TRO Q = L;
    while(Q != NULL && Q->infor.TEN.compare(Ten) != 0) {
        Q = Q->next;
    }
    return Q;
}

//Hiển thị thông tin một sinh viên
void HienThiThongTin1SV(SINHVIEN X, int index) {
    cout << setw(5) << index << setw(10) << X.MASV << setw(17) << X.HODEM << setw(8) << X.TEN  << setw(10) << X.NAMSINH << setw(10) << X.DIEMTK << endl;
}

//Hien thi những sinh vien ten Doanh
void HienThiSVDoanh(TRO L) {
    if(L == NULL) {
        cout << "\tDanh sach rong" << endl;
    }
    else {
        TRO Q, P;
        Q = SearchByName(L, "Doanh");
        if(Q == NULL) {
            cout << "Khong co sinh vien nao ten Doanh trong ds" << endl; 
        }
        else {
            int index = 1;
            P = L;
            cout << setw(5) << "STT" << setw(10) << "Ma SV" << setw(25) << "Ho va ten" << setw(10) << "Nam sinh" << setw(10) << "Diem TK" << endl;
            while(P != NULL) {
                if(P->infor.TEN.compare("Doanh") == 0) {
                    SINHVIEN X = P->infor;
                    HienThiThongTin1SV(X, index);
                }
                P = P->next;
                index++;
            }
        }
    }
}

void SapXepGiamDan(TRO &L) {
    TRO P, Q, R;
    P = L;
    while(P->next != NULL) {
        R = P;
        Q = P->next;
        while(Q != NULL) {
            if(Q->infor.DIEMTK > R->infor.DIEMTK) {
                R = Q;
            }
            Q = Q->next;
        }

        SINHVIEN X = P->infor;
        P->infor = R->infor;
        R->infor = X;

        P = P->next;
    }
    cout << "========DS SAU KHI SAP XEP GIAM DIEM TONG KET==========" << endl;
    HienThiDsSV(L);

}

int main() {
    TRO L;
    NhapDsSV(L);
    HienThiDsSV(L);
    //Xoa_sv8089(L);
    //BoSung(L);
    // cout << "=====Hien thi SV Doanh======" << endl;
    // HienThiSVDoanh(L);
    SapXepGiamDan(L);
    


}

