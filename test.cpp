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

const int N = 1050;
int n, w_sum;
int w[N], v[N];
int dp[N][N];
int main()
{
    cin >> n >> w_sum;

    for (int i = 1;i<=n;i++){
        cin >> w[i];
        cin >> v[i];
    }

    for (int i = 1; i <=n;i++){
        for (int j = 1; j <= w_sum;j++){
            if(j>=w[i])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j-w[i]] + v[i]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[n][w_sum] << endl;
}