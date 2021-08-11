/*
  Problem Name:
  algorithm tag:
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

class Solution
{
  public:
    vector<int> g[15];
    bool st[15][5000];
    int n;
    struct Node
    {
        int v, s, dis;
    };
    int bfs(int start)
    {
        memset(st, 0, sizeof st);
        queue<Node> q;
        q.push({start, 1 << start, 0});
        st[start][1 << start] = true;
        while (q.size()) {
            auto t = q.front();
            q.pop();
            int u = t.v;
            int state = t.s;
            int dis = t.dis;
            if (state == (1 << n) - 1)
                return dis;
            for (auto v : g[u]) {
                int s = state | (1 << v);
                int dist = dis + 1;
                if (!st[v][s]) {
                    q.push({v, s, dist});
                    st[v][s] = true;
                }
            }
        }
    }
    int shortestPathLength(vector<vector<int>> &graph)
    {
        n = graph.size();

        for (int i = 0; i < n; i++)
            for (auto v : graph[i])
                g[i].push_back(v);

        int ans = 0x3f3f3f3f;
        for (int i = 0; i < n; i++)
            ans = min(ans, bfs(i));
        return ans;
    }
};
int main()
{
    Solution a;
    vector<vector<int>> ttt = {
        {1, 2, 3},
        {0},
        {0},
        {0},
    };

    cout << a.shortestPathLength(ttt) << endl;
}