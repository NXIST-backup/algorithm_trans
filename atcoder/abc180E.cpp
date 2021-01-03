/*
  Problem Name:
  algorithm tag:状态压缩dp
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

const int N = 18, M = 1 << 17;
int n;
int dp[N][M];
struct abc
{
    int a, b, c;
} num[N];

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        num[i] = {a, b, c};
    }
    memset(dp, 0x3f, sizeof dp);
    dp[0][1] = 0;

    for (int j = 0; j < 1 << n; j++) {
        if (j & 1 == 0)
            continue;
        for (int i = 1; i < n; i++) {
            if (j >> i & 1) {
                int tmp = j - (1 << i);
                for (int k = 0; k < n; k++) {
                    if (tmp >> k & 1) {
                        if (k == 0 && tmp > 1)
                            continue;
                        int dis = abs(num[i].a - num[k].a) + abs(num[i].b - num[k].b) + max(0, num[i].c - num[k].c);
                        dp[i][j] = min(dp[i][j], dp[k][tmp] + dis);
                    }
                }
            }
        }
    }

    int ans = 1e9;
    int temp = (1 << n) - 1;
    for (int i = 1; i < n; i++) {
        ans = min(ans, dp[i][temp] + abs(num[0].a - num[i].a) + abs(num[0].b - num[i].b) + max(0, num[0].c - num[i].c));
    }

    cout << ans << endl;
}