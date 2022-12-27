#include "graphics.h"
#include<iostream>
#include<windows.h>
#include<string.h>
#include<sstream>
#include<conio.h>
using namespace std;
void daoChuoi(int n, int a[])
{
	for (int i = n - 1; i >= n / 2; i--)
	{
		int tmp = a[i];
		a[i] = a[n - 1 - i];
		a[n - 1 - i] = tmp;
	}
}
void xoaPhanTuDau(int& m, int b[])
{
	for (int i = m - 1; i > 0; i--)
	{
		int tmp = b[i - 1];
		b[i - 1] = b[i];
		b[i] = tmp;
	}
	m--;
}
void themPhanTuCuoi(int& m, int b[], int x)
{
	for (int i = m; i >= 0; i--)
	{
		if (i == 0)
		{
			b[i] = x;
			break;
		}
		int tmp = b[i];
		b[i] = b[i - 1];
		b[i - 1] = tmp;
	}
	m++;
}
void showFirst(int tam1, int tam2, int n, int ntam, int i, int j, int a[])
{
	line(700, 500, 1200, 500);
	line(700, 600, 1200, 600);
	int h = 0;
	for (; tam1 < 200 + n * 60; tam1 += 60)
	{
		string s = to_string(a[h]);
		char const* pchar = s.c_str();
		rectangle(tam1, tam2, tam1 + i, tam2 + j);
		drawText(tam1 + 15, tam2 + 10, pchar);
		h++;
	}
	drawText(700, 450, "LEFT");
	drawText(1150, 450, "RIGHT");
	setcolor(9);
}
void showInsertLeft(int tam1, int tam2, int dem, int m, int i, int j, int b[])
{
	line(700, 500, 1200, 500);
	line(700, 600, 1200, 600);
	int h = m - 1;
	while (tam1 < 710 + dem * 60)
	{
		string s = to_string(b[h]);
		char const* pchar = s.c_str();
		rectangle(tam1, tam2, tam1 + i, tam2 + j);
		drawText(tam1 + 15, tam2 + 10, pchar);
		h--;
		tam1 += 60;
	}
	setcolor(9);
}
void InsertNodeRight(int& n, int a[], int& ntam, int i, int j, int h, int& xInsertLeft, int& yInsertLeft, int& xInsertRight, int& yInsertRight, int& xDeleteLeft, int& yDeleteLeft, int& xDeleteRight, int& yDeleteRight, int& m, int b[], int& mtam, int& dem)
{
	int x = 200 + (n - 1) * 60, y = 400;
	int k = x, l = y;
	string s = to_string(a[h]);
	char const* pchar = s.c_str();
	int xshow = 710;
	while (y <= 700)
	{
		system("cls");
		showFirst(200, 400, ntam - 1, ntam, i, j, a);
		showInsertLeft(xshow, 520, dem, m, i, j, b);
		rectangle(x, y, x + i, y + j);
		drawText(x + 15, y + 10, pchar);
		y += 10;
	}
	y -= 10;
	for (; k <= 1300; k += 10)
	{
		system("cls");
		showFirst(200, 100, ntam - 1, ntam, i, j, a);
		showInsertLeft(xshow, 520, dem, m, i, j, b);
		rectangle(k, y, k + i, y + j);
		drawText(k + 15, y + 10, pchar);
	}
	for (; y >= 520; y -= 10)
	{
		system("cls");
		showFirst(200, 400, ntam - 1, ntam, i, j, a);
		showInsertLeft(xshow, 520, dem, m, i, j, b);
		rectangle(k, y, k + i, y + j);
		drawText(k + 15, y + 10, pchar);
	}
	y += 10;
	for (int tam = 1300; tam >= xInsertRight; tam -= 10)
	{
		system("cls");
		showFirst(200, 400, ntam - 1, ntam, i, j, a);
		showInsertLeft(xshow, 520, dem, m, i, j, b);
		rectangle(tam, y, tam + i, y + j);
		drawText(tam + 15, y + 10, pchar);
	}
	xshow += 60;
	mtam++;
	themPhanTuCuoi(m, b, a[h]);
	dem++;
	showInsertLeft(710, 520, dem, m, i, j, b);
	xDeleteLeft = 710;
	xInsertRight += 60, xDeleteRight = 710 + dem * 60;
	setcolor(9);
	n--;
	ntam--;
	Sleep(1000);
}
void InsertNodeLeft(int& n, int a[], int& ntam, int i, int j, int h, int& xInsertLeft, int& yInsertLeft, int& xInsertRight, int& yInsertRight, int& xDeleteLeft, int& yDeleteLeft, int& xDeleteRight, int& yDeleteRight, int& m, int b[], int& mtam, int& dem)
{
	int x = 200 + (n - 1) * 60, y = 400;
	int k = x, l = y;
	string s = to_string(a[h]);
	char const* pchar = s.c_str();
	int xshow = 710;
	while (y <= yInsertLeft)
	{
		system("cls");
		showFirst(200, 400, ntam - 1, ntam, i, j, a);
		showInsertLeft(xshow, 520, dem, m, i, j, b);
		rectangle(x, y, x + i, y + j);
		drawText(x + 15, y + 10, pchar);
		y += 10;
	}
	y -= 10;
	for (; k <= xInsertLeft; k += 10)
	{
		system("cls");
		showFirst(200, 400, ntam - 1, ntam, i, j, a);
		showInsertLeft(xshow, 520, dem, m, i, j, b);
		rectangle(k, y, k + i, y + j);
		drawText(k + 15, y + 10, pchar);
	}
	xshow += 60;
	xDeleteLeft = xInsertLeft, yDeleteLeft = yInsertLeft;
	xInsertRight += 60, xDeleteRight = 710 + dem * 60;
	mtam++;
	b[m++] = a[h];
	dem++;
	showInsertLeft(710, 520, dem, m, i, j, b);
	setcolor(9);
	n--;
	ntam--;
	Sleep(1000);
}
void DeleteNodeLeft(int& m, int b[], int i, int j, int& xInsertRight, int& yInsertRight, int& xDeleteLeft, int& yDeleteLeft, int& xDeleteRight, int& yDeleteRight, int ntam, int a[], int n, int& dem)
{
	string s = to_string(b[m - 1]);
	char const* pchar = s.c_str();
	m--;
	dem--;
	for (int x = xDeleteLeft; x >= 100; x -= 10)
	{
		system("cls");
		showFirst(200, 400, n, ntam, i, j, a);
		showInsertLeft(710, 520, dem, m, i, j, b);
		rectangle(x, yDeleteLeft, x + i, yDeleteLeft + j);
		drawText(x + 15, yDeleteLeft + 10, pchar);
	}
	xInsertRight -= 60, xDeleteRight -= 60;
	showInsertLeft(710, 520, dem, m, i, j, b);
	Sleep(1000);
}
void DeleteNodeRight(int& m, int b[], int i, int j, int& xInsertRight, int& yInsertRight, int& xDeleteLeft, int& yDeleteLeft, int& xDeleteRight, int& yDeleteRight, int ntam, int a[], int n, int& dem)
{
	string s = to_string(b[0]);
	char const* pchar = s.c_str();
	xoaPhanTuDau(m, b);
	dem--;
	int x = xDeleteRight;
	while(x <= 1500)
	{
		system("cls");
		showFirst(200, 400, n, ntam, i, j, a);
		showInsertLeft(710, 520, dem, m, i, j, b);
		rectangle(x, yDeleteRight, x + i, yDeleteRight + j);
		drawText(x + 15, yDeleteRight + 10, pchar);
		x += 10;
	}
	xInsertRight -= 60, xDeleteRight -= 60;
	showInsertLeft(710, 520, dem, m, i, j, b);
	Sleep(1000);
}
int main()
{
	char ini[] = "C:\\TURBOC3\\BGI";
	initgraph();
	char s1[] = "Mo phong hoat dong cua DEQUEUE";
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
	int tam1 = 200, tam2 = 400, ntam = n, i = 50, j = 50;
	int xInsertLeft = 710, xInsertRight = 710, yInsertLeft = 520, yInsertRight = 520, xDeleteLeft, yDeleteLeft = 520, xDeleteRight, yDeleteRight = 520;
	showFirst(tam1, tam2, n, ntam, i, j, a);
	int chon = 1;
	do
	{
		do
		{
			cout << "1. Insert Left\n2. Insert Right\n3. Delete Left\n4. Delete Right\n0. Exit\n";
			cin >> chon;
		} while (chon != 0 && chon != 1 && chon != 2 && chon != 3 && chon != 4);
		if (chon == 1)
		{
			if (n > 0)
			{
				int h = n - 1;
				InsertNodeLeft(n, a, ntam, i, j, h, xInsertLeft, yInsertLeft, xInsertRight, yInsertRight, xDeleteLeft, yDeleteLeft, xDeleteRight, yDeleteRight, m, b, mtam, dem);
			}
			else
				cout << "EMPTY !\n";
		}
		else if (chon == 2)
		{
			if (n > 0)
			{
				int h = n - 1;
				InsertNodeRight(n, a, ntam, i, j, h, xInsertLeft, yInsertLeft, xInsertRight, yInsertRight, xDeleteLeft, yDeleteLeft, xDeleteRight, yDeleteRight, m, b, mtam, dem);
			}
			else
				cout << "EMPTY !\n";
		}
		else if (chon == 3)
		{
			if (m > 0)
			{
				DeleteNodeLeft(m, b, i, j, xInsertRight, yInsertRight, xDeleteLeft, yDeleteLeft, xDeleteRight, yDeleteRight, ntam, a, n, dem);
			}
			else
				cout << "EMPTY !\n";
		}
		else if (chon == 4)
		{
			if (m > 0)
			{
				DeleteNodeRight(m, b, i, j, xInsertRight, yInsertRight, xDeleteLeft, yDeleteLeft, xDeleteRight, yDeleteRight, ntam, a, n, dem);
			}
			else
				cout << "EMPTY !\n";
		}
		else
		{
			system("cls");
			break;
		}
	} while (chon == 1 || chon == 2 || chon == 3 || chon == 4);
	char s2[] = "-----MO PHONG HOAN TAT-----";
	outtextxy(700, 100, s2);
	return 0;
}