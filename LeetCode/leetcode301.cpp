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
    bool check(int mask, string s)
    {
        char q[30];
        int hh = 0, tt = -1;
        for (int i = 0; i < s.size(); i++)
            if (mask >> i & 1) {
                if (s[i] == ')' && hh <= tt && q[tt] == '(')
                    tt--;
                else
                    q[++tt] = s[i];
            }

        return hh > tt;
    }
    vector<string> removeInvalidParentheses(string s)
    {
        string s1;
        vector<string> ans;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == '(' || s[i] == ')')
                s1.push_back(s[i]);
        int n = s1.size();
        char q[30];
        int hh = 0, tt = -1;
        for (int i = 0; i < s1.size(); i++) {
            if (s[i] == ')' && hh <= tt && q[tt] == '(')
                tt--;
            else
                q[++tt] = s1[i];
        }
        int m = (tt - hh + 1);
        int mn = s.size() - m;
        cout << m << endl;
        cout << mn << endl;
        set<string> set;
        for (int i = 0; i < 1 << n; i++) {
            string tmp;
            int cnt = 0;
            int mask = i;
            while (mask) {
                if (mask & 1)
                    cnt++;
                mask >>= 1;
            }
            if (cnt != s1.size() - m)
                continue;

            if (check(i, s1)) {
                int idx = 0;
                for (int j = 0; j < s.size(); j++) {
                    if (s[j] != '(' && s[j] != ')')
                        tmp.push_back(s[j]);
                    else if (i >> idx++ & 1)
                        tmp.push_back(s[j]);
                }
                cout << tmp << endl;
                set.insert(tmp);
            }
        }

        for (auto &s : set)
            ans.push_back(s);
        return ans;
    }
};
int main()
{
    string s = ")(()c))(";

    Solution a;

    auto t = a.removeInvalidParentheses(s);

    for (auto i : t) {
        cout << i << endl;
    }
}