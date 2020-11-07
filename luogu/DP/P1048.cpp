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

const int N = 1005, M = 105;

int t, m;
int ti[M], v[M];
int dp[M][N];

int main()
{
    cin >> t >> m;

    for (int i = 1; i <= m;i++){
        cin >> ti[i] >> v[i];
    }

    for (int i = 1; i <= m;i++){
        for (int j = 1; j <= t;j++){
            if(j>=ti[i]){
                dp[i][j] = max(dp[i-1][j], dp[i - 1][j - ti[i]]+v[i]);
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[m][t] << endl;
}