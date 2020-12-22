/*
  Problem Name:Throne
  algorithm tag:线性同余方程
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

ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    ll g = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return g;
}
int main()
{
    int t;
    cin >> t;

    while (t--) {
        ll n, s, k;
        cin >> n >> s >> k;
        ll b = -s;
        ll a = k;
        ll x1, y1;
        ll d = exgcd(a, n, x1, y1);
        if (b % d) {
            cout << -1 << endl;
        } else {
            n /= d;
            x1 *= -s / d;
            cout << (x1 % n + n) % n << endl;
        }
    }
}