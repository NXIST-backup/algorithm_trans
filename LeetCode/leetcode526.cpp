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
    int ans = 0;
    vector<int> a;
    int st[20];
    bool check()
    {
        for (int i = 0; i < a.size(); i++) {
            if (a[i] % (i + 1) && (i + 1) % a[i])
                return false;
        }
        return true;
    }
    void dfs(int depth, int n)
    {
        if (depth == n) {
            if (check())
                ans++;
            return;
        }
        for (int i = 1; i <= n; i++) {
            if (st[i])
                continue;
            a.push_back(i);
            st[i] = 1;
            dfs(depth + 1, n);
            st[i] = 0;
            a.pop_back();
        }
    }
    int countArrangement(int n)
    {
        memset(st, 0, sizeof st);
        dfs(0, n);
        return ans;
    }
};

int main()
{
    Solution a;
    cout << a.countArrangement(11) << endl;
}