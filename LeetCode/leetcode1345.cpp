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
    int dp[50005];
    int minJumps(vector<int> &arr)
    {
        memset(dp, 0, sizeof dp);
        unordered_map<int, vector<int>> mp;
        unordered_map<int, bool> st;

        for (int i = 0; i < arr.size(); i++)
            mp[arr[i]].push_back(i);

        queue<int> q;
        q.push(0);
        dp[0] = 1;

        while (q.size()) {
            int t = q.front();
            q.pop();

            if (t == arr.size() - 1)
                break;
            // l,r
            if (t - 1 >= 0 && !dp[t - 1] && arr[t - 1] != arr[t]) {
                q.push(t - 1);
                dp[t - 1] = dp[t] + 1;
            }
            if (!dp[t + 1] && arr[t + 1] != arr[t]) {
                q.push(t + 1);
                dp[t + 1] = dp[t] + 1;
            }
            if (!st[arr[t]]) {
                st[arr[t]] = 1;
                for (auto item : mp[arr[t]]) {
                    if (item != t && !dp[item]) {
                        q.push(item);
                        dp[item] = dp[t] + 1;
                    }
                }
            }
        }

        return dp[arr.size() - 1] - 1;
    }
};

int main()
{
    Solution s;
    vector<int> a = {100, -23, -23, 404, 100, 23, 23, 23, 3, 404};
    s.minJumps(a);
}