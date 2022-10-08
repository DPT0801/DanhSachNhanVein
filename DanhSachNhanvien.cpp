#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string.h>
using namespace std;
class Nhanvien
{
    private:
        int Manv;
        char* Hoten;
        int Sdt;
    public:
        Nhanvien* next;
        Nhanvien()
        {
            Manv=0;
            Sdt=0;
            Hoten=new char[25];
            next=NULL;
        }
        void Input()
        {
            cout<<"  Ma so:";
            cin>>Manv;
            cout<<"  Ho ten:";
            cin.ignore();cin.getline(Hoten,25);
            cout<<"  So dien thoai:";
            cin>>Sdt;
        }
        void setIndex(int id,char* ht,float sdt)
        {
            Manv=id;
            Hoten=ht;
            Sdt=sdt;
        }
        int getManv()
        {
            return Manv;
        }
        char* getHoten()
        {
            return Hoten;
        }
        float getsdt()
        {
            return Sdt;
        }
};
 
class QuanLy
{
    private:
        Nhanvien* first;
    public:
        QuanLy()
        {
            first=NULL;
        }
        void Creat();
        void Change(Nhanvien* nv1,Nhanvien* nv2);
        void Sort();
        void printDSach();
        void SearchManv();
};
 
void QuanLy::Creat()
{
    Nhanvien* present;
    int amount=0;
    char c;
    do
    {
        if(first==NULL)
        {
            first=new Nhanvien;
            present=first;
        }
        else
        {
            present->next=new Nhanvien;
            present=present->next;
        }
        cout<<"Nhap thong tin nhan vien thu "<<++amount<<":"<<endl;
        present->Input();
        cout<<"Tiep tuc?(c/k):";
        fflush(stdin);c=getche();
        cout<<endl;
    }
    while(c=='c'||c=='C');
}
void QuanLy::SearchManv()
{
	
    
}
void QuanLy::Sort()
{
    if(first==NULL)
    {
        printf("Danh sach trong");
        fflush(stdin);getch();
        return;
    }
    Nhanvien* sorting;
    sorting=first;
    while(sorting->next!=NULL)
    {
        Nhanvien* sort;
        sort=sorting->next;
        while(sort!=NULL)
        {
            if(strcmp(sort->getHoten(),sorting->getHoten())<0)
            {
                int id=sorting->getManv();
                char* s=sorting->getHoten();
                float sdt=sorting->getsdt();
                sorting->setIndex(sort->getManv(),sort->getHoten(),sort->getsdt());
                sort->setIndex(id,s,sdt);
            }
            sort=sort->next;
        }
        sorting=sorting->next;
    }
    cout<<"Da sap xep nhan vien";
    fflush(stdin);getch();
}
void QuanLy::printDSach()
{
    if(first==NULL)
    {
        printf("Danh sach trong");
        fflush(stdin);getch();
        return;
    }
    Nhanvien* present;
    present=first;
    if(present!=NULL)
        printf("%-8s%-26s%s\n","Ma so","Ho va ten","So dien thoai");
    while(present!=NULL)
    {
        printf("%-8d%-26s%-0.3f\n",present->getManv(),present->getHoten(),present->getsdt());
        present=present->next;
    }
    fflush(stdin);getch();
}
 
int main()
{
    QuanLy ql;
    int c;
    while(1)
    {
        cout<<"\t\tMENU"<<endl;
        cout<<"\t1.Tao danh sach"<<endl;
        cout<<"\t2.Sap xep danh sach"<<endl;
        cout<<"\t3.In danh sach"<<endl;
        cout<<"\t4.Thoat chuong trinh"<<endl;
        cout<<"\n\tMoi ban chon chuc nang:";
        fflush(stdin);c=getche();
        cout<<endl;
        switch(c)
        {
            case '1':
                ql.Creat();
                break;
            case '2':
                ql.Sort();
                break;
            case '3':
                ql.printDSach();
                break;
            case '4':
                exit;
        }
    }
}