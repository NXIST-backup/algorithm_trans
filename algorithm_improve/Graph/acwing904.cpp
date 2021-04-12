/*
  Problem Name:虫洞
  algorithm tag:spfa，负环
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

const int N = 505, M = 5205;
int n, m1, m2;
int h[N], e[M], ne[M], w[M], idx;
int dist[N];
int cnt[M], st[N];
int q[N];

void add(int a, int b, int c)
{
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}

bool spfa()
{
    memset(st, 0, sizeof st);
    memset(cnt, 0, sizeof cnt);

    int hh = 0, tt = 0;
    for (int i = 1; i <= n; i++)
        q[tt++] = i, st[i] = true;

    while (hh != tt) {
        int u = q[hh++];
        if (hh == N) //环所以要循环队列
            hh = 0;

        st[u] = false;

        for (int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];
            if (dist[v] > dist[u] + w[i]) {
                dist[v] = dist[u] + w[i];
                cnt[i]++;
                if (cnt[i] >= n)
                    return true;
                if (!st[v]) {
                    q[tt++] = v;
                    if (tt == N)
                        tt = 0;
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
    int _;
    cin >> _;
    while (_--) {
        memset(h, -1, sizeof h);
        idx = 0;
        cin >> n >> m1 >> m2;

        for (int i = 1; i <= m1; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            add(a, b, c), add(b, a, c);
        }
        for (int i = 1; i <= m2; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            add(a, b, -c);
        }

        if (spfa())
            puts("YES");
        else
            puts("NO");
    }
}