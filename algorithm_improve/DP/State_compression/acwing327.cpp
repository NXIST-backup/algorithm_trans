/*
  Problem Name:玉米田
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
const int mod = 1e8;
typedef pair<int, int> pii;

const int N = 14, M = 1 << 14;
int n, m;
bool st[N][M];
bool g[N][N];
vector<int> state[N][M];
ll dp[N][M];

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cin >> g[i][j];
    }
    for (int k = 1; k <= n + 1; k++) {
        for (int i = 0; i < 1 << m; i++) {
            bool is_valid = true;
            for (int j = 0; j < m; j++) {
                if ((i >> j & 1) && (i >> j + 1 & 1)) {
                    is_valid = false;
                    break;
                }
                if (i >> j & 1 && g[k][m - j] == 0) {
                    is_valid = false;
                    break;
                }
            }
            st[k][i] = is_valid;
        }
    }

    for (int i = 1; i <= n + 1; i++) {
        for (int j = 0; j < 1 << m; j++) {
            if (st[i][j]) {
                for (int k = 0; k < 1 << m; k++) {
                    if (!(j & k)) {
                        state[i][j].push_back(k);
                    }
                }
            }
        }
    }

    dp[0][0] = 1;

    for (int i = 1; i <= n + 1; i++) {
        for (int j = 0; j < 1 << m; j++) {
            if (st[i][j]) {
                for (auto item : state[i][j]) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][item]) % mod;
                }
            }
        }
    }

    cout << dp[n + 1][0] << endl;
}