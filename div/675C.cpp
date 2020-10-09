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
const int MOD = 1e9 + 7;
typedef pair<int, int> pii;

const int N = 1e5 + 10;

ll f[N];

int main()
{
    string s;

    cin >> s;
    f[0] = 1;
    for (int i = 1; i <= N; i++) {
        f[i] = (f[i - 1] * 10) % MOD;
    }
    ll len = s.size();
    reverse(s.begin(), s.end());
    ll ans = 0, cost1 = 0, cost2 = 0, tmp = 0;
    for (int i = 0; i < s.size(); i++) {
        cost1 = (len - i) * (len - i - 1) / 2 % MOD * f[i] * (s[i] - '0') % MOD;
        cost2 = (s[i] - '0') * tmp % MOD;
        tmp = ((i + 1) * f[i] % MOD + tmp) % MOD;
        ans += (cost1 + cost2) % MOD;
        ans %= MOD;
    }

    cout << ans << endl;
}