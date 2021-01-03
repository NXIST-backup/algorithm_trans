/*
  Problem Name:加分二叉树
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

const int N = 30;

int n;
int w[N];
int f[N][N], g[N][N];

void ans(int l, int r)
{
    if (l > r)
        return;

    int root = g[l][r];
    cout << root << " ";

    ans(l, root - 1);
    ans(root + 1, r);
}

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> w[i];

    for (int len = 1; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            if (len == 1) {
                f[l][r] = w[l];
                g[l][r] = l;
            } else {
                for (int k = l; k <= r; k++) {
                    int left = k == l ? 1 : f[l][k - 1];
                    int right = k == r ? 1 : f[k + 1][r];
                    int score = left * right + w[k];
                    if (score > f[l][r]) {
                        f[l][r] = score;
                        g[l][r] = k;
                    }
                }
            }
        }
    }

    cout << f[1][n] << endl;
    ans(1, n);
}