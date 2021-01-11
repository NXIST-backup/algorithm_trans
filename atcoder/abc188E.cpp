/*
  Problem Name:Peddler
  algorithm tag:
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int mod = 1e9 + 7;
typedef pair<int, int> pii;

const int N = 2e5 + 5;
int n, m;
vector<int> g[N];
int w[N];
int dp[N];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[b].push_back(a);
    }
    int ans = -mod;
    for (int i = 1; i <= n; i++) {
        dp[i] = w[i];
        for (auto v : g[i]) {
            ans = max(ans, w[i] - dp[v]);
            dp[i] = min(dp[i], dp[v]);
        }
    }
    cout << ans << endl;
}