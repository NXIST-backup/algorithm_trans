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
    int countDigitOne(int n)
    {
        vector<int> digit;
        while (n) {
            digit.push_back(n % 10);
            n /= 10;
        }
        int cnt = 0;
        for (int i = 0; i < digit.size(); i++) {
            if (digit[i] < 1)
                continue;
            int p = digit.size() - 2;
            for (int j = digit.size() - 1; i >= 0; j++) {
                if (i == j)
                    continue;
                cnt += digit[j] * pow(10, p--);
            }
        }
        return cnt;
    }
};
int main()
{
    Solution a;
    int n = 23;
    cout << a.countDigitOne(n) << endl;
}