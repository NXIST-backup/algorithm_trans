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
    int n;
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
    {
        int max_r[55], max_c[55];
        memset(max_r, 0, sizeof max_r);
        memset(max_c, 0, sizeof max_c);
        n = grid.size();

        for (int i = 0; i < n; i++) {
            int mx = 0;
            for (int j = 0; j < n; j++)
                mx = max(grid[i][j], mx);
            max_r[i] = mx;
        }

        for (int i = 0; i < n; i++) {
            int mx = 0;
            for (int j = 0; j < n; j++)
                mx = max(grid[j][i], mx);
            max_c[i] = mx;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int t = grid[i][j];
                int mn = min(max_r[i], max_c[j]);
                ans += mn - t;
            }
        }
        return ans;
    }
};
