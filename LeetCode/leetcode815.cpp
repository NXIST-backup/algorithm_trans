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
    int st[505];
    int ed[505];
    vector<int> g[505];
    int fa[505];
    int dis[505];
    int bfs(int n)
    {
        memset(dis, 0, sizeof dis);
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (st[i]) {
                q.push(i);
                dis[i] = 1;
            }

        while (q.size()) {
            int u = q.front();
            if (ed[u])
                break;
            q.pop();

            for (auto v : g[u]) {
                if (!dis[v]) {
                    q.push(v);
                    dis[v] = dis[u] + 1;
                }
            }
        }
        int res = 1e9 + 5;
        for (int i = 0; i < n; i++)
            if (ed[i] && dis[i])
                res = min(res, dis[i]);
        if (res != 1e9 + 5)
            return res;
        else
            return -1;
    }

    int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
    {
        if (source == target)
            return 0;
        unordered_map<int, vector<int>> rec;
        for (int i = 0; i < routes.size(); i++) {
            for (int site : routes[i]) {
                for (int j : rec[site]) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
                rec[site].push_back(i);
            }
        }
        for (int i = 0; i < routes.size(); i++)
            for (int j = 0; j < routes[i].size(); j++)
                if (routes[i][j] == source)
                    st[i] = 1;
                else if (routes[i][j] == target)
                    ed[i] = 1;

        return bfs(routes.size());
    }
};

int main()
{
    Solution a;
    vector<vector<int>> routes = {{1, 2, 7}, {3, 6, 7}};
    int source = 1, target = 6;
    cout << a.numBusesToDestination(routes, source, target) << endl;
}