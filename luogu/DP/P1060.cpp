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

const int M = 30, N = 3e5 + 50;
int n, m;
int v[M], p[M];
int dp[M][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed;
    cin >> n >> m;

    for (int i = 1; i <= m;i++){
        cin >> v[i] >> p[i];
    }

    for (int i = 1; i <= m;i++){
        for (int j = 1; j <= n;j++){
            if(j-v[i]<0){
                dp[i][j] = dp[i - 1][j];
            }
            else
                dp[i][j] = max(dp[i - 1][j - v[i]] + v[i] * p[i], dp[i - 1][j]);
        }
    }

    cout << dp[m][n] << endl;
}