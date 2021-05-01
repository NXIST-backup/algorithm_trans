#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long LL;

const int N = 3;

int n, m;

void mul(int c[], int a[], int b[][N])
{
    int temp[N] = {0};
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            temp[i] = (temp[i] + (LL)a[j] * b[j][i]) % m;

    memcpy(c, temp, sizeof temp);
}

void mul(int c[][N], int a[][N], int b[][N])
{
    int temp[N][N] = {0};
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                temp[i][j] = (temp[i][j] + (LL)a[i][k] * b[k][j]) % m;

    memcpy(c, temp, sizeof temp);
}

int main()
{
    cin >> n >> m;

    int f1[N] = {1, 1, 1};
    int a[N][N] = {
        {0, 1, 0},
        {1, 1, 1},
        {0, 0, 1}};
    int e[N][N];
    for (int i = 0; i < 3; i++)
        e[i][i] = 1;
    n--;
    while (n) {
        if (n & 1)
            mul(f1, f1, a); // res = res * a
        mul(a, a, a);       // a = a * a
        n >>= 1;
    }

    cout << f1[2] << endl;

    return 0;
}
