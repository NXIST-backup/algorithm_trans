#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 34, M = 100000;
int a[N], n;
int d[7], m[7];
int dp[4][M + 4];
int ans = 0x3f3f3f3f;
int shift(int pt, vector<int> &v)
{
    vector<int> tp = v;
    v.clear();
    for (int i = 0; i < 4; i++)
        if (tp[i])
            v.push_back(tp[i]);
    while (pt <= n && v.size() < 4)
        v.push_back(a[pt++]);
    while (v.size() < 4)
        v.push_back(0);
    return pt;
}
void dfs(int p, vector<int> v, int cost)
{
    if (cost >= ans)
        return;
    if (p > n && v[0] + v[1] + v[2] + v[3] == 0) {
        ans = min(ans, cost);
        return;
    }
    for (int k = 0; k < 4; k++) {
        if (v[k] == 0)
            break;
        vector<int> now = v;
        int ncc = 0;
        for (int i = 0; i <= k; i++) {
            now[i] = 0;
            ncc += dp[i][v[i]];
        }
        int x = shift(p, now);
        dfs(x, now, cost + ncc);
    }
    for (int k = 0; k < 4; k++) {
        v[k] = max(v[k] - 40000, 0);
    }
    int x = shift(p, v);
    dfs(x, v, cost + m[4]);
}
int main()
{
    //freopen("r.txt","r",stdin);
    scanf("%d", &n);
    for (int i = 0; i < 4; i++)
        scanf("%d", &d[i]);
    for (int i = 0; i < 5; i++)
        scanf("%d", &m[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int j = 0; j <= M; j++)
        dp[0][j] = ((j + d[0] - 1) / d[0]) * m[0];
    for (int i = 1; i < 4; i++) {
        for (int j = 1; j < d[i]; j++)
            dp[i][j] = min(dp[i - 1][j], m[i]);
        for (int j = d[i]; j <= M; j++)
            dp[i][j] = min(dp[i - 1][j], dp[i][j - d[i]] + m[i]);
    }
    vector<int> v{a[1], a[2], a[3], a[4]};
    dfs(5, v, 0);
    printf("%d\n", ans);
}