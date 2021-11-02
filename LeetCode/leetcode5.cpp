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
    string longestPalindrome(string s)
    {
        int ans = 0;
        string re;
        for (int i = 0; i < s.size(); i++) {
            int l = i, r = i + 1;
            int res = 0;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                res += 2;
                l--, r++;
            }
            if (res > ans) {
                re.clear();
                ans = res;
                for (int j = l + 1; j <= r - 1; j++)
                    re.push_back(s[j]);
            }
            l = i, r = i;
            res = 1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if (l != i)
                    res += 2;
                l--, r++;
            }
            if (res > ans) {
                re.clear();
                ans = res;
                for (int j = l + 1; j <= r - 1; j++)
                    re.push_back(s[j]);
            }
        }
        return re;
    }
};
int main()
{
    string s = "babad";
    Solution a;
    cout << a.longestPalindrome(s) << endl;
}