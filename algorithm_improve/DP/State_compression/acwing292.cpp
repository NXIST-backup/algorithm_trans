/*
  Problem Name:炮兵阵地
  algorithm tag:状态压缩DP
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

const int N = 110, M = 1 << 12;
int g[1010];
int n, m;
int dp[2][M][M];
vector<int> states;
int cnt[M];

bool check(int state)
{
    for (int i = 0; i < m; i++) {
        if ((state >> i & 1) && ((state >> i + 1 & 1) || (state >> i + 2 & 1)))
            return false;
    }
    return true;
}
int count(int state)
{
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        if (state >> i & 1)
            cnt++;
    }
    return cnt;
}
int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == 'H')
                g[i] += 1 << j;
        }
    }

    for (int i = 0; i < 1 << m; i++) {
        if (check(i)) {
            states.push_back(i);
            cnt[i] = count(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < states.size(); j++) {
            for (int k = 0; k < states.size(); k++) {
                for (int u = 0; u < states.size(); u++) {
                    int a = states[j], b = states[k], c = states[u];
                    if (a & b | a & c | b & c)
                        continue;
                    if (g[i] & b | g[i - 1] & a)
                        continue;
                    dp[i & 1][j][k] = max(dp[i & 1][j][k], dp[i - 1 & 1][u][j] + cnt[b]);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < states.size(); i++) {
        for (int j = 0; j < states.size(); j++)
            ans = max(ans, dp[n & 1][i][j]);
    }

    cout << ans << endl;
}
