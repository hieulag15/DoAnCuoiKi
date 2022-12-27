#include "graphics.h"
#include<iostream>
#include <sstream>
#include <string.h>
using namespace std;

//Hien thi cac phan tu chua duoc them vao hang hoi
void showElement(int x_insert, int y, int n, int i, int j, int x_igh, int a[])
{
	line(1040, y - 5, 1800, y - 5);
	line(1040, y + 105, 1800, y + 105);
	int h = n - 1;
	for (; x_insert <= x_igh; x_insert += 110)
	{
		string s = to_string(a[h]);
		char const* pchar = s.c_str();
		setcolor(8);
		frame(x_insert, y, i, j, pchar);
		h--;
	}
	setcolor(15);
}

//Hien thi cac phan tu trong hang doi
void showQueue(int dem, int x_show, int y, int i, int j, int x_gh, int a[])
{
	line(1040, y - 5, 1800, y - 5);
	line(1040, y + 105, 1800, y + 105);
	int x_temp = x_show;
	int h = 0;
	while (x_gh >= x_show)
	{
		string s = to_string(a[h]);
		char const* pchar = s.c_str();
		setcolor(8);
		frame(x_gh, y, i, j, pchar);
		h++;
		x_gh -= 110;
	}
	setcolor(15);
}

//Them phan tu
void Insert(int dem, int n, int x_insert, int y, int x_move, int x_igh, int x_show, int x_show2, int x_gh, int x_gh2, int i, int j, int a[], int b[], int c[], int val)
{
	int k = 100;
	for (; x_move + k <= x_show; k += 50)
	{
		//Hien thi front va rear
		line(x_gh + (i / 2), y - 5, x_gh + (i / 2), y - 100);
		drawText(x_gh + (i / 2) - 40, y - 150, "FRONT");
		line(x_show + (i / 2), y + 105, x_show + (i / 2), y + 200);
		drawText(x_show + (i / 2) - 30, y + 180, "REAR");
		//Qua trinh Insert
		string s = to_string(val);
		char const* pchar = s.c_str();
		setcolor(8);
		frame(x_move + k, y, i, j, pchar);
		showElement(x_insert, y, n, i, j, x_igh - 110, a);
		showQueue(dem, x_show + 110, y, i, j, x_gh, b);
		showQueue(n, x_show2 + 110, y, i, j, x_gh2, c);
		setcolor(15);
		system("cls");
	}
}

//Xoa phan tu
void Delete(int n, int dem2, int dem1, int x_insert, int x_insert2, int y, int x_move2, int x_igh, int x_igh2, int x_show2, int x_gh2, int i, int j, int a[], int b[], int c[], int val)
{
	int k = 100;
	for (; x_move2 + k <= x_show2; k += 50)
	{
		//Hien thi front va rear
		if (x_insert2 < x_igh2)
		{
			line(x_igh2 + (i / 2), y - 5, 1700 + (i / 2), y - 100);
			drawText(x_igh2 + (i / 2) - 40, y - 150, "FRONT");
			line(x_insert2 + 110 + (i / 2), y + 105, x_insert2 + 110 + (i / 2), y + 200);
			drawText(x_insert2 + 110 + (i / 2) - 30, y + 180, "REAR");
		}
		//Qua trinh Delete
		string s = to_string(val);
		char const* pchar = s.c_str();
		setcolor(8);
		frame(x_move2 + k, y, i, j, pchar);
		showElement(x_insert, y, n, i, j, x_igh, a);
		showElement(x_insert2 + 110, y, dem1, i, j, x_igh2, b);
		showQueue(dem2, x_show2 + 110, y, i, j, x_gh2, c);
		setcolor(15);
		system("cls");
	}
}

void InsertX(int arr[], int dem, int x, int index)
{
	dem++;

	for (int i = dem - 1;i > index;i--)
		arr[i] = arr[i - 1];

	arr[index] = x;
}

void DeleteX(int arr[], int dem, int index)
{
	for (int i = index; i < dem - 1; i++) {
		arr[i] = arr[i + 1];
	}

	dem--;
}

