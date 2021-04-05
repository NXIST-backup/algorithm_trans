/*
  Problem Name:道路与航线
  algorithm tag:topsort,dijkstra
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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define x first
#define y second
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed

const int N = 25010, M = 150010;

int n, mr, mp, start;
int h[N], e[M], ne[M], w[M], idx;
int dist[N];
int id[N];
int st[N];
int bin[N];
vector<int> block[N];
int bcnt;
queue<int> q;
void add(int a, int b, int c)
{
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}
void dfs(int u, int bid)
{
    id[u] = bid;
    block[bid].push_back(u);
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (!id[j])
            dfs(j, bid);
    }
}
void dij(int bid)
{
    priority_queue<pii, vector<pii>, greater<pii>> heap;

    for (auto u : block[bid]) {
        heap.push({dist[u], u});
    }

    while (heap.size()) {
        auto t = heap.top();
        heap.pop();

        int u = t.y, dis = t.x;
        if (st[u])
            continue;
        st[u] = 1;

        for (int i = h[u]; ~i; i = ne[i]) {
            int j = e[i];
            if (id[j] != id[u] && --bin[id[j]] == 0)
                q.push(id[j]);
            if (dist[j] > dist[u] + w[i]) {
                dist[j] = dist[u] + w[i];
                if (id[j] == id[u])
                    heap.push({dist[j], j});
            }
        }
    }
}
void topsort()
{
    memset(dist, 0x3f, sizeof dist);
    dist[start] = 0;
    for (int i = 1; i <= bcnt; i++) {
        if (!bin[i])
            q.push(i);
    }

    while (q.size()) {
        int t = q.front();
        q.pop();
        dij(t);
    }
}

int main()
{
    iosf;
    cin >> n >> mr >> mp >> start;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= mr; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }

    for (int i = 1; i <= n; i++) {
        if (!id[i])
            dfs(i, ++bcnt);
    }

    for (int i = 1; i <= mp; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        bin[id[b]]++;
        add(a, b, c);
    }

    topsort();

    for (int i = 1; i <= n; i++) {
        if (dist[i] > INF / 2)
            cout << "NO PATH" << endl;
        else
            cout << dist[i] << endl;
    }
}
