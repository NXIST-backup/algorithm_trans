#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 200005;
int n, a[N], s[N], p[N], mx[N], ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
        p[i] = p[i - 1] + s[i];
        mx[i] = max(mx[i - 1], s[i]);
        ans = max(ans, p[i - 1] + mx[i]);
    }
    cout << ans << endl;
    return 0;
}