//最长公共子序列

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

const int N = 1e4 + 50;

char a[N], b[N];
int f[N][N];
int n, m;

int main() {
  cin >> n >> m;

  scanf("%s%s", a + 1, b + 1);

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      f[i][j] = max(f[i - 1][j], f[i][j - 1]);
      if (a[i] == b[j])
        f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
    }
  }

  cout << f[n][m] << endl;
}