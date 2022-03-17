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

vector<int> g[505];
bool st[505];
bool mp[505][505];
class Solution
{
  public:
    bool symbol = false;
    bool dfs(int u)
    {
        st[u] = true;
        for (auto v : g[u]) {
            if (st[v])
                continue;
            if (g[v].size() > g[u].size())
                cout << "YES" << endl;
            for (auto v2 : g[v])
                if (!mp[u][v2] && v2 != u)
                    return false;
            st[v] = true;
            if (g[v].size() == g[u].size())
                symbol = true;
            return dfs(v);
        }
        return true;
    }
    int checkWays(vector<vector<int>> &pairs)
    {
        int n = 0;
        for (int i = 0; i <= 501; i++)
            g[i].clear();
        memset(mp, 0, sizeof mp);
        memset(st, 0, sizeof st);
        bool state[505];
        memset(state, 0, sizeof state);
        int root = 0;
        vector<int> arr;
        for (int i = 0; i < pairs.size(); i++) {
            int a = pairs[i][0], b = pairs[i][1];
            g[a].push_back(b);
            g[b].push_back(a);
            mp[a][b] = true;
            mp[b][a] = true;
            if (!state[a]) {
                n++;
                state[a] = true;
                arr.push_back(a);
            }
            if (!state[b]) {
                n++;
                state[b] = true;
                arr.push_back(b);
            }
        }
        for (auto i : arr) {
            if (g[i].size() == n - 1)
                root = i;
            sort(g[i].begin(), g[i].end(), [](int a, int b) {
                return g[a].size() > g[b].size();
            });
        }
        if (!root)
            return 0;
        bool ans = dfs(root);
        if (ans && symbol)
            return 2;
        if (ans)
            return 1;
        return 0;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> list = {{1, 2}, {2, 3}};
    cout << s.checkWays(list) << endl;
}
