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
const int mod = 1e9 + 7;
typedef pair<int, int> pii;

ll x, y;
ll a, b;

int main()
{
    cin >> x >> y >> a >> b;
    ll mid = b / (a - 1);
    ll ans = 0;
    while (x < mid) {
        x *= a;
        if (x >= y) {
            x /= a;
            break;
        }
        ans++;
    }
    ans += (y - x - 1) / b;
    cout << ans << endl;
}