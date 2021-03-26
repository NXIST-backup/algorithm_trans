/*
  Problem Name:第K短路
  algorithm tag:A star
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

const int N = 1005, M = 200005;

int n, m;
int st, ed, k;
int h[N], rh[N], e[M], ne[M], w[M], idx;
int dist[N];
int state[N];

void init()
{
    memset(h, -1, sizeof h);
    memset(rh, -1, sizeof rh);
}
void add(int h[], int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

void dij()
{
    priority_queue<pii, vector<pii>, greater<pii>> heap;
    memset(dist, 0x3f, sizeof dist);
    heap.push({0, ed});
    dist[ed] = 0;

    while (heap.size()) {
        auto t = heap.top();
        heap.pop();

        int u = t.y;

        if (state[u])
            continue;
        state[u] = 1;

        for (int i = rh[u]; i != -1; i = ne[i]) {
            int v = e[i];

            if (dist[v] > dist[u] + w[i]) {
                dist[v] = dist[u] + w[i];
                heap.push({dist[v], v});
            }
        }
    }
}
int astar()
{
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> heap;
    int cnt = 0;
    heap.push({dist[st], {0, st}});

    while (heap.size()) {
        auto t = heap.top();
        heap.pop();

        int u = t.y.y;
        int dis = t.y.x;

        if (u == ed)
            cnt++;
        if (cnt == k)
            return dis;

        for (int i = h[u]; i != -1; i = ne[i]) {
            int v = e[i];
            heap.push({dis + w[i] + dist[v], {dis + w[i], v}});
        }
    }

    return -1;
}
int main()
{
    iosf;
    init();
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(h, a, b, c);
        add(rh, b, a, c);
    }
    cin >> st >> ed >> k;
    dij();

    cout << astar() << endl;
}