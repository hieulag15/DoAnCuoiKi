#include "graphics.h"
#include<iostream>
#include<windows.h>
#include<conio.h>
#include <sstream>
#include <string.h>

using namespace std;

struct NODE
{
	int SUC;
	NODE* NEXT;

	NODE()
	{
		SUC = 0;
		NEXT = NULL;
	}
};

int n;
int COUNT[100 + 1] = { 0 };
int QLINK[100 + 1] = { 0 };
NODE* TOP[100 + 1] = { NULL };
int soluong;
int ngang = 100;
int doc = 200;
int con1 = 1;
int doc1 = 60;
int R = 0;
int F = QLINK[0];
int KQ[100] = { 0 };
int valueKQ = 1;



void khoiTao()
{
	drawText(200, 220, "COUNT[k]");
	drawText(215, 280, "TOP[k]");
	drawText(215, 420, "SUC");
	drawText(210, 500, "NEXT");
	drawText(250, 175, "K");
	for (int i = 1; i <= n; i++)
	{
		string chu = to_string(COUNT[i]);
		char const* pchar = chu.c_str();
		frame(200 + i * ngang, 200, 60, 60, pchar, 15);
		frameLK(200 + i * ngang, 260, 60, 60, 15);
		string chu1 = to_string(i);
		char const* pchar1 = chu1.c_str();
		drawText(220 + i * ngang, 175, pchar1);
		NODE* tmp = TOP[i];
		int con1 = 1;
		while (tmp != NULL)
		{
			string chu = to_string(tmp->SUC);
			char const* pchar = chu.c_str();
			frame(200 + i * ngang, 200 + con1 * doc, 60, 60, pchar, 15);
			frameLK(200 + i * ngang, 260 + con1 * doc, 60, 60, 15);
			con1++;
			tmp = tmp->NEXT;
		}
	}
}

void khoiTaoQLink()
{
	for (int i = 1; i <= n; i++)
	{
		string chu = "QLINK[" + to_string(i) + "]";
		char const* pchar = chu.c_str();
		frame(220 + (n + 3) * ngang, 140 + doc1 * (i + 1), 100, 60, pchar, 15);
		string valueQLINK = to_string(QLINK[i]);
		char const* vlQLINK = valueQLINK.c_str();
		frame(320 + (n + 3) * ngang, 140 + doc1 * (i + 1), 60, 60, vlQLINK, 15);
	}
	string chuQL0 = "QLINK[" + to_string(0) + "]";
	char const* chQL0 = chuQL0.c_str();
	frame(220 + (n + 3) * ngang, 140 + doc1, 100, 60, chQL0, 15);
	string valueQLINK0 = to_string(QLINK[0]);
	char const* vlQLINK0 = valueQLINK0.c_str();
	frame(320 + (n + 3) * ngang, 140 + doc1, 60, 60, vlQLINK0, 15);
}

