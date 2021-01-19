/*
  Problem Name:数字游戏 II
  algorithm tag:数位DP
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
const int INF = 1e9 + 7;
typedef pair<int, int> pii;
#define vec vector
const int N = 105;

ll f[14][14][N];
ll l, r, mod;

ll MOD(ll x, ll y)
{
    return (x % y + y) % y;
}
void init()
{
    memset(f, 0, sizeof f);
    for (ll i = 0; i <= 9; i++)
        f[1][i][i % mod] = 1;
    for (ll i = 2; i <= 11; i++) {
        for (ll j = 0; j <= 9; j++) {
            for (ll k = 0; k <= 9; k++) {
                for (ll M = 0; M < mod; M++)
                    f[i][j][MOD(j + M, mod)] += f[i - 1][k][M];
            }
        }
    }
}
ll dp(ll n)
{
    if (!n)
        return 1;
    vec<int> nums;
    while (n)
        nums.push_back(n % 10), n /= 10;
    int res = 0;
    ll sum = 0;
    for (int i = nums.size() - 1; i >= 0; i--) {
        int t = nums[i];

        for (int j = 0; j < t; j++) {
            res += f[i + 1][j][MOD(-sum, mod)];
        }

        sum += t;
    }
    if (sum % mod == 0)
        res++;
    return res;
}
int main()
{
    while (cin >> l >> r >> mod) {
        init();

        cout << dp(r) - dp(l - 1) << endl;
    }
}