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
typedef pair<int, int> pii;

const int N = 105, M = 25005;
int t, n;
int a[N];
int dp[M];


int main()
{
    cin >> t;
    while (t--) {
        cin >> n;
        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + 1 + n);
        int res = n;
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < a[i]; j++) {
                dp[j] += dp[j - a[j]];
            }
            if (dp[a[i]])
                res--;
        }

        cout << res << endl;
    }
}

//未优化
void solve()
{
    cin >> t;
    while (t--) {
        cin >> n;
        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + 1 + n);
        int res = n;
        dp[0] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                for (int k = a[j]; k <= a[i]; k++) {
                    dp[k] += dp[k - a[j]];
                }
            }
            if (dp[a[i]])
                res--;
        }

        cout << res << endl;
    }
}