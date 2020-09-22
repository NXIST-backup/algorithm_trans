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
const int INF = 1e9+7;
typedef pair<int,int> pii;

const int N = 60;
int n, m, K;
int g[N][N];
int dp[N][N][13][13];
int main()
{
    cin >> n >> m >> K;

    for (int i = 1;i<=n;i++){
        for (int j = 1;j<=m;j++){
            cin >> g[i][j];
            g[i][j]++;
        }
    }
    dp[1][1][1][g[1][1]] = 1;
    dp[1][1][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m;j++){
            
        }
    }
}