void nhapJvaK()
{
	for (int i = 1; i <= soluong; i++)
	{
		int j, k;
		cin >> j >> k;
		system("cls");
		setfontcolor(3);
		outtextxy(230, 80, "NHAP NEXT RELATION");
		setfontcolor(3);
		setfontcolor(8);
		outtextxy(230, 95, "INCREASE COUNT[K] BY ONE");
		outtextxy(230, 100, "P = AVALI, P->SUC = K, P->NEXT = TOP[J], TOP[J] = P");
		setfontcolor(8);
		string chJ = to_string(j);
		char const* chuJ = chJ.c_str();
		frame(660, 30, 60, 60, "J", 15);
		string chK = to_string(k);
		char const* chuK = chK.c_str();
		frame(660, 100, 60, 60, "K", 15);
		frame(720, 30, 60, 60, chuJ, 8);
		frame(720, 100, 60, 60, chuK, 8);
		khoiTao();

		Sleep(1000);
		system("cls");

		COUNT[k]++;
		setfontcolor(3);
		outtextxy(230, 95, "INCREASE COUNT[K] BY ONE");
		setfontcolor(3);
		setfontcolor(8);
		outtextxy(230, 80, "NHAP NEXT RELATION");
		outtextxy(230, 100, "P = AVALI, P->SUC = K, P->NEXT = TOP[J], TOP[J] = P");
		setfontcolor(8);
		frame(660, 30, 60, 60, "J", 15);
		frame(660, 100, 60, 60, "K", 15);
		frame(720, 30, 60, 60, chuJ, 8);
		frame(720, 100, 60, 60, chuK, 8);
		drawText(200, 220, "COUNT[k]");
		drawText(215, 280, "TOP[k]");
		drawText(215, 420, "SUC");
		drawText(210, 500, "NEXT");
		drawText(250, 175, "K");
		for (int i = 1; i <= n; i++)
		{
			string chu = to_string(i);
			char const* pchar = chu.c_str();
			drawText(220 + i * ngang, 175, pchar);
		}
		for (int i = 1; i <= n; i++)
		{
			if (i != k)
			{
				string chu = to_string(COUNT[i]);
				char const* pchar = chu.c_str();
				frame(200 + i * ngang, 200, 60, 60, pchar, 15);
				frameLK(200 + i * ngang, 260, 60, 60, 15);
			}
			NODE* tmp = TOP[i];
			int con1 = 1;
			while (tmp != NULL)
			{
				string chu = to_string(tmp->SUC);
				char const* pchar = chu.c_str();
				frame(200 + i * ngang, 200 + con1 * doc, 60, 60, pchar, 15);
				frameLK(200 + i * ngang, 260 + con1 * doc, 60, 60, 15);
				con1++;
				tmp = tmp->NEXT;
			}
		}
		string chu = to_string(COUNT[k]);
		char const* pchar = chu.c_str();
		frame(200 + k * ngang, 200, 60, 60, pchar, 8);
		frameLK(200 + k * ngang, 260, 60, 60, 8);
		Sleep(1000);
		frame(200 + k * ngang, 200, 60, 60, pchar, 15);
		frameLK(200 + k * ngang, 260, 60, 60, 15);

		setfontcolor(8);
		outtextxy(230, 95, "INCREASE COUNT[K] BY ONE");
		setfontcolor(8);
		setfontcolor(3);
		outtextxy(230, 100, "P = AVALI, P->SUC = K, P->NEXT = TOP[J], TOP[J] = P");
		setfontcolor(3);
		Sleep(1000);
		NODE* P = new NODE();
		P->SUC = k;
		P->NEXT = TOP[j];
		if (TOP[j] == NULL)
		{
			string chu = to_string(k);
			char const* pchar = chu.c_str();
			frame(200 + j * ngang, 400, 60, 60, pchar, 8);
			frameLK(200 + j * ngang, 460, 60, 60, 8);
			Sleep(1000);
			frame(200 + j * ngang, 400, 60, 60, pchar, 15);
			frameLK(200 + j * ngang, 460, 60, 60, 15);
		}
		else
		{
			system("cls");
			setfontcolor(8);
			outtextxy(230, 80, "NHAP NEXT RELATION");
			outtextxy(230, 95, "INCREASE COUNT[K] BY ONE");
			setfontcolor(8);
			setfontcolor(3);
			outtextxy(230, 100, "P = AVALI, P->SUC = K, P->NEXT = TOP[J], TOP[J] = P");
			setfontcolor(3);
			frame(660, 30, 60, 60, "J", 15);
			frame(660, 100, 60, 60, "K", 15);
			frame(720, 30, 60, 60, chuJ, 8);
			frame(720, 100, 60, 60, chuK, 8);
			drawText(200, 220, "COUNT[k]");
			drawText(215, 280, "TOP[k]");
			drawText(215, 420, "SUC");
			drawText(210, 500, "NEXT");
			drawText(250, 175, "K");
			for (int i = 1; i <= n; i++)
			{
				string chu1 = to_string(COUNT[i]);
				char const* pchar1 = chu1.c_str();
				frame(200 + i * ngang, 200, 60, 60, pchar1, 15);
				frameLK(200 + i * ngang, 260, 60, 60, 15);
				string chu = to_string(i);
				char const* pchar = chu.c_str();
				drawText(220 + i * ngang, 175, pchar);
				if (i != j)
				{
					NODE* tmp = TOP[i];
					con1 = 1;
					while (tmp != NULL)
					{
						string chu = to_string(tmp->SUC);
						char const* pchar = chu.c_str();
						frame(200 + i * ngang, 200 + con1 * doc, 60, 60, pchar, 15);
						frameLK(200 + i * ngang, 260 + con1 * doc, 60, 60, 15);
						con1++;
						tmp = tmp->NEXT;
					}
				}
				else
				{
					NODE* tmp = TOP[i];
					con1 = 2;
					while (tmp != NULL)
					{
						string chu = to_string(tmp->SUC);
						char const* pchar = chu.c_str();
						frame(200 + i * ngang, 200 + con1 * doc, 60, 60, pchar, 15);
						frameLK(200 + i * ngang, 260 + con1 * doc, 60, 60, 15);
						con1++;
						tmp = tmp->NEXT;
					}
				}
			}
			Sleep(1000);
			string chu = to_string(k);
			char const* pchar = chu.c_str();
			frame(200 + j * ngang, 400, 60, 60, pchar, 8);
			frameLK(200 + j * ngang, 460, 60, 60, 8);
			Sleep(1000);
			frame(200 + j * ngang, 400, 60, 60, pchar, 15);
			frameLK(200 + j * ngang, 460, 60, 60, 15);
		}
		Sleep(1000);
		frame(660, 30, 60, 60, "J", 15);
		frame(660, 100, 60, 60, "K", 15);
		frame(720, 30, 60, 60, chuJ, 15);
		frame(720, 100, 60, 60, chuK, 15);
		Sleep(1000);
		TOP[j] = P;
	}
	Sleep(1000);
}

