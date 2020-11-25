//潜水员
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

const int N = 100, M = 30;

int m, n, k;
int a[1005], b[1005], c[1005];
int dp[M][N];


int main()
{
    cin >> m >> n >> k;

    for (int i = 1; i <= k;i++){
        cin >> a[i] >> b[i] >> c[i];
    }

    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;

    for (int i = 1; i <= k;i++){
        for (int j = m; j >= 0;j--){
            for (int k = n; k >= 0;k--)
                dp[j][k] = min(dp[j][k], dp[max(j - a[i], 0)][max(k - b[i], 0)] + c[i]);
        }
    }

    cout << dp[m][n] << endl;
}