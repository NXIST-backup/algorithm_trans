/*
  Problem Name:机器任务
  algorithm tag:图论,二分图,最小点覆盖,匈牙利算法
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

const int N = 105;
int n, m, k;
int g[N][N];
int st[N];
int match[N];

bool find(int u)
{
    for (int i = 1; i < m; i++) {
        if (g[u][i] && !st[i]) {
            st[i] = true;
            int t = match[i];
            if (t == 0 || find(t)) {
                match[i] = u;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    iosf;
    while (cin >> n, n) {
        cin >> m >> k;
        memset(g, 0, sizeof g);
        memset(match, 0, sizeof match);
        for (int i = 1; i <= k; i++) {
            int t, a, b;
            cin >> t >> a >> b;
            if (!a || !b)
                continue;
            g[a][b] = 1;
        }
        int res = 0;
        for (int i = 1; i < n; i++) {
            memset(st, 0, sizeof st);
            if (find(i))
                res++;
        }
        cout << res << endl;
    }
    return 0;
}