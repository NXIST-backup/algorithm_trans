/*
  Problem Name:新的开始
  algorithm tag:最小生成树扩展，最小森林(虚拟原点)？，kruskal
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

const int N = 305, M = N * N + N;

int n;
int dist[N];
bool st[N];
int g[N][N];
//构建虚拟原点
int prim()
{
    int res = 0;
    memset(dist, 0x3f, sizeof dist);
    priority_queue<pii, vector<pii>, greater<pii>> heap;
    heap.push({0, 0});
    dist[0] = 0;

    while (heap.size()) {
        int u = heap.top().second;
        int dis = heap.top().first;
        heap.pop();
        if (st[u])
            continue;
        st[u] = 1;
        res += dis;

        for (int i = 1; i <= n; i++) {
            if (!st[i] && dist[i] > g[u][i]) {
                dist[i] = g[u][i];
                heap.push({dist[i], i});
            }
        }
    }

    return res;
}
int main()
{
    iosf;
    cin >> n;
    memset(g, 0x3f, sizeof g);
    for (int i = 1; i <= n; i++)
        cin >> g[0][i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> g[i][j];

    cout << prim() << endl;
}