/*Xây d?ng danh sách liên k?t don v?i m?i node là 1 sinh viên có các field sau:
Mã sv, h? tên, gi?i tính, d?a ch?, sdt, di?m môn toán, van anh*/



#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
struct SV
{
    int maSV;
    char tenSV[30];
    char gioiTinh[20];
    char diaChi[50];
    char sdt[12];
    float diemMT,diemMA;
};
// d?nh nghia 1 nút
struct Node
{
    SV info;
    struct Node*next;
};
// d?nh nghia damh sách
struct list
{
    Node *Head;
    Node *Tail;
};
// t?o danh sach r?ng
void init (list &Q)
{;
    Q.Head=NULL;
    Q.Tail=NULL;
}
// t?o nút m?i
Node *getNode(SV x)
{
    Node *p;
    p = new Node;
    if(p== NULL)
    {
        printf("\n Cap nhap khong thanh cong");
        exit(1);
    }
    p->info=x;
    p-> next =NULL;
    return p;
}
void chendau(list &Q, Node *p)
{
    if(Q.Head == NULL)
    {
        Q.Head=p;
        Q.Tail=p;
    }
    else
    {
        p-> next= Q.Head;
        Q.Head=p;
    }
}
void nhapdsSV(list &Q)
{
    int n,i;
    SV x;
    Node *p;
    printf("\n Nhap so sinh vien: "); scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("\n Nhap thong tin sinh vien thu %d ",i+1);
        printf("\n Nhap ma sinh vien: "); scanf("%d", &x.maSV);
        printf("\n Nhap ten sinh vien: ");
        fflush(stdin); gets(x.tenSV);
        printf("\n Nhap gioi tinh sinh vien: ");
        fflush(stdin); gets(x.gioiTinh);
        printf("\n Nhap dia chi sinh vien: ");
        fflush(stdin); gets(x.diaChi);
        printf("\n Nhap so dien thoai sinh vien: ");
        fflush(stdin); gets(x.sdt);
        printf("\n Nhap diem mon toan:"); scanf("%f",&x.diemMT);
        printf("\n Nhap diem mon anh: "); scanf("%f",&x.diemMA);
        p= getNode(x);
        chendau(Q,p);
    }
}
void indssach(list &Q)
{
    Node *p;
    printf("\n Danh sach sach la: ");
    printf("\n %-15s%-15s%-15s%-15s%-15s%-15s%-10s","Ma sinh vien","Ten sinh vien", "Gioi tinh","Dia chi","So dien thoai","Diem mon toan","Diem mon anh");
    for(p=Q.Head; p!=NULL; p=p->next)
    {
        printf("\n %-15d%-15s%-15s%-15s%-15s%-15f%-10f%",p->info.maSV, p->info.tenSV, p->info.gioiTinh, p->info.diaChi, p->info.sdt, p->info.diemMT,p->info.diemMA);
    }
    printf("\n ----------------- \n");
}
int main ()
{
        list Q;
        SV x;
        Node*p;
        init (Q);
        int a;
        printf("\n 1.Nhap danh sach sinh vien");
        printf("\n 2.In danh sinh vien");
        printf("\n 0. thoat chuong trinh");
        do{
                printf("\n moi ban lua chon: ");scanf("%d",&a);
                switch(a)
                {
                  case 1:  nhapdsSV(Q); break;
                  case 2:  indssach(Q);break;
                  
                }
        }
        while(a!=0);
        return 0;
    }

