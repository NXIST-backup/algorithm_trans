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
    bool check_int(string s)
    {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9')
                continue;
            else
                return false;
        }
        return true;
    }
    bool check_ls(string s)
    {
        int cnt = 0, pos = s.size();
        for (int i = 0; i < s.size(); i++)
            if (s[i] == '.')
                cnt++, pos = i;
        if (cnt > 1 || cnt == 0)
            return false;
        string pre = s.substr(0, pos), suf = s.substr(pos + 1, s.size());
        if (cnt == 1 && !pre.size() && !suf.size())
            return false;
        for (int i = 0; i < suf.size(); i++)
            if (suf[i] < '0' || suf[i] > '9')
                return false;
        return check_int(pre);
    }
    bool isNumber(string s)
    {
        string pre, suf;
        int cnt = 0, pos = s.size();
        for (int i = 0; i < s.size(); i++)
            if (s[i] == 'e' || s[i] == 'E')
                cnt++, pos = i;
        if (cnt > 1)
            return false;

        pre = s.substr(0, pos);
        if (pos < s.size())
            suf = s.substr(pos + 1, s.size());
        if (pre[0] == '+' || pre[0] == '-')
            pre = pre.substr(1, pre.size());
        if (suf[0] == '+' || suf[0] == '-')
            suf = suf.substr(1, suf.size());
        if (cnt == 1 && (!suf.size() || !pre.size()))
            return false;
        check_int(suf);
        if ((check_ls(pre) || check_int(pre)) && check_int(suf))
            return true;
        else
            return false;
    }
};

int main()
{
    string s;
    cin >> s;
    Solution a;
    cout << a.isNumber(s) << endl;
}
