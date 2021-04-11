/*
  Problem Name:最短网络
  algorithm tag:prim,kruskal
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
//#define x first
//#define y second
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed

const int N = 105;
int g[N][N];
int n, m;
int dist[N];
bool st[N];

int prim()
{
    memset(dist, 0x3f, sizeof dist);
    int res = 0;

    for (int i = 1; i <= n; i++) {
        int t = -1;

        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
        if (i != 1 && dist[t] == INF)
            return INF;
        if (i > 1)
            res += dist[t];

        for (int j = 1; j <= n; j++) {
            if (!st[j])
                dist[j] = min(dist[j], g[t][j]);
        }
        st[t] = 1;
    }

    return res;
}
int prim2()
{
    memset(dist, 0x3f, sizeof dist);
    int res = 0;
    int cnt = 0;
    priority_queue<pii, vector<pii>, greater<pii>> heap;
    heap.push({0, 1});
    dist[1] = 0;

    while (heap.size()) {
        int u = heap.top().second;
        int dis = heap.top().first;
        heap.pop();

        if (st[u])
            continue;
        st[u] = 1;
        res += dis;
        cnt++;

        for (int i = 1; i <= n; i++)
            if (!st[i] && dist[i] > g[u][i]) {
                dist[i] = g[u][i];
                heap.push({dist[i], i});
            }
    }

    if (cnt == n)
        return res;
    else
        return INF;
}
int main()
{
    iosf;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cin >> g[i][j];
    }

    cout << prim2() << endl;
}
