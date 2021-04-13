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
const double eps = 1e-4;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
//#define x first
//#define y second
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed

const int N = 1005, M = 5005;
int n, m;
int h[N], e[M], ne[M], idx;
double w[M], cy[M];
double f[N];
double dist[N];
int st[N], cnt[M];

void add(int a, int b, double c)
{
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}
bool spfa()
{
    // 注意求最小环判负是不行的
    memset(dist, 0, sizeof dist);
    memset(st, 0, sizeof st);
    memset(cnt, 0, sizeof cnt);
    queue<int> q;
    for (int i = 1; i <= n; i++)
        q.push(i), st[i] = true;

    while (q.size()) {
        int u = q.front();
        q.pop();

        st[u] = false;

        for (int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];
            if (dist[v] < dist[u] + w[i]) {
                dist[v] = dist[u] + w[i];
                cnt[v] = cnt[u] + 1;
                if (cnt[v] >= n)
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
    for (int i = 1; i <= n; i++)
        cin >> f[i];
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    double l = 0, r = 1e5;
    while (r - l > eps) {
        double mid = (l + r) / 2;
        memcpy(cy, w, sizeof cy);
        for (int i = 0; i < idx; i++)
            w[i] = f[e[i]] - w[i] * mid;
        if (spfa())
            l = mid;
        else
            r = mid;
        memcpy(w, cy, sizeof w);
    }
    printf("%.2lf", l);
}