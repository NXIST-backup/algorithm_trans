/*
  Problem Name:
  algorithm tag:
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

const int N = 2;
int x, y, A, m;

struct Matrix
{
    int a[N][N];
    Matrix() { memset(a, 0, sizeof a); }
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

Matrix Mqmi(Matrix a, ll b)
{
    Matrix res = E;
    for (; b; b >>= 1, a = a * a)
        if (b & 1)
            res = res * a;
    return res;
}

ll qmi(ll a, ll b, ll p)
{
    ll res = 1;
    for (; b; b >>= 1, a = a * a % p)
        if (b & 1)
            res = res * a % p;
    return res;
}
ll get_res(ll a, ll b)
{
    ll ans = a % (m * b);
    ll inv = qmi(b, mod - 2, mod);
    return inv * ans % mod;
}
int main()
{
    iosf;
    int _;
    cin >> _;
    for (int i = 0; i < N; i++)
        E[i][i] = 1;
    Matrix R;
    R[0][1] = R[1][0] = R[1][1] = 1;

    while (_--) {
        cin >> x >> y >> A >> m;
        Matrix X = Mqmi(R, x - 1);
        Matrix Y = Mqmi(R, y - 1);
        ll fx = 0, fy = 0;
        for (int i = 0; i < N; i++)
            fx = (fx + X[0][i]) % m, fy = (fy + Y[0][i]) % m;

        ll ansa = (qmi(A, fx, m) + m - 1) % m, ansb = (qmi(A, fy, m) + m - 1) % m;
        ll ans = ansa * ansb % m;

        ll gd = __gcd(ansa, ansb) % m;
        ans = get_res(ans, gd);
        ans = get_res(ans, gd);
        cout << ans << endl;
    }
}