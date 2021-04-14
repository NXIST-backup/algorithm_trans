/*
  Problem Name:糖果
  algorithm tag:图论,Tarjan算法,有向图的强连通分量,SPFA,差分约束
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
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

const int N = 1e5 + 5, M = 1e5 + 5;
int n, m;
int h[N], e[M], ne[M], idx;
ll w[M], dist[N];
int cnt[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}
bool spfa()
{
    memset(dist, -0x3f, sizeof dist);
    memset(cnt, 0, sizeof cnt);
    memset(st, 0, sizeof st);
    stack<int> q;
    dist[0] = 0;
    st[0] = true;
    q.push(0);
    while (q.size()) {
        int u = q.top();
        q.pop();

        st[u] = false;

        for (int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];
            if (dist[v] < dist[u] + w[i]) {
                dist[v] = dist[u] + w[i];
                cnt[v] = cnt[u] + 1;
                if (cnt[v] >= n + 1)
                    return true;
                if (!st[v]) {
                    q.push(v);
                    st[v] = true;
                }
            }
        }
    }
    return false;
}

int main()
{
    iosf;
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= m; i++) {
        int x, a, b;
        cin >> x >> a >> b;
        if (x == 1)
            add(a, b, 0), add(b, a, 0);
        else if (x == 2)
            add(a, b, 1);
        else if (x == 3)
            add(b, a, 0);
        else if (x == 4)
            add(b, a, 1);
        else
            add(a, b, 0);
    }

    for (int i = 1; i <= n; i++)
        add(0, i, 1);
    if (spfa())
        puts("-1");
    else {
        ll res = 0;
        for (int i = 1; i <= n; i++)
            res += dist[i];

        cout << res << endl;
    }
}