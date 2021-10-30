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
#include <unordered_set>
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
    unordered_set<int> mp;
    vector<int> nums;
    bool st[10];
    bool flag;
    void dfs(int n, int res)
    {
        if (n == nums.size()) {
            if (mp.find(res))
                flag = true;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (st[i] || (n == nums.size() - 1 && nums[i] == 0))
                continue;
            st[i] = 1;
            dfs(n + 1, res + nums[i] * pow(10, n));
            st[i] = 0;
        }
    }
    bool reorderedPowerOf2(int n)
    {
        while (n) {
            nums.push_back(n % 10);
            n /= 10;
        }
        for (int i = 0; i <= 30; i++)
            mp[1 << i]++;
        flag = false;
        memset(st, 0, sizeof st);
        dfs(0, 0);
        return flag;
    }
};
int main()
{
    Solution a;
    cout << a.reorderedPowerOf2(850239671) << endl;
}