#include "graphics.h"
#include<iostream>
#include<windows.h>
#include<string.h>
#include<sstream>
#include<conio.h>
using namespace std;
void daoChuoi(int n, int a[])
{
	for (int i = n - 1; i >= n/2; i--)
	{
		int tmp = a[i];
		a[i] = a[n - 1 - i];
		a[n - 1 - i] = tmp;
	}
}
void showFirst(int tam1, int tam2, int n, int ntam, int i, int j, int a[])
{
	line(800, 500, 800, 870);
	line(800, 870, 1000, 870);
	line(1000, 870, 1000, 500);
	int h = 0;
	for (; tam1 <= 100 + n * 110; tam1 += 100)
	{
		string s = to_string(a[h]);
		char const* pchar = s.c_str();
		line(tam1, tam2, tam1 + i, tam2);
		line(tam1, tam2, tam1, tam2 + j);
		line(tam1, tam2 + j, tam1 + i, tam2 + j);
		line(tam1 + i, tam2, tam1 + i, tam2 + j);
		drawText(tam1 + 40, tam2 + 10, pchar);
		tam1 += 10;
		h++;
	}
	setcolor(9);
}
void showDelete(int tam1, int tam2, int m, int i, int j, int b[])
{
	line(800, 500, 800, 870);
	line(800, 870, 1000, 870);
	line(1000, 870, 1000, 500);
	int h = 0;
	while (tam2 > 800 - (m-1) * 60)
	{
		string s = to_string(b[h]);
		char const* pchar = s.c_str();
		line(tam1, tam2, tam1 + i, tam2);
		line(tam1, tam2, tam1, tam2 + j);
		line(tam1, tam2 + j, tam1 + i, tam2 + j);
		line(tam1 + i, tam2, tam1 + i, tam2 + j);
		drawText(tam1 + 40, tam2 + 10, pchar);
		h++;
		tam2 -= 60;
	}
	setcolor(9);
}
void showInsert(int tam1, int tam2, int dem, int i, int j, int b[])
{
	line(800, 500, 800, 870);
	line(800, 870, 1000, 870);
	line(1000, 870, 1000, 500);
	int h = 0;
	while(tam2 > 800 - dem * 60)
	{
		string s = to_string(b[h]);
		char const* pchar = s.c_str();
		line(tam1, tam2, tam1 + i, tam2);
		line(tam1, tam2, tam1, tam2 + j);
		line(tam1, tam2 + j, tam1 + i, tam2 + j);
		line(tam1 + i, tam2, tam1 + i, tam2 + j);
		drawText(tam1 + 40, tam2 + 10, pchar);
		h++;
		tam2 -= 60;
	}
	setcolor(9);
}
void InsertNode(int &n, int a[], int &ntam, int i, int j, int h, int &xInsert, int &yInsert, int &xDelete, int &yDelete, int &m, int b[], int &mtam, int &dem)
{
	int x = 100 + n * 100, y = 400;
	int k = x, l = y;
	string s = to_string(a[h]);
	char const* pchar = s.c_str();
	for (; k <= xInsert; k+=10)
	{
		system("cls");
		showFirst(200, 400, ntam-1, ntam, i, j, a);
		line(k, y, k + i, y);
		line(k, y, k, y + j);
		line(k, y + j, k + i, y + j);
		line(k + i, y, k + i, y + j);
		drawText(k + 40, y + 10, pchar);
		showInsert(850, 800, dem, i, j, b);
	}
	k -= 10;
	while(y <= yInsert)
	{
		system("cls");
		showFirst(200, 400, ntam-1, ntam, i, j, a);
		line(k, y, k + i, y);
		line(k, y, k, y + j);
		line(k, y + j, k + i, y + j);
		line(k + i, y, k + i, y + j);
		drawText(k + 40, y + 10, pchar);
		showInsert(850, 800, dem, i, j, b);
		y += 10;
	}
	mtam++;
	b[m++] = a[h];
	dem++;
	showInsert(k, 800, dem, i, j, b);
	drawText(k - 100, yInsert + 10, "TOP");
	line(k - 60, yInsert + 25, k, yInsert + 25);
	xDelete = xInsert, yDelete = yInsert, yInsert -= 60;
	setcolor(9);
	n--;
	ntam--;
	Sleep(1000);
}
void DeleteNode(int& m, int b[], int i, int j, int& xInsert, int& yInsert, int& xDelete, int& yDelete, int ntam, int a[], int n, int &dem)
{
	string s = to_string(b[m-1]);
	char const* pchar = s.c_str();
	for (int y = yDelete; y > 400; y -= 10)
	{
		system("cls");
		showFirst(200, 400, n, ntam, i, j, a);
		showDelete(850, 800, m, i, j, b);
		line(xDelete, y, xDelete + i, y);
		line(xDelete, y, xDelete, y + j);
		line(xDelete, y + j, xDelete + i, y + j);
		line(xDelete + i, y, xDelete + i, y + j);
		drawText(xDelete + 40, y + 10, pchar);
	}
	int y = 400;
	for (int x = xDelete; x < 1400; x += 10)
	{
		system("cls");
		showFirst(200, 400, n, ntam, i, j, a);
		showDelete(850, 800, m, i, j, b);
		line(x, y, x + i, y);
		line(x, y, x, y + j);
		line(x, y + j, x + i, y + j);
		line(x + i, y, x + i, y + j);
		drawText(x + 40, y + 10, pchar);
	}	
	yInsert = yDelete, yDelete += 60;
	m--;
	dem--;
	if (m > 0)
	{
		drawText(xDelete - 100, yDelete + 10, "TOP");
		line(xDelete - 60, yDelete + 25, xDelete, yDelete + 25);
	}
	Sleep(1000);
}
int main()
{
	char ini[] = "C:\\TURBOC3\\BGI";
	initgraph();
	char s1[] = "Mo phong hoat dong cua Stack";
	outtextxy(700, 20, s1);
	cout << endl;
	int n, m = 0, mtam = 0, dem = 0;
	int a[100], b[100];
	cout << "Nhap so phan tu can them: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	daoChuoi(n, a);
	int tam1 = 200, tam2 = 400, ntam = n, i = 100, j = 50;
	int xInsert = 850, yInsert = 800, xDelete, yDelete;
	showFirst(tam1, tam2, n, ntam, i, j, a);
	int chon = 1;
	do
	{
		do
		{
			cout << "1. Insert\n2. Delete\n0. Exit\n";
			cin >> chon;
		} while (chon != 0 && chon != 1 && chon != 2);
		if (chon == 1)
		{
			if (n > 0)
			{
				int h = n - 1;
				InsertNode(n, a, ntam, i, j, h, xInsert, yInsert, xDelete, yDelete, m, b, mtam, dem);
			}
			else
				cout << "EMPTY !\n";
		}
		else if (chon == 2)
		{
			if (m > 0)
			{
				DeleteNode(m, b, i, j, xInsert, yInsert, xDelete, yDelete, ntam, a, n, dem);
			}
			else
				cout << "STACK IS EMPTY !\n";
		}
		else
		{
			system("cls");
			break;
		}
	} while (chon == 1 || chon == 2);
	char s2[] = "-----MO PHONG HOAN TAT-----";
	outtextxy(700, 100, s2);
	return 0;
}