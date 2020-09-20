
//
//               集合(符合条件的所有选法的表示)
//              /
//       状态表示
//      /       \
// y式DP         属性-key(Max,min,num)
//      \
//       状态计算——集合划分
//

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

//分组背包
const int N = 150;

int n, m;
int v[N][N], w[N][N], s[N];
int f[N];

int main() {
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    for (int j = 0; j < s[i]; j++)
      cin >> v[i][j] >> w[i][j];
  }

  for (int i = 1; i <= n; i++)
    for (int j = m; j >= 0; j--)
      for (int k = 0; k < s[i]; k++)
        if (v[i][k] <= j)
          f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);

  cout << f[m] << endl;
}
