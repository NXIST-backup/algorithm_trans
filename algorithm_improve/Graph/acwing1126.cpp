/*
  Problem Name:最小花费
  algorithm tag:dijkstra
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
typedef pair<double, int> pdl;
#define x first
#define y second
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed

int n, m;
vector<pair<double, int>> g[2005];
int st, ed;
double dist[2005];
int state[2005];
void dij(int st)
{
    priority_queue<pdl, vector<pdl>, less<pdl>> heap;

    heap.push({1, st});
    dist[st] = 1;

    while (heap.size()) {
        auto t = heap.top();
        heap.pop();
        if (state[t.y])
            continue;
        state[t.y] = 1;

        for (auto v : g[t.y]) {
            if (dist[v.y] < dist[t.y] * v.x) {
                dist[v.y] = dist[t.y] * v.x;
                heap.push({dist[v.y], v.y});
            }
        }
    }
}

int main()
{
    iosf;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        double z = (100.0 - c) / 100;
        g[a].push_back({z, b});
        g[b].push_back({z, a});
    }
    cin >> st >> ed;
    dij(st);

    printf("%.8lf\n", 100 / dist[ed]);
}
