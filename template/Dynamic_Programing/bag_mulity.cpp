//多重背包

//!尝试用二维数组写下
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

const int N = 3e5 + 50;
const int M = 2050;
int n, m;
int v[N], w[N];
int f[N];

int main() {
  cin >> n >> m;

  int cnt = 0;

  for (int i = 1; i <= n; i++) {
    int a, b, s;

    cin >> a >> b >> s;

    int k = 1;
    while (k <= s) {
      cnt++;
      v[cnt] = a * k;
      w[cnt] = b * k;
      s -= k;
      k *= 2;
    }
    if (s > 0) {
      cnt++;
      v[cnt] = a * s;
      w[cnt] = b * s;
    }
  }
  n = cnt;
  for (int i = 1; i <= n; i++)
    for (int j = m; j >= v[i]; j--)
      f[j] = max(f[j], f[j - v[i]] + w[i]);

  cout << f[m] << endl;
}