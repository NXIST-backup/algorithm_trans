/*
  Problem Name:Friends and Travel costs
  algorithm tag:easy simulation
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
#define x first
#define y second
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed

const int N = 2e5 + 5;
int n, k;
pll fri[N];

int main()
{
    iosf;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        ll a, b;
        cin >> a >> b;
        fri[i] = {a, b};
    }

    sort(fri + 1, fri + 1 + n);
    ll ans = k;
    for (int i = 1; i <= n; i++) {
        if (fri[i].x > ans)
            break;
        else
            ans += fri[i].y;
    }

    cout << ans << endl;
}