int main()
{
	char ini[] = "C:\\TURBOC3\\BGI";
	initgraph();
	int* a = new int[10];
	int* b = new int[10];
	int* c = new int[10];

	int n;
	cout << "Nhap so luong phan tu: ";
	cin >> n;

	int x_insert = 100, y = 800, x_igh = n * 110;
	int i = 100, j = 100;
	int x_gh = 1700, x_show = x_gh, x_move = x_igh;
	int x_insert2, x_igh2;
	int x_gh2 = 2650, x_show2 = x_gh2, x_move2;
	int h, m, dem = n, dem1 = 0, dem2 = 0;

	for (int h = 0; h < n; h++)
	{
		cin >> a[h];
	}


	h = 0, m = 0;
	while (true)
	{
		//Hien thi cac phan tu chua duoc them vao
		showElement(x_insert, y, n, i, j, x_igh, a);
		//Danh sach cac lua chon
		cout << "\n\tList Select";
		cout << "\n\t1. Insert";
		cout << "\n\t2. Delete";
		cout << "\n\t3. Exit";

		int select;
		cout << "\n\tEnter select: ";
		cin >> select;
		system("cls");

		//Hien thi phan tu trong hang doi
		showQueue(n, x_show + 110, y, i, j, x_gh, b);
		//Hien thi cac phan tu vua xoa
		showQueue(n, x_show2 + 110, y, i, j, x_gh2, c);
		//Hien thi front va rear
		if (x_show < x_gh)
		{
			line(x_gh + (i / 2), y - 5, x_gh + (i / 2), y - 100);
			drawText(x_gh + (i / 2) - 40, y - 150, "FRONT");
			line(x_show + 110 + (i / 2), y + 105, x_show + 110 + (i / 2), y + 200);
			drawText(x_show + 110 + (i / 2) - 30, y + 180, "REAR");
		}

		if (select == 1)
		{
			if (dem == 0)
			{
				setcolor(9);
				drawNoti(100, y, "HET PHAN TU DE THEM VAO HANG DOI");
				setcolor(15);
			}
			else
			{
				InsertX(b, dem1, a[h], dem1);
				dem1++; //dem so luong phan tu trong hang doi
				dem--; // dem so luong phan tu chua them vao 
				Insert(dem1, n, x_insert, y, x_move, x_igh, x_show, x_show2, x_gh, x_gh2, i, j, a, b, c, a[h]);
				x_igh -= 110;
				//Hien thi front va rear
				line(x_gh + (i / 2), y - 5, x_gh + (i / 2), y - 100);
				drawText(x_gh + (i / 2) - 40, y - 150, "FRONT");
				line(x_show + (i / 2), y + 105, x_show + (i / 2), y + 200);
				drawText(x_show + (i / 2) - 30, y + 180, "REAR");
				//Hien thi phan tu trong hang doi
				showQueue(n, x_show, y, i, j, x_gh, b);
				//Hien thi cac phan tu vua xoa
				showQueue(n, x_show2 + 110, y, i, j, x_gh2, c);
				//Cap nhat lai cac gia tri
				x_show -= 110;
				x_move -= 110;
				h++;
			}
		}

		else if (select == 2)
		{
			if (dem1 == 0) drawNoti(1250, y - 200, "CHUA CO PHAN TU TRONG HANG DOI");
			else
			{
				m = 0;
				x_insert2 = x_show + 110, x_igh2 = x_gh, x_move2 = x_igh2;
				InsertX(c, dem2, b[m], dem2);
				dem2++;//dem so luong phan tu da duoc xoa
				Delete(n, dem2, dem1, x_insert, x_insert2, y, x_move2, x_igh, x_igh2, x_show2, x_gh2, i, j, a, b, c, b[m]);
				DeleteX(b, dem1, 0);
				dem1--;//dem so luong phan tu con trong hang doi
				//Hien thi front va rear
				if (x_insert2 < x_igh2)
				{
					line(x_igh2 + (i / 2), y - 5, x_igh2 + (i / 2), y - 100);
					drawText(x_gh + (i / 2) - 40, y - 150, "FRONT");
					line(x_insert2 + 110 + (i / 2), y + 105, x_insert2 + 110 + (i / 2), y + 200);
					drawText(x_insert2 + 110 + (i / 2) - 30, y + 180, "REAR");
				}
				//Hien thi phan tu trong hang doi
				showElement(x_insert2 + 110, y, dem1, i, j, x_igh2, b);
				//Hien thi phan tu vua xoa
				showQueue(n, x_show2, y, i, j, x_gh2, c);
				//Cap nhat lai cac gia tri
				x_show2 -= 110;
				x_igh2 -= 110;
				x_show += 110;
				m++;
			}
		}

		else if (select == 3)
		{
			system("cls");
			drawNoti(1275, y - 200, "KET THUC CHUONG TRINH MO PHONG");
			break;
		}

		else cout << "\n\tVui long nhap lai!";

		//tat ca phan tu deu da duoc xoa
		if (dem2 == n)
		{
			drawNoti(1275, y - 200, "KET THUC CHUONG TRINH MO PHONG");
			break;
		}
	}

	return 0;
}