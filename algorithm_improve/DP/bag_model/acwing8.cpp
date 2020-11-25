//二维费用背包问题

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

const int N = 1e3 + 5, T = 105;

int n, V, M;
int v[N], m[N];
int w[N];
int dp[T][T];


int main()
{
    cin >> n >> V >> M;

    for (int i = 1; i <= n;i++){
        cin >> v[i] >> m[i] >> w[i];
    }

    for (int i = 1; i <= n;i++){
        for (int j = M; j >= m[i];j--){
            for (int k = V; k >= v[i];k--)
                dp[j][k] = max(dp[j][k], dp[j - m[i]][k - v[i]] + w[i]);
        }
    }

    cout << dp[M][V] << endl;
}