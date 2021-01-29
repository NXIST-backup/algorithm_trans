#pragma GCC optimize("Ofast")
//#pragma GCC target ("sse4")

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <ciso646>
#include <cmath>
#include <complex>
#include <cstdio>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
constexpr ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop   \
    char nyaa; \
    cin >> nyaa;
#define rep(i, n) for (int i = 0; i < n; i++)
#define per(i, n) for (int i = n - 1; i >= 0; i--)
#define Rep(i, sta, n) for (int i = sta; i < n; i++)
#define rep1(i, n) for (int i = 1; i <= n; i++)
#define per1(i, n) for (int i = n; i >= 1; i--)
#define Rep1(i, sta, n) for (int i = sta; i <= n; i++)
#define all(v) (v).begin(), (v).end()
typedef pair<ll, ll> LP;
typedef double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-12;
const ld pi = acosl(-1.0);

ll mod_pow(ll x, ll n, ll m = mod)
{
    if (n < 0) {
        ll res = mod_pow(x, -n, m);
        return mod_pow(res, m - 2, m);
    }
    if (abs(x) >= m)
        x %= m;
    if (x < 0)
        x += m;
    ll res = 1;
    while (n) {
        if (n & 1)
            res = res * x % m;
        x = x * x % m;
        n >>= 1;
    }
    return res;
}
struct modint
{
    ll n;
    modint() : n(0) { ; }
    modint(ll m) : n(m)
    {
        if (n >= mod)
            n %= mod;
        else if (n < 0)
            n = (n % mod + mod) % mod;
    }
    operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
modint operator+=(modint &a, modint b)
{
    a.n += b.n;
    if (a.n >= mod)
        a.n -= mod;
    return a;
}
modint operator-=(modint &a, modint b)
{
    a.n -= b.n;
    if (a.n < 0)
        a.n += mod;
    return a;
}
modint operator*=(modint &a, modint b)
{
    a.n = ((ll)a.n * b.n) % mod;
    return a;
}
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, ll n)
{
    if (n == 0)
        return modint(1);
    modint res = (a * a) ^ (n / 2);
    if (n % 2)
        res = res * a;
    return res;
}

ll inv(ll a, ll p)
{
    return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }
modint operator/=(modint &a, modint b)
{
    a = a / b;
    return a;
}
const int max_n = 1 << 2;
modint fact[max_n], factinv[max_n];
void init_f()
{
    fact[0] = modint(1);
    for (int i = 0; i < max_n - 1; i++) {
        fact[i + 1] = fact[i] * modint(i + 1);
    }
    factinv[max_n - 1] = modint(1) / fact[max_n - 1];
    for (int i = max_n - 2; i >= 0; i--) {
        factinv[i] = factinv[i + 1] * modint(i + 1);
    }
}
modint comb(int a, int b)
{
    if (a < 0 || b < 0 || a < b)
        return 0;
    return fact[a] * factinv[b] * factinv[a - b];
}
modint combP(int a, int b)
{
    if (a < 0 || b < 0 || a < b)
        return 0;
    return fact[a] * factinv[a - b];
}

void solve()
{
    int n, m;
    cin >> n >> m;
    int k;
    cin >> k;
    vector<bool> b(n + 1);
    rep(i, k)
    {
        int a;
        cin >> a;
        b[a] = true;
    }
    rep(i, n)
    {
        if (b[i]) {
            int le = i;
            while (i + 1 < n && b[i + 1])
                i++;
            if (i - le + 1 >= m) {
                cout << -1 << "\n";
                return;
            }
        }
    }
    vector<LDP> ex(n + m);
    LDP sum = {0, 0};
    per(i, n + m)
    {
        if (i >= n) {
            ex[i] = {0, 0};
        } else {
            if (b[i]) {
                ex[i] = {1, 0};
            } else {
                ex[i] = {sum.first / (ld)m, sum.second / (ld)m + 1};
            }
        }
        sum.first += ex[i].first;
        sum.second += ex[i].second;
        if (i + m < n + m) {
            sum.first -= ex[i + m].first;
            sum.second -= ex[i + m].second;
        }
    }
    ld p = 1 - ex[0].first;
    ld q = ex[0].second;
    ld ans = q / p;
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);
    //init_f();
    //init();
    //expr();
    //int t; cin >> t; rep(i,t)
    //expr();
    solve();
    return 0;
}