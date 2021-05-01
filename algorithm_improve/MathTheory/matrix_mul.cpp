/*
  Problem Name: 斐波那契前 n 项和 acwing1303
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

const int N = 3;
int n, m;

struct Matrix
{
    int a[N][N];
    Matrix() { memset(a, 0, sizeof a); };
    int *operator[](int x)
    {
        return a[x];
    }
    Matrix operator*(Matrix b)
    {
        Matrix res;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                for (int k = 0; k < N; k++)
                    res[i][j] = (res[i][j] + (ll)a[i][k] * b[k][j]) % m;
        return res;
    }
} E;

Matrix qmi(Matrix a, ll b)
{
    Matrix res = E;
    for (; b; b >>= 1, a = a * a)
        if (b & 1)
            res = res * a;
    return res;
}

int main()
{
    iosf;
    cin >> n >> m;

    for (int i = 0; i < N; i++)
        E[i][i] = 1;

    Matrix A;
    A[0][1] = A[1][0] = A[1][1] = A[1][2] = A[2][2] = 1;

    Matrix R = qmi(A, n - 1);
    int f[N] = {1, 1, 1};
    int f1[N] = {0, 0, 0};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            f1[i] = (f1[i] + (ll)f[i] * R[j][i]) % m;
        }
    }

    cout << f1[2] << endl;
}