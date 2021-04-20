/*
  Problem Name:闇の連鎖
  algorithm tag:图论,树上差分,LCA
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

const int N = 1e5 + 5, M = 2e5 + 5;
int n, m;
int h[N], e[N * 2], ne[N * 2], idx;
int sum[N], dif[N];
int fa[N][20], dep[N];
int ans;
void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void bfs()
{
    memset(dep, 0x3f, sizeof dep);
    queue<int> q;
    q.push(1);
    dep[1] = 1, dep[0] = 0;

    while (q.size()) {
        int u = q.front();
        q.pop();

        for (int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];

            if (dep[v] > dep[u] + 1) {
                dep[v] = dep[u] + 1;
                q.push(v);
                fa[v][0] = u;
                for (int j = 1; j <= 17; j++)
                    fa[v][j] = fa[fa[v][j - 1]][j - 1];
            }
        }
    }
}

int lca(int a, int b)
{
    if (dep[a] < dep[b])
        swap(a, b);

    for (int i = 17; i >= 0; i--)
        if (dep[fa[a][i]] >= dep[b])
            a = fa[a][i];

    if (a == b)
        return a;

    for (int i = 17; i >= 0; i--)
        if (fa[a][i] != fa[b][i]) {
            a = fa[a][i];
            b = fa[b][i];
        }

    return fa[a][0];
}
void dfs(int u, int fa)
{
    sum[u] = dif[u];

    for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (v != fa) {
            dfs(v, u);
            sum[u] += sum[v];
        }
    }
    if (u != 1) {
        if (sum[u] == 0)
            ans += m;
        else if (sum[u] == 1)
            ans++;
    }
}

int main()
{
    iosf;
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }

    bfs();

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        dif[a]++;
        dif[b]++;
        dif[lca(a, b)] -= 2;
    }

    dfs(1, -1);

    cout << ans << endl;
}
