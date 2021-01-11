/*
  Problem Name: Choose Me
  algorithm tag: sort
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

const int N = 2e5 + 5;
int n;
struct abc
{
    ll a, b, c;
} s[N];

bool cmp(abc x, abc y)
{
    if (x.c > y.c)
        return true;
    else
        return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed;

    cin >> n;
    ll suma = 0, sumb = 0;

    for (int i = 1; i <= n; i++) {
        ll a, b;
        cin >> a >> b;
        suma += a;
        s[i] = {a, b, 2 * a + b};
    }
    sort(s + 1, s + n + 1, cmp);
    int ans = 0;
    while (sumb <= suma) {
        ans++;
        sumb += s[ans].a + s[ans].b;
        suma -= s[ans].a;
    }

    cout << ans << endl;
}