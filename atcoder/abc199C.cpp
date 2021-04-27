/*
  Problem Name:
  algorithm tag:
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
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-4;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
//#define x first
//#define y second
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed

const int N = 2e5 + 5;
int n, Q;
char s1[N], s2[N], s[N * 2];
int main()
{
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; i++)
        s1[i] = s[i];
    for (int i = n; i < 2 * n; i++)
        s2[i - n] = s[i];

    scanf("%d", &Q);

    char *a = s1, *b = s2;
    while (Q--) {
        int t, x, y;
        scanf("%d%d%d", &t, &x, &y);
        x--, y--;
        if (t == 1) {
            if (x >= n && y >= n)
                swap(b[x % n], b[y % n]);
            else if (x < n && y >= n)
                swap(a[x], b[y % n]);
            else if (x >= n && y < n)
                swap(b[x % n], a[y]);
            else
                swap(a[x % n], a[y % n]);
        } else
            swap(a, b);
    }
    printf("%s%s\n", a, b);
}