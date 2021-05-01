/*
  Problem Name:Graph Smoothing
  algorithm tag:矩阵快速幂
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-4;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
//#define x first
//#define y second
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed

const int N = 110;

typedef long long ll;

int n;

struct Matrix
{
    int a[N][N];
    Matrix() { memset(a, 0, sizeof(a)); }
    int *operator[](int x)
    {
        return a[x];
    }
    Matrix operator*(Matrix b)
    {
        Matrix res;
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    res[i][j] = (res[i][j] + (ll)a[i][k] * b[k][j]) % mod;
        return res;
    }
} E;

Matrix Pow(Matrix x, int y)
{
    Matrix res = E;
    for (; y; y >>= 1, x = x * x)
        if (y & 1)
            res = res * x;
    return res;
}

int Pow(int x, int y)
{
    int res = 1;
    for (; y; y >>= 1, x = (ll)x * x % mod)
        if (y & 1)
            res = (ll)res * x % mod;
    return res;
}

int ind[N], A[N];

int main()
{
    int m, k;
    scanf("%d%d%d", &n, &m, &k);
    int inv = Pow(2 * m, mod - 2);
    for (int i = 1; i <= n; i++)
        scanf("%d", &A[i]);
    for (int i = 1; i <= n; i++)
        E[i][i] = 1;
    Matrix base;
    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d%d", &a, &b), ind[a]++, ind[b]++;
        base[a][a] = base[b][b] = base[a][b] = base[b][a] = inv;
    }
    for (int a = 1; a <= n; a++) {
        base[a][a] = (ll)(2 * m - ind[a]) * inv % mod;
    }
    base = Pow(base, k);
    for (int i = 1; i <= n; i++) {
        int res = 0;
        for (int j = 1; j <= n; j++)
            res = (res + (ll)A[j] * base[j][i]) % mod;
        printf("%d\n", res);
    }
}