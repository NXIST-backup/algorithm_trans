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
const int INF = -1e9 - 50;
typedef pair<int, int> pii;

const int N = 1050;
int n;
int a[N];
int dp[N];

int main()
{
    cin >> n;

    for (int i = 1; i <= n;i++){
        cin >> a[i];
    }
    a[0] = -1e9 - 50;
    for (int i = 1; i <= n; i++) { //子序列最后一个数字pos为i的
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }

    int ans = 0;
    for (int i = 1;i<=n;i++){
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;
}
