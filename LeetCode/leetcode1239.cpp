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
#include <set>
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
    int cnt[26];
    int maxLength(vector<string> &arr)
    {
        int n = arr.size();
        int ans = 0;
        for (int i = 0; i < 1 << n; i++) {
            memset(cnt, 0, sizeof cnt);
            string res;
            int tmp = i, idx = 0;
            while (tmp) {
                if (tmp & 1)
                    res += arr[idx];
                idx++;
                tmp >>= 1;
            }
            bool flag = 1;
            for (int i = 0; i < res.size(); i++) {
                cnt[res[i] - 'a']++;
                if (cnt[res[i] - 'a'] > 1) {
                    flag = 0;
                    break;
                }
            }
            int sss = res.size();
            if (flag)
                ans = max(ans, sss);
        }
        return ans;
    }
};
int main()
{
    Solution a;
    vector<string> s = {"abcdefghijklmnopqrstuvwxyz"};
    cout << a.maxLength(s) << endl;
}