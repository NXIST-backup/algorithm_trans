/*
  Problem Name:Nowhere P
  algorithm tag:快速幂,math
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
int n, p;

ll ksm(int a, int b, int mod)
{
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans = ans * a % mod;
        }
        a = (ll)a * a % mod;
        b >>= 1;
    }
    return ans;
}

int main()
{
    cin >> n >> p;

    ll ans = ksm(p - 2, n - 1, Mod);
    ans = ans * (p - 1) % Mod;

    cout << ans << endl;
}