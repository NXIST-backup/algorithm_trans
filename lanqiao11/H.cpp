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
const int INF = -1;
const int MOD = 1e9 + 7;
typedef pair<int,int> pii;

int n, m;
ll ans = 0;
int dp[1000][1000];
int main()
{
    cin >> n >> m;
    if(n%2==0&&m%2==0){
        cout << 0 << endl;
        return 0;
    }
    dp[1][1] = 1;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            if((i%2&&i!=0)||(j%2&&j!=0)){
                if(dp[i][j-1]!=INF)
                    dp[i][j] += dp[i][j - 1] % MOD;
                if(dp[i-1][j]!=INF)
                    dp[i][j] += dp[i - 1][j] % MOD;
            }
            else
                dp[i][j] = INF;
        }
    }
    cout << dp[n][m] << endl;
}