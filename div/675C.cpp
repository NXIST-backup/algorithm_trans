#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int MOD = 1e9+7;
typedef pair<int,int> pii;

const int N = 1e5 + 50;

int f[N];

int main()
{
    string s;
    
    cin >> s;
    f[0] = 1;
    for (int i = 1; i <= N;i++) {
        f[i] = f[i - 1] * 10 % MOD;
    }
    reverse(s.begin(), s.end());
    int len = s.size();
    ll ans = 0, cost1 = 0, cost2 = 0, tmp = 0;
    for (int i = 0; i < s.size(); i++) {
        cost1 += (s[i] - '0') * (len - i) % MOD * (len - i - 1) / 2 * f[i] % MOD;
        cost2 += (s[i] - '0') * tmp % MOD;
        tmp = (tmp + f[i] * (i + 1) % MOD) % MOD;
        ans += (cost1 + cost2) % MOD;
    }

    cout << ans << endl;
}