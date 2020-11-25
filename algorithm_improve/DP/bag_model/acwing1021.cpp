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

const int N = 20, M = 3005;
int n,m;
int dp[M];
int a[N];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    dp[0] = 1;
    for (int i = 1; i <= n;i++){
        for (int j = 0; j <= m;j++){
                dp[j] += dp[j - a[i]];
        }
    }

    cout << dp[m] << endl;
}