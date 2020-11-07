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

const int N = 34, M = 2e4 + 50;

int v, n;
int val[N],w[N];
int dp[N][M];

int main()
{
    cin >> v >> n;

    for (int i = 1; i <= n;i++){
        cin >> val[i];
        w[i] = val[i];
    }

    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= v;j++){
            if(j>=val[i])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - val[i]] + w[i]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << v-dp[n][v] << endl;
}