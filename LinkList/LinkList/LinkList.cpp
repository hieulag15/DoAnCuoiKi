#include "graphics.h"
#include<iostream>
#include <sstream>
#include <string.h>
using namespace std;

void Insert(int& x_insert, int& y_insert, int i, int j, int val)
{
	setcolor(12);
	string s = to_string(val);
	char const* pchar = s.c_str();
	frame(x_insert, y_insert, i, j, pchar);
}

void showInsert(int dem, int x_show, int y, int i, int j, int x_gh, int h, int a[], int index)
{
	int x_temp = x_show;
	while (x_show < x_gh)
	{
		string s = to_string(a[h]);
		char const* pchar = s.c_str();
		if (h == dem) frameNULL(x_show, y, i, j, pchar);
		else frameLKT(x_show, y, i, j, pchar);
		if (h == index)
		{
			setcolor(8);
			frameColor(x_show, y, i, j);
			setcolor(12);
		}
		
		head(x_temp, y, i, j);
		tail(x_gh - 180, y, i, j);
		x_show += 180;
		h++;
	}
}

void showDelete(int dem, int x_show, int y, int i, int j, int x_gh, int h, int a[])
{
	int x_temp = x_show;
	while (x_show < x_gh)
	{
		string s = to_string(a[h]);
		char const* pchar = s.c_str();
		if (h == dem) frameNULL(x_show, y, i, j, pchar);
		else frameLKT(x_show, y, i, j, pchar);
		head(x_temp, y, i, j);
		tail(x_gh - 180, y, i, j);
		x_show += 180;
		h++;
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

	int x_insert = 1400, y_insert = 300;
	int i = 100, j = 50;
	int x_gh, x_show, y, h;
	int dem = 0;

	while (true)
	{
		if (dem == 0)
		{
			x_gh = 1500, y = 600;
			x_show = x_gh;
			h = 0;
		}

		cout << "\n\tDanh sach cac lua chon";
		cout << "\n\t1. Them";
		cout << "\n\t2. Xoa";
		cout << "\n\t3. Thoat";
		cout << "\n\tLua chon cua ban: ";
		int select;
		cin >> select;

		if (select == 1)
		{
			cout << "\n\tNhap gia tri node: ";
			int val;
			cin >> val;
			Insert(x_insert, y_insert, i, j, val);

			while (true)
			{
				cout << "\n\t1. Them dau";
				cout << "\n\t2. Them cuoi";
				cout << "\n\t3. Them giua";
				cout << "\n\tLua chon cua ban: ";
				int selectInsert;
				cin >> selectInsert;

				//Them dau
				if (selectInsert == 1)
				{
					system("cls");
					InsertX(a, dem, val, 0);
					x_show -= 180;
					showInsert(dem, x_show, y, i, j, x_gh, h, a, 0);
					dem++;
					break;
				}

				//Them cuoi
				else if (selectInsert == 2)
				{
					system("cls");
					InsertX(a, dem, val, dem);
					x_gh += 180;
					showInsert(dem, x_show, y, i, j, x_gh, h, a, dem);
					dem++;
					break;
				}

				//Them giua
				else if (selectInsert == 3)
				{
					cout << "\n\tNhap vi tri muon them: ";
					int index;
					cin >> index;
					if (index < 0) index = 0;
					if (index > dem) index = dem;
					system("cls");

					if (index < dem / 2)
					{
						system("cls");
						InsertX(a, dem, val, index);
						x_show -= 180;
					}

					else
					{
						system("cls");
						InsertX(a, dem, val, index);
						x_gh += 180;
					}

					showInsert(dem, x_show, y, i, j, x_gh, h, a, index);
					dem++;
					break;
				}

				else cout << "\n\tVui long nhap lai!" << endl;
			}
		}

		else if (select == 2)
		{
			if (dem == 0) drawNoti(1260, y, "CHUA CO PHAN TU NAO TRONG DANH SACH");
			else
			{
				while (true)
				{
					cout << "\n\t1. Xoa dau";
					cout << "\n\t2. Xoa cuoi";
					cout << "\n\t3. Xoa giua";
					cout << "\n\tLua chon cua ban: ";
					int selectDelete;
					cin >> selectDelete;

					//Xoa dau
					if (selectDelete == 1)
					{
						system("cls");
						DeleteX(a, dem, 0);
						x_show += 180;
						dem--;
						showDelete(dem - 1, x_show, y, i, j, x_gh, h, a);
						break;
					}

					//Xoa cuoi
					else if (selectDelete == 2)
					{
						system("cls");
						DeleteX(a, dem, dem);
						x_gh -= 180;
						dem--;
						showDelete(dem - 1, x_show, y, i, j, x_gh, h, a);
						break;
					}

					//Xoa giua
					else if (selectDelete == 3)
					{
						cout << "\n\tNhap vi tri muon xoa: ";
						int index;
						cin >> index;
						if (index < 0) index = 0;
						if (index > dem) index = dem;
						system("cls");

						if (index < dem / 2)
						{
							system("cls");
							DeleteX(a, dem, index);
							x_show += 180;
						}

						else
						{
							system("cls");
							DeleteX(a, dem, index);
							x_gh -= 180;
						}

						dem--;
						showDelete(dem - 1, x_show, y, i, j, x_gh, h, a);
						break;
					}

					else cout << "\n\tVui long nhap lai!" << endl;
				}
			}
		}

		else if (select == 3)
		{
			system("cls");
			drawNoti(1275, y, "KET THUC CHUONG TRINH MO PHONG");
			break;
		}
		else cout << "\n\tVui long nhap lai!" << endl;
	}

	return 0;
}