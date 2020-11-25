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

const int N = 105, M = 1e4 + 5;

int n, m;
int a[N];
int dp[N][M];

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n;i++)
        cin >> a[i];
    dp[0][0]=1;
    for (int i = 1; i <= n;i++){
        for (int j = 0; j <= m;j++){
            dp[i][j]+=dp[i-1][j];
            if(j>=a[i])
                dp[i][j]+=dp[i-1][j-a[i]];
        }   
    }
    ll res=0;
    cout<<dp[n][m]<<endl;
}