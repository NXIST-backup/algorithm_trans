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

const int N = 1e3 + 50;
int n;
int a[N], dp[N], dp2[N];
int ans, res;
int main()
{
    int x;
    int ax = 1;
    while (~scanf("%d", &x))
        if (x)
            a[ax++] = x;
    for (int i = 1; i <= ax - 1; i++) {
        dp[i] = 1;
        for (int j = 1; j < i; j++)
            if (a[i] <= a[j])
                dp[i] = max(dp[i], dp[j] + 1);
    }
    for (int i = 1; i <= ax - 1; i++) {
        dp2[i] = 1;
        for (int j = 1; j < i; j++)
            if (a[i] > a[j])
                dp2[i] = max(dp2[i], dp2[j] + 1);
    }

    for (int i = 1; i <= n;i++){
        res = max(res, dp[i]);
        ans = max(ans, dp2[i]);
    }

    cout << res << endl;
    cout << ans << endl;
}