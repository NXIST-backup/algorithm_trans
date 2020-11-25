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

const int T = 1e3 + 5, M = 105;
int t, m;
int dp[M][T];
int w[M],val[M];

int main()
{
    cin >> t >> m;

    for (int i = 1; i <= m;i++)
        cin >> w[i] >> val[i];

    for (int i = 1; i <= m;i++){
        for (int j = 0; j <= t;j++){
            if(j>=w[i])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + val[i]);
        }
    }

    cout << dp[m][t] << endl;
}