void buocBon()
{
	system("cls");
	setfontcolor(3);
	outtextxy(230, 80, "SET R = 0, QLINK[0] = 0");
	setfontcolor(3);
	setfontcolor(8);
	outtextxy(230, 95, "KIEM TRA COUNT[K] = 0 THI QLINK[R] = K, R = K (1 <= K <= N)");
	outtextxy(230, 100, "SAU KHI HOANG THANG TAT CA THI SET F = QLINK[0]");
	setfontcolor(8);
	khoiTao();
	string chuR = to_string(R);
	char const* chR = chuR.c_str();
	frame(200 + (n + 1.5) * ngang, 200, 60, 60, "R", 8);
	frame(210 + (n + 2) * ngang, 200, 60, 60, chR, 8);
	QLINK[0] = 0;
	khoiTaoQLink();
	Sleep(1000);
	frame(200 + (n + 1.5) * ngang, 200, 60, 60, "R", 15);
	frame(210 + (n + 2) * ngang, 200, 60, 60, chR, 15);

	Sleep(1000);

	for (int i = 1; i <= n; i++)
	{
		if (COUNT[i] == 0)
		{
			setfontcolor(8);
			outtextxy(230, 80, "SET R = 0, QLINK[0] = 0");
			setfontcolor(8);
			setfontcolor(3);
			outtextxy(230, 95, "KIEM TRA COUNT[K] = 0 THI QLINK[R] = K, R = K (1 <= K <= N)");
			setfontcolor(3);
			string chu1 = to_string(COUNT[i]);
			char const* pchar1 = chu1.c_str();
			frame(200 + i * ngang, 200, 60, 60, pchar1, 8);
			Sleep(1000);
			frame(200 + i * ngang, 200, 60, 60, pchar1, 15);
			QLINK[R] = i;
			Sleep(1000);
			system("cls");
			setfontcolor(3);
			outtextxy(230, 95, "KIEM TRA COUNT[K] = 0 THI QLINK[R] = K, R = K (1 <= K <= N)");
			setfontcolor(3);
			setfontcolor(8);
			outtextxy(230, 80, "SET R = 0, QLINK[0] = 0");
			outtextxy(230, 100, "SAU KHI HOANG THANG TAT CA THI SET F = QLINK[0]");
			setfontcolor(8);
			khoiTao();
			string chuR = to_string(R);
			char const* chR = chuR.c_str();
			frame(200 + (n + 1.5) * ngang, 200, 60, 60, "R", 15);
			frame(210 + (n + 2) * ngang, 200, 60, 60, chR, 15);
			for (int i = 0; i <= n; i++)
			{
				if (i != R)
				{
					string chu = "QLINK[" + to_string(i) + "]";
					char const* pchar = chu.c_str();
					frame(220 + (n + 3) * ngang, 140 + doc1 * (i + 1), 100, 60, pchar, 15);
					string valueQLINK = to_string(QLINK[i]);
					char const* vlQLINK = valueQLINK.c_str();
					frame(320 + (n + 3) * ngang, 140 + doc1 * (i + 1), 60, 60, vlQLINK, 15);
				}
			}
			string chu = "QLINK[" + to_string(R) + "]";
			char const* pchar = chu.c_str();
			frame(220 + (n + 3) * ngang, 140 + doc1 * (R + 1), 100, 60, pchar, 8);
			string valueQLINK = to_string(QLINK[R]);
			char const* vlQLINK = valueQLINK.c_str();
			frame(320 + (n + 3) * ngang, 140 + doc1 * (R + 1), 60, 60, vlQLINK, 8);
			Sleep(1000);
			frame(220 + (n + 3) * ngang, 140 + doc1 * (R + 1), 100, 60, pchar, 15);
			frame(320 + (n + 3) * ngang, 140 + doc1 * (R + 1), 60, 60, vlQLINK, 15);
			Sleep(1000);
			system("cls");
			setfontcolor(3);
			outtextxy(230, 95, "KIEM TRA COUNT[K] = 0 THI QLINK[R] = K, R = K (1 <= K <= N)");
			setfontcolor(3);
			setfontcolor(8);
			outtextxy(230, 80, "SET R = 0, QLINK[0] = 0");
			outtextxy(230, 100, "SAU KHI HOANG THANG TAT CA THI SET F = QLINK[0]");
			setfontcolor(8);
			khoiTao();
			khoiTaoQLink();
			R = i;
			chuR = to_string(R);
			chR = chuR.c_str();
			frame(200 + (n + 1.5) * ngang, 200, 60, 60, "R", 8);
			frame(210 + (n + 2) * ngang, 200, 60, 60, chR, 8);
			Sleep(1000);
			frame(200 + (n + 1.5) * ngang, 200, 60, 60, "R", 15);
			frame(210 + (n + 2) * ngang, 200, 60, 60, chR, 15);
			Sleep(1000);
		}
	}
}

