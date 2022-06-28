// Chuong trinh thuc hien quan li sinh vien demo
#include <iostream>
#include <cstring>
#include <conio.h>
#include <string>
#include <fstream>
#include <Windows.h>
using namespace std;
//=============================Ham do hoa=============================================
void GoTo(SHORT posX, SHORT posY)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Position;
    Position.X = posX;
    Position.Y = posY;

	SetConsoleCursorPosition(hStdout, Position);
}
//=============================Thong tin cua sinh vien================================
struct SinhVien{
	int mssv;
	char hoten[30];
};
typedef SinhVien sv;
//============================Danh sach sinh vien=====================================
struct node{
	sv a;
	node *next;
};
typedef node* NODE;
//===========================Khoi tao danh sach lien ket don==========================
void KhoiTao(NODE &PTR)
{
	PTR = NULL;
}
//===========================Xay dung ham tao node====================================
NODE TaoNut(sv c)
{
	NODE p = new node;
	p->a = c;
	p->next = NULL;
	return p;
}
void ThemNut(NODE &p,NODE q)// Them vao dau
{
	q->next = p;
	p = q;
}
void ThemNutCuoi(NODE p,NODE k)//Them vao cuoi
{
	while(p != NULL)
	{
		if(p->next == NULL)
		{
			p->next = k;
			break;
		}
		p = p->next;
	}
}
void XuatSinhVien(NODE PTR,int count)
{
	GoTo(0,3);
	cout << "----------------------------------------------------------";
    GoTo(0,2);
    cout << "|";
    GoTo(57,2);
    cout << "|";
	cout <<"\n\n Ma so sinh vien"<<"\t\t"<<"\tHo ten sinh vien\n";
	for(int i = 4 ; i < 11 + count-5; i++)
	{
		GoTo(25,i);
		cout <<"|";
	}
	for(int i = 4 ; i < 11 + count - 5 ; i++)
	{
		GoTo(0,i);
		cout <<"|";
	}
	for(int i = 0 ; i < 58 ; i++)
	{
		GoTo(i,10+count -5);
		cout <<"-";
	}
	for(int i = 4 ; i < 10 + count - 5 ; i++)
	{
		GoTo(57,i);
		cout <<"|";
	}
	int k = 5;
	int t = 5;
	for(NODE p = PTR;p != NULL; p = p->next)
	{
	    GoTo(t,k);
		cout <<"\t"<<p->a.mssv <<"\t\t"<<"\t\t" << p->a.hoten << endl;
	    ++k;
	}
}
int DemSoNut(NODE PTR)
{
	int count = 0;
	for(NODE p = PTR;p != NULL; p = p->next)
	{
		count++;
	}
	return count;
}
void GiaiPhong(NODE PTR)
{
	NODE p;
	while(PTR != NULL)
	{
		p = PTR;
		PTR = PTR->next;
		delete p;
	}
}
NODE SearchMa(NODE PTR,int n)
{
	for(NODE p = PTR;p != NULL; p = p->next)
	{
		if(p->a.mssv == n )
		{
		    return p;
		}
	}
	return NULL;
}
void Swap(sv &a, sv &b)
{
	sv temp = a;
	a = b;
	b = temp;
}
void SapXep(NODE PTR,int count)
{
	sv p[100];
	int i = 0;
	for(NODE q = PTR ; q != NULL; q = q->next)
	{
		p[i] = q->a;
		i++;
	}
	for(int  h = 0 ; h < i ; h++)
	{
		for( int j = h + 1 ;j < i ; j++)
		{
			if(p[h].mssv > p[j].mssv)
			{
				Swap(p[h],p[j]);
			}
		}
	}
	GoTo(0,3);
	cout << "----------------------------------------------------------";
    GoTo(0,2);
    cout << "|";
    GoTo(57,2);
    cout << "|";
	cout <<"\n\n Ma so sinh vien"<<"\t\t"<<"\tHo ten sinh vien\n";
	for(int i = 4 ; i < 11 + count-5; i++)
	{
		GoTo(25,i);
		cout <<"|";
	}
	for(int i = 4 ; i < 11 + count - 5 ; i++)
	{
		GoTo(0,i);
		cout <<"|";
	}
	for(int i = 0 ; i < 58 ; i++)
	{
		GoTo(i,10+count -5);
		cout <<"-";
	}
	for(int i = 4 ; i < 10 + count - 5 ; i++)
	{
		GoTo(57,i);
		cout <<"|";
	}
	int k = 5;
	int t = 5;
	for(int h = 0 ; h < i ; h++)
	{
	    GoTo(t,k);
		cout <<"\t"<<p[h].mssv << "\t\t" <<"\t\t"<< p[h].hoten << endl;
	    ++k;
	}
	
}
void DeleteFirst(NODE &PTR)
{
	NODE p;
	p = PTR;
	PTR = PTR->next;
	delete p;
}
void DeleteInFo(NODE &PTR,NODE q)
{
	if(PTR->a.mssv == q->a.mssv)
	{
       DeleteFirst(PTR);
	}
	else
	{
		NODE g = new node;
		for(NODE k = PTR; k != NULL; k = k->next)
		{
			if(k->a.mssv == q->a.mssv)
			{
				NODE d = k->next;
				g->next = d;
				delete k;
				break;
			}
			g = k;
		}
	}
}
void GhiFile(NODE PTR)
{
	ofstream of;
	of.open("output.txt",ios_base::out);
	of << DemSoNut(PTR) << endl;
	for(NODE p = PTR; p != NULL; p=p->next)
	{
		of << p->a.mssv << endl;
		of << p->a.hoten << endl;
	}
}
void DocFile(NODE &PTR)
{
	
	ifstream a;
	a.open("input.txt",ios_base::in);
	int count;
	string HOTEN,temp;
	sv p[100];
    a >> count;
    if (count == 0) {
		return;
	}
    getline(a,temp);
    for(int i = 0; i < count ; i++)
    {
    	a >> p[i].mssv;
    	getline(a,temp,'\n');
    	getline(a,HOTEN,'\n');
    	HOTEN.copy(p[i].hoten,HOTEN.length());
    	p[i].hoten[HOTEN.length()]='\0';
    	if(DemSoNut(PTR) == 0)
		 	{
		 	NODE q = TaoNut(p[i]);
		 	ThemNut(PTR,q);
		    }
		    else
		    {
		    	NODE q = TaoNut(p[i]);
		    	ThemNutCuoi(PTR,q);
			}
		
    	
	}
	a.close();
}
int CheckTrungMa(NODE PTR,int n)
{
	for(NODE p = PTR ; p != NULL ; p = p->next)
	{
		if(p->a.mssv == n)
		{
			return 1;
		}
	}
	return 0;
}
int main ()
{
	 sv b;
	 NODE PTR;
	 KhoiTao(PTR);
	 DocFile(PTR);
	 int n;
	 do{
	 	 system("cls");
	 	 cout <<"\t\t\t\tMENU QUAN LI SINH VIEN\n";
	 	 cout <<"\t\t======================================================\n";
	 	 cout <<"\t\t|| 1.Liet ke danh sach sinh vien ra man hinh.       ||\n";
	 	 cout <<"\t\t|| 2.Tong sinh vien hien dang co trong danh sach.   ||\n";
	 	 cout <<"\t\t|| 3.Them sinh vien vao danh sach.                  ||\n";
	 	 cout <<"\t\t|| 4.Tim sinh vien.                                 ||\n";
	 	 cout <<"\t\t|| 5.Xoa sinh vien.                                 ||\n";
	 	 cout <<"\t\t|| 6.Sap xep theo ma tang dan.                      ||\n";
	     cout <<"\t\t|| 0.Thoat khoi chuong trinh.                       ||\n";
		 cout <<"\t\t======================================================\n";
		 
		 cout << "\nMoi ban nhap chuc nang muon lam: ";
		 cin >> n;
		 if(n == 0)
		 {
		 	GhiFile(PTR);
		 	GiaiPhong(PTR);
		    break;
		 }
		 else if ( n == 1)
		 {
		 	while(true)
		 	{
		 		system("cls");
		 	GoTo(0,1);
		 	cout << "----------------------------------------------------------";
		 	cout << "\n\t\tDANH SACH SINH VIEN\n";
		 	int n = DemSoNut(PTR);
		 	XuatSinhVien(PTR,n);
		 	//system("pause");
		 	char c;
		 	c = getch();
		 	if(c == 13)
		 	{
		 		break;
			 }
		    }	
		 }
	     else if( n == 2)
	     {
	 	    cout << "Hien co trong danh sach la: "<< DemSoNut(PTR) <<" sinh vien\n";
	 	    system("pause");
		 }
		 else if( n == 3)
		 {
		 	while(true)
		 	{
		 	cout << "Moi ban nhap ma sinh vien: ";
		 	cin >> b.mssv;
		 	if(CheckTrungMa(PTR,b.mssv) == 0)
		 	{
		 		break;
			 }
			 else
			 {
			 	cout << "Ma sinh vien da ton tai !\n";
			 }
		    }
		 	cin.ignore();
		 	cout << "Moi ban nhap ho ten: ";
		 	gets(b.hoten);
		    
		 	if(DemSoNut(PTR) == 0)
		 	{
		 	NODE p = TaoNut(b);
		 	ThemNut(PTR,p);
		    }
		    else
		    {
		    	NODE p = TaoNut(b);
		    	ThemNutCuoi(PTR,p);
			}
		 }
		 else if( n == 4)
		 {
		 	cout << "Nhap ma sinh vien can tim: ";
		 	int k;
		 	cin >> k;
		 	NODE q = SearchMa(PTR, k);
		 	if(q != NULL)
		 	{
		 		cout <<"Ma so sinh vien"<<"\t\tHo ten sinh vien\n";
		 		cout <<q->a.mssv << "\t\t\t" << q->a.hoten << endl;
		 		system("pause");
			}
			else
			{
				 cout << "Ma sinh vien khong co trong danh sach\n";
				 system("pause");
			}
		 }
		 else if ( n == 5)
		 {
		 	cout << "Nhap ma sinh vien can xoa: ";
		 	int k;
		 	cin >> k;
		 	NODE q = SearchMa(PTR, k);
		 	if(q != NULL)
		 	{
		 		cout << "Ban that su muon xoa(Y/N): \n";
		 		char c;
		 		cin >> c;
		 		if( c == 'y'|| c == 'Y')
		 		{
		 		  DeleteInFo(PTR,q);
		 	    }
			}
			else
			{
				 cout << "Ma sinh vien khong co trong danh sach\n";
				 system("pause");
			}
		 }
		 else if ( n == 6)
		 {
		 	// ham demo sau nay se dung quicksort
		 	while(true)
		 	{
		 		system("cls");
		 	GoTo(0,1);
		 	cout << "----------------------------------------------------------";
		 	cout << "\n\t\tDANH SACH SINH VIEN\n";
		 	int n = DemSoNut(PTR);
		 	SapXep(PTR,n);
		 	//system("pause");
		 	char c;
		 	c = getch();
		 	if(c == 13)
		 	{
		 		break;
			 }
		    }	
		 	system("pause");
		 }
	 	
	 }while(true);
	 
}

