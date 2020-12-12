/*
  Problem Name:Super Ryuma
  algorithm tag:概率DP,期望DP
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
const int N = 105;
double dp[N][N][N];

int main()
{
    int g, s, b;
    cin >> g >> s >> b;
    for (int i = 100; i >= 0; i--) {
        for (int j = 100; j >= 0; j--) {
            dp[100][i][j] = 0;
            dp[i][j][100] = 0;
            dp[i][100][j] = 0;
        }
    }

    for (int i = 99; i >= g; i--) {
        for (int j = 99; j >= s; j--) {
            for (int k = 99; k >= b; k--) {
                double x = i, y = j, z = k;
                dp[i][j][k] = x / (x + y + z) * (dp[i + 1][j][k] + 1) + y / (x + y + z) * (dp[i][j + 1][k] + 1) + z / (x + y + z) * (dp[i][j][k + 1] + 1);
            }
        }
    }

    printf("%.8lf", dp[g][s][b]);
}