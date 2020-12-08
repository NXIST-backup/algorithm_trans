/*
   Problem Name:
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

const int N = 12, M = (1 << 11) + 5;

int n, m;
ll dp[12][M];
vector<int> state[M];
bool st[M];

int main()
{
    while (cin >> n >> m, n || m) {
        for (int i = 0; i < 1 << n; i++) {
            int cnt = 0;
            bool is_valid = true;
            for (int j = 0; j < n; j++) {
                if (i >> j & 1) {
                    if (cnt & 1) {
                        is_valid = false;
                        break;
                    }
                    cnt = 0;
                } else
                    cnt++;
            }
            if (cnt & 1)
                is_valid = false;
            st[i] = is_valid;
        }
        for (int i = 0; i < 1 << n; i++) {
            state[i].clear();
            for (int j = 0; j < 1 << n; j++) {
                if (st[i | j] && (i & j) == 0)
                    state[i].push_back(j);
            }
        }

        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < 1 << n; j++)
                for (auto k : state[j])
                    dp[i][j] += dp[i - 1][k];
        }

        cout << dp[m][0] << endl;
    }
}