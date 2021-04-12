/*
  Problem Name:观光
  algorithm tag:DP,最短路，次短路
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
#define x first
#define y second
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed

const int N = 1e3 + 5, M = 1e4 + 5;

int n, m;
int h[N], e[M], ne[M], w[M], idx;
int S, F;
int dist[N][2], cnt[N][2], st[N][2];

struct Ver
{
    int ver;
    int type;
    int dist;

    bool operator>(const Ver &W) const
    {
        return dist > W.dist;
    }
};

void add(int a, int b, int c)
{
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}
int dij()
{
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    memset(cnt, 0, sizeof cnt);

    priority_queue<Ver, vector<Ver>, greater<Ver>> heap;
    heap.push({S, 0, 0});
    dist[S][0] = 0;
    cnt[S][0] = 1;

    while (heap.size()) {
        int u = heap.top().ver, dis = heap.top().dist, type = heap.top().type, count = cnt[u][type];
        heap.pop();

        if (st[u][type])
            continue;
        st[u][type] = 1;

        for (int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];

            if (dist[v][0] > dis + w[i]) {
                dist[v][1] = dist[v][0], dist[v][0] = dis + w[i];
                cnt[v][1] = cnt[v][0], cnt[v][0] = count;
                heap.push({v, 0, dist[v][0]});
                heap.push({v, 1, dist[v][1]});
            } else if (dist[v][0] == dis + w[i])
                cnt[v][0] += count;
            else if (dist[v][1] > dis + w[i]) {
                dist[v][1] = dis + w[i], cnt[v][1] = count;
                heap.push({v, 1, dist[v][1]});
            } else if (dist[v][1] == dis + w[i])
                cnt[v][1] += count;
        }
    }
    int res = cnt[F][0];
    if (dist[F][1] - 1 == dist[F][0])
        res += cnt[F][1];
    return res;
}

int main()
{
    iosf;
    int _;
    cin >> _;
    while (_--) {
        memset(h, -1, sizeof h);
        idx = 0;
        cin >> n >> m;

        for (int i = 1; i <= m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            add(a, b, c);
        }
        cin >> S >> F;

        cout << dij() << endl;
    }
}