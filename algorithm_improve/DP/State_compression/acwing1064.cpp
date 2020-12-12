/*
  Problem Name:小国王
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

const int N = 12, M = 1 << N;
int dp[N][N * N][M];
bool st[M];
vector<int> state[M];
int n, K;
int cnt[M];

int main()
{
    cin >> n >> K;

    for (int i = 0; i < 1 << n; i++) {
        bool is_valid = true;
        for (int j = 0; j < n; j++) {
            if (i >> j & 1)
                cnt[i]++;
            if (i >> j & 1 && i >> j + 1 & 1) {
                is_valid = false;
                break;
            }
        }
        st[i] = is_valid;
    }

    for (int i = 0; i < 1 << n; i++) {
        if (st[i]) {
            for (int j = 0; j < 1 << n; j++) {
                if ((i & j) == 0 && st[i | j])
                    state[i].push_back(j);
            }
        }
    }
    dp[0][0][0] = 1;
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 0; j <= K; j++) {
            for (int k = 0; k < 1 << n; k++) {
                if (st[k]) {
                    for (auto item : state[k]) {
                        int c = cnt[k];
                        if (j >= c)
                            dp[i][j][k] += dp[i - 1][j - c][item];
                    }
                }
            }
        }
    }

    cout << dp[n + 1][K][0] << endl;
}
s