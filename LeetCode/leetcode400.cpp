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
    int findNthDigit(int n)
    {
        vector<long long> fac = {9, 90 * 2, 900 * 3, 9000 * 4, 90000 * 5, 900000 * 6, 9000000 * 7, 90000000 * 8};

        for (int i = 1; i < fac.size(); i++)
            fac[i] = fac[i] + fac[i - 1];
        int idx = 0;
        for (int i = 0; i < fac.size(); i++)
            if (fac[i] >= n) {
                idx = i;
                break;
            }

        int st = pow(10, idx);
        int cut = n - 1;
        if (idx >= 1)
            cut = n - fac[idx - 1] - 1;
        int num = cut / (idx + 1);
        int res = cut % (idx + 1);
        int ans = st + num;

        string s = to_string(ans);
        int rel_ans = s[res] - '0';

        return rel_ans;
    }
};

int main()
{
    Solution a;
    cout << a.findNthDigit(9) << endl;
}