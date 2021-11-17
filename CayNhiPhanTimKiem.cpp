#include<iostream>
using namespace std;
struct node
{
    int data;
    node* pLeft;
    node* pRight;
};
typedef struct node NODE;
typedef NODE* TREE;

void KhoiTaoCay(TREE &t)
{
    t = NULL;
}
void ThemNodeVaoCay(TREE &t,int x)
{
    if(t == NULL)
    {
        NODE* p = new NODE;
        p->data = x;
        p->pLeft= NULL;
        p->pRight = NULL;
        t=p;
    }
    else // cay ton tai phan tu
    {
        if (t->data>x)
        {
            ThemNodeVaoCay(t->pLeft,x);
        }
        else if (t->data<x)
        {
            ThemNodeVaoCay(t->pRight,x);
        }
    }
}
void DuyetCay_NLR(TREE t)
{
    if(t != NULL)
    {
        cout<<t->data<<" ";
        DuyetCay_NLR(t->pLeft);
        DuyetCay_NLR(t->pRight);
    }
}
void MENU(TREE &t)
{
    while (true)
    {
        cout<<"\n\t\t========= Chuong trinh nhap du lieu cho cay nhi phan =========";
        cout<<"\n\t\t\t1.Nhap du lieu";
        cout<<"\n\t\t\t2.Xuat cay theo kieu nhi phan ";
        cout<<"\n\t\t\t0. Thoat ";
        int luachon;
        cout<<"\nMoi ban lua chon:"; cin>>luachon;
        if(luachon >2 || luachon < 0)
        {
            cout<<"Lua chon khong hop le !";
            system("pause");
        }
        else if (luachon == 1 )
        {
            // int x ;
            // cout <<"Moi ban nhap du lieu: ";
            // cin>> x;
            // ThemNodeVaoCay(t,x);
            int x;
            do
            {
                cout<<"Moi ban nhap(0 de thoat): "; cin>>x;
                if(x == 0)
                    break;
                ThemNodeVaoCay(t,x);
            } while (x!= 0);
            cout<<"\n Da nhap du lieu xong !";          
        }
        else if (luachon == 2)
        {
            cout<<" Day so vua nhap la:";DuyetCay_NLR(t);
            
        }
        else
        {
            break;
        }
    }
}
int main()
{
    TREE t;
    KhoiTaoCay(t);
    MENU(t);
    system("pause");
    return 0;
}