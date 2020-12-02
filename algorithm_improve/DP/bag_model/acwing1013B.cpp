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

const int N = 20;
int n, m;
int w[N][N];
int dp[N][N];
int way[N];
int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= m;j++){
            cin >> w[i][j];
        }

    for (int i = 1; i <= n;i++){
        for (int j = 0; j <= m;j++){
            dp[i][j] = dp[i - 1][j];
            for (int k = 0; k <= j;k++){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + w[i][k]);
            }
        }
    }
    int k = m;
    for (int i = n; i;i--)
        for (int j = 0; j <= k;j++)
            if(dp[i][k]==dp[i-1][k-j]+w[i][j]){
                way[i] = j;
                k -= j;
                break;
            }
    cout << dp[n][m] << endl;
    for (int i = 1; i <= n;i++)
        cout << i << " " << way[i] << endl;
}