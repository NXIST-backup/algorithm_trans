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

const int N = 150;
int t;
int dp[N][N];
int a[N][N];
int main()
{
    cin >> t;

    while(t--){
        int R, C;
        cin >> R >> C;
        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C;j++){
                cin >> a[i][j];
            }
        }

        for (int i = 1; i <= R;i++){
            for (int j = 1;j<=C;j++){
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
            }
        }

        cout << dp[R][C] << endl;
    }
}