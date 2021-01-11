/*
  Problem Name:Through Path
  algorithm tag:BFS DFS 线段树 dfs序
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
const int mod = 1e9 + 7;
typedef pair<int, int> pii;

const int N = 2e5 + 5;
vector<int> g[N];
pii lis[N];
int dis[N];
int st[N];
int n, q;
ll w[N];

int bfs(int start)
{
    queue<int> q;
    q.push(start);
    dis[start] = 1;
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (auto v : g[u]) {
            if (!dis[v]) {
                dis[v] = dis[u] + 1;
                w[v] += w[u];
                q.push(v);
            }
        }
    }
    return 0;
}
int main()
{
    cin >> n;

    for (int i = 1; i <= n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
        lis[i] = {a, b};
    }

    bfs(1);
    cin >> q;

    for (int i = 1; i <= q; i++) {
        int t, e, x;
        cin >> t >> e >> x;

        int u = lis[e].first, v = lis[e].second;
        if (t == 2)
            swap(u, v);
        if (dis[u] < dis[v]) {
            w[1] += x;
            w[v] -= x;
        } else {
            w[u] += x;
        }
    }
    memset(dis, 0, sizeof dis);

    bfs(1);
    for (int i = 1; i <= n; i++)
        cout << w[i] << endl;
}