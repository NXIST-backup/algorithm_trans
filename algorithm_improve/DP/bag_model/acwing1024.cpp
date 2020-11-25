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

const int V = 2e4 + 5;

int v, n;
int w[55];
int dp[55][V];

int main()
{
    cin >> v >> n;

    for (int i = 1; i <= n;i++)
        cin >> w[i];

    for (int i = 1; i <= n;i++){
        for (int j = 0; j <= v;j++){
            dp[i][j] = dp[i - 1][j];
            if(j>=w[i])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + w[i]);
        }
    }

    cout << dp[n][v] << endl;
}