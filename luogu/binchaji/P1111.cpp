#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
struct hh {
  int x, y, t;
} a[200000];
int f[200000], n, m;
int cmp(const hh &a, const hh &b) { return a.t < b.t; }
int find(int x) { return f[x] == x ? x : (f[x] = find(f[x])); }
int getin() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9')
    ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = x * 10 + ch - 48, ch = getchar();
  return x;
}
int main() {
  n = getin(), m = getin();
  if (n == 1) {
    cout << 0;
    return 0;
  } //其实并没有什么用的特判
  for (int i = 1; i <= m; i++)
    a[i].x = getin(), a[i].y = getin(), a[i].t = getin();
  sort(a + 1, a + m + 1, cmp);
  for (int i = 1; i <= n; i++)
    f[i] = i;
  for (int i = 1; i <= m; i++) {
    int fx = find(a[i].x), fy = find(a[i].y);
    if (fx != fy)
      f[fx] = fy, n--;
    if (n == 1) {
      cout << a[i].t;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}