void khoiTaoFRNKQ(int N)
{
	string chuR = to_string(R);
	char const* chR = chuR.c_str();
	string chuF = to_string(F);
	char const* chF = chuF.c_str();
	string chuN = to_string(N);
	char const* chN = chuN.c_str();
	frame(200 + (n + 1.5) * ngang, 200, 60, 60, "R", 15);
	frame(210 + (n + 2) * ngang, 200, 60, 60, chR, 15);
	frame(200 + (n + 1.5) * ngang, 300, 60, 60, "F", 15);
	frame(210 + (n + 2) * ngang, 300, 60, 60, chF, 15);
	frame(200 + (n + 1.5) * ngang, 400, 60, 60, "N", 15);
	frame(210 + (n + 2) * ngang, 400, 60, 60, chN, 15);
	frame(100 + (n + 3) * ngang, 140 + (n + 3) * 60, 60, 60, "KQ:", 15);
}

void xuatKq()
{
	for (int i = 1; i < valueKQ; i++)
	{
		string chuKQ = to_string(KQ[i]);
		char const* chKQ = chuKQ.c_str();
		frame(100 + (n + 3) * ngang + (60 * i), 200 + (n + 2) * 60, 60, 60, chKQ, 15);
	}
}

void xuLiCuoiCung(int N)
{
	F = QLINK[0];
	setfontcolor(3);
	outtextxy(230, 100, "SAU KHI HOANG THANG TAT CA THI SET F = QLINK[0]");
	setfontcolor(3);
	setfontcolor(8);
	outtextxy(230, 80, "SET R = 0, QLINK[0] = 0");
	outtextxy(230, 95, "KIEM TRA COUNT[K] = 0 THI QLINK[R] = K, R = K (1 <= K <= N)");
	setfontcolor(8);
	string chuF = to_string(F);
	char const* chF = chuF.c_str();
	frame(200 + (n + 1.5) * ngang, 300, 60, 60, "F", 8);
	frame(210 + (n + 2) * ngang, 300, 60, 60, chF, 8);
	Sleep(1000);
	frame(200 + (n + 1.5) * ngang, 300, 60, 60, "F", 15);
	frame(210 + (n + 2) * ngang, 300, 60, 60, chF, 15);

	string chuN = to_string(N);
	char const* chN = chuN.c_str();
	frame(200 + (n + 1.5) * ngang, 400, 60, 60, "N", 15);
	frame(210 + (n + 2) * ngang, 400, 60, 60, chN, 15);
	frame(100 + (n + 3) * ngang, 140 + (n + 3) * 60, 60, 60, "KQ:", 15);
	Sleep(1000);
	system("cls");
	setfontcolor(8);
	outtextxy(230, 50, "B5. XUAT F, NEU F = 0 THI TOI B8, KHONG THI N = N - 1, P = TOP[F]");
	outtextxy(230, 65, "B6. NEU P = RONG THI TOI B7, KHONG THI DECREASE COUNT[P->SUC] 1 DON VI");
	outtextxy(230, 80, "NEU COUNT[P->SUC] = 0 THI QLINK[R] = P->SUC, R = P->SUC. P = P->NEXT LAP LAI Y TREN");
	outtextxy(230, 90, "B7. SET F = QLINK[F] TRO VE B5");
	outtextxy(230, 100, "B8. NEU N = 0 THI KET THUC CHUONG TRINH");
	setfontcolor(8);
	khoiTao();
	khoiTaoQLink();
	khoiTaoFRNKQ(N);
	
	while (N != 0)
	{
		while (F != 0)
		{
			system("cls");
			setfontcolor(3);
			outtextxy(230, 50, "B5. XUAT F, NEU F = 0 THI TOI B8, KHONG THI N = N - 1, P = TOP[F]");
			setfontcolor(3);
			setfontcolor(8);
			outtextxy(230, 65, "B6. NEU P = RONG THI TOI B7, KHONG THI DECREASE COUNT[P->SUC] 1 DON VI");
			outtextxy(230, 80, "NEU COUNT[P->SUC] = 0 THI QLINK[R] = P->SUC, R = P->SUC. P = P->NEXT LAP LAI Y TREN");
			outtextxy(230, 90, "B7. SET F = QLINK[F] TRO VE B5");
			outtextxy(230, 100, "B8. NEU N = 0 THI KET THUC CHUONG TRINH");
			setfontcolor(8);
			khoiTao();
			khoiTaoQLink();
			string chuR = to_string(R);
			char const* chR = chuR.c_str();
			chuF = to_string(F);
			chF = chuF.c_str();
			frame(200 + (n + 1.5) * ngang, 200, 60, 60, "R", 15);
			frame(210 + (n + 2) * ngang, 200, 60, 60, chR, 15);
			frame(200 + (n + 1.5) * ngang, 300, 60, 60, "F", 8);
			frame(210 + (n + 2) * ngang, 300, 60, 60, chF, 8);
			frame(200 + (n + 1.5) * ngang, 400, 60, 60, "N", 15);
			frame(210 + (n + 2) * ngang, 400, 60, 60, chN, 15);
			frame(100 + (n + 3) * ngang, 140 + (n + 3) * 60, 60, 60, "KQ:", 15);
			xuatKq();
			KQ[valueKQ] = F;
			string chuKQ = to_string(KQ[valueKQ]);
			char const* chKQ = chuKQ.c_str();
			frame(100 + (n + 3) * ngang + (60 * valueKQ), 200 + (n + 2) * 60, 60, 60, chKQ, 8);
			Sleep(1000);
			frame(100 + (n + 3) * ngang + (60 * valueKQ), 200 + (n + 2) * 60, 60, 60, chKQ, 15);
			Sleep(1000);
			frame(200 + (n + 1.5) * ngang, 300, 60, 60, "F", 15);
			frame(210 + (n + 2) * ngang, 300, 60, 60, chF, 15);
			valueKQ++;
			N = N - 1;
			Sleep(1000);
			system("cls");
			setfontcolor(3);
			outtextxy(230, 50, "B5. XUAT F, NEU F = 0 THI TOI B8, KHONG THI N = N - 1, P = TOP[F]");
			setfontcolor(3);
			setfontcolor(8);
			outtextxy(230, 65, "B6. NEU P = RONG THI TOI B7, KHONG THI DECREASE COUNT[P->SUC] 1 DON VI");
			outtextxy(230, 80, "NEU COUNT[P->SUC] = 0 THI QLINK[R] = P->SUC, R = P->SUC. P = P->NEXT LAP LAI Y TREN");
			outtextxy(230, 90, "B7. SET F = QLINK[F] TRO VE B5");
			outtextxy(230, 100, "B8. NEU N = 0 THI KET THUC CHUONG TRINH");
			setfontcolor(8);
			khoiTao();
			khoiTaoQLink();
			chuR = to_string(R);
			chR = chuR.c_str();
			chuN = to_string(N);
			chN = chuN.c_str();
			chuF = to_string(F);
			chF = chuF.c_str();
			frame(200 + (n + 1.5) * ngang, 200, 60, 60, "R", 15);
			frame(210 + (n + 2) * ngang, 200, 60, 60, chR, 15);
			frame(200 + (n + 1.5) * ngang, 300, 60, 60, "F", 15);
			frame(210 + (n + 2) * ngang, 300, 60, 60, chF, 15);
			frame(200 + (n + 1.5) * ngang, 400, 60, 60, "N", 8);
			frame(210 + (n + 2) * ngang, 400, 60, 60, chN, 8);
			frame(100 + (n + 3) * ngang, 140 + (n + 3) * 60, 60, 60, "KQ:", 15);
			xuatKq();
			Sleep(1000);
			frame(200 + (n + 1.5) * ngang, 400, 60, 60, "N", 15);
			frame(210 + (n + 2) * ngang, 400, 60, 60, chN, 15);
			Sleep(1000);
			int con1 = 1;
			NODE* P1 = TOP[F];
			while (P1 != NULL)
			{
				Sleep(1000);
				system("cls");
				setfontcolor(3);
				outtextxy(230, 65, "B6. NEU P = RONG THI TOI B7, KHONG THI DECREASE COUNT[P->SUC] 1 DON VI");
				outtextxy(230, 80, "NEU COUNT[P->SUC] = 0 THI QLINK[R] = P->SUC, R = P->SUC. P = P->NEXT LAP LAI Y TREN");
				setfontcolor(3);
				setfontcolor(8);
				outtextxy(230, 50, "B5. XUAT F, NEU F = 0 THI TOI B8, KHONG THI N = N - 1, P = TOP[F]");
				outtextxy(230, 90, "B7. SET F = QLINK[F] TRO VE B5");
				outtextxy(230, 100, "B8. NEU N = 0 THI KET THUC CHUONG TRINH");
				setfontcolor(8);
				drawText(200, 220, "COUNT[k]");
				drawText(215, 280, "TOP[k]");
				drawText(215, 420, "SUC");
				drawText(210, 500, "NEXT");
				drawText(250, 175, "K");
				COUNT[P1->SUC]--;
				for (int i = 1; i <= n; i++)
				{
					if (i != P1->SUC)
					{
						string chu1 = to_string(COUNT[i]);
						char const* pchar1 = chu1.c_str();
						frame(200 + i * ngang, 200, 60, 60, pchar1, 15);
						frameLK(200 + i * ngang, 260, 60, 60, 15);
						string chu = to_string(i);
						char const* pchar = chu.c_str();
						drawText(220 + i * ngang, 175, pchar);
					}
					NODE* tmp = TOP[i];
					int con1 = 1;
					while (tmp != NULL)
					{
						string chu = to_string(tmp->SUC);
						char const* pchar = chu.c_str();
						frame(200 + i * ngang, 200 + con1 * doc, 60, 60, pchar, 15);
						frameLK(200 + i * ngang, 260 + con1 * doc, 60, 60, 15);
						con1++;
						tmp = tmp->NEXT;
					}
				}
				khoiTaoQLink();
				khoiTaoFRNKQ(N);
				xuatKq();
				string chu6 = to_string(P1->SUC);
				char const* pchar2 = chu6.c_str();
				frame(200 + F * ngang, 200 + con1 * doc, 60, 60, pchar2, 8);
				frameLK(200 + F * ngang, 260 + con1 * doc, 60, 60, 8);
				string chu1 = to_string(COUNT[P1->SUC]);
				char const* pchar1 = chu1.c_str();
				frame(200 + P1->SUC * ngang, 200, 60, 60, pchar1, 8);
				frameLK(200 + P1->SUC * ngang, 260, 60, 60, 8);
				string chu = to_string(P1->SUC);
				char const* pchar = chu.c_str();
				drawText(220 + P1->SUC * ngang, 175, pchar);
				Sleep(1000);
				if (COUNT[P1->SUC] == 0)
				{
					system("cls");
					setfontcolor(3);
					outtextxy(230, 65, "B6. NEU P = RONG THI TOI B7, KHONG THI DECREASE COUNT[P->SUC] 1 DON VI");
					outtextxy(230, 80, "NEU COUNT[P->SUC] = 0 THI QLINK[R] = P->SUC, R = P->SUC. P = P->NEXT LAP LAI Y TREN");
					setfontcolor(3);
					setfontcolor(8);
					outtextxy(230, 50, "B5. XUAT F, NEU F = 0 THI TOI B8, KHONG THI N = N - 1, P = TOP[F]");
					outtextxy(230, 90, "B7. SET F = QLINK[F] TRO VE B5");
					outtextxy(230, 100, "B8. NEU N = 0 THI KET THUC CHUONG TRINH");
					setfontcolor(8);
					drawText(200, 220, "COUNT[k]");
					drawText(215, 280, "TOP[k]");
					drawText(215, 420, "SUC");
					drawText(210, 500, "NEXT");
					drawText(250, 175, "K");
					for (int i = 1; i <= n; i++)
					{
						if (i != P1->SUC)
						{
							string chu1 = to_string(COUNT[i]);
							char const* pchar1 = chu1.c_str();
							frame(200 + i * ngang, 200, 60, 60, pchar1, 15);
							frameLK(200 + i * ngang, 260, 60, 60, 15);
							string chu = to_string(i);
							char const* pchar = chu.c_str();
							drawText(220 + i * ngang, 175, pchar);
						}
						NODE* tmp = TOP[i];
						int con1 = 1;
						while (tmp != NULL)
						{
							string chu = to_string(tmp->SUC);
							char const* pchar = chu.c_str();
							frame(200 + i * ngang, 200 + con1 * doc, 60, 60, pchar, 15);
							frameLK(200 + i * ngang, 260 + con1 * doc, 60, 60, 15);
							con1++;
							tmp = tmp->NEXT;
						}
					}
					QLINK[R] = P1->SUC;
					for (int i = 0; i <= n; i++)
					{
						if (i != R)
						{
							string chu = "QLINK[" + to_string(i) + "]";
							char const* pchar = chu.c_str();
							frame(220 + (n + 3) * ngang, 140 + doc1 * (i + 1), 100, 60, pchar, 15);
							string valueQLINK = to_string(QLINK[i]);
							char const* vlQLINK = valueQLINK.c_str();
							frame(320 + (n + 3) * ngang, 140 + doc1 * (i + 1), 60, 60, vlQLINK, 15);
						}
					}
					khoiTaoFRNKQ(N);
					xuatKq();

					frame(200 + F * ngang, 200 + con1 * doc, 60, 60, pchar2, 8);
					frameLK(200 + F * ngang, 260 + con1 * doc, 60, 60, 8);

					frame(200 + P1->SUC * ngang, 200, 60, 60, pchar1, 8);
					frameLK(200 + P1->SUC * ngang, 260, 60, 60, 8);

					drawText(220 + P1->SUC * ngang, 175, pchar);

					string chu7 = "QLINK[" + to_string(R) + "]";
					char const* pchar7 = chu7.c_str();
					frame(220 + (n + 3) * ngang, 140 + doc1 * (R + 1), 100, 60, pchar7, 8);
					string valueQLINK3 = to_string(QLINK[R]);
					char const* vlQLINK = valueQLINK3.c_str();
					frame(320 + (n + 3) * ngang, 140 + doc1 * (R + 1), 60, 60, vlQLINK, 8);

					Sleep(1000);
					frame(220 + (n + 3) * ngang, 140 + doc1 * (R + 1), 100, 60, pchar7, 15);
					frame(320 + (n + 3) * ngang, 140 + doc1 * (R + 1), 60, 60, vlQLINK, 15);

					Sleep(1000);
					system("cls");
					R = P1->SUC;
					setfontcolor(3);
					outtextxy(230, 65, "B6. NEU P = RONG THI TOI B7, KHONG THI DECREASE COUNT[P->SUC] 1 DON VI");
					outtextxy(230, 80, "NEU COUNT[P->SUC] = 0 THI QLINK[R] = P->SUC, R = P->SUC. P = P->NEXT LAP LAI Y TREN");
					setfontcolor(3);
					setfontcolor(8);
					outtextxy(230, 50, "B5. XUAT F, NEU F = 0 THI TOI B8, KHONG THI N = N - 1, P = TOP[F]");
					outtextxy(230, 90, "B7. SET F = QLINK[F] TRO VE B5");
					outtextxy(230, 100, "B8. NEU N = 0 THI KET THUC CHUONG TRINH");
					setfontcolor(8);
					drawText(200, 220, "COUNT[k]");
					drawText(215, 280, "TOP[k]");
					drawText(215, 420, "SUC");
					drawText(210, 500, "NEXT");
					drawText(250, 175, "K");
					for (int i = 1; i <= n; i++)
					{
						if (i != P1->SUC)
						{
							string chu1 = to_string(COUNT[i]);
							char const* pchar1 = chu1.c_str();
							frame(200 + i * ngang, 200, 60, 60, pchar1, 15);
							frameLK(200 + i * ngang, 260, 60, 60, 15);
							string chu = to_string(i);
							char const* pchar = chu.c_str();
							drawText(220 + i * ngang, 175, pchar);
						}
						NODE* tmp = TOP[i];
						int con1 = 1;
						while (tmp != NULL)
						{
							string chu = to_string(tmp->SUC);
							char const* pchar = chu.c_str();
							frame(200 + i * ngang, 200 + con1 * doc, 60, 60, pchar, 15);
							frameLK(200 + i * ngang, 260 + con1 * doc, 60, 60, 15);
							con1++;
							tmp = tmp->NEXT;
						}
					}
					khoiTaoQLink();
					chuR = to_string(R);
					chR = chuR.c_str();
					frame(200 + (n + 1.5) * ngang, 200, 60, 60, "R", 8);
					frame(210 + (n + 2) * ngang, 200, 60, 60, chR, 8);
					frame(200 + (n + 1.5) * ngang, 300, 60, 60, "F", 15);
					frame(210 + (n + 2) * ngang, 300, 60, 60, chF, 15);
					frame(200 + (n + 1.5) * ngang, 400, 60, 60, "N", 15);
					frame(210 + (n + 2) * ngang, 400, 60, 60, chN, 15);
					frame(100 + (n + 3) * ngang, 140 + (n + 3) * 60, 60, 60, "KQ:", 15);
					xuatKq();
					string chu6 = to_string(P1->SUC);
					char const* pchar2 = chu6.c_str();
					frame(200 + F * ngang, 200 + con1 * doc, 60, 60, pchar2, 8);
					frameLK(200 + F * ngang, 260 + con1 * doc, 60, 60, 8);
					string chu1 = to_string(COUNT[P1->SUC]);
					char const* pchar1 = chu1.c_str();
					frame(200 + P1->SUC * ngang, 200, 60, 60, pchar1, 8);
					frameLK(200 + P1->SUC * ngang, 260, 60, 60, 8);
					string chu = to_string(P1->SUC);
					char const* pchar = chu.c_str();
					drawText(220 + P1->SUC * ngang, 175, pchar);

					Sleep(1000);
					frame(200 + (n + 1.5) * ngang, 200, 60, 60, "R", 15);
					frame(210 + (n + 2) * ngang, 200, 60, 60, chR, 15);
				}

				Sleep(1000);
				frame(200 + F * ngang, 200 + con1 * doc, 60, 60, pchar2, 15);
				frameLK(200 + F * ngang, 260 + con1 * doc, 60, 60, 15);
				frame(200 + P1->SUC * ngang, 200, 60, 60, pchar1, 15);
				frameLK(200 + P1->SUC * ngang, 260, 60, 60, 15);
				con1++;
				P1 = P1->NEXT;
			}
			int F2 = QLINK[F];
			F = F2;
			Sleep(1000);
			Sleep(1000);
			system("cls");
			setfontcolor(3);
			outtextxy(230, 90, "B7. SET F = QLINK[F] TRO VE B5");
			setfontcolor(3);
			setfontcolor(8);
			outtextxy(230, 50, "B5. XUAT F, NEU F = 0 THI TOI B8, KHONG THI N = N - 1, P = TOP[F]");
			outtextxy(230, 65, "B6. NEU P = RONG THI TOI B7, KHONG THI DECREASE COUNT[P->SUC] 1 DON VI");
			outtextxy(230, 80, "NEU COUNT[P->SUC] = 0 THI QLINK[R] = P->SUC, R = P->SUC. P = P->NEXT LAP LAI Y TREN");
			outtextxy(230, 100, "B8. NEU N = 0 THI KET THUC CHUONG TRINH");
			setfontcolor(8);
			khoiTao();
			khoiTaoQLink();
			chuR = to_string(R);
			chR = chuR.c_str();
			chuF = to_string(F);
			chF = chuF.c_str();
			frame(200 + (n + 1.5) * ngang, 200, 60, 60, "R", 15);
			frame(210 + (n + 2) * ngang, 200, 60, 60, chR, 15);
			frame(200 + (n + 1.5) * ngang, 300, 60, 60, "F", 8);
			frame(210 + (n + 2) * ngang, 300, 60, 60, chF, 8);
			frame(200 + (n + 1.5) * ngang, 400, 60, 60, "N", 15);
			frame(210 + (n + 2) * ngang, 400, 60, 60, chN, 15);
			frame(100 + (n + 3) * ngang, 140 + (n + 3) * 60, 60, 60, "KQ:", 15);
			xuatKq();
			Sleep(1000);
			frame(200 + (n + 1.5) * ngang, 300, 60, 60, "F", 15);
			frame(210 + (n + 2) * ngang, 300, 60, 60, chF, 15);
		}
	}
	Sleep(1000);
	system("cls");
	setfontcolor(3);
	outtextxy(230, 50, "B5. XUAT F, NEU F = 0 THI TOI B8, KHONG THI N = N - 1, P = TOP[F]");
	setfontcolor(3);
	setfontcolor(8);
	outtextxy(230, 65, "B6. NEU P = RONG THI TOI B7, KHONG THI DECREASE COUNT[P->SUC] 1 DON VI");
	outtextxy(230, 80, "NEU COUNT[P->SUC] = 0 THI QLINK[R] = P->SUC, R = P->SUC. P = P->NEXT LAP LAI Y TREN");
	outtextxy(230, 90, "B7. SET F = QLINK[F] TRO VE B5");
	outtextxy(230, 100, "B8. NEU N = 0 THI KET THUC CHUONG TRINH");
	setfontcolor(8);
	khoiTao();
	khoiTaoQLink();
	khoiTaoFRNKQ(N);
	xuatKq();

	Sleep(1000);
	system("cls");
	setfontcolor(3);
	outtextxy(230, 100, "B8. NEU N = 0 THI KET THUC CHUONG TRINH");
	setfontcolor(3);
	setfontcolor(8);
	outtextxy(230, 50, "B5. XUAT F, NEU F = 0 THI TOI B8, KHONG THI N = N - 1, P = TOP[F]");
	outtextxy(230, 65, "B6. NEU P = RONG THI TOI B7, KHONG THI DECREASE COUNT[P->SUC] 1 DON VI");
	outtextxy(230, 80, "NEU COUNT[P->SUC] = 0 THI QLINK[R] = P->SUC, R = P->SUC. P = P->NEXT LAP LAI Y TREN");
	outtextxy(230, 90, "B7. SET F = QLINK[F] TRO VE B5");
	setfontcolor(8);
	khoiTao();
	khoiTaoQLink();
	khoiTaoFRNKQ(N);
	xuatKq();
	Sleep(1000);
}


int main()
{
	char ini[] = "C:\\TURBOC3\\BGI";
	initgraph();
	cout << "Nhap so luong phan tu: ";
	cin >> n;
	int N = n;
	frame(200, 130, 400, 40, "SET TAT CA CAC COUNT = 0 VA TAT CA CAC TOP = NULL", 8);
	khoiTao();
	cout << "Nhap so luong cac moi quan he: ";
	cin >> soluong;
	nhapJvaK();
	buocBon();
	xuLiCuoiCung(N);

	return 0;
}