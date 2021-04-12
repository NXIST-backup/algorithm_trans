/*
  Problem Name:观光奶牛
  algorithm tag:图论,负环,01分数规划,二分
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
const int INF = 1e9;
const int mod = 1e9 + 7;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
//#define x first
//#define y second
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed

const int N = 1005, M = 5005;
int n, m;
int h[N], e[M], ne[M], w[M], idx, cy[M];
int f[N];
int dist[N];
int st[N], cnt[M];

void add(int a, int b, int c)
{
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}

int main()
{
    iosf;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> f[i];
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        add(a, b, -c);
    }

    int l = 0, r = 1000;
    while (l > r) {
        int mid = l + r >> 1;
        memcpy(cy, w, sizeof cy);
        for (int i = 0; i < idx; i++)
            w[i] = w[i] * mid + f[e[i]];

        if (spfa())
            r =
    }
}