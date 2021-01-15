/*
  Problem Name:棋盘分割
  algorithm tag:区间DP
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

const int N = 15, M = 9;

int s[M][M];
double f[M][M][M][M][N];
double X;
int n;

double get(int x1, int y1, int x2, int y2)
{
    double sum = s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1] - X;

    return (double)sum * sum / n;
}
double dp(int x1, int y1, int x2, int y2, int k)
{
    double &v = f[x1][y1][x2][y2][k];
    if (v >= 0)
        return v;
    if (k == 1)
        return v = get(x1, y1, x2, y2);
    v = mod;
    for (int i = x1; i < x2; i++) {
        v = min(v, dp(x1, y1, i, y2, k - 1) + get(i + 1, y1, x2, y2));
        v = min(v, dp(i + 1, y1, x2, y2, k - 1) + get(x1, y1, i, y2));
    }
    for (int i = y1; i < y2; i++) {
        v = min(v, dp(x1, y1, x2, i, k - 1) + get(x1, i + 1, x2, y2));
        v = min(v, dp(x1, i + 1, x2, y2, k - 1) + get(x1, y1, x2, i));
    }
    return v;
}

int main()
{
    cin >> n;

    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            cin >> s[i][j];
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }
    X = s[8][8] / n;
    memset(f, -1, sizeof f);

    dp(1, 1, 8, 8, n);

    printf("%.3lf\n", f[1][1][8][8][n]);
}