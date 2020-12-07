/*
  Problem Name:金明的预算方案
  algorithm tag:有依赖的背包,分组背包，01背包，泛化背包
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
const int INF = 1e9;
typedef pair<int, int> pii;

const int M = 32005;
int n, m;
int dp[65][M];
vector<int> v[65], w[65];

int main()
{
    cin >> m >> n;
    int idx = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int x, y, z;
        cin >> x >> y >> z;

        if (z == 0) {
            v[i].push_back(x);
            w[i].push_back(y * x);
        } else {
            if (v[z].size() == 1) {
                v[z].push_back(x + v[z][0]);
                w[z].push_back(y * x + w[z][0]);
            } else if (v[z].size() == 2) {
                v[z].push_back(x + v[z][0]);
                w[z].push_back(y * x + w[z][0]);
                v[z].push_back(x + v[z][1]);
                w[z].push_back(y * x + w[z][1]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = dp[i - 1][j];
            for (int k = 0; k < v[i].size(); k++) {
                if (j >= v[i][k])
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i][k]] + w[i][k]);
            }
        }
    }

    cout << dp[n][m] << endl;
}