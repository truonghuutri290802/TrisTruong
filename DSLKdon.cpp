#include<iostream>
using namespace std;
// Bai toan : Khai bao danh sach lien ket don cac so nguyen . Tim gia tri lon nhat trong danh sach
// ================Khai bao cau truc Danh Sach lien ket don cac so nguyen  ========
// khai bao cau truc mot node
struct node
{
    int data; // du lieu chua trong mot node
    node *link; // con tro dung de lien ket giua cac node voi nhau
};
typedef struct node NODE; // thay the struct node bang NODE
// khai bao cau truc cua danh sach lien ket don
struct List
{
    NODE *pHead;
    NODE *pTail;
};
typedef struct List LIST;
// Khoi tao cau truc Danh Sach lien ket don cac so nguyen
void KhoiTao(List &l){
    // cho hai node tro de den NULL - vi danh sach lien ket chua co phan tu
    l.pHead = NULL;
    l.pTail = NULL;
}
// ham khoi tao mot cai NODE
NODE *KhoiTaoNode(int x){
    NODE *p = new NODE;
    if(p == NULL){
        cout<<"Khong du bo nho de cap phat!";
        return NULL;
    }
    p->data = x;// truyen gia tri x vao cho data 
    p->link = NULL;// dau tien ta khai bao node no thi node do chua co lien ket den node nao het ==> con tro cua no tro den NULL
    return p;// tra ve node vua khoi tao
}
// ham them node vao dau danh sach lien ket
void ThemVaoDau(LIST &l,NODE *p)
{
    if(l.pHead == NULL){
        l.pHead = l.pTail = p;
    }
    else{
        p->link = l.pHead;// cho con tro vua them la node p lien ket vao den node dau -pHead
        l.pHead = p;//cap nhat lai pHead chinh la node p;
    }
}
// ham them node p vao cuoi danh sach lien ket don 
void ThemVaoCuoi(LIST &l, NODE  *p){
    if(l.pHead == NULL){
        l.pHead = l.pTail = p;
    }
    else{
        l.pTail -> link = p;// cho con tro ptail lien ket den con tro cua node p 
        l.pTail = p;// cap nhat lai ptTail chinh la node p;
    }
}
// them node p vao sau node q

// Ham xuat danh sach lien ket don
void XuatDS(List l){
    for(NODE *k = l.pHead ; k != NULL;k = k->link)
    {
        cout<<k->data<<" ";
    }
}
// ham tim gia tri lon nhat trong danh sach
int TimMax(List l)
{
    int max = l.pHead->data;
    // bat dau duyen tu node thu 2 vi node dau ta da gan gia tri lon nhat
    for (NODE *k = l.pHead->link ; k!= NULL ; k = k->link)
    {
        if(max<k->data){
            k->data = max;// cap nhat lai gia tri max
        }
    }
    return max;
}
void Menu(LIST &l)
{
    int luachon;

    while (69)
    {
        system("cls");
        cout<<" \n\t\t===== MENU =====";
        cout<<"\n\t 1.Nhap du lieu cho danh sach lien ket";
        cout<<"\n\t 2.Xuat danh sach lien ket don ";
        cout<<"\n\t 3.Xuat ra gia tri max";
        cout<<"\n\t 0.Thoat";
        cout<<" \n\t\t===== END =====";

        cout<<" \nMoi nhap lua chon:";
        cin>>luachon;
        if(luachon <0 || luachon >3){
            cout<<"\n\n Lua chon cua ban khong hop le. Xin vui long kiem tra lai !";
            system("pause");  // dung man hinh   
        }
        if(luachon == 1){
            int x;
            do
            {
            
                cout<<" Nhap x (0 de thoat) :";
                cin>>x;
                if(x == 0)
                    break;
                NODE *p = KhoiTaoNode(x);
                ThemVaoCuoi(l,p);
            } while (x != 0);
            
            
        }
        else if(luachon == 2)
        {
            cout<<"\nDanh sach vua nhap:";
            XuatDS(l);
            system("pause");
        }
        else if (luachon ==3)
        {
            cout<<"\n Gia tri lon nhat trong DSLK:"<<TimMax(l);
            cout<<endl;
        }
        
        else
        {
            break;// thoat khoi vong lap hien tai 
        }
    }
    
}
int main()
{
    LIST l;
    KhoiTao(l);// luon luon goi ham khoi tao danh sach lien ket don truoc khi thao tac voi danh sach
    Menu(l);
    system("pause");
    return 0;
}
/*int main(){
    LIST l;
    KhoiTao(l); // khoi ds lien ket don
    int n ;
    cout<<"Nhap so luong node can them : ";
    cin>> n;
    for (int i = 0; i <= n; i++)
    {
        int x;
        cout<< "nhap gia tri so nguyen :";
        cin>>x;
        NODE *p = KhoiTaoNode(x); // khoi tao ra 1 node so nguyen
        ThemVaoDau(l,p);    
    }
    cout<<"Danh sach lien ket cac so nguyen:";
    XuatDS(l);
    cout<<endl;
    cout<<"So lon nhat trong danh sach la:"<<TimMax(l)<<endl;
    system("pause");
    return 0;
}*/