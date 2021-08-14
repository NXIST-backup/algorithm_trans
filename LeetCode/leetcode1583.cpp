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
    int mp[505][505];
    int st[505];
    int unhappyFriends(int n, vector<vector<int>> &preferences, vector<vector<int>> &pairs)
    {
        for (int i = 0; i < preferences.size(); i++)
            for (int j = 0; j < preferences[i].size(); j++)
                mp[i][preferences[i][j]] = j;
        int ans = 0;
        for (int i = 0; i < pairs.size(); i++) {
            for (int j = i + 1; j < pairs.size(); j++) {
                int a = pairs[i][0], b = pairs[i][1];
                int c = pairs[j][0], d = pairs[j][1];
                if (mp[a][b] > mp[a][c] && mp[c][d] > mp[c][a])
                    st[a] = st[c] = 1;
                if (mp[a][b] > mp[a][d] && mp[d][c] > mp[d][a])
                    st[a] = st[d] = 1;
                if (mp[b][a] > mp[b][c] && mp[c][d] > mp[c][b])
                    st[b] = st[c] = 1;
                if (mp[b][a] > mp[b][d] && mp[d][c] > mp[d][b])
                    st[b] = st[d] = 1;
            }
        }
        for (int i = 0; i < n; i++)
            if (st[i])
                ans++;
        return ans;
    }
};

int main()
{
    Solution a;
    int n = 4;
    vector<vector<int>> s1 = {{1, 2, 3},
                              {3, 2, 0},
                              {3, 1, 0},
                              {1, 2, 0}};
    vector<vector<int>> s2 = {{0, 1}, {2, 3}};

    cout << a.unhappyFriends(4, s1, s2);
}
