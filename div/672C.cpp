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

int t;
const int N = 3e5 + 50;
ll dp[N][2][2];
int main()
{
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        memset(dp, 0, sizeof dp);
        vector<int> a(n+1);
        for (int i = 1; i <= n;i++)
            cin >> a[i];

        for (int i = n; i >= 1 ;i--){//长度
            for (int j = 0; j < 2;j++){//取和不取
                for (int k = 0; k < 2;k++){//加或减
                    if(j==0&&k==0)
                        dp[i][0][0] = max(dp[i + 1][1][1], dp[i + 1][0][1]) + a[i];
                    if(j==0&&k==1)
                        dp[i][0][1] = max(dp[i + 1][1][0], dp[i + 1][0][0]) - a[i];
                    if(j==1&&k==1)
                        dp[i][1][1] = max(dp[i + 1][1][1], dp[i + 1][0][1]);
                    if(j==1&&k==0)
                        dp[i][1][0] = max(dp[i + 1][1][0], dp[i + 1][0][0]);
                }
            }
        }

        cout << max(dp[1][0][0], dp[1][1][0]) << endl;
    }
}