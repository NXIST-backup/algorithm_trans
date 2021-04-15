/*
  Problem Name:祖孙询问
  algorithm tag:LCA,图论
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

const int N = 4e4 + 5, M = N * 2;

int n, m;
int h[N], e[M], ne[M], idx;
int dep[N];
int fa[N][20];
int root;

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
    dep[0] = 0, dep[root] = 1;
    q.push(root);

    while (q.size()) {
        int u = q.front();
        q.pop();

        for (int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];
            if (dep[v] > dep[u] + 1) {
                dep[v] = dep[u] + 1;
                q.push(v);
                fa[v][0] = u;
                for (int i = 1; i <= 15; i++)
                    fa[v][i] = fa[fa[v][i - 1]][i - 1];
            }
        }
    }
}

int lca(int a, int b)
{
    if (dep[a] < dep[b])
        swap(a, b);
    for (int i = 15; i >= 0; i--)
        if (dep[fa[a][i]] >= dep[b])
            a = fa[a][i];
    if (a == b)
        return a;
    for (int i = 15; i >= 0; i--) {
        if (fa[a][i] != fa[b][i]) {
            a = fa[a][i];
            b = fa[b][i];
        }
    }
    return fa[a][0];
}
int main()
{
    iosf;
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        if (b == -1)
            root = a;
        else
            add(a, b), add(b, a);
    }

    int Q;
    cin >> Q;
    bfs();
    for (int i = 1; i <= Q; i++) {
        int a, b;
        cin >> a >> b;
        int p = lca(a, b);
        if (p == a)
            cout << 1 << endl;
        else if (p == b)
            cout << 2 << endl;
        else
            cout << 0 << endl;
    }
}