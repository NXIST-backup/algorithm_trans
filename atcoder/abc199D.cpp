/*
  Problem Name: RGB Coloring 2 
  algorithm tag: 暴力
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

const int N = 25;
bool g[N][N];
int n, m;
bool st[N];
int num[N];
void dfs(int u, int fa)
{
    for (int i = 1; i <= n; i++) {
    }
}
int main()
{
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a][b] = g[b][a] = 1;
    }
    num[0] = 3;
    for (int i = 1; i <= n; i++) {
        if (!st[i]) {
            st[i] = 1;
            num[i] = 3;
            dfs(i, 0);
        }
    }
    ll ans = 1;
    for (int i = 1; i <= n; i++)
        ans *= num[i];
    cout << ans << endl;
}