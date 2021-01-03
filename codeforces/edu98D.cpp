//斐波那契+逆元
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e9;
typedef pair<int,int> pii;

const ll mod = 998244353;

const int N = 2e6 + 5;
int n;
ll dp[N];

ll q_pow(ll a, ll b, ll mod)
{
    ll res = 1;
    while (b) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main()
{
    cin >> n;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    for (int i = 4; i <= 200000;i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
    }
    ll res = q_pow(2, n, mod);
    cout << dp[n] * q_pow(res, mod - 2, mod) % mod << endl;
}