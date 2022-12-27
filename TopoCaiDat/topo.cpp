#include<bits/stdc++.h>
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


int main()
{
    int n;
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    int N = n;
    int COUNT[n+1] = {0};
    int QLINK[n+1] = {0};
    NODE* TOP[n+1] = {NULL};
    cout << "Nhap so luong cac moi quan he: ";
    int count;  cin >> count;
    for (int i = 1; i <= count; i++)
    {
        int j, k;
        cin >> j >> k;
        COUNT[k]++;
        NODE* P = new NODE();
        P->SUC = k;
        P->NEXT = TOP[j];
        TOP[j] = P;
    }

    int R = 0;
    QLINK[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (COUNT[i] == 0)
        {
            QLINK[R] = i;
            R = i;
        }
    }
    int F = QLINK[0];

    while (N != 0)
    {
        while (F != 0)
        {
            cout << F << " ";
            N = N -1;
            NODE* P1 = TOP[F];
            while (P1 != NULL)
            {
                COUNT[P1->SUC]--;
                if (COUNT[P1->SUC] == 0)
                {
                    QLINK[R] = P1->SUC;
                    R = P1->SUC;
                }
                P1 = P1->NEXT;
            }
            int F2 = QLINK[F];
            F = F2;
        }
    }
    return 0;
}