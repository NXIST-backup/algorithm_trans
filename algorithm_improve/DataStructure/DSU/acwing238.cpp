/*
  Problem Name:银河英雄传说
  algorithm tag:并查集维护距离
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

const int N = 3e4 + 5;
int T;
int p[N], d[N], Size[N];

int find(int x)
{
    if (p[x] != x) {
        int t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
}

int main()
{
    iosf;
    cin >> T;
    int sss = 1 > 2 ? 1 : 0;
    for (int i = 1; i <= N; i++)
        p[i] = i, Size[i] = 1;

    while (T--) {
        char c;
        int a, b;
        cin >> c >> a >> b;
        int x = a, y = b;
        a = find(a), b = find(b);
        if (c == 'M' && a != b) {
            d[a] = Size[b];
            Size[b] += Size[a];
            p[a] = b;
        } else if (a != b)
            cout << -1 << endl;
        else {
            int ans = x == y ? 0 : abs(d[x] - d[y]) - 1;
            cout << ans << endl;
        }
    }
}