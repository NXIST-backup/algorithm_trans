//背包问题求方案数

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
const int mod = 1e9+7;
typedef pair<int,int> pii;

const int N = 1005;

int n, m;
int w[N], v[N];
int dp[N];
ll dp2[N];

int main()
{
    cin >> n >> m;

    memset(dp, -0x3f, sizeof dp);
    dp[0] = 0;
    dp2[0] = 1;

    for (int i = 1; i <= n;i++)
        cin >> v[i] >> w[i];
    //先采用恰好为m的方法求出方案数
    for (int i = 1; i <= n;i++){
        for (int j = m; j >= v[i];j--){
            int maxv = max(dp[j], dp[j - v[i]] + w[i]);
            int s = 0;
            if(maxv==dp[j])
                s += dp2[j] % mod;
            if(maxv==dp[j-v[i]]+w[i])
                s += dp2[j - v[i]] % mod;
            dp[j] = maxv, dp2[j] = s % mod;
        }
    }
    int res = 0;
    //求出最大
    for (int i = 0; i <= m;i++)
        res = max(res, dp[i]);
    ll ans = 0;
    //求出方案数
    for (int i = 0; i <= m;i++)
        if(res==dp[i])
            ans = (ans + dp2[i]) % mod;

    cout << ans << endl;
}