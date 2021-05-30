/*
  Problem Name:关押罪犯
  algorithm tag:并查集,扩展域或边带权,二分,染色法判断二分图
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

const int N = 2e4, M = 2e5 + 5;
int n, m;
int h[N], e[M], ne[M], w[M], idx;
int color[N];

void add(int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

bool dfs(int u, int c, int mid)
{
    color[u] = c;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (w[i] <= mid)
            continue;
        if (color[j]) {
            if (color[j] == c)
                return false;
        } else if (!dfs(j, 3 - c, mid))
            return false;
    }

    return true;
}

bool check(int mid)
{
    memset(color, 0, sizeof color);
    for (int i = 1; i <= n; i++)
        if (!color[i])
            if (!dfs(i, 1, mid))
                return false;
    return true;
}
int main()
{
    iosf;
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }

    int l = 0, r = 1e9;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << r << endl;
}