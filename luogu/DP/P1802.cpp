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

const int N = 1050;
int n, x;
int los[N], win[N], doc[N];
ll dp[N][N];

int main()
{
    cin >> n >> x;

    for (int i = 1; i <= n;i++){
        cin >> los[i] >> win[i] >> doc[i];
    }

    for (int i = 1; i <= n;i++){
        for (int j = 0; j <= x;j++){
            if(j>=doc[i]){
                dp[i][j] = max(dp[i-1][j]+los[i], dp[i - 1][j - doc[i]] + win[i]);
            }
            else
                dp[i][j] = dp[i - 1][j] + los[i];
        }
    }

    cout << dp[n][x]*5 << endl;
}