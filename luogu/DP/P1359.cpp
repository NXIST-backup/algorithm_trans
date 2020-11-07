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

const int N = 203;
int dp[N][N];
int r[N][N];
int n;

int main()
{
    cin >> n;

    for (int i = 1; i <= n-1;i++){
        for (int j = i; j <= n-1;j++){
            cin >> r[i][j];
        }
    }
    for (int i = n - 1; i >= 1; i--) {
        for (int j = i + 1; j <= n;j++){
            dp[i][j] = r[i][j - 1];
            for (int k = i + 1; k <= j - 1;k++){
                dp[i][j] = min(dp[i][k] + r[k][j - 1], dp[i][j]);
            }
        }
    }

    cout << dp[1][n] << endl;
}
