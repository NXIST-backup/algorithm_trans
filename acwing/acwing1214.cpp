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
const int INF = 1e9;
const int MOD = 100000007;
typedef pair<int, int> pii;

const int N = 1e3 + 50;
int n, s, a, b;
int dp[N][N];

int get_mod(int a, int b)
{
    return (a % b + b) % b;
}

int main()
{
    cin >> n >> s >> a >> b;

    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = (dp[i - 1][get_mod(j - a * (n - i), n)] + dp[i - 1][get_mod(j + b * (n - i), n)]) % MOD;
        }
    }

    cout << dp[n - 1][get_mod(s, n)] << endl;
}