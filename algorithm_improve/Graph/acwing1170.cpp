/*
  Problem Name:排队布局
  algorithm tag:SPFA,差分约束
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

const int N = 1005, M = 3e4 + 50;

int n, ml, md;
int h[N], e[M], ne[M], w[M], idx;
int dist[N], cnt[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}
bool spfa()
{
    memset(dist, 0x3f, sizeof dist);
    queue<int> q;
    dist[1] = 0;

    for (int i = 1; i <= n; i++)
        q.push(i), st[i] = true;

    while (q.size()) {
        int u = q.front();
        q.pop();

        st[u] = false;

        for (int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];

            if (dist[v] > dist[u] + w[i]) {
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
    cin >> n >> ml >> md;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= ml; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a < b)
            swap(a, b);
        add(b, a, c);
    }

    for (int i = 1; i <= md; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a < b)
            swap(a, b);
        add(a, b, -c);
    }
    for (int i = 1; i < n; i++)
        add(i + 1, i, 0);
    if (spfa())
        puts("-1");
    else if (dist[n] == 0x3f3f3f3f)
        puts("-2");
    else
        cout << dist[n] << endl;
}