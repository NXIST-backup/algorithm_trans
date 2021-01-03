// nuoyanli
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

#define inf 0x3f3f3f3f
#define lson l, mid, root << 1
#define rson mid + 1, r, root << 1 | 1
#define min(a, b) a > b ? b : a
#define max(a, b) a < b ? b : a
#define ll long long int
using namespace std;
const int N = 1e3 + 10;

int n, m;
const int mod = 1e9 + 7;
int a[N][N];
ll ksm(ll a, ll p) {
  ll ans = 1;
  while (p) {
    if (p & 1)
      ans = ans * a % mod;
    a = a * a % mod;
    p >>= 1;
  }
  return ans;
}
signed main() {
  int x;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    for (int j = 1; j <= x; j++)
      a[i][j] = 1;
    a[i][++x] = -1;
  }

  for (int i = 1; i <= m; i++) {
    scanf("%d", &x);
    for (int j = 1; j <= x; j++) {
        if (a[j][i] == -1)
            return !printf("0\n");
        a[j][i] = 1;
    }
    if (a[++x][i] == 1)
      return !printf("0\n");
    a[x][i] = -1;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (a[i][j] == 0)
        ans++;
  printf("%lld\n", ksm(2, ans));
  return 0;
}