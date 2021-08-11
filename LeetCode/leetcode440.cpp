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
    int num[10];
    string ans;
    int work(int len)
    {
        int p = 1;
        int res = 0;
        for (int i = 1; i <= len; i++) {
            res += p;
            p *= 10;
        }
        return res;
    }
    void del(int n)
    {
        int t = n;
        int len = 0;
        int hum = 0;
        while (t) {
            hum = t % 10;
            t /= 10, len++;
        }
        if (n > 10)
            num[0] = 0;
        else
            num[0] = 1;
        for (int i = 1; i <= 9; i++) {
            if (i < hum)
                num[i] = work(len);
            else if (i == hum)
                num[i] = work(len - 1) + n % (int)pow(10, len - 1) + 1;
            else
                num[i] = work(len - 1);
        }
        for (int i = 1; i <= 9; i++)
            num[i] += num[i - 1];
    }
    int findKthNumber(int n, int k)
    {
        if (!k) {
            int result = 0;
            int p = 1;
            for (int i = ans.size() - 1; i >= 0; i--) {
                result += (ans[i] - '0') * p;
                p *= 10;
            }
            return result;
        }
        del(n);
        for (int i = 0; i <= 9; i++) {
            if (k <= num[i]) {
                ans.push_back(i + '0');
                k = k - num[i - 1] - 1;
                return findKthNumber(num[i] - 1, k);
            }
        }
    }
};
int main()
{
    Solution a;
    cout << a.findKthNumber(147, 22) << '\n';
}