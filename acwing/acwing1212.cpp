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
int dp[14][144][N][N];
int main()
{
    cin >> n >> m >> K;

    for (int i = 1;i<=n;i++){
        for (int j = 1;j<=m;j++)
            cin >> g[i][j];
    }

    for (int k = 0; k <= K;k++){
        int temp = k;
        for (int c = 0; c <= 12; c++) {
            for (int i = 1;i<=n;i++){
                for (int j = 1;j<=m;j++){
                    if(g[i][j]>=c&&temp>0)
                        dp[k][c][i][j] = (dp[k][c][i - 1][j] + dp[k][c][i][j - 1]) % INF,temp--;
                    if(temp==0)
                        dp[k][c][i][j] = (dp[k][c][i - 1][j] + dp[k][c][i][j - 1]) % INF;
                }
            }
        }
    }
}